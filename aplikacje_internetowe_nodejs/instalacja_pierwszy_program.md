# 📘 LEKCJA 1 — Instalacja Node.js, REPL i pierwszy program

Celem tej lekcji jest:

* upewnić się, że Node działa poprawnie na Twoim Debianie,
* zrozumieć, czym jest REPL,
* nauczyć się uruchamiać pliki `.js` z terminala,
* poznać różnicę między „kodem JS w przeglądarce” a „kodem JS w Node”.

Ta lekcja jest fundamentem — wszystko później będzie się do niej odwoływać.

---

# 1. Czym właściwie jest Node.js?

Node.js to środowisko uruchomieniowe JavaScriptu, które działa **poza przeglądarką**.
W przeglądarce mamy:

* DOM,
* CSS,
* zdarzenia użytkownika,
* ograniczenia bezpieczeństwa.

W Node mamy:

* dostęp do systemu plików (jak w C, Pythonie, Bashu),
* możliwość tworzenia serwerów,
* moduły i paczki npm,
* zdolność do uruchamiania JS jako programu konsolowego.

Można o tym myśleć tak:
**Node = JavaScript jako język backendowy i narzędziowy.**

---

# 2. Sprawdzenie instalacji

W terminalu:

```
node -v
```

Przykład:

```
v18.20.4
```

Wersja 18 to LTS, stabilna i powszechnie używana.

Sprawdzenie npm:

```
npm -v
```

npm (Node Package Manager) to menedżer paczek — coś jak pip w Pythonie czy apt w Debianie.

---

# 3. REPL — interaktywny interpreter Node.js

REPL to skrót:

**R – Read**
**E – Evaluate**
**P – Print**
**L – Loop**

W praktyce to „żywe środowisko” do testowania kodu.

Uruchamiasz:

```
node
```

Pojawia się:

```
Welcome to Node.js v18.20.4.
Type ".help" for more information.
>
```

To środowisko potrafi:

* wykonywać pojedyncze linie JS,
* trzymać zmienne między poleceniami,
* testować funkcje i fragmenty kodu.

Przykłady:

```
> 2+2
4

> let x = 10
undefined

> x * 3
30

> console.log("Test wiadomości")
Test wiadomości
undefined
```

Wynik `undefined` oznacza, że `console.log()` niczego nie zwraca.

Wyjście z REPL:
`Ctrl + C`, potem jeszcze raz `Ctrl + C`.

---

# 4. Pierwszy plik .js i uruchamianie kodu z terminala

REPL służy do eksperymentów, ale prawdziwe programy zapisuje się w plikach `.js`.

Stwórz plik:

```
nano hello.js
```

Wpisz:

```js
console.log("Witaj w Node.js z pliku!");
```

Zapisz:
`Ctrl + O`, Enter
Wyjście:
`Ctrl + X`

Uruchom:

```
node hello.js
```

Efekt:

```
Witaj w Node.js z pliku!
```

W tym momencie masz już działające środowisko programistyczne.

---

# 5. Różnica: JS w przeglądarce vs JS w Node.js

## W przeglądarce:

Masz dostęp do:

* `document`
* `window`
* elementów HTML

Nie masz dostępu do:

* systemu plików,
* sieci w trybie niskopoziomowym,
* funkcji systemowych.

## W Node:

Masz dostęp do:

* `fs` – praca z plikami,
* `http` – serwery i zapytania,
* `os` – informacje o systemie,
* `child_process` – uruchamianie innych programów,
* bibliotek z npm.

Nie masz dostępu do:

* `document`,
* `localStorage`,
* DOM.

---

# 6. Prosta diagnostyka: sprawdź, czy Node działa poprawnie

Możesz wykonać kilka testów:

### Test 1 — logowanie

```js
console.log("Node działa");
```

### Test 2 — obliczenia

```js
console.log(100 * 42);
```

### Test 3 — utworzenie funkcji

```js
function greet(name) {
    return "Cześć, " + name;
}

console.log(greet("Marcin"));
```

### Test 4 — tablice i obiekty

```js
let arr = [1, 2, 3];
console.log(arr.map(x => x * 2));

let user = { id: 1, name: "Kasia" };
console.log(user);
```

Jeśli wszystko działa — środowisko jest w pełni przygotowane.

---

# 7. Najważniejsze rzeczy do zapamiętania z tej lekcji

* Node pozwala uruchamiać JavaScript jak normalne programy.
* REPL służy do szybkiego testowania kodu.
* Programy zapisujesz do plików `.js` i uruchamiasz komendą `node plik.js`.
* Node nie ma DOM-u, ale ma moduły systemowe i dostęp do plików.
* Ta lekcja tworzy fundament do serwerów, obsługi plików, modułów i npm.


