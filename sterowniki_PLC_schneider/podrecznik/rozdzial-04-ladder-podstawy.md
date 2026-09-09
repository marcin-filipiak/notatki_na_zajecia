# Rozdział 4 — Podstawy języka drabinkowego (Ladder Diagram)

> [Powrót do spisu treści](./README.md)

---

## 4.1 Filozofia języka drabinkowego

Język drabinkowy (ang. *Ladder Diagram*, LD) jest **najpopularniejszym** językiem programowania PLC. Został opracowany tak, aby **elektrycy i automatykowiec** mogli go czytać i pisać bez znajomości programowania komputerowego.

> Ladder Diagram jest graficzną reprezentacją **schematu elektrycznego** — przekaźnikowego układu sterowania.

### Analogia do schematu elektrycznego

```
  Schemat elektryczny klasyczny          Język drabinkowy PLC
  ─────────────────────────────          ──────────────────────
  
  +24V ──[S1]──[S2]────(KM1)── GND      ═══| |═══| |═══( )═══
           │                                I0.0  I0.1   Q0.0
         [S3]                               ═══| |═══
          │                                  I0.2
         GND
```

W schemacie elektrycznym przepływ prądu jest **fizyczny**. W PLC jest to **logiczna symulacja** przepływu prądu przez sieć (rung).

---

## 4.2 Zasilacz (Power Rail) i sieci (Rungs)

### Struktura drabiny

```
  Zasilacz lewy                  Zasilacz prawy
  (L1 / +24V)                   (L2 / 0V)
      │                              │
      │   ═══ Rung 1 ═══           │
      │   ═══| |═══| |═══( )════   │
      │        │                    │
      │   ═══ Rung 2 ═══           │
      │   ═══| |═══|/|═══( )════   │
      │        │                    │
      │   ═══ Rung 3 ═══           │
      │        │                    │
      ▼                              ▼
```

- **Zasilacz lewy (L+)** — źródło logiki 1
- **Zasilacz prawy (L−)** — masa
- **Rung** (sieć) — pojedyncza linia logiczna (lewo → prawo)
- Program składa się z **wielu rungów** wykonywanych po kolei

---

## 4.3 Styki — NO i NC

### Styk normalnie otwarty (NO — Normally Open)

```
  ═══| |═══
     I0.0
```

- Gdy **I0.0 = 0** → styk **OTWARTY** → brak przepływu
- Gdy **I0.1 = 1** → styk **ZAMKNIĘTY** → przepływ

### Styk normalnie zamknięty (NC — Normally Closed)

```
  ═══|/|═══
     I0.1
```

- Gdy **I0.1 = 0** → styk **ZAMKNIĘTY** → przepływ
- Gdy **I0.1 = 1** → styk **OTWARTY** → brak przepływu

### Tabela prawdy

| Zmienna | Styk NO | Styk NC |
|---------|---------|---------|
| 0 | Otwarty (0) | Zamknięty (1) |
| 1 | Zamknięty (1) | Otwarty (0) |

---

## 4.4 Cewki wyjściowe (Coils)

### Cewka standardowa (coil)

```
  ═══| |═══( )═══
     I0.0   Q0.0
```

- Gdy **I0.0 = 1** → **Q0.0 = 1**
- Gdy **I0.0 = 0** → **Q0.0 = 0**

### Cewka z negacją (NC coil)

```
  ═══| |═══(/)═══
     I0.0   Q0.0
```

- Gdy **I0.0 = 1** → **Q0.0 = 0**
- Gdy **I0.0 = 0** → **Q0.0 = 1**

> **Uwaga:** Cewka z negacją w SoMachine Basic jest dostępna jako osobny element (negated coil).

---

## 4.5 Przekaźniki pomocnicze (Markers / Internal Relays)

Przekaźniki pomocnicze to **wirtualne przekaźniki** — nie mają fizycznego odpowiednika na sterowniku. Służą do przechowywania stanów pośrednich.

### Adresacja markerów

| Zakres | Opis |
|--------|------|
| **M0** – **M2047** | Markery bitowe (BOOL) |
| **%MW0** – **%MW255** | Rejestry 16-bitowe (INT) |
| **%MD0** – **%MD63** | Rejestry 32-bitowe (DINT) |
| **%MF0** – **%MF63** | Rejestry 32-bitowe pływające (REAL) |

### Przykład użycia markera

```
  ═══| |═══| |═══(M0)═══     ; wywołanie warunku → zapis do M0
     I0.0  I0.1

  ══(M0)═══| |═══(Q0.0)═══  ; M0 steruje wyjściem
```

---

## 4.6 Zasady kolejności oceniania

PLC ocenia program w **ściśle określonej kolejności**:

### Hierarchia oceniania

```
1. Ocena rungów — od rung #1 do ostatniego rung
2. W obrębie runga — od LEWEJ do PRAWEJ
3. Przełączniki szeregowe (AND) — kolejność od lewej
4. Przełączniki równoległe (OR) — najpierw gałąź główna, potem równoległe
```

### Przykład kolejności

```
  Rung 1:
  ═══| |═══|/|═══| |═══(Q0.0)═══
     A      B      C

  Ocena: ((A=1) AND (B=0) AND (C=1)) → Q0.0=1
```

