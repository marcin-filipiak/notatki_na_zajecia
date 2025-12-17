## 📝 Notatka: Jak wybrać dobrą płytkę i uruchomić OLED

### ✅ Krok 1: Wybór płytki w Arduino IDE


> **Wybierz: `Tools → Board → ESP32 Arduino → WEMOS LOLIN32`**

**Dlaczego?**  
- Płytka **WEMOS LOLIN32** ma OLED podłączony do **GPIO 5 (SDA)** i **GPIO 4 (SCL)** – **to samo co HW-724**.  
- Arduino IDE automatycznie ustawi I2C na te piny – nie trzeba modyfikować kodu.


---

### ✅ Krok 2: Zainstaluj biblioteki (raz)
- **Adafruit SSD1306**  
- **Adafruit GFX Library**  
(Menu: `Sketch → Include Library → Manage Libraries...`)

---

## 💡 Minimalistyczny kod z komentarzami

```cpp
// --- BIBLIOTEKI ---
#include <Wire.h>                // Komunikacja I2C (do OLED)
#include <Adafruit_GFX.h>        // Bazowa biblioteka graficzna Adafruit
#include <Adafruit_SSD1306.h>    // Sterownik dla OLED SSD1306

// --- KONFIGURACJA WYŚWIETLACZA ---
#define SCREEN_WIDTH 128   // Szerokość ekranu w pikselach
#define SCREEN_HEIGHT 64   // Wysokość ekranu w pikselach
#define OLED_ADDR 0x3C     // Standardowy adres I2C dla OLED SSD1306

// Tworzymy obiekt "display" – automatycznie używa I2C (SDA/SCL zależne od wybranej płytki)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); 
// -1 = brak pinu RESET (OLED na HW-724 nie ma osobnego pinu reset)

// --- INICJALIZACJA ---
void setup() {
  // Uruchamiamy komunikację szeregową (do debugowania – opcjonalne)
  Serial.begin(115200);

  // Inicjalizacja OLED
  // SSD1306_SWITCHCAPVCC = ekran używa wewnętrznego zasilania (zwykle tak)
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("Blad: nie mozna polaczyc z OLED!");
    for (;;); // Zawieś program – bez OLED dalsza praca nie ma sensu
  }

  // Czyszczenie bufora ekranu
  display.clearDisplay();

  // Ustawienia tekstu
  display.setTextSize(1);             // Skala tekstu (1 = 8x6 pikseli)
  display.setTextColor(SSD1306_WHITE); // Kolor (biały – OLED monochromatyczny)
  display.setCursor(0, 0);            // Pozycja kursora: x=0, y=0 (lewy górny róg)

  // Tekst do wyświetlenia
  display.println("Czesc, HW-724!");

  // ⚠️ WAŻNE: bez tej linii nic się NIE POJAWI na ekranie!
  display.display();
}

// --- GŁÓWNA PĘTLA ---
void loop() {
  // Nic nie robimy – ekran już wyświetla tekst
  // Możesz tu dodać aktualizację danych, czujniki itp.
}
```
