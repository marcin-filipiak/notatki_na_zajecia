# Rozdział 7 — Liczniki (Counters)

> [Powrót do spisu treści](./README.md)

---

## 7.1 Przegląd liczników w M221

Licznik to **blok funkcyjny** zliczający rosnące lub malejące impulsy. M221 udostępnia **32 liczniki** (CT0–CT31).

```
  Struktura licznika CTx:
  ┌─────────────────────────┐
  │ Counter CTx              │
  │ ├── CU    (count up)    │
  │ ├── CD    (count down)  │
  │ ├── R     (reset)       │
  │ ├── LD    (load/preset) │
  │ ├── PV    (preset value)│
  │ ├── CV    (current val) │
  │ └── QU/QD (wyjścia)     │
  └─────────────────────────┘
```

| Parametr | Opis |
|----------|------|
| **CU** | Wejście zliczające w górę (rosnące zbocze) |
| **CD** | Wejście zliczające w dół (rosnące zbocze) |
| **R** | Reset licznika (CV = 0) |
| **LD** | Ładowanie wartości (CV = PV) |
| **PV** | Wartość zadamana (*Preset Value*) |
| **CV** | Wartość bieżąca (*Current Value*) |
| **QU** | Wyjście = 1 gdy CV >= PV (przy CTU) |
| **QD** | Wyjście = 1 gdy CV <= 0 (przy CTD) |

---

## 7.2 CTU — licznik w górę (Count Up)

**CTU** zlicza **rosnące zbocza** na wejściu CU. Wyjście QU ustawia się na 1 gdy CV >= PV.

### Schemat działania

```
  Wejście CU:  ──┐  ┌──┐  ┌──
                  └──┘  └──┘
                  ▲  ▲  ▲
              impulsy (rosnące zbocza)

  CV:          0  1  2  3  ...
  PV:          3

  QU:          ────────────────┐
                               └──── (1 gdy CV >= PV)
```

### Realizacja w drabince

```
  Rung 1:
  ═══| |═══[CTU]═══
     I0.0  │ CT0  │
           │ CU   │
           │ PV   │ = 10
           │ R    │
           │ QU   │
           │ CV   │
           └──────┘

  Rung 2:
  ═══[CT0.QU]═══(Q0.0)═══     ; Lampka po 10 impulsach
```

### Tabela zachowania CTU

| CV | PV | QU |
|----|----|----|
| 0 | 10 | 0 |
| 9 | 10 | 0 |
| 10 | 10 | 1 |
| 15 | 10 | 1 (po OVERFLOW) |

---

## 7.3 CTD — licznik w dół (Count Down)

**CTD** zlicza **rosnące zbocza** na wejściu CD i **odejmuje** 1. Wyjście QD ustawia się na 1 gdy CV <= 0.

### Schemat działania

```
  Wejście CD:  ──┐  ┌──┐  ┌──
                  └──┘  └──┘

  CV:          10  9  8  7  ...
  PV:          10

  QD:          ────────────────┐
                               └──── (1 gdy CV <= 0)
```

### Realizacja w drabince

```
  Rung 1:
  ═══| |═══[CTD]═══
     I0.1  │ CT1  │
           │ CD   │
           │ PV   │ = 10
           │ R    │
           │ QD   │
           │ CV   │
           └──────┘

  Rung 2:
  ═══[CT1.QD]═══(Q0.1)═══
```

---

## 7.4 CTUD — licznik w obie strony (Count Up/Down)

**CTUD** łączy funkcje CTU i CTD w jednym bloku.

### Realizacja w drabince

```
  Rung 1:
  ═══| |═══| |═══[CTUD]═══
     I0.0  I0.1 │ CT2   │
           │ CU  │
           │ CD  │
           │ PV  │ = 5
           │ R   │
           │ LD  │
           │ QU  │
           │ QD  │
           │ CV  │
           └─────┘
```

### Zachowanie CTUD

| Zdarzenie | Efekt na CV | Efekt na QU | Efekt na QD |
|-----------|-------------|-------------|-------------|
| Rosnące zbocze CU | CV + 1 | CV >= PV → 1 | — |
| Rosnące zbocze CD | CV − 1 | — | CV <= 0 → 1 |
| R = 1 | CV = 0 | 0 | 1 |
| LD = 1 | CV = PV |取决于 PV |取决于 PV |