```
  Rung 2:
  ═══| |═══┬═══| |═══(Q0.1)═══
     A     │    C
           │
  ═══| |═══┘
     B

  Ocena: ((A=1) OR (B=1)) AND (C=1) → Q0.1=1
```

---

## 4.7 Adresowanie zmiennych w M221

### Tabela adresacji

| Typ zmiennej | Przedrostek | Zakres | Rozmiar |
|--------------|-------------|--------|---------|
| Wejścia cyfrowe | `%I` | I0.0 – I1.1 | 1 bit |
| Wyjścia cyfrowe | `%Q` | Q0.0 – Q0.5 | 1 bit |
| Markery bitowe | `%M` | M0 – M2047 | 1 bit |
| Rejestry słowa | `%MW` | MW0 – MW255 | 16 bitów |
| Rejestry podwójne | `%MD` | MD0 – MD63 | 32 bity |
| Rejestry pływające | `%MF` | MF0 – MF63 | 32 bity |
| Timery | `%TM` | TM0 – TM31 | struktura |
| Liczniki | `%CT` | CT0 – CT31 | struktura |
| STA (systemowy) | `%S` | S0 – S... | 1 bit |

### Zmienne symboiczne

W SoMachine Basic możesz nadać **czytelne nazwy** zmiennym:

| Nazwa symbolu | Adres | Typ | Komentarz |
|---------------|-------|-----|-----------|
| `Start` | `%I0.0` | BOOL | Przycisk Start |
| `Stop` | `%I0.1` | BOOL | Przycisk Stop |
| `Lampa` | `%Q0.0` | BOOL | Sygnalizacja |
| `Temperatura` | `%MW0` | INT | Odczyt z czujnika |

---

## 4.8 Tabela zmiennych (DTT — Data Type Table)

### Jak dodać zmienną

1. W panelu drzewa kliknij **Zmienne** (Variables)
2. Kliknij **Dodaj zmienną**
3. Wypełnij pola:
   - **Nazwa** — czytelna nazwa (np. `Przycisk_Start`)
   - **Adres** — fizyczny adres (np. `%I0.0`)
   - **Typ** — BOOL, INT, UINT, DINT, REAL itp.
   - **Komentarz** — opis用途

### Przykładowa tabela zmiennych

| Nazwa | Adres | Typ | Komentarz |
|-------|-------|-----|-----------|
| Start | %I0.0 | BOOL | Przycisk Start |
| Stop | %I0.1 | BOOL | Przycisk Stop |
| Czujnik_1 | %I0.2 | BOOL | Czujnik zbliżeniowy |
| Lampka_Start | %Q0.0 | BOOL | Zielona lampka |
| Lampka_Stop | %Q0.1 | BOOL | Czerwona lampka |
| Zawor_1 | %Q0.2 | BOOL | Zawór pneumatyczny |
| Licznik_Wyrob%C3%B3w | %MW0 | INT | Liczba wyrobów |
| Temp_Zadana | %MW1 | INT | Temperatura zadana |

---

## 4.9 Ćwiczenie 1 — Prosty układ z dwoma wyłącznikami

**Zadanie:** Włącz lampkę Q0.0, gdy:
- Przycisk I0.0 jest wciśnięty **I**
- Przycisk I0.1 **NIE** jest wciśnięty

### Rozwiązanie

```
  Rung 1:
  ═══| |═══|/|═══( )═══
     I0.0  I0.1  Q0.0
```

### Tabela zmiennych

| Nazwa | Adres | Typ |
|-------|-------|-----|
| Start | %I0.0 | BOOL |
| Blokada | %I0.1 | BOOL |
| Lampa | %Q0.0 | BOOL |

### Wyjaśnienie
- Styk NO `I0.0` — przepływ gdy wciśnięty
- Styk NC `I0.1` — przepływ gdy NIE wciśnięty
- Cewka `Q0.0` — lampka załącza się gdy oba warunki spełnione

---

## 4.10 Ćwiczenie 2 — Przycisk z zapamiętaniem (SET/RESET)

**Zadanie:** Przycisk I0.0 włącza lampkę Q0.0. Przycisk I0.1 wyłącza lampkę Q0.0. Lampa zapamiętuje stan po puszczeniu przycisku.

### Rozwiązanie

```
  Rung 1:                Rung 2:
  ═══| |═══(S)═══        ═══| |═══(R)═══
     I0.0   Q0.0            I0.1   Q0.0
```

### Wyjaśnienie
- **(S)** = SET — ustawia bit na 1 (zatrzymuje się na 1)
- **(R)** = RESET — ustawia bit na 0
- Po wciśnięciu I0.0: Q0.0 = 1 (na stałe)
- Po wciśnięciu I0.1: Q0.0 = 0 (na stałe)

---

## 4.11 Podsumowanie

- Ladder = graficzna reprezentacja logiki przekaźnikowej
- Styki NO (`| |`) i NC (`|/|`) to wejścia logiczne
- Cewki (`( )`) to wyjścia
- Markery (`M0`–`M2047`) to pamięć wewnętrzna
- Program oceniany lewo → prawo, góra → dół
- SET/RESET do zapamiętywania stanów

> **Następny rozdział:** [Bramki logiczne i kombinacje](./rozdzial-05-bramki-logiczne.md)

> [Powrót do spisu treści](./README.md)
