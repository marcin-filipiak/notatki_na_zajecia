import pygame

pygame.init()
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Efekty dźwiękowe - naciśnij jakiś klawisz")

# Ładowanie efektu dźwiękowego
sound = pygame.mixer.Sound("mixkit-video-game-health-recharge-2837.wav")

# Pętla główna
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:  # Odtwarzanie dźwięku po naciśnięciu klawisza
            sound.play()

    screen.fill((50, 50, 50))  # Tło aplikacji
    pygame.display.flip()  # Odświeżanie ekranu

pygame.quit()
