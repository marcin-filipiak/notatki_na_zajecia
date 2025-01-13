import pygame

pygame.init()

# Utworzenie okna gry
screen = pygame.display.set_mode((800, 600))
running = True

# Pętla gry
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:  # Zamknięcie okna
            running = False
        elif event.type == pygame.KEYDOWN:  # Naciśnięcie klawisza
            if event.key == pygame.K_UP:
                print("Naciśnięto strzałkę w górę")
            elif event.key == pygame.K_DOWN:
                print("Naciśnięto strzałkę w dół")
            elif event.key == pygame.K_SPACE:
                print("Naciśnięto spację")
        elif event.type == pygame.KEYUP:  # Zwolnienie klawisza
            if event.key == pygame.K_UP:
                print("Zwolniono strzałkę w górę")
            elif event.key == pygame.K_DOWN:
                print("Zwolniono strzałkę w dół")
