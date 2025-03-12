### Algorytm Dijkstry – proste wyjaśnienie  

Algorytm Dijkstry znajduje najkrótszą ścieżkę od jednego wierzchołka do wszystkich innych wierzchołków w grafie. W moim przykładzie szukamy ścieżki od A do wszystkich innych wierzchołków (czyli do B i do C). 
Działa tylko dla **grafów z dodatnimi wagami krawędzi**.

Jeśli chcesz znaleźć najkrótszą ścieżkę od A do konkretnego wierzchołka, np. do B, to po prostu kończysz algorytm, gdy znajdziesz najkrótszą trasę do tego wierzchołka.

#### Jak działa algorytm?  
1. **Inicjalizacja**  
   - Ustaw odległość startowego wierzchołka na **0**, a wszystkich pozostałych na **nieskończoność** (∞).
   - Tworzymy **zbiór wierzchołków przetworzonych** (na początku pusty).  

2. **Przetwarzanie wierzchołków**  
   - Wybierz **wierzchołek o najmniejszej znanej odległości** (na początku jest to startowy wierzchołek).
   - Sprawdź jego **sąsiadów** – jeśli dotarcie do sąsiada przez ten wierzchołek jest krótsze niż jego obecna odległość, **zaktualizuj** tę odległość.
   - Oznacz ten wierzchołek jako **przetworzony** i nie analizuj go ponownie.  

3. **Powtarzaj kroki, aż przeanalizujesz wszystkie wierzchołki.**  

#### Przykład  
Mamy graf:  

```
       (A)
      /   \
   4 /     \ 1
    /       \
  (B) ---- (C)
     2
```
**Wagi krawędzi:**  
- A → B: 4  
- A → C: 1  
- B → C: 2  

Szukamy najkrótszej ścieżki od **A**.  

1. **Start:**
   - A = 0, B = ∞, C = ∞  
   - Wybieramy A (bo 0 < ∞).  

2. **Przetwarzamy A:**  
   - Do B możemy dojść w 4 (∞ → 4), do C w 1 (∞ → 1).  
   - Nowe wartości: **A = 0, B = 4, C = 1**.  
   - Wybieramy C (bo ma mniejszą wartość).  

3. **Przetwarzamy C:**  
   - Do B możemy dojść przez C w **1 + 2 = 3** (lepsze niż 4 → aktualizujemy).  
   - Nowe wartości: **A = 0, B = 3, C = 1**.  
   - Wybieramy B (bo to ostatni nieprzetworzony wierzchołek).  

4. **Koniec – najkrótsze ścieżki:**  
   - **A → B = 3**  
   - **A → C = 1**  

#### Złożoność obliczeniowa  
- **Z użyciem listy i tablicy:** \\( O(V^2) \\)  
- **Z użyciem kopca (priorytetowej kolejki):** \\( O((V + E) \log V) \\)


## Algorytm

### **Algorytm działania kodu (Dijkstra na tablicach)**  

1. **Przygotowanie danych**  
   - `graph[N][N]` → macierz sąsiedztwa przechowuje wagi krawędzi między wierzchołkami.  
   - `INF` → duża liczba (symbolizuje brak połączenia).  
   - `dist[N]` → tablica z najkrótszymi odległościami od wierzchołka startowego.  
   - `visited[N]` → tablica, która oznacza odwiedzone wierzchołki.  

2. **Inicjalizacja**  
   - Wszystkie odległości w `dist[]` są ustawione na **INF** (nieskończoność).  
   - Wszystkie wierzchołki w `visited[]` są ustawione na **false** (nieodwiedzone).  
   - Odległość `dist[start] = 0` → punkt startowy ma dystans 0.  

3. **Wybór wierzchołka o najmniejszej odległości**  
   - W pętli `for (int i = 0; i < N; i++)` wybieramy wierzchołek `minVertex`, który:  
     - **Nie był jeszcze odwiedzony** (`visited[j] == false`).  
     - Ma **najmniejszą wartość w `dist[]`**.  
   - Jeśli nie ma takiego wierzchołka (`minVertex == -1`), kończymy działanie.  

