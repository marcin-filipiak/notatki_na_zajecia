### Notatka: Dziedziczenie w C++

#### Czym jest dziedziczenie?

Dziedziczenie to mechanizm programowania obiektowego, który pozwala na **przekazywanie właściwości i metod** z jednej klasy (tzw. klasy bazowej) do innej klasy (tzw. klasy pochodnej). Dzięki dziedziczeniu można tworzyć nowe klasy, które rozszerzają lub modyfikują funkcjonalność istniejących klas.

Przykład: Klasa **Pojazd** może być klasą bazową, a klasa **Samochod** klasą pochodną, która dziedziczy cechy pojazdu i dodaje swoje własne.

#### Słowo kluczowe `public` w dziedziczeniu

Podczas dziedziczenia używamy specyfikatora dostępu (np. `public`), który określa, jakie elementy klasy bazowej będą dostępne w klasie pochodnej:
- **`public`** – Publiczne elementy klasy bazowej pozostają publiczne w klasie pochodnej.
- **`protected`** – Publiczne i chronione elementy stają się chronione w klasie pochodnej.
- **`private`** – Wszystkie elementy klasy bazowej stają się prywatne w klasie pochodnej.

#### Przykład dziedziczenia w C++

```cpp
#include <iostream>
#include <string>
using namespace std;

// Klasa bazowa
class Pojazd {
protected: // Dostępne dla klas pochodnych, ale nie bezpośrednio spoza klasy
    string marka;
    int predkosc;

public:
    Pojazd(string m, int p) : marka(m), predkosc(p) {} // Konstruktor klasy bazowej

    void wyswietlInformacje() {
        cout << "Marka: " << marka << endl;
        cout << "Prędkość: " << predkosc << " km/h" << endl;
    }
};

// Klasa pochodna
class Samochod : public Pojazd {
private:
    int liczbaDrzwi;

public:
    Samochod(string m, int p, int drzwi) : Pojazd(m, p), liczbaDrzwi(drzwi) {} // Konstruktor wywołuje konstruktor klasy bazowej

    void wyswietlInformacjeSamochodu() {
        wyswietlInformacje(); // Wywołanie metody z klasy bazowej
        cout << "Liczba drzwi: " << liczbaDrzwi << endl;
    }
};

int main() {
    // Tworzenie obiektu klasy pochodnej
    Samochod mojSamochod("Toyota", 120, 4);

    // Wywoływanie metod
    mojSamochod.wyswietlInformacjeSamochodu();

    return 0;
}
```

#### Wyjaśnienie kodu:

1. **Klasa bazowa (`Pojazd`)**  
   - Posiada pola `marka` i `predkosc`, które są chronione (`protected`), więc mogą być używane w klasach pochodnych.
   - Zawiera metodę `wyswietlInformacje()`, która wyświetla dane pojazdu.

2. **Klasa pochodna (`Samochod`)**  
   - Dziedziczy wszystkie pola i metody klasy `Pojazd`.
   - Dodaje nowe pole `liczbaDrzwi` i metodę `wyswietlInformacjeSamochodu()`, która rozszerza funkcjonalność klasy bazowej.

3. **Wywołanie konstruktora klasy bazowej**  
   - Konstruktor klasy pochodnej `Samochod` wywołuje konstruktor klasy bazowej `Pojazd` za pomocą składni `: Pojazd(m, p)`.

4. **Wywoływanie metod z klasy bazowej**  
   - Klasa pochodna może używać metod klasy bazowej (np. `wyswietlInformacje()`).

#### Zalety dziedziczenia
- **Reużywalność kodu** – Nie trzeba powtarzać kodu, ponieważ klasa pochodna może korzystać z gotowych funkcji klasy bazowej.
- **Modularność** – Klasy są bardziej elastyczne i łatwiejsze do rozbudowy.
- **Uporządkowanie** – Logika programu jest lepiej zorganizowana, np. wspólne cechy można umieścić w klasie bazowej.

#### Wskazówki:
- Używaj dziedziczenia tylko wtedy, gdy istnieje **relacja typu "jest"** (np. Samochód **jest** pojazdem).
- Chronione (`protected`) pola klasy bazowej mogą być używane w klasie pochodnej, ale są niedostępne spoza klasy.
