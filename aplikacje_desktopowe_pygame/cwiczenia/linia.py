import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Rysowanie linii
pygame.draw.line(screen, (255, 0, 0), (100, 100), (700, 500), 5)

pygame.display.flip()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
