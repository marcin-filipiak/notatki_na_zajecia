import pygame

# Inicjalizacja Pygame
pygame.init()

# Tworzenie okna gry
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Moja pierwsza gra")

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((0, 0, 0))  # Czarny kolor tła
    pygame.display.flip()  # Aktualizacja okna

# Zakończenie programu
pygame.quit()
