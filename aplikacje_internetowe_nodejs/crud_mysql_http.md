**Lekcja 8: Node.js + MySQL + formularze HTML – pełna aplikacja CRUD w pamięci i bazie**

W tej lekcji połączymy wcześniejsze lekcje: serwer HTTP w Node.js, obsługę formularzy HTML i zapis danych bezpośrednio do bazy MySQL.

---

### 1. Instalacja i konfiguracja

* Node.js i MySQL muszą być zainstalowane.
* Zainstaluj pakiet `mysql2`:

```bash
npm install mysql2
```

* Przygotuj bazę i tabelę w MySQL:

```sql
CREATE DATABASE testdb;
USE testdb;

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    age INT
);
```

---

### 2. Serwer HTTP z formularzem i obsługą GET/POST

```js
const http = require('http');
const mysql = require('mysql2');
const { URLSearchParams } = require('url');

const connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'haslo', // zmień na swoje hasło
    database: 'testdb'
});

connection.connect(err => {
    if (err) {
        console.error('Błąd połączenia z bazą:', err);
        return;
    }
    console.log('Połączono z bazą MySQL');
});

const server = http.createServer((req, res) => {
    if (req.method === 'GET' && req.url === '/') {
        // formularz HTML
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
            const name = params.get('name');
            const age = parseInt(params.get('age'));

            if (!name || isNaN(age)) {
                res.writeHead(400, { 'Content-Type': 'text/html' });
                res.end('<p>Błędne dane</p><a href="/">Powrót</a>');
                return;
            }

            // zapis do MySQL
            connection.query(
                'INSERT INTO users (name, age) VALUES (?, ?)',
                [name, age],
                (err, result) => {
                    if (err) {
                        res.writeHead(500, { 'Content-Type': 'text/html' });
                        res.end('<p>Błąd serwera</p><a href="/">Powrót</a>');
                        return;
                    }
                    res.writeHead(200, { 'Content-Type': 'text/html' });
                    res.end(`<p>Dodano użytkownika: ${name}, wiek: ${age}</p><a href="/">Powrót</a>`);
                }
            );
        });
    } else if (req.method === 'GET' && req.url === '/users') {
        // lista użytkowników
        connection.query('SELECT * FROM users', (err, results) => {
            if (err) {
                res.writeHead(500, { 'Content-Type': 'text/html' });
                res.end('<p>Błąd serwera</p>');
                return;
            }
            res.writeHead(200, { 'Content-Type': 'text/html' });
            let html = '<h1>Lista użytkowników</h1><ul>';
            results.forEach(u => {
                html += `<li>${u.id}: ${u.name}, wiek: ${u.age}</li>`;
            });
            html += '</ul><a href="/">Dodaj kolejnego</a>';
            res.end(html);
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

---

### 3. Wyjaśnienia

* `URLSearchParams` – parsuje dane z formularza POST (`application/x-www-form-urlencoded`).
* `connection.query` – pozwala wykonać zapytania SQL i wstawić dane do MySQL.
* `/` – formularz do dodawania użytkownika.
* `/add` – obsługa POST formularza i zapis do bazy.
* `/users` – wyświetla listę wszystkich użytkowników w tabeli HTML.
* Dane są od razu zapisywane w bazie i dostępne w przeglądarce.

