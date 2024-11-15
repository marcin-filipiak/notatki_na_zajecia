### Notatka: Dyrektywa `#include` w C++

#### Co to jest `#include`?

Dyrektywa `#include` jest komendą preprocesora w C++, która pozwala na dołączanie zewnętrznych plików do programu. Umożliwia to korzystanie z funkcji, klas, zmiennych i innych elementów, które zostały zdefiniowane w innych plikach.

#### Jak działa `#include`?

Gdy używamy `#include`, kompilator wstawia zawartość wskazanego pliku bezpośrednio do miejsca, gdzie ta dyrektywa występuje. Dzięki temu możemy dzielić kod na mniejsze, łatwiejsze do zarządzania pliki.

#### Rodzaje `#include`

1. **Dołączanie plików systemowych**  
   Pliki systemowe, takie jak standardowe biblioteki C++ (np. `iostream`, `cmath`), są dołączane w nawiasach ostrych `<>`.

   ```cpp
   #include <iostream>  // Dołącza bibliotekę standardową iostream
   ```

2. **Dołączanie własnych plików nagłówkowych**  
   Jeśli dołączamy plik, który znajduje się w tym samym katalogu, używamy podwójnych cudzysłowów `""`.

   ```cpp
   #include "mojplik.h"  // Dołącza plik nagłówkowy 'mojplik.h'
   ```

#### Przykłady użycia

1. **Dołączenie pliku nagłówkowego standardowej biblioteki**

   Aby używać funkcji do wyjścia na ekran, takich jak `cout` lub `cin`, musimy dołączyć plik nagłówkowy `iostream`.

   ```cpp
   #include <iostream>  // Dołączenie biblioteki iostream
   using namespace std;

   int main() {
       cout << "Witaj w C++!" << endl;  // Wyświetlanie tekstu
       return 0;
   }
   ```

2. **Dołączenie własnego pliku nagłówkowego**

   Możemy stworzyć własny plik nagłówkowy z definicjami funkcji, klas itp., a następnie za pomocą `#include` dołączyć go do głównego programu.

   **Plik `moja_funkcja.h`:**
   ```cpp
   #ifndef MOJA_FUNKCJA_H
   #define MOJA_FUNKCJA_H

   void wypiszHello();

   #endif
   ```

   **Plik `moja_funkcja.cpp`:**
   ```cpp
   #include "moja_funkcja.h"
   #include <iostream>

   void wypiszHello() {
       std::cout << "Hello, World!" << std::endl;
   }
   ```

   **Plik `main.cpp`:**
   ```cpp
   #include "moja_funkcja.h"

   int main() {
       wypiszHello();
       return 0;
   }
   ```

   **Wynik działania programu:**
   ```
   Hello, World!
   ```

#### Dlaczego używamy `#include`?

1. **Modularność**: Dzięki `#include` możemy dzielić program na mniejsze pliki, co sprawia, że kod jest łatwiejszy do zarządzania.
2. **Reużywalność kodu**: Pliki nagłówkowe pozwalają na ponowne użycie funkcji i klas w różnych częściach programu.
3. **Ułatwienie w pracy zespołowej**: Programiści mogą tworzyć swoje własne pliki nagłówkowe i używać ich w innych projektach.

#### Podsumowanie

- Dyrektywa `#include` pozwala na dołączanie plików nagłówkowych do programu.
- Pliki systemowe są dołączane z użyciem `<>`, a pliki lokalne — z użyciem `""`.
- `#include` umożliwia modularność, reużywalność kodu i ułatwia pracę zespołową.
