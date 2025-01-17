### Pobieranie danych z klawiatury w Pythonie

W Pythonie do pobierania danych od użytkownika z klawiatury używamy funkcji `input()`. Funkcja ta zwraca dane w postaci ciągu znaków (string), dlatego w przypadku chęci użycia innych typów danych, będziemy musieli odpowiednio przekonwertować te dane.

---

#### **1. Pobieranie danych jako tekst (string)**

Najprostszym sposobem wczytania danych z klawiatury jest użycie funkcji `input()`. Zwróci ona dane w postaci łańcucha znaków (string), niezależnie od tego, co użytkownik wpisze. 

```python
imie = input("Podaj swoje imię: ")
print("Witaj, " + imie + "!")
```

Przykład wprowadzenia:
```
Podaj swoje imię: Jan
```
Wynik:
```
Witaj, Jan!
```

---

#### **2. Pobieranie danych liczbowych**

Ponieważ `input()` zwraca dane w formie tekstu, aby uzyskać dane numeryczne, musimy je przekonwertować na odpowiedni typ danych.

##### **a) Liczby całkowite (int)**

Aby pobrać liczbę całkowitą, używamy funkcji `int()` do przekształcenia tekstu na liczbę całkowitą:

```python
wiek = int(input("Podaj swój wiek: "))
print("Twój wiek to:", wiek)
```

Przykład wprowadzenia:
```
Podaj swój wiek: 25
```
Wynik:
```
Twój wiek to: 25
```

##### **b) Liczby zmiennoprzecinkowe (float)**

Podobnie, jeśli potrzebujemy liczby zmiennoprzecinkowej (np. z częścią dziesiętną), możemy użyć funkcji `float()`:

```python
wysokosc = float(input("Podaj swoją wysokość w metrach: "))
print("Twoja wysokość to:", wysokosc, "m")
```

Przykład wprowadzenia:
```
Podaj swoją wysokość w metrach: 1.75
```
Wynik:
```
Twoja wysokość to: 1.75 m
```

---

#### **3. Obsługa błędów przy nieprawidłowym wpisie**

Jeśli użytkownik wpisze coś, co nie może być przekonwertowane na liczbę (np. litery zamiast liczb), program zgłosi błąd (ValueError). Możemy obsłużyć te błędy za pomocą instrukcji `try...except`, aby zapobiec awarii programu.

```python
try:
    wiek = int(input("Podaj swój wiek: "))
    print("Twój wiek to:", wiek)
except ValueError:
    print("Wpisz poprawną liczbę!")
```

Jeśli użytkownik wpisze np. tekst zamiast liczby:
```
Podaj swój wiek: dwadzieścia
```
Wynik:
```
Wpisz poprawną liczbę!
```

---

#### **4. Pobieranie wielu danych jednocześnie**

Możemy również pobierać wiele danych w jednym wierszu, oddzielając je spacjami. W takim przypadku musimy je rozdzielić za pomocą metody `.split()` i przekonwertować na odpowiednie typy danych.

```python
imie, wiek = input("Podaj swoje imię i wiek, oddzielone spacją: ").split()
wiek = int(wiek)  # Konwertowanie wieku na liczbę całkowitą
print(f"Imię: {imie}, Wiek: {wiek}")
```

Przykład wprowadzenia:
```
Podaj swoje imię i wiek, oddzielone spacją: Jan 25
```
Wynik:
```
Imię: Jan, Wiek: 25
```

---

#### **5. Wczytywanie wielu zmiennych o różnych typach**

Jeśli chcemy pobrać różne dane o różnych typach, musimy przetworzyć wprowadzone dane na odpowiednie typy, jak w poniższym przykładzie:

```python
imie = input("Podaj swoje imię: ")
wiek = int(input("Podaj swój wiek: "))
waga = float(input("Podaj swoją wagę w kg: "))

print(f"Imię: {imie}, Wiek: {wiek}, Waga: {waga} kg")
```

Przykład wprowadzenia:
```
Podaj swoje imię: Anna
Podaj swój wiek: 30
Podaj swoją wagę w kg: 60.5
```
Wynik:
```
Imię: Anna, Wiek: 30, Waga: 60.5 kg
```

---

#### **6. Podsumowanie**

- Funkcja `input()` pozwala na pobieranie danych w formie tekstu (string).
- Aby uzyskać dane liczbowego typu (np. całkowite, zmiennoprzecinkowe), należy użyć funkcji konwertujących: `int()` lub `float()`.
- W przypadku błędów (np. niepoprawne dane), warto używać bloków `try...except`, aby obsługiwać wyjątki i zapobiec awarii programu.
- Możemy pobierać wiele danych jednocześnie, używając `.split()` i konwertując każdą zmienną do odpowiedniego typu.
