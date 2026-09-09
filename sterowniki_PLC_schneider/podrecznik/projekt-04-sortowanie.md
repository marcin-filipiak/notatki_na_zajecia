# Projekt 4 — System liczenia i sortowania

> [Powrót do spisu treści](./README.md)

---

## Cel projektu

Zrealizować system **liczenia i sortowania** elementów na taśmie transportowej z użyciem czujników, liczników i timerów.

---

## Zadanie

1. Czujnik I0.0 liczy elementy przejeżdżające na taśmie
2. Czujnik I0.1 wykrywa elementy **duże** (np. czujnik wysokości)
3. Co **5 sztuk** otwiera się bramka 1 (Q0.0) na 2 sekundy — sortowanie małych
4. Co **10 sztuk** otwiera się bramka 2 (Q0.1) na 3 sekundy — sortowanie dużych
5. Przycisk I0.2 resetuje liczniki
6. Przycisk I0.3 startuje/stopa taśmę (Q0.2)

---

## Tabela zmiennych

| Nazwa | Adres | Typ | Opis |
|-------|-------|-----|------|
| Czujnik_Tasmy | %I0.0 | BOOL | Czujnik elementów na taśmie |
| Czujnik_Wielkosc | %I0.1 | BOOL | Czujnik dużych elementów |
| Reset_Sort | %I0.2 | BOOL | Reset liczników |
| Start_Tasmy | %I0.3 | BOOL | Start taśmy |
| Bramka_Mala | %Q0.0 | BOOL | Bramka dla małych |
| Bramka_Duza | %Q0.1 | BOOL | Bramka dla dużych |
| Tasmy | %Q0.2 | BOOL | Napęd taśmy |
| Licznik_Male | %CT0 | CTU | Licznik małych |
| Licznik_Duze | %CT1 | CTU | Licznik dużych |
| Timer_Bramy | %TM0 | TIMER | Czas bramki małej |
| Timer_Bramy2 | %TM1 | TIMER | Czas bramki dużej |
| Stan_Tasmy | %M0 | BOOL | Taśma pracuje |

---

## Program drabinkowy

### Sekcja 1 — Start/Stop taśmy

```
  Rung 1:
  ═══| |═══|/|═══(S)═══
     I0.3  I0.0  M0      ; Stan taśmy (zapamiętanie)

  Rung 2:
  ═══| |═══(R)═══
     I0.2  M0            ; Reset zatrzymuje

  Rung 3:
  ═══| |═══(Q0.2)═══
     M0                  ; Taśma pracuje
```

### Sekcja 2 — Licznik dużych elementów

```
  Rung 4 — Licznik dużych (co 10):
  ═══| |═══| |═══[CTU]═══
     M0    I0.1  │ CT1  │
                  │ CU   │
                  │ PV   │ = 10
                  │ R    │ = I0.2
                  │ QU   │──┐
                  └──────┘  │
                            │
  Rung 5 — Otwórz bramkę dużą:
  ═══[CT1.QU]═══(Q0.1)═══
```

### Sekcja 3 — Licznik małych elementów

```
  Rung 6 — Licznik małych (co 5):
  ═══| |═══|/|═══[CTU]═══
     M0    I0.1  │ CT0  │
                  │ CU   │
                  │ PV   │ = 5
                  │ R    │ = I0.2
                  │ QU   │──┐
                  └──────┘  │
                            │
  Rung 7 — Otwórz bramkę małą:
  ═══[CT0.QU]═══(Q0.0)═══
```

### Sekcja 4 — Timer zamknięcia bramek

```
  Rung 8 — Timer bramki małej (2s):
  ═══[CT0.QU]═══[TON]═══
              │ TM0  │
              │ PT   │ = 2000
              │ Q    │──┐
              └──────┘  │
                        │
  Rung 9 — Zamknij bramkę małą po 2s:
  ═══|/|═══[R]═══
     TM0.Q   CT0

  Rung 10 — Timer bramki dużej (3s):
  ═══[CT1.QU]═══[TON]═══
              │ TM1  │
              │ PT   │ = 3000
              │ Q    │──┐
              └──────┘  │
                        │
  Rung 11 — Zamknij bramkę dużą po 3s:
  ═══|/|═══[R]═══
     TM1.Q   CT1
```

### Sekcja 5 — Liczba wyrobów (rejestr)

```
  Rung 12 — Zliczanie całkowitego wyrobów do %MW0:
  ═══| |═══[ADD]═══
     I0.0  │ IN1  │ = %MW0
           │ IN2  │ = 1
           │ OUT  │ = %MW0
           └──────┘
```

---

## Diagram przebiegu

```
  Taśma:     ██████████████████████████████████
  ─────────────────────────────────────────────
  Małe:   ┌──┐  ┌──┐  ┌──┐  ┌──┐
          │  │  │  │  │  │  │  │
  ────────┴──┴──┴──┴──┴──┴──┴──┴──────────────
  Duże:                       ┌───┐
                              │   │
  ────────────────────────────┴───┴────────────
  
  Co 5 małych elementów → bramka 1 na 2s
  Co 10 dużych elementów → bramka 2 na 3s
```

---

## Testowanie

| # | Akcja | Oczekiwany wynik |
|---|-------|------------------|
| 1 | Start taśmy | Taśma pracuje (Q0.2=1) |
| 2 | Podaj 5 małych | Bramka 1 otwiera się na 2s |
| 3 | Podaj 10 dużych | Bramka 2 otwiera się na 3s |
| 4 | Reset | Liczniki zerowane |
| 5 | Pomiń czujnik wielkości | Tylko małe liczone |

---

## Modyfikacje i rozszerzenia

Możliwe rozszerzenia projektu:
- Dodanie **wyświetlacza** (HMI) do podglądu liczników
- Logowanie do rejestrów (historia produkcji)
- Komunikacja Modbus TCP z nadrzędnym systemem
- Alarm przy przekroczeniu liczby
- Auto-start po cyklu

---

> [Powrót do spisu treści](./README.md)
