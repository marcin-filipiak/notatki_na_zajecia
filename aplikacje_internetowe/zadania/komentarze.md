## 📘 Treść zadania egzaminacyjnego

**Temat:**
Stwórz prostą aplikację webową umożliwiającą dodawanie i wyświetlanie komentarzy użytkowników.
Wszystko ma być zawarte w jednym pliku `index.php`.

---

### 1. Wymagania funkcjonalne

1. Utwórz w bazie danych MySQL (nazwa: `egzamin`) tabelę `comments` o strukturze:

   * `id` – INT, AUTO_INCREMENT, klucz główny,
   * `author` – VARCHAR(50),
   * `content` – TEXT,
   * `created_at` – DATETIME.

2. W pliku `index.php` należy:

   * wykonać **połączenie z bazą danych** przy użyciu obiektu `mysqli`,
   * umożliwić użytkownikowi **dodanie nowego komentarza** za pomocą formularza HTML,
   * zapisać dane do bazy po wysłaniu formularza,
   * wyświetlić wszystkie komentarze w tabeli HTML od najnowszego do najstarszego.

3. Walidacja:

   * sprawdzić po stronie przeglądarki (JavaScript), czy pola formularza nie są puste,
   * po stronie serwera (PHP) ponownie zweryfikować dane przed zapisem.

4. Stylizacja (CSS):

   * dodać prosty wygląd formularza i tabeli: ramki, tło, odstępy, kolory.

---

### 2. Wymagania techniczne

* Użyj **jednego pliku PHP** – wszystkie elementy (HTML, CSS, JS, PHP) mają znajdować się w `index.php`.
* Połączenie z bazą danych powinno być zrealizowane przy użyciu:
  `new mysqli("localhost", "root", "", "egzamin");`
* Nie należy korzystać z frameworków.
* Użycie stylów inline (atrybut `style`) jest dopuszczalne, ale premiowane będzie użycie sekcji `<style>`.

---

### 3. Kryteria oceniania (100 punktów)

| Kryterium                        | Opis                                                            | Punkty |
| -------------------------------- | --------------------------------------------------------------- | ------ |
| **1. Połączenie z bazą danych**  | Poprawne utworzenie obiektu `mysqli`, obsługa błędu połączenia  | 10     |
| **2. Tworzenie i użycie tabeli** | Poprawne zapytania SQL `CREATE TABLE`, `INSERT`, `SELECT`       | 10     |
| **3. Dodawanie danych (PHP)**    | Dane z formularza są poprawnie zapisywane do bazy               | 10     |
| **4. Walidacja (JavaScript)**    | Sprawdzenie pól `author` i `content` przed wysłaniem formularza | 10     |
| **5. Walidacja (PHP)**           | Dane są filtrowane/sanitizowane po stronie serwera              | 10     |
| **6. Wyświetlanie danych**       | Dane z bazy są poprawnie wypisywane w tabeli                    | 10     |
| **7. Sortowanie**                | Komentarze wyświetlane od najnowszego                           | 5      |
| **8. Wygląd (CSS)**              | Użycie podstawowych stylów (np. kolor, margines, ramka, tło)    | 10     |
| **9. Struktura HTML**            | Poprawna struktura dokumentu (doctype, head, body)              | 10     |
| **10. Czytelność kodu**          | Wcięcia, komentarze, przejrzystość                              | 5      |
| **11. Działanie całości**        | Brak błędów runtime, poprawny przebieg dodania i wyświetlenia   | 10     |

**Razem: 100 pkt**

---

### 4. Przeliczanie punktów na ocenę

| Procent | Ocena |
| ------- | ----- |
| 0–49%   | 1     |
| 50–64%  | 2     |
| 65–79%  | 3     |
| 80–89%  | 4     |
| 90–100% | 5     |

---

### 5. Materiały, które zdający może wykorzystać

* Edytor kodu (np. Visual Studio Code, Geany)
* Przeglądarka internetowa
* phpMyAdmin / terminal MySQL
* Dokumentacja PHP, HTML, CSS, JavaScript (offline)
