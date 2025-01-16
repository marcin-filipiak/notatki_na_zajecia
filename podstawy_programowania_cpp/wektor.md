# Wektor w C++ 

**Wektor** w C++ to dynamiczna struktura danych dostępna w bibliotece standardowej (STL – Standard Template Library). Wektor jest podobny do tablicy, jednak ma jedną istotną zaletę – może dynamicznie zmieniać swój rozmiar w czasie działania programu, co sprawia, że jest bardziej elastyczny od statycznych tablic.

Wektor jest częścią przestrzeni nazw `std` i znajduje się w nagłówku `<vector>`.

#### Cechy wektora:
1. **Dynamiczne zarządzanie pamięcią** – wektor automatycznie zarządza pamięcią, rozszerzając się, gdy jest potrzeba dodania nowych elementów.
2. **Indeksowanie** – do elementów wektora można uzyskać dostęp tak samo jak do tablicy, używając indeksu.
3. **Wielkość i pojemność** – wektor ma dwie właściwości związane z rozmiarem: rozmiar (`size`) oznacza liczbę elementów w wektorze, a pojemność (`capacity`) to ilość miejsca zarezerwowanego na dodatkowe elementy bez konieczności realokacji pamięci.
4. **Łatwość dodawania i usuwania elementów** – wektor umożliwia łatwe dodawanie elementów na końcu oraz usuwanie elementów za pomocą funkcji takich jak `push_back()` i `pop_back()`.

#### Przykład użycia wektora

```cpp
#include <iostream>
#include <vector>

int main() {
    // Tworzenie wektora liczb całkowitych
    std::vector<int> liczby;

    // Dodawanie elementów do wektora
    liczby.push_back(10);
    liczby.push_back(20);
    liczby.push_back(30);

    // Wyświetlanie elementów wektora
    std::cout << "Elementy wektora: ";
    for (int i = 0; i < liczby.size(); ++i) {
        std::cout << liczby[i] << " ";
    }

    // Usunięcie ostatniego elementu
    liczby.pop_back();

    // Wyświetlanie elementów po usunięciu
    std::cout << "\nPo usunięciu ostatniego elementu: ";
    for (int liczba : liczby) {
        std::cout << liczba << " ";
    }

    return 0;
}
```

**Wynik:**
```
Elementy wektora: 10 20 30 
Po usunięciu ostatniego elementu: 10 20 
```

#### Podstawowe operacje na wektorach:
1. **Dodawanie elementu** – za pomocą metody `push_back()` można dodać element na końcu wektora.
2. **Usuwanie elementu** – metoda `pop_back()` usuwa ostatni element.
3. **Rozmiar wektora** – metoda `size()` zwraca aktualny rozmiar wektora (liczbę elementów).
4. **Dostęp do elementów** – można uzyskać dostęp do elementu wektora za pomocą operatora `[]` lub metody `at()`, która sprawdza poprawność indeksu.
5. **Iteracja po elementach** – można korzystać z pętli `for` lub iteratorów, aby przechodzić przez wszystkie elementy wektora.

#### Realne zastosowania wektora:
- **Przechowywanie dynamicznych danych** – wektor jest często używany, gdy nie znamy z góry liczby elementów, które będą przechowywane (np. listy wyników, dane od użytkownika).
- **Sortowanie danych** – wektor łatwo integruje się z funkcjami sortującymi z biblioteki STL, takimi jak `std::sort()`.
- **Tablice wielowymiarowe** – wektory mogą być używane do tworzenia dynamicznych tablic wielowymiarowych (np. wektor wektorów).
- **Bufory danych** – w aplikacjach wymagających dynamicznego zarządzania buforami (np. w programach sieciowych) wektory mogą służyć do przechowywania i manipulowania danymi.

#### Przykład: Wektor wektorów (macierz 2D)

```cpp
#include <iostream>
#include <vector>

int main() {
    // Tworzenie macierzy 2D za pomocą wektora wektorów
    std::vector<std::vector<int>> macierz(3, std::vector<int>(3, 0));

    // Wypełnianie macierzy wartościami
    macierz[0][0] = 1; macierz[0][1] = 2; macierz[0][2] = 3;
    macierz[1][0] = 4; macierz[1][1] = 5; macierz[1][2] = 6;
    macierz[2][0] = 7; macierz[2][1] = 8; macierz[2][2] = 9;

    // Wyświetlanie macierzy
    for (int i = 0; i < macierz.size(); ++i) {
        for (int j = 0; j < macierz[i].size(); ++j) {
            std::cout << macierz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

**Wynik:**
```
1 2 3 
4 5 6 
7 8 9 
```
