# Rozdział 11 — Diagnostyka i debugowanie

> [Powrót do spisu treści](./README.md)

---

## 11.1 Wskaźniki LED na sterowniku

TM221M16R posiada diody LED na panelu przednim — **pierwsze narzędzie diagnostyczne**.

### Diody systemowe

| LED | Kolor | Normalny stan | Oznaczenie problemu |
|-----|-------|---------------|---------------------|
| **PWR** | Zielony | Stałe ON | Wyłączony / brak zasilania |
| **RUN** | Zielony | Stałe ON | Błąd programu (miga) / STOP |
| **ERR** | Czerwony | Wyłączony | Błąd systemu (stałe) / błąd programu (miga) |
| **USB** | Zielony | Wyłączony | Aktywne połączenie USB |
| **ETH** | Zielony | Miga | Aktywne połączenie Ethernet |

### Diody I/O

| LED | Znaczenie |
|-----|-----------|
| **I0.0 – I1.1** | Zielony = stan wejścia HIGH (1) |
| **Q0.0 – Q0.5** | Zielony = stan wyjścia HIGH (1) |

### Diagnostyka przez LED

```
  Problem                          Diagnostyka
  ─────────────────────────────────────────────────
  Sterownik nie startuje   →  Sprawdź PWR, zasilanie
  ERR świeci na czerwono   →  Błąd programu / hardware
  RUN miga                 →  Błąd w programie
  Wejście nie reaguje      →  Sprawdź LED wejścia, okablowanie
  Wyjście nie działa       →  Sprawdź LED wyjścia, obciążenie
```

---

## 11.2 Diagnostyka w SoMachine Basic

### Okno diagnostyki

W SoMachine Basic → **Widok → Diagnostyka**:

| Zakładka | Zawartość |
|----------|-----------|
| **Status** | Stan RUN/STOP, błędy, komunikacja |
| **Zdarzenia** | Log zdarzeń (start, stop, błędy) |
| **I/O** | Stan wejść i wyjść |
| **Komunikacja** | Status portów Ethernet, USB, Serial |

### Kod błędu

| Kod | Opis | Rozwiązanie |
|-----|------|-------------|
| E001 | Błąd pamięci | Restart sterownika |
| E002 | Błąd programu | Sprawdź program (syntax) |
| E003 | Watchdog timeout | Skróć program lub zwiększ watchdog |
| E004 | Błąd komunikacji | Sprawdź kable, adresy IP |
| E005 | Brak rozszerzenia | Sprawdź moduły TM2 |

---

## 11.3 Tryb monitorowania online

### Aktywacja

1. Połącz się ze sterownikiem (USB/Ethernet)
2. Kliknij **Monitor Online** (ikona oka)
3. Przełącznik musi być w trybie **RUN**

### Co widać w trybie monitorowania

```
  ═══| |═══|/|═══(Q0.0)═══      ← Stan na żywo
     I0.0  I0.1
     ───   ───
     ON    OFF                     ← ZIELONA linia = ON
                                  ← BRAK linii = OFF
```

### Informacje wyświetlane

| Element | Co pokazuje |
|---------|-------------|
| Styki | Czy są zamknięte (zielona linia) czy otwarte |
| Cewki | Czy są załączone (zielona linia) |
| Timery | ET (czas bieżący), PT (zadany), Q (wyjście) |
| Liczniki | CV (wartość bieżąca), QU/QD |
| Rejestry | Aktualna wartość (MW, MD, MF) |

---

## 11.4 Wymuszanie (Forcing) wejść i wyjść

**Forcing** pozwala **ręczne ustawić** stan wejścia lub wyjścia — niezależnie od stanu fizycznego.

### Uwaga

> Forcing jest **niebezpieczny** — używaj tylko podczas testów! Zapamiętaj wyłączenie force'a po testach.

### Jak wymusić

1. W trybie monitorowania kliknij prawym przyciskiem na zmienną
2. Wybierz **Force Value**
3. Ustaw wartość **0** lub **1**
4. Potwierdź

### Przykłady użycia

| Cel | Jak |
|-----|-----|
| Testuj logikę bez fizycznych przycisków | Wymuś I0.0 = 1 |
| Testuj wyjścia bez podłączonych urządzeń | Wymuś Q0.0 = 1 |
| Symuluj warunki awaryjne | Wymuś I0.4 = 1 (STOP) |

