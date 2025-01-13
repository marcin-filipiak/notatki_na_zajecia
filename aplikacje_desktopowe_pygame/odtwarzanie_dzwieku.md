Oto poprawiona wersja notatki, która zawiera przykłady działające w pętli głównej programu oraz uruchamiające okno aplikacji:

---

### Odtwarzanie dźwięku w Pygame

W Pygame odtwarzanie dźwięku jest realizowane za pomocą modułu `pygame.mixer`. Umożliwia on obsługę krótkich efektów dźwiękowych oraz dłuższych utworów muzycznych, które mogą być odtwarzane w tle gry. Poniżej przedstawiono kroki i przykłady implementacji.

---

#### **1. Inicjalizacja modułu dźwiękowego i tworzenie okna**

Aby rozpocząć pracę z dźwiękiem i aplikacją graficzną, należy zainicjalizować moduł `pygame.mixer` oraz warto stworzyć okno aplikacji (by aplikacja nie zamknęła się nim dźwięk zostanie odtworzony).

```python
import pygame

pygame.init()  # Inicjalizacja wszystkich modułów, w tym dźwiękowego

# Tworzenie okna aplikacji
screen = pygame.display.set_mode((800, 600))  # Wymiary okna: 800x600 pikseli
pygame.display.set_caption("Pygame: Odtwarzanie dźwięku")  # Tytuł okna
```

---

#### **2. Ładowanie i odtwarzanie dźwięków**

##### **Efekty dźwiękowe**
Do odtwarzania krótkich efektów dźwiękowych, takich jak kroki czy wybuchy, używamy klasy `pygame.mixer.Sound`.

**Przykład:**
```python
import pygame

pygame.init()
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Efekty dźwiękowe")

# Ładowanie efektu dźwiękowego
sound = pygame.mixer.Sound("effect.wav")

# Pętla główna
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:  # Odtwarzanie dźwięku po naciśnięciu klawisza
            sound.play()

    screen.fill((50, 50, 50))  # Tło aplikacji
    pygame.display.flip()  # Odświeżanie ekranu

pygame.quit()
```

---

##### **Muzyka w tle**
Dłuższe utwory muzyczne mogą być odtwarzane w tle aplikacji za pomocą funkcji `pygame.mixer.music`.

**Przykład:**
```python
import pygame

pygame.init()
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Muzyka w tle")

# Ładowanie i odtwarzanie muzyki
pygame.mixer.music.load("background.mp3")
pygame.mixer.music.play(-1)  # Odtwarzanie w pętli (-1 oznacza nieskończone powtórzenia)

# Pętla główna
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((30, 30, 30))  # Tło aplikacji
    pygame.display.flip()

pygame.quit()
```

---

#### **3. Ustawianie głośności i wyciszanie dźwięków**

Dźwięki i muzyka w Pygame mają niezależne ustawienia głośności, które można dostosować za pomocą metody `set_volume()`.

**Przykład:**
```python
import pygame

pygame.init()
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Ustawianie głośności")

# Ładowanie efektu i muzyki
sound = pygame.mixer.Sound("effect.wav")
pygame.mixer.music.load("background.mp3")

pygame.mixer.music.set_volume(0.5)  # Ustawienie głośności muzyki na 50%
sound.set_volume(0.8)  # Ustawienie głośności efektu na 80%
pygame.mixer.music.play(-1)

# Pętla główna
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:  # Odtwarzanie dźwięku po naciśnięciu klawisza
            sound.play()

    screen.fill((20, 20, 20))  # Tło aplikacji
    pygame.display.flip()

pygame.quit()
```

---

#### **4. Stopniowe wyciszanie muzyki**

Muzykę można stopniowo wyciszać, co jest przydatne np. podczas przejść między scenami.

**Przykład:**
```python
import pygame

pygame.init()
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Wyciszanie muzyki")

pygame.mixer.music.load("background.mp3")
pygame.mixer.music.play()

# Pętla główna
running = True
fade_started = False  # Flaga informująca o rozpoczęciu wyciszania
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN and not fade_started:
            pygame.mixer.music.fadeout(3000)  # Wyciszenie w ciągu 3 sekund
            fade_started = True

    screen.fill((10, 10, 10))  # Tło aplikacji
    pygame.display.flip()

pygame.quit()
```

---

#### **Podsumowanie**

W Pygame można odtwarzać muzykę i efekty dźwiękowe w tle aplikacji. Najważniejsze funkcje:
- **Efekty dźwiękowe:** `pygame.mixer.Sound` z metodami `play()` i `set_volume()`.
- **Muzyka w tle:** `pygame.mixer.music` z metodami `play()`, `set_volume()`, `fadeout()`.
- **Obsługa błędów:** warto sprawdzać, czy pliki dźwiękowe istnieją i są obsługiwane przez Pygame.

Używanie dźwięku w grach pozwala wzbogacić rozgrywkę o immersyjne efekty i podkreślić atmosferę.
