### Rysowanie figur i linii w Pygame

Rysowanie figur geometrycznych i linii jest podstawową funkcjonalnością w Pygame, wykorzystywaną do tworzenia grafiki w grach i aplikacjach. Pygame udostępnia funkcje do rysowania prostokątów, okręgów, linii, elips, a także pozwala na wypełnianie tych kształtów kolorami.

---

#### **1. Rysowanie linii**

Aby narysować linię, używamy funkcji `pygame.draw.line()`. Funkcja ta przyjmuje kilka parametrów:

- **Surface**: Obiekt, na którym rysujemy (np. ekran).
- **Kolor**: Kolor linii, zapisany w formacie RGB.
- **Początkowy punkt**: Krotka `(x1, y1)` definiująca początek linii.
- **Końcowy punkt**: Krotka `(x2, y2)` definiująca koniec linii.
- **Grubość linii** *(opcjonalne)*: Liczba określająca grubość linii.

**Przykład:**
```python
import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Rysowanie linii
pygame.draw.line(screen, (255, 0, 0), (100, 100), (700, 500), 5)

pygame.display.flip()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
```

---

#### **2. Rysowanie prostokątów**

Prostokąty można rysować za pomocą funkcji `pygame.draw.rect()`. Funkcja ta przyjmuje następujące parametry:

- **Surface**: Obiekt, na którym rysujemy (np. ekran).
- **Kolor**: Kolor prostokąta, zapisany w formacie RGB.
- **Rect**: Krotka `(x, y, szerokość, wysokość)`, która określa pozycję i rozmiar prostokąta.
- **Grubość krawędzi** *(opcjonalne)*: Liczba określająca grubość linii (domyślnie wypełnia prostokąt).

**Przykład:**
```python
import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Rysowanie prostokąta
pygame.draw.rect(screen, (0, 255, 0), (150, 150, 200, 100))

pygame.display.flip()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
```

---

#### **3. Rysowanie okręgów**

Aby narysować okrąg, używamy funkcji `pygame.draw.circle()`. Funkcja ta przyjmuje:

- **Surface**: Obiekt, na którym rysujemy (np. ekran).
- **Kolor**: Kolor okręgu, zapisany w formacie RGB.
- **Środek**: Krotka `(x, y)` określająca środek okręgu.
- **Promień**: Wartość określająca promień okręgu.
- **Grubość linii** *(opcjonalne)*: Liczba określająca grubość linii okręgu (domyślnie wypełnia okrąg).

**Przykład:**
```python
import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Rysowanie okręgu
pygame.draw.circle(screen, (0, 0, 255), (400, 300), 100)

pygame.display.flip()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
```

---

#### **4. Rysowanie elips**

Elipsę rysujemy za pomocą funkcji `pygame.draw.ellipse()`. Parametry funkcji są podobne do tych, które wykorzystujemy w przypadku prostokątów:

- **Surface**: Obiekt, na którym rysujemy (np. ekran).
- **Kolor**: Kolor elipsy, zapisany w formacie RGB.
- **Rect**: Krotka `(x, y, szerokość, wysokość)`, która określa prostokąt, w którym mieści się elipsa.
- **Grubość linii** *(opcjonalne)*: Liczba określająca grubość linii elipsy (domyślnie wypełnia elipsę).

**Przykład:**
```python
import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Rysowanie elipsy
pygame.draw.ellipse(screen, (255, 255, 0), (200, 150, 400, 200))

pygame.display.flip()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
```

---

#### **5. Rysowanie wielokątów**

Wielokąty rysujemy za pomocą funkcji `pygame.draw.polygon()`. Funkcja ta przyjmuje:

- **Surface**: Obiekt, na którym rysujemy (np. ekran).
- **Kolor**: Kolor wielokąta, zapisany w formacie RGB.
- **Lista punktów**: Lista krotek `(x, y)`, które definiują wierzchołki wielokąta.
- **Grubość linii** *(opcjonalne)*: Liczba określająca grubość linii wielokąta (domyślnie wypełnia wielokąt).

**Przykład:**
```python
import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Rysowanie wielokąta
points = [(100, 100), (200, 50), (300, 100), (250, 200), (150, 200)]
pygame.draw.polygon(screen, (255, 0, 255), points)

pygame.display.flip()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
```
