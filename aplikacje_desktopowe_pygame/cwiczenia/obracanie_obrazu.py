import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Wczytywanie obrazu
image = pygame.image.load('pinup_face.png')

# Obracanie obrazu o 45 stopni
rotated_image = pygame.transform.rotate(image, 45)

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    # Wyświetlanie obróconego obrazu
    screen.blit(rotated_image, (100, 100))

    pygame.display.flip()

pygame.quit()
