# Sprawdzian PHP - Operacje na bazie danych MySQLi

1. Uzupełnij kod połączenia z bazą danych MySQLi:
```
$host = '________';
$dbname = '________';
$user = '________';
$password = '________';
$conn = new mysqli($host, $user, $password, $dbname);
```

2. Jak sprawdzisz, czy połączenie z bazą danych się powiodło? Uzupełnij brakujący kod:
```
if ($conn->________) {
    die("Połączenie nieudane: " . $conn->________);
}
```

3. Uzupełnij kod, aby usunąć rekord z tabeli 'users' o identyfikatorze podanym w zmiennej $id:
```
$conn->________("DELETE FROM users WHERE id = $id");
```

4. Napisz kod, który pobiera dane użytkownika o podanym id z tabeli 'users' i zwraca jako tablicę asocjacyjną:
```
function getUser($conn, $id) {
    $result = $conn->________("SELECT * FROM users WHERE id = $id");
    return $result->________();
}
```

5. Uzupełnij kod formularza do dodawania/edytowania użytkownika:
```
<form action="________" method="POST">
    <input type="hidden" name="id" value="<?= isset($_GET['________']) ? $_GET['________'] : '' ?>">
    <label for="imie">Imię:</label>
    <input type="text" name="imie" value="<?= isset($_GET['edit']) ? getUser($conn, $_GET['edit'])['imie'] : '' ?>" required>
    <label for="kolor">Kolor:</label>
    <input type="text" name="kolor" value="<?= isset($_GET['edit']) ? getUser($conn, $_GET['edit'])['kolor'] : '' ?>" required>
    <button type="submit">Zapisz</button>
</form>
```

6. Uzupełnij kod zapisu nowego rekordu do bazy danych:
```
$conn->________("INSERT INTO users (imie, kolor) VALUES ('$imie', '$kolor')");
```

7. Uzupełnij kod, aby zaktualizować dane użytkownika w bazie danych:
```
$conn->________("UPDATE users SET imie = '$imie', kolor = '$kolor' WHERE id = $id");
```

8. Jak zamkniesz połączenie z bazą danych? Napisz brakujący kod:
```
$conn->________();
```

9. Wyjaśnij, do czego służy parametr 'required' w formularzu HTML.

10. Co się stanie, jeśli w zapytaniu SQL użyjesz danych pochodzących bezpośrednio z formularza bez walidacji?

11. Wyjaśnij, co robi funkcja fetch_assoc() w kontekście zapytania SQL.

12. Dlaczego w kodzie usuwania rekordu z tabeli 'users' warto użyć przygotowanego zapytania zamiast bezpośredniego wstrzyknięcia zmiennej $id?

13. W jaki sposób można zabezpieczyć aplikację PHP przed atakami typu SQL Injection?

14. Jakie znaczenie ma metoda POST w formularzu HTML? Czy można użyć metody GET?

15. Uzupełnij kod zapytania SELECT, aby wybrać tylko użytkowników, których kolor to 'niebieski':
```
$conn->________("SELECT * FROM users WHERE kolor = '________'");
```

16. Opisz, co robi kod poniżej:
```
<a href="index.php?delete=<?= $user['id'] ?>" onclick="return confirm('Czy na pewno chcesz usunąć ten rekord?')">Usuń</a>
```

17. W jaki sposób można poprawić wydajność zapytań do bazy danych w PHP?

18. Co oznacza i dlaczego warto stosować 'strict mode' w konfiguracji MySQL?

19. Jakie są alternatywne metody komunikacji z bazą danych MySQL w PHP oprócz MySQLi?

20. Dlaczego warto stosować transakcje w operacjach na bazie danych, np. przy jednoczesnym dodawaniu i aktualizowaniu danych?

------------

# Odpowiedzi do sprawdzianu PHP - Operacje na bazie danych MySQLi:

1. 
```
$host = 'localhost';
$dbname = 'your_database_name';
$user = 'your_username';
$password = 'your_password';
$conn = new mysqli($host, $user, $password, $dbname);
```

2. 
```
if ($conn->connect_error) {
    die("Połączenie nieudane: " . $conn->connect_error);
}
```

3. 
```
$conn->query("DELETE FROM users WHERE id = $id");
```

4. 
```
function getUser($conn, $id) {
    $result = $conn->query("SELECT * FROM users WHERE id = $id");
    return $result->fetch_assoc();
}
```

5. 
```
<form action="index.php" method="POST">
    <input type="hidden" name="id" value="<?= isset($_GET['edit']) ? $_GET['edit'] : '' ?>">
```

6. 
```
$conn->query("INSERT INTO users (imie, kolor) VALUES ('$imie', '$kolor')");
```

7. 
```
$conn->query("UPDATE users SET imie = '$imie', kolor = '$kolor' WHERE id = $id");
```

8. 
```
$conn->close();
```

9. Atrybut `required` w formularzu HTML wymusza na użytkowniku wypełnienie pola przed wysłaniem formularza.

10. Wykorzystanie danych z formularza bez walidacji może prowadzić do ataków SQL Injection, umożliwiając osobom niepowołanym modyfikację bazy danych.

11. Funkcja `fetch_assoc()` pobiera jeden rekord z wyniku zapytania SQL jako tablicę asocjacyjną, gdzie kluczami są nazwy kolumn.

12. Użycie przygotowanego zapytania zapobiega SQL Injection, ponieważ dane są traktowane jako parametry, a nie część kodu SQL.

13. Aby zabezpieczyć aplikację przed SQL Injection, można:
   - Używać przygotowanych zapytań (`prepared statements`).
   - Oczyszczać dane wejściowe (`mysqli_real_escape_string()`).
   - Walidować dane przed przetwarzaniem.

14. Metoda POST przesyła dane w ciele zapytania, co jest bezpieczniejsze niż metoda GET, która wyświetla dane w adresie URL. Można użyć GET, ale dane będą mniej bezpieczne.

15. 
```
$conn->query("SELECT * FROM users WHERE kolor = 'niebieski'");
```

16. Kod usuwa rekord użytkownika na podstawie identyfikatora `id`. Przed wykonaniem operacji użytkownik jest proszony o potwierdzenie za pomocą okna dialogowego `confirm()`.

17. Wydajność można poprawić przez:
   - Używanie indeksów na kluczach tabel.
   - Używanie ograniczenia `LIMIT` w zapytaniach.
   - Buforowanie wyników.
   - Optymalizację zapytań SQL.

18. 'Strict mode' w MySQL sprawia, że błędy SQL są traktowane bardziej rygorystycznie, co zapobiega nieprzewidzianym błędom w działaniu aplikacji.

19. Alternatywy dla MySQLi to:
   - PDO (PHP Data Objects) — wspiera różne bazy danych.
   - Stare rozszerzenie MySQL (już niezalecane i usunięte z PHP 7).

20. Transakcje pozwalają na grupowanie operacji w jeden blok, zapewniając integralność danych. W razie błędu można wycofać całą transakcję (`ROLLBACK`).
