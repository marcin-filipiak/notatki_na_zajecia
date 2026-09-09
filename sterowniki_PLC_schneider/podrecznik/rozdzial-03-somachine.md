# Rozdział 3 — Oprogramowanie SoMachine Basic

> [Powrót do spisu treści](./README.md)

---

## 3.1 Wstęp

**SoMachine Basic** to darmowe oprogramowanie do programowania sterowników z rodziny Modicon M221 firmy Schneider Electric. Stanowi uproszczoną wersję platformy **SoMachine** (obecnie **EcoStruxure Machine Expert**).

### Kluczowe cechy

- Bezpłatne (freeware) — do pobrania ze strony Schneider Electric
- Języki: **Ladder Diagram (LD)**, Instruction List (IL)
- Konfiguracja hardware sterownika
- Kompilacja, pobieranie i monitorowanie programu
- Wbudowany serwer WWW (konfiguracja przez przeglądarkę)
- Obsługa rozszerzeń TM2

---

## 3.2 Instalacja i wymagania systemowe

### Wymagania

| Parametr | Wartość |
|----------|---------|
| System operacyjny | Windows 7 SP1 / 8.1 / 10 (64-bit) |
| RAM | min. 4 GB (zalecane 8 GB) |
| Dysk | 2 GB wolnego miejsca |
| .NET Framework | 4.5.2 lub nowszy |
| Ekran | min. 1280×768 |

### Kolejność instalacji

1. Pobierz instalator ze strony Schneider Electric
2. Uruchom `setup.exe`
3. Wybierz komponenty: **SoMachine Basic**
4. Postępuj zgodnie z kreatorem instalacji
5. Po instalacji uruchom program z menu Start

> **Uwaga:** Jeśli masz zainstalowaną pełną wersję SoMachine / Machine Expert, SoMachine Basic może być już włączony jako osobna aplikacja.

---

## 3.3 Struktura interfejsu

```
┌─────────────────────────────────────────────────────────────┐
│  SoMachine Basic                                     [─][□][×]│
├─────────────────────────────────────────────────────────────┤
│  Plik  Edycja  Widok  Narzędzia  Pomoc                     │
├─────────────────────────────────────────────────────────────┤
│  [Nowy] [Otwórz] [Zapisz] [Kompiluj] [Pobierz] [▶ RUN]    │
├───────────┬─────────────────────────────────────────────────┤
│           │                                                 │
│  PANEL    │          OBSZAR ROBOCZY                         │
│  DRZEWA   │                                                 │
│           │  ┌─────────────────────────────────────────┐   │
│  ┌───────┐│  │                                         │   │
│  │Projekt││  │     Edytor drabinkowy (Ladder)         │   │
│  │ ├─ HW ││  │                                         │   │
│  │ ├─ Prog│  │     ═══| |═══| |═══( )═══              │   │
│  │ ├─ Var ││  │                                         │   │
│  │ └─ Com │  └─────────────────────────────────────────┘   │
│  └───────┘│                                                 │
│           │                                                 │
├───────────┴─────────────────────────────────────────────────┤
│  Kompilacja: 0 błędów | 0 ostrzeżeń                         │
└─────────────────────────────────────────────────────────────┘
```

### Główne elementy interfejsu

| Element | Lokalizacja | Opis |
|---------|-------------|------|
| **Panel drzewa** | Lewa strona | Struktura projektu: HW, Program, Zmienne, Komunikacja |
| **Edytor drabinkowy** | Centrum | Edycja sieci (rungs) w języku drabinkowym |
| **Pasek narzędzi** | Góra | Przyciski: Nowy, Zapisz, Kompiluj, Pobierz, Uruchom |
| **Okno kompilacji** | Dół | Komunikaty błędów i ostrzeżeń |
| **Tabela zmiennych** | Panel drzewa | Definicja zmiennych (nazwa, typ, adres, komentarz) |

---

## 3.4 Tworzenie nowego projektu

### Krok po kroku

1. **Uruchom** SoMachine Basic
2. Kliknij **Plik → Nowy projekt** (lub ikonę [Nowy])
3. W oknie konfiguracji wybierz typ sterownika:
   - Seria: **M221**
   - Model: **TM221M16R**
