### Obsługa zdarzeń klawiatury w Pygame

W Pygame obsługa zdarzeń klawiatury jest podstawowym mechanizmem umożliwiającym reagowanie na naciśnięcia i zwolnienia klawiszy. Pygame udostępnia dwa główne typy zdarzeń związanych z klawiaturą: `pygame.KEYDOWN` (naciśnięcie klawisza) i `pygame.KEYUP` (zwolnienie klawisza). Dzięki tym zdarzeniom możemy reagować na wciśnięcie konkretnego klawisza lub kombinacji klawiszy w czasie rzeczywistym.

#### **1. Typy zdarzeń związanych z klawiaturą**
- **`pygame.KEYDOWN`**: Występuje, gdy użytkownik naciśnie klawisz. Zdarzenie zawiera informację o kodzie klawisza.
- **`pygame.KEYUP`**: Występuje, gdy użytkownik zwolni klawisz. Zdarzenie zawiera kod klawisza, który został zwolniony.

#### **2. Obsługa zdarzeń klawiatury**
Aby obsłużyć zdarzenia klawiatury w Pygame, należy w głównej pętli gry używać funkcji `pygame.event.get()` do sprawdzenia zdarzeń, a następnie reagować na nie odpowiednimi akcjami, w zależności od typu zdarzenia.

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
```

#### **3. Kodowanie klawiszy**
W Pygame każdy klawisz klawiatury jest reprezentowany przez unikalny kod, który można znaleźć w module `pygame.K_`. Poniżej przedstawiono przykłady popularnych klawiszy:

- **`pygame.K_UP`**: Strzałka w górę.
- **`pygame.K_DOWN`**: Strzałka w dół.
- **`pygame.K_LEFT`**: Strzałka w lewo.
- **`pygame.K_RIGHT`**: Strzałka w prawo.
- **`pygame.K_SPACE`**: Spacja.
- **`pygame.K_RETURN`**: Enter.
- **`pygame.K_ESCAPE`**: Escape.

**Przykład:**
```python
if event.type == pygame.KEYDOWN:
    if event.key == pygame.K_LEFT:
        print("Naciśnięto lewy klawisz strzałki")
    elif event.key == pygame.K_RIGHT:
        print("Naciśnięto prawy klawisz strzałki")
```

#### **4. Przechwytywanie wielu klawiszy**
Pygame pozwala również na przechwytywanie stanu wielu klawiszy jednocześnie. W tym celu używa się funkcji `pygame.key.get_pressed()`, która zwraca stan wszystkich klawiszy w postaci listy. Każdy element listy jest równy 1, jeśli klawisz jest wciśnięty, i 0, jeśli nie jest.

**Przykład:**
```python
keys = pygame.key.get_pressed()

if keys[pygame.K_LEFT]:
    print("Naciśnięto lewy klawisz strzałki")
if keys[pygame.K_RIGHT]:
    print("Naciśnięto prawy klawisz strzałki")
```

#### **5. Trzymanie klawisza**
Aby obsłużyć długotrwałe naciśnięcie klawisza, należy sprawdzić, czy dany klawisz jest trzymany, wykorzystując `pygame.key.get_pressed()`. Dzięki temu można realizować funkcje, takie jak poruszanie postacią w grze bez konieczności wielokrotnego naciśnięcia klawisza.

**Przykład:**
```python
keys = pygame.key.get_pressed()

if keys[pygame.K_UP]:
    print("Strzałka w górę wciśnięta")
```

#### **6. Czułość na wciśnięcia klawiszy**
Pygame umożliwia również monitorowanie, czy klawisz został naciśnięty tylko raz, dzięki zdarzeniu `pygame.KEYDOWN`. Jeśli klawisz jest naciśnięty i zwolniony, można wykorzystać `pygame.KEYUP` do wykrycia momentu zwolnienia.

**Przykład:**
```python
if event.type == pygame.KEYDOWN:
    if event.key == pygame.K_a:
        print("Naciśnięto klawisz 'a'")
    elif event.key == pygame.K_s:
        print("Naciśnięto klawisz 's'")
```

#### **7. Modyfikatory klawiszy (Shift, Ctrl, Alt)**
Pygame pozwala na detekcję klawiszy modyfikatorów, takich jak Shift, Ctrl i Alt, w połączeniu z innymi klawiszami. Można to zrobić za pomocą funkcji `pygame.key.get_mods()`.

**Przykład:**
```python
if event.type == pygame.KEYDOWN:
    if event.key == pygame.K_a and pygame.key.get_mods() & pygame.KMOD_SHIFT:
        print("Naciśnięto Shift + A")
```

#### **8. Przydatne funkcje**
- **`pygame.key.get_pressed()`**: Zwraca stan wszystkich klawiszy (wciśnięte/nie wciśnięte).
- **`pygame.key.get_mods()`**: Zwraca aktualny stan klawiszy modyfikatorów (Shift, Ctrl, Alt).
- **`pygame.KMOD_SHIFT`**, **`pygame.KMOD_CTRL`**, **`pygame.KMOD_ALT`**: Określają, czy dany klawisz modyfikator jest wciśnięty.
