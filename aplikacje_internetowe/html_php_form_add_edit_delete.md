# Dodawanie, Wyświetlanie, Edycja, Usuwanie

Przykład zawiera podstawowe funkcjonalności każdej aplikacji internetowej.


## Plik index.php

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

// Usuwanie rekordu
if (isset($_GET['delete'])) {
    $id = $_GET['delete'];
    $conn->query("DELETE FROM users WHERE id = $id");
}

// Funkcja pobierająca dane użytkownika do edycji
function getUser($conn, $id) {
    $result = $conn->query("SELECT * FROM users WHERE id = $id");
    return $result->fetch_assoc();
}

// Dodawanie lub edytowanie rekordu
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $id = $_POST['id'];
    $imie = $_POST['imie'];
    $kolor = $_POST['kolor'];

    if ($id) {
        // Aktualizacja istniejącego rekordu
        $conn->query("UPDATE users SET imie = '$imie', kolor = '$kolor' WHERE id = $id");
    } else {
        // Dodanie nowego rekordu
        $conn->query("INSERT INTO users (imie, kolor) VALUES ('$imie', '$kolor')");
    }
}


// Pobieranie wszystkich danych po wykonaniu: edycji, kasowania i dodawania
$result = $conn->query("SELECT * FROM users");

?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>Lista użytkowników</title>
</head>
<body>
    <h1>Lista użytkowników</h1>
    
    <!-- Formularz do dodawania/edytowania użytkownika -->
    <form action="index.php" method="POST">
        <input type="hidden" name="id" value="<?= isset($_GET['edit']) ? $_GET['edit'] : '' ?>">
        <label for="imie">Imię:</label>
        <input type="text" name="imie" value="<?= isset($_GET['edit']) ? getUser($conn, $_GET['edit'])['imie'] : '' ?>" required>
        <label for="kolor">Kolor:</label>
        <input type="text" name="kolor" value="<?= isset($_GET['edit']) ? getUser($conn, $_GET['edit'])['kolor'] : '' ?>" required>
        <button type="submit">Zapisz</button>
    </form>

    <!-- Tabela użytkowników -->
    <table border="1">
        <tr>
            <th>Imię</th>
            <th>Kolor</th>
            <th>Akcje</th>
        </tr>
        <?php while($user = $result->fetch_assoc()): ?>
        <tr>
            <td><?= $user['imie'] ?></td>
            <td><?= $user['kolor'] ?></td>
            <td>
                <a href="index.php?edit=<?= $user['id'] ?>">Edytuj</a>
                <a href="index.php?delete=<?= $user['id'] ?>" onclick="return confirm('Czy na pewno chcesz usunąć ten rekord?')">Usuń</a>
            </td>
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

## Struktura bazy danych

```sql
CREATE TABLE users (
    id INT(11) AUTO_INCREMENT PRIMARY KEY,
    imie VARCHAR(255) NOT NULL,
    kolor VARCHAR(255) NOT NULL
);

```

###  Wyjaśnienie kodu PHP - obsługa operacji CRUD

Ten skrypt PHP demonstruje, jak realizować podstawowe operacje CRUD (Create, Read, Update, Delete) na danych użytkowników za pomocą formularzy HTML oraz zapytań SQL. Kluczowymi elementami są różnice w użyciu metod HTTP (GET i POST), operacje na bazie danych, oraz sposób prezentacji danych w formularzach i tabelach.

#### 1. **Połączenie z bazą danych**
Na samym początku skryptu jest zdefiniowane połączenie z bazą danych MySQL:

```php
$conn = new mysqli($host, $user, $password, $dbname);
```

Jeśli połączenie się nie powiedzie, zostanie wyświetlony komunikat o błędzie:

```php
if ($conn->connect_error) {
    die("Połączenie nieudane: " . $conn->connect_error);
}
```

To kluczowy krok, ponieważ bez nawiązania połączenia z bazą, żadne operacje na danych nie mogą być wykonane.

#### 2. **Obsługa metod GET i POST**

##### **Metoda GET**
Metoda GET jest używana, gdy chcemy przekazać dane za pomocą adresu URL. W tym przypadku GET służy do **pobierania danych** lub usuwania rekordu.
- **Usuwanie rekordu**: Sprawdzanie, czy użytkownik kliknął przycisk "Usuń", odbywa się przy pomocy `$_GET['delete']`, co oznacza, że dane (id rekordu) są przekazane w URL:

```php
if (isset($_GET['delete'])) {
    $id = $_GET['delete'];
    $conn->query("DELETE FROM users WHERE id = $id");
}
```

- **Edycja rekordu**: Podobnie, metoda GET jest używana, gdy użytkownik chce edytować rekord. W tym przypadku `$_GET['edit']` przekazuje ID użytkownika, którego dane mają zostać wyświetlone w formularzu:

