# Notatka: Czasowa złożoność obliczeniowa algorytmów

## 1. Co to jest złożoność obliczeniowa?

Złożoność obliczeniowa algorytmu to miara ilości zasobów, jakie algorytm potrzebuje do rozwiązania problemu w zależności od wielkości danych wejściowych. Zasoby te to:
- **Czas** (czas działania algorytmu)
- **Pamięć** (ilość pamięci potrzebnej do przechowywania danych)

Złożoność obliczeniową można podzielić na:
- **Złożoność czasową** (time complexity): ile operacji wykonuje algorytm w zależności od wielkości danych wejściowych.
- **Złożoność pamięciową** (space complexity): ile pamięci potrzebuje algorytm do działania.

## 2. Czasowa złożoność obliczeniowa

### 2.1. Jak ocenia się złożoność obliczeniową czasową?

Złożoność algorytmu wyrażana jest zazwyczaj za pomocą notacji **O-wielkie** (ang. Big-O), która opisuje najgorszy możliwy scenariusz (worst-case). Mówi nam, jak szybko rośnie liczba operacji w algorytmie, gdy rośnie liczba danych wejściowych \(n\).

#### Przykłady złożoności czasowej:
- **O(1)** – złożoność stała: algorytm wykonuje zawsze tę samą liczbę operacji, niezależnie od wielkości danych. Przykład: dostęp do elementu tablicy.
- **O(log n)** – złożoność logarytmiczna: liczba operacji rośnie powoli wraz z wielkością danych wejściowych. Przykład: wyszukiwanie binarne.
- **O(n)** – złożoność liniowa: liczba operacji rośnie proporcjonalnie do wielkości danych. Przykład: liniowe przeszukiwanie tablicy.
- **O(n log n)** – złożoność liniowo-logarytmiczna: Przykład: algorytmy sortowania takie jak mergesort czy quicksort.
- **O(n²)** – złożoność kwadratowa: liczba operacji rośnie jak kwadrat wielkości danych. Przykład: sortowanie bąbelkowe.
- **O(2^n)** – złożoność wykładnicza: liczba operacji rośnie bardzo szybko, np. w algorytmach z przeszukiwaniem wyczerpującym (brute force).
  
### 2.2. Jak oblicza się złożoność obliczeniową?

Aby oszacować złożoność czasową algorytmu, wykonujemy następujące kroki:
1. **Zidentyfikowanie najczęściej powtarzającej się operacji**: Skupiamy się na operacji, która ma największy wpływ na czas działania algorytmu.
2. **Policzenie liczby operacji**: Sprawdzamy, jak często dana operacja będzie wykonywana w zależności od danych wejściowych \(n\).
3. **Wyrażenie wyniku w notacji O-wielkie**: Na koniec upraszczamy wyrażenie i odrzucamy wszystkie stałe oraz mniej istotne czynniki, zostawiając główny człon.

#### Przykład:
Rozważmy pętlę, która wykonuje się \(n\) razy:
```cpp
for(int i = 0; i < n; i++) {
    // operacja
}
```
W tym przypadku liczba operacji to \(n\), więc złożoność czasowa algorytmu wynosi **O(n)**.

### 2.3. Dlaczego złożoność obliczeniowa jest ważna?

Zrozumienie złożoności obliczeniowej jest kluczowe, ponieważ pozwala ocenić, czy dany algorytm będzie efektywny dla dużych zestawów danych. Algorytmy o mniejszej złożoności są szybsze i mniej wymagające w użyciu, co ma znaczenie w praktycznych aplikacjach, takich jak przetwarzanie dużych zbiorów danych czy analiza w czasie rzeczywistym.

### 2.4. Przykłady poziomów złożoności czasowej algorytmów

Oto przykłady kodu w C++ dla poszczególnych poziomów złożoności czasowej algorytmów:

### 2.4.1. **Złożoność stała: O(1)**
Algorytm wykonuje zawsze tę samą liczbę operacji, niezależnie od rozmiaru danych wejściowych.

