### Notatka: Dyrektywa `#define` w C++

#### Co to jest `#define`?

Dyrektywa `#define` w C++ jest częścią preprocesora, który pozwala na definiowanie stałych, makr lub wyrażeń przed kompilowaniem programu. Jest używana głównie do tworzenia aliasów dla wartości, stałych, funkcji lub nawet wyrażeń, które mogą być później używane w kodzie źródłowym.

#### Składnia `#define`

```cpp
#define NAZWA wartość
```

- **`NAZWA`**: Nazwa stałej lub makra, która będzie używana w programie.
- **`wartość`**: Wartość, która zostanie przypisana do nazwy lub kod, który zostanie wstawiony w miejsce `NAZWA`.

#### Przykład 1: Definicja stałej

```cpp
#include <iostream>
using namespace std;

#define PI 3.14159  // Definicja stałej PI

int main() {
    cout << "Wartość PI: " << PI << endl;
    return 0;
}
```

**Wynik działania programu:**
```
Wartość PI: 3.14159
```

**Wyjaśnienie**: 
- Dyrektywa `#define` zdefiniowała stałą `PI` o wartości `3.14159`.
- Gdy kompilator napotka `PI` w kodzie, zastępuje ją wartością `3.14159` przed kompilowaniem.

#### Przykład 2: Definicja makra

Makro to wyrażenie, które jest zastępowane w kodzie źródłowym przed kompilacją.

```cpp
#include <iostream>
using namespace std;

#define SQUARE(x) ((x) * (x))  // Makro obliczające kwadrat liczby

int main() {
    int a = 5;
    cout << "Kwadrat liczby " << a << " to " << SQUARE(a) << endl;
    return 0;
}
```

**Wynik działania programu:**
```
Kwadrat liczby 5 to 25
```

**Wyjaśnienie**: 
- Makro `SQUARE(x)` jest zdefiniowane, aby obliczać kwadrat liczby.
- Zamiast funkcji, preprocesor podstawia odpowiednią formułę, np. `SQUARE(5)` zostaje zastąpione przez `((5) * (5))`.

#### Przykład 3: Makro z wieloma argumentami

Można definiować makra, które przyjmują więcej niż jeden argument.

```cpp
#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))  // Makro zwracające większą z dwóch liczb

int main() {
    int x = 10, y = 20;
    cout << "Większa liczba to: " << MAX(x, y) << endl;
    return 0;
}
```

**Wynik działania programu:**
```
Większa liczba to: 20
```

**Wyjaśnienie**: 
- Makro `MAX(a, b)` zwraca większą z dwóch wartości. Preprocesor zamienia `MAX(x, y)` na odpowiednią część wyrażenia, czyli `((x) > (y) ? (x) : (y))`.

#### Przykład 4: Warunkowe definiowanie makr

Można używać dyrektywy `#define` do zdefiniowania warunków kompilacji, np. dla różnych platform.

```cpp
#include <iostream>
using namespace std;

#define WINDOWS  // Kompilowanie programu dla systemu Windows

int main() {
    #ifdef WINDOWS
        cout << "Program działa na systemie Windows" << endl;
    #else
        cout << "Program działa na innym systemie" << endl;
    #endif

    return 0;
}
```

**Wynik działania programu:**
```
Program działa na systemie Windows
```

**Wyjaśnienie**:
- Dyrektywa `#ifdef WINDOWS` sprawdza, czy `WINDOWS` zostało zdefiniowane.
- Jeśli jest zdefiniowane, zostanie wykonany odpowiedni blok kodu.
- Jeśli `#define WINDOWS` zostanie usunięte, program wypisze "Program działa na innym systemie".

#### Zastosowania `#define`

1. **Stałe wartości**: Używając `#define`, można łatwo tworzyć stałe, które mogą być używane w całym programie.
2. **Makra**: `#define` umożliwia tworzenie makr, które działają jak funkcje, ale są przetwarzane przez preprocesor, co może przyspieszyć działanie programu.
3. **Kontrola kompilacji**: `#define` może być używane w połączeniu z dyrektywami warunkowymi (takimi jak `#ifdef`, `#ifndef`) do tworzenia wersji programu przeznaczonej dla różnych systemów lub warunków.

#### Uwagi o `#define`

- **Brak sprawdzania typu**: Preprocesor nie sprawdza typów podczas podstawiania wartości przez makra, co może prowadzić do problemów z typami danych, zwłaszcza w przypadku makr przyjmujących argumenty.
- **Problemy z nawiasami**: Aby uniknąć błędów przy obliczaniach w makrach, zawsze warto używać nawiasów wokół argumentów i wyrażeń, np. `((x) * (x))`, żeby zapewnić prawidłową kolejność działań.

#### Podsumowanie

- Dyrektywa `#define` pozwala na definiowanie stałych i makr, które są podstawiane w kodzie przed kompilacją.
- Może być używana do zwiększenia czytelności kodu, unikania powtarzania wartości i uproszczenia konfiguracji dla różnych platform.
- Warto zachować ostrożność przy używaniu makr, szczególnie przy operacjach matematycznych i logice warunkowej.
