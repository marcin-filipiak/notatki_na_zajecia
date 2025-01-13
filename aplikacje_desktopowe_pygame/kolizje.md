### Wykrywanie kolizji obiektów w Pygame

Wykrywanie kolizji między obiektami jest istotnym elementem wielu gier, ponieważ pozwala na interakcję między obiektami (np. gracz z przeszkodami, pociskami, innymi postaciami). W Pygame możemy wykorzystywać różne techniki do wykrywania kolizji, zależnie od kształtu obiektów, które chcemy sprawdzać. Poniżej omówimy najpopularniejsze metody wykrywania kolizji w Pygame.

#### **1. Kolizje prostokątnych obiektów (ang. Axis-Aligned Bounding Box, AABB)**

Najprostszym sposobem wykrywania kolizji jest użycie prostokątów (Bounding Boxes). Pygame dostarcza funkcję `pygame.Rect.colliderect()`, która sprawdza, czy dwa prostokąty (obszary) zachodzą na siebie. Każdy obiekt w Pygame posiada swój prostokątny obszar (np. `pygame.Rect`), który jest łatwy do porównania z innymi obiektami.

##### **Przykład kolizji prostokątnych obiektów**
```python
import pygame

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

# Pozycje obiektów
rect1 = pygame.Rect(200, 150, 50, 50)  # Pierwszy prostokąt
rect2 = pygame.Rect(300, 250, 50, 50)  # Drugi prostokąt

clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Sprawdzanie kolizji
    if rect1.colliderect(rect2):
        print("Kolizja!")

    # Rysowanie obiektów
    screen.fill((0, 0, 0))  # Czarny kolor tła
    pygame.draw.rect(screen, (255, 0, 0), rect1)  # Pierwszy prostokąt
    pygame.draw.rect(screen, (0, 255, 0), rect2)  # Drugi prostokąt
    pygame.display.flip()

    clock.tick(60)

pygame.quit()
```
W tym przykładzie, funkcja `colliderect()` sprawdza, czy dwa prostokąty zachodzą na siebie. Jeśli zachodzą, zostanie wyświetlona informacja o kolizji.

#### **2. Kolizje z okręgami**

Jeśli obiekty są reprezentowane jako okręgi (np. kula w grze), wykrywanie kolizji będzie bardziej skomplikowane. Do tego celu możemy użyć matematycznego podejścia: obliczamy odległość między środkami obu okręgów i porównujemy ją z sumą ich promieni.

##### **Przykład kolizji okręgów**
```python
import pygame
import math

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

# Pozycje obiektów
circle1 = (400, 300, 30)  # (x, y, promień)
circle2 = (500, 300, 30)

clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Sprawdzanie kolizji okręgów
    distance = math.sqrt((circle1[0] - circle2[0]) ** 2 + (circle1[1] - circle2[1]) ** 2)
    if distance < (circle1[2] + circle2[2]):  # Odległość < suma promieni
        print("Kolizja!")

    # Rysowanie obiektów
    screen.fill((0, 0, 0))  # Czarny kolor tła
    pygame.draw.circle(screen, (255, 0, 0), (circle1[0], circle1[1]), circle1[2])  # Pierwszy okrąg
    pygame.draw.circle(screen, (0, 255, 0), (circle2[0], circle2[1]), circle2[2])  # Drugi okrąg
    pygame.display.flip()

    clock.tick(60)

pygame.quit()
```
Tutaj, używamy funkcji `math.sqrt()` do obliczenia odległości między środkami okręgów, a następnie porównujemy ją z sumą ich promieni, aby wykryć kolizję.

#### **3. Kolizje między obiektami o nieregularnych kształtach**

Jeśli obiekty mają nieregularne kształty, możemy użyć maski (bitowej reprezentacji kształtu), aby wykryć kolizję. Pygame oferuje funkcję `pygame.mask.from_surface()`, która pozwala na stworzenie maski z powierzchni obiektu i sprawdzanie, czy maski dwóch obiektów nakładają się na siebie.

##### **Przykład kolizji z maską**
```python
import pygame

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

# Tworzenie powierzchni i masek
rect1 = pygame.Surface((50, 50))
rect1.fill((255, 0, 0))
mask1 = pygame.mask.from_surface(rect1)

rect2 = pygame.Surface((50, 50))
rect2.fill((0, 255, 0))
mask2 = pygame.mask.from_surface(rect2)

# Pozycje obiektów
rect1_pos = pygame.Rect(200, 150, 50, 50)
rect2_pos = pygame.Rect(300, 250, 50, 50)

clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Sprawdzanie kolizji maski
    offset = (rect2_pos.x - rect1_pos.x, rect2_pos.y - rect1_pos.y)
    if mask1.overlap(mask2, offset):
        print("Kolizja!")

    # Rysowanie obiektów
    screen.fill((0, 0, 0))  # Czarny kolor tła
    screen.blit(rect1, rect1_pos)  # Pierwszy prostokąt
    screen.blit(rect2, rect2_pos)  # Drugi prostokąt
    pygame.display.flip()

    clock.tick(60)

pygame.quit()
```
Tutaj tworzymy maski dla obiektów za pomocą `pygame.mask.from_surface()` i sprawdzamy, czy maski zachodzą na siebie. Funkcja `overlap()` pozwala na porównanie dwóch masek z uwzględnieniem przesunięcia (`offset`).

#### **4. Kolizje z użyciem wektorów**

Kolizje mogą być także wykrywane za pomocą wektorów, szczególnie w grach, które wymagają bardziej zaawansowanego podejścia fizycznego (np. w grach wyścigowych czy symulacjach). W tym przypadku musimy obliczyć kąt, prędkość i kierunek obiektów, aby wykryć, czy ich trajektorie się przecinają.

#### **5. Kolizje a fizyka**

Po wykryciu kolizji, kolejnym krokiem jest odpowiednia reakcja na nią (np. odbicie, zatrzymanie, zniszczenie obiektu). Pygame nie zapewnia wbudowanej fizyki, ale można to zrealizować samodzielnie, np. za pomocą wektorów odbicia, modyfikacji prędkości lub zewnętrznych bibliotek fizycznych, takich jak `pymunk`.

#### **Podsumowanie**

Wykrywanie kolizji jest kluczowe dla interakcji w grach i może przybierać różne formy, zależnie od kształtu i rodzaju obiektów. Pygame udostępnia różne metody wykrywania kolizji, takie jak:
- **Kolizje prostokątów (AABB)** – najprostsza i najczęściej wykorzystywana metoda.
- **Kolizje okręgów** – dla obiektów o okrągłych kształtach.
- **Kolizje z maskami** – dla bardziej złożonych kształtów.
- **Kolizje z wektorami** – dla bardziej zaawansowanej fizyki gry.

Dzięki tym narzędziom możemy wykrywać kolizje między obiektami, co jest niezbędne w większości gier.
