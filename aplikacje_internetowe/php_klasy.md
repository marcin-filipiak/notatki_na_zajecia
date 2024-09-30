### Klasa i obiekt w PHP – Notatka

**Klasa** w PHP to struktura, która pozwala na grupowanie funkcji i zmiennych (w PHP nazywanych **właściwościami**) związanych z danym tematem w jeden moduł. **Obiekt** natomiast to instancja klasy, czyli konkretny egzemplarz, który może przechowywać dane i wykonywać metody zdefiniowane w klasie.

#### Tworzenie klasy
W PHP tworzenie klasy odbywa się za pomocą słowa kluczowego `class`. Klasa może zawierać właściwości (zmienne) oraz metody (funkcje).

```php
<?php
class Samochod {
    // Właściwości (zmienne)
    public $marka;
    public $model;
    public $rok;

    // Konstruktor
    public function __construct($marka, $model, $rok) {
        $this->marka = $marka;
        $this->model = $model;
        $this->rok = $rok;
    }

    // Metoda (funkcja)
    public function opis() {
        return "Samochód: $this->marka $this->model z roku $this->rok.";
    }
}
?>
```

#### Tworzenie obiektu
Obiekt tworzymy za pomocą słowa kluczowego `new`, które wywołuje konstruktor klasy.

```php
<?php
// Tworzenie obiektu klasy Samochod
$mojSamochod = new Samochod("Toyota", "Corolla", 2021);

// Wywołanie metody opis() na obiekcie
echo $mojSamochod->opis();
?>
```

**Wynik:**
```
Samochód: Toyota Corolla z roku 2021.
```

#### Realne zastosowania klas i obiektów
1. **Modelowanie rzeczywistych obiektów:** Klasy mogą reprezentować rzeczywiste obiekty, takie jak samochody, użytkownicy, produkty w sklepie internetowym itp. Każdy obiekt będzie zawierał dane i funkcje specyficzne dla swojej instancji.
   
2. **Zarządzanie danymi użytkowników:** W aplikacjach internetowych klasy są często używane do przechowywania i manipulowania danymi użytkowników, np. klasę „Użytkownik” można użyć do rejestrowania, logowania i aktualizowania danych użytkowników.

3. **Operacje na bazie danych:** Klasy mogą być wykorzystywane do abstrakcji operacji na bazie danych, np. ORM-y (Object-Relational Mapping), które mapują obiekty w PHP na tabele w bazie danych.

4. **Modularność i ponowne użycie kodu:** Zastosowanie klas umożliwia łatwe organizowanie kodu w mniejsze, niezależne moduły. Każda klasa może realizować specyficzną funkcjonalność, co ułatwia zarządzanie kodem i jego ponowne wykorzystanie.

5. **Dziedziczenie i polimorfizm:** Klasy pozwalają na dziedziczenie, co oznacza, że jedna klasa może dziedziczyć właściwości i metody innej klasy. Dzięki temu można łatwo rozszerzać istniejące funkcje bez konieczności ponownego pisania kodu.

#### Dziedziczenie – Przykład
```php
<?php
class Pojazd {
    public $typ;
    
    public function __construct($typ) {
        $this->typ = $typ;
    }
    
    public function opis() {
        return "To jest pojazd typu: $this->typ.";
    }
}

class Motocykl extends Pojazd {
    public $marka;

    public function __construct($typ, $marka) {
        parent::__construct($typ);  // Wywołanie konstruktora klasy bazowej
        $this->marka = $marka;
    }

    public function opis() {
        return parent::opis() . " Marka: $this->marka.";
    }
}

$motocykl = new Motocykl("Dwukołowy", "Yamaha");
echo $motocykl->opis();
?>
```

**Wynik:**
```
To jest pojazd typu: Dwukołowy. Marka: Yamaha.
```
