### Aktualizacja pozycji obiektów w pętli gry

W Pygame, aktualizacja pozycji obiektów w pętli gry jest niezbędnym elementem tworzenia dynamicznego i interaktywnego środowiska. Aktualizacja pozycji obiektów polega na przetwarzaniu ich zmian w czasie, które są zależne od różnych czynników, takich jak ruch użytkownika, fizyka gry czy zdarzenia interaktywne.

#### **1. Aktualizacja pozycji obiektów**

Aby zaktualizować pozycję obiektu w Pygame, często korzysta się z matematyki związanej z ruchem oraz zmiennych kontrolujących jego prędkość i kierunek. W pętli gry, każda iteracja sprawdza pozycję obiektów, przelicza ich nowe położenie i odświeża widok gry.

**Przykład:**
```python
import pygame

pygame.init()

# Rozmiar okna gry
screen = pygame.display.set_mode((800, 600))
running = True

# Pozycja obiektu
x, y = 400, 300
velocity = 5  # Prędkość poruszania się obiektu

# Pętla gry
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Aktualizacja pozycji obiektu (ruch w prawą stronę)
    x += velocity

    # Odświeżanie ekranu
    screen.fill((0, 0, 0))  # Czarny kolor tła
    pygame.draw.rect(screen, (255, 0, 0), (x, y, 50, 50))  # Czerwony kwadrat
    pygame.display.flip()

    # Spowolnienie klatki
    pygame.time.Clock().tick(60)

pygame.quit()
```

W tym przykładzie, prędkość ruchu obiektu (`velocity`) jest dodawana do jego współrzędnej x w każdej iteracji pętli gry, co pozwala na płynne przesuwanie obiektu w prawo. Można dostosować prędkość, aby uzyskać pożądane tempo ruchu.

#### **2. Uwzględnienie czasu**

Aby ruch był bardziej płynny, warto uwzględnić czas w przeliczaniu zmian pozycji. Najczęściej stosuje się zmienną `deltaTime` obliczaną na podstawie odstępu czasu między kolejnymi klatkami.

**Przykład:**
```python
import pygame

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

x, y = 400, 300
velocity = 5
clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    deltaTime = clock.get_time() / 1000.0  # Sekundy od ostatniej klatki
    x += velocity * deltaTime

    screen.fill((0, 0, 0))
    pygame.draw.rect(screen, (255, 0, 0), (x, y, 50, 50))
    pygame.display.flip()

    clock.tick(60)  # Ustawienie liczby klatek na sekundę

pygame.quit()
```

W tym przykładzie, wartość `deltaTime` jest używana do przeliczenia ruchu obiektu, co zapewnia płynność animacji niezależnie od liczby klatek na sekundę.

#### **3. Obsługa granic ekranu**

Często konieczne jest także zapewnienie, aby obiekty nie wychodziły poza granice ekranu. W takim przypadku można dodać warunki sprawdzające pozycję obiektu i dostosowujące jego ruch tak, aby nie przekraczał granic okna gry.

**Przykład:**
```python
import pygame

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

x, y = 400, 300
velocity = 5
clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    deltaTime = clock.get_time() / 1000.0
    x += velocity * deltaTime

    # Zapewnienie, że obiekt nie wychodzi poza granice ekranu
    if x < 0:
        x = 0
    elif x > 750:
        x = 750

    screen.fill((0, 0, 0))
    pygame.draw.rect(screen, (255, 0, 0), (x, y, 50, 50))
    pygame.display.flip()

    clock.tick(60)

pygame.quit()
```

#### **4. Przydatne funkcje**
- **`pygame.time.Clock().tick(fps)`**: Ustawia maksymalną liczbę klatek na sekundę.
- **`pygame.get_time()`**: Zwraca czas od ostatniej klatki w milisekundach.
- **`pygame.draw.rect()`**: Funkcja do rysowania prostokątów na ekranie.
- **Granice ekranu**: Użycie warunków typu `x < 0` i `x > ekran_szerokość - obiekt_szerokość` dla ograniczenia ruchu obiektu.
