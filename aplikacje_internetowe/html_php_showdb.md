# Wyświetlanie danych z bazy danych

Przykład prezentuje podstawowe podejście do wyświetlania danych z bazy MySQL w PHP, z wykorzystaniem zapytania `SELECT`.

---

## Plik `index.php`

```php
<?php
// Połączenie z bazą danych MySQLi
$host = 'localhost';
$dbname = 'your_database_name';
$user = 'your_username';
$password = 'your_password';

$conn = new mysqli($host, $user, $password, $dbname);

// Sprawdzenie połączenia
if ($conn->connect_error) {
    die("Połączenie nieudane: " . $conn->connect_error);
}

// Pobieranie danych z tabeli 'products'
$result = $conn->query("SELECT * FROM products");
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>Lista produktów</title>
</head>
<body>
    <h1>Lista produktów</h1>
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Nazwa</th>
            <th>Cena</th>
        </tr>
        <?php while ($product = $result->fetch_assoc()): ?>
        <tr>
            <td><?= $product['id'] ?></td>
            <td><?= $product['name'] ?></td>
            <td><?= $product['price'] ?></td>
        </tr>
        <?php endwhile; ?>
    </table>
</body>
</html>

<?php
// Zamknięcie połączenia
$conn->close();
?>
```

---

## Struktura bazy danych

```sql
CREATE TABLE products (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    price DECIMAL(10, 2) NOT NULL
);

INSERT INTO products (name, price) VALUES
('Produkt 1', 10.99),
('Produkt 2', 15.50),
('Produkt 3', 7.30);
```

---

## Wyjaśnienie kodu PHP

### 1. **Połączenie z bazą danych**
Na początku skryptu nawiązujemy połączenie z bazą danych za pomocą klasy `mysqli`:

```php
$conn = new mysqli($host, $user, $password, $dbname);
```

Jeśli połączenie się nie powiedzie, zostanie wyświetlony komunikat o błędzie:

```php
if ($conn->connect_error) {
    die("Połączenie nieudane: " . $conn->connect_error);
}
```

### 2. **Pobieranie danych z bazy**
W celu pobrania danych z tabeli `products`, wykonujemy zapytanie SQL:

```php
$result = $conn->query("SELECT * FROM products");
```

Metoda `query` zwraca obiekt zawierający dane wynikowe, które można przetworzyć w pętli.

### 3. **Wyświetlanie danych w tabeli HTML**
Pobrane dane są wyświetlane w tabeli HTML za pomocą pętli `while`. Każdy wiersz z wyników jest przetwarzany przez `fetch_assoc()`, który zwraca dane w formie tablicy asocjacyjnej:

```php
<?php while ($product = $result->fetch_assoc()): ?>
<tr>
    <td><?= $product['id'] ?></td>
    <td><?= $product['name'] ?></td>
    <td><?= $product['price'] ?></td>
</tr>
<?php endwhile; ?>
```

Każda kolumna tabeli odpowiada polu w bazie danych (`id`, `name`, `price`).

### 4. **Zamknięcie połączenia**
Po zakończeniu pracy z bazą danych zamykamy połączenie, aby zwolnić zasoby:

```php
$conn->close();
```

---
