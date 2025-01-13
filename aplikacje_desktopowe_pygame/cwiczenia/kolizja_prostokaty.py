import pygame

pygame.init()

screen = pygame.display.set_mode((800, 600))
running = True

# Pozycje obiektów i prędkości
rect1 = pygame.Rect(100, 150, 50, 50)  # Pierwszy prostokąt
rect2 = pygame.Rect(400, 150, 50, 50)  # Drugi prostokąt

velocity1 = [1, 0]  # Prędkość dla pierwszego prostokąta (ruch w prawo)
velocity2 = [-1, 0]  # Prędkość dla drugiego prostokąta (ruch w lewo)

clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Ruch obiektów
    rect1.x += velocity1[0]
    rect1.y += velocity1[1]
    rect2.x += velocity2[0]
    rect2.y += velocity2[1]

    # Sprawdzanie kolizji
    if rect1.colliderect(rect2):
        print("Kolizja!")
        # Zatrzymanie obiektów po kolizji
        velocity1 = [0, 0]
        velocity2 = [0, 0]

    # Rysowanie obiektów
    screen.fill((0, 0, 0))  # Czarny kolor tła
    pygame.draw.rect(screen, (255, 0, 0), rect1)  # Pierwszy prostokąt
    pygame.draw.rect(screen, (0, 255, 0), rect2)  # Drugi prostokąt
    pygame.display.flip()

    clock.tick(60)

pygame.quit()

