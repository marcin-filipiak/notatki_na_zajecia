**Obsługa błędów – try, except, finally, raise**

**1. Konstrukcja `try ... except`**
Służy do przechwytywania błędów (wyjątków), które mogłyby przerwać działanie programu.

```python
try:
    x = int(input("Podaj liczbę: "))
    print(10 / x)
except ZeroDivisionError:
    print("Nie można dzielić przez zero.")
except ValueError:
    print("To nie jest liczba.")
```

Jeśli w bloku `try` wystąpi wyjątek, Python przechodzi do odpowiedniego bloku `except`.
Jeśli żaden wyjątek się nie pojawi – `except` zostanie pominięty.

---

**2. Kilka typów wyjątków**

* `ValueError` – błędny typ danych (np. konwersja tekstu na liczbę)
* `ZeroDivisionError` – dzielenie przez zero
* `FileNotFoundError` – brak pliku
* `IndexError` – nieprawidłowy indeks listy
* `TypeError` – nieprawidłowy typ operandu

Można też użyć ogólnego `except:` gdy nie wiadomo, jaki wyjątek wystąpi:

```python
try:
    ...
except:
    print("Wystąpił nieoczekiwany błąd.")
```

---

**3. Blok `finally`**
Kod w `finally` wykona się **zawsze** – niezależnie od tego, czy wyjątek wystąpił, czy nie.
Stosowany np. do zamykania plików lub zwalniania zasobów.

```python
try:
    plik = open("dane.txt", "r")
    dane = plik.read()
except FileNotFoundError:
    print("Nie znaleziono pliku.")
finally:
    plik.close()
    print("Plik został zamknięty.")
```

---

**4. Rzucanie własnych wyjątków – `raise`**

`raise` służy do **celowego zgłoszenia błędu**.

```python
def dziel(a, b):
    if b == 0:
        raise ValueError("Nie można dzielić przez zero!")
    return a / b

try:
    wynik = dziel(10, 0)
except ValueError as e:
    print("Błąd:", e)
```

---

**5. Tworzenie własnych klas wyjątków**

```python
class MojWyjatek(Exception):
    pass

try:
    raise MojWyjatek("To jest własny wyjątek.")
except MojWyjatek as e:
    print("Złapano wyjątek:", e)
```
