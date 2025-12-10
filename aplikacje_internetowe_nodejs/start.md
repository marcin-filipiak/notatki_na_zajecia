Poniżej masz konkretne kroki, które pozwolą Ci zobaczyć, jak Node działa w praktyce.

---

# 1. Sprawdź, czy działa REPL (interaktywna konsola)

W terminalu wpisz:

```bash
node
```

Powinno pojawić się:

```
Welcome to Node.js v18.20.4.
Type ".help" for more information.
>
```

Teraz możesz pisać JavaScript jak w interpreterze:

```
> 2+2
4
> console.log("działa")
działa
```

Wyjście:
`Ctrl + C` dwa razy.

---

# 2. Upewnij się, że npm też działa

```
npm -v
```

Jeśli pokazuje numer wersji, jesteś gotowy do instalowania paczek.

---

# 3. Pierwszy plik .js i uruchomienie go

Stwórz plik:

```bash
nano test.js
```

Wklej:

```js
console.log("Node działa z pliku!");
```

Uruchom:

```bash
node test.js
```

---

# 4. Od razu zrób prosty serwer

To bardzo obrazowo pokazuje możliwości Node.js:

```bash
nano server.js
```

Wklej:

```js
const http = require("http");

const server = http.createServer((req, res) => {
    res.writeHead(200, {"Content-Type": "text/plain"});
    res.end("Pozdrowienia z Node v18!");
});

server.listen(3000, () => {
    console.log("Serwer działa na http://localhost:3000");
});
```

Uruchom:

```bash
node server.js
```

Wejdź na:

```
http://localhost:3000
```

---

# 5. Jeśli chcesz mieć nowsze wersje (opcjonalnie)

Możesz zainstalować `n` — menedżera wersji Node — i łatwo przełączać wersje:

```bash
sudo npm install -g n
sudo n stable
```

Po restarcie terminala:

```bash
node -v
```

---
