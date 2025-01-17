### Pętla `while` w Pythonie

Pętla `while` wykonuje się dopóki określony warunek logiczny jest spełniony. Jest używana, gdy nie znamy z góry liczby iteracji, ale wiemy, że mają trwać, dopóki pewien warunek pozostaje prawdziwy.

---

#### **Składnia**
```python
while warunek:
    # Kod do wykonania w każdej iteracji
```

- **`warunek`**: Wyrażenie logiczne, które jest sprawdzane przed każdą iteracją.
- Jeśli **warunek jest `True`**, blok kodu w pętli zostanie wykonany.
- Jeśli **warunek jest `False`**, pętla kończy działanie.

---

#### **Przykłady użycia**

1. **Prosta pętla:**
   ```python
   licznik = 0
   while licznik < 5:
       print(licznik)
       licznik += 1
   ```

2. **Oczekiwanie na określony warunek:**
   ```python
   odpowiedz = ""
   while odpowiedz != "tak":
       odpowiedz = input("Czy chcesz zakończyć? (tak/nie): ")
   print("Koniec pętli")
   ```

3. **Niekończąca się pętla (kontrolowana `break`):**
   ```python
   while True:
       liczba = int(input("Podaj liczbę (0 kończy program): "))
       if liczba == 0:
           break
       print(f"Podana liczba to: {liczba}")
   ```

---

#### **`break` i `continue` w pętli `while`**

1. **`break`:** Przerywa działanie pętli, niezależnie od warunku.
   ```python
   licznik = 0
   while licznik < 10:
       if licznik == 5:
           break
       print(licznik)
       licznik += 1
   ```

2. **`continue`:** Pomija bieżącą iterację i przechodzi do kolejnej.
   ```python
   licznik = 0
   while licznik < 10:
       licznik += 1
       if licznik % 2 == 0:
           continue
       print(licznik)  # Drukuje tylko liczby nieparzyste
   ```

---

#### **Pętla `while` z `else`**
Podobnie jak w pętli `for`, blok `else` w pętli `while` wykonuje się, jeśli pętla zakończy się normalnie, bez użycia `break`.

**Przykład:**
```python
licznik = 0
while licznik < 3:
    print(licznik)
    licznik += 1
else:
    print("Pętla zakończona normalnie")
```

**Przykład z `break`:**
```python
licznik = 0
while licznik < 3:
    if licznik == 2:
        break
    print(licznik)
    licznik += 1
else:
    print("Pętla zakończona normalnie")  # Ten blok nie zostanie wykonany
```

---

#### **Praktyczne przykłady**

1. **Sumowanie liczb wprowadzone przez użytkownika:**
   ```python
   suma = 0
   while True:
       liczba = int(input("Podaj liczbę (0 kończy): "))
       if liczba == 0:
           break
       suma += liczba
   print(f"Suma podanych liczb: {suma}")
   ```

2. **Zgadnij liczbę:**
   ```python
   import random
   liczba_do_odgadniecia = random.randint(1, 100)
   odgadniecie = 0

   while odgadniecie != liczba_do_odgadniecia:
       odgadniecie = int(input("Zgadnij liczbę (1-100): "))
       if odgadniecie < liczba_do_odgadniecia:
           print("Za mało!")
       elif odgadniecie > liczba_do_odgadniecia:
           print("Za dużo!")
   print("Gratulacje! Odgadłeś liczbę.")
   ```

3. **Walidacja danych wejściowych:**
   ```python
   wiek = -1
   while wiek < 0 or wiek > 120:
       wiek = int(input("Podaj swój wiek (0-120): "))
   print(f"Twój wiek to: {wiek}")
   ```

---

### Podsumowanie
Pętla `while` jest idealna w sytuacjach, gdy:
- Liczba iteracji nie jest z góry znana.
- Warunek kontroli jest dynamiczny i zależy od danych lub działań użytkownika.

Łącząc ją z instrukcjami `break`, `continue`, i `else`, można tworzyć elastyczne i złożone algorytmy.
