### Inicjalizacja Pygame i tworzenie okna

Inicjalizacja i tworzenie okna to podstawowe kroki w każdym programie napisanym w Pygame. Pozwala to na przygotowanie środowiska do pracy z grafiką, obsługą zdarzeń i innymi elementami potrzebnymi do tworzenia gier.

---

#### **1. Inicjalizacja Pygame**

- Wszystkie moduły Pygame muszą zostać zainicjowane przed ich użyciem.  
  Inicjalizacja odbywa się za pomocą:  
  ```python
  pygame.init()
  ```
- Funkcja `pygame.init()` zwraca dwie liczby:  
  - Liczba zainicjalizowanych modułów.
  - Liczba modułów, których nie udało się zainicjalizować.  
  Można to wykorzystać do weryfikacji, czy wszystko działa poprawnie:
  ```python
  initialized, failed = pygame.init()
  print(f"Zainicjalizowano {initialized} modułów, niepowodzenia: {failed}")
  ```

---

#### **2. Tworzenie okna gry**

Okno aplikacji w Pygame jest tworzone za pomocą funkcji `pygame.display.set_mode()`. Funkcja ta przyjmuje dwa kluczowe argumenty:

1. **Rozmiar okna**  
   Rozmiar definiowany jest jako krotka `(szerokość, wysokość)`:
   ```python
   screen = pygame.display.set_mode((800, 600))  # Okno o wymiarach 800x600 pikseli
   ```

2. **Flagi okna** *(opcjonalne)*  
   Można dostosować właściwości okna za pomocą flag, takich jak:  
   - `pygame.FULLSCREEN`: Tworzy pełnoekranowe okno.  
   - `pygame.RESIZABLE`: Pozwala użytkownikowi zmieniać rozmiar okna.  
   - `pygame.NOFRAME`: Tworzy okno bez ramki.  

   Przykład:
   ```python
   screen = pygame.display.set_mode((800, 600), pygame.RESIZABLE)
   ```

3. **Głębia kolorów** *(opcjonalne)*  
   Określa liczbę bitów używanych na kanał koloru. Domyślnie Pygame wybiera odpowiednią głębię dla systemu:
   ```python
   screen = pygame.display.set_mode((800, 600), pygame.NOFRAME, 32)  # 32-bitowa głębia kolorów
   ```

---

#### **3. Ustawienia dodatkowe okna**

1. **Tytuł okna**  
   Tytuł wyświetlany na pasku okna można ustawić za pomocą:
   ```python
   pygame.display.set_caption("Moja pierwsza gra")
   ```

2. **Ikona okna**  
   Możesz zmienić ikonę wyświetlaną w pasku okna:
   ```python
   icon = pygame.image.load("icon.png")  # Wczytaj plik z ikoną
   pygame.display.set_icon(icon)
   ```

3. **Wymiary ekranu** *(Dynamiczne)*  
   Wymiary ekranu urządzenia można uzyskać za pomocą funkcji:
   ```python
   info = pygame.display.Info()
   print(f"Szerokość: {info.current_w}, Wysokość: {info.current_h}")
   ```

---

#### **4. Pętla wyświetlania okna**

Pętla główna programu odpowiada za ciągłe odświeżanie okna, obsługę zdarzeń i aktualizację elementów graficznych. Minimalna wersja wygląda następująco:
```python
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:  # Zamknięcie okna
            running = False
    pygame.display.flip()  # Aktualizacja zawartości okna
```

---

#### **5. Zamykanie programu**

Na zakończenie programu należy zwolnić zasoby i zamknąć moduły Pygame:
```python
pygame.quit()
```

---

### Przykład: Tworzenie pełnoekranowego i standardowego okna
```python
import pygame

# Inicjalizacja Pygame
pygame.init()

# Tworzenie standardowego okna
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Standardowe okno")

# Tworzenie pełnoekranowego okna
# screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
# pygame.display.set_caption("Pełnoekranowe okno")

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    screen.fill((0, 128, 128))  # Wypełnienie kolorem
    pygame.display.flip()

# Zamknięcie Pygame
pygame.quit()
```

---

Dzięki różnym opcjom tworzenia okna możesz dostosować swój program do różnych scenariuszy, takich jak pełnoekranowe gry, dynamiczne rozmiary okien lub minimalistyczne aplikacje bez ramek.
