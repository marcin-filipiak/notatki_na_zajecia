import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Rysowanie okręgu
pygame.draw.circle(screen, (0, 0, 255), (400, 300), 100)

pygame.display.flip()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
