### Kolory w Pygame

W Pygame, kolory są reprezentowane przy użyciu krotek (tupli), które zawierają wartości dla trzech podstawowych składowych: czerwonej (R), zielonej (G) i niebieskiej (B). Każda z tych składowych przyjmuje wartość w zakresie od 0 do 255, co daje możliwość tworzenia 16,7 miliona różnych kolorów.

#### **1. Reprezentacja koloru**
Kolor w Pygame jest zazwyczaj zapisany jako krotka `(R, G, B)`.

**Przykłady:**
- **Czerwony:** `(255, 0, 0)`
- **Zielony:** `(0, 255, 0)`
- **Niebieski:** `(0, 0, 255)`
- **Czarny:** `(0, 0, 0)`
- **Biały:** `(255, 255, 255)`
- **Szary:** `(128, 128, 128)`

#### **2. Kolory zdefiniowane w Pygame**
Pygame udostępnia wbudowaną bibliotekę kolorów, w której znajdziesz wiele predefiniowanych nazw kolorów, takich jak:

```python
import pygame

pygame.init()

# Przykłady kolorów zdefiniowanych w Pygame
RED = pygame.Color('red')
GREEN = pygame.Color('green')
BLUE = pygame.Color('blue')
WHITE = pygame.Color('white')
BLACK = pygame.Color('black')
```

#### **3. Kolor z przezroczystością**
Pygame obsługuje również przezroczystość przy użyciu kanału alfa (A). Kanał alfa kontroluje stopień przezroczystości koloru (0 to pełna przezroczystość, 255 to pełna nieprzezroczystość). Kolory z przezroczystością są zapisywane jako krotki `(R, G, B, A)`.

**Przykład:**
- **Przezroczysty czerwony:** `(255, 0, 0, 128)` – 50% przezroczystości.

#### **4. Tworzenie kolorów**
Można także tworzyć kolory poprzez manipulowanie wartościami RGB i definiowanie nowych kolorów w programie. Pygame pozwala również na łatwą konwersję wartości RGB na różne formaty.

**Przykład:**
```python
import pygame

# Kolor utworzony przy użyciu wartości RGB
my_color = (100, 150, 200)

# Tworzenie obiektu koloru z nazwą
my_color2 = pygame.Color('lightblue')
```

#### **5. Przydatne funkcje**
- **`pygame.Color()`**: Używana do tworzenia kolorów z nazw, RGB lub HSV.
- **`pygame.Color.r`**, **`pygame.Color.g`**, **`pygame.Color.b`**: Dostęp do wartości kanałów koloru.
- **`pygame.Surface.fill()`**: Używana do wypełniania powierzchni określonym kolorem.


