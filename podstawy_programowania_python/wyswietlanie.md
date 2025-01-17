### Wyświetlanie danych na ekranie w Pythonie

W Pythonie do wyświetlania danych na ekranie używamy funkcji `print()`. Możemy wyświetlać zarówno tekst, jak i zmienne w różnorodny sposób, dostosowując wyświetlane informacje do naszych potrzeb.

---

#### **1. Wyświetlanie tekstu**

Aby wyświetlić prosty tekst, należy umieścić go w cudzysłowach i przekazać do funkcji `print()`. Możemy używać zarówno pojedynczych (`'`) jak i podwójnych (`"`) cudzysłowów:

```python
print("Hello, world!")  # Wyświetli: Hello, world!
print('Witaj w Pythonie!')  # Wyświetli: Witaj w Pythonie!
```

---

#### **2. Wyświetlanie wartości zmiennych**

Jeśli chcemy wyświetlić wartość zmiennej, przekazujemy ją jako argument do funkcji `print()`. Przykład:

```python
x = 10
print(x)  # Wyświetli: 10
```

---

#### **3. Wyświetlanie tekstu i wartości zmiennych w jednym wierszu**

Jeśli chcemy wyświetlić tekst razem z wartością zmiennej, możemy skorzystać z kilku metod:

##### **a) Łączenie tekstu z wartością zmiennej za pomocą operatora `+`**

Operator `+` pozwala na połączenie tekstu i zmiennych, jednak należy pamiętać, że wszystkie elementy muszą być typu `str` (tekst):

```python
imie = "Jan"
wiek = 25
print("Cześć, mam " + imie + " i mam " + str(wiek) + " lat.")  # Wyświetli: Cześć, mam Jan i mam 25 lat.
```

W przypadku zmiennych, które są liczbami, musimy je najpierw przekonwertować na tekst przy pomocy funkcji `str()`.

##### **b) Formatowanie ciągu znaków z użyciem f-stringów (od Python 3.6)**

F-stringi to wygodny sposób łączenia tekstu z wartościami zmiennych, w którym można bezpośrednio osadzić zmienne w ciągu znaków, umieszczając je w nawiasach klamrowych `{}`:

```python
imie = "Jan"
wiek = 25
print(f"Cześć, mam {imie} i mam {wiek} lat.")  # Wyświetli: Cześć, mam Jan i mam 25 lat.
```

F-stringi są jednym z najczęściej wykorzystywanych sposobów formatowania tekstu w Pythonie, ponieważ są czytelne i wydajne.

##### **c) Formatowanie ciągu znaków z użyciem metody `format()`**

Metoda `format()` pozwala na osadzenie zmiennych w ciągu znaków za pomocą specjalnych symboli `{}`. Zmienne są przekazywane jako argumenty metody `format()`:

```python
imie = "Jan"
wiek = 25
print("Cześć, mam {} i mam {} lat.".format(imie, wiek))  # Wyświetli: Cześć, mam Jan i mam 25 lat.
```

Można także określić kolejność zmiennych w nawiasach:

```python
print("Cześć, mam {1} i mam {0} lat.".format(wiek, imie))  # Wyświetli: Cześć, mam Jan i mam 25 lat.
```

---

#### **4. Wyświetlanie wielu zmiennych w jednym `print()`**

Funkcja `print()` może przyjmować wiele argumentów, oddzielonych przecinkami. W takim przypadku Python automatycznie doda między nimi spację:

```python
imie = "Jan"
wiek = 25
miasto = "Warszawa"
print(imie, wiek, miasto)  # Wyświetli: Jan 25 Warszawa
```

---

#### **5. Wyświetlanie tekstu z różnymi separatorami i końcami linii**

Funkcja `print()` umożliwia także dostosowanie separatora (domyślnie jest to spacja) oraz końca linii (domyślnie jest to nowa linia). Można to zrobić za pomocą argumentów `sep` i `end`:

- **`sep`**: Określa separator, który zostanie użyty między argumentami w funkcji `print()`.
- **`end`**: Określa, czym zakończy się wydrukowany tekst (domyślnie jest to nowa linia `\n`).

Przykłady:

```python
# Zmieniamy separator na przecinek
print("A", "B", "C", sep=", ")  # Wyświetli: A, B, C

# Zmieniamy końcowy znak na spację
print("Cześć", end=" ")
print("Świecie")  # Wyświetli: Cześć Świecie
```

---

#### **6. Wyświetlanie danych w postaci tabeli (zachowanie wyrównania)**

Funkcja `print()` może być także wykorzystywana do formatowania danych w postaci tabeli, wyrównując je na podstawie szerokości kolumn. Możemy używać tego za pomocą metod formatowania, takich jak f-stringi.

```python
# Wyrównanie tekstu do lewej, prawej lub środka
imie = "Jan"
wiek = 25
miasto = "Warszawa"
print(f"{imie:<10} {wiek:>3} {miasto:^15}")
# Wyświetli: Jan        25     Warszawa
```

- **`<10`**: Wyrównanie do lewej, szerokość 10.
- **`>3`**: Wyrównanie do prawej, szerokość 3.
- **`^15`**: Wyrównanie do środka, szerokość 15.

---

#### **7. Podsumowanie**

- Używając `print()`, możemy wyświetlać tekst, wartości zmiennych oraz łączyć je w różnych formatach.
- F-stringi są najwygodniejszym i najczęściej używanym sposobem formatowania tekstu w Pythonie.
- Dzięki parametrom `sep` i `end` możemy dostosować sposób wyświetlania danych, w tym separator oraz końcowy znak.
- W Pythonie mamy także możliwość formatowania danych, co jest przydatne przy tworzeniu tabel lub innych zorganizowanych danych.
