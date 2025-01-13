### Struktura podstawowego programu w Pygame

Podstawowy program w Pygame składa się z następujących elementów:

1. **Inicjalizacja Pygame**  
   Każdy program w Pygame zaczyna się od inicjalizacji, która przygotowuje bibliotekę do działania:  
   ```python
   import pygame
   pygame.init()
   ```

2. **Tworzenie okna gry**  
   Okno gry jest kluczowym elementem aplikacji. Możesz je utworzyć za pomocą `pygame.display.set_mode()`:  
   ```python
   screen = pygame.display.set_mode((800, 600))  # Szerokość 800px, wysokość 600px
   pygame.display.set_caption("Moja pierwsza gra")  # Tytuł okna
   ```

3. **Pętla gry**  
   Pętla gry to serce aplikacji. Obsługuje zdarzenia, aktualizuje logikę gry i renderuje grafikę:  
   ```python
   running = True
   while running:
       for event in pygame.event.get():
           if event.type == pygame.QUIT:  # Zamknięcie okna
               running = False
       screen.fill((0, 0, 0))  # Wypełnienie okna kolorem (czarny)
       pygame.display.flip()  # Aktualizacja wyświetlacza
   ```

4. **Zakończenie programu**  
   Na końcu należy zwolnić zasoby i zakończyć Pygame:  
   ```python
   pygame.quit()
   ```

### Przykładowy minimalny program
```python
import pygame

# Inicjalizacja Pygame
pygame.init()

# Tworzenie okna gry
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Moja pierwsza gra")

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((0, 0, 0))  # Czarny kolor tła
    pygame.display.flip()  # Aktualizacja okna

# Zakończenie programu
pygame.quit()
```

Dzięki tej strukturze możesz rozwijać swoje aplikacje, dodając kolejne funkcjonalności, takie jak obsługa zdarzeń, animacje czy logika gry.
