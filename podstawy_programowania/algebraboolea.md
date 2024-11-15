### Notatka: Algebra Boole'a w kontekście C++ i instrukcji warunkowych `if`

#### Co to jest algebra Boole'a?

Algebra Boole'a to dziedzina matematyki zajmująca się operacjami logicznymi, które operują na wartościach **prawda** (True) i **fałsz** (False). Jest to podstawa do pracy z warunkami i instrukcjami warunkowymi w programowaniu, w tym w języku C++. Algebra Boole'a pozwala na manipulowanie wartościami logicznymi, co umożliwia podejmowanie decyzji w programie.

W algebraze Boole'a mamy do czynienia z dwoma głównymi operacjami logicznymi:
- **AND (konjunkcja)** – zwraca `true`, gdy oba operandy są `true`.
- **OR (alternatywa)** – zwraca `true`, gdy przynajmniej jeden operand jest `true`.
- **NOT (negacja)** – odwraca wartość logiczną, czyli zmienia `true` na `false` i odwrotnie.

#### Typ logiczny w C++ (`bool`)

W języku C++ typ **`bool`** jest typem logicznym, który może przyjmować tylko dwie wartości:
- **`true`** (prawda)
- **`false`** (fałsz)

Wartości te są używane w warunkach logicznych, które decydują o dalszym przebiegu programu.

#### Instrukcja warunkowa `if` w C++

Instrukcja warunkowa `if` w C++ służy do wykonywania różnych fragmentów kodu w zależności od spełnienia określonego warunku. Warunek w instrukcji `if` jest wyrażeniem logicznym, które może być prawdziwe (`true`) lub fałszywe (`false`).

**Składnia:**
```cpp
if (warunek) {
    // kod wykonywany, gdy warunek jest prawdziwy (true)
}
```

Jeśli warunek w nawiasach jest prawdziwy, zostanie wykonany kod znajdujący się wewnątrz bloku `{}`. Jeśli warunek jest fałszywy, blok ten zostanie pominięty.

#### Przykład użycia `if`:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;

    if (a < b) {
        cout << "a jest mniejsze od b" << endl;
    }

    return 0;
}
```

**Wynik:**
```
a jest mniejsze od b
```

W tym przykładzie, jeśli zmienna `a` jest mniejsza od zmiennej `b`, warunek `a < b` jest prawdziwy (`true`), więc zostanie wykonany kod wewnątrz bloku `if`.

#### Operatory logiczne w C++

C++ udostępnia różne operatory logiczne do tworzenia bardziej złożonych warunków:

1. **Operator AND (`&&`)**: Zwraca `true`, jeśli oba warunki są `true`.

   ```cpp
   if (a > 5 && b < 30) {
       // kod wykonany, jeśli oba warunki są prawdziwe
   }
   ```

2. **Operator OR (`||`)**: Zwraca `true`, jeśli przynajmniej jeden warunek jest `true`.

   ```cpp
   if (a > 5 || b < 15) {
       // kod wykonany, jeśli przynajmniej jeden warunek jest prawdziwy
   }
   ```

3. **Operator NOT (`!`)**: Zwraca `true`, jeśli warunek jest fałszywy.

   ```cpp
   if (!(a == 10)) {
       // kod wykonany, jeśli a nie jest równe 10
   }
   ```

#### Złożone wyrażenia logiczne

W C++ możemy łączyć różne operatory logiczne w bardziej złożone wyrażenia logiczne. To pozwala na tworzenie bardziej skomplikowanych warunków w instrukcjach `if`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20, c = 5;

    if ((a < b) && (c < a)) {
        cout << "Warunek jest prawdziwy!" << endl;
    }

    return 0;
}
```

**Wynik:**
```
Warunek jest prawdziwy!
```

W tym przypadku oba warunki muszą być spełnione, aby blok `if` został wykonany. Użycie operatora `&&` (AND) sprawia, że obie części warunku muszą być prawdziwe.

#### Zastosowanie instrukcji warunkowej `if` w praktyce

Instrukcja `if` jest podstawowym narzędziem do podejmowania decyzji w programie. Na przykład:

1. **Sprawdzanie wartości zmiennych**: Używając `if`, możemy sprawdzić, czy zmienna spełnia określony warunek i na tej podstawie podjąć dalsze działania.
   
   ```cpp
   int wiek = 18;
   if (wiek >= 18) {
       cout << "Jesteś pełnoletni!" << endl;
   }
   ```

2. **Wielokrotne warunki**: Możemy używać instrukcji `if` z operatorem `else` lub `else if` do obsługi różnych przypadków.

   ```cpp
   int liczba = 5;

   if (liczba > 0) {
       cout << "Liczba jest dodatnia" << endl;
   } else if (liczba < 0) {
       cout << "Liczba jest ujemna" << endl;
   } else {
       cout << "Liczba jest zerem" << endl;
   }
   ```

**Wynik:**
```
Liczba jest dodatnia
```

#### Podsumowanie

Algebra Boole'a w C++ jest podstawą dla operacji logicznych, które są używane w instrukcjach warunkowych `if`. Dzięki niej możemy sprawdzać warunki, podejmować decyzje i tworzyć bardziej złożone logiki w programie. Instrukcja `if` pozwala na wykonanie kodu tylko wtedy, gdy spełniony jest określony warunek, a operatorzy logiczni (`&&`, `||`, `!`) umożliwiają tworzenie bardziej skomplikowanych warunków w programie.
