### PHP Session: Przykład i Omówienie

#### Co to jest sesja w PHP?

Sesja w PHP umożliwia przechowywanie danych na serwerze dla danego użytkownika podczas jego interakcji z witryną. Każdy użytkownik ma swoją unikalną sesję identyfikowaną przez identyfikator sesji, który jest przechowywany po stronie klienta (np. w ciasteczku).

#### Dlaczego używamy sesji?

Sesje są przydatne, gdy chcemy przechowywać dane o użytkowniku pomiędzy przeładowaniami strony (np. informacje o zalogowanym użytkowniku, zawartość koszyka w sklepie internetowym itp.). Pozwalają one również zwiększyć bezpieczeństwo w porównaniu do przechowywania informacji bezpośrednio w ciasteczkach.

---

#### Przykład prostego skryptu z sesją w PHP

Poniżej znajduje się prosty przykład, który ilustruje, jak utworzyć i zarządzać sesją w PHP. W tym przypadku przechowujemy liczbę odświeżeń strony dla danego użytkownika.

**Kod PHP:**

```php
<?php
session_start(); // Rozpoczynamy sesję

// Sprawdzamy, czy zmienna sesyjna 'licznik' istnieje
if (isset($_SESSION['licznik'])) {
    $_SESSION['licznik']++; // Zwiększamy licznik o 1
} else {
    $_SESSION['licznik'] = 1; // Ustawiamy licznik na 1, jeśli jeszcze nie istnieje
}

// Wyświetlamy liczbę odwiedzin
echo "Liczba odświeżeń strony: " . $_SESSION['licznik'];
?>
```

#### Omówienie działania skryptu:

1. **Rozpoczęcie sesji**:
   ```php
   session_start();
   ```
   Zawsze zaczynamy od `session_start()`, co pozwala PHP na dostęp do danych sesji. Ta funkcja musi być wywołana przed jakimkolwiek wyjściem HTML czy nagłówkami.

2. **Sprawdzenie i modyfikacja zmiennej sesyjnej**:
   - Używamy zmiennej sesyjnej `$_SESSION['licznik']`, aby przechowywać liczbę odświeżeń strony.
   - Jeśli zmienna już istnieje, zwiększamy jej wartość o 1 (`$_SESSION['licznik']++`).
   - Jeśli zmienna nie istnieje (np. przy pierwszym wejściu na stronę), ustawiamy ją na wartość 1.

3. **Wyświetlenie licznika**:
   - Na koniec wyświetlamy liczbę odświeżeń strony.

#### Przeładowanie strony

Po każdym odświeżeniu strony wartość zmiennej `$_SESSION['licznik']` jest zwiększana. Gdy użytkownik zamyka przeglądarkę i otwiera ją ponownie, sesja może być kontynuowana (jeśli ciasteczko sesji jest jeszcze ważne) lub może zostać od nowa utworzona.

#### Działanie skryptu

1. **Pierwsze załadowanie strony**:
   - Zmienna `$_SESSION['licznik']` jest tworzona i ustawiana na 1.
   - Wyświetla się informacja: *Liczba odświeżeń strony: 1*.

2. **Kolejne przeładowania**:
   - Zmienna `$_SESSION['licznik']` jest zwiększana o 1 przy każdym odświeżeniu.
   - Użytkownik widzi aktualizowaną liczbę odświeżeń.

---

### Uwagi
- Sesje są przechowywane na serwerze, co oznacza, że dane te nie są widoczne dla użytkownika.
- Warto pamiętać, że sesje PHP wygasają po określonym czasie, lub po zamknięciu przeglądarki (chyba że sesja jest przedłużona przez ciasteczka).

Dzięki sesjom możemy więc w prosty sposób zachować dane dla użytkownika pomiędzy przeładowaniami strony bez konieczności przechowywania ich w ciasteczkach po stronie klienta.
