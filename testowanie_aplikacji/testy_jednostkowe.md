# Testy jednostkowe

**Testy jednostkowe** (ang. *unit tests*) to testy, które sprawdzają pojedyncze, najmniejsze elementy oprogramowania – funkcje, metody lub klasy. Celem testu jednostkowego jest potwierdzenie, że dany komponent działa poprawnie w izolacji, bez interakcji z resztą systemu.

---

## Czym jest jednostka (unit)?

**Jednostka** to najmniejszy testowalny element kodu:
- funkcja,
- metoda,
- klasa.

Test jednostkowy wywołuje tę jednostkę z określonymi danymi wejściowymi i sprawdza, czy zwracany wynik zgadza się z oczekiwanym.

---

## Dlaczego piszemy testy jednostkowe?

1. **Szybkie wykrywanie błędów** – błąd w pojedynczej funkcji zostaje wykryty niemal natychmiast, zanim rozprzestrzeni się dalej.
2. **Ułatwienie refaktoryzacji** – po zmianie kodu testy potwierdzają, że funkcja nadal działa poprawnie.
3. **Dokumentacja kodu** – testy pokazują, jak funkcja powinna być używana.
4. **Zapewnienie jakości** – tworzą "bezpieczną siatkę" dla dalszego rozwoju.
5. **Oszczędność czasu** – automatyczne testy jednostkowe można uruchamiać wielokrotnie w ciągu kilku sekund.

---

## Przykład testu jednostkowego

Rozważmy prostą funkcję, która oblicza sumę dwóch liczb:

```cpp
int add(int a, int b) {
    return a + b;
}
```

Test jednostkowy sprawdzałby kilka przypadków:

| Przypadek | Dana wejściowa | Oczekiwany wynik |
|-----------|----------------|------------------|
| Dodawanie liczb dodatnich | add(2, 3) | 5 |
| Dodawanie liczb ujemnych | add(-1, -1) | -2 |
| Dodawanie z zerem | add(0, 5) | 5 |

---

## Frameworki do testów jednostkowych

Testy jednostkowe najczęściej pisze się z wykorzystaniem specjalnych frameworków:

| Język | Framework |
|-------|-----------|
| C++ | Google Test, Catch2, Boost.Test |
| Java | JUnit, TestNG |
| Python | unittest, pytest |
| JavaScript | Jest, Mocha, Jasmine |
| C# | NUnit, xUnit |

### Przykład testów w pytest (Python):

```python
def add(a, b):
    return a + b

def test_add_positive():
    assert add(2, 3) == 5

def test_add_negative():
    assert add(-1, -1) == -2

def test_add_zero():
    assert add(0, 5) == 5
```

### Przykład testów w Google Test (C++):

```cpp
#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(add(-1, -1), -2);
}
```

---

## Zasady dobrych testów jednostkowych (zapamiętaj akronim FIRST):

1. **F**ast – muszą być szybkie (wykonywane w milisekundach).
2. **I**ndependent – niezależne jeden od drugiego, można je uruchamiać w dowolnej kolejności.
3. **R**epeatable – powtarzalne (ten sam wynik za każdym razem).
4. **S**elf-validating – samodzielnie potwierdzające poprawność (zakończone "pass" lub "fail").
5. **T**imely – pisane w odpowiednim czasie (najlepiej przed kodem – patrz TDD).

---

## Struktura testu: AAA

Dobrze napisany test jednostkowy składa się z trzech sekcji:

1. **Arrange (przygotowanie)** – przygotowanie danych i stanu.
2. **Act (wykonanie)** – wywołanie testowanej funkcji.
3. **Assert (weryfikacja)** – sprawdzenie wyniku.

```python
def test_calculate_discount():
    # Arrange
    price = 100
    discount = 0.2

    # Act
    result = price * (1 - discount)

    # Assert
    assert result == 80
```

---

## Atrapy (mocks), stubs i fakes

Przy testowaniu pojedynczej jednostki często musimy odizolować ją od zależności (np. bazy danych, służb sieciowych). Służą do tego:

- **Stub** – obiekt zwracający zaprogramowaną odpowiedź na wywołania.
- **Mock** – obiekt, który dodatkowo weryfikuje, czy wywołano odpowiednie metody z odpowiednimi argumentami.
- **Fake** – uproszczona, działająca implementacja (np. baza danych w pamięci).

**Przykład:** Testujemy funkcję `sendEmail()`, która wysyła wiadomość. Nie chcemy, aby test faktycznie wysyłał e-mail – używamy mocka usługi wysyłania poczty, który sprawdza, czy funkcja wywołała wysyłkę z poprawnymi argumentami.

---

## Pokrycie testami jednostkowymi

**Pokrycie kodu** (code coverage) to odsetek linii kodu, które zostały wykonane podczas testów. Narzędzia takie jak gcov, Istanbul czy Coverage.py pokazują, które linie kodu są pokryte testami.

> **Uwaga:** Wysokie pokrycie nie gwarantuje braku błędów, ale niskie pokrycie oznacza, że duża część kodu nie została przetestowana.

---

## Czego NIE robić w testach jednostkowych:

- Nie testować kodu, który dopiero się pisze, bez wcześniejszego uruchomienia.
- Nie pisać testów zależnych od kolejności wykonania.
- Nie używać w testach rzeczywistej bazy danych lub sieci (używaj mocków).
- Nie sprawdzać całego systemu – to rola testów integracyjnych.
- Nie pomijać przypadków brzegowych (wartości graniczne, dane puste, błędy).

---

## Podsumowanie

- Testy jednostkowe sprawdzają pojedyncze funkcje i metody.
- Piszesz je szybko, automatyzujesz i uruchamiasz często.
- Dobry test jest szybki, niezależny, powtarzalny i samodzielny.
- Struktura Arrange-Act-Assert porządkuje każdy test.
- Mocki i stuby izolują testowaną jednostkę od zależności.
