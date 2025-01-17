### Krotki w Pythonie

Krotki (ang. *tuples*) to struktury danych podobne do list, ale są **niemodyfikowalne** (immutable). Oznacza to, że raz utworzonej krotki nie można zmieniać – nie można dodawać, usuwać ani modyfikować jej elementów. Krotki są używane, gdy chcemy przechowywać zestaw danych, które nie powinny się zmieniać.

---

#### **Tworzenie krotek**

1. **Pusta krotka:**
   ```python
   pusta = ()
   ```

2. **Krotka z elementami:**
   ```python
   krotka = (1, 2, 3)
   napisy = ("kot", "pies", "ryba")
   mieszana = (42, "Python", True)
   ```

3. **Krotka z jednym elementem:**
   Aby utworzyć krotkę z jednym elementem, konieczny jest przecinek po tym elemencie:
   ```python
   pojedyncza = (42,)
   print(type(pojedyncza))  # <class 'tuple'>
   ```

4. **Tworzenie bez nawiasów:**
   Python pozwala pominąć nawiasy podczas definiowania krotek:
   ```python
   krotka = 1, 2, 3
   ```

---

#### **Operacje na krotkach**

1. **Dostęp do elementów:**
   ```python
   krotka = (10, 20, 30, 40)
   print(krotka[0])  # Pierwszy element: 10
   print(krotka[-1]) # Ostatni element: 40
   ```

2. **Wycinanie (slicing):**
   ```python
   podkrotka = krotka[1:3]  # (20, 30)
   ```

3. **Sprawdzanie obecności elementu:**
   ```python
   if 30 in krotka:
       print("30 jest w krotce")
   ```

4. **Iterowanie po krotce:**
   ```python
   for element in krotka:
       print(element)
   ```

5. **Łączenie krotek:**
   ```python
   krotka1 = (1, 2, 3)
   krotka2 = (4, 5, 6)
   nowa_krotka = krotka1 + krotka2  # (1, 2, 3, 4, 5, 6)
   ```

6. **Powielanie krotki:**
   ```python
   powielona = krotka * 3  # (10, 20, 30, 40, 10, 20, 30, 40, 10, 20, 30, 40)
   ```

---

#### **Funkcje i operacje na krotkach**

1. **Długość krotki:**
   ```python
   print(len(krotka))  # Liczba elementów w krotce
   ```

2. **Minimalna, maksymalna wartość i suma:**
   (dotyczy krotek z liczbami)
   ```python
   liczby = (10, 20, 30)
   print(min(liczby))  # Najmniejszy element: 10
   print(max(liczby))  # Największy element: 30
   print(sum(liczby))  # Suma elementów: 60
   ```

3. **Indeks elementu:**
   ```python
   print(krotka.index(20))  # Indeks pierwszego wystąpienia 20
   ```

4. **Zliczanie wystąpień elementu:**
   ```python
   print(krotka.count(10))  # Liczba wystąpień 10
   ```

---

#### **Zastosowania krotek**

1. **Przypisywanie wielu wartości naraz:**
   ```python
   a, b, c = (1, 2, 3)
   print(a, b, c)  # 1 2 3
   ```

2. **Funkcje zwracające wiele wartości:**
   Funkcja może zwracać krotkę, aby przekazać wiele wyników:
   ```python
   def podziel(a, b):
       return a // b, a % b  # Zwracamy iloraz i resztę

   wynik = podziel(10, 3)
   print(wynik)  # (3, 1)
   ```

3. **Krotki jako klucze w słownikach:**
   Krotki mogą być używane jako klucze w słownikach, ponieważ są niemodyfikowalne:
   ```python
   slownik = {(1, 2): "punkt A", (3, 4): "punkt B"}
   print(slownik[(1, 2)])  # "punkt A"
   ```

---

#### **Zalety krotek**

- **Niezmienność:** Chronią dane przed przypadkowymi zmianami.
- **Wydajność:** Operacje na krotkach są szybsze niż na listach.
- **Użyteczność:** Mogą służyć do przechowywania stałych zbiorów danych lub wartości zwracanych przez funkcje.

---

#### **Przykłady**

1. **Porównanie listy i krotki:**
   ```python
   lista = [1, 2, 3]
   krotka = (1, 2, 3)

   lista[0] = 10  # Działa
   # krotka[0] = 10  # Błąd: TypeError, bo krotki są niemodyfikowalne
   ```

2. **Iterowanie przez indeksy:**
   ```python
   krotka = (100, 200, 300)
   for i in range(len(krotka)):
       print(f"Element {i}: {krotka[i]}")
   ```

3. **Rozpakowywanie krotki:**
   ```python
   dane = (2025, "styczeń", 16)
   rok, miesiac, dzien = dane
   print(f"Dzisiaj jest {dzien} {miesiac} {rok}")
   ```

---

### Podsumowanie

Krotki są przydatne, gdy potrzebujemy przechowywać dane w sposób niezmienny. Ich zastosowanie obejmuje zwracanie wielu wartości z funkcji, tworzenie stałych struktur danych czy użycie jako kluczy w słownikach. Dzięki ich prostocie i szybkości są często wykorzystywane w Pythonie.
