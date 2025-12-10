**Lekcja 4: Asynchroniczność w Node.js – callbacki, Promise i async/await**

Node.js jest w dużej mierze asynchroniczny, co oznacza, że wiele operacji (np. odczyt plików, żądania sieciowe) nie blokuje programu. Dzięki temu serwery Node.js mogą obsługiwać wiele zapytań jednocześnie.

---

### 1. Callbacki (funkcje zwrotne)

Najstarszy sposób obsługi asynchroniczności w Node.js. Funkcja jest przekazywana jako argument i wywoływana po zakończeniu operacji.

Przykład odczytu pliku:

```js
const fs = require('fs');

fs.readFile('example.txt', 'utf-8', (err, data) => {
    if (err) {
        console.error('Błąd odczytu pliku:', err);
        return;
    }
    console.log('Zawartość pliku:', data);
});
```

* Pierwszy argument callbacka (`err`) służy do obsługi błędów.
* Drugi argument (`data`) zawiera wynik operacji.

**Minusy callbacków:** mogą tworzyć tzw. "callback hell", czyli zagnieżdżone funkcje trudne w czytaniu.

---

### 2. Promise

Promise pozwala lepiej zarządzać asynchronicznością i łączyć operacje w łańcuchy.

Tworzenie Promise:

```js
const fs = require('fs').promises;

fs.readFile('example.txt', 'utf-8')
    .then(data => {
        console.log('Zawartość pliku:', data);
    })
    .catch(err => {
        console.error('Błąd odczytu pliku:', err);
    });
```

* `.then()` obsługuje wynik sukcesu.
* `.catch()` obsługuje błędy.

Promise można łączyć w łańcuchy, co poprawia czytelność w porównaniu do callbacków.

---

### 3. Async / Await

Nowoczesny sposób używania Promise, który wygląda jak kod synchroniczny.

```js
const fs = require('fs').promises;

async function readFile() {
    try {
        const data = await fs.readFile('example.txt', 'utf-8');
        console.log('Zawartość pliku:', data);
    } catch (err) {
        console.error('Błąd odczytu pliku:', err);
    }
}

readFile();
```

* `async` przed funkcją pozwala używać `await` wewnątrz niej.
* `await` zatrzymuje wykonanie funkcji do momentu zakończenia Promise.
* Kod wygląda czytelnie, a błędy można obsługiwać zwykłym `try/catch`.

---

### 4. Zadania do praktyki

1. Utwórz plik `notes.txt` i napisz kilka linijek tekstu.
2. Odczytaj zawartość pliku najpierw przy użyciu callbacka, potem Promise, a na końcu async/await.
3. Spróbuj zapisać nowy tekst do pliku używając tych samych trzech metod (`fs.writeFile`).
4. Stwórz funkcję `readAndUppercase` – odczytuje plik i zwraca jego zawartość wielkimi literami (użyj async/await).

