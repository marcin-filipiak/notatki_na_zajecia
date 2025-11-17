## Funkcje do przetwarzania tekstu w PHP

### **1. Normalizacja liter**

**`mb_strtolower($text)`**

* Zamienia wszystkie litery na małe, obsługując polskie i inne znaki Unicode.
* Używane przed analizą słów, aby zliczanie było niezależne od wielkości liter.

```php
$text = "Żółć I KOT";
echo mb_strtolower($text); // żółć i kot
```

**`mb_strtoupper($text)`**

* Odwrotność `mb_strtolower` – zmienia wszystkie litery na wielkie.

---

### **2. Usuwanie niechcianych znaków**

**`preg_replace`**

* Zamienia fragmenty tekstu zgodnie z wyrażeniem regularnym.
* Przydatne do usuwania interpunkcji lub innych niepotrzebnych znaków.

```php
$text = "Ala ma kota! Kot ma Ale?";
$clean = preg_replace('/[^\p{L}\p{N}\s]/u', ' ', $text);
echo $clean; // Ala ma kota  Kot ma Ale 
```

**Wyrażenia regularne:**

* `\p{L}` – litery Unicode (w tym polskie znaki)
* `\p{N}` – cyfry
* `\s` – białe znaki (spacje, tabulatory, nowe linie)
* `[^ ... ]` – negacja, czyli usuwa wszystko, co nie pasuje
* `u` – tryb Unicode

---

### **3. Dzielenie tekstu na słowa**

**`preg_split($pattern, $text, -1, $flags)`**

* Dzieli tekst według wzorca regularnego.
* Bardziej elastyczne niż `explode`, bo pozwala na wiele separatorów, np. spacje, tabulatory, nowe linie.

```php
$text = "Ala  ma   kota \n kot ma Ale";
$words = preg_split('/\s+/', $text, -1, PREG_SPLIT_NO_EMPTY);
print_r($words);
```

Wynik:

```
Array ( [0] => Ala [1] => ma [2] => kota [3] => kot [4] => ma [5] => Ale )
```

**Parametry:**

* `\s+` – jedno lub więcej białych znaków
* `PREG_SPLIT_NO_EMPTY` – usuwa puste elementy
* `-1` – bez limitu liczby podziałów

**`explode($delimiter, $string, $limit)`**

* Prostsza funkcja do dzielenia tekstu po jednym konkretnym separatorze, np. spacji, przecinku.
* Nie obsługuje wyrażeń regularnych, więc mniej elastyczna.

```php
$text = "Ala,ma,kota";
$words = explode(",", $text);
print_r($words); 
// Array ( [0] => Ala [1] => ma [2] => kota )
```

**Różnica `preg_split` vs `explode`:**

* `preg_split` – pozwala użyć wzorca i obsługuje wiele znaków separatorów naraz.
* `explode` – prosty, szybki, tylko jeden znak/sekwencja jako separator.

---

### **4. Liczenie wystąpień słów**

**`array_count_values($array)`**

* Liczy, ile razy każdy element występuje w tablicy.

```php
$words = ["kot", "pies", "kot"];
$counts = array_count_values($words);
print_r($counts);
// Array ( [kot] => 2 [pies] => 1 )
```

---

### **5. Inne przydatne funkcje**

**`trim($text)`**

* Usuwa spacje lub inne znaki z początku i końca tekstu.

```php
$text = "  Ala ma kota  ";
echo trim($text); // Ala ma kota
```

**`str_word_count($text, $format=0, $charlist)`**

* Dzieli tekst na słowa i zlicza je.
* `1` – zwraca tablicę słów
* `0` – zwraca liczbę słów
* `2` – zwraca tablicę z pozycjami słów

**Uwaga:** domyślnie nie obsługuje polskich znaków poprawnie, trzeba użyć dodatkowego `charlist`.

**`mb_strlen($text)`**

* Zlicza długość tekstu w znakach Unicode, w przeciwieństwie do `strlen`, który liczy bajty.

**`mb_substr($text, $start, $length)`**

* Wyciąga fragment tekstu, obsługując polskie znaki.

---

### **6. Przykładowy przepływ analizy tekstu**

```php
$text = "Ala ma kota, a kot ma Ale!";

$text = mb_strtolower($text); // normalizacja
$text = preg_replace('/[^\p{L}\p{N}\s]/u', ' ', $text); // usunięcie interpunkcji
$words = preg_split('/\s+/', $text, -1, PREG_SPLIT_NO_EMPTY); // dzielenie
$stats = array_count_values($words); // liczenie

print_r($stats);
```

Wynik:

```
Array ( [ala] => 2 [ma] => 2 [kota] => 1 [a] => 1 [kot] => 1 [ale] => 1 )
```
