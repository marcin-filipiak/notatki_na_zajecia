# TDD – Test Driven Development

**TDD** (ang. *Test Driven Development*, rozwój sterowany testami) to technika tworzenia oprogramowania, w której **najpierw piszemy test**, a dopiero potem kod, który ma ten test spełnić. To odwrócenie tradycyjnego podejścia, w którym najpierw pisze się kod, a testy dopiero potem.

---

## Cykl TDD (Red-Green-Refactor)

Praca w TDD opiera się na powtarzanym cyklu składającym się z trzech kroków:

```
   ┌───────────────────────────────────────┐
   │                                       │
   ▼                                       │
[RED] → [GREEN] → [REFACTOR] ──────────────┘
```

### 1. RED (czerwony)
- Piszemy **test**, który sprawdza nową funkcjonalność.
- Uruchamiamy test – **zawodzi** (jest "czerwony"), bo funkcja jeszcze nie istnieje.
- Stan zawiedzenia testu jest dowodem, że test faktycznie coś sprawdza.

### 2. GREEN (zielony)
- Piszemy **najprostszy możliwy kod**, który sprawi, że test przejdzie.
- Uruchamiamy test – **przechodzi** (jest "zielony").

### 3. REFACTOR (refaktoryzacja)
- Ulepszamy kod (czytelność, wydajność, struktura) **nie zmieniając jego zachowania**.
- Cały czas uruchamiamy testy, aby upewnić się, że nic nie jest zepsute.

Następnie przechodzimy do kolejnej funkcjonalności i cały cykl powtarza się od nowa.

---

## Przykład TDD krok po kroku

**Zadanie:** Napisz funkcję `factorial(n)`, która oblicza silnię.

### Krok 1: RED – piszemy test

```python
def test_factorial():
    assert factorial(0) == 1
    assert factorial(1) == 1
    assert factorial(5) == 120
```

Uruchamiamy test → `NameError: name 'factorial' is not defined` (test zawodzi).

### Krok 2: GREEN – piszemy najmniej kodu, aby test przeszedł

```python
def factorial(n):
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result
```

Uruchamiamy test → przechodzi.

### Krok 3: REFACTOR – ulepszamy bez zmiany zachowania

Kod jest już prosty, więc możemy go zostawić. Testy dalej przechodzą.

---

## Dlaczego TDD jest wartościowe?

1. **Zaczynamy od wymagań** – zanim napiszemy kod, musimy jasno określić, co ma robić.
2. **Automatyczny zestaw testów** – mamy ciągłą "siatkę bezpieczeństwa".
3. **Wcześniejsze wykrywanie błędów** – każda funkcjonalność jest od razu testowana.
4. **Prostszy kod** – piszemy tylko tyle kodu, ile potrzeba, by przejść testy.
5. **Dokumentacja** – testy pokazują, jak powinny działać funkcje.
6. **Ułatwiona refaktoryzacja** – bez obaw można przebudowywać kod.

---

## Różnica: TDD a zwykłe pisanie testów

| Tradycyjne podejście | TDD |
|----------------------|-----|
| Najpierw kod, potem testy | Najpierw test, potem kod |
| Testy pisane na końcu, często pomijane | Testy są integralną częścią procesu |
| Trudno oszacować, co testować | Wymagania są testowane od początku |
| Mniejsze pokrycie testami | Wysokie pokrycie testami |

---

## Testy w TDD a testy jednostkowe

W technice TDD piszemy głównie **testy jednostkowe**, bo:
- Są szybkie i pozwalają natychmiastowo sprawdzić kod.
- Izolują konkretną funkcjonalność.
- Ułatwiają cykl red-green-refactor.

TDD nie zastępuje testów integracyjnych, funkcjonalnych ani innych – one wciąż są potrzebne, ale TDD poprawia jakość kodu na najniższym poziomie.

---

## Wady i wyzwania TDD

- **Wymaga dyscypliny** – łatwo "oszczędzić" sobie pisania testów.
- **Może spowolnić początkowo rozwój** – pisanie testów zajmuje czas.
- **Testy trudne do napisania dla niektórych elementów** – np. interfejsów graficznych.
- **Zła praktyka testów** – jeśli testy są źle napisane, TDD nie pomoże.

---

## Powiązane pojęcia

### BDD (Behavior Driven Development)
Rozwój sterowany zachowaniem – rozszerzenie TDD, w którym testy pisze się w języku zrozumiałym dla nietechnicznych interesariuszy (np. Gherkin: `Given... When... Then...`).

### ATDD (Acceptance Test Driven Development)
Przypadki akceptacyjne pisane są przed implementacją, wspólnie z klientem.

### RED-GREEN-REFACTOR w praktyce
- **RED:** test zawodzi → dowód, że wymaganie nie jest spełnione.
- **GREEN:** kod działa → wymaganie spełnione.
- **REFACTOR:** kod jest ładniejszy, a testy nadal przechodzą.

---

## Podsumowanie

- TDD odwraca kolejność: najpierw test, potem kod.
- Cykl RED-GREEN-REFACTOR jest sercem podejścia.
- Tworzy automatyczny zestaw testów i ułatwia utrzymanie jakości.
- Wymaga dyscypliny, ale znacząco poprawia jakość i niezawodność oprogramowania.
