# 📝 **Lekcja: Sterowanie modułem RGB LED z KY-016 i wyświetlanie stanu na OLED**

## 🔍 1. Co to jest moduł KY-016?

<img src="KY-016.jpg" width="50%">

**KY-016** to moduł z **diodą RGB o wspólnej katodzie (common cathode)**, czyli:

- Zawiera trzy osobne diody: **czerwoną (R), zieloną (G) i niebieską (B)** w jednej obudowie,
- **Wspólny pin GND** – dlatego nazywany **common cathode**,
- **Każdy kolor ma osobny pin sygnałowy**,
- **Po podaniu napięcia (HIGH)** na dany pin – **odpowiedni kolor się świeci**,
- **Mieszanie światła**: przez jednoczesne włączenie dwóch lub trzech kolorów można uzyskać **miliony odcieni**.

> 💡 Zasada mieszania addytywnego:  
> - **Czerwony + Zielony = Żółty**  
> - **Czerwony + Niebieski = Fioletowy**  
> - **Zielony + Niebieski = Cyjan**  
> - **R + G + B = Biały**

---

## 🔌 2. Jak podłączyć KY-016 i OLED do ESP32?

| Element       | ESP32        | Uwagi |
|---------------|--------------|-------|
| **KY-016 R**  | `GPIO 25`    | Pin z PWM – steruje czerwonym |
| **KY-016 G**  | `GPIO 26`    | Pin z PWM – steruje zielonym |
| **KY-016 B**  | `GPIO 16`    | Pin z PWM – steruje niebieskim |
| **KY-016 GND**| `GND`        | **Wspólna katoda – musi być podłączona!** |

> ✅ **GPIO 16, 25, 26** są poprawnymi pinami z **PWM** na ESP32 – idealne do sterowania jasnością LED.

> ⚠️ **Uwaga**:  
> Większość modułów KY-016 ma **wbudowane rezystory** (ok. 220 Ω).  
> Jeśli dioda **bardzo świeci lub się grzeje**, dodaj zewnętrzne rezystory 220 Ω szeregowo do R, G, B.

---

## 💻 3. Struktura projektu

W projekcie mamy **dwa pliki**:
- `main.ino` – główny program (poniżej)
- `sensor_kit.cpp` – nasz własny moduł z klasą `KY016`

---

## 📄 4. Kod z komentarzami – `main.ino`

```cpp
// main.ino – KY-016 RGB LED + OLED
#include "../sensor_kit.cpp"  // zawiera: KY016, OledHelper

// RGB LED: R=25, G=26, B=16
KY016 rgb(25, 26, 16);

// Stan koloru do wyświetlenia
const char* currentColor = "OFF";

// Czas ostatniej zmiany koloru
unsigned long lastChange = 0;

// Ekran OLED – domyślne piny (SDA=5, SCL=4)
OledHelper oled;

void setup() {
  if (!oled.begin()) {
    for (;;); // awaria OLED
  }
  oled.showText("KY-016\nRGB");
  delay(1000);
}

void loop() {
  // Zmieniaj kolor co 2 sekundy
  if (millis() - lastChange > 2000) {
    static uint8_t step = 0;
    switch (step) {
      case 0: rgb.red();    currentColor = "RED";    break;
      case 1: rgb.green();  currentColor = "GREEN";  break;
      case 2: rgb.blue();   currentColor = "BLUE";   break;
      case 3: rgb.yellow(); currentColor = "YELLOW"; break;
      case 4: rgb.purple(); currentColor = "PURPLE"; break;
      case 5: rgb.cyan();   currentColor = "CYAN";   break;
      case 6: rgb.white();  currentColor = "WHITE";  break;
      case 7: rgb.off();    currentColor = "OFF";    break;
    }
    step = (step + 1) % 8;
    lastChange = millis();
  }

  // Wyświetl aktualny kolor
  oled.clear();
  oled.print("RGB: ");
  oled.print(currentColor);
  oled.update();

  delay(100);
}
```

---

## 🧠 5. Kluczowe pojęcia do omówienia na lekcji

| Pojęcie | Wyjaśnienie |
|--------|-------------|
| **RGB** | Model kolorów oparty na trzech podstawowych barwach: czerwonej, zielonej i niebieskiej |
| **Wspólna katoda (common cathode)** | Wszystkie diody mają wspólny GND – aby świeciły, podajemy **HIGH** na anodę |
| **PWM (modulacja szerokości impulsu)** | Technika symulowania jasności przez szybkie włączanie/wyłączanie sygnału |
| **`analogWrite(pin, value)`** | Ustawia jasność na pinie (0 = wyłączony, 255 = maksymalna jasność) |
| **Mieszanie addytywne** | Łączenie światła – im więcej kolorów, tym jaśniejszy wynik (np. biały) |

---

## ⚠️ 6. Typowe problemy i ich rozwiązania

| Problem | Możliwa przyczyna | Rozwiązanie |
|--------|------------------|------------|
| **Diody się nie świecą** | Niepodłączony GND | Upewnij się, że **GND KY-016 → GND ESP32** |
| | Błędne piny | Sprawdź: R=25, G=26, B=16 |
| **Zbyt jasne / przepalone kolory** | Brak rezystorów ograniczających | Dodaj rezystory 220 Ω do R, G, B |
| **Tylko jeden kolor działa** | Uszkodzona dioda lub zły pin | Przetestuj każdy kolor osobno |

---

## 🎯 7. Zadania dla uczniów (rozszerzenie)

1. **Stwórz pulsujące światło**: użyj `sin(millis())` do płynnej zmiany jasności.
2. **Losowy kolor co sekundę**: `rgb.setColor(random(256), random(256), random(256));`
3. **Symulator świateł ulicznych**: czerwony (3s) → czerwono-zielony (1s) → zielony (3s) → żółty (1s).
4. **Reakcja na temperaturę**: czerwony = gorąco (>28°C), niebieski = zimno (<20°C).
5. **Sterowanie przyciskiem**: po naciśnięciu – zmień kolor na następny z listy.


> 💡 **Ciekawostka**:  
> Diody RGB są podstawą **wszystkich kolorowych ekranów** – telewizorów, telefonów, monitorów.  
> Każdy piksel to zestaw trzech małych diod: R, G, B!
