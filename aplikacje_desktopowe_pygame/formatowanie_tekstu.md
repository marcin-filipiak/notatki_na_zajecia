### Formatowanie tekstu w Pygame

Pygame oferuje różne sposoby na formatowanie tekstu poprzez styl czcionek, rozmiar, kolory, a także efekty wizualne. Dzięki temu tekst w grze lub aplikacji może być atrakcyjniejszy wizualnie i dopasowany do stylu graficznego projektu.

---

#### **1. Wybór czcionki i jej rozmiaru**

**Rozmiar czcionki:**  
Rozmiar tekstu definiuje się podczas wczytywania czcionki za pomocą metody `pygame.font.Font`.

**Przykład:**
```python
font_small = pygame.font.Font(None, 24)  # Mała czcionka
font_large = pygame.font.Font(None, 72)  # Duża czcionka
```

---

#### **2. Kolor tekstu i tła**

Podczas renderowania tekstu można dostosować:
- Kolor tekstu (parametr `color` w formacie RGB).
- Kolor tła (parametr `background` w renderowaniu, opcjonalny).

**Przykład:**
```python
import pygame

pygame.init()
font = pygame.font.Font(None, 48)
text_surface = font.render("Kolorowy tekst", True, (0, 255, 0), (0, 0, 0))  # Zielony tekst na czarnym tle
```

---

#### **3. Wyrównanie tekstu**

Wyrównanie tekstu można realizować, manipulując pozycją, w której zostanie on narysowany na ekranie za pomocą metody `blit`.

##### **Wyrównanie do środka:**
Aby wyrównać tekst do środka okna, można obliczyć pozycję na podstawie wymiarów ekranu i tekstu:
```python
screen = pygame.display.set_mode((800, 600))
text_surface = font.render("Wyrównany tekst", True, (255, 255, 255))
text_rect = text_surface.get_rect(center=(400, 300))
screen.blit(text_surface, text_rect)
```

##### **Wyrównanie do narożników:**
Dzięki właściwościom `Rect` (np. `top`, `bottom`, `left`, `right`) tekst można wyrównywać także do narożników:
```python
text_rect.topleft = (10, 10)  # W lewym górnym rogu
text_rect.bottomright = (790, 590)  # W prawym dolnym rogu
```

---

#### **4. Styl czcionki**

Można używać różnych stylów czcionek, w tym pogrubienia, kursywy oraz podkreślenia.

##### **Pogrubienie:**
```python
font.set_bold(True)
```

##### **Kursywa:**
```python
font.set_italic(True)
```

##### **Podkreślenie:**
```python
font.set_underline(True)
```

##### **Przykład pełny:**
```python
import pygame

pygame.init()
font = pygame.font.Font(None, 48)
font.set_bold(True)
font.set_italic(True)
font.set_underline(True)

text_surface = font.render("Styl tekstu", True, (255, 0, 0))
```

---

#### **5. Dynamiczne formatowanie tekstu**

W grach często pojawia się potrzeba dynamicznego formatowania, np. zmiany koloru tekstu w zależności od warunków.

**Przykład zmiany koloru:**
```python
score = 100
if score > 50:
    color = (0, 255, 0)  # Zielony
else:
    color = (255, 0, 0)  # Czerwony

text_surface = font.render(f"Punkty: {score}", True, color)
```

---

#### **6. Efekty wizualne**

##### **Animacja tekstu:**
Aby animować tekst, np. zwiększać rozmiar lub zmieniać kolor, wystarczy dynamicznie aktualizować parametry czcionki lub koloru w pętli gry.

**Przykład zmiany rozmiaru w pętli:**
```python
font_size = 36
running = True
while running:
    font = pygame.font.Font(None, font_size)
    text_surface = font.render("Animowany tekst", True, (255, 255, 0))
    screen.fill((0, 0, 0))
    screen.blit(text_surface, (100, 100))
    pygame.display.flip()

    font_size += 1
    if font_size > 72:
        font_size = 36
```

##### **Efekt migania:**
```python
import time

visible = True
while running:
    if visible:
        text_surface = font.render("Migający tekst", True, (255, 255, 255))
    else:
        text_surface = font.render("", True, (0, 0, 0))  # Ukryty tekst
    
    screen.fill((0, 0, 0))
    screen.blit(text_surface, (100, 100))
    pygame.display.flip()
    
    time.sleep(0.5)
    visible = not visible
```

---

#### **7. Obsługa wielowierszowego tekstu**

Pygame nie obsługuje wielowierszowego tekstu wprost, ale można to zrealizować, renderując każdą linię osobno i przesuwając ją w pionie.

**Przykład:**
```python
lines = ["Linia 1", "Linia 2", "Linia 3"]
y_offset = 100
for line in lines:
    text_surface = font.render(line, True, (255, 255, 255))
    screen.blit(text_surface, (100, y_offset))
    y_offset += font.get_height()  # Przesunięcie w pionie
```

---

#### **8. Zaawansowane czcionki**

Dla bardziej zaawansowanego formatowania można korzystać z zewnętrznych bibliotek, takich jak **Pillow**, która pozwala na tworzenie bardziej skomplikowanego tekstu i renderowanie go jako obrazu, a następnie ładowanie do Pygame.

**Przykład z Pillow:**
```python
from PIL import Image, ImageDraw, ImageFont
import pygame

pygame.init()
font_path = "arial.ttf"
image_font = ImageFont.truetype(font_path, 48)
image = Image.new("RGBA", (400, 200), (0, 0, 0, 0))
draw = ImageDraw.Draw(image)
draw.text((10, 10), "Pillow + Pygame", font=image_font, fill=(255, 255, 255))

mode = image.mode
size = image.size
data = image.tobytes()
text_surface = pygame.image.fromstring(data, size, mode)
```
