**Lekcja 3: Moduły w Node.js – import i eksport funkcji oraz obiektów**

Node.js używa systemu modułów, co pozwala dzielić kod na części i ponownie go używać. Podstawowo mamy dwa sposoby importowania modułów:

1. **CommonJS** – klasyczny system w Node.js (`require` i `module.exports`)
2. **ES Modules (ESM)** – nowoczesny sposób (`import` i `export`)

---

### 1. CommonJS (najczęściej spotykane)

**Tworzenie modułu:**

Stwórz plik `math.js`:

```js
// math.js
function add(a, b) {
    return a + b;
}

function multiply(a, b) {
    return a * b;
}

// eksportujemy funkcje
module.exports = { add, multiply };
```

**Importowanie modułu:**

Stwórz plik `app.js` w tym samym folderze:

```js
// app.js
const math = require('./math.js');

console.log(math.add(2, 3));      // 5
console.log(math.multiply(4, 5)); // 20
```

* `require('./math.js')` ładuje moduł i zwraca obiekt z funkcjami, które wyeksportowaliśmy.
* Każdy plik w Node.js jest traktowany jako moduł.

---

### 2. ES Modules (ESM)

Musisz zmienić rozszerzenie pliku na `.mjs` lub dodać `"type": "module"` w `package.json`.

**math.mjs**:

```js
export function add(a, b) {
    return a + b;
}

export function multiply(a, b) {
    return a * b;
}
```

**app.mjs**:

```js
import { add, multiply } from './math.mjs';

console.log(add(2, 3));      // 5
console.log(multiply(4, 5)); // 20
```

* `export` pozwala wybrać, co chcemy udostępnić innym modułom.
* `import { add } from './math.mjs'` pozwala pobrać konkretną funkcję lub obiekt z modułu.

---

### 3. Moduły wbudowane w Node.js

Node.js ma własne moduły, np. `fs` (filesystem), `path`, `os`, `http`.

Przykład użycia modułu `fs`:

```js
const fs = require('fs');

// odczytanie zawartości pliku
const data = fs.readFileSync('example.txt', 'utf-8');
console.log(data);
```

* `fs.readFileSync` działa synchronicznie – Node.js czeka aż plik zostanie wczytany.
* Istnieje też wersja asynchroniczna `fs.readFile` z callbackiem.

---

### 4. Zadania do praktyki:

1. Stwórz własny moduł `stringUtils.js` z funkcjami `toUpperCase` i `toLowerCase`.
2. Zaimportuj moduł w `app.js` i sprawdź działanie obu funkcji.
3. Spróbuj zrobić to w stylu CommonJS i ES Modules.
4. Otwórz plik tekstowy `sample.txt` i przeczytaj jego zawartość w Node.js przy użyciu modułu `fs`.

