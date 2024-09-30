Oto przykład formularza HTML wysyłającego dane metodą POST, zawierającego wymagane pola:

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
    <form action="/submit" method="POST" enctype="multipart/form-data">
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
