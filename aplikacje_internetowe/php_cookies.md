### PHP Cookies: Przykład i Omówienie

#### Co to jest cookie?

Ciasteczko (cookie) to mały plik przechowywany na komputerze użytkownika przez przeglądarkę. Pozwala on serwerowi na zapisanie i odczytanie danych użytkownika nawet po zamknięciu przeglądarki, aż do momentu wygaśnięcia ciasteczka lub jego usunięcia przez użytkownika.

#### Dlaczego używamy ciasteczek?

Ciasteczka są przydatne, gdy chcemy przechowywać dane użytkownika pomiędzy wizytami na stronie, np. preferencje, stan logowania, dane koszyka w sklepie internetowym, czy licznik odwiedzin strony.

---

#### Przykład prostego skryptu z ciasteczkiem w PHP

Poniżej znajduje się prosty przykład, który ilustruje, jak utworzyć i zarządzać ciasteczkiem w PHP. W tym przykładzie ciasteczko przechowuje liczbę odwiedzin strony.

**Kod PHP:**

```php
<?php
// Sprawdzamy, czy ciasteczko 'licznik' istnieje
if (isset($_COOKIE['licznik'])) {
    $licznik = $_COOKIE['licznik'] + 1; // Zwiększamy licznik o 1
} else {
    $licznik = 1; // Ustawiamy licznik na 1, jeśli ciasteczko jeszcze nie istnieje
}

// Ustawiamy ciasteczko 'licznik' z nową wartością i czasem wygaśnięcia 30 dni
setcookie('licznik', $licznik, time() + (30 * 24 * 60 * 60));

// Wyświetlamy liczbę odwiedzin
echo "Liczba odwiedzin: " . $licznik;
?>
```

#### Omówienie działania skryptu:

1. **Sprawdzenie ciasteczka**:
   - Używamy `$_COOKIE['licznik']`, aby sprawdzić, czy ciasteczko o nazwie `licznik` już istnieje.
   - Jeśli ciasteczko istnieje, zwiększamy jego wartość o 1.
   - Jeśli ciasteczko nie istnieje, ustawiamy zmienną `$licznik` na 1.

2. **Ustawienie ciasteczka**:
   ```php
   setcookie('licznik', $licznik, time() + (30 * 24 * 60 * 60));
   ```
   Używamy funkcji `setcookie()` do ustawienia ciasteczka:
   - Pierwszy parametr to nazwa ciasteczka (`'licznik'`).
   - Drugi parametr to jego wartość (zwiększona wartość `$licznik`).
   - Trzeci parametr określa czas wygaśnięcia ciasteczka (aktualny czas + 30 dni).

3. **Wyświetlenie wartości ciasteczka**:
   - Na koniec wyświetlamy liczbę odwiedzin strony, która jest równa wartości ciasteczka `licznik`.

#### Przeładowanie strony

Ciasteczko `licznik` zostanie zapisane w przeglądarce użytkownika i będzie dostępne pomiędzy kolejnymi przeładowaniami strony. Po każdym przeładowaniu licznik zostaje zwiększony, a ciasteczko jest ustawiane z nową wartością i terminem ważności.

#### Działanie skryptu

1. **Pierwsze załadowanie strony**:
   - Ciasteczko `licznik` jeszcze nie istnieje, więc ustawiamy zmienną `$licznik` na 1 i zapisujemy ciasteczko.
   - Użytkownik widzi komunikat: *Liczba odwiedzin: 1*.

2. **Kolejne wizyty lub przeładowania strony**:
   - Wartość ciasteczka `licznik` jest zwiększana o 1 przy każdym przeładowaniu.
   - Użytkownik widzi zaktualizowaną liczbę odwiedzin.

---

### Uwagi
- Ciasteczka są przechowywane po stronie klienta, więc ich zawartość może być przeglądana i modyfikowana przez użytkownika.
- Należy być ostrożnym przy przechowywaniu wrażliwych danych w ciasteczkach. Zazwyczaj do przechowywania informacji wymagających bezpieczeństwa, np. o sesji użytkownika, preferowane są ![sesje](php_session.md) serwerowe zamiast ciasteczek.
  
Dzięki ciasteczkom możemy więc przechowywać proste dane użytkownika pomiędzy wizytami na stronie, co pozwala na bardziej spersonalizowane i interaktywne doświadczenia.
