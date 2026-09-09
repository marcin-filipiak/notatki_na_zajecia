# Projekt 2 — Sekwencja sterowań z timerami

> [Powrót do spisu treści](./README.md)

---

## Cel projektu

Zrealizować automatyczną **sekwencję uruchamiania urządzeń** z wykorzystaniem timerów i pracy w trybie **automatycznym** i **ręcznym**.

---

## Zadanie

Po włączeniu przycisku START (I0.0):
1. Po 0s załącza się wentylator (Q0.0)
2. Po 2s załącza się pompa (Q0.1)
3. Po 5s załącza się grzałka (Q0.2)
4. Po 10s załącza się sygnał gotowości (Q0.3)

Wyłączenie STOP (I0.1) wyłącza **wszystko natychmiast**.

Tryb pracy:
- **Ręczny** (I0.2 = 0): Każdy przycisk ręcznie włącza/wyłącza urządzenie
- **Automatyczny** (I0.2 = 1): Sekwencja czasowa

---

## Tabela zmiennych

| Nazwa | Adres | Typ | Opis |
|-------|-------|-----|------|
| Start | %I0.0 | BOOL | Przycisk START |
| Stop | %I0.1 | BOOL | Przycisk STOP |
| Tryb_Auto | %I0.2 | BOOL | Przełącznik auto/ręczny |
| Wentylator | %Q0.0 | BOOL | Wentylator chłodzący |
| Pompa | %Q0.1 | BOOL | Pompa obiegowa |
| Grzalka | %Q0.2 | BOOL | Grzałka |
| Sygnal_Gotowosci | %Q0.3 | BOOL | Lampka gotowości |
| Timer_Sekwencja | %TM0 | TIMER | Timer sekwencji |
| Marker_Start | %M0 | BOOL | Zapamiętanie START |
| Marker_2s | %M1 | BOOL | Zdarzenie po 2s |
| Marker_5s | %M2 | BOOL | Zdarzenie po 5s |
| Marker_10s | %M3 | BOOL | Zdarzenie po 10s |

---

## Program drabinkowy

### Sekcja 1 — Zapamiętanie stanu

```
  Rung 1 — START / STOP latch:
  ═══| |═══|/|═══(S)═══
     I0.0  I0.1  M0

  Rung 2 — STOP resetuje wszystko:
  ═══| |═══(R)═══(R)═══(R)═══(R)═══
     I0.1  Q0.0  Q0.1  Q0.2  Q0.3
```

### Sekcja 2 — Tryb automatyczny (sekwencja timerów)

```
  Rung 3 — Timer 0-2s (wentylator):
  ═══| |═══| |═══[TON]═══
     M0    I0.2  │ TM0  │
                  │ IN   │
                  │ PT   │ = 2000
                  │ Q    │──┐
                  └──────┘  │
                            │
  Rung 4:                    │
  ═══[TM0.Q]═══(Q0.0)═══   ; Wentylator po 0s (natychmiast)
```

### Sekcja 3 — Timer 2s (pompa)

```
  Rung 5 — Timer 2-5s (pompa):
  ═══| |═══| |═══[TON]═══
     M0    I0.2  │ TM1  │
                  │ IN   │
                  │ PT   │ = 5000
                  │ Q    │──┐
                  └──────┘  │
                            │
  Rung 6:                    │
  ═══[TM1.Q]═══(Q0.1)═══   ; Pompa po 5s
```

### Sekcja 4 — Timer 5s (grzałka)

```
  Rung 7 — Timer 5-10s (grzałka):
  ═══| |═══| |═══[TON]═══
     M0    I0.2  │ TM2  │
                  │ IN   │
                  │ PT   │ = 10000
                  │ Q    │──┐
                  └──────┘  │
                            │
  Rung 8:                    │
  ═══[TM2.Q]═══(Q0.2)═══   ; Grzałka po 10s
```

### Sekcja 5 — Sygnał gotowości

```
  Rung 9 — Sygnał gotowości (po 10s):
  ═══| |═══| |═══(Q0.3)═══
     M0    TM2.Q
```

---

## Tryb ręczny

```
  Rung 10 — Ręczne sterowanie wentylatorem:
  ═══| |═══|/|═══| |═══(Q0.0)═══
     I0.3  I0.2  M0

  Rung 11 — Ręczne sterowanie pompą:
  ═══| |═══|/|═══| |═══(Q0.1)═══
     I0.4  I0.2  M0

  Rung 12 — Ręczne sterowanie grzałką:
  ═══| |═══|/|═══| |═══(Q0.2)═══
     I0.5  I0.2  M0
```

---

## Diagram sekwencji czasowej

```
  Czas (s):  0    2    5    10
             │    │    │    │
  Wentylator: ████████████████████
  Pompa:      ░░░░░████████████████
  Grzałka:    ░░░░░░░░░░██████████
  Gotowość:   ░░░░░░░░░░░░░░░░░░██

  █ = ON    ░ = OFF
```

---

## Testowanie

| # | Akcja | Oczekiwany wynik |
|---|-------|------------------|
| 1 | Wciśnij START (tryb auto) | Wentylator włącza się natychmiast |
| 2 | Poczekaj 2s | Pompa się włącza |
| 3 | Poczekaj 5s | Grzałka się włącza |
| 4 | Poczekaj 10s | Sygnał gotowości |
| 5 | Wciśnij STOP | Wszystko wyłącza się natychmiast |

---

> [Powrót do spisu treści](./README.md)
