### Operator reszty z dzielenia (`%`)

---

#### **Co to jest operator `%`?**
Operator `%` w języku C++ służy do obliczania **reszty z dzielenia** dwóch liczb całkowitych.  
- Jest to operator arytmetyczny, który pozwala sprawdzić, ile „zostanie” po wykonaniu dzielenia.

#### **Jak działa `%`?**
Gdy dzielimy jedną liczbę całkowitą przez drugą, operator `%` zwraca **resztę** z tej operacji, a nie wynik dzielenia.  
Na przykład:  
- `7 / 3` = `2` (wynik dzielenia to 2)  
- `7 % 3` = `1` (reszta z dzielenia to 1, bo \( 7 = 3 \times 2 + 1 \))  

---

#### **Składnia**
```cpp
reszta = a % b;
```
- **`a`**: Liczba, którą dzielimy.  
- **`b`**: Liczba, przez którą dzielimy.  
- **`reszta`**: Wynik działania `%`.

---

#### **Przykład programu**
```cpp
#include <iostream>

int main() {
    int a = 10;
    int b = 4;

    // Obliczanie reszty z dzielenia
    int reszta = a % b;

    // Wyświetlanie wyniku
    std::cout << "Reszta z dzielenia " << a << " przez " << b << " wynosi: " << reszta << std::endl;

    return 0;
}
```

---

#### **Przykład wyjaśnienia**
Dla powyższego programu:
- \( 10 \div 4 \) = 2 (wynik dzielenia całkowitego).  
- \( 10 - (4 \times 2) = 2 \).  
- Reszta wynosi 2.

Wynik:  
```
Reszta z dzielenia 10 przez 4 wynosi: 2
```

---

#### **Kiedy używamy `%`?**
1. **Sprawdzanie podzielności liczby:**  
   Jeśli reszta z dzielenia liczby przez inną wynosi 0, to pierwsza liczba jest podzielna przez drugą.  
   Przykład:  
   ```cpp
   if (a % 2 == 0) {
       std::cout << a << " jest liczbą parzystą." << std::endl;
   } else {
       std::cout << a << " jest liczbą nieparzystą." << std::endl;
   }
   ```

2. **Powtarzalne cykle w programach:**  
   Operator `%` jest przydatny do ograniczenia wartości w określonym zakresie, np. liczenie godzin na zegarze (modulo 12 lub 24).

3. **Zastosowanie w grach:**  
   Na przykład, aby określić pozycję na planszy o określonym rozmiarze.

---

#### **Ważne uwagi**
1. **Działa tylko na liczbach całkowitych:**  
   Operator `%` nie działa dla liczb zmiennoprzecinkowych (np. `float`, `double`).  

   Dla zmiennoprzecinkowych można użyć funkcji w bibliotece matematycznej:  
   ```cpp
   #include <cmath>
   double reszta = fmod(7.5, 2.5); // fmod - reszta z dzielenia zmiennoprzecinkowego
   ```

2. **Znak reszty:**  
   Reszta ma taki sam znak jak pierwsza liczba (dzielna).  
   Przykłady:  
   - \( 7 \% 3 = 1 \)  
   - \( -7 \% 3 = -1 \)

---

Operator `%` to narzędzie, które często używamy w programowaniu do analizy i manipulacji liczb. Opanowanie go to ważny krok w nauce C++.
