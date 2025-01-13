import pygame

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

# Pozycja obiektu
x, y = 400, 300
velocity = 1  # Prędkość
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
