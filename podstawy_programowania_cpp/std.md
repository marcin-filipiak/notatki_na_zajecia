# Namespace std

Przestrzeń nazw (ang. *namespace*) w C++ to mechanizm służący do organizacji i grupowania nazw (zmiennych, funkcji, klas itp.) w sposób, który pomaga uniknąć konfliktów nazw między różnymi częściami kodu lub bibliotekami.

### Co robi `std`?

Gdy w C++ dodajesz `#include <iostream>` i używasz `cout`, `std` wskazuje na przestrzeń nazw, w której `cout` (jak i inne rzeczy z `iostream`, np. `cin` i `endl`) zostały zdefiniowane. Właściwie `cout` jest pełną nazwą `std::cout`, gdzie `std` to skrót od "standard" (*standard library namespace*). Dzięki temu kompilator wie, że `cout` należy do standardowej biblioteki C++.

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

Powyższy kod jest poprawny, ponieważ `std::cout` wyraźnie wskazuje na `cout` z przestrzeni nazw `std`. Można również zastosować instrukcję:

```cpp
using namespace std;
```

dzięki której możesz pisać po prostu `cout` zamiast `std::cout`. Jednak `using namespace std;` nie jest najlepszym rozwiązaniem w dużych programach, ponieważ może prowadzić do konfliktów nazw, zwłaszcza przy korzystaniu z różnych bibliotek.

### Po co się tego używa?

Celem przestrzeni nazw jest:
1. **Zapobieganie konfliktom nazw** – kiedy różne biblioteki mają te same nazwy funkcji lub zmiennych, przestrzeń nazw pozwala uniknąć konfliktów, np. `std::cout` i `myLib::cout`.
2. **Organizacja kodu** – przestrzenie nazw grupują kod logicznie. Dzięki temu łatwiej się nim zarządza w większych projektach.

### Czy mogą być inne przestrzenie nazw?

Tak, możesz tworzyć własne przestrzenie nazw, aby zorganizować swój kod i uniknąć konfliktów. Oto przykład:

```cpp
#include <iostream>

namespace myNamespace {
    void print() {
        std::cout << "Hello from myNamespace!" << std::endl;
    }
}

int main() {
    myNamespace::print();
    return 0;
}
```

Tutaj `print` należy do `myNamespace`, więc możesz odwołać się do niej jako `myNamespace::print()`, co pozwala na bezkonfliktowe użycie różnych funkcji `print` w innych przestrzeniach nazw.

### Podsumowanie

- **`std`** to przestrzeń nazw, która zawiera elementy standardowej biblioteki C++, jak `cout`, `cin`, `string` itd.
- **Inne przestrzenie nazw** również mogą istnieć – możesz nawet tworzyć własne.
- Przestrzenie nazw są przydatne dla **organizacji kodu** i **unikania konfliktów nazw** w większych projektach.
