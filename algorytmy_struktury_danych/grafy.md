**Graf - podstawowe pojęcia i operacje**

### 1. Definicja grafu
Graf to struktura matematyczna składająca się z wierzchołków (ang. vertices, nodes) oraz krawędzi (ang. edges), które łączą te wierzchołki. Formalnie graf można zapisać jako:

\[ G = (V, E) \]

Gdzie:
- \( V \) – zbiór wierzchołków,
- \( E \) – zbiór krawędzi, które są parami wierzchołków.

### 2. Rodzaje grafów
- **Graf nieskierowany** – krawędzie nie mają kierunku, czyli \( (u, v) \) oznacza to samo co \( (v, u) \).
- **Graf skierowany (digraf)** – każda krawędź ma określony kierunek, czyli \( (u, v) \) nie jest tym samym co \( (v, u) \).
- **Graf ważony** – krawędzie mają przypisane wagi, co często wykorzystywane jest w algorytmach optymalizacyjnych.
- **Graf pełny** – każdy wierzchołek jest połączony z każdym innym.
- **Graf spójny** – istnieje ścieżka między każdą parą wierzchołków.
- **Graf dwudzielny** – zbiór wierzchołków można podzielić na dwa rozłączne podzbiory, tak że każda krawędź łączy wierzchołki z różnych podzbiorów.

### 3. Podstawowe pojęcia związane z grafami
- **Stopień wierzchołka** – liczba krawędzi incydentnych do danego wierzchołka.
- **Ścieżka** – ciąg krawędzi łączący pewien zbiór wierzchołków.
- **Cykl** – ścieżka, która zaczyna i kończy się w tym samym wierzchołku.
- **Drzewo** – szczególny przypadek grafu acyklicznego, w którym istnieje dokładnie jedna ścieżka między każdą parą wierzchołków.
- **Graf planarny** – można go narysować na płaszczyźnie bez przecinających się krawędzi.
- **Macierz sąsiedztwa** – reprezentacja grafu w postaci macierzy \( |V| \times |V| \), gdzie komórka \( (i, j) \) oznacza obecność (i ewentualnie wagę) krawędzi między \( v_i \) i \( v_j \).
- **Lista sąsiedztwa** – reprezentacja grafu, w której każdy wierzchołek przechowuje listę swoich sąsiadów.

### 4. Podstawowe operacje na grafach
- **Dodawanie i usuwanie wierzchołków oraz krawędzi.**
- **Przeszukiwanie grafu:**
  - BFS (Breadth-First Search) – przeszukiwanie wszerz.
  - DFS (Depth-First Search) – przeszukiwanie w głąb.
- **Znajdowanie najkrótszej ścieżki:**
  - Algorytm Dijkstry – dla grafów z dodatnimi wagami.
  - Algorytm Bellmana-Forda – obsługuje ujemne wagi.
  - Algorytm Floyda-Warshalla – znajduje ścieżki dla wszystkich par wierzchołków.
- **Minimalne drzewo rozpinające:**
  - Algorytm Kruskala – podejście zachłanne.
  - Algorytm Prima – alternatywne podejście.
- **Sprawdzanie spójności grafu.**
- **Wyszukiwanie mostów i punktów artykulacji – ważne w analizie sieci.**
- **Sortowanie topologiczne – dla grafów skierowanych acyklicznych (DAG).**

Grafy mają szerokie zastosowanie w informatyce, np. w sieciach komputerowych, nawigacji, analizie danych czy algorytmach sztucznej inteligencji.

