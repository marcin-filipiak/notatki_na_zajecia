# WordPress – podstawy

## Czym jest WordPress?
WordPress to **darmowy, otwartoźródłowy system zarządzania treścią (CMS)** oparty na PHP i MySQL. Umożliwia tworzenie stron internetowych, blogów, sklepów czy portali bez konieczności programowania od zera. Obecnie napędza ponad 40% stron w internecie.

---

## Instalacja w XAMPP (w skrócie)
1. Uruchom **XAMPP Control Panel** → włącz moduły `Apache` i `MySQL`.
2. Pobierz paczkę z [wordpress.org](https://wordpress.org) i wypakuj ją do `C:\xampp\htdocs\nazwa_projektu`.
3. Wejdź w przeglądarkę: `http://localhost/phpmyadmin` → kliknij **Nowa** → wpisz nazwę bazy (np. `wp_test`) → `UTF8_general_ci` → **Utwórz**.
4. Otwórz `http://localhost/nazwa_projektu` → uruchomi się kreator instalacji.
5. Wpisz dane bazy (nazwa, użytkownik: `root`, hasło: puste), prefix tabeli (domyślnie `wp_`), następnie ustaw login, hasło i e-mail konta admina.
6. Po zakończeniu kliknij **Zaloguj się**.

---

## Logowanie do panelu
- Adres: `http://localhost/nazwa_projektu/wp-admin` (lub `/wp-login.php`)
- Wpisz login/hasło utworzone przy instalacji.
- Po zalogowaniu trafisz do **Kokpitu** (Dashboard).

---

## Co widać w Panelu Administratora?
- **Lewy pasek nawigacyjny** – główne sekcje: Kokpit, Wpisy, Strony, Media, Wtyczki, Wygląd, Narzędzia, Ustawienia.
- **Górny pasek** – szybkie akcje, przełącznik widoku, powiadomienia, profil.
- **Główny obszar** – podsumowanie aktywności, aktualności WP, stan strony, quick draft.
- Wszystko jest responsywne i w pełni spolszczone.

---

## Wpisy vs Strony – czym się różnią?
| Cecha | **Wpisy** | **Strony** |
|-------|-----------|------------|
| Przeznaczenie | Aktualności, blog, newsy | Statyczne treści: O nas, Kontakt, Regulamin |
| Data & autor | Tak (widoczne, sortowanie chronologiczne) | Brak (nie są datowane) |
| Kategorie/Tagi | Tak | Nie |
| Hierarchia | Płaska (brak podstron) | Tak (można tworzyć strony nadrzędne/podrzędne) |
| RSS & Archiwum | Automatycznie generowane | Nie uczestniczą |

---

## Jak stworzyć menu nawigacyjne?
1. Przejdź: **Wygląd → Menu**.
2. W polu `Nazwa menu` wpisz nazwę (np. `Główne`) → **Utwórz menu**.
3. Z lewej strony zaznacz strony/wpisy/odnośniki niestandardowe → kliknij **Dodaj do menu**.
4. Przeciągnij pozycje, aby ustawić kolejność lub utwórz podmenu (wciśnięcie w prawo).
5. Na dole w `Ustawienia wyświetlania` zaznacz lokalizację obsługiwaną przez motyw (np. `Primary Menu`).
6. Kliknij **Zapisz menu**.

---

## Jak wgrać pliki (Media)?
1. Przejdź: **Media → Dodaj nowy**.
2. Przeciągnij pliki na obszar lub kliknij `Wybierz pliki`.
3. Obsługiwane formaty: obrazy (jpg, png, webp), dokumenty (pdf, doc), audio/wideo, archiwa.
4. Po wgraniu możesz edytować tytuł, opis, tekst alternatywny (ALT) oraz przyciąć/obrócić obraz.
5. Pliki można też wstawiać bezpośrednio w edytorze wpisu/strony (`+` → `Media`).

---

## Wtyczki & Motywy (skórki) – instalacja
### Wtyczki (rozbudowa funkcji)
- **Wtyczki → Dodaj nową** → wyszukaj w repozytorium lub kliknij `Wgraj wtyczkę` → wybierz plik `.zip` → `Zainstaluj teraz` → **Aktywuj**.
- Przykłady must-have: `Yoast SEO` / `RankMath`, `Wordfence`, `WP Super Cache`, `Contact Form 7`.

### Motywy (wygląd strony)
- **Wygląd → Motywy → Dodaj nowy** → przeglądaj/wgraj `.zip` → `Zainstaluj` → **Aktywuj**.
- Nowoczesne motywy korzystają z **Full Site Editing (FSE)** – edycja bloków w `Wygląd → Edytor` lub `Wygląd → Dostosuj`.
- Zawsze używaj motywu potomnego (child theme) przy modyfikacjach kodu.

---
*Notatka przygotowana pod WordPress 6.x/7.x. Interfejs i ścieżki mogą nieznacznie ewoluować, ale logika działania pozostaje stabilna.*
