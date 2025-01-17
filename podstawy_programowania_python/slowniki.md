### Słowniki w Pythonie

Słowniki (ang. *dictionaries*) to struktury danych w Pythonie, które przechowują **pary klucz-wartość**. Dzięki nim można łatwo przypisywać i wyszukiwać dane na podstawie unikalnych kluczy.

---

#### **Tworzenie słowników**

1. **Pusty słownik:**
   ```python
   pusty_slownik = {}
   pusty_slownik_alt = dict()
   ```

2. **Słownik z danymi:**
   ```python
   slownik = {
       "klucz1": "wartość1",
       "klucz2": "wartość2",
       "klucz3": 123
   }
   ```

3. **Tworzenie za pomocą `dict`:**
   ```python
   slownik = dict(klucz1="wartość1", klucz2="wartość2")
   ```

4. **Słownik jako lista krotek:**
   ```python
   slownik = dict([("klucz1", "wartość1"), ("klucz2", "wartość2")])
   ```

---

#### **Operacje na słownikach**

1. **Dostęp do wartości:**
   ```python
   slownik = {"imie": "Jan", "wiek": 30}
   print(slownik["imie"])  # Jan
   ```

2. **Dodawanie lub modyfikacja wartości:**
   ```python
   slownik["miasto"] = "Warszawa"  # Dodanie nowego klucza
   slownik["wiek"] = 31           # Modyfikacja istniejącego klucza
   ```

3. **Sprawdzanie obecności klucza:**
   ```python
   if "wiek" in slownik:
       print("Klucz 'wiek' istnieje")
   ```

4. **Usuwanie klucza:**
   ```python
   del slownik["wiek"]  # Usunięcie klucza
   ```

5. **Pobieranie wartości z domyślną wartością:**
   ```python
   wiek = slownik.get("wiek", "Nie podano")  # Zwraca 'Nie podano', jeśli klucz nie istnieje
   ```

6. **Iterowanie po słowniku:**
   - **Po kluczach:**
     ```python
     for klucz in slownik:
         print(klucz)
     ```
   - **Po wartościach:**
     ```python
     for wartosc in slownik.values():
         print(wartosc)
     ```
   - **Po parach klucz-wartość:**
     ```python
     for klucz, wartosc in slownik.items():
         print(f"{klucz}: {wartosc}")
     ```

---

#### **Funkcje wbudowane**

1. **Liczba elementów:**
   ```python
   print(len(slownik))  # Liczba kluczy w słowniku
   ```

2. **Kopiowanie słownika:**
   ```python
   nowy_slownik = slownik.copy()
   ```

3. **Czyszczenie zawartości słownika:**
   ```python
   slownik.clear()
   ```

4. **Usuwanie klucza z pobraniem jego wartości:**
   ```python
   wartosc = slownik.pop("klucz1", "Brak")  # Jeśli brak klucza, zwraca 'Brak'
   ```

5. **Połączenie dwóch słowników:**
   ```python
   drugi_slownik = {"klucz3": "wartość3"}
   slownik.update(drugi_slownik)  # Dodaje elementy z drugiego słownika
   ```

---

#### **Przykłady użycia**

1. **Słownik jako prosty rejestr:**
   ```python
   uczniowie = {
       "001": "Anna Kowalska",
       "002": "Jan Nowak",
       "003": "Piotr Zieliński"
   }

   print(uczniowie["002"])  # Jan Nowak
   ```

2. **Zliczanie wystąpień elementów:**
   ```python
   tekst = "abrakadabra"
   licznik = {}

   for litera in tekst:
       licznik[litera] = licznik.get(litera, 0) + 1

   print(licznik)  # {'a': 5, 'b': 2, 'r': 2, 'k': 1, 'd': 1}
   ```

3. **Tworzenie słownika z list:**
   ```python
   klucze = ["a", "b", "c"]
   wartosci = [1, 2, 3]

   slownik = dict(zip(klucze, wartosci))
   print(slownik)  # {'a': 1, 'b': 2, 'c': 3}
   ```

4. **Słownik zagnieżdżony:**
   ```python
   pracownicy = {
       "Dział IT": {"Jan": 30, "Anna": 25},
       "Dział HR": {"Piotr": 45, "Maria": 29}
   }

   print(pracownicy["Dział IT"]["Anna"])  # 25
   ```

---

#### **Zalety słowników**

- **Szybkie wyszukiwanie:** Operacje na kluczach w słownikach są bardzo wydajne.
- **Elastyczność:** Możemy przechowywać dowolne typy danych jako wartości.
- **Przejrzystość:** Intuicyjna struktura klucz-wartość.

---

### Podsumowanie

Słowniki w Pythonie to potężne narzędzie do przechowywania i manipulowania danymi w formacie klucz-wartość. Są szczególnie użyteczne w przypadkach, gdy potrzebujemy szybkiego dostępu do danych na podstawie unikalnych kluczy. Dzięki wbudowanym metodom i możliwości zagnieżdżania struktur ich zastosowanie jest niemal nieograniczone.