```php
<input type="hidden" name="id" value="<?= isset($_GET['edit']) ? $_GET['edit'] : '' ?>">
```

Dzięki temu formularz wie, czy ma wypełnić dane do edycji, czy dodać nowego użytkownika.

##### **Metoda POST**
Metoda POST jest używana, gdy użytkownik wysyła dane z formularza. Używamy jej do **dodawania** lub **aktualizowania** rekordu w bazie. 

```php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $id = $_POST['id'];
    $imie = $_POST['imie'];
    $kolor = $_POST['kolor'];
```

Wartości te są przesyłane z formularza do serwera, gdzie są następnie przetwarzane. Sprawdzamy, czy przesłano identyfikator użytkownika (`id`):
- Jeśli tak, to aktualizujemy istniejący rekord (operacja UPDATE),
- Jeśli nie, to dodajemy nowego użytkownika (operacja INSERT).

#### 3. **Dodawanie i edytowanie użytkownika**
Cała logika dla operacji dodawania i edytowania znajduje się wewnątrz bloku `if ($_SERVER['REQUEST_METHOD'] == 'POST')`. Jeśli formularz jest przesyłany, dane użytkownika są pobierane z pól formularza:

```php
$imie = $_POST['imie'];
$kolor = $_POST['kolor'];
```

Jeśli ID jest obecne, oznacza to, że mamy do czynienia z edycją, i wtedy aktualizujemy istniejący rekord w bazie danych:

```php
$conn->query("UPDATE users SET imie = '$imie', kolor = '$kolor' WHERE id = $id");
```

W przeciwnym razie tworzymy nowy rekord za pomocą zapytania `INSERT`:

```php
$conn->query("INSERT INTO users (imie, kolor) VALUES ('$imie', '$kolor')");
```

#### 4. **Formularz HTML: Dodawanie i edycja**
Formularz HTML jest używany zarówno do dodawania, jak i edytowania użytkownika. W przypadku edycji, pola formularza są automatycznie wypełniane danymi wybranego użytkownika:

```php
<input type="text" name="imie" value="<?= isset($_GET['edit']) ? getUser($conn, $_GET['edit'])['imie'] : '' ?>" required>
<input type="text" name="kolor" value="<?= isset($_GET['edit']) ? getUser($conn, $_GET['edit'])['kolor'] : '' ?>" required>
```

Funkcja `getUser()` pobiera dane użytkownika o określonym ID z bazy danych:

```php
function getUser($conn, $id) {
    $result = $conn->query("SELECT * FROM users WHERE id = $id");
    return $result->fetch_assoc();
}
```

#### 5. **Wyświetlanie danych (READ)**
Po każdej operacji (dodanie, edycja, usunięcie) dane są odczytywane z bazy danych i wyświetlane w tabeli HTML. Pobranie danych odbywa się za pomocą zapytania SQL:

```php
$result = $conn->query("SELECT * FROM users");
```

Następnie dane są wyświetlane dynamicznie w pętli:

```php
<?php while($user = $result->fetch_assoc()): ?>
<tr>
    <td><?= $user['imie'] ?></td>
    <td><?= $user['kolor'] ?></td>
    <td>
        <a href="index.php?edit=<?= $user['id'] ?>">Edytuj</a>
        <a href="index.php?delete=<?= $user['id'] ?>" onclick="return confirm('Czy na pewno chcesz usunąć ten rekord?')">Usuń</a>
    </td>
</tr>
<?php endwhile; ?>
```

#### 6. **Usuwanie użytkownika**
Operacja usuwania jest aktywowana przez kliknięcie linku "Usuń", który przekazuje ID rekordu do usunięcia za pomocą metody GET. Po kliknięciu, użytkownik musi potwierdzić swoją decyzję (okno dialogowe), a następnie rekord zostaje usunięty:

```php
<a href="index.php?delete=<?= $user['id'] ?>" onclick="return confirm('Czy na pewno chcesz usunąć ten rekord?')">Usuń</a>
```

#### 7. **Zamknięcie połączenia z bazą danych**
Na końcu skryptu połączenie z bazą danych zostaje zamknięte, aby zwolnić zasoby serwera:

```php
$conn->close();
```

### Podsumowanie
Ten skrypt demonstruje jak w prosty sposób za pomocą PHP i MySQL zrealizować aplikację, która umożliwia:
- Dodawanie nowych użytkowników (metoda POST),
- Edytowanie istniejących (GET do pobrania danych, POST do zapisania zmian),
- Wyświetlanie wszystkich użytkowników (metoda GET i zapytanie SELECT),
- Usuwanie użytkowników (GET i zapytanie DELETE).

Całość działa w oparciu o interakcje z formularzem i tabelą HTML.
