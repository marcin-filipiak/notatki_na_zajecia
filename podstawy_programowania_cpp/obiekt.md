### Notatka: Podstawy obiektowości w C++ – klasa, obiekt, metoda, private, public

#### Czym jest klasa?

Klasa to **szablon**, który opisuje, jakie dane i funkcje (metody) będą miały obiekty stworzone na jej podstawie. Klasa definiuje strukturę i zachowanie obiektów, łącząc dane i funkcje w jedną całość.

Przykład: Klasa **Samochod** może mieć dane takie jak **marka**, **model**, **prędkość**, oraz funkcje, które pozwalają np. zwiększyć prędkość.

#### Czym jest obiekt?

Obiekt to **instancja klasy**, czyli konkretny egzemplarz, który posiada swoje własne wartości danych opisanych w klasie. Obiekt to coś, co istnieje w pamięci i może wykonywać metody klasy.

#### Czym są metody?

Metody to **funkcje zdefiniowane w klasie**, które operują na danych obiektu. Mogą np. zmieniać wartości pól, pobierać dane lub wykonywać obliczenia.

#### Dostępność pól i metod: **private** i **public**

1. **private**  
   - Dane lub metody oznaczone jako `private` są **niedostępne** bezpośrednio spoza klasy. Można się do nich odwoływać tylko wewnątrz klasy.  
   - Używane do ukrycia szczegółów implementacji.

2. **public**  
   - Dane lub metody oznaczone jako `public` są **dostępne** z zewnątrz klasy.  
   - Używane do komunikacji z obiektem (np. wywoływanie metod).

#### Jak zrobić klasę i obiekt w C++?

Oto przykładowy kod:

```cpp
#include <iostream>
#include <string>
using namespace std;

// Definicja klasy
class Samochod {
private:
    string marka;      // Prywatne pole
    int predkosc;      // Prywatne pole

public:
    // Konstruktor do inicjalizacji obiektu
    Samochod(string m, int p) {
        marka = m;
        predkosc = p;
    }

    // Metoda publiczna do ustawiania prędkości
    void ustawPredkosc(int p) {
        predkosc = p;
    }

    // Metoda publiczna do wyświetlania informacji
    void wyswietlInformacje() {
        cout << "Marka: " << marka << endl;
        cout << "Prędkość: " << predkosc << " km/h" << endl;
    }
};

int main() {
    // Tworzenie obiektu klasy Samochod
    Samochod mojSamochod("Toyota", 0);

    // Wywoływanie metod obiektu
    mojSamochod.ustawPredkosc(120); // Ustaw prędkość na 120 km/h
    mojSamochod.wyswietlInformacje(); // Wyświetl informacje o samochodzie

    return 0;
}
```

#### Wyjaśnienie krok po kroku:

1. **Tworzenie klasy**  
   - Pole `marka` i `predkosc` są prywatne (`private`), więc nie można ich zmieniać bezpośrednio.
   - Publiczne (`public`) metody `ustawPredkosc()` i `wyswietlInformacje()` pozwalają ustawić wartości pól i wyświetlić ich zawartość.

2. **Tworzenie obiektu**  
   - W funkcji `main()` tworzony jest obiekt `mojSamochod` z nazwą marki "Toyota" i początkową prędkością 0.

3. **Wywoływanie metod**  
   - `ustawPredkosc(120)` zmienia wartość prędkości.
   - `wyswietlInformacje()` wypisuje aktualny stan obiektu.

#### Ważne wskazówki:
- **Konstruktor** (np. `Samochod(string m, int p)`) automatycznie inicjalizuje pola obiektu w momencie jego tworzenia.
- Stosowanie **private** pomaga chronić dane przed niepożądanymi zmianami.
- Publiczne metody są "interfejsem", który umożliwia kontrolowany dostęp do obiektu.
