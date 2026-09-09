# Rozdział 5 — Bramki logiczne i kombinacje

> [Powrót do spisu treści](./README.md)

---

## 5.1 Podstawowe funkcje logiczne w drabince

W języku drabinkowym funkcje logiczne realizowane są za pomocą **połączeń szeregowych i równoległych** styków.

---

## 5.2 Funkcja AND (szeregowe)

Styki połączone **szeregowo** realizują funkcję **AND** (iloczyn logiczny).

```
  ═══| |═══| |═══| |═══(Q0.0)═══
     A      B      C
```

**Warunek:** A=1 **AND** B=1 **AND** C=1 → Q0.0=1

**Tabela prawdy (2 wejścia):**

| A | B | Q = A AND B |
|---|---|-------------|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

---

## 5.3 Funkcja OR (równoległe)

Styki połączone **równolegle** realizują funkcję **OR** (suma logiczna).

```
  ═══| |═══┬═══| |═══(Q0.0)═══
     A     │    C
           │
  ═══| |═══┘
     B
```

**Warunek:** (A=1 **OR** B=1) **AND** C=1 → Q0.0=1

**Tabela prawdy (2 wejścia OR):**

| A | B | Q = A OR B |
|---|---|------------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

---

## 5.4 Funkcja NOT (styki NC)

Styk NC realizuje funkcję **NOT** (negacja).

```
  ═══|/|═══(Q0.0)═══
     A       Q0.0

  Q0.0 = NOT A
```

| A | Q = NOT A |
|---|-----------|
| 0 | 1 |
| 1 | 0 |

---

## 5.5 Funkcja XOR (excluding OR)

XOR (alternatywa wykluczająca) — prawda gdy **dokładnie jedno** z wejść jest aktywne.

```
  ═══| |═══|/|═══┬═══| |═══| |═══(Q0.0)═══
     A      B    │    C      D
                 │
  ═══|/|═══| |═══┘
     A      B

  Q0.0 = (A AND NOT B) OR (NOT A AND B)
```

W uproszczeniu (2 wejścia):

```
  ═══| |═══|/|═══┬═══|/|═══| |═══(Q0.0)═══
     A      B    │    A      B
```

---

## 5.6 Bloki SET i RESET (S/R)

### Blok SET

```
  ═══| |═══(S)═══
     I0.0   Q0.0
```

- Gdy I0.0 = 1 → Q0.0 zostaje **ustawiony na 1**
- Po puszczeniu I0.0 → Q0.0 **pozostaje 1** (zapamiętywanie)

### Blok RESET

```
  ═══| |═══(R)═══
     I0.1   Q0.0
```

- Gdy I0.1 = 1 → Q0.0 zostaje **ustawiony na 0**

### Priorytet

Jeśli oba warunki są spełnione jednocześnie (SET i RESET na tym samym bicie):
- **RESET ma priorytet** (w M221)
- Q0.0 = 0

### Zastosowanie — przycisk z zapamiętaniem

```
  Rung 1:  ═══| |═══(S)═══      ; START zapamiętuje ON
              I0.0   Q0.0

  Rung 2:  ═══| |═══(R)═══      ; STOP kasuje
              I0.1   Q0.0
```

---

## 5.7 Złożone kombinacje logiczne

### Przykład 1: Sterowanie bramą garażową

Warunki:
- Bramka otwiera się gdy: przycisk OTWÓRZ (I0.0) **OR** pilot (I0.2)
- Bramka zamyka się gdy: przycisk ZAMKNIJ (I0.1) **AND** brama nie jest otwarta (I0.3 = 0)
- Wyłączenie awaryjne:wyłącznik STOP (I0.4) = 1 → wszystko OFF

```
  Rung 1 — Otwieranie:
  ═══| |═══|/|═══|/|═══(S)═══
     I0.0  I0.4  I0.3  Q0.0       ; Otwieranie

  ═══| |═══|/|═══|/|═══(S)═══
     I0.2  I0.4  I0.3  Q0.0       ; Otwieranie (pilot)

  Rung 2 — Zamykanie:
  ═══| |═══|/|═══|/|═══(S)═══
     I0.1  I0.4  Q0.0  Q0.1       ; Zamykanie

  Rung 3 — Wyłączenie awaryjne:
  ═══| |═══(R)═══(R)═══
     I0.4  Q0.0  Q0.1             ; STOP awaryjny
```

### Przykład 2: Kombinacja warunków czasowych

```
  Rung 1 — Lampa miga co 500ms:
  ═══| |═══| |═══(Q0.0)═══       ; Start i timer OK
     I0.0  T1.Q

  Timer T1: TON, PT=500ms, wywoływany z M0 (migający bit)
```

---

## 5.8 Ćwiczenia praktyczne

### Ćwiczenie 1 — TRZECI KLUCZ

**Zadanie:** Dwa wyłączniki I0.0 i I0.1 sterują lampką Q0.0. Lampa świeci gdy:
- Oba wyłączniki są w tej samej pozycji (oba ON luboba OFF)

**Podpowiedź:** Zastosuj funkcję XOR i negację.

### Ćwiczenie 2 — STEROWANIE DWÓCH LAMPEK

**Zadanie:** Trzy przyciski (I0.0, I0.1, I0.2). Lampa Q0.0 włącza się gdy:
- I0.0 lub I0.1 jest wciśnięty
- I0.2 NIE jest wciśnięty

Lampa Q0.1 włącza się gdy:
- Wszystkie trzy przyciski są wciśnięte

### Ćwiczenie 3 — ZAPAMIĘTYWANIE STANU

**Zadanie:** Przycisk I0.0 cyklicznie przełącza stan lampki Q0.0 (ON/OFF) za każdym razem gdy jest wciśnięty. Użyj bloków SET/RESET i markera M0.

```
  Rung 1 — Zapamiętaj nowy stan:
  ═══| |═══|/|═══(S)═══
     I0.0  M0    M0

  Rung 2 — Przełącz lampkę:
  ═══| |═══( )═══
     M0    Q0.0

  Rung 3 — Resetera po odliczeniu:
  ═══| |═══(R)═══
     I0.0  M0
```

---

## 5.9 Podsumowanie

| Funkcja | Realizacja w drabince | Operator |
|---------|----------------------|----------|
| AND | Styki szeregowo | `| |` + `| |` |
| OR | Styki równolegle | gałąź równoległa |
| NOT | Styk NC | `|/|` |
| XOR | Kombinacja AND+OR+NOT | *(patrz 5.5)* |
| SET | Blok (S) | `(S)` |
| RESET | Blok (R) | `(R)` |

> **Następny rozdział:** [Timery (Opóźnienia czasowe)](./rozdzial-06-timery.md)

> [Powrót do spisu treści](./README.md)
