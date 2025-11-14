### Notatka: Obsługa plików w C++

#### Co jest potrzebne?

Do pracy z plikami w C++ używamy biblioteki `<fstream>`, która udostępnia trzy klasy:

* **ifstream** – do odczytu z pliku
* **ofstream** – do zapisu do pliku
* **fstream** – do odczytu i zapisu

Aby korzystać z plików, dołączasz:

```cpp
#include <fstream>
```

---

### Otwieranie plików

Plik można otworzyć na dwa sposoby:

1. **Przy tworzeniu obiektu**

   ```cpp
   ifstream plik("dane.txt");
   ```
2. **Później**

   ```cpp
   ifstream plik;
   plik.open("dane.txt");
   ```

Zawsze warto sprawdzić, czy plik się otworzył:

```cpp
if (!plik.is_open()) {
    cout << "Nie udalo sie otworzyc pliku\n";
}
```

---

### Zapis do pliku

Do zapisu używasz klasy **ofstream**:

```cpp
#include <fstream>
using namespace std;

int main() {
    ofstream plik("wynik.txt");

    if (!plik.is_open()) {
        cout << "Blad otwierania pliku\n";
        return 1;
    }

    plik << "Pierwsza linia\n";
    plik << "Druga linia\n";
    plik << 123 << endl;

    plik.close();
    return 0;
}
```

---

### Odczyt linia po linii

Najczęściej używa się `getline()`:

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream plik("dane.txt");

    if (!plik.is_open()) {
        cout << "Blad otwierania pliku\n";
        return 1;
    }

    string linia;

    while (getline(plik, linia)) {
        cout << linia << endl;
    }

    plik.close();
    return 0;
}
```

`getline()` pobiera całą linię aż do znaku końca linii.

---

### Odczyt element po elemencie (np. liczby, słowa)

Możesz czytać tak jak z `cin`:

```cpp
int liczba;
plik >> liczba;

string slowo;
plik >> slowo;
```

Odczyt kończy się, gdy:

* dane nie mają już odpowiedniego formatu,
* plik się skończy.

---

### Odczyt całego pliku naraz

Czasem potrzebujesz wczytać wszystko jako jeden string:

```cpp
#include <sstream>

ifstream plik("tekst.txt");
stringstream bufor;
bufor << plik.rdbuf();
string calosc = bufor.str();
```

---

### Zapis dopisujący do istniejącego pliku

Otwierasz plik z flagą `ios::app`:

```cpp
ofstream plik("log.txt", ios::app);
plik << "Nowy wpis\n";
```

`ios::app` oznacza dopisywanie na końcu.

---

### Odczyt i zapis w tym samym pliku (fstream)

```cpp
fstream plik("dane.txt", ios::in | ios::out);
```

Możesz wtedy używać `<<` i `>>` tak jak w ofstream/ifstream.

---

### Flagi otwarcia pliku

Najważniejsze:

* `ios::in` – otwórz do odczytu
* `ios::out` – otwórz do zapisu
* `ios::app` – dopisuj na końcu
* `ios::trunc` – wyczyść plik przy otwarciu
* `ios::binary` – tryb binarny (np. do zdjęć)

Przykład użycia kilku:

```cpp
ofstream plik("dane.txt", ios::out | ios::app);
```

---

### Sprawdzanie końca pliku

Najczęściej nie trzeba tego robić samodzielnie, bo pętle oparte na `getline` lub `>>` zatrzymują się same.

Jeśli potrzebujesz:

```cpp
while (!plik.eof()) { }
```

Ta konstrukcja bywa myląca, dlatego stosuj ją z ostrożnością.

---

### Zamknięcie pliku

Możesz zamknąć ręcznie:

```cpp
plik.close();
```

Plik zamknie się też automatycznie, gdy obiekt wyjdzie poza zakres.

---

### Przykład: kopiowanie pliku linia po linii

```cpp
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream wej("a.txt");
    ofstream wyj("b.txt");

    string linia;

    while (getline(wej, linia)) {
        wyj << linia << "\n";
    }

    return 0;
}
```
