### Kompilator G++ dla języka C++

G++ (i cały zestaw GCC) jest bardzo wszechstronny i może kompilować kod na wiele różnych architektur procesorów. Najpopularniejsze z nich to:

1. **x86 i x86_64 (AMD64)** – Architektury używane w większości komputerów stacjonarnych, laptopów i serwerów.
2. **ARM** – Szeroko stosowane w urządzeniach mobilnych, takich jak smartfony, tablety, a także w systemach wbudowanych i serwerach (np. Raspberry Pi).
3. **PowerPC** – Używany dawniej w komputerach Apple, a obecnie w systemach serwerowych i wbudowanych.
4. **RISC-V** – Nowoczesna, otwarta architektura procesorów, która zyskuje na popularności.
5. **MIPS** – Wykorzystywana w niektórych systemach wbudowanych, routerach i urządzeniach sieciowych.
6. **SPARC** – Architektura stosowana głównie w serwerach.

Dzięki tej wszechstronności, G++ może być używany zarówno do kompilowania aplikacji na komputery osobiste, jak i na urządzenia mobilne, systemy wbudowane oraz serwery.

#### 1. **Podstawowe kompilowanie w G++**
Aby skompilować plik źródłowy w C++ za pomocą G++, wystarczy wywołać polecenie:
```bash
g++ nazwa_pliku.cpp -o nazwa_programu
```
- `nazwa_pliku.cpp` – Twój kod źródłowy.
- `-o nazwa_programu` – Opcjonalnie określa nazwę wyjściowego pliku wykonywalnego. Bez tego G++ wygeneruje plik o nazwie `a.out`.

#### 2. **Kompilowanie wielu plików**
Jeżeli masz więcej niż jeden plik źródłowy, możesz podać je wszystkie:
```bash
g++ plik1.cpp plik2.cpp -o program
```
G++ automatycznie połączy je w jeden program.

#### 3. **Dodawanie bibliotek**
- **Biblioteki standardowe** (np. `math.h`):
  Aby dołączyć bibliotekę standardową, użyj flagi `-l`:
  ```bash
  g++ program.cpp -o program -lm
  ```
  Flaga `-lm` dołącza bibliotekę matematyczną (libm).

- **Zewnętrzne biblioteki**:
  Jeśli używasz zewnętrznych bibliotek, musisz dodać ścieżki do nagłówków i plików obiektowych:
  - `-I` – Dodaje ścieżkę do katalogu nagłówków.
  - `-L` – Dodaje ścieżkę do katalogu bibliotek.
  - `-l` – Określa nazwę biblioteki.
  Przykład:
  ```bash
  g++ program.cpp -o program -I/sciezka_do_naglowkow -L/sciezka_do_bibliotek -lnazwa_biblioteki
  ```

#### 4. **Przydatne parametry**
- **-Wall** – Włącza wszystkie ostrzeżenia:
  ```bash
  g++ program.cpp -o program -Wall
  ```
  Pomaga w wykrywaniu potencjalnych błędów w kodzie.

- **-g** – Generuje dodatkowe informacje do debugowania (używane z `gdb`):
  ```bash
  g++ program.cpp -o program -g
  ```

- **-O, -O2, -O3** – Optymalizacja kodu:
  ```bash
  g++ program.cpp -o program -O2
  ```
  Ustawienie poziomu optymalizacji. Wyższy poziom (np. `-O3`) może poprawić wydajność kosztem dłuższego czasu kompilacji.

- **-std=c++17** – Ustawia standard C++:
  ```bash
  g++ program.cpp -o program -std=c++17
  ```
  Przydatne, gdy używasz nowszych funkcji C++.

- **-static** – Kompiluje program z linkowaniem statycznym:
  ```bash
  g++ program.cpp -o program -static
  ```
  Sprawia, że program nie wymaga dynamicznych bibliotek podczas uruchamiania.

- **-c** – Kompiluje pliki źródłowe do plików obiektowych:
  ```bash
  g++ -c plik1.cpp
  ```
  Używane w kompilacji wieloetapowej.

#### 5. **Kompilacja wieloetapowa**
W większych projektach często kompiluje się pliki do plików obiektowych `.o` i następnie je linkuje:
```bash
g++ -c plik1.cpp -o plik1.o
g++ -c plik2.cpp -o plik2.o
g++ plik1.o plik2.o -o program
```
Taka metoda skraca czas kompilacji przy zmianach w pojedynczych plikach.

#### 6. **Kompilacja wielowątkowa**
Dla przyspieszenia kompilacji można uruchomić ją na wielu rdzeniach procesora:
```bash
make -j4
```
`make` z flagą `-j` oznacza liczbę jednoczesnych procesów kompilacji.

---

Dzięki tym podstawowym komendom i parametrom możesz skutecznie używać g++ w praktyce i kompilować nawet bardziej zaawansowane projekty C++.
