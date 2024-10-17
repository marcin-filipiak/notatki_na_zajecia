### Notatka na zajęcia: Wprowadzenie do XAMPP i Tworzenie Pierwszej Strony Internetowej

---

#### 1. **Czym jest XAMPP?  
XAMPP** to darmowy pakiet oprogramowania, który umożliwia lokalne uruchamianie serwera WWW na komputerze. Zawiera:
- **Apache** (serwer WWW),
- **MySQL/MariaDB** (baza danych),
- **PHP** (język skryptowy do tworzenia dynamicznych stron internetowych),
- **Perl** oraz inne przydatne narzędzia.

XAMPP jest szczególnie przydatny do testowania stron i aplikacji internetowych na komputerze lokalnym przed ich wdrożeniem na serwer produkcyjny.

---

#### 2. **Gdzie znajdują się pliki HTML i PHP w XAMPP (na Windows)?  
Po zainstalowaniu XAMPP, główny folder serwera WWW znajduje się w folderze `htdocs`. Domyślna ścieżka to:**

```
C:\xampp\htdocs\
```

W tym folderze umieszczamy pliki HTML, PHP i inne zasoby naszej strony internetowej.

---

#### 3. **Jak otworzyć stronę w przeglądarce z localhost?  
Aby otworzyć stronę lokalnie, wykonaj poniższe kroki:**

1. **Uruchom XAMPP:** Otwórz **XAMPP Control Panel** i wciśnij przycisk **Start** obok serwera **Apache**.
2. **Umieść plik HTML lub PHP w folderze `htdocs`.**
3. **W przeglądarce wpisz adres:**  
   ```
   http://localhost/nazwa_pliku.html
   ```  
   Jeśli plik nazywa się `index.html`, wystarczy wpisać:  
   ```
   http://localhost/
   ```

---

#### 4. **Jak napisać pierwszą stronę internetową w HTML?  
Przykładowy plik HTML:**

```html
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Moja Pierwsza Strona</title>
</head>
<body>
    <h1>Witaj na mojej pierwszej stronie!</h1>
    <p>To jest przykładowy tekst.</p>
</body>
</html>
```

---

#### 5. **Gdzie umieścić plik HTML w XAMPP?**

1. **Zapisz powyższy kod jako plik o nazwie np. `index.html`.**
2. **Skopiuj plik do folderu `htdocs`, który znajduje się w katalogu instalacyjnym XAMPP, np.**  
   ```
   C:\xampp\htdocs\
   ```

---

#### 6. **Jak uruchomić stronę?**

1. Otwórz **XAMPP Control Panel** i uruchom **Apache**.
2. Otwórz przeglądarkę i wpisz:  
   ```
   http://localhost/index.html
   ```

Twoja pierwsza strona internetowa powinna się teraz wyświetlić w przeglądarce!
