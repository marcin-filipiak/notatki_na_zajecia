### Notatka: Szablony (Templates) w C++

#### Czym są szablony (templates)?
Szablony w C++ pozwalają pisać funkcje oraz klasy, które mogą działać na różnych typach danych bez konieczności powtarzania kodu dla każdego z typów. Dzięki temu kod jest bardziej elastyczny i wielokrotnego użytku. Szablony są narzędziem pozwalającym na **generowanie kodu**, który działa z różnymi typami danych na etapie kompilacji.

#### Dlaczego warto używać szablonów?
- **Elastyczność**: Szablony umożliwiają tworzenie funkcji i klas, które mogą działać na dowolnym typie danych.
- **Oszczędność kodu**: Unikamy duplikowania kodu dla różnych typów danych, co zmniejsza jego rozmiar i poprawia czytelność.
- **Bezpieczeństwo typów**: Błędy związane z niezgodnością typów są wykrywane na etapie kompilacji, co poprawia bezpieczeństwo programu.

#### Szablony funkcji

Szablon funkcji to sposób na zdefiniowanie jednej funkcji, która będzie działała na różnych typach danych. Kluczowe słowo kluczowe `template <typename T>` lub `template <class T>` mówi kompilatorowi, że funkcja będzie działać na typie `T`, który zostanie określony podczas wywołania funkcji.

##### Przykład 1: Funkcja szablonowa do porównania dwóch wartości

```cpp
#include <iostream>
using namespace std;

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Maksymalna wartość: " << max(10, 20) << endl;          // Dla typu int
    cout << "Maksymalna wartość: " << max(5.5, 2.3) << endl;        // Dla typu double
    cout << "Maksymalna wartość: " << max('a', 'z') << endl;        // Dla typu char
    return 0;
}
```

##### Wyjaśnienie:
- `template <typename T>` oznacza, że `T` to dowolny typ danych.
- Funkcja `max` działa na dowolnym typie `T` i porównuje dwie wartości, zwracając większą.

#### Szablony klas

Szablon klasy to sposób na definiowanie klas, które mogą działać na różnych typach danych. Używamy podobnej składni jak w przypadku funkcji.

##### Przykład 2: Szablon klasy dla stosu (stack)

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T arr[10];
    int top;
public:
    Stack() : top(-1) {}
    
    void push(T value) {
        if (top < 9) {
            arr[++top] = value;
        } else {
            cout << "Stos jest pełny!" << endl;
        }
    }
    
    T pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stos jest pusty!" << endl;
            return T();  // Zwraca wartość domyślną dla typu T
        }
    }
};

int main() {
    Stack<int> stackInt;
    stackInt.push(10);
    stackInt.push(20);
    cout << "Zdejmowanie ze stosu: " << stackInt.pop() << endl;
    
    Stack<string> stackString;
    stackString.push("Hello");
    stackString.push("World");
    cout << "Zdejmowanie ze stosu: " << stackString.pop() << endl;
    
    return 0;
}
```

##### Wyjaśnienie:
- `template <typename T>` pozwala na utworzenie klasy `Stack`, która może przechowywać elementy dowolnego typu `T`.
- W przykładzie pokazano stos dla liczb całkowitych (`Stack<int>`) oraz dla ciągów znaków (`Stack<string>`).

#### Kiedy używać szablonów?
- Gdy masz funkcje lub klasy, które mogą działać na różnych typach danych.
- Gdy chcesz zredukować powielanie kodu.
- Gdy zależy Ci na elastyczności i wielokrotności użycia kodu bez rezygnacji z bezpieczeństwa typów.

Szablony są szczególnie przydatne w sytuacjach, gdzie podobne operacje wykonywane są na różnych typach danych, jak na przykład sortowanie, przechowywanie elementów w strukturach danych czy operacje matematyczne.

### Podsumowanie
Szablony w C++ to potężne narzędzie, które zwiększa elastyczność i wielokrotność użycia kodu. Umożliwiają pisanie funkcji i klas, które mogą działać na różnych typach danych, co oszczędza czas i zmniejsza ilość powtarzanego kodu.
