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
    header("Location: index.php"); // Przekierowanie po usunięciu
    exit;
}

// Pobieranie wszystkich danych
$result = $conn->query("SELECT * FROM users");

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
    header("Location: index.php");
    exit;
}
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
