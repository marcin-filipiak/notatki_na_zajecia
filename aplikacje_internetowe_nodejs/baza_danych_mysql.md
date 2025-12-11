**Lekcja 7: Node.js i baza danych MySQL – podstawowy CRUD**

W tej lekcji nauczymy się łączyć Node.js z bazą danych MySQL i wykonywać podstawowe operacje CRUD (Create, Read, Update, Delete).

---

### 1. Instalacja pakietu `mysql2`

Node.js nie ma wbudowanego sterownika do MySQL, więc używamy pakietu `mysql2`:

```bash
npm init -y           # jeśli nie masz package.json
npm install mysql2
```

---

### 2. Tworzenie połączenia z bazą danych

Przykład konfiguracji:

```js
const mysql = require('mysql2');

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
    console.log('Połączono z bazą danych MySQL');
});
```

* `host` – adres serwera MySQL (localhost w lokalnym środowisku).
* `user` – użytkownik bazy danych.
* `password` – hasło użytkownika.
* `database` – nazwa bazy danych, w której będziemy pracować.

---

### 3. Tworzenie tabeli

W bazie MySQL możesz wykonać np.:

```sql
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    age INT
);
```

---

### 4. Operacja CREATE – dodawanie danych

```js
const user = { name: 'Marcin', age: 20 };

connection.query('INSERT INTO users SET ?', user, (err, result) => {
    if (err) throw err;
    console.log('Dodano użytkownika, ID:', result.insertId);
});
```

* `?` – pozwala bezpiecznie wstawić dane, unikając SQL Injection.
* `result.insertId` – ID dodanego rekordu.

---

### 5. Operacja READ – odczyt danych

```js
connection.query('SELECT * FROM users', (err, results) => {
    if (err) throw err;
    console.log('Użytkownicy w bazie:');
    console.log(results);
});
```

* `results` to tablica obiektów reprezentujących wiersze w tabeli.

---

### 6. Operacja UPDATE – aktualizacja danych

```js
const newAge = 25;
const userId = 1;

connection.query(
    'UPDATE users SET age = ? WHERE id = ?',
    [newAge, userId],
    (err, result) => {
        if (err) throw err;
        console.log('Zaktualizowano wiersze:', result.affectedRows);
    }
);
```

* `result.affectedRows` – liczba zmienionych wierszy.

---

### 7. Operacja DELETE – usuwanie danych

```js
const userIdToDelete = 1;

connection.query(
    'DELETE FROM users WHERE id = ?',
    [userIdToDelete],
    (err, result) => {
        if (err) throw err;
        console.log('Usunięto wiersze:', result.affectedRows);
    }
);
```

---

### 8. Zamykanie połączenia

Po zakończeniu pracy należy zamknąć połączenie:

```js
connection.end(err => {
    if (err) console.error('Błąd przy zamykaniu połączenia:', err);
    else console.log('Połączenie z bazą zakończone');
});
```

