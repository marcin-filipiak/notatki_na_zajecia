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
            
        elif event.type == pygame.MOUSEMOTION:  # Ruch myszy
            print("Pozycja myszy:", event.pos)
            
        elif event.type == pygame.MOUSEBUTTONDOWN:  # Naciśnięcie przycisku myszy
            if event.button == 1:  # Lewy przycisk myszy
                print("Lewy przycisk myszy naciśnięty na pozycji", event.pos)
            elif event.button == 3:  # Prawy przycisk myszy
                print("Prawy przycisk myszy naciśnięty na pozycji", event.pos)
        elif event.type == pygame.MOUSEBUTTONUP:  # Zwolnienie przycisku myszy
            if event.button == 1:  # Lewy przycisk myszy
                print("Lewy przycisk myszy zwolniony na pozycji", event.pos)
