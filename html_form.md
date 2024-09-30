# Formularz w HTML i zapis do bazy

* form.html - formularz z danymi
* save.php - odbiór danych z formularza i zapis do bazy
* pliki - folder 

## HTML

Przykład formularza HTML wysyłającego dane metodą POST, zawierającego wymagane pola.  
Nazwa pliku form.html

```html
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formularz POST</title>
</head>
<body>
    <h2>Formularz Rejestracyjny</h2>
    <form action="save.php" method="POST" enctype="multipart/form-data">
        <!-- Imię -->
        <label for="imie">Imię:</label>
        <input type="text" id="imie" name="imie" required><br><br>

        <!-- Wzrost -->
        <label for="wzrost">Wzrost (cm):</label>
        <input type="number" id="wzrost" name="wzrost" required><br><br>

        <!-- Data urodzenia -->
        <label for="data_urodzenia">Data urodzenia:</label>
        <input type="date" id="data_urodzenia" name="data_urodzenia" required><br><br>

        <!-- Email -->
        <label for="email">Email:</label>
        <input type="email" id="email" name="email" required><br><br>

        <!-- Telefon -->
        <label for="telefon">Telefon:</label>
        <input type="tel" id="telefon" name="telefon" pattern="[0-9]{9}" required><br><br>

        <!-- Kolor włosów -->
        <label for="kolor_wlosow">Kolor włosów:</label>
        <input type="color" id="kolor_wlosow" name="kolor_wlosow" value="#000000" required><br><br>

        <!-- Hasło -->
        <label for="haslo">Hasło:</label>
        <input type="password" id="haslo" name="haslo" required><br><br>

        <!-- Dołącz plik -->
        <label for="plik">Dołącz plik:</label>
        <input type="file" id="plik" name="plik" required><br><br>

        <input type="submit" value="Wyślij">
    </form>
</body>
</html>
```

### Wyjaśnienia:
1. `action="/submit"` - wskazuje URL, do którego dane zostaną wysłane.
2. `method="POST"` - metoda wysyłania danych (POST).
3. `enctype="multipart/form-data"` - wymagane do przesyłania plików.
4. Każde pole jest opisane etykietą `label`, a odpowiednie pola formularza są oznaczone typami (np. `text`, `number`, `date`, `email`, `password`, `file`).



## Baza danych

```sql
CREATE TABLE tabela_testowa (
    id INT(11) AUTO_INCREMENT PRIMARY KEY,
    imie VARCHAR(100) NOT NULL,
    kolor VARCHAR(7) NOT NULL,
    plik_nazwa VARCHAR(255) NOT NULL,
    plik_sciezka VARCHAR(255) NOT NULL
);
```

## PHP

Odbiór danych w PHP oraz zapis do bazy danych i zapis na dysku.  
Nazwa pliku: save.php

```php
<?php
// Dane do połączenia z bazą danych
$servername = "localhost";  // Nazwa hosta (zwykle localhost dla lokalnej bazy danych)
$username = "root";  // Użytkownik bazy danych (root dla lokalnych serwerów MySQL)
$password = "";  // Hasło użytkownika (puste w tym przypadku)
$dbname = "baza_testowa";  // Nazwa bazy danych

// Połączenie z bazą danych
$conn = new mysqli($servername, $username, $password, $dbname);

// Sprawdzenie połączenia z bazą danych
if ($conn->connect_error) {
    die("Połączenie nieudane: " . $conn->connect_error);  // Jeśli połączenie się nie uda, zakończ i wyświetl błąd
}

// Sprawdzanie, czy formularz został wysłany metodą POST
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // Pobieranie danych z formularza (pole 'imie' i 'kolor_wlosow')
    $imie = $_POST['imie'];
    $kolor = $_POST['kolor_wlosow'];

    // Sprawdzenie, czy plik został przesłany bez błędów
    if (isset($_FILES['plik']) && $_FILES['plik']['error'] == 0) {
        // Pobranie nazwy pliku i jego ścieżki tymczasowej
        $plik_nazwa = $_FILES['plik']['name'];  // Nazwa pliku
        $plik_tmp = $_FILES['plik']['tmp_name'];  // Tymczasowa lokalizacja pliku

        // Definiowanie folderu, do którego plik ma być przeniesiony
        $folder = 'pliki/';
        if (!is_dir($folder)) {
            // Tworzenie folderu "pliki", jeśli jeszcze nie istnieje
            mkdir($folder, 0777, true);
        }
        // Definiowanie pełnej ścieżki, gdzie plik zostanie zapisany
        $plik_sciezka = $folder . basename($plik_nazwa);

        // Przeniesienie pliku z folderu tymczasowego do docelowego folderu "pliki"
        if (move_uploaded_file($plik_tmp, $plik_sciezka)) {
            echo "Plik został przesłany pomyślnie.";  // Komunikat o sukcesie

            // SQL - wstawienie danych do tabeli w bazie danych
            // Wstawiane są: imię, kolor, nazwa pliku oraz jego ścieżka
            $sql = "INSERT INTO tabela_testowa (imie, kolor, plik_nazwa, plik_sciezka)
                    VALUES ('$imie', '$kolor', '$plik_nazwa', '$plik_sciezka')";

            // Wykonanie zapytania SQL i sprawdzenie, czy się udało
            if ($conn->query($sql) === TRUE) {
                echo "Dane zostały zapisane w bazie danych.";  // Sukces przy zapisie do bazy
            } else {
                // Wyświetlenie błędu w przypadku problemów z zapisem
                echo "Błąd: " . $sql . "<br>" . $conn->error;
            }
        } else {
            // Komunikat, jeśli wystąpił problem podczas przenoszenia pliku
            echo "Wystąpił problem z przesyłaniem pliku.";
        }
    } else {
        // Komunikat o błędzie, jeśli plik nie został przesłany poprawnie
        echo "Błąd podczas przesyłania pliku.";
    }
}

// Zamknięcie połączenia z bazą danych
$conn->close();
?>
```
