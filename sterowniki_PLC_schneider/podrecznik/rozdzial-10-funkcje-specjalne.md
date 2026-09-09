# Rozdział 10 — Funkcje specjalne

> [Powrót do spisu treści](./README.md)

---

## 10.1 Przegląd funkcji specjalnych

M221 oferuje szereg zaawansowanych funkcji wykraczających poza podstawową logikę drabinkową.

---

## 10.2 Przetwornik analogowy

TM221M16R sam nie posiada wejść/wyjść analogowych, ale obsługuje je przez **moduły rozszerzeń TM2**.

### Dostępne moduły analogowe

| Moduł | Wejścia | Wyjścia | Zakres |
|-------|---------|---------|--------|
| **TM2AI4** | 4 AI | — | 0–10V, 4–20mA |
| **TM2AO2** | — | 2 AO | 0–10V, 4–20mA |
| **TM2AM6GT** | 2 AI | 2 AO | 0–10V, 4–20mA |

### Adresacja modułów analogowych

| Moduł | Adres wejścia | Adres wyjścia |
|-------|---------------|---------------|
| TM2AI4 (slot 1) | %IW0 – %IW3 | — |
| TM2AO2 (slot 1) | — | %QW0 – %QW1 |

### Skalowanie sygnału analogowego

```
  Zakres fizyczny:     0 ─────────────────── 100 °C
                        │                     │
  Zakres surowy:        0 ─────────────────── 4095
  (12-bit ADC)

  Skalowanie:
  Temp (°C) = (Surowa × 100) / 4095
```

### Realizacja w drabince

```
  Rung 1 — Odczyt surowy:
  ═══[MOVE]═══
     │ IN   │ = %IW0
     │ OUT  │ = %MW0
     └──────┘

  Rung 2 — Skalowanie (× 100):
  ═══[MUL]═══
     │ IN1  │ = %MW0
     │ IN2  │ = 100
     │ OUT  │ = %MW1
     └──────┘

  Rung 3 — Dzielenie (÷ 4095):
  ═══[DIV]═══
     │ IN1  │ = %MW1
     │ IN2  │ = 4095
     │ OUT  │ = %MW2
     └──────┘

  ; %MW2 = temperatura w °C
```

---

## 10.3 Funkcja PWM

**PWM** (Pulse Width Modulation) — modulacja szerokości impulsu. Umożliwia sterowanie **mocą** urządzeń (np. grzałki, silnika) poprzez zmianę czasu załączenia.

### Realizacja PWM w M221

M221 nie posiada dedykowanego bloku PWM, ale można go zrealizować za pomocą **timera**:

```
  Cel: PWM o częstotliwości 1 Hz (1000ms), wypełnienie 30%

  Rung 1 — Timer okresu:
  ═══|/|═══[TON]═══(M100)═══
     M100  │ TM0  │
           │ PT   │ = 1000
           └──────┘

  Rung 2 — Timer wypełnienia:
  ═══| |═══[TON]═══(M101)═══
     M100  │ TM1  │
           │ PT   │ = 300    ; 30% z 1000ms = 300ms
           └──────┘

  Rung 3 — Wyjście PWM:
  ═══| |═══|/|═══(Q0.0)═══
     M100  M101

  ; Q0.0 = 1 przez 300ms, 0 przez 700ms
```

### Zastosowania PWM

- **Grzanie:** Regulacja mocy grzałki
- **Oświetlenie:** Ściemniacze LED
- **Silniki DC:** Regulacja prędkości

---

## 10.4 Funkcja rampy (RAMP)

**RAMP** — generuje sygnał rosnący lub malejący liniowo od wartości początkowej do końcowej.

### Realizacja rampy

```
  Cel: Zwiększaj %MW0 od 0 do 1000 z szybkością 1/s

  Rung 1 — Timer co 1s:
  ═══| |═══[TON]═══(M200)═══
     I0.0  │ TM2  │
           │ PT   │ = 1000
           └──────┘

  Rung 2 — Inkrementacja:
  ═══[M200]═══[ADD]═══
            │ IN1  │ = %MW0
            │ IN2  │ = 1
            │ OUT  │ = %MW0
            └──────┘

  Rung 3 — Warunek brzegowy:
  ═══[>=]═══[R]═══
     │ MW0  │     │ I0.0 │
     │ 1000 │     └──────┘
     └──────┘

  ; %MW0 rośnie od 0 do 1000
```

