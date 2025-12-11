**Lekcja 5 Tworzenie serwera HTTP w Node.js i obsługa GET i POST**

Node.js pozwala tworzyć serwery HTTP bez dodatkowych bibliotek. W tej lekcji omówimy tworzenie serwera, obsługę różnych ścieżek oraz żądań GET i POST.

---

### 1. Tworzenie podstawowego serwera

```js
const http = require('http');

const server = http.createServer((req, res) => {
    console.log('Otrzymano żądanie:', req.method, req.url);

    // Ustawiamy nagłówki odpowiedzi
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    res.end('Witaj na moim serwerze Node.js!');
});

server.listen(3000, () => {
    console.log('Serwer działa na http://localhost:3000');
});
```

* `req` – obiekt żądania (metoda, URL, nagłówki).
* `res` – obiekt odpowiedzi (status, nagłówki, treść).
* `res.writeHead(status, headers)` – ustawia status i nagłówki odpowiedzi.
* `res.end()` – kończy odpowiedź.

---

### 2. Obsługa różnych ścieżek

Możemy reagować w zależności od URL:

```js
const http = require('http');

const server = http.createServer((req, res) => {
    if (req.url === '/') {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end('Strona główna');
    } else if (req.url === '/about') {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end('O nas');
    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain' });
        res.end('Nie znaleziono strony');
    }
});

server.listen(3000, () => {
    console.log('Serwer działa na http://localhost:3000');
});
```

* `req.url` – pozwala sprawdzić, jaka ścieżka została wywołana.
* Można też sprawdzać metodę żądania (`req.method`) – GET, POST itp.

---

### 3. Obsługa żądań GET

Żądania GET mogą mieć parametry w URL (`?param1=wartość`). Node.js ma wbudowany moduł `url` do ich parsowania:

```js
const http = require('http');
const url = require('url');

const server = http.createServer((req, res) => {
    if (req.method === 'GET') {
        const parsedUrl = url.parse(req.url, true); // true -> parse query string
        const path = parsedUrl.pathname;
        const query = parsedUrl.query;

        res.writeHead(200, { 'Content-Type': 'text/plain' });

        if (path === '/hello' && query.name) {
            res.end(`Witaj, ${query.name}!`);
        } else {
            res.end('Strona główna GET');
        }
    }
});

server.listen(3000, () => {
    console.log('Serwer działa na http://localhost:3000');
});
```

Przykład wywołania:
`http://localhost:3000/hello?name=Marcin` → odpowiedź: `Witaj, Marcin!`

---

### 4. Obsługa żądań POST

Żądania POST przesyłają dane w ciele żądania. Dane mogą przychodzić w kawałkach, więc należy je łączyć.

```js
const http = require('http');

const server = http.createServer((req, res) => {
    if (req.method === 'POST') {
        let body = '';

        req.on('data', chunk => {
            body += chunk; // zbieramy kolejne fragmenty danych
        });

        req.on('end', () => {
            console.log('Otrzymano dane POST:', body);
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end('Dane POST odebrane!');
        });

        req.on('error', err => {
            console.error('Błąd podczas odbierania danych:', err);
            res.writeHead(500, { 'Content-Type': 'text/plain' });
            res.end('Błąd serwera');
        });
    } else {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end('Wyślij dane metodą POST');
    }
});

server.listen(3000, () => {
    console.log('Serwer działa na http://localhost:3000');
});
```

* `req.on('data', callback)` – odbiera fragmenty danych przesyłanych w POST.
* `req.on('end', callback)` – wywoływane po zakończeniu przesyłania danych.
* `req.on('error', callback)` – obsługa błędów przesyłania.

---

### 5. Łączenie GET i POST w jednym serwerze

```js
const http = require('http');
const url = require('url');

const server = http.createServer((req, res) => {
    const parsedUrl = url.parse(req.url, true);
    const path = parsedUrl.pathname;
    const query = parsedUrl.query;

    if (req.method === 'GET') {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        if (path === '/hello' && query.name) {
            res.end(`Witaj, ${query.name}!`);
        } else {
            res.end('Strona główna GET');
        }
    } else if (req.method === 'POST') {
        let body = '';
        req.on('data', chunk => body += chunk);
        req.on('end', () => {
            console.log('Dane POST:', body);
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end(`Otrzymano dane POST: ${body}`);
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

* Obsługa wielu metod w jednym miejscu (`req.method`).
* Wykorzystanie zarówno parametrów GET (`req.url` + `url.parse`) jak i ciała POST (`req.on('data')` + `req.on('end')`).

