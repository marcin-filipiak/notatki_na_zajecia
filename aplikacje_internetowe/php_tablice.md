### Tablice zwykłe i asocjacyjne

#### Czym jest tablica w PHP?

Tablica to struktura danych, która pozwala przechowywać wiele wartości w jednym miejscu. W PHP możemy mieć dwa główne typy tablic:

1. **Tablice indeksowane** (zwykłe) - elementy są dostępne za pomocą indeksów liczbowych.
2. **Tablice asocjacyjne** - elementy są dostępne za pomocą nazw (kluczy), które mogą być tekstowe.

#### Tablica indeksowana (zwykła)

Tablica indeksowana jest uporządkowanym zbiorem wartości, gdzie każdy element jest dostępny za pomocą liczbowego indeksu, zaczynając od 0. Tworzenie i korzystanie z takiej tablicy może wyglądać tak:

```php
// Tworzenie tablicy indeksowanej
$owoce = ["jabłko", "banan", "gruszka"];

// Dostęp do elementów
echo $owoce[0]; // Wyświetli "jabłko"
echo $owoce[1]; // Wyświetli "banan"

// Dodawanie nowego elementu
$owoce[] = "pomarańcza"; // Dodaje "pomarańcza" na koniec tablicy
```

Tablice indeksowane są przydatne, gdy chcemy przechowywać listy wartości bez konieczności określania kluczy dla każdego elementu.

#### Tablica asocjacyjna

Tablica asocjacyjna jest podobna do słownika: każdy element ma klucz, który jest nazwą (zwykle tekstową), a nie liczbą. Pozwala to na bardziej opisowy dostęp do danych:

```php
// Tworzenie tablicy asocjacyjnej
$osoba = [
    "imie" => "Jan",
    "nazwisko" => "Kowalski",
    "wiek" => 30
];

// Dostęp do elementów za pomocą kluczy
echo $osoba["imie"];      // Wyświetli "Jan"
echo $osoba["nazwisko"];   // Wyświetli "Kowalski"

// Dodawanie nowego elementu
$osoba["miasto"] = "Warszawa";
```

Tablice asocjacyjne są idealne, gdy chcemy przypisywać wartości do konkretnych kluczy, co zwiększa czytelność kodu.

#### Różnice między tablicą indeksowaną a asocjacyjną

| Tablica indeksowana                | Tablica asocjacyjna                    |
|------------------------------------|----------------------------------------|
| Indeksy liczbowe (0, 1, 2, ...)    | Klucze tekstowe (np. "imie", "wiek")   |
| Dostęp po indeksie liczbowym       | Dostęp po kluczu                      |
| Przydatna do list o nieznanym formacie | Ułatwia opisanie danych strukturalnych |

#### Przykłady użycia

1. **Tablica indeksowana** – lista ulubionych kolorów:

    ```php
    $kolory = ["czerwony", "zielony", "niebieski"];
    ```

2. **Tablica asocjacyjna** – dane osobowe:

    ```php
    $dane = [
        "imie" => "Anna",
        "nazwisko" => "Nowak",
        "wiek" => 25
    ];
    ```

Tablice w PHP są elastyczne i można je dostosować do różnych potrzeb. Można nawet łączyć oba typy, tworząc **tablice wielowymiarowe**, które zawierają zarówno indeksowane, jak i asocjacyjne elementy.
