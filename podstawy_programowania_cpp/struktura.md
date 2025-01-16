### Notatka: Struktura w C++

#### Co to jest struktura?

Struktura (`struct`) w C++ to typ danych, który pozwala na grupowanie różnych zmiennych (pol) w jedną całość. Każde pole struktury może mieć inny typ danych, co umożliwia przechowywanie różnych informacji związanych ze sobą w jednym obiekcie.

Struktury są używane, gdy chcemy przechowywać dane różnych typów, które mają być powiązane, np. informacje o pracowniku, książce, samochodzie itp.

#### Składnia definicji struktury

Struktura jest definiowana przy użyciu słowa kluczowego `struct`, a jej składnia wygląda następująco:

```cpp
struct NazwaStruktury {
    TypDanych pole1;
    TypDanych pole2;
    TypDanych pole3;
};
```

- **`NazwaStruktury`**: Nazwa struktury, która może być dowolna, ale zwykle opisuje, do jakiego typu danych się odnosi.
- **`TypDanych`**: Typ danych przypisany do pola w strukturze, może to być dowolny typ (np. `int`, `float`, `char`, inna struktura, wskaźnik itp.).
- **`pole1, pole2, pole3`**: Nazwy pól struktury, które będą przechowywać dane.

#### Przykład: Struktura `Samochód`

```cpp
#include <iostream>
using namespace std;

struct Samochód {
    string marka;
    int rokProdukcji;
    float cena;
};

int main() {
    // Tworzenie obiektu struktury
    Samochód samochód1;
    
    // Przypisanie wartości do pól struktury
    samochód1.marka = "Toyota";
    samochód1.rokProdukcji = 2020;
    samochód1.cena = 75000.50;

    // Wyświetlanie wartości
    cout << "Marka: " << samochód1.marka << endl;
    cout << "Rok produkcji: " << samochód1.rokProdukcji << endl;
    cout << "Cena: " << samochód1.cena << " PLN" << endl;

    return 0;
}
```

**Wynik działania programu:**
```
Marka: Toyota
Rok produkcji: 2020
Cena: 75000.5 PLN
```

**Wyjaśnienie:**
- Struktura `Samochód` zawiera trzy pola: `marka`, `rokProdukcji`, `cena`.
- W funkcji `main` tworzymy obiekt `samochód1` typu `Samochód` i przypisujemy wartości do jego pól.
- Następnie wypisujemy te wartości na ekranie.

#### Tworzenie wskaźników na struktury

Możemy również tworzyć wskaźniki na struktury, aby pracować z nimi bardziej efektywnie, np. w funkcjach.

```cpp
#include <iostream>
using namespace std;

struct Samochód {
    string marka;
    int rokProdukcji;
    float cena;
};

int main() {
    // Tworzenie obiektu struktury
    Samochód samochód1 = {"Toyota", 2020, 75000.50};
    
    // Tworzenie wskaźnika na strukturę
    Samochód* wsk = &samochód1;

    // Dostęp do pól struktury za pomocą wskaźnika
    cout << "Marka: " << wsk->marka << endl;
    cout << "Rok produkcji: " << wsk->rokProdukcji << endl;
    cout << "Cena: " << wsk->cena << " PLN" << endl;

    return 0;
}
```

**Wynik działania programu:**
```
Marka: Toyota
Rok produkcji: 2020
Cena: 75000.5 PLN
```

**Wyjaśnienie:**
- `wsk` to wskaźnik na strukturę `Samochód`, który przechowuje adres obiektu `samochód1`.
- Aby uzyskać dostęp do pól struktury przez wskaźnik, używamy operatora `->` zamiast `.`.

#### Zastosowanie struktur w C++

Struktury mogą być używane do różnych celów:

1. **Organizacja danych**: Struktury pozwalają na łatwiejsze przechowywanie i organizowanie danych powiązanych ze sobą. Na przykład, w programie dotyczącym pracowników możemy stworzyć strukturę `Pracownik`, która zawiera takie pola jak `imie`, `nazwisko`, `wiek`, `pensja`.

2. **Przekazywanie danych do funkcji**: Struktury mogą być przekazywane jako argumenty do funkcji, co umożliwia łatwiejsze zarządzanie danymi.

3. **Tablice struktur**: Możemy tworzyć tablice struktur, co pozwala na przechowywanie wielu obiektów tego samego typu w jednym miejscu.

#### Przykład: Tablica struktur

```cpp
#include <iostream>
using namespace std;

struct Pracownik {
    string imie;
    string nazwisko;
    int wiek;
};

int main() {
    // Tworzenie tablicy struktur
    Pracownik pracownicy[2] = {{"Jan", "Kowalski", 30}, {"Anna", "Nowak", 25}};
    
    // Wyświetlanie danych z tablicy struktur
    for (int i = 0; i < 2; i++) {
        cout << "Imie: " << pracownicy[i].imie << ", Nazwisko: " << pracownicy[i].nazwisko << ", Wiek: " << pracownicy[i].wiek << endl;
    }

    return 0;
}
```

**Wynik działania programu:**
```
Imie: Jan, Nazwisko: Kowalski, Wiek: 30
Imie: Anna, Nazwisko: Nowak, Wiek: 25
```

#### Podsumowanie

- **Struktura** w C++ pozwala na grupowanie różnych typów danych w jedną całość.
- Dzięki strukturom możemy organizować dane w sposób zrozumiały i logiczny.
- Struktury mogą być przekazywane do funkcji, przechowywane w tablicach, a także używane w połączeniu z wskaźnikami.