---

## 7.5 Reset licznika

### Reset przez wejście R

```
  ═══| |═══(R)═══
     I0.1  CT0
```

### Reset przez marker

```
  Rung 1:
  ═══| |═══(M10)═══
     I0.2

  Rung 2:
  ═══| |═══[CTU]═══
     I0.0  │ CT0  │
           │ R    │ = M10
           └──────┘
```

---

## 7.6 Przepływ licznika (overflow / underflow)

### Overflow (przepełnienie CTU)

Gdy CV osiągnie wartość maksymalną (32767 dla INT), dalsze zliczanie **zawija się** do 0.

> W praktyce: jeśli PV = 10, a CV = 10, to QU = 1. Dalsze impulsy zwiększają CV, ale QU pozostaje 1.

### Underflow (niedopełnienie CTD)

Gdy CV osiągnie 0, dalsze zliczanie w dół **zawija się** do 32767.

---

## 7.7 Przykłady zastosowań

### Przykład 1 — Liczba elementów na taśmie

**Zadanie:** Czujnik I0.0 liczy elementy na taśmie. Po 100 elementach włącza się sygnał Q0.0.

```
  Rung 1:
  ═══| |═══[CTU]═══
     I0.0  │ CT0  │
           │ CU   │
           │ PV   │ = 100
           │ R    │
           │ QU   │──┐
           └──────┘  │
                     │
  Rung 2:            │
  ═══[CT0.QU]═══(Q0.0)═══

  Rung 3 — Reset licznika po zatwierdzeniu:
  ═══| |═══[R]═══
     I0.1  CT0
```

### Przykład 2 — Przeliczanie na sztuki

**Zadanie:** Czujnik I0.0 liczy przejeżdżające towary. Po 5 sztukach otwiera się bramka Q0.0 na 2 sekundy.

```
  Rung 1:
  ═══| |═══[CTU]═══
     I0.0  │ CT0  │
           │ CU   │
           │ PV   │ = 5
           │ QU   │──┐
           └──────┘  │
                     │
  Rung 2:            │
  ═══[CT0.QU]═══[TON]═══
              │ TM0  │
              │ PT   │ = 2000
              │ Q    │──┐
              └──────┘  │
                        │
  Rung 3:               │
  ═══[CT0.QU]═══(Q0.0)═══

  Rung 4 — Zamknij bramkę po czasie:
  ═══[TM0.Q]═══[R]═══
          │    CT0    │
          └───────────┘
```

---

## 7.8 Ćwiczenia praktyczne

### Ćwiczenie 1 — Licznik od 0 do 5

**Zadanie:** Każdy impuls na I0.0 zwiększa wartość w rejestrze %MW0 o 1. Po osiągnięciu 5, wartość wraca do 0 automatycznie. Wyjście Q0.0 = 1 gdy wartość = 5.

### Ćwiczenie 2 — Licznik z przyciskiem reset

**Zadanie:** I0.0 zlicza w górę, I0.1 zlicza w dół. PV = 10. Q0.0 = 1 gdy CV >= 10. I0.2 resetuje licznik.

### Ćwiczenie 3 — Dwie Bramki

**Zadanie:** Czujnik I0.0 liczy elementy. Po 10 sztukach otwiera się bramka 1 (Q0.0) i licznik resetuje się. Po kolejnych 15 sztukach otwiera się bramka 2 (Q0.1).

---

## 7.9 Podsumowanie

| Typ | Wejście | Wyjście | Zastosowanie |
|-----|---------|---------|-------------|
| **CTU** | CU (rosnące zbocze) | QU (CV >= PV) | Liczenie w górę |
| **CTD** | CD (rosnące zbocze) | QD (CV <= 0) | Liczenie w dół |
| **CTUD** | CU + CD | QU + QD | Liczenie w obie strony |

> **Następny rozdział:** [Operacje na danych i rejestry](./rozdzial-08-dane.md)

> [Powrót do spisu treści](./README.md)
