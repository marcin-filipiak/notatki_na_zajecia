### Pętla gry w Pygame

Pętla gry to serce każdej aplikacji napisanej w Pygame. Jej zadaniem jest ciągłe odświeżanie stanu gry, obsługa zdarzeń, aktualizacja logiki gry oraz rysowanie elementów na ekranie. Pętla działa w sposób cykliczny aż do momentu zamknięcia programu przez użytkownika.

---

#### **1. Struktura pętli gry**

Minimalna pętla gry w Pygame składa się z następujących kroków:

1. **Obsługa zdarzeń**  
   Reagowanie na interakcje użytkownika (np. naciśnięcia klawiszy, kliknięcia myszą) za pomocą `pygame.event.get()`.

2. **Aktualizacja stanu gry**  
   Aktualizowanie pozycji obiektów, logiki gry i innych elementów dynamicznych.

3. **Rysowanie na ekranie**  
   Oczyszczanie ekranu i rysowanie aktualnego stanu gry.

4. **Aktualizacja okna gry**  
   Wyświetlenie zaktualizowanego obrazu na ekranie za pomocą `pygame.display.flip()` lub `pygame.display.update()`.

5. **Kontrola czasu**  
   Utrzymanie stałej liczby klatek na sekundę (FPS).

---

#### **2. Obsługa zdarzeń**

Zdarzenia są podstawą interakcji użytkownika z aplikacją. Są one obsługiwane w pętli za pomocą funkcji `pygame.event.get()`. Przykładowe zdarzenia:
- `pygame.QUIT`: Zamknięcie okna gry.
- `pygame.KEYDOWN` i `pygame.KEYUP`: Naciśnięcie lub puszczenie klawisza.
- `pygame.MOUSEBUTTONDOWN`: Kliknięcie przyciskiem myszy.

Przykład:
```python
for event in pygame.event.get():
    if event.type == pygame.QUIT:
        running = False
    elif event.type == pygame.KEYDOWN:
        if event.key == pygame.K_ESCAPE:
            running = False
```

---

#### **3. Utrzymywanie stałego FPS**

Stała liczba klatek na sekundę zapewnia płynność działania gry. Pygame umożliwia kontrolę czasu za pomocą obiektu `pygame.time.Clock`:
```python
clock = pygame.time.Clock()
```
Na końcu każdej iteracji pętli należy wywołać:
```python
clock.tick(60)  # Ograniczenie do 60 FPS
```

---

#### **4. Rysowanie i aktualizacja okna**

Ekran gry musi być regularnie odświeżany. Zwykle zaczynamy od wypełnienia tła, a następnie rysujemy elementy gry:
```python
screen.fill((0, 0, 0))  # Czarny kolor tła
pygame.draw.rect(screen, (255, 0, 0), (50, 50, 100, 100))  # Czerwony prostokąt
pygame.display.flip()  # Wyświetlenie zaktualizowanego obrazu
```

---

#### **5. Kompletny przykład pętli gry**

Oto prosty przykład implementacji pętli gry:
```python
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
```

---

#### **6. Porady dotyczące pętli gry**

- **Optymalizacja**: Unikaj skomplikowanych obliczeń w pętli. Jeśli to możliwe, przetwarzaj dane przed jej uruchomieniem.
- **Debugowanie**: Dodaj wyświetlanie liczby klatek na sekundę:
  ```python
  print(clock.get_fps())
  ```
- **Podział na funkcje**: Rozważ rozdzielenie obsługi zdarzeń, aktualizacji logiki i rysowania do osobnych funkcji, aby kod był bardziej czytelny.

---

Pętla gry jest kluczowym elementem każdej gry w Pygame. Dzięki niej możesz kontrolować czas, reagować na działania użytkownika i dynamicznie aktualizować zawartość ekranu.
