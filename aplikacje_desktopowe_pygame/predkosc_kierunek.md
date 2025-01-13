### Zmiana prędkości obiektów i kierunku ruchu w Pygame

W Pygame, zmiana prędkości obiektów oraz kierunku ich ruchu jest kluczowym elementem interakcji w grze. W zależności od potrzeb gry, możemy manipulować tymi wartościami, aby osiągnąć efekt dynamicznego poruszania się obiektów w różnych kierunkach. W tej notatce omówimy, jak zmieniać prędkość obiektów oraz jak zmieniać kierunek ich ruchu w odpowiedzi na wejście użytkownika lub inne zdarzenia.

#### **1. Zmiana prędkości obiektów**

Prędkość obiektów w Pygame zazwyczaj jest reprezentowana przez zmienne, które określają, o ile jednostek obiekt przesuwa się w czasie jednej klatki gry. Prędkość ta może być stała lub zmieniać się w zależności od okoliczności, np. w odpowiedzi na działania użytkownika.

##### **Przykład zmiany prędkości obiektu**
Prędkość może być modyfikowana przez przypisanie nowych wartości do zmiennych prędkości. Można ją również uzależnić od zdarzeń w grze, takich jak naciśnięcie klawisza.

```python
import pygame

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

# Pozycja obiektu
x, y = 400, 300
velocity = 5  # Prędkość początkowa
clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Zmiana prędkości w zależności od klawiszy
    keys = pygame.key.get_pressed()
    if keys[pygame.K_UP]:
        velocity += 0.1  # Zwiększenie prędkości
    if keys[pygame.K_DOWN]:
        velocity -= 0.1  # Zmniejszenie prędkości

    # Aktualizacja pozycji
    x += velocity

    # Rysowanie obiektu
    screen.fill((0, 0, 0))  # Czarny kolor tła
    pygame.draw.rect(screen, (255, 0, 0), (x, y, 50, 50))
    pygame.display.flip()

    clock.tick(60)  # Ograniczenie liczby klatek na sekundę

pygame.quit()
```

W tym przykładzie, naciśnięcie strzałki w górę zwiększa prędkość obiektu, a naciśnięcie strzałki w dół ją zmniejsza. Prędkość obiektu jest zmieniana dynamicznie podczas działania gry, co umożliwia interakcję z użytkownikiem.

#### **2. Zmiana kierunku ruchu**

Zmiana kierunku ruchu obiektu zależy od przemieszczenia obiektu w osi X lub Y. Możemy wprowadzać kierunki takie jak ruch w lewo, prawo, w górę czy w dół, kontrolując wartości tych osi.

##### **Przykład zmiany kierunku ruchu**
Aby zmieniać kierunek, wystarczy manipulować współrzędnymi obiektu w zależności od wciśniętych klawiszy. Można to zrobić, dodając lub odejmując wartości od zmiennych `x` i `y`.

```python
import pygame

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

# Pozycja obiektu
x, y = 400, 300
velocity = 5  # Prędkość
clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Zmiana kierunku w zależności od klawiszy
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT]:
        x -= velocity  # Ruch w lewo
    if keys[pygame.K_RIGHT]:
        x += velocity  # Ruch w prawo
    if keys[pygame.K_UP]:
        y -= velocity  # Ruch w górę
    if keys[pygame.K_DOWN]:
        y += velocity  # Ruch w dół

    # Rysowanie obiektu
    screen.fill((0, 0, 0))  # Czarny kolor tła
    pygame.draw.rect(screen, (255, 0, 0), (x, y, 50, 50))
    pygame.display.flip()

    clock.tick(60)

pygame.quit()
```

W tym przypadku, wciśnięcie klawisza strzałki w prawo zwiększa wartość `x`, a strzałka w lewo ją zmniejsza. Strzałki w górę i w dół zmieniają odpowiednio wartość `y`.

#### **3. Ruch w różnych kierunkach**

Aby umożliwić ruch w różnych kierunkach (np. ruch ukośny, w lewo i w górę jednocześnie), wystarczy jednocześnie modyfikować zarówno `x`, jak i `y`.

##### **Przykład ruchu ukośnego**
```python
import pygame

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

# Pozycja obiektu
x, y = 400, 300
velocity = 5
clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Ruch w różnych kierunkach
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT]:
        x -= velocity
    if keys[pygame.K_RIGHT]:
        x += velocity
    if keys[pygame.K_UP]:
        y -= velocity
    if keys[pygame.K_DOWN]:
        y += velocity

    # Rysowanie obiektu
    screen.fill((0, 0, 0))
    pygame.draw.rect(screen, (255, 0, 0), (x, y, 50, 50))
    pygame.display.flip()

    clock.tick(60)

pygame.quit()
```

W tym przypadku, jeśli wciśniemy klawisze w lewo i w górę, obiekt będzie poruszać się w kierunku lewego górnego rogu.

#### **4. Zmiana kierunku na podstawie fizyki gry**

Czasami kierunek ruchu zależy od fizyki gry, np. od prędkości lub przyspieszenia obiektu. Można to osiągnąć poprzez odpowiednie manipulowanie wektorami prędkości, które określają nie tylko wartość, ale i kierunek ruchu.

**Przykład z wektorem prędkości:**
```python
import pygame
import math

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

# Pozycja obiektu
x, y = 400, 300
velocity = 5
angle = 0  # Kąt w kierunku ruchu
speed_x = velocity * math.cos(math.radians(angle))
speed_y = velocity * math.sin(math.radians(angle))

clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Zmiana kąta i prędkości
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT]:
        angle -= 1  # Zmiana kąta w lewo
    if keys[pygame.K_RIGHT]:
        angle += 1  # Zmiana kąta w prawo

    # Przeliczanie nowych wartości prędkości
    speed_x = velocity * math.cos(math.radians(angle))
    speed_y = velocity * math.sin(math.radians(angle))

    # Aktualizacja pozycji
    x += speed_x
    y += speed_y

    # Rysowanie obiektu
    screen.fill((0, 0, 0))
    pygame.draw.rect(screen, (255, 0, 0), (x, y, 50, 50))
    pygame.display.flip()

    clock.tick(60)

pygame.quit()
```

W tym przykładzie, obiekt porusza się w kierunku określonym przez kąt (`angle`), a jego prędkość jest obliczana przy użyciu funkcji trygonometrycznych.

#### **5. Przydatne funkcje**
- **`pygame.key.get_pressed()`**: Pobiera stan wszystkich klawiszy (naciśnięte/nie naciśnięte).
- **`math.cos()`** i **`math.sin()`**: Funkcje trygonometryczne do obliczania składowych prędkości w kierunkach X i Y na podstawie kąta.
- **Zmienna prędkości**: Manipulacja zmienną prędkości pozwala na kontrolowanie tempa ruchu obiektu.
