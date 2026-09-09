# Rozdział 8 — Operacje na danych i rejestry

> [Powrót do spisu treści](./README.md)

---

## 8.1 Typy danych w M221

M221 obsługuje następujące typy danych:

| Typ | Rozmiar | Zakres | Opis |
|-----|---------|--------|------|
| **BOOL** | 1 bit | 0 lub 1 | Stan binarny (ON/OFF) |
| **BYTE** | 8 bitów | 0–255 | Bajt |
| **WORD** | 16 bitów | 0–65535 | Słowo bez znaku |
| **INT** | 16 bitów | −32768 do +32767 | Liczba całkowita ze znakiem |
| **UINT** | 16 bitów | 0–65535 | Liczba całkowita bez znaku |
| **DINT** | 32 bity | −2^31 do +2^31−1 | Podwójna całkowita ze znakiem |
| **UDINT** | 32 bity | 0–2^32−1 | Podwójna całkowita bez znaku |
| **REAL** | 32 bity | ±3.4×10^38 | Liczba zmiennoprzecinkowa |
| **STRING** | zmienna | — | Tekst |

### Adresacja typów

| Typ | Przedrostek | Przykład |
|-----|-------------|---------|
| BOOL | `%M` lub `%I/%Q` | M0, I0.0, Q0.1 |
| INT | `%MW` | MW0, MW1, MW2 |
| DINT | `%MD` | MD0, MD1 |
| REAL | `%MF` | MF0, MF1 |
| STRING | `%MS` | MS0, MS1 |

---

## 8.2 Rejestry funkcyjne

### Global Data (GD)

Rejestry globalne — dostępne **we wszystkich programach**:

| Zakres | Rozmiar | Typ |
|--------|---------|-----|
| `%MW0` – `%MW255` | 16 bitów | INT / UINT |
| `%MD0` – `%MD63` | 32 bity | DINT / UDINT |
| `%MF0` – `%MF63` | 32 bity | REAL |

### Local Data (LD)

Rejestry lokalne — dostępne **tylko w danym programie**:

| Zakres | Rozmiar | Typ |
|--------|---------|-----|
| `%LW0` – `%LW255` | 16 bitów | INT |
| `%LD0` – `%LD63` | 32 bity | DINT |

### System Data (SD / %S)

Rejestry systemowe — przechowują informacje o stanie sterownika:

| Rejestr | Opis |
|---------|------|
| `%S0` | Status komunikacji |
| `%S1` | Status sterownika |
| `%S5` | Licznik cykli (scan counter) |
| `%S8` | Status timerów |

---

## 8.3 Blok MOVE — kopiowanie danych

Blok **MOVE** kopiuje wartość ze źródła do celu.

### Realizacja w drabince

```
  Rung 1:
  ═══| |═══[MOVE]═══
     I0.0  │ IN   │ = %MW0
           │ OUT  │ = %MW1
           └──────┘
```

**Efekt:** Gdy I0.0 = 1, wartość %MW0 jest kopiowana do %MW1.

### MOVE z warunkiem

```
  ═══| |═══[MOVE]═══
     I0.0  │ IN   │ = 100
           │ OUT  │ = %MW0
           └──────┘
```

**Efekt:** Gdy I0.0 = 1, stała 100 jest wpisywana do %MW0.

---

## 8.4 Bloki porównawcze

### Porównanie = (EQUAL)

```
  ═══| |═══[=]═══(Q0.0)═══
     I0.0  │ IN1 │ = %MW0
           │ IN2 │ = 100
           └─────┘
```

**Efekt:** Q0.0 = 1 gdy %MW0 = 100

### Dostępne porównania

| Blok | Operator | Opis |
|------|----------|------|
| `=` | `=` | Równe |
| `<>` | `<>` | Różne |
| `<` | `<` | Mniejsze |
| `>` | `>` | Większe |
| `<=` | `<=` | Mniejsze lub równe |
| `>=` | `>=` | Większe lub równe |

### Przykład — zakres

```
  Rung 1:
  ═══| |═══[>=]═══[<=]═══(M0)═══
     I0.0  │ MW0 │  │ MW0 │
           │ 50  │  │ 200 │
           └─────┘  └─────┘

  ; M0 = 1 gdy 50 <= MW0 <= 200
```

---

## 8.5 Operacje arytmetyczne

### ADD — dodawanie

```
  ═══| |═══[ADD]═══
     I0.0  │ IN1 │ = %MW0
           │ IN2 │ = %MW1
           │ OUT │ = %MW2
           └─────┘

  ; %MW2 = %MW0 + %MW1
```

### Bloki arytmetyczne

| Blok | Operacja | Wzór |
|------|----------|------|
| **ADD** | Dodawanie | OUT = IN1 + IN2 |
| **SUB** | Odejmowanie | OUT = IN1 − IN2 |
| **MUL** | Mnożenie | OUT = IN1 × IN2 |
| **DIV** | Dzielenie | OUT = IN1 / IN2 |
| **MOD** | Reszta z dzielenia | OUT = IN1 mod IN2 |

