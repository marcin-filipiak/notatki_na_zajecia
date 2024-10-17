### Najważniejsze znaczniki HTML5

HTML5 to najnowsza wersja języka HTML, która wprowadza szereg nowych znaczników i funkcji, pozwalających na bardziej semantyczne i elastyczne tworzenie stron internetowych. Oto przegląd najważniejszych znaczników HTML5:

---

#### 1. **Znaczniki strukturalne**
Te znaczniki pomagają podzielić stronę na logiczne sekcje, ułatwiając organizację i semantykę strony.

- **`<header>`**  
  - Zawiera wprowadzenie lub nawigację strony. Może obejmować nagłówki, logo, menu nawigacyjne itp.
  - Przykład:
    ```html
    <header>
        <h1>Nagłówek strony</h1>
        <nav>
            <a href="strona1.html">Strona 1</a>
            <a href="strona2.html">Strona 2</a>
        </nav>
    </header>
    ```

- **`<nav>`**  
  - Sekcja przeznaczona dla linków nawigacyjnych. Zwykle stosowana dla głównego menu strony.
  - Przykład:
    ```html
    <nav>
        <ul>
            <li><a href="home.html">Strona Główna</a></li>
            <li><a href="about.html">O nas</a></li>
        </ul>
    </nav>
    ```

- **`<section>`**  
  - Oznacza samodzielną sekcję dokumentu, która zawiera logiczny blok treści. Może być stosowana do grupowania treści o podobnej tematyce.
  - Przykład:
    ```html
    <section>
        <h2>Temat sekcji</h2>
        <p>To jest akapit wewnątrz sekcji.</p>
    </section>
    ```

- **`<article>`**  
  - Reprezentuje niezależną treść, np. artykuł, wpis na blogu, komentarz. Może być samodzielnie dystrybuowany i wykorzystywany w różnych miejscach.
  - Przykład:
    ```html
    <article>
        <h2>Wpis na blogu</h2>
        <p>To jest treść artykułu.</p>
    </article>
    ```

- **`<aside>`**  
  - Zawiera dodatkowe informacje, które są związane z główną treścią, ale nie są bezpośrednio jej częścią, np. reklamy, linki pomocnicze, cytaty.
  - Przykład:
    ```html
    <aside>
        <p>To jest przypis lub dodatkowa informacja.</p>
    </aside>
    ```

- **`<footer>`**  
  - Reprezentuje stopkę strony lub sekcji, często zawiera informacje o autorach, prawa autorskie, linki do polityki prywatności.
  - Przykład:
    ```html
    <footer>
        <p>&copy; 2024 Firma X</p>
    </footer>
    ```

---

#### 2. **Znaczniki multimedialne**
HTML5 wprowadza nowe, natywne znaczniki do obsługi multimediów bez potrzeby korzystania z zewnętrznych wtyczek.

- **`<audio>`**  
  - Służy do osadzania dźwięku.
  - Atrybuty: `controls` (dodaje kontrolki do odtwarzania), `src` (ścieżka do pliku audio).
  - Przykład:
    ```html
    <audio controls>
        <source src="audio.mp3" type="audio/mpeg">
        Twoja przeglądarka nie obsługuje elementu audio.
    </audio>
    ```

- **`<video>`**  
  - Służy do osadzania plików wideo.
  - Atrybuty: `controls`, `autoplay`, `loop`, `muted`.
  - Przykład:
    ```html
    <video controls width="600">
        <source src="video.mp4" type="video/mp4">
        Twoja przeglądarka nie obsługuje elementu video.
    </video>
    ```

- **`<canvas>`**  
  - Element do rysowania grafiki, wykresów, animacji przy użyciu JavaScript.
  - Przykład (proste rysowanie):
    ```html
    <canvas id="rysunek" width="200" height="200"></canvas>
    <script>
        var c = document.getElementById("rysunek");
        var ctx = c.getContext("2d");
        ctx.fillStyle = "#FF0000";
        ctx.fillRect(20, 20, 150, 100);
    </script>
    ```

---

#### 3. **Formularze w HTML5**
HTML5 wprowadza nowe elementy i atrybuty do tworzenia bardziej zaawansowanych i użytecznych formularzy.

- **`<form>`**  
  - Definiuje formularz do wysyłania danych.
  - Atrybuty: `action` (adres serwera, na który wysyłane są dane), `method` (metoda przesyłania danych, np. GET, POST).
  - Przykład:
    ```html
    <form action="/submit" method="post">
        <label for="name">Imię:</label>
        <input type="text" id="name" name="name">
        <input type="submit" value="Wyślij">
    </form>
    ```

- **Nowe typy pól formularzy:**
    - **`<input type="email">`** – Pole do wprowadzania adresu e-mail (walidowane automatycznie).
    - **`<input type="url">`** – Pole do wprowadzania adresu URL.
    - **`<input type="date">`** – Pole do wyboru daty z kalendarza.
    - **`<input type="range">`** – Pasek przesuwania do wyboru wartości z zakresu.
    - **`<input type="number">`** – Pole do wprowadzania liczb.

---

#### 4. **Semantyczne znaczniki tekstowe**

- **`<mark>`**  
  - Zaznacza tekst, który jest wyróżniony (np. podkreślenie ważnych informacji).
  - Przykład:
    ```html
    <p>To jest <mark>ważna</mark> informacja.</p>
    ```

- **`<time>`**  
  - Reprezentuje określony moment w czasie lub przedział czasu.
  - Przykład:
    ```html
    <time datetime="2024-10-17">17 października 2024</time>
    ```

---

#### 5. **API w HTML5**
HTML5 rozszerza możliwości interakcji z przeglądarką i urządzeniami użytkownika, wprowadzając nowe API (interfejsy programowania aplikacji).

- **Geolocation API** – Umożliwia dostęp do lokalizacji urządzenia użytkownika (za jego zgodą).
- **Local Storage** – Przechowywanie danych w przeglądarce bez potrzeby użycia ciasteczek.
- **Drag and Drop** – API umożliwiające przeciąganie i upuszczanie elementów na stronie.

---

HTML5 wprowadza wiele udoskonaleń i nowych funkcji, które ułatwiają tworzenie nowoczesnych, dynamicznych i semantycznych stron internetowych, a jednocześnie zwiększają ich dostępność i użyteczność.
