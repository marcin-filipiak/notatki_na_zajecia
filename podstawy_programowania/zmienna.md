### Notatka: Zmienne i typy danych w C++

#### Co to jest zmienna?

Zmienne to nazwy reprezentujące miejsca w pamięci, które przechowują dane. Zmienne pozwalają na odwoływanie się do tych danych w kodzie.

- Każda zmienna ma **typ**, który określa, jakie dane może przechowywać (np. liczby, teksty, znaki).  
- Przed użyciem zmienną należy zadeklarować, podając jej typ i nazwę.

#### Deklaracja zmiennej

```cpp
typ nazwa_zmiennej;
```

#### Inicjalizacja zmiennej

Możemy przypisać wartość do zmiennej podczas jej deklaracji lub później.

```cpp
typ nazwa_zmiennej = wartość; // Deklaracja i inicjalizacja
nazwa_zmiennej = nowa_wartość; // Przypisanie nowej wartości
```

#### Przykład:

```cpp
#include <iostream>
using namespace std;

int main() {
    int liczba = 10;  // Deklaracja i inicjalizacja
    cout << "Liczba: " << liczba << endl;
    liczba = 20;      // Zmiana wartości
    cout << "Nowa liczba: " << liczba << endl;

    return 0;
}
```

**Wynik działania programu:**
```
Liczba: 10
Nowa liczba: 20
```

---

#### Typy danych w C++

C++ oferuje różne typy danych do przechowywania różnych rodzajów informacji.

| **Typ danych** | **Opis**                         | **Przykład wartości** |
|-----------------|---------------------------------|-----------------------|
| `int`          | Liczby całkowite                | 10, -5, 0            |
| `float`        | Liczby zmiennoprzecinkowe       | 3.14, -2.7           |
| `double`       | Liczby zmiennoprzecinkowe (precyzyjne) | 3.141592             |
| `char`         | Pojedynczy znak                 | 'a', '1', '$'        |
| `bool`         | Wartości logiczne               | `true`, `false`      |
| `string`       | Ciągi znaków (tekst)            | "Cześć", "123"       |

---

#### Przykłady deklaracji różnych typów:

```cpp
#include <iostream>
#include <string> // Konieczne dla typu string
using namespace std;

int main() {
    int liczba = 42;                // Liczba całkowita
    float temperatura = 36.6;       // Liczba zmiennoprzecinkowa
    char znak = 'A';                // Pojedynczy znak
    bool czyPrawda = true;          // Wartość logiczna
    string tekst = "Witaj w C++!";  // Ciąg znaków

    cout << "Liczba: " << liczba << endl;
    cout << "Temperatura: " << temperatura << endl;
    cout << "Znak: " << znak << endl;
    cout << "Czy prawda: " << czyPrawda << endl;
    cout << "Tekst: " << tekst << endl;

    return 0;
}
```

**Wynik działania programu:**
```
Liczba: 42
Temperatura: 36.6
Znak: A
Czy prawda: 1
Tekst: Witaj w C++!
```

---

#### Zasady nazywania zmiennych

1. Nazwa zmiennej może zawierać litery, cyfry i znak podkreślenia `_`.
2. Nazwa musi zaczynać się od litery lub `_` (nie może zaczynać się od cyfry).
3. Nazwa zmiennej jest **wielkościoliterowa** (`liczba` i `Liczba` to różne zmienne).
4. Nie można używać słów kluczowych języka C++ jako nazw zmiennych (np. `int`, `return`).

---

#### Konwersja typów

Możesz konwertować wartości jednego typu na inny, np. liczby całkowite na zmiennoprzecinkowe.

**Przykład:**

```cpp
int liczba = 10;
float liczbaFloat = (float)liczba; // Jawna konwersja
cout << "Liczba jako float: " << liczbaFloat << endl;
```

---

#### Podsumowanie

- Zmienne przechowują dane, które program wykorzystuje w trakcie działania.  
- Typ zmiennej określa rodzaj przechowywanych danych.  
- Warto używać nazw opisowych, które jasno określają, co zmienna reprezentuje.
