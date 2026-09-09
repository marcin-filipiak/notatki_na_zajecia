# Ściągawka — bloki funkcyjne

> [Powrót do spisu treści](./README.md)

---

## 1. Styki i cewki

```
  Styk NO:     ═══| |═══          → przepływ gdy = 1
  Styk NC:     ═══|/|═══          → przepływ gdy = 0
  Cewka:       ═══( )═══          → wynik = stan wyjścia
  Cewka negac.:═══(/)═══          → wynik = NOT
  SET:         ═══(S)═══          → ustawia na 1 i zapamiętuje
  RESET:       ═══(R)═══          → zeruje do 0
```

---

## 2. Timery

### TON — opóźnienie włączenia
```
  ═══[TON]═══
     │ IN  │
     │ PT  │ = czas (ms)
     │ Q   │ → 1 po upływie PT
     │ ET  │ → czas bieżący
     └─────┘
```

### TOF — opóźnienie wyłączenia
```
  ═══[TOF]═══
     │ IN  │
     │ PT  │ = czas (ms)
     │ Q   │ → 0 po upływie PT od wyłączenia
     │ ET  │
     └─────┘
```

### TP — monostabilny (impuls)
```
  ═══[TP]═══
     │ IN  │
     │ PT  │ = czas (ms)
     │ Q   │ → 1 przez dokładnie PT
     │ ET  │
     └─────┘
```

### RTIM — reset timera
```
  ═══[RTIM]═══
     │ TM0 │
     └─────┘
```

---

## 3. Liczniki

### CTU — w górę
```
  ═══[CTU]═══
     │ CU │ → zlicza w górę
     │ PV │ = wartość zadana
     │ R  │ → reset
     │ QU │ → 1 gdy CV >= PV
     │ CV │
     └────┘
```

### CTD — w dół
```
  ═══[CTD]═══
     │ CD │ → zlicza w dół
     │ PV │ = wartość zadana
     │ R  │ → reset
     │ QD │ → 1 gdy CV <= 0
     │ CV │
     └────┘
```

### CTUD — w obie strony
```
  ═══[CTUD]═══
     │ CU │ → +1
     │ CD │ → −1
     │ PV │ = wartość zadana
     │ R  │ → reset
     │ LD │ → CV = PV
     │ QU │ → CV >= PV
     │ QD │ → CV <= 0
     │ CV │
     └─────┘
```

---

## 4. Operacje na danych

### MOVE — kopiowanie
```
  ═══[MOVE]═══
     │ IN │ → źródło (stała lub rejestr)
     │ OUT│ → cel (rejestr)
     └────┘
```

### Porównania
```
  ═══[=]═══     ; równe
  ═══[<>]═══    ; różne
  ═══[<]═══     ; mniejsze
  ═══[>]═══     ; większe
  ═══[<=]═══    ; mniejsze/równe
  ═══[>=]═══    ; większe/równe
     │ IN1 │
     │ IN2 │
     └─────┘
```

### Arytmetyka
```
  ═══[ADD]═══     ; IN1 + IN2 = OUT
  ═══[SUB]═══     ; IN1 − IN2 = OUT
  ═══[MUL]═══     ; IN1 × IN2 = OUT
  ═══[DIV]═══     ; IN1 ÷ IN2 = OUT
  ═══[MOD]═══     ; IN1 mod IN2 = OUT
     │ IN1 │
     │ IN2 │
     │ OUT │
     └─────┘
```

### Konwersja
```
  ═══[CONV]═══
     │ IN  │
     │ OUT │
     └─────┘
```

---

## 5. Bitowe

### Praca na bitach
```
  ═══[TEST]═══    ; sprawdzanie bitu
     │ IN  │ = rejestr
     │ BIT │ = nr bitu
     └─────┘

  ═══[MODIFY]═══  ; zmiana bitu
     │ IN  │ = rejestr
     │ BIT │ = nr bitu
     │ VAL │ = 0 lub 1
     └─────┘
```

---

## 6. Typowe wartości czasowe

| Opis | PT (ms) |
|------|---------|
| 0.5 s | 500 |
| 1 s | 1000 |
| 2 s | 2000 |
| 5 s | 5000 |
| 10 s | 10000 |
| 30 s | 30000 |
| 1 min | 60000 |

---

## 7. Szybkie przypomnienie adresacji

| Symbol | Znaczenie |
|--------|-----------|
| %I | Wejście cyfrowe |
| %Q | Wyjście cyfrowe |
| %M | Marker / przekaźnik pomocniczy |
| %MW | Rejestr 16-bitowy |
| %MD | Rejestr 32-bitowy |
| %MF | Rejestr zmiennoprzecinkowy |
| %TM | Timer |
| %CT | Licznik |
| %LW | Rejestr lokalny |
| %S | Zmienna systemowa |

---

> [Powrót do spisu treści](./README.md)
