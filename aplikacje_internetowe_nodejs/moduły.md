# 📘 LEKCJA 2 — Moduły, `require()` i tworzenie własnych bibliotek

Celem lekcji jest:

* zrozumienie, jak Node ładuje kod z innych plików,
* nauczenie się eksportowania funkcji, zmiennych i obiektów,
* stworzenie małej biblioteki, która będzie wykorzystywana w głównym programie.

Node.js jest mocno zbudowany wokół systemu modułów.
Są dwa style modułów:

1. **CommonJS (require / module.exports)** – klasyczny, domyślny w Node.
2. **ESM (import/export)** – nowocześniejszy, znany z przeglądarek.

W tej lekcji korzystamy z **CommonJS**, bo jest najprostszy i najczęściej używany w początkowej nauce.

---

# 1. Po co istnieją moduły?

Każdy większy program powinien być podzielony na wiele plików.
Dlaczego?

* łatwiejsza organizacja kodu,
* łatwiejsze debugowanie,
* wygodne ponowne używanie funkcji,
* możliwość tworzenia własnych bibliotek.

Bez modułów program szybko zmieniłby się w jeden dłuuugi plik, w którym trudno coś znaleźć.

---

# 2. Jak działa `require()`?

`require()` to funkcja, która:

* ładuje i wykonuje plik,
* zwraca to, co zostało wyeksportowane.

Przykład użycia:

```js
const math = require("./math.js");
```

`math` otrzymuje obiekt, który plik `math.js` udostępnił.

Ścieżka musi mieć:

* `./` przed nazwą (bo to plik lokalny),
* lub `/absolutną`,
* lub nazwę paczki z npm.

---

# 3. Tworzenie własnego modułu

Stwórz plik `math.js`:

```
nano math.js
```

Wpisz:

```js
function add(a, b) {
    return a + b;
}

function sub(a, b) {
    return a - b;
}

// Wszystkie rzeczy, które chcemy udostępnić na zewnątrz:
module.exports = {
    add,
    sub
};
```

Wyjaśnienie:

* `module.exports` to obiekt,
* wszystko, co do niego wpiszesz, będzie widoczne w innych plikach.

---

# 4. Używanie modułu w głównym programie

Stwórz plik `main.js`:

```
nano main.js
```

Treść:

```js
const math = require("./math.js");

console.log("5 + 7 =", math.add(5, 7));
console.log("10 - 3 =", math.sub(10, 3));
```

Uruchamiasz:

```
node main.js
```

Powinno wypisać:

```
5 + 7 = 12
10 - 3 = 7
```

---

# 5. Możesz eksportować wszystko: funkcje, zmienne, klasy, obiekty

### Eksport jednej funkcji:

```js
module.exports = function(a, b) {
    return a * b;
};
```

Import:

```js
const multiply = require("./multiply.js");
console.log(multiply(3, 4));
```

---

### Eksport stałej:

```js
module.exports = 123;
```

Import:

```js
const value = require("./value.js");
console.log(value);
```

---

### Eksport klasy:

```js
class User {
    constructor(name) {
        this.name = name;
    }
}

module.exports = User;
```

Import:

```js
const User = require("./User.js");
let u = new User("Adam");
console.log(u.name);
```

---

# 6. W jaki sposób Node uruchamia moduł?

Kiedy używasz `require("./plik.js")`:

1. Node otwiera plik.
2. Owija go w funkcję (żeby zmienne nie przeciekały do globalnego zakresu).
3. Wykonuje kod.
4. To, co trafiło do `module.exports`, wraca do programu głównego.

Każdy moduł jest wykonywany **raz**.
Powtórne wywołanie `require()` nie uruchamia pliku ponownie — jest używana wersja zapisana w pamięci.

To zachowanie jest bardzo ważne przy większych projektach.

---

# 7. Praca z wieloma plikami — małe ćwiczenie

Stwórz katalog projektu:

```
mkdir project
cd project
```

Utwórz pliki:

### `greetings.js`

```js
function hello(name) {
    return "Cześć " + name;
}

function bye(name) {
    return "Do zobaczenia, " + name + "!";
}

module.exports = { hello, bye };
```

### `time.js`

```js
function now() {
    return new Date().toLocaleString();
}

module.exports = { now };
```

### `main.js`

```js
const g = require("./greetings.js");
const t = require("./time.js");

console.log(g.hello("Marcin"));
console.log("Czas teraz:", t.now());
console.log(g.bye("Marcin"));
```

Uruchom:

```
node main.js
```

---

# 8. Najważniejsze rzeczy do zapamiętania z lekcji 2

* `require()` służy do ładowania plików i paczek.
* `module.exports` określa, co dany plik udostępnia.
* Moduły są wykonywane tylko raz i zapamiętywane.
* Możesz eksportować funkcje, stałe, klasy i obiekty.
* Dziel program na małe pliki — to ułatwia pracę.

