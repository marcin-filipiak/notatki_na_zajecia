import pygame

pygame.init()

# Tworzenie okna
screen = pygame.display.set_mode((800, 600))

# Rysowanie wielokąta
points = [(100, 100), (200, 50), (300, 100), (250, 200), (150, 200)]
pygame.draw.polygon(screen, (255, 0, 255), points)

pygame.display.flip()

# Pętla gry
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
