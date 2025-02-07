**Klasa i obiekty w PHP**

### Tworzenie klasy
W PHP klasy definiuje się za pomocą słowa kluczowego `class`:

```php
class Car {
    // Właściwości klasy (pola)
    public $brand;
    public $model;
    private $mileage;
    
    // Konstruktor
    public function __construct($brand, $model, $mileage = 0) {
        $this->brand = $brand;
        $this->model = $model;
        $this->mileage = $mileage;
    }
    
    // Metoda publiczna
    public function drive($distance) {
        $this->mileage += $distance;
        echo "Przejechano $distance km. Łączny przebieg: $this->mileage km.\n";
    }
    
    // Metoda prywatna
    private function getMileage() {
        return $this->mileage;
    }
    
    // Destruktor
    public function __destruct() {
        echo "Obiekt klasy Car został zniszczony.\n";
    }
}
```

### Tworzenie obiektów
Obiekt klasy tworzymy za pomocą `new`:

```php
$myCar = new Car("Toyota", "Corolla", 10000);
$myCar->drive(150);
```

### Dziedziczenie
Jedna klasa może dziedziczyć po innej, używając `extends`:

```php
class ElectricCar extends Car {
    public $batteryCapacity;
    
    public function __construct($brand, $model, $batteryCapacity, $mileage = 0) {
        parent::__construct($brand, $model, $mileage);
        $this->batteryCapacity = $batteryCapacity;
    }
    
    public function charge() {
        echo "Ładowanie baterii o pojemności $this->batteryCapacity kWh.\n";
    }
}
```

### Prywatne i publiczne pola/metody
- **public** – dostępne wszędzie.
- **private** – dostępne tylko wewnątrz klasy.
- **protected** – dostępne wewnątrz klasy i klas dziedziczących.

Przykład użycia:

```php
$tesla = new ElectricCar("Tesla", "Model S", 100);
$tesla->drive(200);
$tesla->charge();
```

Obiekty w PHP pozwalają na organizację kodu w sposób obiektowy, umożliwiając enkapsulację, dziedziczenie i polimorfizm.

