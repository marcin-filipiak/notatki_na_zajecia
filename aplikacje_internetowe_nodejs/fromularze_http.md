**Lekcja 6: Przechowywanie danych w pamięci serwera i obsługa prostych formularzy w Node.js**

Node.js pozwala tymczasowo przechowywać dane w pamięci serwera (np. w tablicach lub obiektach). Dzięki temu możemy tworzyć proste aplikacje typu „mini baza danych” bez użycia zewnętrznych baz.

---

### 1. Przechowywanie danych w tablicy

```js
const http = require('http');

const users = []; // tablica przechowująca dane użytkowników

const server = http.createServer((req, res) => {
    if (req.method === 'GET') {
        res.writeHead(200, { 'Content-Type': 'application/json' });
        res.end(JSON.stringify(users)); // zwracamy listę użytkowników w formacie JSON
    } else if (req.method === 'POST') {
        let body = '';

        req.on('data', chunk => body += chunk);
        req.on('end', () => {
            try {
                const user = JSON.parse(body); // zakładamy, że klient wysyła JSON
                users.push(user); // zapisujemy dane w pamięci
                res.writeHead(201, { 'Content-Type': 'application/json' });
                res.end(JSON.stringify({ message: 'Użytkownik dodany', users }));
            } catch (err) {
                res.writeHead(400, { 'Content-Type': 'application/json' });
                res.end(JSON.stringify({ error: 'Niepoprawny format danych' }));
            }
        });
    } else {
        res.writeHead(405, { 'Content-Type': 'text/plain' });
        res.end('Metoda niedozwolona');
    }
});

server.listen(3000, () => {
    console.log('Serwer działa na http://localhost:3000');
});
```

* `users` to tablica, w której przechowujemy dane użytkowników w pamięci.
* Dane POST wysyłane w JSON są parsowane i zapisywane w tablicy.
* GET zwraca całą tablicę w formacie JSON.

---

### 2. Obsługa prostego formularza HTML

Możemy utworzyć formularz HTML, który wysyła dane metodą POST:

```js
const http = require('http');

const users = [];

const server = http.createServer((req, res) => {
    if (req.method === 'GET' && req.url === '/') {
        res.writeHead(200, { 'Content-Type': 'text/html' });
        res.end(`
            <form method="POST" action="/add">
                Imię: <input name="name" /><br/>
                Wiek: <input name="age" /><br/>
                <button type="submit">Wyślij</button>
            </form>
        `);
    } else if (req.method === 'POST' && req.url === '/add') {
        let body = '';
        req.on('data', chunk => body += chunk);
        req.on('end', () => {
            const params = new URLSearchParams(body);
            const user = {
                name: params.get('name'),
                age: params.get('age')
            };
            users.push(user);
            res.writeHead(200, { 'Content-Type': 'text/html' });
            res.end(`<p>Dodano użytkownika: ${user.name}, wiek: ${user.age}</p><a href="/">Powrót</a>`);
        });
    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain' });
        res.end('Nie znaleziono strony');
    }
});

server.listen(3000, () => {
    console.log('Serwer działa na http://localhost:3000');
});
```

* Formularz wysyła dane metodą POST.
* `URLSearchParams` pozwala łatwo odczytać parametry przesłane w formacie `application/x-www-form-urlencoded`.
* Dane są zapisywane w tablicy `users` i można je wyświetlać w odpowiedzi.

---

### 3. Ważne uwagi

* Dane przechowywane w pamięci serwera są tymczasowe – po restarcie serwera tablica zostaje wyczyszczona.
* Do trwałego przechowywania danych używa się baz danych (np. SQLite, MySQL, MongoDB).
* Można kombinować GET i POST, aby mieć prosty interfejs do dodawania i odczytu danych.
