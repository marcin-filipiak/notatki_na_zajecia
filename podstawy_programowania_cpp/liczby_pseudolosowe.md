### Losowanie liczb w C++  

W C++ możemy losować liczby za pomocą funkcji z biblioteki `<cstdlib>` oraz `<ctime>`. Aby uzyskać różne liczby losowe przy każdym uruchomieniu programu, konieczne jest zainicjowanie generatora losowego za pomocą bieżącego czasu, korzystając z funkcji `time()` z biblioteki `<ctime>`.

---

#### **Kluczowe funkcje:**
1. **`srand(seed)`**  
   - Ustawia *ziarno* (ang. seed) dla generatora liczb pseudolosowych.  
   - Jeśli ziarno jest takie samo, sekwencja liczb losowych również będzie taka sama.  
   - Zazwyczaj używamy czasu systemowego jako ziarna, np. `srand(time(0))`.

2. **`rand()`**  
   - Generuje liczbę pseudolosową z zakresu od `0` do stałej `RAND_MAX`.  
   - Aby ograniczyć wynik do określonego zakresu, stosujemy operację modulo (`%`).

---

#### **Przykład kodu:**
```cpp
#include <iostream> // Do wejścia i wyjścia
#include <cstdlib>  // Do rand() i srand()
#include <ctime>    // Do time()

int main() {
    // Inicjalizacja generatora losowego za pomocą bieżącego czasu
    srand(time(0)); // time(0) zwraca czas w sekundach od 1 stycznia 1970 roku

    // Losowanie liczb w określonym zakresie
    int liczba1 = rand() % 10 + 1; // Losuje liczbę z zakresu [1, 10]
    int liczba2 = rand() % 100 + 50; // Losuje liczbę z zakresu [50, 149]

    // Wyświetlenie wyników
    std::cout << "Losowa liczba z zakresu [1, 10]: " << liczba1 << std::endl;
    std::cout << "Losowa liczba z zakresu [50, 149]: " << liczba2 << std::endl;

    return 0;
}
```

---

#### **Wyjaśnienia do kodu:**

1. **Biblioteki**  
   - `<cstdlib>`: Funkcje `rand()` i `srand()` znajdują się w tej bibliotece.  
   - `<ctime>`: Funkcja `time()` dostarcza czas systemowy.

2. **`srand(time(0))`**  
   - `time(0)` zwraca liczbę sekund od tzw. EPOKI UNIX-a (1 stycznia 1970 roku).  
   - Użycie `srand(time(0))` zapewnia różne ziarno przy każdym uruchomieniu programu, co prowadzi do generowania różnych liczb losowych.

3. **`rand() % zakres`**  
   - Operacja modulo (`%`) ogranicza wynik `rand()` do wartości od `0` do `zakres - 1`.  
   - Dodanie wartości początkowej (np. `+ 1`) zmienia zakres.  
     - Przykład: `rand() % 10 + 1` losuje liczby od `1` do `10`.

4. **Komentarze w kodzie**  
   - Komentarze wyjaśniają, co robi każdy fragment kodu, co pomaga zrozumieć jego działanie.

---

#### **Uwagi:**
- Funkcja `rand()` generuje liczby pseudolosowe, co oznacza, że wynik zależy od ziarna, a nie jest całkowicie losowy.
- W przypadku bardziej zaawansowanych aplikacji, takich jak symulacje lub gry, warto rozważyć użycie generatora liczb losowych z biblioteki `<random>` (dostępnej w C++11 i nowszych).

---

#### **Zadanie dla ucznia:**
1. Napisz program, który losuje trzy liczby całkowite z zakresu od `-100` do `100` i wyświetla je na ekranie.
2. Spróbuj zmienić wartość ziarna w funkcji `srand()`, aby zobaczyć, jak wpływa to na wyniki.
