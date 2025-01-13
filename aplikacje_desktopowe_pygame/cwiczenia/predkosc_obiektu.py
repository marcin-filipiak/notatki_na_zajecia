import pygame

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

# Pozycja obiektu
x, y = 400, 300
velocity = 1  # Prędkość początkowa
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
