# Rozdział 6 — Timery (Opóźnienia czasowe)

> [Powrót do spisu treści](./README.md)

---

## 6.1 Przegląd timerów w M221

Timer to **blok funkcyjny** realizujący opóźnienie czasowe. M221 udostępnia **32 timery** (TM0–TM31), każdy o strukturze:

```
  Struktura timera TM221:
  ┌─────────────────────────┐
  │ Timer TMx               │
  │ ├── IN    (wejście)     │
  │ ├── PT    (czas zadany) │
  │ ├── ET    (czas bieżący)│
  │ ├── Q     (wyjście)     │
  │ └── INO   (numer timera)│
  └─────────────────────────┘
```

| Parametr | Opis |
|----------|------|
| **IN** | Wejście sterujące (BOOL) |
| **PT** | Czas zadany (*Preset Time*) — po jakim czasie timer reaguje |
| **ET** | Czas bieżący (*Elapsed Time*) — ile czasu już upłynęło |
| **Q** | Wyjście timera (BOOL) — stan po upływie PT |

### Jednostki czasowe w M221

| Jednostka | Oznaczenie | Zakres |
|-----------|-----------|--------|
| Milisekundy | ms | 0–32767 ms |
| Sekundy | s | 0–32767 s |

> W SoMachine Basic wpisujesz wartość PT w milisekundach (np. `5000` = 5 sekund).

---

## 6.2 TON — opóźnienie załączenia (On-Delay Timer)

**TON** — timer z opóźnieniem **włączenia**. Wyjście Q załącza się dopiero po upływie czasu PT.

### Schemat działania

```
  Wejście IN:  ─────┐          ┌─────
                     └──────────┘

  Wyjście Q:   ─────────────┐          ┌─────
                             └──────────┘
                         ▲
                    Opóźnienie PT
```

### Realizacja w drabince

```
  Rung 1:
  ═══| |═══[TON]═══
     I0.0  │ TM0  │
           │ IN   │
           │ PT   │ = 5000 ms (5 s)
           │ Q    │
           │ ET   │
           └──────┘

  Rung 2:
  ═══[TM0.Q]═══(Q0.0)═══    ; Wyjście timera
```

### Tabela prawdy TON

| IN | ET < PT | ET >= PT | Q |
|----|---------|----------|---|
| 0 | — | — | 0 (natychmiast) |
| 1 | rośnie | osiągnięto PT | 1 |

### Zachowanie TON
1. Gdy **IN = 1**: timer zaczyna odliczać
2. Gdy **ET reaches PT**: Q = 1
3. Gdy **IN = 0**: Q = 0 natychmiast, ET = 0

---

## 6.3 TOF — opóźnienie wyłączenia (Off-Delay Timer)

**TOF** — timer z opóźnieniem **wyłączenia**. Wyjście Q wyłącza się dopiero po upływie czasu PT od momentu wyłączenia IN.

### Schemat działania

```
  Wejście IN:  ─────┐          ┌─────
                     └──────────┘

  Wyjście Q:   ──────────────────┐
                                  └──────
                              ▲
                         Opóźnienie PT
```

### Realizacja w drabince

```
  Rung 1:
  ═══| |═══[TOF]═══
     I0.0  │ TM1  │
           │ IN   │
           │ PT   │ = 3000 ms (3 s)
           │ Q    │
           │ ET   │
           └──────┘

  Rung 2:
  ═══[TM1.Q]═══(Q0.1)═══
```

### Zachowanie TOF
1. Gdy **IN = 1**: Q = 1 natychmiast, ET = 0
2. Gdy **IN = 0**: timer zaczyna odliczać
3. Gdy **ET reaches PT**: Q = 0

---

## 6.4 TP — monostabilny (Pulse Timer)

**TP** — generuje **impuls o zadanym czasie trwania** niezależnie od czasu trwania sygnału na wejściu IN.

### Schemat działania

```
  Wejście IN:  ──┐              ┌──
                  └──────────────┘

  Wyjście Q:   ──────────┐
                          └──────
                     ▲
                Impuls PT
```

### Realizacja w drabince

