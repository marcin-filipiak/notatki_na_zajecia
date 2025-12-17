## 📝 Notatka: Jak wybrać dobrą płytkę i uruchomić OLED

### ✅ Krok 1: Wybór płytki w Arduino IDE


> **Wybierz: `Tools → Board → ESP32 Arduino → WEMOS LOLIN32`**

---

### ✅ Krok 2: Zainstaluj biblioteki (raz)
- **Adafruit SSD1306**  
- **Adafruit GFX Library**  
(Menu: `Sketch → Include Library → Manage Libraries...`)

---

## 💡 Minimalistyczny kod z komentarzami

```cpp
// --- BIBLIOTEKI ---
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- KONFIGURACJA OLED ---
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR    0x3C

// 🔑 RĘCZNE USTAWIENIE PINÓW I2C (dla HW-724!)
#define OLED_SDA     5   // SDA → GPIO 5
#define OLED_SCL     4   // SCL → GPIO 4

// Tworzymy obiekt wyświetlacza (RESET = -1, bo nie używany)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// --- INICJALIZACJA ---
void setup() {
  Serial.begin(115200);

  // ⚠️ KLUCZOWA LINIA: inicjalizacja I2C z WŁAŚCIWYMI pinami
  Wire.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("Blad: OLED nie odpowiada!");
    for (;;); // Zawieś program
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("HW-724 DZIALA!");
  display.display(); // ⚠️ Bez tego – brak obrazu!
}

void loop() {
  // Pusta pętla – ekran już działa
}
```
