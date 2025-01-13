### Wczytywanie czcionek w Pygame

W Pygame obsługa tekstu i czcionek odbywa się za pomocą modułu `pygame.font`. Umożliwia on ładowanie czcionek, wyświetlanie tekstu w różnych stylach i rozmiarach, a także renderowanie tekstu jako powierzchni graficznej.

---

#### **1. Inicjalizacja modułu czcionek**

Moduł `pygame.font` jest automatycznie inicjalizowany podczas wywołania `pygame.init()`. Nie trzeba go więc osobno uruchamiać. 

---

#### **2. Wczytywanie czcionek**

##### **a) Systemowe czcionki**
Do wczytania domyślnej czcionki systemowej wystarczy użyć metody `pygame.font.Font` z argumentem `None`.

**Przykład:**
```python
import pygame

pygame.init()
font = pygame.font.Font(None, 36)  # Domyślna czcionka, rozmiar 36
```

##### **b) Własne czcionki**
Pygame umożliwia użycie plików czcionek w formacie TTF (TrueType Font). 

**Przykład:**
```python
import pygame

pygame.init()
font = pygame.font.Font("arial.ttf", 36)  # Wczytanie czcionki Arial, rozmiar 36
```

---

#### **3. Renderowanie tekstu**

Aby wyświetlić tekst na ekranie, należy go najpierw wyrenderować jako powierzchnię (`Surface`) za pomocą metody `render()`.

**Składnia:**
```python
font.render(text, antialias, color, background=None)
```
- `text` – tekst do wyrenderowania.
- `antialias` – wygładzanie krawędzi tekstu (True lub False).
- `color` – kolor tekstu (w formacie RGB, np. `(255, 255, 255)`).
- `background` – kolor tła (opcjonalny, domyślnie przezroczysty).

**Przykład:**
```python
import pygame

pygame.init()
screen = pygame.display.set_mode((400, 300))
font = pygame.font.Font(None, 48)  # Domyślna czcionka, rozmiar 48
text_surface = font.render("Witaj, świecie!", True, (255, 255, 255))  # Biały tekst
screen.blit(text_surface, (50, 100))  # Rysowanie tekstu na ekranie
pygame.display.flip()

pygame.time.delay(3000)
```

---

#### **4. Wyświetlanie tekstu w pętli gry**

W praktyce tekst jest zwykle wyświetlany w pętli głównej gry, aby był dynamicznie odświeżany.

**Przykład:**
```python
import pygame

pygame.init()
screen = pygame.display.set_mode((400, 300))
clock = pygame.time.Clock()

font = pygame.font.Font(None, 48)

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((0, 0, 0))  # Czyszczenie ekranu
    text_surface = font.render("Pygame Font Demo", True, (255, 255, 0))
    screen.blit(text_surface, (50, 100))
    
    pygame.display.flip()
    clock.tick(60)
pygame.quit()
```

---

#### **5. Skalowanie tekstu**

Można tworzyć różne instancje czcionek o różnych rozmiarach, co pozwala na dynamiczne dostosowanie tekstu.

**Przykład:**
```python
font_small = pygame.font.Font(None, 24)
font_large = pygame.font.Font(None, 72)

text_small = font_small.render("Mały tekst", True, (255, 255, 255))
text_large = font_large.render("Duży tekst", True, (255, 0, 0))
```

---

#### **6. Obsługa błędów**

Jeśli czcionka nie istnieje, Pygame może zwrócić błąd. Warto zadbać o odpowiednią obsługę wyjątków.

**Przykład:**
```python
try:
    font = pygame.font.Font("brak_czcionki.ttf", 36)
except FileNotFoundError:
    print("Nie znaleziono pliku czcionki.")
    font = pygame.font.Font(None, 36)  # Domyślna czcionka
```

---

#### **Podsumowanie**

- Używaj `pygame.font.Font` do ładowania domyślnych i niestandardowych czcionek.
- Tekst renderuj jako powierzchnie za pomocą `render()`.
- Kolory i wygładzanie krawędzi mogą być dostosowane w metodzie `render`.
- Czcionki TTF oferują szeroką możliwość personalizacji wizualnej tekstu. 

Pygame pozwala na proste i elastyczne zarządzanie tekstem, dzięki czemu można łatwo dostosować jego wygląd do stylu gry lub aplikacji.
