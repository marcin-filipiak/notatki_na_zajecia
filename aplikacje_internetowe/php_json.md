# PHP i JSON

## 1. Co to jest JSON?

JSON (JavaScript Object Notation) to tekstowy format zapisu danych.
Służy do wymiany danych między aplikacjami (np. przeglądarka ↔ serwer, API ↔ program).

Jest:

* czytelny dla człowieka,
* lekki,
* niezależny od języka programowania.

### Podstawowe typy danych w JSON

JSON obsługuje:

* string (tekst)
* number (liczba)
* boolean (true / false)
* null
* array (tablica)
* object (obiekt)

---

## 2. Składnia JSON

### Obiekt

Obiekt zapisujemy w nawiasach klamrowych `{}`
Składa się z par klucz–wartość.

```
{
    "imie": "Jan",
    "wiek": 30,
    "aktywny": true
}
```

Zasady:

* klucze MUSZĄ być w cudzysłowie
* tekst również w cudzysłowie
* pary oddzielamy przecinkami

---

### Tablica

Tablica w JSON jest w nawiasach kwadratowych `[]`

```
[
    "Ala",
    "Ola",
    "Ela"
]
```

---

### Tablica obiektów (najczęstszy przypadek)

```
[
    {
        "imie": "Jan",
        "wiek": 30
    },
    {
        "imie": "Anna",
        "wiek": 25
    }
]
```

To bardzo typowy format przy API i bazach danych.

---

## 3. Przetwarzanie JSON w PHP

W PHP używamy dwóch podstawowych funkcji:

* json_decode() – zamienia JSON na strukturę PHP
* json_encode() – zamienia dane PHP na JSON

---

# CZĘŚĆ I – JSON → tablica PHP

## Przykład danych JSON

```
$json = '[
    {
        "imie": "Jan",
        "wiek": 30
    },
    {
        "imie": "Anna",
        "wiek": 25
    }
]';
```

---

## Zamiana JSON na tablicę

```
$data = json_decode($json, true);
```

Drugi parametr `true` jest bardzo ważny.
Powoduje, że obiekty JSON zostaną zamienione na tablice asocjacyjne PHP.

Bez `true` otrzymasz obiekty.

---

## Sprawdzenie struktury

```
var_dump($data);
```

Otrzymasz tablicę:

```
array(
    0 => array(
        "imie" => "Jan",
        "wiek" => 30
    ),
    1 => array(
        "imie" => "Anna",
        "wiek" => 25
    )
)
```

---

## Przetwarzanie tablicy

```
foreach ($data as $osoba) {
    echo "Imię: " . $osoba["imie"] . "<br>";
    echo "Wiek: " . $osoba["wiek"] . "<br><br>";
}
```

---

# CZĘŚĆ II – tablica PHP → eksport do JSON

## Tworzymy tablicę w PHP

```
$students = [
    [
        "imie" => "Kamil",
        "wiek" => 18
    ],
    [
        "imie" => "Ola",
        "wiek" => 19
    ]
];
```

---

## Zamiana na JSON

```
$json = json_encode($students);
echo $json;
```

Wynik:

```
[{"imie":"Kamil","wiek":18},{"imie":"Ola","wiek":19}]
```

---

## Czytelny zapis (formatowanie)

Jeśli chcesz ładny format:

```
$json = json_encode($students, JSON_PRETTY_PRINT);
echo $json;
```

---

# Zapis JSON do pliku (eksport do pliku)

```
$json = json_encode($students, JSON_PRETTY_PRINT);
file_put_contents("students.json", $json);
```

Powstanie plik `students.json`.

---

# Odczyt JSON z pliku

```
$json = file_get_contents("students.json");
$data = json_decode($json, true);

print_r($data);
```

---


# Mini przykład praktyczny – zapis temperatur

## Tablica temperatur

```
$temperatures = [12, 15, 18, 20, 17];
```

## Eksport do JSON

```
$json = json_encode($temperatures);
file_put_contents("temp.json", $json);
```

## Odczyt

```
$json = file_get_contents("temp.json");
$data = json_decode($json, true);

foreach ($data as $t) {
    echo $t . "<br>";
}
```
