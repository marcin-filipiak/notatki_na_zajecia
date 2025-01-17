### Listy w Pythonie

Listy to jedne z najczęściej używanych struktur danych w Pythonie. Są to dynamiczne sekwencje, które mogą przechowywać elementy różnych typów, takie jak liczby, napisy, a nawet inne listy.

---

#### **Tworzenie list**

1. **Pusta lista:**
   ```python
   lista = []
   ```

2. **Lista z elementami:**
   ```python
   liczby = [1, 2, 3, 4, 5]
   napisy = ["kot", "pies", "ryba"]
   mieszana = [42, "Python", True]
   ```

3. **Lista z elementami jednego typu:**
   ```python
   jedynki = [1] * 5  # [1, 1, 1, 1, 1]
   ```

4. **Lista utworzona za pomocą `list()`:**
   ```python
   lista_znakow = list("Python")  # ['P', 'y', 't', 'h', 'o', 'n']
   ```

---

#### **Operacje na listach**

1. **Dostęp do elementów:**
   ```python
   lista = [10, 20, 30, 40, 50]
   print(lista[0])  # Pierwszy element: 10
   print(lista[-1]) # Ostatni element: 50
   ```

2. **Modyfikacja elementów:**
   ```python
   lista[1] = 25  # Zmienia drugi element
   ```

3. **Dodawanie elementów:**
   - Na koniec listy:
     ```python
     lista.append(60)
     ```
   - W określonym miejscu:
     ```python
     lista.insert(2, 35)  # Wstawia 35 na trzecie miejsce
     ```

4. **Usuwanie elementów:**
   - Usuwanie przez wartość:
     ```python
     lista.remove(25)  # Usuwa pierwsze wystąpienie 25
     ```
   - Usuwanie przez indeks:
     ```python
     del lista[0]  # Usuwa pierwszy element
     ```
   - Usuwanie i zwracanie elementu:
     ```python
     ostatni = lista.pop()  # Usuwa i zwraca ostatni element
     ```

5. **Łączenie list:**
   ```python
   nowa_lista = lista1 + lista2
   lista1.extend(lista2)
   ```

6. **Sprawdzanie obecności elementu:**
   ```python
   if 30 in lista:
       print("30 jest w liście")
   ```

---

#### **Funkcje i metody list**

1. **Długość listy:**
   ```python
   print(len(lista))
   ```

2. **Sortowanie:**
   ```python
   lista.sort()  # Sortuje rosnąco
   lista.sort(reverse=True)  # Sortuje malejąco
   ```

3. **Odwracanie kolejności:**
   ```python
   lista.reverse()
   ```

4. **Minimalna, maksymalna wartość i suma:**
   ```python
   print(min(lista))  # Najmniejszy element
   print(max(lista))  # Największy element
   print(sum(lista))  # Suma elementów (dla liczb)
   ```

5. **Zliczanie wystąpień elementu:**
   ```python
   print(lista.count(10))
   ```

6. **Znajdowanie indeksu elementu:**
   ```python
   print(lista.index(30))  # Pierwsze wystąpienie elementu
   ```

---

#### **Slicing (wycinanie fragmentów listy)**

1. **Podstawowy slicing:**
   ```python
   podlista = lista[1:4]  # Od drugiego do czwartego elementu
   ```

2. **Co drugi element:**
   ```python
   co_drugi = lista[::2]
   ```

3. **Odwrócona lista:**
   ```python
   odwrocona = lista[::-1]
   ```

---

#### **Listy wielowymiarowe**

1. **Tworzenie listy dwuwymiarowej:**
   ```python
   macierz = [
       [1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]
   ]
   print(macierz[1][2])  # Drugi wiersz, trzeci element: 6
   ```

---

#### **Iterowanie przez listę**

1. **Za pomocą pętli `for`:**
   ```python
   for element in lista:
       print(element)
   ```

2. **Za pomocą indeksów:**
   ```python
   for i in range(len(lista)):
       print(f"Element {i}: {lista[i]}")
   ```

---

#### **Przykłady praktyczne**

1. **Znajdowanie największej liczby w liście:**
   ```python
   liczby = [3, 1, 4, 1, 5, 9]
   maks = max(liczby)
   print(f"Największa liczba to: {maks}")
   ```

2. **Filtrowanie elementów:**
   ```python
   liczby = [1, 2, 3, 4, 5]
   parzyste = [x for x in liczby if x % 2 == 0]
   print(parzyste)  # [2, 4]
   ```

3. **Tworzenie nowej listy z modyfikacją:**
   ```python
   liczby = [1, 2, 3]
   podwojone = [x * 2 for x in liczby]
   print(podwojone)  # [2, 4, 6]
   ```

---

### Podsumowanie

Listy są potężnym i elastycznym narzędziem w Pythonie, pozwalającym na przechowywanie i manipulację danych. Warto znać ich podstawowe operacje, aby efektywnie wykorzystywać je w codziennym programowaniu.
