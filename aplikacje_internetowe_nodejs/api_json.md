**Lekcja 11: Tworzenie API w Node.js z MySQL – JSON zamiast HTML**

### 1. Instalacja i konfiguracja

```bash
npm install express mysql2
```

Tabela w MySQL:

```sql
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    age INT
);
```

---

### 2. Podstawowy serwer Express serwujący JSON

```js
const express = require('express');
const mysql = require('mysql2');
const app = express();

app.use(express.json()); // parsowanie JSON w body

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

### 3. CRUD w formacie JSON

#### CREATE – dodawanie użytkownika

```js
app.post('/users', (req, res) => {
    const { name, age } = req.body;
    if (!name || !age) return res.status(400).json({ error: 'Brak danych' });

    connection.query(
        'INSERT INTO users (name, age) VALUES (?, ?)',
        [name, age],
        (err, result) => {
            if (err) return res.status(500).json({ error: 'Błąd serwera' });
            res.status(201).json({ id: result.insertId, name, age });
        }
    );
});
```

#### READ – pobranie wszystkich użytkowników

```js
app.get('/users', (req, res) => {
    connection.query('SELECT * FROM users', (err, results) => {
        if (err) return res.status(500).json({ error: 'Błąd serwera' });
        res.json(results);
    });
});
```

#### READ – pobranie użytkownika po ID

```js
app.get('/users/:id', (req, res) => {
    const id = req.params.id;
    connection.query('SELECT * FROM users WHERE id = ?', [id], (err, results) => {
        if (err) return res.status(500).json({ error: 'Błąd serwera' });
        if (results.length === 0) return res.status(404).json({ error: 'Nie znaleziono użytkownika' });
        res.json(results[0]);
    });
});
```

#### UPDATE – aktualizacja użytkownika

```js
app.put('/users/:id', (req, res) => {
    const id = req.params.id;
    const { name, age } = req.body;
    connection.query(
        'UPDATE users SET name = ?, age = ? WHERE id = ?',
        [name, age, id],
        (err, result) => {
            if (err) return res.status(500).json({ error: 'Błąd serwera' });
            if (result.affectedRows === 0) return res.status(404).json({ error: 'Nie znaleziono użytkownika' });
            res.json({ message: 'Zaktualizowano użytkownika', id, name, age });
        }
    );
});
```

#### DELETE – usuwanie użytkownika

```js
app.delete('/users/:id', (req, res) => {
    const id = req.params.id;
    connection.query('DELETE FROM users WHERE id = ?', [id], (err, result) => {
        if (err) return res.status(500).json({ error: 'Błąd serwera' });
        if (result.affectedRows === 0) return res.status(404).json({ error: 'Nie znaleziono użytkownika' });
        res.json({ message: 'Usunięto użytkownika', id });
    });
});
```

---

### 4. Uruchomienie serwera

```js
app.listen(3000, () => {
    console.log('API działa na http://localhost:3000');
});
```

---

Teraz serwer działa jako **REST API**, wszystkie odpowiedzi są w JSON:

* GET `/users` → lista użytkowników
* GET `/users/:id` → użytkownik po ID
* POST `/users` → dodanie użytkownika
* PUT `/users/:id` → edycja użytkownika
* DELETE `/users/:id` → usunięcie użytkownika

Taki backend idealnie nadaje się do współpracy z front-endem lub aplikacjami mobilnymi.
