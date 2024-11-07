
# Wprowadzenie do PHP – Praca z Formularzami

**PHP** to popularny język skryptowy wykorzystywany po stronie serwera, który pozwala na dynamiczne generowanie stron internetowych. PHP może odbierać dane przesyłane z formularzy HTML i przetwarzać je na serwerze.

#### 1. Zmienne w PHP

W PHP zmienne deklarujemy za pomocą znaku `$`. Nazwa zmiennej powinna rozpoczynać się od tego znaku, a następnie może zawierać litery, cyfry i znaki podkreślenia, ale nie może zaczynać się od cyfry.

**Przykład zmiennej:**
```php
<?php
$liczba = 5;
$tekst = "To jest tekst";
?>
```

#### 2. Odbieranie danych z formularza

Dane przesyłane z formularza można odbierać w PHP za pomocą superglobalnej tablicy `$_POST`. Formularz HTML przesyła dane do tego samego pliku, który przetwarza je w PHP.

### Przykładowa aplikacja: Dodawanie dwóch liczb

Poniżej znajduje się kod HTML z formularzem, który przesyła dwie liczby. PHP odbiera te liczby, dodaje je i wyświetla wynik. Program sprawdza też, czy wynik jest dodatni czy ujemny.

```php
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>Dodawanie liczb w PHP</title>
</head>
<body>

<h2>Dodawanie dwóch liczb</h2>
<form method="POST" action="">
    <label for="liczba1">Pierwsza liczba:</label>
    <input type="number" name="liczba1" id="liczba1" required><br><br>

    <label for="liczba2">Druga liczba:</label>
    <input type="number" name="liczba2" id="liczba2" required><br><br>

    <input type="submit" name="submit" value="Dodaj liczby">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Odbieranie wartości z formularza
    $liczba1 = $_POST['liczba1'];
    $liczba2 = $_POST['liczba2'];

    // Obliczanie sumy
    $wynik = $liczba1 + $liczba2;

    // Wyświetlanie wyniku
    echo "<h3>Wynik dodawania: $wynik</h3>";

    // Sprawdzanie, czy wynik jest dodatni czy ujemny
    if ($wynik > 0) {
        echo "<p>Wynik jest dodatni.</p>";
    } elseif ($wynik < 0) {
        echo "<p>Wynik jest ujemny.</p>";
    } else {
        echo "<p>Wynik to zero.</p>";
    }
}
?>

</body>
</html>
```

### Wyjaśnienie kodu

1. **Formularz HTML**: Składa się z dwóch pól dla liczb (`liczba1` i `liczba2`). Formularz przesyła dane metodą POST.
2. **Przetwarzanie danych w PHP**: Skrypt sprawdza, czy formularz został przesłany. Jeśli tak, odbiera wartości pól i dodaje je.
3. **Wyświetlanie wyniku**: Program wyświetla wynik dodawania i informację, czy wynik jest dodatni, ujemny, czy równy zeru.
