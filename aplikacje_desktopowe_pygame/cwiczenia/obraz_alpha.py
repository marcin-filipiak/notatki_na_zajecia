import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Wczytywanie obrazu z przezroczystością
image = pygame.image.load('pinup_face.png').convert_alpha()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    # Wyświetlanie obrazu z przezroczystością
    screen.blit(image, (100, 100))

    pygame.display.flip()

pygame.quit()

