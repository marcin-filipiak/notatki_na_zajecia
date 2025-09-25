## Licznik krokowy (%SC) – opis i zastosowanie

### Cel

Licznik krokowy (%SC) umożliwia realizację sekwencyjnych procesów sterowania, gdzie kolejne etapy (kroki) są aktywowane w odpowiedzi na sygnały wejściowe. Każdy krok odpowiada pojedynczemu bitowi w tablicy wyjść (%SCi.j), co pozwala na przypisanie konkretnych działań do poszczególnych kroków sekwencji.

### Tryby pracy

Licznik krokowy może pracować w dwóch trybach:

* **Tryb jednokierunkowy (Non-reversible)**: Po osiągnięciu ostatniego kroku licznik nie wraca do początku, a proces zatrzymuje się.
* **Tryb cykliczny (Reversible)**: Po osiągnięciu ostatniego kroku licznik wraca do pierwszego kroku, umożliwiając ciągłe powtarzanie sekwencji.

### Wejścia

Licznik krokowy posiada trzy podstawowe wejścia:

* **R (Reset)**: Ustawienie na 1 resetuje licznik do pierwszego kroku.
* **CU (Count Up)**: Na narastającym zboczu sygnału licznik przechodzi do następnego kroku.
* **CD (Count Down)**: Na narastającym zboczu sygnału licznik przechodzi do poprzedniego kroku.

### Wyjścia

Każdy krok licznika (%SCi.j) jest reprezentowany przez pojedynczy bit:

* **%SCi.j**: Wartość 1 oznacza aktywność danego kroku, 0 – brak aktywności.

### Przykład użycia

W poniższym przykładzie przedstawiono sposób implementacji licznika krokowego w drabince LD:

```ladder

                  %SC0
 %I0.0       ______________
--| |--------| R           |
             |             |
 %I0.1       |             |
--| |--------| CU          |
             |             |
 %I0.2       |             |
--| |--------| CD          |
             _______________
             
 %SC0.2                %Q0.0
--| |-------------------( )
```

W tym przykładzie, w zależności od aktywnego kroku licznika, włączane są odpowiednie wyjścia.

### Parametry konfiguracyjne

Licznik krokowy posiada następujące parametry:

* **Used**: Określa, czy adres jest używany w programie.
* **Address**: Adres obiektu licznika krokowego w pamięci.
* **Symbol**: Nazwa symboliczna przypisana do licznika.
* **Value**: Aktualna wartość licznika.

### Specjalne przypadki

* **Cold restart (%S0=1)**: Inicjalizuje licznik krokowy, ustawiając go na pierwszy krok.
* **Warm restart (%S1=1)**: Nie ma wpływu na stan licznika krokowego.