Przykład: dostęp do elementu tablicy
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int index = 2;
    cout << "Element at index 2: " << arr[index] << endl; // O(1)
    return 0;
}
```

###  2.4.2. **Złożoność logarytmiczna: O(log n)**
Liczba operacji rośnie logarytmicznie w zależności od danych wejściowych.

Przykład: wyszukiwanie binarne w posortowanej tablicy
```cpp
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;   // O(log n)
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    int target = 40;
    int result = binarySearch(arr, target);
    cout << "Index of target: " << result << endl;
    return 0;
}
```

###  2.4.3. **Złożoność liniowa: O(n)**
Liczba operacji rośnie liniowo wraz z rozmiarem danych wejściowych.

Przykład: liniowe przeszukiwanie tablicy
```cpp
#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;   // O(n)
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 30;
    int result = linearSearch(arr, target);
    cout << "Index of target: " << result << endl;
    return 0;
}
```

###  2.4.4. **Złożoność liniowo-logarytmiczna: O(n log n)**
Liczba operacji rośnie w tempie \(n \log n\). Taki czas osiągają optymalne algorytmy sortujące.

Przykład: sortowanie przy użyciu `std::sort` (które implementuje introsort, mające złożoność O(n log n))
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {50, 20, 40, 10, 30};
    sort(arr.begin(), arr.end());   // O(n log n)
    cout << "Sorted array: ";
    for (int i : arr) cout << i << " ";
    cout << endl;
    return 0;
}
```

###  2.4.5. **Złożoność kwadratowa: O(n²)**
Liczba operacji rośnie jak kwadrat rozmiaru danych wejściowych.

Przykład: sortowanie bąbelkowe (bubble sort)
```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);   // O(n²)
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
```

###  2.4.6. **Złożoność wykładnicza: O(2ⁿ)**
Liczba operacji rośnie bardzo szybko, wykładniczo wraz z wielkością danych wejściowych.

Przykład: rozwiązanie problemu n-tych liczb Fibonacciego metodą rekurencyjną
```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);   // O(2^n)
}

int main() {
    int n = 5;
    cout << "Fibonacci of " << n << ": " << fibonacci(n) << endl;
    return 0;
}
```

###  2.4.7. **Złożoność silni: O(n!)**
Liczba operacji rośnie jak silnia \(n!\), np. dla problemów permutacji.

