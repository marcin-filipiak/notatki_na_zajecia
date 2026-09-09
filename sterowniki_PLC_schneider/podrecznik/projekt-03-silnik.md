# Projekt 3 — Sterowanie silnikiem krokowym

> [Powrót do spisu treści](./README.md)

---

## Cel projektu

Zrealizować sterowanie **silnikiem krokowym** za pomocą wyjść cyfrowych sterownika PLC z wykorzystaniem generatora impulsów.

---

## Zadanie

Sterować silnikiem krokowym podłączonym do wyjść Q0.0–Q0.3:
1. **Obroty w prawo** — sekwencja 1000 → 0100 → 0010 → 0001 (cyklicznie)
2. **Obroty w lewo** — sekwencja 1000 → 0001 → 0010 → 0100 (cyklicznie)
3. **Regulacja prędkości** — zmiana częstotliwości impulsów (timer)
4. **Stop** — zatrzymanie po zakończeniu sekwencji

---

## Tabela zmiennych

| Nazwa | Adres | Typ | Opis |
|-------|-------|-----|------|
| Start_P | %I0.0 | BOOL | Start obrotów w prawo |
| Start_L | %I0.1 | BOOL | Start obrotów w lewo |
| Stop_S | %I0.2 | BOOL | Stop silnika |
| Predkosc+ | %I0.3 | BOOL | Zwiększ prędkość |
| Predkosc- | %I0.4 | BOOL | Zmniejsz prędkość |
| Silnik_A | %Q0.0 | BOOL | Cewka A silnika |
| Silnik_B | %Q0.1 | BOOL | Cewka B silnika |
| Silnik_C | %Q0.2 | BOOL | Cewka C silnika |
| Silnik_D | %Q0.3 | BOOL | Cewka D silnika |
| Timer_Obrotow | %TM0 | TIMER | Timer obrotów silnika |
| Krok | %MW0 | INT | Numer bieżącego kroku |
| Predkosc | %MW1 | INT | Czas kroku (ms) |
| Kierunek | %M0 | BOOL | 0 = prawo, 1 = lewo |

---

## Sekwencja krokowa (half-step)

### Prawo (Kierunek = 0)

| Krok | Q0.3 | Q0.2 | Q0.1 | Q0.0 |
|------|------|------|------|------|
| 0 | 1 | 0 | 0 | 0 |
| 1 | 1 | 1 | 0 | 0 |
| 2 | 0 | 1 | 0 | 0 |
| 3 | 0 | 1 | 1 | 0 |
| 4 | 0 | 0 | 1 | 0 |
| 5 | 0 | 0 | 1 | 1 |
| 6 | 0 | 0 | 0 | 1 |
| 7 | 1 | 0 | 0 | 1 |

### Lewo (Kierunek = 1)

| Krok | Q0.3 | Q0.2 | Q0.1 | Q0.0 |
|------|------|------|------|------|
| 0 | 0 | 0 | 0 | 1 |
| 1 | 0 | 0 | 1 | 1 |
| 2 | 0 | 0 | 1 | 0 |
| 3 | 0 | 1 | 1 | 0 |
| 4 | 0 | 1 | 0 | 0 |
| 5 | 1 | 1 | 0 | 0 |
| 6 | 1 | 0 | 0 | 0 |
| 7 | 1 | 0 | 0 | 1 |

---

## Program drabinkowy

### Sekcja 1 — Start i kierunek

```
  Rung 1 — Zapamiętaj kierunek:
  ═══| |═══(S)═══
     I0.0  M0        ; Prawo

  ═══| |═══(R)═══
     I0.1  M0        ; Lewo

  Rung 2 — Start/Stop:
  ═══| |═══|/|═══(S)═══
     I0.0  I0.2  M10  ; M10 = silnik pracuje

  ═══| |═══(R)═══
     I0.2  M10        ; Stop
```

### Sekcja 2 — Timer obrotów

```
  Rung 3 — Timer prędkości:
  ═══|/|═══[TON]═══(M11)═══
     M11   │ TM0  │
           │ IN   │
           │ PT   │ = %MW1  ; Zmienna prędkość
           └──────┘
```

### Sekcja 3 — Sekwencja krokowa (Prawo)

```
  Rung 4 — Inkrementacja kroku:
  ═══| |═══|/|═══[ADD]═══
     M10   M0    │ IN1  │ = %MW0
                  │ IN2  │ = 1
                  │ OUT  │ = %MW0
                  └──────┘

  Rung 5 — Reset kroku po osiągnięciu 8:
  ═══[>=]═══[MOVE]═══
     │ MW0  │ │ IN  │ = 0
     │ 8    │ │ OUT │ = %MW0
     └──────┘ └─────┘
```

### Sekcja 4 — Dekoder kroku → wyjścia

```
  Rung 6 — Krok 0:
  ═══[=]═══| |═══(Q0.3)═══
     │ MW0  │  M10
     │ 0    │
     └──────┘

  Rung 7 — Krok 1:
  ═══[=]═══| |═══(Q0.3)═══(Q0.2)═══
     │ MW0  │  M10
     │ 1    │
     └──────┘

  Rung 8 — Krok 2:
  ═══[=]═══| |═══(Q0.2)═══
     │ MW0  │  M10
     │ 2    │
     └──────┘

  ; ... (kontynuacja dla kroków 3-7)
```

---

## Regulacja prędkości

```
  Rung 10 — Zwiększ prędkość:
  ═══| |═══[SUB]═══
     I0.3  │ IN1  │ = %MW1
           │ IN2  │ = 50
           │ OUT  │ = %MW1
           └──────┘

  Rung 11 — Zmniejsz prędkość:
  ═══| |═══[ADD]═══
     I0.4  │ IN1  │ = %MW1
           │ IN2  │ = 50
           │ OUT  │ = %MW1
           └──────┘

  Rung 12 — Ograniczenie:
  ═══[<=]═══[MOVE]═══
     │ MW1  │ │ IN  │ = 50
     │ 50   │ │ OUT │ = %MW1
     └──────┘ └─────┘

  ═══[>=]═══[MOVE]═══
     │ MW1  │ │ IN  │ = 1000
     │ 1000 │ │ OUT │ = %MW1
     └──────┘ └─────┘
```

---

## Schemat połączeń

```
  TM221M16R
  ┌──────────────────────────────────────┐
  │ I0.0 ── Start Prawo                  │
  │ I0.1 ── Start Lewo                   │
  │ I0.2 ── Stop                         │
  │ I0.3 ── Prędkość +                   │
  │ I0.4 ── Prędkość -                   │
  │                                      │
  │ Q0.0 ──▶ Silnik krokowy A            │
  │ Q0.1 ──▶ Silnik krokowy B            │
  │ Q0.2 ──▶ Silnik krokowy C            │
  │ Q0.3 ──▶ Silnik krokowy D            │
  └──────────────────────────────────────┘
```

---

## Testowanie

| # | Akcja | Oczekiwany wynik |
|---|-------|------------------|
| 1 | Start Prawo | Silnik obraca się w prawo |
| 2 | Start Lewo | Silnik obraca się w lewo |
| 3 | Stop | Silnik zatrzymuje się |
| 4 | Prędkość +/- | Zmiana prędkości obrotów |

---

> [Powrót do spisu treści](./README.md)
