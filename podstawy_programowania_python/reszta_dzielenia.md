# Reszta z dzielenia w Pythonie

## Operator `%`

* W Pythonie do obliczania reszty z dzielenia używamy operatora `%`.
* Składnia:

```python
reszta = a % b
```

* `a` – dzielna
* `b` – dzielnik
* `reszta` – wartość reszty po podzieleniu `a` przez `b`

**Przykłady:**

```python
10 % 3   # wynik: 1, bo 10 = 3*3 + 1
15 % 5   # wynik: 0, bo 15 = 5*3 + 0
7 % 4    # wynik: 3, bo 7 = 4*1 + 3
```

---

## Zastosowania reszty z dzielenia

1. **Sprawdzanie parzystości liczby**

```python
liczba = 8
if liczba % 2 == 0:
    print("Liczba parzysta")
else:
    print("Liczba nieparzysta")
```

2. **Wykrywanie wielokrotności liczby**

```python
for i in range(1, 11):
    if i % 3 == 0:
        print(i, "jest wielokrotnością 3")
```

3. **Zastosowania w algorytmach i grach**

* Obracanie elementów w kole (np. karta w talii, kolejka w grze)
* Wyświetlanie co n-ty element w pętli
* Cyfry liczby, np. sprawdzanie ostatniej cyfry:

```python
cyfra_jednosci = 123 % 10  # wynik: 3
```

---

## Kilka uwag

* Operator `%` działa też z liczbami ujemnymi:

```python
-7 % 3   # wynik: 2, bo Python zwraca resztę tak, aby była nieujemna
```

* W połączeniu z operatorami `//` (dzielenie całkowite) można zapisać dowolną liczbę w postaci:

```python
a = b * (a // b) + (a % b)
```


