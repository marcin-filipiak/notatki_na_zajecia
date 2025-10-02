
# Moduł `random` w Pythonie

## Co to jest?

* `random` to wbudowany moduł w Pythonie do **generowania liczb losowych** i losowego wybierania elementów.
* Aby go użyć, należy zaimportować moduł:

```python
import random
```

---

## Podstawowe funkcje

1. **`random.randint(a, b)`**

* Zwraca losową liczbę całkowitą z przedziału `[a, b]` (oba końce włącznie).

```python
losowa_liczba = random.randint(1, 10)
print(losowa_liczba)  # np. 7
```

2. **`random.random()`**

* Zwraca liczbę zmiennoprzecinkową (float) z przedziału `[0.0, 1.0)`.

```python
x = random.random()
print(x)  # np. 0.3745
```

3. **`random.choice(lista)`**

* Zwraca losowy element z listy, krotki lub innej sekwencji.

```python
kolory = ["czerwony", "zielony", "niebieski"]
print(random.choice(kolory))  # np. "zielony"
```

4. **`random.shuffle(lista)`**

* Tasuje elementy w liście w miejscu (zmienia oryginalną listę).

```python
karty = ["A", "K", "Q", "J"]
random.shuffle(karty)
print(karty)  # np. ['Q', 'A', 'J', 'K']
```

5. **`random.sample(lista, k)`**

* Zwraca `k` unikalnych losowych elementów z listy, bez powtórzeń.

```python
liczby = [1, 2, 3, 4, 5]
print(random.sample(liczby, 3))  # np. [4, 1, 5]
```

---

## Przykłady zastosowań

1. **Losowanie liczby do gry “Zgadnij liczbę”**

```python
tajna_liczba = random.randint(1, 50)
```

2. **Losowy wybór zwycięzcy w klasie**

```python
uczniowie = ["Ania", "Bartek", "Celina"]
wygrany = random.choice(uczniowie)
print("Wygrany:", wygrany)
```

3. **Tasowanie talii kart**

```python
talia = ["♠", "♥", "♦", "♣"]
random.shuffle(talia)
print(talia)
```

---

## Uwagi

* Funkcje `random` generują liczby **pseudolosowe** – do zastosowań w grach i prostych symulacjach w zupełności wystarczają.
* Jeśli chcesz powtarzalne wyniki np. do testów, możesz ustawić **ziarno (seed)**:

```python
random.seed(42)  # ta sama sekwencja losowa przy każdym uruchomieniu
```
