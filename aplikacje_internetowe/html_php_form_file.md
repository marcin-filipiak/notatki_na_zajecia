### Formularz HTML z Przesyłaniem Pliku

Plik: `form.html`

Formularz HTML umożliwiający wyłącznie przesyłanie pliku na serwer.

```html
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Przesyłanie Pliku</title>
</head>
<body>
    <h2>Prześlij Plik</h2>
    <form action="save.php" method="POST" enctype="multipart/form-data">
        <!-- Dołącz plik -->
        <label for="plik">Wybierz plik:</label>
        <input type="file" id="plik" name="plik" required><br><br>

        <input type="submit" value="Wyślij">
    </form>
</body>
</html>
```

---

### PHP - Odbiór i Zapis Pliku na Serwerze

Plik: `save.php`

Skrypt PHP odbiera plik przesłany przez formularz i zapisuje go na serwerze w folderze `pliki`.

```php
<?php
// Sprawdzanie, czy formularz został wysłany metodą POST
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // Sprawdzenie, czy plik został przesłany bez błędów
    if (isset($_FILES['plik']) && $_FILES['plik']['error'] == 0) {
        $plik_nazwa = $_FILES['plik']['name'];  // Nazwa pliku
        $plik_tmp = $_FILES['plik']['tmp_name'];  // Tymczasowa lokalizacja pliku

        // Definiowanie folderu, do którego plik ma być przeniesiony
        $folder = 'pliki/';
        if (!is_dir($folder)) {
            mkdir($folder, 0777, true);  // Tworzenie folderu, jeśli nie istnieje
        }

        // Pełna ścieżka, gdzie plik zostanie zapisany
        $plik_sciezka = $folder . basename($plik_nazwa);

        // Przeniesienie pliku z folderu tymczasowego do docelowego folderu "pliki"
        if (move_uploaded_file($plik_tmp, $plik_sciezka)) {
            echo "Plik został przesłany pomyślnie. Zapisano jako: $plik_sciezka";
        } else {
            echo "Wystąpił problem z przesyłaniem pliku.";
        }
    } else {
        echo "Błąd podczas przesyłania pliku.";
    }
}
?>
```

---
- Formularz HTML z `enctype="multipart/form-data"` pozwala na przesyłanie plików.
- W PHP plik jest odbierany przez tablicę `$_FILES`, a zapis odbywa się za pomocą funkcji `move_uploaded_file()`, która przenosi plik z folderu tymczasowego na serwer.
- Zawsze trzeba sprawdzić, czy plik przesłano bez błędów oraz upewnić się, że folder do zapisu istnieje.
