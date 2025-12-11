**Lekcja 9: Node.js z frameworkiem Express – prosty serwer i obsługa formularzy**

Express to popularny framework dla Node.js, który upraszcza tworzenie serwerów HTTP, routing oraz obsługę formularzy i JSON.

---

### 1. Instalacja Express

W folderze projektu:

```bash
npm install express
```

Jeśli będziemy używać MySQL:

```bash
npm install mysql2
```

---

### 2. Podstawowy serwer Express

```js
const express = require('express');
const app = express();

// middleware do parsowania danych formularzy
app.use(express.urlencoded({ extended: true }));
app.use(express.json());

// GET – strona główna
app.get('/', (req, res) => {
    res.send(`
        <form method="POST" action="/add">
            Imię: <input name="name" /><br/>
            Wiek: <input name="age" /><br/>
            <button type="submit">Wyślij</button>
        </form>
    `);
});

// POST – obsługa formularza
app.post('/add', (req, res) => {
    const { name, age } = req.body;
    if (!name || !age) {
        return res.send('<p>Błędne dane</p><a href="/">Powrót</a>');
    }
    res.send(`<p>Dodano użytkownika: ${name}, wiek: ${age}</p><a href="/">Powrót</a>`);
});

// uruchomienie serwera
app.listen(3000, () => {
    console.log('Serwer Express działa na http://localhost:3000');
});
```

* `app.use(express.urlencoded({ extended: true }))` – parsuje dane z formularzy POST.
* `app.use(express.json())` – parsuje dane JSON wysyłane w ciele żądania.
* `app.get()` i `app.post()` – obsługa tras w prosty sposób.

---

### 3. Routing w Express

Express pozwala łatwo tworzyć różne ścieżki:

```js
app.get('/about', (req, res) => {
    res.send('<h1>O nas</h1>');
});

app.get('/users/:id', (req, res) => {
    const id = req.params.id;
    res.send(`Wyświetlam użytkownika o ID: ${id}`);
});
```

* `req.params` – parametry w ścieżce URL (`/users/5` → `req.params.id = 5`).
* `req.query` – parametry GET (`/hello?name=Marcin` → `req.query.name = 'Marcin'`).

---

### 4. Połączenie z MySQL w Express

```js
const mysql = require('mysql2');

const connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'haslo',
    database: 'testdb'
});

connection.connect(err => {
    if (err) throw err;
    console.log('Połączono z bazą MySQL');
});

// zapis do bazy w POST
app.post('/add', (req, res) => {
    const { name, age } = req.body;
    connection.query(
        'INSERT INTO users (name, age) VALUES (?, ?)',
        [name, age],
        (err, result) => {
            if (err) return res.send('Błąd serwera');
            res.send(`<p>Dodano użytkownika: ${name}, wiek: ${age}</p><a href="/">Powrót</a>`);
        }
    );
});

// lista użytkowników
app.get('/users', (req, res) => {
    connection.query('SELECT * FROM users', (err, results) => {
        if (err) return res.send('Błąd serwera');
        let html = '<h1>Lista użytkowników</h1><ul>';
        results.forEach(u => {
            html += `<li>${u.id}: ${u.name}, wiek: ${u.age}</li>`;
        });
        html += '</ul><a href="/">Dodaj kolejnego</a>';
        res.send(html);
    });
});
```

* Express upraszcza obsługę tras i danych z formularzy.
* Łatwo integruje się z bazą danych MySQL.
* Kod jest bardziej czytelny i krótszy niż w czystym Node.js.
