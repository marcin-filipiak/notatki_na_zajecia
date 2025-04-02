### **Routing w Angular (standalone, wersja 15+)**

Routing w Angular pozwala na nawigację między różnymi widokami aplikacji.

---

### **1. Konfiguracja routingu**
W pliku `src/app/app.routes.ts` zdefiniuj ścieżki:

```ts
import { Routes } from '@angular/router';
import { HomeComponent } from './home/home.component';
import { AboutComponent } from './about/about.component';

export const routes: Routes = [
  { path: '', component: HomeComponent },
  { path: 'about', component: AboutComponent }
];
```

---

### **2. Konfiguracja głównego komponentu**
W pliku `src/app/app.component.ts` zaimportuj `RouterOutlet` oraz `RouterLink`:

```ts
import { Component } from '@angular/core';
import { RouterOutlet, RouterLink } from '@angular/router';

@Component({
  selector: 'app-root',
  standalone: true,
  templateUrl: './app.component.html',
  imports: [RouterOutlet, RouterLink]
})
export class AppComponent {}
```

---

### **3. Tworzenie komponentów**
W terminalu utwórz dwa komponenty:

```sh
ng g c home --standalone
ng g c about --standalone
```

To wygeneruje pliki `home.component.ts` i `about.component.ts`.

---

### **4. Dodanie treści do komponentów**
#### `home.component.ts`
```ts
import { Component } from '@angular/core';

@Component({
  selector: 'app-home',
  standalone: true,
  template: `<h2>Home Page</h2>`
})
export class HomeComponent {}
```

#### `about.component.ts`
```ts
import { Component } from '@angular/core';

@Component({
  selector: 'app-about',
  standalone: true,
  template: `<h2>About Page</h2>`
})
export class AboutComponent {}
```

---

### **5. Modyfikacja `app.component.html`**
Dodaj linki nawigacyjne oraz `router-outlet`:

```html
<h1>Welcome to My Angular App!</h1>
<nav>
  <a routerLink="/">Home</a> | <a routerLink="/about">About</a>
</nav>
<router-outlet></router-outlet>
```

---

### **6. Integracja routingu w `main.ts`**
Otwórz `src/main.ts` i zarejestruj routing:

```ts
import { bootstrapApplication } from '@angular/platform-browser';
import { AppComponent } from './app/app.component';
import { provideRouter } from '@angular/router';
import { routes } from './app/app.routes';

bootstrapApplication(AppComponent, {
  providers: [provideRouter(routes)]
});
```

---

### **7. Uruchomienie aplikacji**
W terminalu uruchom aplikację:

```sh
ng serve
```

Otwórz przeglądarkę i przejdź na `http://localhost:4200/`. Kliknięcie linku **About** powinno przenieść Cię na stronę `http://localhost:4200/about`.


