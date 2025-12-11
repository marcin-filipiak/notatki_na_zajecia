### 1. HTML + prosty interfejs

```html
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>API Client</title>
</head>
<body>
    <h1>Użytkownicy</h1>
    <ul id="userList"></ul>

    <h2>Dodaj użytkownika</h2>
    <input id="name" placeholder="Imię">
    <input id="age" placeholder="Wiek" type="number">
    <button id="addBtn">Dodaj</button>

    <script src="client.js"></script>
</body>
</html>
```

---

### 2. client.js – komunikacja z API

```js
const API_URL = 'http://localhost:3000/users';
const userList = document.getElementById('userList');
const nameInput = document.getElementById('name');
const ageInput = document.getElementById('age');
const addBtn = document.getElementById('addBtn');

// GET – pobranie wszystkich użytkowników
const getUsers = async () => {
    const res = await fetch(API_URL);
    const users = await res.json();
    userList.innerHTML = '';
    users.forEach(u => {
        const li = document.createElement('li');
        li.textContent = `${u.id}: ${u.name}, wiek: ${u.age}`;
        
        // przyciski PUT i DELETE
        const editBtn = document.createElement('button');
        editBtn.textContent = 'Edytuj';
        editBtn.onclick = () => updateUser(u.id);
        
        const delBtn = document.createElement('button');
        delBtn.textContent = 'Usuń';
        delBtn.onclick = () => deleteUser(u.id);
        
        li.append(' ', editBtn, ' ', delBtn);
        userList.appendChild(li);
    });
};

// POST – dodanie użytkownika
const addUser = async () => {
    const name = nameInput.value;
    const age = parseInt(ageInput.value);
    if (!name || !age) return alert('Podaj imię i wiek');

    await fetch(API_URL, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ name, age })
    });
    nameInput.value = '';
    ageInput.value = '';
    getUsers();
};

// PUT – aktualizacja użytkownika (prosta demonstracja)
const updateUser = async (id) => {
    const newName = prompt('Nowe imię:');
    const newAge = parseInt(prompt('Nowy wiek:'));
    if (!newName || !newAge) return;

    await fetch(`${API_URL}/${id}`, {
        method: 'PUT',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ name: newName, age: newAge })
    });
    getUsers();
};

// DELETE – usunięcie użytkownika
const deleteUser = async (id) => {
    await fetch(`${API_URL}/${id}`, { method: 'DELETE' });
    getUsers();
};

// wywołanie przy starcie
getUsers();
addBtn.onclick = addUser;
```

---

### 3. Omówienie

* **GET** (`getUsers`) – pobiera użytkowników z API i wyświetla w `<ul>`.

* **POST** (`addUser`) – dodaje nowego użytkownika wpisanego w inputy.

* **PUT** (`updateUser`) – pyta użytkownika o nowe dane (prompt) i aktualizuje po ID.

* **DELETE** (`deleteUser`) – usuwa użytkownika po ID.

* Wszystko działa w **przeglądarce**, żądania są wysyłane do API w formacie JSON.

* Nie używamy HTML z serwera – cała logika frontendu jest po stronie klienta.

