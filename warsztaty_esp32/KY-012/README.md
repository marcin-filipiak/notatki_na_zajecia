# 📝 **Lekcja: Sterowanie pasywnym buzzerem KY-012 i wyświetlanie jego stanu na OLED**

## 🔍 1. Co to jest moduł KY-012?

<img src="KY-012.jpg" width="50%">

**KY-012** to moduł z **pasywnym buzzerem piezoelektrycznym**, często (ale błędnie) oznaczany jako „aktywny” w tanich zestawach edukacyjnych.

- **Nie ma wewnętrznego generatora** – aby wydawał dźwięk, musi otrzymać **sygnał zmienny (PWM)** o określonej **częstotliwości**.
- **Może grać różne tony** – im wyższa częstotliwość, tym wyższy dźwięk.
- **Zakres słyszalny**: zwykle **1 kHz – 5 kHz** (poniżej 100 Hz lub powyżej 10 kHz dźwięk może być niesłyszalny).
- **3 piny**: `VCC`, `GND`, `I/O` (sygnał sterujący).

> ⚠️ **Uwaga**:  
> Prawdziwy **aktywny buzzer** wydaje dźwięk po podaniu `HIGH` – **ten nie**!  
> Jeśli słychać tylko „kliknięcie” przy zasilaniu – to **pasywny buzzer**.

---

## 🔌 2. Jak podłączyć KY-012 i OLED do ESP32?

| Element       | ESP32        | Uwagi |
|---------------|--------------|-------|
| **KY-012 GND** | `GND`        |       |
| **KY-012 I/O** | `GPIO 13`    | Sygnał PWM – **nie może być pinem 20, 24+ na ESP32** |
| **OLED VCC**   | `3.3V`       |       |
| **OLED GND**   | `GND`        |       |
| **OLED SDA**   | `GPIO 5`     | Linia danych I2C |
| **OLED SCL**   | `GPIO 4`     | Linia zegara I2C |

> ✅ ESP32 obsługuje funkcję `tone()` na pinach: **0–19, 21–23** – **GPIO13 jest poprawny**.

---

## 💻 3. Struktura projektu

W projekcie mamy **dwa pliki**:
- `main.ino` – główny program (poniżej)
- `sensor_kit.cpp` – nasz własny moduł z klasą `KY012` (oraz opcjonalnie `KY015`, `KY019`)

Uczniowie dodają plik `sensor_kit.cpp` przez **Sketch → Add File...** w Arduino IDE.

---

## 📄 4. Kod z komentarzami – `main.ino`

```cpp
// main.ino – KY-012 z możliwością wyboru tonu

#include <Wire.h>                // obsługa komunikacji I2C (do OLED)
#include <Adafruit_GFX.h>        // grafika podstawowa (tekst, linie)
#include <Adafruit_SSD1306.h>    // obsługa OLED SSD1306
#include "../sensor_kit.cpp"     // nasz moduł z klasą KY012

// --- Ustawienia OLED ---
#define SCREEN_WIDTH 128    // szerokość ekranu w pikselach
#define SCREEN_HEIGHT 64    // wysokość ekranu w pikselach
#define OLED_ADDR 0x3C      // adres I2C wyświetlacza
#define OLED_SDA 5          // pin SDA → GPIO5
#define OLED_SCL 4          // pin SCL → GPIO4

// Obiekt OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// --- Buzzer na GPIO13 ---
KY012 buzzer(13);

// Zmienna do cyklicznego testowania dźwięków
unsigned long lastTest = 0;

void setup() {
  // Inicjalizacja I2C z własnymi pinami (ważne na ESP32!)
  Wire.begin(OLED_SDA, OLED_SCL);

  // Uruchomienie OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    for (;;); // Zawieś program – OLED jest niezbędny
  }

  // Komunikat startowy
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("KY-012 Tones");
  display.display();
  delay(1000);
}

void loop() {
  // WAŻNE: update() obsługuje automatyczne wyłączanie po czasie
  buzzer.update();

  // Co 3 sekundy: odtwórz inny ton
  if (millis() - lastTest > 3000) {
    static uint8_t step = 0;
    switch (step) {
      case 0: buzzer.beep(1000, 300); break; // niski ton
      case 1: buzzer.beep(2000, 300); break; // średni
      case 2: buzzer.beep(3000, 300); break; // wysoki
      case 3: buzzer.beep(4000, 300); break; // bardzo wysoki
    }
    step = (step + 1) % 4;
    lastTest = millis();
  }

  // Wyświetl aktualny stan buzzera na OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Buzzer: ");
  display.println(buzzer.getState()); // "ON " lub "OFF"
  display.display();

  delay(100); // małe opóźnienie dla stabilności
}
```

---

## 🧠 5. Kluczowe pojęcia do omówienia na lekcji

| Pojęcie | Wyjaśnienie |
|--------|-------------|
| **Pasywny buzzer** | Element wymagający zewnętrznego sygnału PWM – nie ma wewnętrznego generatora |
| **Częstotliwość (Hz)** | Liczba drgań na sekundę – decyduje o wysokości dźwięku |
| **`tone(pin, freq)`** | Funkcja Arduino generująca sygnał PWM o danej częstotliwości |
| **`millis()`** | Czas od uruchomienia (w ms) – pozwala na nieblokujące opóźnienia |
| **`update()`** | Metoda, która **musi być wywoływana w `loop()`** – obsługuje funkcję `beep()` |

---

## ⚠️ 6. Typowe problemy i ich rozwiązania

| Problem | Możliwa przyczyna | Rozwiązanie |
|--------|------------------|------------|
| **Nie ma dźwięku** | Buzzer podłączony do złego pinu | Użyj pinu z zakresu 0–19 lub 21–23 |
| | Zasilanie 3.3V zbyt słabe | Podłącz VCC do **5V** (sygnał I/O nadal z GPIO!) |
| | Buzzer aktywny (nie pasywny) | Sprawdź, czy po `HIGH` jest ciągły dźwięk – jeśli tak, to inny typ |
| **OLED nie działa** | Zły adres I2C | Sprawdź, czy adres to `0x3C` (czasem `0x3D`) |
| **Dźwięk nie wyłącza się** | Brak `buzzer.update()` | Upewnij się, że ta linia jest w `loop()` |

---

## 🎯 7. Zadania dla uczniów (rozszerzenie)

1. **Stwórz syrenę**: naprzemiennie odtwarzaj 800 Hz i 1200 Hz co 200 ms.
2. **Zagraj nuty**: C = 523 Hz, D = 587 Hz, E = 659 Hz – zrób sekwencję.
3. **Połącz z przyciskiem**: po naciśnięciu – pisk 2000 Hz na 500 ms.
4. **Alarm temperaturowy**: jeśli temperatura > 28°C, graj 3000 Hz przez 1 s co 2 s.
5. **Zmierz zakres słyszalności**: znajdź najniższą i najwyższą częstotliwość, którą słychać.

---

> 💡 **Ciekawostka**:  
> Człowiek słyszy dźwięki w zakresie **20 Hz – 20 000 Hz**, ale z wiekiem górna granica spada.  
> Większość buzzera dobrze brzmi w zakresie **2–4 kHz** – to właśnie częstotliwość alarmów!
