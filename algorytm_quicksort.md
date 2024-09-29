Algorytm QuickSort to jeden z najpopularniejszych i najefektywniejszych algorytmów sortowania. Opiera się na technice **dziel i zwyciężaj** (ang. *divide and conquer*). Główna idea QuickSortu to wybór elementu, zwanego **pivotem**, oraz podzielenie tablicy na dwie części – jedna część zawiera elementy mniejsze od pivota, a druga część elementy większe. Następnie algorytm rekurencyjnie sortuje obie te części.

### Kroki algorytmu QuickSort:
1. Wybierz element pivot (np. ostatni element).
2. Podziel tablicę na dwie części: 
   - Jedna część z elementami mniejszymi od pivota.
   - Druga z elementami większymi od pivota.
3. Rekurencyjnie wywołaj QuickSort dla obu części.
4. Gdy każda część zostanie posortowana, tablica jest już posortowana.

Oto przykład implementacji algorytmu QuickSort w C++:

```cpp
#include <iostream>
using namespace std;

// Funkcja pomocnicza do zamiany dwóch elementów
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funkcja do podziału tablicy na dwie części
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Wybieramy pivot (ostatni element)
    int i = (low - 1);     // Indeks mniejszego elementu

    // Przechodzimy przez tablicę i zamieniamy elementy mniejsze od pivota
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; // Zwiększamy indeks mniejszego elementu
            swap(&arr[i], &arr[j]); // Zamieniamy miejscami
        }
    }
    // Umieszczamy pivot na właściwym miejscu
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Funkcja implementująca QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Uzyskujemy indeks podziału, pivot jest na właściwym miejscu
        int pi = partition(arr, low, high);

        // Rekurencyjnie sortujemy elementy przed i za pivotem
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Wywołanie funkcji QuickSort
    quickSort(arr, 0, n - 1);

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
1. **Funkcja `partition()`** wybiera pivot i przemieszcza elementy mniejsze od pivota na jego lewą stronę, a większe na prawą. Na końcu umieszcza pivot na właściwej pozycji.
2. **Funkcja `quickSort()`** dzieli tablicę na dwie części w oparciu o pivot i rekurencyjnie sortuje obie te części.
3. Proces sortowania kończy się, gdy każda z części tablicy jest posortowana.

### Zalety QuickSort:
- W praktyce szybki, jego złożoność czasowa to **O(n log n)** dla większości przypadków.
- Działa w miejscu, więc nie wymaga dodatkowej pamięci (oprócz stosu rekurencyjnego).

### Wady:
- W najgorszym przypadku (gdy zawsze wybierany jest najgorszy pivot) ma złożoność **O(n²)**, ale takie przypadki są rzadkie i można je minimalizować, np. poprzez losowy wybór pivota.
