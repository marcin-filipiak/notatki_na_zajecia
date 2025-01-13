import pygame

# Inicjalizacja Pygame
pygame.init()

# Tworzenie standardowego okna
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Standardowe okno")

# Tworzenie pełnoekranowego okna
# screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
# pygame.display.set_caption("Pełnoekranowe okno")

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    screen.fill((0, 128, 128))  # Wypełnienie kolorem
    pygame.display.flip()

# Zamknięcie Pygame
pygame.quit()
