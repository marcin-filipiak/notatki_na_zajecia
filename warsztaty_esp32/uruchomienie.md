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

#include "../sensor_kit.cpp"  // ✅ Nasza "czarna skrzynka": zawiera KY-moduły i OledHelper

// --- OBIEKT OLED ---
// ✅ OledHelper sam wie, że w HW-724:
//    - SDA = GPIO5, SCL = GPIO4
//    - adres I2C = 0x3C
//    - nie trzeba podawać rozmiaru ekranu ani obiektu Wire
OledHelper oled;  // ← wystarczy jedna linia!

// --- INICJALIZACJA ---
void setup() {

  // ✅ Inicjalizacja OLED – cała złożoność ukryta w bibliotece:
  //    - Wire.begin(5, 4)
  //    - display.begin(SSD1306_SWITCHCAPVCC, 0x3C)
  //    - ustawienie koloru tekstu
  //    - sprawdzenie, czy ekran odpowiada
  oled.begin();


  // ✅ Wyświetlenie komunikatu – prosto i czytelnie:
  //    - clear() i setTextColor() są w showText()
  //    - "\n" = nowa linia (jak w edytorze tekstu)
  oled.showText("HW-724\nDZIALA!");
  // ⚠️ UWAGA: showText() SAM odświeża ekran – nie trzeba .display()!
}

void loop() {
  // Pusta pętla – ekran już działa
}
```
