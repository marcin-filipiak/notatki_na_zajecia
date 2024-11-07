# Specjalne Znaki (Special Chars) w PHP

**Specjalne znaki** to znaki, które mają szczególne znaczenie w językach programowania, jak np. znaki HTML (`<`, `>`) oraz znaki sterujące (`\n`, `\t`). W PHP możemy używać funkcji do ich obsługi, aby zapobiec problemom z bezpieczeństwem i formatowaniem tekstu.

#### 1. Funkcja `htmlspecialchars()`

Funkcja `htmlspecialchars()` zamienia specjalne znaki HTML na ich odpowiedniki w formie encji. Jest szczególnie przydatna przy wyświetlaniu danych wprowadzonych przez użytkownika, aby zapobiec atakom XSS (Cross-Site Scripting).

**Przykład:**
```php
<?php
$tekst = "<script>alert('Hello!');</script>";
$bezpiecznyTekst = htmlspecialchars($tekst);

echo $bezpiecznyTekst;  // Wyświetli: &lt;script&gt;alert('Hello!');&lt;/script&gt;
?>
```

W powyższym przykładzie `<` i `>` są zamieniane na `&lt;` i `&gt;`, dzięki czemu kod JavaScript nie zostanie wykonany, a tylko wyświetlony jako tekst.

#### 2. Funkcja `htmlentities()`

Funkcja `htmlentities()` działa podobnie do `htmlspecialchars()`, ale konwertuje więcej znaków specjalnych, takich jak cudzysłowy (`"`), apostrofy (`'`), oraz inne znaki specjalne HTML.

**Przykład:**
```php
<?php
$tekst = "\"Cytat\" z użyciem 'apostrofów'";
$bezpiecznyTekst = htmlentities($tekst);

echo $bezpiecznyTekst;  // Wyświetli: &quot;Cytat&quot; z użyciem &#039;apostrofów&#039;
?>
```

#### 3. Przydatność w praktyce

Używanie `htmlspecialchars()` i `htmlentities()` jest dobrą praktyką, szczególnie podczas pracy z danymi pochodzącymi od użytkowników. Funkcje te chronią aplikacje przed niepożądanym wykonaniem kodu HTML lub JavaScript, co poprawia bezpieczeństwo strony internetowej.
