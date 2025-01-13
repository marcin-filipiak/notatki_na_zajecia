import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Rysowanie elipsy
pygame.draw.ellipse(screen, (255, 255, 0), (200, 150, 400, 200))

pygame.display.flip()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
