import pygame

# Inicjalizacja Pygame
pygame.init()

# Tworzenie okna gry
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Pętla gry")
clock = pygame.time.Clock()

# Pętla gry
running = True
while running:
    # Obsługa zdarzeń
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Aktualizacja stanu gry
    # (Tu możesz dodać logikę, np. ruch obiektów)

    # Rysowanie na ekranie
    screen.fill((0, 0, 0))  # Czyszczenie ekranu
    pygame.draw.circle(screen, (0, 255, 0), (400, 300), 50)  # Zielone koło

    # Aktualizacja wyświetlanego obrazu
    pygame.display.flip()

    # Kontrola liczby klatek na sekundę
    clock.tick(60)

# Zakończenie programu
pygame.quit()