```
  Rung 1:
  ═══| |═══[TP]═══
     I0.0  │ TM2  │
           │ IN   │
           │ PT   │ = 2000 ms (2 s)
           │ Q    │
           │ ET   │
           └──────┘

  Rung 2:
  ═══[TM2.Q]═══(Q0.2)═══
```

### Zachowanie TP
1. Na **rosnącym zboczu IN** (0→1): Q = 1 na czas PT
2. Wyjście Q = 1 przez **dokładnie PT** niezależnie od IN
3. Po upływie PT: Q = 0

---

## 6.5 RTIM — reset timera

Aby zresetować timer (zerować ET) przed osiągnięciem PT, użyj bloku **RTIM** lub zastosuj poniższy trick:

### Metoda 1: Przerwanie zasilania IN
Wystarczy ustawić IN na 0 — timer zresetuje się automatycznie.

### Metoda 2: Blok RTIM
```
  ═══| |═══[RTIM]═══
     I0.1  │ TM0  │
           └──────┘
```

---

## 6.6 Przykłady zastosowań timera

### Przykład 1 — Opóźnienie włączenia wentylatora

**Zadanie:** Po włączeniu przycisku (I0.0) wentylator (Q0.0) uruchamia się po 3 sekundach.

```
  Rung 1:
  ═══| |═══[TON]═══
     I0.0  │ TM0  │
           │ PT   │ = 3000
           │ Q    │──┐
           └──────┘  │
                     │
  Rung 2:            │
  ═══[TM0.Q]═══(Q0.0)═══
```

### Przykład 2 — Auto-wyłączenie lampy (schodowe)

**Zadanie:** Naciśnięcie I0.0 włącza lampę Q0.0 na 30 sekund. Po 30s lampa gaśnie.

```
  Rung 1:
  ═══| |═══|/|═══[TON]═══
     I0.0  TM0.Q │ TM0  │
                  │ PT   │ = 30000
                  │ Q    │──┐
                  └──────┘  │
                            │
  Rung 2:                   │
  ═══| |═══[TM0.Q]═══(Q0.0)═══
     I0.0
```

### Przykład 3 — Migacz (kierunkowskaz)

**Zadanie:** Lampa Q0.0 miga z częstotliwością 1 Hz (500ms ON, 500ms OFF).

```
  Rung 1:
  ═══|/|═══[TON]═══(M0)═══
     M0    │ TM0  │
           │ PT   │ = 500
           └──────┘

  Rung 2:
  ═══| |═══[TON]═══(M1)═══
     M0    │ TM1  │
           │ PT   │ = 500
           └──────┘

  Rung 3:
  ═══| |═══(Q0.0)═══
     M1
```

---

## 6.7 Ćwiczenia praktyczne

### Ćwiczenie 1 — Opóźnienie wyłączenia

**Zadanie:** Przycisk I0.0 włącza silnik Q0.0. Po puszczeniu I0.0 silnik pracuje jeszcze 5 sekund.

**Wskazówka:** Użyj timera **TOF**.

### Ćwiczenie 2 — Sekwencja czasowa

**Zadanie:** Po wciśnięciu I0.0:
1. Po 1s zapala się Q0.0
2. Po kolejnych 2s zapala się Q0.1
3. Po kolejnych 3s oba wyłączają się

**Wskazówka:** Użyj **ton.chain** (połączonych timerów).

### Ćwiczenie 3 — Generator impulsów

**Zadanie:** Wygeneruj sygnał o częstotliwości 0.5 Hz (1s okres) na wyjściu Q0.0. Sygnał powinien być kwadratem 50% duty cycle.

---

## 6.8 Podsumowanie

| Typ timera | Zastosowanie | Zachowanie |
|------------|-------------|------------|
| **TON** | Opóźnienie włączenia | Q=1 po upływie PT |
| **TOF** | Opóźnienie wyłączenia | Q=0 po upływie PT od wyłączenia IN |
| **TP** | Impuls o stałej długości | Q=1 dokładnie przez PT |
| **RTIM** | Reset timera | Zeruje ET |

> **Następny rozdział:** [Liczniki (Counters)](./rozdzial-07-liczniki.md)

> [Powrót do spisu treści](./README.md)
