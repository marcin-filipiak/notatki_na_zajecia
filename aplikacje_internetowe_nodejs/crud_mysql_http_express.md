**Lekcja 10: Pełny CRUD w Express + MySQL – dodawanie, odczyt, edycja i usuwanie danych**

W tej lekcji zbudujemy prostą aplikację webową z formularzami i pełną obsługą CRUD dla tabeli `users` w MySQL przy użyciu Express.

---

### 1. Konfiguracja

* Node.js, Express i MySQL zainstalowane:

```bash
npm install express mysql2
```

* Baza danych i tabela:

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

### 2. Podstawowy serwer Express z MySQL

```js
const express = require('express');
const mysql = require('mysql2');
const app = express();

app.use(express.urlencoded({ extended: true }));
app.use(express.json());

const connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'haslo',
    database: 'testdb'
});

connection.connect(err => {
    if (err) throw err;
    console.log('Połączono z MySQL');
});
```

---

### 3. Dodawanie użytkowników (CREATE)

```js
app.get('/', (req, res) => {
    res.send(`
        <form method="POST" action="/add">
            Imię: <input name="name"><br/>
            Wiek: <input name="age"><br/>
            <button type="submit">Dodaj</button>
        </form>
        <a href="/users">Lista użytkowników</a>
    `);
});

app.post('/add', (req, res) => {
    const { name, age } = req.body;
    connection.query('INSERT INTO users (name, age) VALUES (?, ?)', [name, age], (err) => {
        if (err) return res.send('Błąd serwera');
        res.redirect('/users');
    });
});
```

* Formularz wysyła dane metodą POST.
* `res.redirect('/users')` – po dodaniu przekierowuje na listę użytkowników.

---

### 4. Odczyt użytkowników (READ)

```js
app.get('/users', (req, res) => {
    connection.query('SELECT * FROM users', (err, results) => {
        if (err) return res.send('Błąd serwera');
        let html = '<h1>Użytkownicy</h1><ul>';
        results.forEach(u => {
            html += `<li>${u.id}: ${u.name}, wiek: ${u.age} 
                <a href="/edit/${u.id}">Edytuj</a> 
                <a href="/delete/${u.id}">Usuń</a>
            </li>`;
        });
        html += '</ul><a href="/">Dodaj użytkownika</a>';
        res.send(html);
    });
});
```

* Wyświetlamy wszystkich użytkowników z przyciskami do edycji i usuwania.

---

### 5. Edycja użytkowników (UPDATE)

```js
app.get('/edit/:id', (req, res) => {
    const id = req.params.id;
    connection.query('SELECT * FROM users WHERE id = ?', [id], (err, results) => {
        if (err || results.length === 0) return res.send('Nie znaleziono użytkownika');
        const user = results[0];
        res.send(`
            <form method="POST" action="/edit/${id}">
                Imię: <input name="name" value="${user.name}"><br/>
                Wiek: <input name="age" value="${user.age}"><br/>
                <button type="submit">Zapisz</button>
            </form>
            <a href="/users">Powrót</a>
        `);
    });
});

app.post('/edit/:id', (req, res) => {
    const id = req.params.id;
    const { name, age } = req.body;
    connection.query('UPDATE users SET name = ?, age = ? WHERE id = ?', [name, age, id], (err) => {
        if (err) return res.send('Błąd serwera');
        res.redirect('/users');
    });
});
```

* Pobieramy użytkownika po `id` i wyświetlamy w formularzu do edycji.
* Po wysłaniu formularza aktualizujemy rekord w bazie.

---

### 6. Usuwanie użytkowników (DELETE)

```js
app.get('/delete/:id', (req, res) => {
    const id = req.params.id;
    connection.query('DELETE FROM users WHERE id = ?', [id], (err) => {
        if (err) return res.send('Błąd serwera');
        res.redirect('/users');
    });
});
```

* Proste usuwanie po ID i przekierowanie na listę użytkowników.

---

### 7. Uruchomienie serwera

```js
app.listen(3000, () => {
    console.log('Serwer działa na http://localhost:3000');
});
```

---

### 8. Podsumowanie funkcjonalności

* `/` – formularz dodawania użytkownika (CREATE)
* `/users` – lista użytkowników (READ)
* `/edit/:id` – formularz edycji użytkownika (UPDATE)
* `/delete/:id` – usuwanie użytkownika (DELETE)

Kod jest prosty, czytelny i pokazuje pełny cykl CRUD w Node.js z MySQL przy użyciu Express.