4. Nazwij projekt (np. `MojaMaszyna`)
5. Określ ścieżkę zapisu
6. Kliknij **OK**

### Konfiguracja parametrów projektu

```
Projekt: MojaMaszyna
├── Sterownik: TM221M16R
│   ├── Wejścia: 10 DI (I0.0–I1.1)
│   ├── Wyjścia: 6 DO (Q0.0–Q0.5)
│   └── Ethernet: 192.168.1.1
├── Program główny: Main
│   └── Język: Ladder (LD)
└── Zmienne: (puste na start)
```

---

## 3.5 Połączenie z sterownikiem

### Połączenie przez Ethernet

1. Podłącz kabel Ethernet z komputera do TM221M16R
2. Upewnij się, że Twój komputer ma adres IP z tej samej podsieci (np. `192.168.1.100`)
3. W SoMachine Basic: **Narzędzia → Komunikacja → Połącz**
4. Wpisz adres IP sterownika (domyślnie: `192.168.1.1`)
5. Kliknij **Połącz**

### Połączenie przez USB

1. Podłącz kabel USB Micro-B z komputera do TM221M16R
2. W SoMachine Basic: **Narzędzia → Komunikacja → Połącz**
3. Wybierz port USB
4. Kliknij **Połącz**

### Diagnostyka połączenia

| Status | Znaczenie |
|--------|-----------|
| Zielona ikona | Połączenie aktywne |
| Czerwona ikona | Brak połączenia |
| Żółta ikona | Połączenie niepełne |

---

## 3.6 Kompilacja, pobranie i uruchomienie programu

### Kompilacja

1. Kliknij ikonę **Kompiluj** (lub F7)
2. Sprawdź okno komunikatów na dole
3. **0 błędów** = program gotowy do pobrania

### Pobranie programu do sterownika

1. Upewnij się, że sterownik jest podłączony
2. Kliknij ikonę **Pobierz** (Download)
3. Sterownik przejdzie w tryb **STOP** (RUN LED zgaśnie)
4. Program zostanie przesłany
5. Kliknij **Uruchom** (▶ RUN) — sterownik rozpoczyna pracę

### Tryb STOP / RUN

| Przełącznik | Znaczenie |
|-------------|-----------|
| **STOP** | Program nie jest wykonywany; wyjścia w stanie bezpiecznym (0) |
| **RUN** | Program jest wykonywany; normalna praca sterownika |

---

## 3.7 Monitorowanie w czasie rzeczywistym

### Tryb online

1. Po połączeniu kliknij **Monitor Online** (lub ikonę oka)
2. W edytorze drabinkowym zobaczysz:
   - **Zielona linia** = przepływ prądu (styki zamknięte)
   - **Brak linii** = prąd nie przepływa (styki otwarte)
   - **Aktualne wartości** zmiennych
3. Możesz **wymuszać** (Forcing) stany wejść i wyjść do celów testowych

### Praca offline i online

| Tryb | Praca w edytorze | Podgląd stanu | Wymuszanie |
|------|------------------|---------------|------------|
| **Offline** | Tak | Nie | Nie |
| **Online** | Nie (tylko odczyt) | Tak | Tak |

---

## 3.8 Typowy przebieg pracy

```
1. Tworzenie projektu
       ↓
2. Konfiguracja hardware (TM221M16R)
       ↓
3. Definicja zmiennych (tabela symboli)
       ↓
4. Pisanie programu (Ladder)
       ↓
5. Kompilacja (F7)
       ↓
6. Połączenie z sterownikiem
       ↓
7. Pobranie programu (Download)
       ↓
8. Przełączenie na RUN
       ↓
9. Monitorowanie online
```

---

## 3.9 Podsumowanie

- SoMachine Basic to darmowe, intuicyjne narzędzie do M221
- Program tworzysz w edytorze drabinkowym
- Połączenie przez Ethernet lub USB
- Cykl: pisz → kompiluj → pobieraj → uruchamiaj → monitoruj

> **Następny rozdział:** [Podstawy języka drabinkowego](./rozdzial-04-ladder-podstawy.md)

> [Powrót do spisu treści](./README.md)
