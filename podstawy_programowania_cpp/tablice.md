### Notatka: Tablice w C++

#### Co to jest tablica?

Tablica to struktura danych, która pozwala na przechowywanie wielu wartości tego samego typu w jednym miejscu w pamięci. Każda wartość w tablicy jest identyfikowana za pomocą indeksu.

#### Deklaracja tablicy

Tablicę deklaruje się, podając typ danych, nazwę tablicy oraz jej rozmiar w nawiasach kwadratowych `[]`.

```cpp
typ nazwa_tablicy[rozmiar];
```

#### Przykład deklaracji i inicjalizacji tablicy

1. **Bez wartości początkowych** (wartości domyślne są nieokreślone):
   ```cpp
   int liczby[5]; // Tablica na 5 elementów typu int
   ```

2. **Z wartościami początkowymi**:
   ```cpp
   int liczby[5] = {1, 2, 3, 4, 5}; // Tablica na 5 elementów z inicjalizacją
   ```

3. **Rozmiar określany automatycznie**:
   ```cpp
   int liczby[] = {10, 20, 30}; // Rozmiar wynosi 3 (tyle, ile elementów w nawiasach)
   ```

#### Indeksowanie tablicy

Elementy tablicy są numerowane od 0. Aby uzyskać dostęp do konkretnego elementu, używamy indeksu w nawiasach kwadratowych.

```cpp
int liczby[3] = {10, 20, 30};
cout << liczby[0]; // Wyświetla 10
cout << liczby[2]; // Wyświetla 30
```

#### Modyfikacja elementów tablicy

Możesz zmieniać wartości elementów tablicy za pomocą indeksu.

```cpp
int liczby[3] = {10, 20, 30};
liczby[1] = 25; // Zmiana drugiego elementu
cout << liczby[1]; // Wyświetla 25
```

#### Iteracja po tablicy

Najczęściej używamy pętli **for**, aby przejść przez wszystkie elementy tablicy.

```cpp
#include <iostream>
using namespace std;

int main() {
    int liczby[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << liczby[i] << endl;
    }

    return 0;
}
```

**Wynik działania programu:**
```
Element 0: 1
Element 1: 2
Element 2: 3
Element 3: 4
Element 4: 5
```

---

#### Tablice wielowymiarowe

Tablice mogą mieć więcej niż jeden wymiar, np. tablice dwuwymiarowe używane do reprezentowania macierzy.

**Deklaracja i inicjalizacja:**

```cpp
int macierz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

**Dostęp do elementów:**

```cpp
cout << macierz[0][1]; // Wyświetla 2 (pierwszy wiersz, druga kolumna)
cout << macierz[1][2]; // Wyświetla 6 (drugi wiersz, trzecia kolumna)
```

**Iteracja:**

```cpp
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        cout << macierz[i][j] << " ";
    }
    cout << endl;
}
```

**Wynik działania programu:**
```
1 2 3 
4 5 6 
```

---

#### Tablice jako argumenty funkcji

Tablicę można przekazać do funkcji jako argument.

**Przykład:**

```cpp
void wypiszTablice(int tab[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

int main() {
    int liczby[] = {10, 20, 30};
    wypiszTablice(liczby, 3);
    return 0;
}
```

**Wynik:**
```
10 20 30
```

---

#### Podsumowanie

- **Tablica** to zbiór elementów tego samego typu.  
- Indeksowanie tablic zaczyna się od 0.  
- Tablice mogą mieć wiele wymiarów, np. dwuwymiarowe.  
- Tablice są przydatne do przechowywania i przetwarzania wielu wartości naraz.  
