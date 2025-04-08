
## 📌 Okna przeglądarki w JavaScript

JavaScript w przeglądarce umożliwia wyświetlanie okien dialogowych do interakcji z użytkownikiem.

---

### 🟡 `alert()`

- Pokazuje prosty komunikat.
- Nie zwraca żadnej wartości.
  
```js
alert("To jest alert!");
```

➡️ Użytkownik może tylko kliknąć „OK”.

---

### 🟡 `prompt()`

- Pyta użytkownika o dane tekstowe.
- Zwraca wpisany tekst **jako string** albo `null`, jeśli użytkownik kliknie „Anuluj”.

```js
let imie = prompt("Jak masz na imię?");
console.log("Witaj, " + imie + "!");
```

Jeśli chcesz przekonwertować wpis na liczbę:

```js
let wiek = Number(prompt("Ile masz lat?"));
```

---

### 🟡 `confirm()`

- Pytanie z przyciskiem **OK** i **Anuluj**.
- Zwraca `true`, jeśli użytkownik kliknie OK, lub `false`, jeśli Anuluj.

```js
let kontynuuj = confirm("Czy chcesz kontynuować?");
console.log("Użytkownik kliknął:", kontynuuj);
```

---

## 📌 Przykład użycia wszystkich trzech:

```js
alert("Witaj na stronie!");

let imie = prompt("Jak masz na imię?");
let kontynuuj = confirm("Czy chcesz zobaczyć powitanie?");

if (kontynuuj) {
    alert("Miło Cię widzieć, " + imie + "!");
} else {
    alert("Do zobaczenia!");
}
```
