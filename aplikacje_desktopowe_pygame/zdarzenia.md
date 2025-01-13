### Wprowadzenie do systemu zdarzeń w Pygame

W Pygame, system zdarzeń odpowiada za obsługę interakcji użytkownika z aplikacją, takich jak kliknięcia myszą, naciśnięcia klawiszy czy inne akcje związane z urządzeniami wejściowymi. Zdarzenia są podstawowym mechanizmem, który umożliwia reagowanie na różnorodne wejścia.

#### **1. Zdarzenia w Pygame**
Zdarzenia w Pygame są przechowywane w kolejce zdarzeń, która jest przetwarzana podczas każdej pętli gry. Aby obsługiwać zdarzenia, należy regularnie sprawdzać, czy wystąpiły nowe zdarzenia.

**Przykład:**
```python
import pygame

pygame.init()

# Utworzenie okna
screen = pygame.display.set_mode((800, 600))
running = True

# Pętla gry
while running:
    for event in pygame.event.get():  # Sprawdzanie wszystkich zdarzeń
        if event.type == pygame.QUIT:  # Zdarzenie zamknięcia okna
            running = False
```

#### **2. Typy zdarzeń**
W Pygame występuje wiele typów zdarzeń, które mogą być używane do różnych celów. Oto najważniejsze z nich:

- **`pygame.QUIT`**: Zdarzenie zamknięcia okna gry.
- **`pygame.KEYDOWN`**: Zdarzenie naciśnięcia klawisza.
- **`pygame.KEYUP`**: Zdarzenie zwolnienia klawisza.
- **`pygame.MOUSEBUTTONDOWN`**: Zdarzenie naciśnięcia przycisku myszy.
- **`pygame.MOUSEBUTTONUP`**: Zdarzenie zwolnienia przycisku myszy.
- **`pygame.MOUSEMOTION`**: Zdarzenie ruchu myszy.

**Przykład:**
```python
if event.type == pygame.KEYDOWN:
    if event.key == pygame.K_LEFT:  # Naciśnięcie lewego klawisza strzałki
        print("Lewy klawisz strzałki naciśnięty")
```

#### **3. Obsługa zdarzeń myszy**
Pygame umożliwia śledzenie zdarzeń związanych z myszą, takich jak kliknięcia przycisków czy ruchy myszy. W zależności od potrzeb można uzyskać informacje o położeniu kursora, klikniętych przyciskach i ich stanie.

**Przykład:**
```python
if event.type == pygame.MOUSEBUTTONDOWN:
    if event.button == 1:  # Lewy przycisk myszy
        print(f"Kliknięto w punkt: {event.pos}")
```

#### **4. Obsługa zdarzeń klawiatury**
Pygame pozwala na detekcję zdarzeń związanych z klawiaturą, takich jak naciśnięcie i zwolnienie klawiszy. Zdarzenia klawiaturowe są łatwe do obsługi za pomocą `pygame.KEYDOWN` i `pygame.KEYUP`.

**Przykład:**
```python
if event.type == pygame.KEYDOWN:
    if event.key == pygame.K_SPACE:  # Naciśnięcie spacji
        print("Spacja naciśnięta")
```

#### **5. Funkcja `pygame.event.get()`**
Funkcja `pygame.event.get()` zwraca listę wszystkich zdarzeń, które zostały dodane do kolejki. Dzięki niej można łatwo sprawdzić, które zdarzenia miały miejsce.

**Przykład:**
```python
events = pygame.event.get()
for event in events:
    if event.type == pygame.QUIT:
        running = False
```

#### **6. Przydatne funkcje**
- **`pygame.event.get()`**: Zwraca listę wszystkich zdarzeń.
- **`pygame.event.pump()`**: Uaktualnia zdarzenia, aby zapewnić, że system działa poprawnie.
- **`pygame.event.clear()`**: Usuwa wszystkie zdarzenia z kolejki.
