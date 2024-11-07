# HTML i Formularze

Formularze HTML umożliwiają użytkownikom wprowadzanie danych, które następnie mogą być przetwarzane na serwerze za pomocą takich języków jak PHP. Formularze składają się z różnych pól wejściowych, które pozwalają na zebranie różnych typów danych. Poniżej opisano najważniejsze elementy formularza oraz wskazówki dotyczące ich użycia.

#### Typy Pól Formularza HTML

1. **`text`** – Pole tekstowe, pozwala użytkownikowi na wprowadzenie krótkiego tekstu (np. imię, nazwisko).
   ```html
   <input type="text" name="username" placeholder="Wpisz swoje imię">
   ```

2. **`date`** – Pole do wyboru daty, które pozwala użytkownikowi wybrać datę z kalendarza.
   ```html
   <input type="date" name="birthdate">
   ```

3. **`tel`** – Pole do wprowadzenia numeru telefonu. Można połączyć je z tzw. "maską", aby wymusić określony format numeru.
   ```html
   <input type="tel" name="phone" placeholder="123-456-789">
   ```

4. **`email`** – Pole do wprowadzania adresu e-mail. Przeglądarki walidują ten typ, sprawdzając poprawność formatu.
   ```html
   <input type="email" name="email" placeholder="example@example.com">
   ```

5. **`number`** – Pole do wprowadzania liczb. Można ustawić minimalną, maksymalną wartość oraz kroki.
   ```html
   <input type="number" name="age" min="1" max="100" step="1">
   ```

6. **`range`** – Pole suwaka, które pozwala użytkownikowi wybrać wartość z określonego zakresu.
   ```html
   <input type="range" name="volume" min="0" max="100">
   ```

7. **`file`** – Pole do przesyłania plików. Przy użyciu tego typu pola formularz musi mieć atrybut `enctype="multipart/form-data"`, aby dane zostały prawidłowo przesłane.
   ```html
   <input type="file" name="profilePicture">
   ```

8. **`checkbox`** – Pole wyboru, które pozwala na zaznaczenie wielu opcji (prawda/fałsz).
   ```html
   <input type="checkbox" name="newsletter" value="subscribe"> Zapisz mnie do newslettera
   ```

9. **`radio`** – Przycisk opcji, który pozwala na wybór jednej opcji z wielu.
   ```html
   <input type="radio" name="gender" value="male"> Mężczyzna
   <input type="radio" name="gender" value="female"> Kobieta
   ```

10. **`submit`** – Przycisk do wysyłania formularza. Wywołuje akcję przesłania danych.
   ```html
   <input type="submit" value="Wyślij">
   ```

#### Atrybuty Wymagane i Walidacja

1. **`required`** – Atrybut, który można dodać do pola, aby uczynić je wymaganym. Użytkownik musi wypełnić takie pole przed wysłaniem formularza.
   ```html
   <input type="text" name="username" required>
   ```

2. **`pattern`** – Atrybut `pattern` pozwala na ustalenie wzorca (wyrażenia regularnego), który musi być spełniony przez wprowadzone dane. Użycie tego atrybutu pozwala na walidację formatu danych na poziomie przeglądarki.
   ```html
   <input type="tel" name="phone" pattern="[0-9]{3}-[0-9]{3}-[0-9]{3}" placeholder="123-456-789">
   ```

#### Wysyłanie Plików – `enctype="multipart/form-data"`

Jeśli formularz zawiera pole typu `file`, należy dodać atrybut `enctype="multipart/form-data"` do tagu `<form>`. Ten atrybut mówi przeglądarce, aby przesłać dane formularza w sposób umożliwiający załączanie plików.

```html
<form action="upload.php" method="POST" enctype="multipart/form-data">
    <input type="file" name="uploadFile">
    <input type="submit" value="Prześlij plik">
</form>
```

#### Maska dla Wprowadzania Danych

"Maska" w formularzu jest to sposób ograniczenia formatu danych, które można wpisać, np. dla numeru telefonu. Maski mogą być tworzone przy pomocy atrybutu `pattern`, a także przy użyciu JavaScript lub zewnętrznych bibliotek (np. jQuery Mask Plugin) dla bardziej złożonych przypadków.

**Przykład maski dla numeru telefonu:**
```html
<input type="tel" name="phone" pattern="[0-9]{3}-[0-9]{3}-[0-9]{3}" placeholder="123-456-789" required>
```
