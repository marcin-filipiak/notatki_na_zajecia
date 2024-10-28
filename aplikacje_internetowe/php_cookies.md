# Cookies w PHP

Cookies to niewielkie pliki przechowywane po stronie użytkownika, które mogą służyć do przechowywania danych takich jak ustawienia użytkownika czy informacje o sesji. W PHP możemy ustawiać cookies za pomocą funkcji `setcookie()`.

**Podstawowe ustawienie ciasteczka**

Przykład kodu PHP, który ustawia ciasteczko z nazwą `username` i wartością `Jan` na 1 dzień:

```php
<?php
setcookie("username", "Jan", time() + 86400); // czas życia 1 dzień (86400 sekund)

// Sprawdzamy, czy ciasteczko jest ustawione
if (isset($_COOKIE["username"])) {
    echo "Witaj ponownie, " . $_COOKIE["username"];
} else {
    echo "Ustawiono ciasteczko!";
}
?>
```

**Opis problemu: ustawienie ciasteczka i przeładowanie strony**

Jednym z typowych problemów związanych z ustawianiem cookies jest fakt, że `setcookie()` nie działa natychmiast – ciasteczko staje się dostępne dopiero przy kolejnym ładowaniu strony. Po pierwszym uruchomieniu skryptu PHP, przeglądarka dopiero otrzymuje instrukcję o utworzeniu ciasteczka, więc sprawdzenie wartości `$_COOKIE["username"]` nie zadziała od razu.

**Rozwiązanie problemu**

Aby rozwiązać ten problem i zobaczyć efekt działania ciasteczka, możemy przeładować stronę po ustawieniu ciasteczka, np. dodając mechanizm przekierowania przy pierwszym uruchomieniu:

```php
<?php
if (!isset($_COOKIE["username"])) {
    setcookie("username", "Jan", time() + 86400);
    header("Location: ".$_SERVER['PHP_SELF']); // Przeładowanie strony
    exit;
}

echo "Witaj ponownie, " . $_COOKIE["username"];
?>
```

Dzięki temu skrypt ustawia ciasteczko, a następnie przeładowuje stronę, przez co ciasteczko będzie już dostępne do odczytu przy kolejnym wywołaniu skryptu.
