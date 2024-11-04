### Podstawy JavaScript

JavaScript to język skryptowy, który pozwala na dodawanie interaktywności do stron internetowych. Można go osadzać w dokumencie HTML, aby tworzyć dynamiczne treści, reagować na zdarzenia użytkownika czy manipulować elementami na stronie.

#### Słowa kluczowe: `let`, `var`, `const`

1. **`var`**:
   - Deklaruje zmienną, która ma zasięg funkcyjny lub globalny (jeśli zadeklarowana na poziomie globalnym).
   - Można ją zadeklarować wielokrotnie w tej samej funkcji lub bloku, co może prowadzić do błędów w większych programach.
   - Przykład:
     ```javascript
     var name = "Jan";
     name = "Kasia";  // Dozwolone
     ```

2. **`let`**:
   - Deklaruje zmienną, która ma zasięg blokowy, czyli jest dostępna tylko w danym bloku (np. w pętli, instrukcji `if`).
   - Zmienne zadeklarowane za pomocą `let` nie mogą być deklarowane ponownie w tym samym zasięgu.
   - Przykład:
     ```javascript
     let age = 25;
     age = 30;  // Dozwolone
     ```

3. **`const`**:
   - Deklaruje stałą, której wartość nie może być później zmieniona.
   - Ma zasięg blokowy, podobnie jak `let`.
   - Przykład:
     ```javascript
     const pi = 3.14159;
     // pi = 3.14;  // Błąd! Nie można zmienić wartości `const`
     ```

#### Osadzanie JavaScript w HTML

JavaScript możemy osadzić w dokumencie HTML na kilka sposobów:

1. **Wewnątrz pliku HTML** – używamy znacznika `<script>`:
   ```html
   <script>
     console.log("Hello, World!");
   </script>
   ```

2. **Zewnętrzny plik** – w HTML wskazujemy plik `.js`:
   ```html
   <script src="script.js"></script>
   ```

   - Taka metoda ułatwia zarządzanie kodem i pozwala na wielokrotne użycie tego samego skryptu na różnych stronach.

#### Kiedy ładować JavaScript

Kod JavaScript powinien być załadowany **po załadowaniu struktury HTML**. Jeśli JavaScript ładuje się przed HTML, skrypt może próbować uzyskać dostęp do elementów, które jeszcze nie istnieją, co może prowadzić do błędów.

**Rozwiązanie**:
1. **Umieszczenie `<script>` na końcu dokumentu HTML** (przed `</body>`):
   ```html
   <body>
     <!-- zawartość strony -->
     <script src="script.js"></script>
   </body>
   ```

2. **Użycie atrybutu `defer`** – ładuje skrypt równocześnie z HTML, ale uruchamia go dopiero po pełnym załadowaniu struktury HTML:
   ```html
   <script src="script.js" defer></script>
   ```

**Podsumowanie**:
- `let`, `var`, `const` różnią się zasięgiem i możliwością ponownej deklaracji.
- Kod JavaScript osadzamy za pomocą `<script>`.
- Skrypt powinien być ładowany **po HTML** – można go umieścić na końcu dokumentu lub użyć atrybutu `defer`.
