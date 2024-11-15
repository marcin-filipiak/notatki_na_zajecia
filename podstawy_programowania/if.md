### Notatka: Instrukcja **if** w C++

#### Co to jest instrukcja **if**?

Instrukcja **if** to jedna z podstawowych konstrukcji sterujących w programowaniu. Pozwala na wykonanie określonego fragmentu kodu tylko wtedy, gdy podany **warunek logiczny** jest spełniony (czyli ma wartość `true`).

#### Składnia instrukcji **if**

```cpp
if (warunek) {
    // kod wykonywany, gdy warunek jest spełniony
}
```

1. **Warunek**: To wyrażenie logiczne, które jest oceniane jako `true` (prawda) lub `false` (fałsz).  
2. **Kod w bloku**: Jeśli warunek jest prawdziwy, wykonywany jest kod umieszczony w nawiasach `{}`.  

#### Przykład podstawowy

```cpp
#include <iostream>
using namespace std;

int main() {
    int liczba = 10;

    if (liczba > 5) {
        cout << "Liczba jest większa niż 5." << endl;
    }

    return 0;
}
```

**Wynik działania programu:**
```
Liczba jest większa niż 5.
```

#### Instrukcja **if...else**

Jeśli chcesz wykonać inny kod, gdy warunek nie jest spełniony, możesz użyć instrukcji **else**:

```cpp
if (warunek) {
    // kod wykonywany, gdy warunek jest spełniony
} else {
    // kod wykonywany, gdy warunek nie jest spełniony
}
```

#### Przykład z **else**

```cpp
#include <iostream>
using namespace std;

int main() {
    int liczba = 3;

    if (liczba > 5) {
        cout << "Liczba jest większa niż 5." << endl;
    } else {
        cout << "Liczba jest mniejsza lub równa 5." << endl;
    }

    return 0;
}
```

**Wynik działania programu:**
```
Liczba jest mniejsza lub równa 5.
```

#### Instrukcja **if...else if...else**

Jeśli chcesz sprawdzić więcej niż jeden warunek, możesz użyć **else if**:

```cpp
if (warunek1) {
    // kod wykonywany, gdy warunek1 jest spełniony
} else if (warunek2) {
    // kod wykonywany, gdy warunek2 jest spełniony
} else {
    // kod wykonywany, gdy żaden warunek nie jest spełniony
}
```

#### Przykład z wieloma warunkami

```cpp
#include <iostream>
using namespace std;

int main() {
    int liczba = 7;

    if (liczba > 10) {
        cout << "Liczba jest większa niż 10." << endl;
    } else if (liczba == 10) {
        cout << "Liczba jest równa 10." << endl;
    } else {
        cout << "Liczba jest mniejsza niż 10." << endl;
    }

    return 0;
}
```

**Wynik działania programu:**
```
Liczba jest mniejsza niż 10.
```

#### Operatory logiczne w instrukcji **if**

Do tworzenia bardziej złożonych warunków można używać operatorów logicznych:
1. **`&&` (i)** – oba warunki muszą być prawdziwe.  
2. **`||` (lub)** – przynajmniej jeden warunek musi być prawdziwy.  
3. **`!` (nie)** – odwraca wartość logiczną (np. `!true` to `false`).

#### Przykład z operatorami logicznymi

```cpp
#include <iostream>
using namespace std;

int main() {
    int liczba = 8;

    if (liczba > 5 && liczba < 10) {
        cout << "Liczba jest większa niż 5 i mniejsza niż 10." << endl;
    } else {
        cout << "Liczba nie spełnia warunków." << endl;
    }

    return 0;
}
```

**Wynik działania programu:**
```
Liczba jest większa niż 5 i mniejsza niż 10.
```

#### Wskazówki dotyczące używania **if**
- Zawsze pamiętaj o umieszczaniu warunku w nawiasach `()`.  
- Blok kodu `{}` jest opcjonalny, jeśli instrukcja ma tylko jedną linię, ale zaleca się jego stosowanie dla przejrzystości.  
- W przypadku złożonych warunków używaj operatorów logicznych, aby uprościć kod.  

#### Podsumowanie

- Instrukcja **if** pozwala na sterowanie wykonaniem kodu na podstawie warunków.  
- Możesz używać **else** i **else if**, aby obsługiwać alternatywne ścieżki działania.  
- Operatory logiczne pomagają tworzyć złożone wyrażenia warunkowe.  
