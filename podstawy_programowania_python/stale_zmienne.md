### Stałe i zmienne w Pythonie  

W Pythonie **zmienne** służą do przechowywania wartości, które mogą się zmieniać w trakcie działania programu. **Stałe** są wartościami, które zgodnie z konwencją nie powinny się zmieniać, choć technicznie Python nie wymusza ich niezmienności.  

---

#### 1. **Deklarowanie zmiennych**  
Python jest językiem dynamicznie typowanym, co oznacza, że nie trzeba określać typu zmiennej podczas jej deklaracji – typ jest przypisywany automatycznie na podstawie przypisanej wartości.  

```python
x = 5           # Zmienna typu int (liczba całkowita)
y = 3.14        # Zmienna typu float (liczba zmiennoprzecinkowa)
name = "Alice"  # Zmienna typu str (ciąg znaków)
is_active = True  # Zmienna typu bool (wartość logiczna)
```

---

#### 2. **Określanie typów danych**  
Chociaż Python sam przypisuje typy, można je sprawdzić lub jawnie konwertować:  
- Sprawdzenie typu zmiennej:  
  ```python
  print(type(x))  # Wypisze: <class 'int'>
  ```
- Konwersja typu:  
  ```python
  x = 5           # int
  y = float(x)    # Konwersja na float
  z = str(x)      # Konwersja na str
  print(type(y))  # Wypisze: <class 'float'>
  print(z)        # Wypisze: "5"
  ```

---

#### 3. **Typy danych w Pythonie**
Python oferuje kilka podstawowych typów danych:  
- **Liczby**:  
  - `int` – liczby całkowite, np. `10`, `-5`.  
  - `float` – liczby zmiennoprzecinkowe, np. `3.14`, `-0.01`.  
  - `complex` – liczby zespolone, np. `2 + 3j`.  
- **Ciągi znaków (str)**: np. `"Hello"`, `'Python'`.  
- **Wartości logiczne (bool)**: `True`, `False`.  
- **Struktury danych**:  
  - `list` – lista, np. `[1, 2, 3]`.  
  - `tuple` – krotka (niezmienna lista), np. `(1, 2, 3)`.  
  - `dict` – słownik, np. `{"key": "value"}`.  
  - `set` – zbiór, np. `{1, 2, 3}`.  

---

#### 4. **Stałe**
Python nie posiada wbudowanego mechanizmu definiowania stałych, ale konwencja przyjmuje używanie wielkich liter z podkreśleniami.  
```python
PI = 3.14159    # Stała matematyczna
MAX_USERS = 100  # Maksymalna liczba użytkowników
```
Technicznie można zmienić wartość takiej "stałej", ale jest to uznawane za błąd konwencji.

---

#### 5. **Przykłady działania ze zmiennymi**
- Operacje arytmetyczne:  
  ```python
  a = 10
  b = 3
  print(a + b)  # Dodawanie: 13
  print(a / b)  # Dzielenie: 3.333...
  print(a // b) # Dzielenie całkowite: 3
  print(a % b)  # Reszta z dzielenia: 1
  ```
- Operacje na ciągach znaków:  
  ```python
  text1 = "Hello"
  text2 = "World"
  print(text1 + " " + text2)  # Konkatenacja: "Hello World"
  print(text1 * 3)           # Powtórzenie: "HelloHelloHello"
  ```

---

#### 6. **Zasięg zmiennych**
Python rozróżnia zmienne globalne i lokalne:  
- **Zmienne globalne**: dostępne w całym programie.  
- **Zmienne lokalne**: dostępne tylko w obrębie funkcji.  
```python
x = 10  # Zmienna globalna

def my_function():
    x = 5  # Zmienna lokalna
    print(x)  # Wypisze: 5

my_function()
print(x)  # Wypisze: 10
```

---

#### 7. **Typowanie statyczne (opcjonalne)**
Python pozwala na wskazanie typów zmiennych dla czytelności kodu (od Pythona 3.5):  
```python
def add_numbers(a: int, b: int) -> int:
    return a + b

result = add_numbers(2, 3)
print(result)  # Wypisze: 5
```

Stałe i zmienne w Pythonie są elastyczne i łatwe do użycia, co czyni ten język bardzo przyjaznym dla początkujących programistów.
