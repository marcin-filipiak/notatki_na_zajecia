### Notatka: Pętla `do-while` w C++

#### Co to jest pętla `do-while`?

Pętla `do-while` jest podobna do pętli `while`, ale różni się tym, że warunek sprawdzany jest **po** wykonaniu kodu wewnątrz pętli, a nie przed. Oznacza to, że kod wewnątrz pętli zostanie wykonany przynajmniej raz, niezależnie od tego, czy warunek jest spełniony.

#### Składnia pętli `do-while`

```cpp
do {
    // kod do wykonania
} while (warunek);
```

- **`warunek`**: Wyrażenie, które jest oceniane po każdej iteracji. Pętla wykonuje się, dopóki warunek zwraca wartość true.

#### Jak działa pętla `do-while`?

1. **Kod w ciele pętli** jest wykonywany przynajmniej raz, ponieważ warunek jest sprawdzany dopiero po wykonaniu kodu.
2. Jeśli warunek zwróci wartość true, pętla wykona się ponownie.
3. Jeśli warunek zwróci wartość false, pętla zakończy działanie.

#### Przykład 1: Pętla `do-while` z licznikiem

```cpp
#include <iostream>
using namespace std;

int main() {
    int licznik = 1;

    do {
        cout << "Licznik: " << licznik << endl;
        licznik++;  // Zwiększenie licznika o 1
    } while (licznik <= 5);

    return 0;
}
```

**Wynik działania programu:**
```
Licznik: 1
Licznik: 2
Licznik: 3
Licznik: 4
Licznik: 5
```

**Dlaczego działa to tak?**
- Kod wewnątrz pętli wykonuje się zawsze co najmniej raz, a potem warunek `licznik <= 5` jest sprawdzany.
- Dopóki `licznik` jest mniejszy lub równy 5, pętla będzie kontynuować działanie.

#### Przykład 2: Pętla `do-while` z użytkownikiem

W tym przykładzie program prosi użytkownika o podanie liczby, aż użytkownik wprowadzi liczbę 0, aby zakończyć.

```cpp
#include <iostream>
using namespace std;

int main() {
    int liczba = -1;  // Inicjalizacja liczby, aby pętla wykonała się co najmniej raz

    do {
        cout << "Podaj liczbę (0, aby zakończyć): ";
        cin >> liczba;
    } while (liczba != 0);

    cout << "Pętla zakończona." << endl;

    return 0;
}
```

**Wynik działania programu (przykład):**
```
Podaj liczbę (0, aby zakończyć): 5
Podaj liczbę (0, aby zakończyć): 10
Podaj liczbę (0, aby zakończyć): 0
Pętla zakończona.
```

**Dlaczego działa to tak?**
- Pętla `do-while` prosi o liczbę i sprawdza warunek po wykonaniu pierwszego pobrania liczby.
- Dopóki użytkownik nie wpisze 0, pętla będzie kontynuować wprowadzanie kolejnych liczb.

#### Zastosowanie pętli `do-while`

1. **Kiedy musimy wykonać kod przynajmniej raz**: Pętla `do-while` jest szczególnie przydatna, gdy chcemy, aby kod w pętli wykonał się przynajmniej raz, niezależnie od warunku. Na przykład, gdy chcemy poprosić użytkownika o dane wejściowe, nawet jeśli nie znamy ich liczby z góry.
   
2. **Interaktywne programy**: Pętla `do-while` jest często stosowana w interaktywnych programach, gdzie użytkownik musi podać dane lub podjąć decyzję, a program powtarza zapytania, dopóki nie uzyska prawidłowej odpowiedzi.

#### Różnice między `while` a `do-while`

- **`while`**: Sprawdza warunek przed każdą iteracją. Jeśli warunek jest fałszywy od samego początku, kod w pętli może się nie wykonać ani razu.
- **`do-while`**: Sprawdza warunek po każdej iteracji, co zapewnia, że kod w pętli wykona się przynajmniej raz, nawet jeśli warunek jest fałszywy już na początku.

#### Podsumowanie

- Pętla `do-while` wykonuje kod przynajmniej raz, a warunek jest sprawdzany po wykonaniu kodu.
- Jest przydatna, gdy chcemy, aby operacja w pętli została przeprowadzona co najmniej raz, na przykład w przypadku interakcji z użytkownikiem.
- Różni się od pętli `while`, w której warunek sprawdzany jest przed wykonaniem kodu, co może spowodować, że kod pętli nie zostanie wykonany wcale, jeśli warunek nie jest spełniony.
