import pygame

pygame.init()
screen = pygame.display.set_mode((400, 300))
font = pygame.font.Font("arial.ttf", 48)  # Czcionka Arial, rozmiar 48
text_surface = font.render("Witaj, świecie!", True, (255, 255, 255))  # Biały tekst
screen.blit(text_surface, (50, 100))  # Rysowanie tekstu na ekranie
pygame.display.flip()

pygame.time.delay(3000)
