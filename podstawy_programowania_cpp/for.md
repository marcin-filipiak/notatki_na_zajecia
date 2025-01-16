### Notatka: Pętla **for** w C++

#### Co to jest pętla **for**?

Pętla **for** to konstrukcja programistyczna, która pozwala na wielokrotne wykonanie określonego fragmentu kodu. Jest często używana, gdy wiemy z góry, ile razy pętla ma zostać wykonana.

#### Składnia pętli **for**

```cpp
for (inicjalizacja; warunek; modyfikacja) {
    // kod wykonywany w pętli
}
```

1. **Inicjalizacja**: Ustawia wartość początkową zmiennej sterującej pętlą. Wykonywana jest tylko raz przed rozpoczęciem pętli.  
2. **Warunek**: Określa, czy pętla ma się dalej wykonywać. Jeśli warunek jest spełniony (true), pętla działa. Gdy warunek staje się fałszywy (false), pętla kończy swoje działanie.  
3. **Modyfikacja**: Wykonywana po każdym przebiegu pętli, zazwyczaj zmienia wartość zmiennej sterującej.

#### Przykład podstawowy

```cpp
#include <iostream>
using namespace std;

int main() {
    // Pętla od 0 do 4
    for (int i = 0; i < 5; i++) {
        cout << "Wartość i: " << i << endl;
    }
    return 0;
}
```

**Wynik działania programu:**
```
Wartość i: 0
Wartość i: 1
Wartość i: 2
Wartość i: 3
Wartość i: 4
```

- **Inicjalizacja**: `int i = 0` – Zmienna `i` rozpoczyna od 0.  
- **Warunek**: `i < 5` – Pętla działa, dopóki `i` jest mniejsze niż 5.  
- **Modyfikacja**: `i++` – Po każdym przebiegu zwiększamy `i` o 1.

#### Przykład z tablicą

Pętla **for** jest często używana do iteracji po elementach tablicy:

```cpp
#include <iostream>
using namespace std;

int main() {
    int liczby[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << liczby[i] << endl;
    }
    return 0;
}
```

**Wynik działania programu:**
```
Element 0: 10
Element 1: 20
Element 2: 30
Element 3: 40
Element 4: 50
```

#### Przykład z liczbami wstecz

Możemy iterować wstecz, zmniejszając wartość zmiennej:

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 5; i > 0; i--) {
        cout << "Wartość i: " << i << endl;
    }
    return 0;
}
```

**Wynik działania programu:**
```
Wartość i: 5
Wartość i: 4
Wartość i: 3
Wartość i: 2
Wartość i: 1
```

#### Pętla **for** i zakresy w C++11

C++ wprowadziło tzw. **range-based for loop**, która upraszcza iterację po kolekcjach, takich jak tablice czy wektory:

```cpp
#include <iostream>
using namespace std;

int main() {
    int liczby[] = {10, 20, 30, 40, 50};

    for (int liczba : liczby) {
        cout << "Liczba: " << liczba << endl;
    }
    return 0;
}
```

**Wynik działania programu:**
```
Liczba: 10
Liczba: 20
Liczba: 30
Liczba: 40
Liczba: 50
```

#### Zalety pętli **for**
1. Idealna do iteracji o określonej liczbie powtórzeń.  
2. Czytelna i przejrzysta struktura.  
3. Łatwo można ją zastosować do pracy z tablicami i kolekcjami.

#### Podsumowanie

- Używaj **for**, gdy znasz liczbę iteracji.  
- Zwracaj uwagę na poprawne warunki i modyfikację zmiennej sterującej, aby uniknąć nieskończonych pętli.  
- Range-based **for** jest wygodniejsze dla iteracji po kontenerach w C++11 i nowszych.
