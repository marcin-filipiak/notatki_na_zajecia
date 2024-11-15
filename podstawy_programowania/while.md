### Notatka: Pętla `while` w C++

#### Co to jest pętla `while`?

Pętla `while` jest jednym z podstawowych mechanizmów umożliwiających wielokrotne wykonanie tego samego fragmentu kodu w zależności od spełnienia określonego warunku. Pętla działa tak długo, jak warunek jest spełniony (true). Gdy warunek stanie się fałszywy (false), pętla zostaje przerwana, a program kontynuuje wykonywanie kolejnych instrukcji.

#### Składnia pętli `while`

```cpp
while (warunek) {
    // kod do wykonania, jeśli warunek jest prawdziwy
}
```

- **`warunek`**: Wyrażenie, które jest oceniane przed każdym obiegiem pętli. Pętla wykonuje się, dopóki to wyrażenie zwraca wartość true.
- **Kod w ciele pętli**: Zawiera instrukcje, które będą wykonywane, gdy warunek będzie spełniony.

#### Przykład 1: Pętla `while` z licznikiem

```cpp
#include <iostream>
using namespace std;

int main() {
    int licznik = 1;

    while (licznik <= 5) {
        cout << "Licznik: " << licznik << endl;
        licznik++;  // Zwiększenie licznika o 1
    }

    return 0;
}
```

**Wynik działania programu:**
```
Licznik: 1
Licznik: 2
Licznik: 3
Licznik: 4
Licznik: 5
```

#### Jak działa ten przykład?

- Zmienna `licznik` jest ustawiona na 1.
- Pętla `while` wykonuje się, dopóki `licznik` jest mniejszy lub równy 5.
- W każdej iteracji wyświetlana jest wartość zmiennej `licznik`, a potem jest ona zwiększana o 1.
- Kiedy `licznik` osiągnie 6, warunek `licznik <= 5` stanie się fałszywy, a pętla zakończy swoje działanie.

#### Przykład 2: Pętla `while` z użytkownikiem

W tym przykładzie użytkownik będzie wprowadzał liczby do momentu, gdy wprowadzi liczbę 0.

```cpp
#include <iostream>
using namespace std;

int main() {
    int liczba = -1;  // Inicjalizacja liczby

    while (liczba != 0) {
        cout << "Podaj liczbę (0, aby zakończyć): ";
        cin >> liczba;
    }

    cout << "Pętla zakończona." << endl;

    return 0;
}
```

**Wynik działania programu (przykład):**
```
Podaj liczbę (0, aby zakończyć): 5
Podaj liczbę (0, aby zakończyć): 10
Podaj liczbę (0, aby zakończyć): 0
Pętla zakończona.
```

#### Wartości zwracane przez warunek

Pętla `while` wykonuje się, gdy warunek zwraca wartość true. Jeśli warunek jest false od samego początku, kod w pętli nigdy nie zostanie wykonany.

```cpp
int liczba = 10;
while (liczba < 5) {
    cout << "Ta linia nigdy się nie wyświetli." << endl;
}
```

W powyższym przykładzie, ponieważ `liczba` jest większa niż 5, warunek `liczba < 5` jest fałszywy, a kod w pętli nigdy się nie wykona.

#### Zastosowania pętli `while`

- **Iteracje o nieznanej liczbie powtórzeń**: Pętla `while` jest przydatna, gdy liczba iteracji nie jest z góry określona, a zależy od warunku w czasie wykonywania programu.
- **Czekanie na spełnienie warunku**: Pętla `while` jest często używana w przypadku oczekiwania na określony stan (np. czekanie na dane od użytkownika, wprowadzenie poprawnej wartości, itp.).

#### Podsumowanie

- Pętla `while` wykonuje się tak długo, jak warunek w nawiasie jest prawdziwy.
- Zmienna sterująca pętlą powinna być odpowiednio modyfikowana, aby uniknąć nieskończonej pętli.
- Pętla `while` jest stosunkowo prosta w użyciu, a jej główną zaletą jest możliwość dynamicznego kontrolowania liczby iteracji na podstawie zmieniających się warunków.
