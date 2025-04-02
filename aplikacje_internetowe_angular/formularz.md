**Obsługa formularzy w Angular Standalone (wersja 15+)

### Tworzenie aplikacji
1. Stwórz nową aplikację Angular:
   ```sh
   ng new my-angular-app --standalone
   cd my-angular-app
   ````

2. Uruchom aplikację:
   ```sh
   ng serve
   ```

### Implementacja formularza

#### **Plik: `app.component.ts`**
```typescript
import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { CommonModule } from '@angular/common';

@Component({
  selector: 'app-root',
  standalone: true,
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
  imports: [FormsModule, CommonModule]
})
export class AppComponent {
  name: string = "";
  age: number | null = null;
  message: string = "";

  processForm() {
    if (this.name && this.age !== null) {
      this.message = `Cześć, ${this.name}! Masz ${this.age} lat.`;
    } else {
      this.message = "Proszę wypełnić wszystkie pola!";
    }
  }
}
```

#### **Plik: `app.component.html`**
```html
<h1>Formularz</h1>
<form (ngSubmit)="processForm()">
  <label for="name">Imię:</label>
  <input type="text" id="name" [(ngModel)]="name" name="name" required>

  <label for="age">Wiek:</label>
  <input type="number" id="age" [(ngModel)]="age" name="age" required>

  <button type="submit">Wyślij</button>
</form>

<h2 *ngIf="message">{{ message }}</h2>
```

### **Podsumowanie**
- W `@Component` dodano `imports: [FormsModule, CommonModule]`, aby obsłużyć `ngModel` oraz `*ngIf`.
- W `processForm()` sprawdzamy, czy użytkownik wypełnił formularz.
- Formularz binduje dane z użyciem `[(ngModel)]` do zmiennych `name` i `age`.
- Po przesłaniu formularza wyświetlana jest wiadomość z wprowadzonymi danymi.

Teraz możesz testować obsługę formularzy w Angular!

