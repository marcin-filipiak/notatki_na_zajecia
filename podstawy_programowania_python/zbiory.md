### Zbiory w Pythonie

Zbiory (ang. *sets*) to struktury danych, które przechowują **unikalne** elementy w sposób nieuporządkowany. Dzięki temu są idealne do eliminowania duplikatów oraz wykonywania operacji matematycznych na zbiorach, takich jak suma, różnica, czy część wspólna.

---

#### **Tworzenie zbiorów**

1. **Pusty zbiór:**
   - Aby stworzyć pusty zbiór, należy użyć funkcji `set()` (niedozwolone jest użycie `{}`, ponieważ to tworzy pusty słownik).
   ```python
   pusty_zbior = set()
   ```

2. **Zbiór z elementami:**
   - Elementy muszą być **niemodyfikowalne** (np. liczby, napisy, krotki), a duplikaty są automatycznie usuwane.
   ```python
   zbior = {1, 2, 3, 4, 5}
   zbior2 = set([1, 2, 2, 3])  # Duplikaty zostaną usunięte
   print(zbior2)  # {1, 2, 3}
   ```

---

#### **Operacje na zbiorach**

1. **Dodawanie elementów:**
   ```python
   zbior = {1, 2, 3}
   zbior.add(4)
   print(zbior)  # {1, 2, 3, 4}
   ```

2. **Usuwanie elementów:**
   - **`remove(element)`**: Usuwa element, a jeśli go nie znajdzie, zgłasza błąd.
   ```python
   zbior.remove(2)
   ```
   - **`discard(element)`**: Usuwa element, ale **nie zgłasza błędu**, jeśli element nie istnieje.
   ```python
   zbior.discard(10)  # Brak błędu
   ```

3. **Czyszczenie zbioru:**
   ```python
   zbior.clear()
   print(zbior)  # set()
   ```

4. **Sprawdzanie przynależności:**
   ```python
   print(3 in zbior)  # True, jeśli 3 należy do zbioru
   print(5 not in zbior)  # True, jeśli 5 nie należy do zbioru
   ```

---

#### **Operacje matematyczne**

1. **Suma zbiorów:**
   - Zwraca wszystkie elementy z obu zbiorów (bez duplikatów).
   ```python
   A = {1, 2, 3}
   B = {3, 4, 5}
   print(A | B)  # {1, 2, 3, 4, 5}
   print(A.union(B))  # {1, 2, 3, 4, 5}
   ```

2. **Przecięcie zbiorów:**
   - Zwraca elementy wspólne obu zbiorów.
   ```python
   print(A & B)  # {3}
   print(A.intersection(B))  # {3}
   ```

3. **Różnica zbiorów:**
   - Elementy, które są w `A`, ale nie w `B`.
   ```python
   print(A - B)  # {1, 2}
   print(A.difference(B))  # {1, 2}
   ```

4. **Różnica symetryczna:**
   - Elementy, które są w jednym z zbiorów, ale nie w obu jednocześnie.
   ```python
   print(A ^ B)  # {1, 2, 4, 5}
   print(A.symmetric_difference(B))  # {1, 2, 4, 5}
   ```

5. **Podzbiory i nadzbiory:**
   - **Podzbiór:** Sprawdza, czy wszystkie elementy `A` są w `B`.
     ```python
     print(A <= B)  # False
     print(A.issubset(B))  # False
     ```
   - **Nadzbiór:** Sprawdza, czy wszystkie elementy `B` są w `A`.
     ```python
     print(A >= B)  # False
     print(A.issuperset(B))  # False
     ```

---

#### **Funkcje wbudowane dla zbiorów**

1. **Liczba elementów w zbiorze:**
   ```python
   zbior = {1, 2, 3}
   print(len(zbior))  # 3
   ```

2. **Kopiowanie zbioru:**
   ```python
   kopia = zbior.copy()
   ```

3. **Zamiana listy na zbiór:**
   ```python
   lista = [1, 2, 2, 3, 3, 3]
   zbior = set(lista)
   print(zbior)  # {1, 2, 3}
   ```

4. **Iteracja po zbiorze:**
   ```python
   for element in zbior:
       print(element)
   ```

---

#### **Przykłady użycia**

1. **Usuwanie duplikatów z listy:**
   ```python
   lista = [1, 2, 2, 3, 3, 3]
   unikalne = set(lista)
   print(list(unikalne))  # [1, 2, 3]
   ```

2. **Porównanie dwóch list:**
   ```python
   lista1 = [1, 2, 3]
   lista2 = [2, 3, 4]

   wspolne = set(lista1) & set(lista2)  # {2, 3}
   ```

3. **Filtrowanie unikalnych słów w tekście:**
   ```python
   tekst = "to jest tekst to jest przykład"
   slowa = tekst.split()
   unikalne_slowa = set(slowa)
   print(unikalne_slowa)  # {'tekst', 'jest', 'przykład', 'to'}
   ```

---

#### **Podsumowanie**

Zbiory w Pythonie są idealne do pracy z unikalnymi wartościami oraz wykonywania operacji zbiorowych. Ich zastosowania obejmują filtrowanie duplikatów, analizę danych i szybkie operacje matematyczne. Dzięki wbudowanym funkcjom i elastyczności, zbiory są niezwykle przydatne w codziennej pracy programistycznej.