4. **Oznaczamy `minVertex` jako odwiedzony**  
   - `visited[minVertex] = true` → nie będziemy go więcej sprawdzać.  

5. **Aktualizacja odległości sąsiadów**  
   - Dla każdego sąsiada `j` `minVertex`, jeśli istnieje połączenie (`graph[minVertex][j] != 0`):  
     - Obliczamy nową odległość `newDist = dist[minVertex] + graph[minVertex][j]`.  
     - Jeśli `newDist < dist[j]`, aktualizujemy `dist[j] = newDist`.  

6. **Po zakończeniu pętli `for (int i = 0; i < N; i++)` mamy najkrótsze odległości**  
   - Wypisujemy wynik, gdzie `char('A' + i)` konwertuje numer na literę (`0 → A`, `1 → B`, `2 → C`).  

---

### **Przykładowe działanie na grafie:**  

Graf:
```
(A)
 /   \
4     1
/       \
(B) ---- (C)
     2
```

#### **Przebieg algorytmu dla `start = A (0)`**  

| Iteracja | `minVertex` | Aktualizacja `dist[]` (od A) |
|----------|------------|------------------------------|
| 1. wybór | `A` (0)    | `dist[A] = 0`, `dist[B] = 4`, `dist[C] = 1` |
| 2. wybór | `C` (2)    | `dist[B] = 1 + 2 = 3` (mniej niż `4`) |
| 3. wybór | `B` (1)    | brak zmian |

Wynik:
```
Najkrótsze drogi od A:
Do A = 0
Do B = 3
Do C = 1
```
- **Do B** → przez C (`A → C → B`), koszt: `1 + 2 = 3`
- **Do C** → bezpośrednio (`A → C`), koszt: `1`

---


## Implementacja w C++

Mamy graf:  

```
       (A)
      /   \
   4 /     \ 1
    /       \
  (B) ---- (C)
     2
```

Poszukujemy najkrótszych ścieżek od A

```cpp
#include <iostream>

using namespace std;

const int INF = 1e9; // "Nieskończoność" - duża liczba
const int N = 3;     // Liczba wierzchołków

// Macierz sąsiedztwa - wagi krawędzi
int graph[N][N] = {
    {0, 4, 1},  // A -> B (4), A -> C (1)
    {4, 0, 2},  // B -> A (4), B -> C (2)
    {1, 2, 0}   // C -> A (1), C -> B (2)
};

void dijkstra(int start) {
    int dist[N];     // Najkrótsze odległości
    bool visited[N]; // Czy wierzchołek był odwiedzony?

    // Inicjalizacja tablic
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[start] = 0; // Startowy wierzchołek ma odległość 0

    for (int i = 0; i < N; i++) {
        // Znajdujemy wierzchołek o najmniejszej odległości
        int minDist = INF, minVertex = -1;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minVertex = j;
            }
        }

        if (minVertex == -1) break; // Nie ma już wierzchołków do odwiedzenia

        visited[minVertex] = true; // Oznaczamy jako odwiedzony

        // Aktualizujemy odległości sąsiadów
        for (int j = 0; j < N; j++) {
            if (graph[minVertex][j] != 0) { // Jeśli istnieje krawędź
                int newDist = dist[minVertex] + graph[minVertex][j];
                if (newDist < dist[j]) {
                    dist[j] = newDist;
                }
            }
        }
    }

    // Wyświetlanie wyników
    cout << "Najkrótsze drogi od A:\n";
    for (int i = 0; i < N; i++) {
        cout << "Do " << char('A' + i) << " = ";
        if (dist[i] == INF) cout << "brak drogi\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    dijkstra(0); // Szukamy najkrótszych ścieżek od A
    return 0;
}
```

