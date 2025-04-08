
## Wyświetlanie w konsoli

```js
console.log("Hello, world!");
```

- `console.log()` – wypisuje tekst lub wartość do konsoli (F12 → zakładka *Console* w przeglądarce).
- Można też wypisywać liczby, zmienne, obiekty, tablice itd.

```js
let x = 42;
console.log("Wartość x to:", x);
```

---

## Deklaracja zmiennych

```js
let imie = "Anna";
const wiek = 25;
var nazwisko = "Kowalska";
```

- `let` – zmienna, którą można później zmienić.
- `const` – stała (nie można zmienić wartości).
- `var` – starszy sposób, obecnie raczej unika się go na rzecz `let`.

Przykład:

```js
let liczba = 10;
console.log(liczba);
liczba = 20;
console.log(liczba);
```

---

## Wczytywanie danych od użytkownika (z konsoli przeglądarki)

W przeglądarce można użyć:

```js
let imie = prompt("Jak masz na imię?");
console.log("Cześć, " + imie + "!");
```

- `prompt()` – otwiera okienko, w którym użytkownik wpisuje tekst.
- Zwraca zawsze tekst (string), nawet jeśli wpiszesz liczbę. Możesz przekonwertować ją na liczbę:

```js
let wiek = prompt("Ile masz lat?");
wiek = Number(wiek);
console.log("Masz " + wiek + " lat.");
```

---
