### Zadanie API kursy walut

Napisz aplikację w PHP, która:

* udostępnia API pod adresem np. `api.php`,
* przyjmuje parametry przez metodę **GET** (np. `?base=PLN` lub `?currency=EUR`),
* pobiera dane o kursach walut z bazy danych (MySQL),
* zwraca odpowiedź w formacie **JSON**,
* ustawia odpowiedni nagłówek `Content-Type: application/json`.

Aplikacja nie ma generować HTML – ma działać wyłącznie jako endpoint API.

---

## 1. Czym jest API i JSON

**API (Application Programming Interface)** w tym kontekście to plik PHP, który:

* przyjmuje dane wejściowe (np. z `$_GET`),
* przetwarza je,
* zwraca odpowiedź w ustalonym formacie (tu: JSON).

**JSON** to tekstowa reprezentacja danych strukturalnych.
Przykład:

```
{
  "base": "PLN",
  "rates": [
    {"currency": "EUR", "rate": 4.32},
    {"currency": "USD", "rate": 3.98}
  ]
}
```

W PHP konwersję tablicy do JSON wykonuje się przez:

```php
echo json_encode($data);
```

---

## 2. Metoda GET w PHP

Parametry przekazane w adresie URL:

```
api.php?currency=EUR
```

W PHP odczytujemy je przez:

```php
$currency = $_GET['currency'];
```

Dobrą praktyką jest sprawdzenie, czy parametr istnieje:

```php
if (isset($_GET['currency'])) {
    $currency = $_GET['currency'];
}
```

Można też użyć operatora null coalescing:

```php
$currency = $_GET['currency'] ?? null;
```

---

## 3. Ustawienie nagłówka JSON

API powinno zwracać poprawny nagłówek HTTP:

```php
header('Content-Type: application/json');
```

Bez tego przeglądarka może traktować odpowiedź jako zwykły tekst.

---

## 4. Połączenie z bazą danych (mysqli)

Zakładamy, że tabela `exchange_rates` ma strukturę:

```
id
currency_code
rate
base_currency
updated_at
```

Połączenie z bazą (mysqli):

```php
$conn = new mysqli("localhost", "user", "password", "database");

if ($conn->connect_error) {
    die("Connection failed");
}
```

---

## 5. Zapytania SQL i bezpieczeństwo

Jeśli parametr z GET trafia do zapytania SQL, należy używać **prepared statements**, aby uniknąć SQL Injection.

Niepoprawne:

```php
$sql = "SELECT * FROM exchange_rates WHERE currency_code = '$currency'";
```

Poprawne podejście:

```php
$stmt = $conn->prepare("SELECT currency_code, rate FROM exchange_rates WHERE currency_code = ?");
$stmt->bind_param("s", $currency);
$stmt->execute();
$result = $stmt->get_result();
```

---

## 6. Pobieranie danych do tablicy PHP

Wynik zapytania można przekształcić w tablicę:

```php
$data = [];

while ($row = $result->fetch_assoc()) {
    $data[] = $row;
}
```

Struktura `$data` może wyglądać tak:

```
[
  ["currency_code" => "EUR", "rate" => 4.32],
  ["currency_code" => "USD", "rate" => 3.98]
]
```

---

## 7. Zwracanie odpowiedzi API

Można przygotować strukturę odpowiedzi:

```php
$response = [
    "status" => "ok",
    "data" => $data
];

echo json_encode($response);
```

Warto też obsłużyć sytuacje błędne:

```php
http_response_code(404);

echo json_encode([
    "status" => "error",
    "message" => "Currency not found"
]);
```

---

## 8. Kody odpowiedzi HTTP

Dobre API powinno używać kodów HTTP:

* `200` – sukces
* `400` – błędne dane wejściowe
* `404` – brak danych
* `500` – błąd serwera

Przykład:

```php
http_response_code(400);
```

---

## 9. Struktura projektu

Minimalna struktura:

```
/api
   api.php
/config
   db.php
```

Można wydzielić połączenie z bazą do osobnego pliku i użyć `require`.

---

To wszystko pozwala zbudować własne, działające REST-owe API w czystym PHP.
