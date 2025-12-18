# 📝 **Lekcja: Pomiar głośności dźwięku z modułem KY-037 i wyświetlanie na OLED**

## 🔍 1. Co to jest moduł KY-037?

<img src="KY-037.jpg" width="50%">

**KY-037** to **analogowy czujnik dźwięku** oparty na **mikrofonie elektretowym** ze wzmacniaczem. Służy do wykrywania **intensywności dźwięku (głośności)** w otoczeniu.

- **Typ wyjścia**: tylko **analogowe (A0)** – nie ma cyfrowego D0 (w przeciwieństwie do KY-038),
- **Zasilanie**: 3.3V (kompatybilne z ESP32),
- **Wyjście**: napięcie proporcjonalne do **głośności** – im głośniej, tym wyższa wartość,
- **Potencjometr**: służy do regulacji **wzmocnienia** sygnału (nie progu!).

> ⚠️ **Uwaga**:  
> Mikrofon nie mierzy „głośności” bezpośrednio – zwraca **chwilowe napięcie**.  
> Aby uzyskać sensowny wynik, trzeba **analizować odchylenie od poziomu spoczynkowego**, co realizuje nasza klasa `KY037`.

---

## 🔌 2. Jak podłączyć KY-037 i OLED do ESP32?

| Element       | ESP32        | Uwagi |
|---------------|--------------|-------|
| **KY-037 VCC** | `3.3V`      | **Nie podłączaj do 5V!** |
| **KY-037 GND** | `GND`       |       |
| **KY-037 A0**  | `GPIO 39`   | Pin analogowy |
| **OLED VCC**   | `3.3V`      |       |
| **OLED GND**   | `GND`       |       |
| **OLED SDA**   | `GPIO 5`    | Linia danych I2C |
| **OLED SCL**   | `GPIO 4`    | Linia zegara I2C |

> ✅ **GPIO 39** to pin **tylko do odczytu analogowego** – idealny dla czujników.

---

## 💻 3. Struktura projektu

W projekcie mamy **dwa pliki**:
- `main.ino` – główny program (poniżej)
- `sensor_kit.cpp` – nasz własny moduł z klasą  **`KY037`**

---

## 📄 4. Kod z komentarzami – `main.ino`

```cpp
// main.ino – KY-037 Czujnik dźwięku + OLED (0–100%)

#include <Wire.h>                // obsługa komunikacji I2C (do OLED)
#include <Adafruit_GFX.h>        // grafika podstawowa (tekst, linie)
#include <Adafruit_SSD1306.h>    // obsługa OLED SSD1306
#include "../sensor_kit.cpp"     // nasz moduł z klasą KY037

// --- Ustawienia OLED ---
#define SCREEN_WIDTH 128    // szerokość ekranu w pikselach
#define SCREEN_HEIGHT 64    // wysokość ekranu w pikselach
#define OLED_ADDR 0x3C      // adres I2C wyświetlacza
#define OLED_SDA 5          // pin SDA → GPIO5
#define OLED_SCL 4          // pin SCL → GPIO4

// Obiekt OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// --- Czujnik dźwięku na GPIO39 ---
KY037 sound(39);

// Próg w procentach (dostosuj do otoczenia!)
const int LOUD_THRESHOLD = 60; // 60% = głośny dźwięk

void setup() {
  // Inicjalizacja I2C z własnymi pinami (ważne na ESP32!)
  Wire.begin(OLED_SDA, OLED_SCL);

  // Próba uruchomienia OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    for (;;); // Zawieś program – OLED jest niezbędny
  }

  // Komunikat startowy
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("KY-037 Sound");
  display.display();
  delay(1000);
}

void loop() {
  // Odczytaj głośność jako procent (0–100%)
  int percent = sound.read();
  bool loud = sound.isLoud(LOUD_THRESHOLD);

  // --- Wyświetl na OLED ---
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Sound: ");
  display.print(percent);
  display.println("%");

  // Pasek wizualizujący głośność (0–100% → 0–120 pikseli)
  int barWidth = map(percent, 0, 100, 0, 120);
  display.drawRect(2, 20, 124, 8, SSD1306_WHITE); // ramka
  display.fillRect(4, 22, barWidth, 4, SSD1306_WHITE); // pasek

  // Komunikat alarmowy
  if (loud) {
    display.setCursor(0, 40);
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.println("LOUD!");
  }

  display.display();
  delay(50); // odświeżaj często dla płynnego paska
}
```

---

## 🧠 5. Kluczowe pojęcia do omówienia na lekcji

| Pojęcie | Wyjaśnienie |
|--------|-------------|
| **Analogowy sygnał dźwięku** | Mikrofon generuje zmienne napięcie – nie jest to bezpośrednia „głośność” |
| **Poziom spoczynkowy** | Wartość ADC w ciszy (ok. połowa zakresu) – od niej liczymy odchylenie |
| **Detekcja szczytu (peak detection)** | Analiza wielu próbek w krótkim czasie, by znaleźć maksymalne odchylenie |
| **Przeskalowanie do 0–100%** | Ułatwia interpretację – uczniowie rozumieją procenty lepiej niż 0–4095 |
| **ADC (analog-to-digital converter)** | Przetwornik w ESP32, który zamienia napięcie na liczbę (0–4095) |

---

## ⚠️ 6. Typowe problemy i ich rozwiązania

| Problem | Możliwa przyczyna | Rozwiązanie |
|--------|------------------|------------|
| **Pasek się nie porusza** | Zły pin analogowy | Użyj pinu 32–39 na ESP32 |
| | Moduł zasilany 5V | Podłącz **VCC do 3.3V** |
| **Wartości zbyt wysokie w ciszy** | Brak kalibracji | Klasa sama kalibruje się – wystarczy chwila ciszy po uruchomieniu |
| **Nie reaguje na dźwięk** | Zbyt niskie wzmocnienie | Kręć potencjometrem na module KY-037 (zwykle lewo/prawo) |
| **OLED nie działa** | Zły adres I2C | Sprawdź, czy adres to `0x3C` (czasem `0x3D`) |

---

## 🎯 7. Zadania dla uczniów (rozszerzenie)

1. **Dostosuj próg**: zmień `LOUD_THRESHOLD`, by reagował tylko na klaśnięcia.
2. **Steruj RGB LED**: jeśli `isLoud()`, ustaw kolor na czerwony.
3. **Licz klaśnięcia**: zwiększ licznik za każdym razem, gdy wykryty zostanie głośny dźwięk.
4. **Symuluj wu-meter**: pasek reaguje na muzykę z telefonu przyłożonego do mikrofonu.
5. **Alarm hałasu w klasie**: jeśli głośność > 70% przez 5 sekund – włącz buzzer.

---

> 💡 **Ciekawostka**:  
> Prawdziwe **mierniki hałasu (decybelometry)** używają skomplikowanych algorytmów i kalibracji.  
> Nasz projekt to **uproszczony model** – ale doskonale pokazuje, jak sprzęt reaguje na świat fizyczny!