### Wyłączenie force'a

1. Kliknij prawym na wymuszoną zmienną
2. Wybierz **Release Force**
3. Zmienna wraca do sterowania fizycznego

---

## 11.5 Logi zdarzeń

### Zdarzenia w SoMachine Basic

W oknie **Diagnostyka → Zdarzenia** znajdziesz:

| Typ zdarzenia | Opis |
|---------------|------|
| **Start** | Sterownik przeszedł w tryb RUN |
| **Stop** | Sterownik przeszedł w tryb STOP |
| **Błąd** | Wystąpił błąd (kod + opis) |
| **Komunikacja** | Nawiązano / zerwano połączenie |
| **Download** | Pobrano nowy program |
| **Watchdog** | Przekroczono czas watchdog |

---

## 11.6 Najczęstsze błędy i rozwiązania

### Błąd 1: Sterownik nie przechodzi w RUN

| Możliwa przyczyna | Rozwiązanie |
|-------------------|-------------|
| Błąd kompilacji | Sprawdź okno błędów, popraw program |
| Błąd hardware | Sprawdź ERR LED, zasilanie |
| Moduł rozszerzenia brak | Sprawdź konfigurację HW |

### Błąd 2: Wejście nie reaguje

| Możliwa przyczyna | Rozwiązanie |
|-------------------|-------------|
| Złe okablowanie | Sprawdź połączenia |
| Zły adres | Sprawdź adresację (I0.0 vs I1.0) |
| Filtr antydrżeniowy | Czas odpowiedzi = 10 ms |
| Zasilanie czujnika | Czujnik wymaga osobnego zasilania 24V |

### Błąd 3: Wyjście nie działa

| Możliwa przyczyna | Rozwiązanie |
|-------------------|-------------|
| Przekaźnik zużyty | Sprawdź LED wyjścia |
| Złe obciążenie | Max 2A na kanał |
| Sterownik w STOP | Sprawdź LED RUN |
| Błąd w programie | Monitoruj online, sprawdź logikę |

### Błąd 4: Brak komunikacji Ethernet

| Możliwa przyczyna | Rozwiązanie |
|-------------------|-------------|
| Zły adres IP | Sprawdź konfigurację sieci |
| Zły kabel | Użyj kabla cross-over lub switch |
| Firewall | Wyłącz firewall na czas testów |
| DHCP | Sprawdź czy DHCP przypisał adres |

---

## 11.7 Backup i przywracanie projektu

### Tworzenie kopii zapasowej

1. W SoMachine Basic: **Plik → Zapisz jako...**
2. Zapisz projekt (.scp) w bezpiecznej lokalizacji
3. Zapisz osobno konfigurację hardware

### Przywracanie projektu

1. **Plik → Otwórz...**
2. Wybierz plik .scp
3. Połącz się ze sterownikiem
4. Pobierz program (Download)

### Eksport konfiguracji

Możesz wyeksportować:
- **Program** (.scp) — plik projektu
- **Konfigurację HW** — ustawienia sterownika
- **Zmienne** — tabelę symboli
- **Firmware** — oprogramowanie wewnętrzne

---

## 11.8 Narzędzia diagnostyczne online

### Test pinów (Pin Test)

W SoMachine Basic → Narzędzia → Test Pinów:
- Wymusza pojedyncze wyjścia
- Sprawdza działanie fizycznych przekaźników

### Monitor portu szeregowego

- Podgląd komunikacji Modbus RTU
- Wysyłanie poleceń testowych
- Sprawdzanie odpowiedzi urządzeń slaves

---

## 11.9 Podsumowanie diagnostyki

```
  Diagnostyka krok po kroku:
  
  1. Sprawdź LED na sterowniku (PWR, RUN, ERR)
  2. Sprawdź LED wejść/wyjść
  3. Połącz się z SoMachine Basic
  4. Sprawdź okno diagnostyki (błędy, zdarzenia)
  5. Monitoruj online (stany, wartości)
  6. Wymuszaj (force) w razie potrzeby
  7. Sprawdź logi zdarzeń
  8. Porównaj z oczekiwanym zachowaniem
```

> **Następny rozdział:** [Projekt 1 — Sterowanie oświetleniem](./projekt-01-oswietlenie.md)

> [Powrót do spisu treści](./README.md)
