# Doxygen – narzędzie do dokumentacji kodu

Doxygen to narzędzie do generowania dokumentacji kodu źródłowego. Obsługuje wiele języków programowania, takich jak C, C++, Java, Python, Fortran i inne. Pozwala na tworzenie czytelnych dokumentacji w różnych formatach, m.in. HTML, LaTeX czy XML, na podstawie specjalnie sformatowanych komentarzy w kodzie.

### **Jak używać Doxygen?**
1. **Instalacja** – w systemie Debian można zainstalować Doxygen poleceniem:
   ```sh
   sudo apt update && sudo apt install doxygen doxygen-doc graphviz
   ```
2. **Konfiguracja** – uruchomienie `doxygen -g` wygeneruje plik `Doxyfile`, który można edytować, dostosowując ustawienia.
3. **Dodanie komentarzy do kodu** – stosowanie specjalnych znaczników w komentarzach.
4. **Generowanie dokumentacji** – uruchomienie `doxygen Doxyfile` wygeneruje dokumentację w wybranym formacie.

### **Przykłady komentarzy Doxygen**

Doxygen **nie tworzy automatycznie komentarzy w kodzie**, ale przetwarza komentarze dodane przez programistę i na ich podstawie generuje dokumentację.

#### **Komentarz dla funkcji:**
```cpp
/**
 * @brief Funkcja oblicza sumę dwóch liczb.
 * @param a Pierwsza liczba.
 * @param b Druga liczba.
 * @return Suma liczb a i b.
 */
int sum(int a, int b) {
    return a + b;
}
```

#### **Komentarz dla klasy:**
```cpp
/**
 * @class Rectangle
 * @brief Klasa reprezentująca prostokąt.
 * @author Jan Kowalski
 */
class Rectangle {
public:
    /**
     * @brief Konstruktor ustawiający szerokość i wysokość.
     * @param w Szerokość prostokąta.
     * @param h Wysokość prostokąta.
     */
    Rectangle(int w, int h);
};
```

### **Generowanie dokumentacji HTML**
1. Tworzymy plik konfiguracyjny:
   ```sh
   doxygen -g
   ```
   To wygeneruje plik `Doxyfile`, który można edytować.
   
2. Uruchamiamy Doxygen:
   ```sh
   doxygen Doxyfile
   ```
   Jeśli w `Doxyfile` mamy ustawione `GENERATE_HTML = YES`, dokumentacja HTML zostanie wygenerowana w katalogu `html/`.

3. Otwieramy plik `html/index.html` w przeglądarce, aby zobaczyć dokumentację.

### **Obsługiwane IDE**
Doxygen można zintegrować z wieloma środowiskami programistycznymi, takimi jak:
- **Visual Studio** (poprzez rozszerzenia lub ręcznie w terminalu)
- **Eclipse** (za pomocą wtyczki Eclox)
- **Qt Creator** (konfiguracja narzędzia zewnętrznego)
- **CLion** (przez konfigurację własnych skryptów)
- **Code::Blocks** (możliwość użycia jako narzędzie do dokumentacji)

### **Popularne komendy Doxygen (@-tags)**
Doxygen obsługuje wiele znaczników ułatwiających dokumentowanie kodu:

- `@brief` – krótki opis funkcji/klasy.
- `@param` – opis parametrów funkcji.
- `@return` – opis zwracanego wyniku funkcji.
- `@author` – informacja o autorze kodu.
- `@version` – wersja kodu.
- `@date` – data stworzenia pliku.
- `@warning` – ostrzeżenie dotyczące kodu.
- `@note` – dodatkowa uwaga.
- `@see` – odniesienie do innej funkcji/klasy.
- `@todo` – oznaczenie miejsc wymagających dalszej pracy.


----

### Przykładowy kod z tagami Doxygen

```cpp
/**
 * @file example.cpp
 * @brief Przykładowy kod dokumentowany za pomocą Doxygen.
 * @author Jan Kowalski
 * @version 1.0
 * @date 2024-02-03
 * 
 * @note Ten plik zawiera przykładową implementację klasy i funkcji.
 * @warning To tylko przykład, kod nie jest przeznaczony do produkcji.
 * @todo Dodać obsługę wyjątków.
 */

#include <iostream>

/**
 * @class Rectangle
 * @brief Klasa reprezentująca prostokąt.
 */
class Rectangle {
private:
    int width;  ///< Szerokość prostokąta
    int height; ///< Wysokość prostokąta

public:
    /**
     * @brief Konstruktor ustawiający szerokość i wysokość.
     * @param w Szerokość prostokąta.
     * @param h Wysokość prostokąta.
     */
    Rectangle(int w, int h);

    /**
     * @brief Oblicza pole powierzchni prostokąta.
     * @return Pole powierzchni prostokąta.
     */
    int area() const;

    /**
     * @brief Wypisuje szczegóły prostokąta.
     */
    void print() const;
};

Rectangle::Rectangle(int w, int h) : width(w), height(h) {}

int Rectangle::area() const {
    return width * height;
}

void Rectangle::print() const {
    std::cout << "Rectangle: " << width << " x " << height << ", Area: " << area() << std::endl;
}

/**
 * @brief Funkcja główna programu.
 * @return Zwraca 0 w przypadku sukcesu.
 */
int main() {
    Rectangle rect(10, 5);
    rect.print();
    return 0;
}

```

