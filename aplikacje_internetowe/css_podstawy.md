### Notatka o CSS

**CSS (Cascading Style Sheets)**, czyli Kaskadowe Arkusze Stylów, to język służący do opisywania wyglądu i formatowania dokumentów HTML. CSS pozwala na oddzielenie treści od jej prezentacji, co ułatwia zarządzanie wyglądem strony oraz poprawia jej dostępność. Dzięki CSS można zmieniać kolory, czcionki, układ elementów, a także stosować różne efekty wizualne.

#### Sposoby użycia CSS

1. **Styl inline**: 
   Styl CSS dołączony bezpośrednio do elementu HTML za pomocą atrybutu `style`.
   ```html
   <p style="color: blue;">To jest tekst z zastosowanym stylem inline.</p>
   ```

2. **Styl wewnętrzny**:
   Styl CSS umieszczony w sekcji `<head>` dokumentu HTML w znaczniku `<style>`.
   ```html
   <style>
       p {
           color: blue;
       }
   </style>
   ```

3. **Styl zewnętrzny**:
   Styl CSS zapisany w osobnym pliku `.css`, który jest dołączany do dokumentu HTML za pomocą znacznika `<link>`.
   ```html
   <link rel="stylesheet" href="style.css">
   ```

### Klasy i identyfikatory

- **Klasa**: Umożliwia przypisanie stylów do grupy elementów. Klasy są definiowane w CSS za pomocą kropki (`.`).
  ```css
  .mojaklasa {
      color: red;
  }
  ```
  Użycie w HTML:
  ```html
  <p class="mojaklasa">To jest tekst z klasą.</p>
  ```

- **Identyfikator**: Umożliwia przypisanie stylów do pojedynczego elementu. Identyfikatory są definiowane w CSS za pomocą hasha (`#`).
  ```css
  #mojidentyfikator {
      color: blue;
  }
  ```
  Użycie w HTML:
  ```html
  <p id="mojidentyfikator">To jest tekst z identyfikatorem.</p>
  ```

### Odwoływanie się do grupy znaczników

Można odwołać się do wszystkich elementów danego typu, np. do wszystkich znaczników `<p>` w dokumencie.
```css
p {
    color: green;
}
```

### Najpopularniejsze parametry w CSS

1. **`margin`**: Ustala marginesy wokół elementu. Może przyjmować jedną, dwie, trzy lub cztery wartości.
   ```css
   margin: 10px; /* Wszystkie marginesy 10px */
   margin: 10px 20px; /* Góra/Dół 10px, Lewo/Prawo 20px */
   ```

2. **`padding`**: Ustala przestrzeń wewnętrzną między zawartością a krawędzią elementu.
   ```css
   padding: 15px; /* Wszystkie paddingi 15px */
   padding: 5px 10px; /* Góra/Dół 5px, Lewo/Prawo 10px */
   ```

3. **`color`**: Ustala kolor tekstu.
   ```css
   color: blue; /* Kolor tekstu niebieski */
   ```

4. **`background-color`**: Ustala kolor tła elementu.
   ```css
   background-color: lightgray; /* Tło szare */
   ```

5. **`font-family`**: Ustala czcionkę używaną w elemencie.
   ```css
   font-family: Arial, sans-serif; /* Czcionka Arial */
   ```

6. **`font-size`**: Ustala rozmiar czcionki.
   ```css
   font-size: 16px; /* Rozmiar czcionki 16px */
   ```

7. **`border`**: Ustala obramowanie elementu. Może obejmować szerokość, styl i kolor.
   ```css
   border: 2px solid black; /* 2px czarne obramowanie solidne */
   ```

8. **`width` i `height`**: Ustala szerokość i wysokość elementu.
   ```css
   width: 100%; /* Szerokość 100% rodzica */
   height: 50px; /* Wysokość 50px */
   ```

9. **`display`**: Ustala sposób wyświetlania elementu (np. `block`, `inline`, `flex`).
   ```css
   display: block; /* Element jako blok */
   ```

10. **`text-align`**: Ustala wyrównanie tekstu w elemencie (np. `left`, `center`, `right`).
    ```css
    text-align: center; /* Wyrównanie do środka */
    ```

Te podstawowe elementy i parametry CSS stanowią fundament do stylizacji dokumentów HTML i tworzenia estetycznych stron internetowych.

_________

Oto przykładowy kod strony HTML z użyciem wymienionych wcześniej parametrów CSS w stylu wewnętrznym:

```html
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Przykładowa Strona z CSS</title>
    <style>
        /* Stylowanie dla całego dokumentu */
        body {
            background-color: lightgray;
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
        }

        /* Nagłówek */
        header {
            background-color: darkblue;
            color: white;
            text-align: center;
            padding: 20px;
        }

        /* Paragrafy */
        p {
            color: green;
            font-size: 16px;
            margin: 20px;
        }

        /* Stylowanie linków w nawigacji */
        nav a {
            color: white;
            margin: 0 15px;
            text-decoration: none;
        }

        /* Sekcja główna */
        section {
            margin: 20px;
            padding: 20px;
            background-color: white;
            border: 2px solid black;
            width: 80%;
        }

        /* Marginesy wewnętrzne dla elementu <aside> */
        aside {
            padding: 15px;
            background-color: lightyellow;
            border: 1px solid gray;
        }

        /* Stylowanie nagłówków */
        h1, h2 {
            color: darkblue;
        }

        /* Stopka */
        footer {
            background-color: darkblue;
            color: white;
            text-align: center;
            padding: 10px;
            margin-top: 20px;
        }
    </style>
</head>
<body>

    <!-- Nagłówek strony -->
    <header>
        <h1>Moja Strona z CSS</h1>
        <nav>
            <a href="#home">Strona Główna</a>
            <a href="#about">O nas</a>
            <a href="#contact">Kontakt</a>
        </nav>
    </header>

    <!-- Sekcja główna -->
    <section>
        <h2>O stronie</h2>
        <p>Ta strona prezentuje, jak stosować podstawowe parametry CSS, takie jak marginesy, padding, kolory, czcionki i obramowania.</p>
        <aside>
            <h3>Informacja dodatkowa</h3>
            <p>CSS ułatwia tworzenie estetycznych i funkcjonalnych stron internetowych, oddzielając treść od jej prezentacji.</p>
        </aside>
    </section>

    <!-- Stopka strony -->
    <footer>
        <p>&copy; 2024 Moja Strona. Wszystkie prawa zastrzeżone.</p>
    </footer>

</body>
</html>
```

### Opis zastosowanych parametrów:

1. **`background-color`**: Ustawiłem kolor tła dla elementów takich jak `body`, `header`, `section`, `aside`, i `footer`.
2. **`font-family`**: Użyłem czcionki Arial dla całej strony.
3. **`margin`**: Zastosowałem marginesy dla sekcji, paragrafów oraz sekcji głównej, by odstawić elementy od krawędzi i innych elementów.
4. **`padding`**: Zastosowałem padding, aby dodać wewnętrzną przestrzeń w elementach `header`, `section`, `aside` i `footer`.
5. **`color`**: Ustawiłem kolory tekstu w nagłówkach, paragrafach oraz linkach w nawigacji.
6. **`border`**: Dodałem obramowania do sekcji oraz asides.
7. **`text-align`**: Ustawiłem wyrównanie tekstu na środku dla `header` i `footer`.

Ta strona pokazuje podstawy użycia CSS do formatowania elementów HTML.