---

## 10.5 HSC — High Speed Counter (Licznik szybki)

**HSC** to licznik zliczający impulsy o częstotliwości **do 100 kHz** — zbyt szybkie dla normalnego cyklu skanowania PLC.

### Zastosowania HSC

- **Enkodery obrotowe** — pomiar prędkości i pozycji
- **Czujniki zbliżeniowe** — liczenie elementów na taśmie
- **Silniki krokowe** — generowanie impulsów sterujących

### Konfiguracja HSC

HSC wymaga modułu **TM2HSC2** (2 liczniki szybkie).

```
  Konfiguracja HSC:
  ┌──────────────────────────┐
  │ TM2HSC2                  │
  │ ├── HSC0                  │
  │ │   ├── Wejście: A, B, Z  │
  │ │   ├── Tryb: Quadrature  │
  │ │   └── Zakres: 0–65535   │
  │ └── HSC1                  │
  │     ├── Wejście: A, B, Z  │
  │     ├── Tryb: Pulse       │
  │     └── Zakres: 0–65535   │
  └──────────────────────────┘
```

### Odczyt wartości HSC

Wartość HSC jest zapisywana do rejestru systemowego lub może być odczytana przez blok funkcyjny.

---

## 10.6 Przerwania

M221 obsługuje **przerwania programowe** — zdarzenia wywołujące wykonywanie określonego fragmentu programu.

### Rodzaje przerwań

| Typ | Opis |
|-----|------|
| **Przerwanie czasowe** | Wywoływane cyklicznie (np. co 100ms) |
| **Przerwanie na zbocze** | Wywoływane przy zmianie stanu wejścia |
| **Przerwanie komunikacyjne** | Wywoływane po odebraniu danych |

### Konfiguracja przerwania

```
  Przerwanie: INT0
  ├── Warunek: I0.0 zbocze rosnące
  ├── Priorytet: 1
  └── Program: INT0_Program
      ═══| |═══(Q0.0)═══
         I0.0
```

---

## 10.7 Watchdog i nadzór programu

**Watchdog** to mechanizm bezpieczeństwa, który resetuje sterownik jeśli program nie jest wykonywany prawidłowo.

### Parametry watchdog

| Parametr | Wartość | Opis |
|----------|---------|------|
| Watchdog timer | 200 ms (domyślnie) | Maksymalny czas jednego cyklu |
| Reakcja | Przejście w STOP | Gdy cykl trwa dłużej niż watchdog |

### Nadzór programu (Supervision)

- **Błąd programu** (np. dzielenie przez 0) → STOP
- **Przekroczenie stosu** (stack overflow) → STOP
- **Błąd pamięci** → STOP

---

## 10.8 Ćwiczenie — Regulacja temperatury z rampą

**Zadanie:** Zwiększaj temperaturę zadaną (%MW10) od 20°C do 80°C z szybkością 1°C/s. Porównuj z odczytem (%MW0). Jeśli odczyt > zadana + 5, wyłącz grzałkę Q0.0.

```
  Rung 1 — Inkrementacja temperatury zadanej:
  ═══| |═══[TON]═══[ADD]═══
     I0.0  │ TM0  │ │ IN1 │ = %MW10
           │ PT   │ │ IN2 │ = 1
           │ Q    │ │ OUT │ = %MW10
           └──────┘ └─────┘

  Rung 2 — Warunek brzegowy:
  ═══[>=]═══[R]═══
     │ MW10 │     │ I0.0 │
     │ 80   │     └──────┘
     └──────┘

  Rung 3 — Sterowanie grzałką:
  ═══[<=]═══| |═══(Q0.0)═══
     │ MW0  │  I0.0
     │ MW10+5│
     └──────┘
```

---

## 10.9 Podsumowanie

| Funkcja | Zastosowanie | Moduł |
|---------|-------------|-------|
| PWM | Regulacja mocy | Programowa |
| RAMP | Liniowa zmiana wartości | Programowa |
| HSC | Licznik szybki | TM2HSC2 |
| Analog | Wejścia/wyjścia analogowe | TM2AI4/AO2 |
| Watchdog | Nadzór programu | Wbudowany |

> **Następny rozdział:** [Diagnostyka i debugowanie](./rozdzial-11-diagnostyka.md)

> [Powrót do spisu treści](./README.md)
