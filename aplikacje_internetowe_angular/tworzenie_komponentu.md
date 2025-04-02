### **1. Tworzenie własnego komponentu**
Angular działa na komponentach. Każdy komponent to niezależny element aplikacji (np. przycisk, nagłówek, karta itp.).  
Spróbujmy stworzyć własny komponent `hello-world`. W Angularze 15 i nowszych używamy podejścia **standalone**, co oznacza, że komponenty mogą działać samodzielnie, bez potrzeby używania modułów.

#### **Utwórz nowy komponent**
W terminalu wpisz:  
```sh
ng generate component hello-world --standalone
```
lub skróconą wersję:  
```sh
ng g c hello-world --standalone
```
To utworzy katalog `src/app/hello-world/` z plikami:
- `hello-world.component.ts` – logika komponentu
- `hello-world.component.html` – szablon HTML
- `hello-world.component.css` – style
- `hello-world.component.spec.ts` – testy (możesz na razie pominąć)

---

### **2. Dodanie komponentu do widoku**
Edytuj `hello-world.component.html` i wpisz:  
```html
<h2>Hello from my first Angular component!</h2>
```
Teraz otwórz `src/app/app.component.html` i dodaj swój nowy komponent:  
```html
<h1>Welcome to My Angular App!</h1>
<app-hello-world></app-hello-world>
```

W **Angularze standalone** nie musisz dodawać komponentu do modułu, wystarczy dodać go do `imports` w dekoratorze `@Component` w `app.component.ts`.

---

### **3. Dodanie komponentu do `app.component.ts`**
Otwórz `app.component.ts` i zaimportuj `HelloWorldComponent` oraz dodaj go do `imports`:

```ts
import { Component } from '@angular/core';
import { HelloWorldComponent } from './hello-world/hello-world.component'; // Import komponentu

@Component({
  selector: 'app-root',
  standalone: true, // Aplikacja standalone
  imports: [HelloWorldComponent], // Dodaj komponent do imports
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'my-angular-app';
}
```

Uruchom aplikację:  
```sh
ng serve
```
i zobacz efekt w przeglądarce (`http://localhost:4200/`).

---

### **4. Dodanie dynamicznych danych**
Edytuj `hello-world.component.ts`:  
```ts
import { Component } from '@angular/core';

@Component({
  selector: 'app-hello-world',
  templateUrl: './hello-world.component.html',
  styleUrls: ['./hello-world.component.css']
})
export class HelloWorldComponent {
  message: string = "Hello from Angular!";
}
```
Teraz w `hello-world.component.html` użyj interpolacji `{{}}`:  
```html
<h2>{{ message }}</h2>
```
Efekt? Angular automatycznie wstawi zawartość zmiennej `message` do HTML.

---

### **5. Obsługa zdarzeń**
Dodaj przycisk do `hello-world.component.html`:  
```html
<h2>{{ message }}</h2>
<button (click)="changeMessage()">Change Message</button>
```
i funkcję w `hello-world.component.ts`:  
```ts
export class HelloWorldComponent {
  message: string = "Hello from Angular!";

  changeMessage() {
    this.message = "You clicked the button!";
  }
}
```
Teraz po kliknięciu przycisku tekst się zmieni.
