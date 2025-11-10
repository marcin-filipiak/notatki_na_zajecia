## 📘 Treść zadania egzaminacyjnego

**Temat:**
Stwórz prostą aplikację webową w PHP, która pozwala użytkownikowi dodawać produkty do listy zakupów. W tabeli wyświetl produkty, a JS umożliwia **podświetlenie wybranego wiersza w tabeli po kliknięciu**. Wszystko w jednym pliku `shopping.php`.

---

### 1. Wymagania funkcjonalne

1. Utwórz w bazie danych MySQL (`egzamin`) tabelę `shopping_list`:

   * `id` – INT, AUTO_INCREMENT, klucz główny
   * `product` – VARCHAR(100)
   * `quantity` – INT
   * `added_at` – DATETIME z domyślnym CURRENT_TIMESTAMP

2. W pliku `shopping.php`:

   * połączenie z bazą danych (`mysqli`),
   * formularz HTML z polami: nazwa produktu + ilość,
   * zapis danych do bazy po wysłaniu formularza,
   * wyświetlenie wszystkich produktów w tabeli: Nazwa, Ilość, Data dodania.

3. JavaScript:

   * po kliknięciu na wiersz w tabeli wiersz zostaje podświetlony (zmiana koloru tła),
   * tylko wizualna zmiana, **bez AJAX i bez zmiany w bazie**.

4. Walidacja:

   * JS sprawdza, czy pola formularza nie są puste i czy ilość jest większa niż 0,
   * PHP ponownie sprawdza poprawność danych (niepuste pola, ilość > 0).

5. Stylizacja:

   * prosty wygląd tabeli i formularza, kolory, marginesy, ramki.

---

### 2. Wymagania techniczne

* Wszystko w jednym pliku `shopping.php`.
* Połączenie z bazą: `new mysqli("localhost", "root", "", "egzamin");`
* Brak frameworków, wszystkie elementy w jednym pliku.

---

### 3. Kryteria oceniania (100 punktów)

| Kryterium                     | Opis                                    | Punkty |
| ----------------------------- | --------------------------------------- | ------ |
| 1. Połączenie z bazą danych   | `mysqli` działa poprawnie               | 10     |
| 2. Tworzenie i użycie tabeli  | INSERT i SELECT działają poprawnie      | 10     |
| 3. Dodawanie danych (PHP)     | Formularz zapisuje dane do bazy         | 10     |
| 4. Walidacja (JS)             | Sprawdzenie pustych pól i ilości > 0    | 10     |
| 5. Walidacja (PHP)            | Sprawdzenie pól po stronie serwera      | 10     |
| 6. Wyświetlanie danych        | Produkty wyświetlane w tabeli           | 10     |
| 7. Sortowanie                 | Produkty od najnowszych do najstarszych | 5      |
| 8. Podświetlenie wiersza (JS) | Kliknięcie na wiersz zmienia kolor tła  | 10     |
| 9. Wygląd (CSS)               | Formularz i tabela czytelne             | 10     |
| 10. Struktura HTML            | Poprawny `doctype`, head, body          | 5      |
| 11. Czytelność kodu           | Wcięcia, komentarze, przejrzystość kodu | 5      |
| 12. Działanie całości         | Brak błędów, wszystko działa poprawnie  | 10     |

**Razem: 100 pkt**

---

### 4. Wskazówki dla ucznia

* Formularz HTML z polami `product` i `quantity`.
* Wyświetlanie produktów w tabeli HTML z nagłówkami: Nazwa, Ilość, Data dodania.
* JS: po kliknięciu na wiersz wiersz zmienia kolor tła (`background-color`) → tylko zmiana wizualna, **bez zmian w bazie**.
* Walidacja JS: pola nie mogą być puste, ilość > 0.
* Walidacja PHP: to samo sprawdzenie po stronie serwera.

---

### 5. Ocena

| Procent zdobytych punktów | Ocena |
| ------------------------- | ----- |
| 0–49%                     | 1     |
| 50–64%                    | 2     |
| 65–79%                    | 3     |
| 80–89%                    | 4     |
| 90–100%                   | 5     |

