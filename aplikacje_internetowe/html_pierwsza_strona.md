### Notatka na zajęcia: Budowa Dokumentu HTML

---

#### 1. **Czym jest HTML?  
HTML** (HyperText Markup Language) to język znaczników używany do tworzenia stron internetowych. Pozwala opisać strukturę dokumentu, a przeglądarka internetowa interpretuje ten kod i wyświetla treść w formie wizualnej.

---

#### 2. **Struktura Dokumentu HTML  
Podstawowy szkielet dokumentu HTML wygląda następująco:**

```html
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tytuł strony</title>
</head>
<body>
    <h1>Witaj, świecie!</h1>
    <p>To jest przykładowy akapit tekstu.</p>
</body>
</html>
```

---

#### 3. **Omówienie poszczególnych elementów:**

##### **a) `<!DOCTYPE html>`**
- Deklaracja typu dokumentu (DOCTYPE) określa wersję HTML. Współczesne strony korzystają z HTML5, dlatego używamy tego zapisu.
  
##### **b) `<html>`**
- Zawiera całą treść dokumentu HTML. Oznacza początek i koniec strony internetowej.
- Atrybut `lang="pl"` określa język strony (w tym przypadku polski), co jest ważne dla przeglądarek i wyszukiwarek.

##### **c) `<head>`**
- Sekcja **head** zawiera informacje **meta** dotyczące strony, które nie są bezpośrednio widoczne dla użytkownika. Są to m.in.:
    - **`<meta charset="UTF-8">`** – kodowanie znaków, UTF-8 obsługuje większość znaków (np. polskie znaki diakrytyczne).
    - **`<meta name="viewport" content="width=device-width, initial-scale=1.0">`** – zapewnia responsywność strony (dopasowanie do różnych rozmiarów ekranów).
    - **`<title>`** – tytuł strony wyświetlany w karcie przeglądarki.

##### **d) `<body>`**
- Sekcja **body** zawiera właściwą treść strony, która będzie widoczna dla użytkownika. Możemy tu umieścić różne elementy, takie jak:
    - **Nagłówki** (np. `<h1>`, `<h2>`, ...) – od największego (`<h1>`) do najmniejszego (`<h6>`).
    - **Akapity** (`<p>`) – tekst sformatowany w bloki.
    - **Obrazy** (`<img>`) – wstawianie obrazów.
    - **Linki** (`<a>`) – umożliwiają przechodzenie do innych stron.
    - **Listy** (`<ul>`, `<ol>`) – listy punktowane (`<ul>`) lub numerowane (`<ol>`).

---

#### 4. **Komentarze w HTML  
Komentarze służą do wstawiania notatek w kodzie, które nie są wyświetlane na stronie. Używamy ich w następujący sposób:**

```html
<!-- To jest komentarz w HTML -->
```

Komentarze mogą pomóc w zrozumieniu kodu, dodawaniu opisów funkcji, a także tymczasowym wyłączaniu fragmentów kodu podczas testowania.

---

#### 5. **Podsumowanie zawartości elementów HTML**

| Element        | Opis                                                                 |
|----------------|----------------------------------------------------------------------|
| `<!DOCTYPE>`   | Deklaracja typu dokumentu, informuje przeglądarkę o wersji HTML.      |
| `<html>`       | Główna sekcja strony, zawierająca całą strukturę dokumentu.           |
| `<head>`       | Sekcja z metadanymi strony, niewidoczna dla użytkownika.              |
| `<meta>`       | Informacje o stronie (np. kodowanie znaków, responsywność).           |
| `<title>`      | Tytuł strony wyświetlany w karcie przeglądarki.                       |
| `<body>`       | Sekcja z treścią strony, widoczna dla użytkownika.                    |
| `<h1> - <h6>`  | Nagłówki, struktura hierarchiczna nagłówków.                          |
| `<p>`          | Akapit tekstu.                                                       |
| `<a>`          | Link hipertekstowy do innej strony lub zasobu.                        |
| `<img>`        | Element wstawiający obraz.                                            |
| `<!-- -->`     | Komentarze, notatki w kodzie niewidoczne dla użytkowników strony.     |

---

Powyższe elementy stanowią podstawę do tworzenia dokumentów HTML i budowania stron internetowych.
