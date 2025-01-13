import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Rysowanie prostokąta
pygame.draw.rect(screen, (0, 255, 0), (150, 150, 200, 100))

pygame.display.flip()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
