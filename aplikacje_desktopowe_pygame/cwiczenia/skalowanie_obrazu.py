import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))
screen.fill((255, 255, 255))  # Tło aplikacji

# Wczytywanie obrazu
image = pygame.image.load('pinup_face.png')

# Skalowanie obrazu
scaled_image = pygame.transform.scale(image, (100, 100))  # Zmiana rozmiaru na 400x300

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    # Wyświetlanie skalowanego obrazu
    screen.blit(scaled_image, (100, 100))

    pygame.display.flip()

pygame.quit()
