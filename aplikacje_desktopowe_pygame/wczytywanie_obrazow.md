### Wczytywanie i wyświetlanie obrazów w Pygame

Pygame umożliwia wczytywanie i wyświetlanie obrazów w różnych formatach graficznych (np. PNG, JPEG). Dzięki temu możemy wzbogacić naszą grę o grafiki, takie jak tła, postacie czy elementy interfejsu.

---

#### **1. Wczytywanie obrazów**

Aby wczytać obraz, używamy funkcji `pygame.image.load()`, która przyjmuje jako argument ścieżkę do pliku graficznego. Funkcja ta zwraca obiekt typu `Surface`, który reprezentuje wczytany obraz.

**Przykład:**
```python
import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Wczytywanie obrazu
image = pygame.image.load('image.png')

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    # Wyświetlanie obrazu
    screen.blit(image, (100, 100))  # Rysowanie obrazu w punkcie (100, 100)

    pygame.display.flip()

pygame.quit()
```

---

#### **2. Obsługa kanału alpha (przezroczystość)**

Pygame obsługuje obrazy z przezroczystością za pomocą kanału alpha. Aby zapewnić poprawne wyświetlanie przezroczystości, należy ustawić odpowiednią kolorkową powierzchnię za pomocą metody `convert_alpha()`. Działa to tylko w przypadku obrazów, które zawierają kanał alfa (np. format PNG).

- **`convert_alpha()`**: Konwertuje obraz, aby obsługiwał kanał alpha, co jest szczególnie ważne dla obrazów z przezroczystością.

**Przykład:**
```python
import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Wczytywanie obrazu z przezroczystością
image = pygame.image.load('pinup_face.png').convert_alpha()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    # Wyświetlanie obrazu z przezroczystością
    screen.blit(image, (100, 100))

    pygame.display.flip()

pygame.quit()
```

---

#### **3. Skalowanie obrazu**

Aby zmienić rozmiar obrazu, używamy funkcji `pygame.transform.scale()`. Przyjmuje ona dwa argumenty:
- **Surface**: Obraz, który chcemy skalować.
- **Nowy rozmiar**: Krotka `(szerokość, wysokość)` definiująca nowy rozmiar obrazu.

**Przykład:**
```python
import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Wczytywanie obrazu
image = pygame.image.load('image.png')

# Skalowanie obrazu
scaled_image = pygame.transform.scale(image, (400, 300))  # Zmiana rozmiaru na 400x300

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    # Wyświetlanie skalowanego obrazu
    screen.blit(scaled_image, (100, 100))

    pygame.display.flip()

pygame.quit()
```

---

#### **4. Obracanie obrazu**

Aby obrócić obraz, używamy funkcji `pygame.transform.rotate()`, która przyjmuje dwa argumenty:
- **Surface**: Obraz, który chcemy obrócić.
- **Kąt obrotu**: Kąt w stopniach, o który obraz ma zostać obrócony (w kierunku przeciwnym do ruchu wskazówek zegara).

**Przykład:**
```python
import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Wczytywanie obrazu
image = pygame.image.load('image.png')

# Obracanie obrazu o 45 stopni
rotated_image = pygame.transform.rotate(image, 45)

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    # Wyświetlanie obróconego obrazu
    screen.blit(rotated_image, (100, 100))

    pygame.display.flip()

pygame.quit()
```

---

#### **5. Wyświetlanie obrazu z poprawnym wyrównaniem po obrocie**

Po obróceniu obrazu jego wymiary mogą się zmienić, a wstawienie go w określone miejsce może sprawiać problemy z wyrównaniem. Aby rozwiązać ten problem, możemy użyć metody `get_rect()` do uzyskania prostokąta obrazka, który umożliwia odpowiednie wyrównanie po obrocie.

**Przykład:**
```python
import pygame

pygame.init()


# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Wczytywanie obrazu
image = pygame.image.load('image.png')

# Obracanie obrazu o 45 stopni
rotated_image = pygame.transform.rotate(image, 45)

# Uzyskiwanie prostokąta obrazka po obrocie
rotated_rect = rotated_image.get_rect(center=(400, 300))

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    # Wyświetlanie obróconego obrazu z poprawnym wyrównaniem
    screen.blit(rotated_image, rotated_rect.topleft)

    pygame.display.flip()

pygame.quit()
```

