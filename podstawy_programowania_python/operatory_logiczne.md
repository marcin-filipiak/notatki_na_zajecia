### Operatory logiczne i porównania w Pythonie

Operatory logiczne i porównania są podstawowymi narzędziami w Pythonie do tworzenia warunków w instrukcjach sterujących, takich jak `if`, `while` itp.

---

#### **Operatory porównania**
Operatory porównania pozwalają porównać dwie wartości i zwracają wartość logiczną (`True` lub `False`).

| Operator | Opis                | Przykład (`a = 5`, `b = 3`) |
|----------|---------------------|-----------------------------|
| `==`     | Równość             | `a == b` → `False`         |
| `!=`     | Różność             | `a != b` → `True`          |
| `<`      | Mniejsze niż        | `a < b` → `False`          |
| `>`      | Większe niż         | `a > b` → `True`           |
| `<=`     | Mniejsze lub równe  | `a <= b` → `False`         |
| `>=`     | Większe lub równe   | `a >= b` → `True`          |

---

#### **Operatory logiczne**
Operatory logiczne służą do łączenia wielu warunków.

| Operator | Opis                        | Przykład (`x = 5`, `y = 10`)       |
|----------|-----------------------------|------------------------------------|
| `and`    | Logiczne "i"                | `(x > 0 and y < 15)` → `True`     |
| `or`     | Logiczne "lub"              | `(x < 0 or y > 5)` → `True`       |
| `not`    | Negacja                     | `not (x > 0)` → `False`           |

---

#### **Zastosowanie operatorów logicznych i porównania**

1. **Użycie w warunkach `if`:**
   ```python
   x = 8
   if x > 5 and x < 10:
       print("x jest między 5 a 10")
   ```

2. **Negacja warunku:**
   ```python
   x = 3
   if not (x > 5):
       print("x nie jest większe od 5")
   ```

3. **Łączenie wielu warunków z `or`:**
   ```python
   x = 0
   if x < 0 or x == 0:
       print("x jest mniejsze lub równe zero")
   ```

---

#### **Prawda (Truthy) i Fałsz (Falsy)**
Python interpretuje różne typy danych jako prawdziwe lub fałszywe w kontekście logicznym.

- **Falsy**: Wartości, które są uznawane za fałszywe:
  - `None`
  - `False`
  - Liczby: `0`, `0.0`
  - Puste kolekcje: `[]`, `{}`, `set()`, `""`

- **Truthy**: Wszystkie inne wartości.

**Przykład:**
```python
x = []
if x:
    print("Lista nie jest pusta")
else:
    print("Lista jest pusta")  # Ten kod zostanie wykonany
```

---

#### **Przykłady praktyczne**

1. **Sprawdzenie, czy liczba jest w zakresie:**
   ```python
   x = 15
   if 10 <= x <= 20:  # Python pozwala na takie zapisy!
       print("x jest w zakresie od 10 do 20")
   ```

2. **Warunek z wieloma operatorami logicznymi:**
   ```python
   x = 7
   y = 10
   if x > 5 and (y < 15 or y % 2 == 0):
       print("Warunek został spełniony")
   ```

3. **Negacja i warunki złożone:**
   ```python
   x = 0
   if not (x > 0 and x < 10):
       print("x nie jest w przedziale od 1 do 9")
   ```

---

### Podsumowanie
Operatory logiczne i porównania są niezbędne do sterowania przepływem programu. Można ich używać w różnych kombinacjach, aby tworzyć złożone warunki. Pamiętaj, że czytelność kodu jest kluczowa, więc używaj nawiasów w warunkach, gdy jest to konieczne dla jasności.
