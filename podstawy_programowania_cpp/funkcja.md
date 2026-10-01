# Funkcje w C++

Funkcja to wydzielony fragment programu, który wykonuje określone zadanie.
Funkcję możemy wywołać wielokrotnie w różnych miejscach programu.

## 1. Podstawowa budowa funkcji

```cpp
typ_zwracanej_wartosci nazwa_funkcji(parametry)
{
    // instrukcje
}
```

Przykład:

```cpp
void przywitaj()
{
    cout << "Czesc!";
}
```

* `void` – funkcja niczego nie zwraca,
* `przywitaj` – nazwa funkcji,
* `()` – lista parametrów,
* `{ }` – ciało funkcji.

Wywołanie funkcji:

```cpp
przywitaj();
```

---

## 2. Funkcja zwracająca wartość

Funkcja może obliczyć wynik i zwrócić go za pomocą `return`.

```cpp
int dodaj()
{
    return 2 + 3;
}
```

Możemy odebrać wynik:

```cpp
int wynik = dodaj();

cout << wynik;
```

Program wypisze:

```text
5
```

Typ przed nazwą funkcji określa typ zwracanej wartości.

```cpp
int       // zwraca liczbę całkowitą
double    // zwraca liczbę zmiennoprzecinkową
char      // zwraca pojedynczy znak
bool      // zwraca true lub false
void      // nic nie zwraca
```

---

## 3. Parametry funkcji

Funkcja może otrzymywać dane z programu.

```cpp
void przywitaj(string imie)
{
    cout << "Czesc " << imie;
}
```

Wywołanie:

```cpp
przywitaj("Marcin");
```

Wynik:

```text
Czesc Marcin
```

`imie` jest **parametrem funkcji**, a `"Marcin"` jest **argumentem przekazanym do funkcji**.

---

## 4. Funkcja z parametrami i wynikiem

Najczęściej funkcje wykorzystujemy do wykonywania obliczeń.

```cpp
int dodaj(int a, int b)
{
    return a + b;
}
```

Wywołanie:

```cpp
int wynik = dodaj(10, 20);

cout << wynik;
```

Wynik:

```text
30
```

Schemat:

```cpp
int dodaj(int a, int b)
{
    return a + b;
}
```

* `int` – typ wyniku,
* `dodaj` – nazwa funkcji,
* `int a, int b` – parametry,
* `return a + b` – zwrócenie wyniku.

---

## 5. Kilka parametrów

Funkcja może mieć dowolną liczbę parametrów.

```cpp
int pomnoz(int a, int b, int c)
{
    return a * b * c;
}
```

Wywołanie:

```cpp
cout << pomnoz(2, 3, 4);
```

Wynik:

```text
24
```

---

## 6. Funkcja typu `void`

Jeżeli funkcja ma wykonać określoną czynność, ale nie musi zwracać wyniku, możemy użyć `void`.

```cpp
void pokazLiczbe(int liczba)
{
    cout << "Liczba: " << liczba;
}
```

Wywołanie:

```cpp
pokazLiczbe(15);
```

Wynik:

```text
Liczba: 15
```

W funkcji `void` można również użyć:

```cpp
return;
```

ale nie zwracamy wtedy żadnej wartości.

---

## 7. Funkcja sprawdzająca warunek

Funkcja może zwracać wartość `bool`.

```cpp
bool czyParzysta(int liczba)
{
    return liczba % 2 == 0;
}
```

Wywołanie:

```cpp
if (czyParzysta(10))
{
    cout << "Liczba jest parzysta";
}
```

Funkcja zwróci:

```text
true
```

dla liczby parzystej albo:

```text
false
```

dla nieparzystej.

---

## 8. Deklaracja funkcji

Funkcję można zadeklarować przed `main()`, a jej definicję umieścić później.

```cpp
#include <iostream>
using namespace std;

int dodaj(int a, int b);

int main()
{
    cout << dodaj(5, 7);

    return 0;
}

int dodaj(int a, int b)
{
    return a + b;
}
```

Linia:

```cpp
int dodaj(int a, int b);
```

to **deklaracja funkcji**.

Informuje kompilator, że taka funkcja istnieje.

---

## 9. Definicja funkcji

Definicja zawiera właściwy kod funkcji:

```cpp
int dodaj(int a, int b)
{
    return a + b;
}
```

Deklaracja:

```cpp
int dodaj(int a, int b);
```

Definicja:

```cpp
int dodaj(int a, int b)
{
    return a + b;
}
```

Deklaracja kończy się średnikiem `;`.

Definicja zawiera ciało funkcji w `{ }`.

---

## 10. Przekazywanie przez wartość

Domyślnie parametr jest przekazywany przez wartość.

```cpp
void zwieksz(int x)
{
    x++;
}
```

Przykład:

```cpp
int liczba = 10;

zwieksz(liczba);

cout << liczba;
```

Wynik:

```text
10
```

Funkcja otrzymała kopię wartości `liczba`, więc oryginalna zmienna się nie zmieniła.

---

## 11. Przekazywanie przez referencję

Jeżeli chcemy, aby funkcja mogła zmienić oryginalną zmienną, używamy `&`.

```cpp
void zwieksz(int &x)
{
    x++;
}
```

Teraz:

```cpp
int liczba = 10;

zwieksz(liczba);

cout << liczba;
```

Wynik:

```text
11
```

`&` oznacza tutaj **referencję**.

Funkcja pracuje na oryginalnej zmiennej.

---

## 12. Funkcja może mieć różne typy parametrów

```cpp
double poleProstokata(double a, double b)
{
    return a * b;
}
```

Wywołanie:

```cpp
double wynik = poleProstokata(5.5, 3.2);

cout << wynik;
```

---

## 13. Przykład kompletnego programu

```cpp
#include <iostream>
using namespace std;

int dodaj(int a, int b)
{
    return a + b;
}

int odejmij(int a, int b)
{
    return a - b;
}

int main()
{
    int a = 10;
    int b = 3;

    cout << "Suma: " << dodaj(a, b) << endl;
    cout << "Roznica: " << odejmij(a, b) << endl;

    return 0;
}
```

Wynik:

```text
Suma: 13
Roznica: 7
```

## Najważniejsze zasady

```cpp
int dodaj(int a, int b)
{
    return a + b;
}
```

Zapamiętaj:

1. **Typ** mówi, co funkcja zwraca.
2. **Nazwa** identyfikuje funkcję.
3. **Parametry** to dane przekazywane do funkcji.
4. **`return`** zwraca wynik.
5. **`void`** oznacza brak zwracanej wartości.
6. Funkcję wywołujemy podając jej nazwę i argumenty:

```cpp
dodaj(5, 10);
```

7. Funkcję można wywoływać wiele razy:

```cpp
cout << dodaj(2, 3);
cout << dodaj(10, 20);
cout << dodaj(100, 200);
```

---

## Schemat do zapamiętania

### Funkcja bez parametrów i bez wyniku

```cpp
void nazwa()
{
    // instrukcje
}
```

### Funkcja z parametrami

```cpp
void nazwa(int a, int b)
{
    // instrukcje
}
```

### Funkcja zwracająca wynik

```cpp
int nazwa(int a, int b)
{
    return a + b;
}
```

### Funkcja zmieniająca przekazaną zmienną

```cpp
void nazwa(int &a)
{
    a++;
}
```
