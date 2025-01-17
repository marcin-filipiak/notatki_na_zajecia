### Pętla `for` w Pythonie

Pętla `for` w Pythonie służy do iteracji po elementach kolekcji, takich jak listy, krotki, łańcuchy znaków, słowniki, czy też zakresy liczb (`range`). Jest jedną z podstawowych konstrukcji do powtarzania operacji.

---

#### **Podstawowa składnia**
```python
for element in kolekcja:
    # Kod do wykonania w każdej iteracji
```

- **`element`**: Zmienna, która w każdej iteracji przyjmuje wartość kolejnego elementu kolekcji.
- **`kolekcja`**: Obiekt, po którym iterujemy, np. lista, łańcuch znaków, słownik itp.

---

#### **Przykłady użycia**

1. **Iteracja po liście:**
   ```python
   lista = [1, 2, 3, 4, 5]
   for liczba in lista:
       print(liczba)
   ```

2. **Iteracja po łańcuchu znaków:**
   ```python
   tekst = "Python"
   for znak in tekst:
       print(znak)
   ```

3. **Iteracja z `range`:**
   Funkcja `range` generuje liczby całkowite w określonym zakresie.
   ```python
   for i in range(5):  # Od 0 do 4
       print(i)

   for i in range(2, 7):  # Od 2 do 6
       print(i)

   for i in range(1, 10, 2):  # Od 1 do 9, skok co 2
       print(i)
   ```

4. **Iteracja po słowniku:**
   ```python
   slownik = {"a": 1, "b": 2, "c": 3}
   for klucz in slownik:
       print(f"Klucz: {klucz}, Wartość: {slownik[klucz]}")
   ```

---

#### **`break` i `continue`**
1. **`break`:** Zatrzymuje pętlę przed jej zakończeniem.
   ```python
   for i in range(10):
       if i == 5:
           break  # Przerwij pętlę, gdy i wynosi 5
       print(i)
   ```

2. **`continue`:** Pomija aktualną iterację i przechodzi do następnej.
   ```python
   for i in range(10):
       if i % 2 == 0:
           continue  # Pomija liczby parzyste
       print(i)
   ```

---

#### **Pętla `for` z `else`**
Blok `else` w pętli `for` wykonuje się, jeśli pętla zakończy się normalnie, tj. bez przerwania za pomocą `break`.

**Przykład:**
```python
for i in range(5):
    print(i)
else:
    print("Pętla zakończona normalnie")
```

**Przykład z `break`:**
```python
for i in range(5):
    if i == 3:
        break
    print(i)
else:
    print("Pętla zakończona normalnie")  # Ten blok nie zostanie wykonany
```

---

#### **Zagnieżdżone pętle**
Pętle można zagnieżdżać, tj. używać jednej pętli wewnątrz drugiej.

**Przykład:**
```python
for i in range(3):  # Zewnętrzna pętla
    for j in range(2):  # Wewnętrzna pętla
        print(f"i: {i}, j: {j}")
```

---

#### **Praktyczne przykłady**

1. **Sumowanie elementów listy:**
   ```python
   liczby = [1, 2, 3, 4, 5]
   suma = 0
   for liczba in liczby:
       suma += liczba
   print(f"Suma: {suma}")
   ```

2. **Generowanie tabliczki mnożenia:**
   ```python
   for i in range(1, 6):
       for j in range(1, 6):
           print(f"{i} * {j} = {i * j}")
   ```

3. **Filtrowanie elementów w liście:**
   ```python
   liczby = [1, 2, 3, 4, 5, 6, 7, 8, 9]
   parzyste = []
   for liczba in liczby:
       if liczba % 2 == 0:
           parzyste.append(liczba)
   print(f"Parzyste liczby: {parzyste}")
   ```

---

### Podsumowanie
Pętla `for` w Pythonie to wszechstronne narzędzie do iteracji. Dzięki wsparciu dla różnych typów kolekcji i funkcji takich jak `range`, jest niezwykle intuicyjna i łatwa w użyciu. Połączenie jej z instrukcjami `break`, `continue` i `else` pozwala na tworzenie złożonych i efektywnych rozwiązań.
