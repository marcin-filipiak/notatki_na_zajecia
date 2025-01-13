### Obsługa zdarzeń myszy w Pygame

Pygame udostępnia bogaty zestaw zdarzeń związanych z używaniem myszy. Obsługuje zdarzenia związane z naciśnięciem przycisków, ruchem myszy oraz przewijaniem kółkiem. Dzięki tym zdarzeniom możemy implementować interaktywne aplikacje, które reagują na działania użytkownika za pomocą myszy, np. w grach, aplikacjach do rysowania, czy graficznych interfejsach użytkownika.

#### **1. Typy zdarzeń związanych z myszą**
Pygame oferuje kilka typów zdarzeń związanych z używaniem myszy:

- **`pygame.MOUSEBUTTONDOWN`**: Występuje, gdy użytkownik naciśnie przycisk myszy.
- **`pygame.MOUSEBUTTONUP`**: Występuje, gdy użytkownik zwolni przycisk myszy.
- **`pygame.MOUSEMOTION`**: Występuje, gdy kursor myszy zostanie przesunięty.
- **`pygame.MOUSEWHEEL`**: Występuje, gdy użytkownik przesunie kółkiem myszy.

#### **2. Obsługa naciśnięć przycisków myszy**
Aby obsłużyć kliknięcia myszy, należy nasłuchiwać zdarzenia `pygame.MOUSEBUTTONDOWN` i `pygame.MOUSEBUTTONUP` w głównej pętli gry. Zdarzenie zawiera informację o przycisku, który został naciśnięty lub zwolniony, a także pozycję kursora myszy w oknie.

**Przykład:**
```python
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
        elif event.type == pygame.MOUSEBUTTONDOWN:  # Naciśnięcie przycisku myszy
            if event.button == 1:  # Lewy przycisk myszy
                print("Lewy przycisk myszy naciśnięty na pozycji", event.pos)
            elif event.button == 3:  # Prawy przycisk myszy
                print("Prawy przycisk myszy naciśnięty na pozycji", event.pos)
        elif event.type == pygame.MOUSEBUTTONUP:  # Zwolnienie przycisku myszy
            if event.button == 1:  # Lewy przycisk myszy
                print("Lewy przycisk myszy zwolniony na pozycji", event.pos)
```

W tym przykładzie używamy `event.button`, aby sprawdzić, który przycisk myszy został naciśnięty. Pygame używa następujących wartości do reprezentowania przycisków myszy:
- **1**: Lewy przycisk myszy.
- **2**: Środkowy przycisk myszy (kółko).
- **3**: Prawy przycisk myszy.

#### **3. Obsługa ruchu myszy**
Jeśli chcesz reagować na ruch myszy, należy nasłuchiwać zdarzeń `pygame.MOUSEMOTION`. To zdarzenie zawiera informacje o aktualnej pozycji kursora w oknie gry oraz zmianach w jego położeniu.

**Przykład:**
```python
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
```

**`event.pos`** zwraca krotkę `(x, y)`, która zawiera aktualną pozycję kursora myszy w oknie.

#### **4. Obsługa przewijania kółka myszy**
Pygame pozwala również na reagowanie na przewijanie kółkiem myszy. Zdarzenie `pygame.MOUSEWHEEL` występuje, gdy użytkownik obraca kółko myszy. Zdarzenie zawiera informację o kierunku przewijania oraz liczbie kroków.

**Przykład:**
```python
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
        elif event.type == pygame.MOUSEWHEEL:  # Przewijanie kółkiem myszy
            if event.y > 0:
                print("Kółko myszy przewinięte w górę")
            elif event.y < 0:
                print("Kółko myszy przewinięte w dół")
```

**`event.y`** zawiera liczbę kroków, o które kółko myszy zostało obrócone. Wartość dodatnia oznacza przewijanie w górę, a wartość ujemna przewijanie w dół.

#### **5. Pozycja myszy**
Jeśli chcesz uzyskać bieżącą pozycję kursora myszy bez konieczności oczekiwania na zdarzenie, możesz użyć funkcji `pygame.mouse.get_pos()`, która zwraca krotkę `(x, y)` z pozycją kursora w oknie gry.

**Przykład:**
```python
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

    # Pobranie pozycji myszy
    mouse_pos = pygame.mouse.get_pos()
    print("Bieżąca pozycja myszy:", mouse_pos)
```

#### **6. Przydatne funkcje**
- **`pygame.mouse.get_pos()`**: Zwraca aktualną pozycję kursora myszy w oknie gry.
- **`pygame.mouse.get_pressed()`**: Zwraca stan przycisków myszy (wciśnięte/nie wciśnięte).
- **`pygame.MOUSEMOTION`**: Zdarzenie wyzwalane przy ruchu myszy.
- **`pygame.MOUSEBUTTONDOWN`**: Zdarzenie wyzwalane przy naciśnięciu przycisku myszy.
- **`pygame.MOUSEBUTTONUP`**: Zdarzenie wyzwalane przy zwolnieniu przycisku myszy.
