Sortowanie bąbelkowe (ang. *bubble sort*) to prosty algorytm, który działa poprzez wielokrotne porównywanie sąsiednich elementów w tablicy i zamianę ich miejscami, jeśli są w niewłaściwej kolejności. Proces ten powtarza się, aż cała tablica będzie posortowana.

Oto prosty przykład sortowania bąbelkowego w C++:

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    // Pętla zewnętrzna, która kontroluje liczbę przejść
    for (int i = 0; i < n - 1; i++) {
        // Pętla wewnętrzna, która porównuje sąsiednie elementy
        for (int j = 0; j < n - i - 1; j++) {
            // Jeśli elementy są w złej kolejności, zamieniamy je miejscami
            if (arr[j] > arr[j + 1]) {
                // Zamiana elementów
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Wywołanie funkcji sortowania bąbelkowego
    bubbleSort(arr, n);

    // Wyświetlenie posortowanej tablicy
    cout << "Posortowana tablica: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
```

### Jak działa ten kod:
1. Mamy tablicę `arr[]`, którą chcemy posortować.
2. Funkcja `bubbleSort()` przyjmuje tę tablicę i jej rozmiar `n`.
3. Pętla zewnętrzna wykonuje n-1 przejść, aby posortować tablicę.
4. Pętla wewnętrzna porównuje sąsiednie elementy i zamienia je, jeśli pierwszy element jest większy od drugiego.
5. Po każdym przejściu największy element "wypływa" na swoje właściwe miejsce, jak bąbelki w wodzie, stąd nazwa algorytmu.

Rezultatem działania programu jest posortowana tablica.