Przykład: generowanie permutacji zbioru
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printPermutations(vector<int> arr, int l, int r) {
    if (l == r) {
        for (int i : arr) cout << i << " ";
        cout << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(arr[l], arr[i]);
            printPermutations(arr, l + 1, r);   // O(n!)
            swap(arr[l], arr[i]); // backtrack
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    printPermutations(arr, 0, arr.size() - 1);
    return 0;
}
```

###  2.4.8. **Złożoność obliczeniowa O(m \* n)**

Złożoność **O(m \* n)** oznacza, że algorytm wykonuje liczbę operacji proporcjonalną do iloczynu dwóch parametrów, czyli \(m\) i \(n\). Najczęściej spotyka się to w algorytmach, które muszą przetwarzać dwie niezależne struktury danych lub iterować po macierzy (tablicy dwuwymiarowej), gdzie \(m\) to liczba wierszy, a \(n\) to liczba kolumn.

Przykłady zastosowań:
- Przetwarzanie macierzy (tablica 2D)
- Algorytmy wyszukiwania w wielu strukturach
- Algorytmy porównujące dwa różne zbiory danych (np. dynamiczne programowanie)

Załóżmy, że mamy macierz o wymiarach \(m \times n\) (m wierszy i n kolumn) i chcemy przetworzyć wszystkie jej elementy.

```cpp
#include <iostream>
using namespace std;

int main() {
    int m = 3, n = 4;
    int matrix[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };

    // Iteracja przez każdy element macierzy
    for (int i = 0; i < m; i++) {          // pętla po wierszach
        for (int j = 0; j < n; j++) {      // pętla po kolumnach
            cout << matrix[i][j] << " ";   // O(m * n)
        }
        cout << endl;
    }
    return 0;
}
```

W powyższym przykładzie, mamy macierz o wymiarach \(m na n\). Każdy wiersz zawiera \(n\) elementów, a wierszy jest \(m\), więc liczba operacji to \(m razy n\). Złożoność czasowa algorytmu wynosi **O(m \* n)**, ponieważ każda iteracja przez komórki macierzy wymaga wykonania \(m razy n\) operacji.


### 3. Pamięciowa złożoność obliczeniowa

Złożoność pamięciowa algorytmu odnosi się do ilości pamięci, jaką algorytm potrzebuje do działania, w zależności od wielkości danych wejściowych. Podobnie jak w przypadku złożoności czasowej, złożoność pamięciowa jest zazwyczaj wyrażana w notacji **O-wielkie**.

#### 3.1. Co to jest złożoność pamięciowa?

Złożoność pamięciowa algorytmu obejmuje wszelkie zasoby pamięciowe potrzebne do przechowywania danych, takich jak:
- Zmienne lokalne (np. w funkcjach)
- Struktury danych (np. tablice, listy, mapy)
- Pamięć rekurencyjna (stos wywołań)

Złożoność pamięciowa może być podzielona na:
- **Złożoność stałą** (O(1)): algorytm wykorzystuje stałą ilość pamięci niezależnie od danych wejściowych.
- **Złożoność liniową** (O(n)): ilość pamięci rośnie liniowo w zależności od rozmiaru danych wejściowych.
- **Złożoność kwadratową** (O(n²)): ilość pamięci rośnie proporcjonalnie do kwadratu rozmiaru danych wejściowych.

#### 3.2. Jak ocenia się złożoność obliczeniową pamięciową?

Aby oszacować złożoność pamięciową algorytmu, wykonujemy następujące kroki:
1. **Zidentyfikowanie używanych struktur danych**: Sprawdzamy, jakie dane są przechowywane i jakie struktury danych są wykorzystywane.
2. **Określenie rozmiaru tych struktur**: Zliczamy, ile pamięci każda struktura zajmuje w zależności od danych wejściowych \(n\).
3. **Wyrażenie wyniku w notacji O-wielkie**: Na koniec upraszczamy wyrażenie, odrzucając stałe i mniej istotne czynniki, zostawiając główny człon.

#### Przykład:

Rozważmy funkcję, która tworzy dynamicznie tablicę o rozmiarze \(n\):

```cpp
#include <iostream>
using namespace std;

void createArray(int n) {
    int* arr = new int[n]; // Przydzielenie pamięci O(n)
    // operacje na arr...
    delete[] arr; // Zwolnienie pamięci
}

int main() {
    int n = 5;
    createArray(n);
    return 0;
}
```

W tym przypadku, złożoność pamięciowa wynosi **O(n)**, ponieważ przydzielamy pamięć dla tablicy o rozmiarze \(n\).

#### 3.3. Dlaczego złożoność pamięciowa jest ważna?

Zrozumienie złożoności pamięciowej jest kluczowe, ponieważ pozwala ocenić, jak efektywnie algorytm będzie działał w kontekście dostępnych zasobów pamięci. Algorytmy o mniejszej złożoności pamięciowej są bardziej wydajne w użyciu, co ma znaczenie szczególnie w środowiskach z ograniczoną pamięcią, takich jak systemy wbudowane czy aplikacje mobilne.

### 3.4. Przykłady poziomów złożoności pamięciowej algorytmów

#### 3.4.1. **Złożoność stała: O(1)**
Algorytm wykorzystuje stałą ilość pamięci, niezależnie od rozmiaru danych wejściowych.

Przykład: prosta funkcja, która zwraca wartość:

```cpp
#include <iostream>
using namespace std;

int getValue() {
    int value = 5; // O(1)
    return value;
}

int main() {
    cout << "Value: " << getValue() << endl;
    return 0;
}
```

#### 3.4.2. **Złożoność liniowa: O(n)**
Algorytm wykorzystuje pamięć proporcjonalną do rozmiaru danych wejściowych.

Przykład: funkcja tworząca tablicę:

```cpp
#include <iostream>
using namespace std;

void createArray(int n) {
    int* arr = new int[n]; // O(n)
    // operacje na arr...
    delete[] arr; // Zwolnienie pamięci
}

int main() {
    int n = 10;
    createArray(n);
    return 0;
}
```

#### 3.4.3. **Złożoność kwadratowa: O(n²)**
Algorytm wykorzystuje pamięć proporcjonalną do kwadratu rozmiaru danych wejściowych.

Przykład: funkcja tworząca macierz \(n \times n\):

```cpp
#include <iostream>
using namespace std;

void createMatrix(int n) {
    int** matrix = new int*[n]; // O(n)
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n]; // O(n) dla każdej kolumny
    }
    // operacje na matrix...
    for (int i = 0; i < n; i++) {
        delete[] matrix[i]; // Zwolnienie pamięci
    }
    delete[] matrix; // Zwolnienie pamięci
}

int main() {
    int n = 5;
    createMatrix(n);
    return 0;
}
```
