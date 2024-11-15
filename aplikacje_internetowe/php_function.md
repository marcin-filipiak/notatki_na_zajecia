# Wprowadzenie do funkcji

#### Czym jest funkcja?

Funkcja w programowaniu to fragment kodu, który wykonuje określone zadanie. Można myśleć o funkcji jak o małym programie wewnątrz większego programu. Funkcja przyjmuje dane wejściowe (tzw. **argumenty**), wykonuje operacje, a następnie zwraca wynik lub po prostu wykonuje działania bez zwracania wyniku.

#### Jak tworzy się funkcje w PHP?

W PHP definiujemy funkcje za pomocą słowa kluczowego `function`, nazwy funkcji i nawiasów, w których mogą znajdować się parametry. Oto przykład:

```php
function nazwaFunkcji($parametr1, $parametr2) {
    // kod do wykonania
    return $wynik; // opcjonalnie zwraca wynik
}
```

Na przykład:

```php
function dodaj($a, $b) {
    return $a + $b;
}

$wynik = dodaj(2, 3); // $wynik wyniesie 5
```

#### Po co tworzymy funkcje?

Funkcje wprowadzają do kodu **organizację i przejrzystość** oraz umożliwiają **ponowne użycie** kodu. Dzięki nim możemy:

1. **Unikać powtórzeń** - zamiast pisać ten sam kod wielokrotnie, tworzymy funkcję, którą możemy wielokrotnie wywoływać.
2. **Ułatwiać modyfikacje i debugowanie** - jeśli kod jest podzielony na funkcje, łatwiej jest znaleźć błędy i modyfikować kod.
3. **Zwiększać czytelność kodu** - funkcje o odpowiednich nazwach pokazują, co robią, co ułatwia zrozumienie kodu przez innych programistów.

#### Przykłady gotowych funkcji w PHP

PHP oferuje wiele wbudowanych funkcji, które ułatwiają programowanie. Oto kilka przykładów:

- **Funkcje matematyczne**: np. `abs($liczba)`, `sqrt($liczba)`, `pow($liczba, $wykladnik)`
- **Funkcje do pracy z ciągami znaków**: np. `strlen($string)`, `str_replace($szukane, $zamiennik, $tekst)`, `strpos($tekst, $szukane)`
- **Funkcje do pracy z tablicami**: np. `array_push($tablica, $element)`, `count($tablica)`, `in_array($wartosc, $tablica)`
- **Funkcje daty i czasu**: np. `date("Y-m-d")`, `time()`, `mktime($godzina, $minuta, $sekunda, $miesiac, $dzien, $rok)`

Funkcje są bardzo przydatne i pozwalają na szybkie rozwiązanie wielu typowych problemów w programowaniu.