### Przykład — średnia

```
  Rung 1 — Suma:
  ═══| |═══[ADD]═══
     I0.0  │ IN1 │ = %MW0
           │ IN2 │ = %MW1
           │ OUT │ = %MW2
           └─────┘

  Rung 2 — Dzielenie przez 2:
  ═══| |═══[DIV]═══
     I0.0  │ IN1 │ = %MW2
           │ IN2 │ = 2
           │ OUT │ = %MW3
           └─────┘

  ; %MW3 = (%MW0 + %MW1) / 2
```

---

## 8.6 Konwersja typów danych

### Blok CONV

```
  ═══| |═══[CONV]═══
     I0.0  │ IN   │ = %MW0 (INT)
           │ OUT  │ = %MF0 (REAL)
           └──────┘
```

### Tabela konwersji

| Z Źródła | Do Celu | Blok |
|----------|---------|------|
| INT → REAL | %MW0 → %MF0 | CONV |
| REAL → INT | %MF0 → %MW0 | CONV (zaokrąglenie) |
| INT → DINT | %MW0 → %MD0 | CONV |
| DINT → INT | %MD0 → %MW0 | CONV (obcięcie) |

---

## 8.7 Praca na bitach rejestru

### Indeksowanie bitów

```
  MW0 = 16-bitowy rejestr:
  
  Bit:    15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0
  Wartość: 0  1  0  0  1  1  0  1  0  0  0  0  0  0  1  1
                                                          ▲
                                                      M0.0
```

### Sprawdzanie pojedynczego bitu

```
  ═══| |═══[TEST]═══(Q0.0)═══
     I0.0  │ IN   │ = %MW0
           │ BIT  │ = 0
           └──────┘

  ; Q0.0 = bit 0 rejestru %MW0
```

### Modyfikacja bitu

```
  ═══| |═══[MODIFY]═══
     I0.0  │ IN   │ = %MW0
           │ BIT  │ = 3
           │ VAL  │ = 1
           └──────┘

  ; Ustawia bit 3 rejestru %MW0 na 1
```

---

## 8.8 Przykłady praktyczne

### Przykład 1 — Przelicznik jednostek

**Zadanie:** Czujnik temperatury wysyła wartość 0–1000 do %MW0. Wyświetl temperaturę w stopniach Celsjusza (÷10) w %MW1.

```
  Rung 1:
  ═══[DIV]═══
     │ IN1 │ = %MW0
     │ IN2 │ = 10
     │ OUT │ = %MW1
     └─────┘

  ; %MW1 = %MW0 / 10
```

### Przykład 2 — Zatrzask bitowy

**Zadanie:** Gdy I0.0 jest wciśnięty (impuls), ustaw bit 0 rejestru %MW0 na 1 (niezależnie od reszty rejestru).

```
  Rung 1:
  ═══| |═══[OR]═══
     I0.0  │ IN1 │ = %MW0
           │ IN2 │ = 1
           │ OUT │ = %MW0
           └─────┘

  ; %MW0 = %MW0 OR 0x0001
```

---

## 8.9 Ćwiczenia praktyczne

### Ćwiczenie 1 — Kalkulator

**Zadanie:** Dwa rejestry %MW0 i %MW1. Przycisk I0.0 dodaje je i zapisuje do %MW2. Przycisk I0.1 odejmuje %MW1 od %MW0 i zapisuje do %MW2.

### Ćwiczenie 2 — Zakresy temperatur

**Zadanie:** %MW0 zawiera temperaturę. Ustaw:
- Q0.0 = 1 gdy temp < 18°C
- Q0.1 = 1 gdy 18°C ≤ temp ≤ 25°C
- Q0.2 = 1 gdy temp > 25°C

### Ćwiczenie 3 — Porównanie i alarm

**Zadanie:** %MW0 = odczyt z czujnika. %MW1 = wartość alarmu. Gdy %MW0 > %MW1, migaj lampką Q0.0 (0.5 Hz).

---

## 8.10 Podsumowanie

| Operacja | Blok | Opis |
|----------|------|------|
| Kopiowanie | MOVE | Kopiuje wartość |
| Porównanie | =, <>, <, >, <=, >= | Porównuje dwie wartości |
| Dodawanie | ADD | OUT = IN1 + IN2 |
| Odejmowanie | SUB | OUT = IN1 − IN2 |
| Mnożenie | MUL | OUT = IN1 × IN2 |
| Dzielenie | DIV | OUT = IN1 / IN2 |
| Reszta | MOD | OUT = IN1 mod IN2 |
| Konwersja | CONV | Konwertuje typ danych |

> **Następny rozdział:** [Komunikacja w M221](./rozdzial-09-komunikacja.md)

> [Powrót do spisu treści](./README.md)
