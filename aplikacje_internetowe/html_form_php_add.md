Przykład zapisu imienia i nazwiska do bazy danych w PHP, używając klasy `mysqli` z podejściem obiektowym, bez przygotowywania zapytań. Cały kod znajduje się w pliku `index.php`, który zawiera formularz oraz kod zapisujący dane do bazy danych.

### Krok 1: Upewnij się, że masz bazę danych, np. `test_db`, i tabelę `users`:

```sql
CREATE DATABASE test_db;
USE test_db;
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    firstname VARCHAR(50),
    lastname VARCHAR(50)
);
```

### Krok 2: Utwórz plik `index.php` i umieść w nim poniższy kod:

```php
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>Formularz zapisu do bazy danych</title>
</head>
<body>

<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Zmienne do połączenia z bazą danych
    $servername = 'localhost';
    $username = 'root';
    $password = '';
    $dbname = 'test_db';

    // Ustanowienie połączenia z bazą danych
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Sprawdzenie połączenia
    if ($conn->connect_error) {
        die("Błąd połączenia: " . $conn->connect_error);
    }

    // Pobranie danych z formularza
    $firstname = $conn->real_escape_string($_POST['firstname']);
    $lastname = $conn->real_escape_string($_POST['lastname']);

    // Wykonanie zapytania do bazy
    $sql = "INSERT INTO users (firstname, lastname) VALUES ('$firstname', '$lastname')";

    if ($conn->query($sql) === TRUE) {
        echo "Dane zapisane pomyślnie!";
    } else {
        echo "Błąd zapisu danych: " . $conn->error;
    }

    // Zamknięcie połączenia
    $conn->close();
}
?>

<h2>Wprowadź swoje imię i nazwisko</h2>
<form method="POST" action="">
    <label for="firstname">Imię:</label>
    <input type="text" id="firstname" name="firstname" required><br><br>
    <label for="lastname">Nazwisko:</label>
    <input type="text" id="lastname" name="lastname" required><br><br>
    <input type="submit" value="Zapisz">
</form>

</body>
</html>
```

### Wyjaśnienie kodu:

1. **Formularz HTML**:
   Formularz zawiera pola dla imienia i nazwiska oraz przycisk „Zapisz”. Dane są przesyłane metodą `POST` na tę samą stronę (`action=""`).

2. **Obsługa danych po wysłaniu**:
   Po przesłaniu formularza skrypt sprawdza, czy metoda żądania to `POST`. Następnie łączy się z bazą danych przy użyciu `new mysqli`.

3. **Połączenie i zapis do bazy**:
   - Ustawiane są parametry połączenia do bazy.
   - `real_escape_string` zabezpiecza dane przed atakami SQL Injection.
   - Wykonanie zapytania `INSERT` przy użyciu `query`.
   - W przypadku sukcesu wyświetlany jest komunikat o zapisaniu danych, a w przeciwnym razie komunikat o błędzie.

4. **Zamknięcie połączenia**:
   Na końcu połączenie z bazą danych jest zamykane.

Ten kod ilustruje, jak zapisać imię i nazwisko do bazy danych z wykorzystaniem obiektowego podejścia w `mysqli`.
