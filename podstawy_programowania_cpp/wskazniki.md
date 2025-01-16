### Notatka: Wskaźniki w C++

#### Co to jest wskaźnik?

Wskaźnik w C++ to zmienna, która przechowuje adres innej zmiennej w pamięci. Zamiast przechowywać bezpośrednią wartość, wskaźnik przechowuje lokalizację tej wartości w pamięci. Wskaźniki są bardzo przydatne, ponieważ pozwalają na efektywne zarządzanie pamięcią, manipulowanie danymi bez ich kopiowania oraz umożliwiają dynamiczne przydzielanie pamięci.

#### Składnia wskaźników

Wskaźnik jest zadeklarowany z użyciem operatora `*`. Oto ogólna składnia:

```cpp
Typ *nazwaWskaźnika;
```

- **`Typ`**: Typ danych, na które wskaźnik będzie wskazywał (np. `int`, `float`, `char`).
- **`nazwaWskaźnika`**: Nazwa wskaźnika.

#### Przykład deklaracji wskaźnika

```cpp
int *wsk;  // wskaźnik na zmienną typu int
```

#### Przypisanie adresu do wskaźnika

Aby przypisać do wskaźnika adres zmiennej, używamy operatora `&`, który zwraca adres zmiennej.

```cpp
int liczba = 10;
int *wsk = &liczba;  // wskaźnik wskazuje na zmienną liczba
```

#### Dereferencja wskaźnika

Aby uzyskać wartość przechowywaną pod adresem wskazywanym przez wskaźnik, używamy operatora `*` (tzw. dereferencja).

```cpp
int liczba = 10;
int *wsk = &liczba;  // wskaźnik wskazuje na zmienną liczba

cout << *wsk;  // wypisuje wartość zmiennej liczba, czyli 10
```

#### Przykład: Prosty program z wskaźnikiem

```cpp
#include <iostream>
using namespace std;

int main() {
    int liczba = 5;
    int *wsk = &liczba;  // wskaźnik wskazuje na zmienną liczba

    cout << "Wartość zmiennej liczba: " << liczba << endl;
    cout << "Adres zmiennej liczba: " << &liczba << endl;
    cout << "Wartość przez wskaźnik: " << *wsk << endl;
    cout << "Adres przechowywany w wskaźniku: " << wsk << endl;

    return 0;
}
```

**Wynik:**
```
Wartość zmiennej liczba: 5
Adres zmiennej liczba: 0x7fffa5b6f7bc  // adres w pamięci
Wartość przez wskaźnik: 5
Adres przechowywany w wskaźniku: 0x7fffa5b6f7bc  // ten sam adres
```

#### Wskaźniki a tablice

Tablice w C++ są w zasadzie wskaźnikami do pierwszego elementu tablicy. Możemy uzyskać dostęp do elementów tablicy za pomocą wskaźników.

```cpp
#include <iostream>
using namespace std;

int main() {
    int tablica[3] = {1, 2, 3};
    int *wsk = tablica;  // wskaźnik wskazuje na pierwszy element tablicy

    // Dostęp do elementów tablicy za pomocą wskaźnika
    cout << *wsk << endl;  // wypisuje 1
    cout << *(wsk + 1) << endl;  // wypisuje 2
    cout << *(wsk + 2) << endl;  // wypisuje 3

    return 0;
}
```

#### Wskaźniki na funkcje

Wskaźniki mogą również wskazywać na funkcje. Używamy wskaźnika funkcji, aby wywołać funkcję, przekazując jej wskaźnik.

```cpp
#include <iostream>
using namespace std;

void przywitaj() {
    cout << "Witaj!" << endl;
}

int main() {
    void (*wsk)() = przywitaj;  // wskaźnik na funkcję przywitaj

    wsk();  // wywołanie funkcji przez wskaźnik

    return 0;
}
```

#### Wskaźniki i dynamiczne przydzielanie pamięci

Wskaźniki są także używane do dynamicznego przydzielania pamięci w czasie wykonywania programu przy użyciu operatorów `new` i `delete`.

- **`new`**: Służy do dynamicznego przydzielania pamięci na stercie.
- **`delete`**: Służy do zwalniania pamięci, która została wcześniej przydzielona.

```cpp
#include <iostream>
using namespace std;

int main() {
    int *wsk = new int;  // dynamicznie przydzielona pamięć dla zmiennej typu int

    *wsk = 10;  // przypisanie wartości do zmiennej w przydzielonej pamięci

    cout << *wsk << endl;  // wypisuje 10

    delete wsk;  // zwolnienie pamięci

    return 0;
}
```

#### Zastosowania wskaźników

1. **Efektywne przekazywanie dużych struktur i tablic do funkcji**: Zamiast przekazywać całe struktury lub tablice (co wiąże się z kopiowaniem danych), możemy przekazać wskaźnik, co jest bardziej efektywne pod względem wydajności.

2. **Praca z dynamiczną pamięcią**: Wskaźniki umożliwiają dynamiczne przydzielanie i zwalnianie pamięci, co jest szczególnie przydatne, gdy nie znamy wielkości danych w czasie kompilacji.

3. **Implementacja struktur danych**: Wskaźniki są podstawą dla wielu struktur danych, takich jak listy jednokierunkowe, stosy, kolejki, drzewa.

4. **Manipulacja danymi w funkcjach**: Wskaźniki pozwalają na bezpośrednią manipulację danymi w funkcjach, co jest często wykorzystywane w algorytmach i operacjach na dużych zbiorach danych.

#### Podsumowanie

Wskaźniki to potężne narzędzie w C++, umożliwiające efektywne zarządzanie pamięcią, manipulację danymi oraz przekazywanie danych do funkcji bez ich kopiowania. Zrozumienie i poprawne używanie wskaźników jest kluczowe dla zaawansowanego programowania w C++.


---

#### Przykłady

##### Zmienna do funkcji

```cpp
#include <iostream>

void modifyValue(int* ptr) {
    *ptr += 10; // Zwiększamy wartość zmiennej, na którą wskazuje wskaźnik, o 10
}

int main() {
    int number = 5; // Deklarujemy zmienną
    std::cout << "Przed wywołaniem funkcji: " << number << std::endl;

    modifyValue(&number); // Przekazujemy adres zmiennej `number` do funkcji

    std::cout << "Po wywołaniu funkcji: " << number << std::endl;

    return 0;
}
```

##### Tablica do funkcji

```cpp
#include <iostream>

void modifyArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] += 1; // Zwiększamy każdy element tablicy o 1
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5}; // Tablica liczb
    int size = sizeof(numbers) / sizeof(numbers[0]); // Obliczenie liczby elementów w tablicy

    std::cout << "Przed wywołaniem funkcji: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    modifyArray(numbers, size); // Przekazujemy tablicę do funkcji

    std::cout << "Po wywołaniu funkcji: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

```

