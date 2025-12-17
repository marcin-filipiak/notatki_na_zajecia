# 📝 **Lekcja: Odczyt temperatury i wilgotności z czujnika DHT11 + wyświetlanie na OLED**

## 🔍 1. Co to jest czujnik DHT11?

**DHT11** to **niedrogi, cyfrowy czujnik** temperatury i wilgotności, często używany w projektach edukacyjnych i IoT.

- **Zakres temperatury**: 0°C do 50°C (dokładność ±2°C)  
- **Zakres wilgotności**: 20% do 90% (dokładność ±5%)  
- **Interfejs**: cyfrowy, **1-pinowy** (protokół własny firmy Aosong)  
- **Częstotliwość odczytu**: max. **raz na 2 sekundy** (nie można czytać szybciej!)

> ❗ Uwaga: nie mylić z **KY-015** – to inny, analogowy moduł, który **nie daje cyfrowych danych**!

---

## 🔌 2. Jak podłączyć DHT11 i OLED do ESP32?

| Element       | ESP32        | Uwagi |
|---------------|--------------|-------|
| **DHT11 VCC** | `3.3V`       | Nie podłączaj do 5V! |
| **DHT11 GND** | `GND`        |       |
| **DHT11 DATA**| `GPIO 15`    | Pin danych – do niego podłączamy sygnał |
| **OLED VCC**  | `3.3V`       |       |
| **OLED GND**  | `GND`        |       |
| **OLED SDA**  | `GPIO 5`     | Linia danych I2C |
| **OLED SCL**  | `GPIO 4`     | Linia zegara I2C |

> ✅ Większość modułów DHT11 ma **wbudowany rezystor pull-up (4.7kΩ)** – jeśli nie, należy dodać go między **DATA** a **VCC**.

---

## 💻 3. Struktura projektu

W projekcie mamy **dwa pliki**:
- `main.ino` – główny program (poniżej)
- `sensor_kit.cpp` – nasz własny moduł z klasą `DHT11modul` (uczniowie go **dodają przez "Add File..."**)

Nie używamy zewnętrznych bibliotek DHT – wszystko jest napisane **od podstaw**, by uczniowie zrozumieli, jak działa komunikacja z czujnikiem.

---

## 📄 4. Kod z komentarzami – `main.ino`

```cpp
// ==================================================
// Projekt: Pomiar temperatury i wilgotności z DHT11
// Wyświetlanie wyników na ekranie OLED SSD1306
// Platforma: ESP32
// ==================================================

// --- Wymagane biblioteki z Arduino IDE ---
#include <Wire.h>                // obsługa komunikacji I2C (do OLED)
#include <Adafruit_GFX.h>        // grafika podstawowa (tekst, linie)
#include <Adafruit_SSD1306.h>    // obsługa konkretnie OLED SSD1306
#include "sensor_kit.cpp"        // nasz własny moduł DHT11 (klasa DHT11modul)

// --- Ustawienia wyświetlacza OLED ---
#define SCREEN_WIDTH 128    // szerokość ekranu w pikselach
#define SCREEN_HEIGHT 64    // wysokość ekranu w pikselach
#define OLED_ADDR 0x3C      // adres I2C wyświetlacza (sprawdź multimetrem, jeśli nie działa!)
#define OLED_SDA 5          // pin SDA → GPIO5 na ESP32
#define OLED_SCL 4          // pin SCL → GPIO4 na ESP32

// Tworzymy obiekt "display", który obsługuje OLED
// -1 oznacza, że nie używamy pinu RESET
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// --- Inicjalizacja czujnika DHT11 na pinie 15 ---
DHT11modul czujnik(15);  // GPIO15 → sygnał z DHT11

// ==================================================
void setup() {
  // Uruchamiamy komunikację szeregową (do debugu w Serial Monitor)
  Serial.begin(115200);

  // Inicjalizujemy magistralę I2C z WŁAŚCIWYMI pinami (ważne na ESP32!)
  Wire.begin(OLED_SDA, OLED_SCL);

  // Próba uruchomienia OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("BLAD: OLED nie odpowiada!");
    for (;;); // Zawieś program – nie ma sensu działać bez ekranu
  }

  // Pierwszy komunikat na ekranie
  display.clearDisplay();         // wyczyść ekran
  display.setTextSize(1);         // rozmiar tekstu (1 = mały)
  display.setTextColor(SSD1306_WHITE); // kolor biały (OLED ma tylko czarno-biały)
  display.setCursor(0, 0);        // ustaw kursor na początek
  display.println("DHT11 + OLED"); // tekst
  display.display();              // WYŚWIETL – bez tego NIC się nie pokaże!
  delay(1000);                    // pokaż komunikat przez 1 sekundę
}

// ==================================================
void loop() {
  // Próba odczytu danych z czujnika
  if (czujnik.odczytaj()) {
    // Odczyt się powiódł – pobieramy wartości
    float t = czujnik.temperatura(); // np. 23.0
    float h = czujnik.wilgotnosc();  // np. 45.0

    // --- Wyświetlenie na OLED ---
    display.clearDisplay();          // wyczyść ekran przed nowym tekstem
    display.setCursor(0, 0);         // początek tekstu
    display.print("Temp: ");
    display.print(t, 1);             // 1 cyfra po przecinku
    display.println(" *C");

    display.print("Wilg: ");
    display.print(h, 1);
    display.println(" %");

    display.display();               // pokaż tekst na ekranie!

    // --- Wypisanie do Serial Monitor (dla nauczyciela/debugu) ---
    Serial.print("Temperatura: "); Serial.print(t, 1); Serial.println(" *C");
    Serial.print("Wilgotnosc: ");  Serial.print(h, 1); Serial.println(" %");
  } 
  else {
    // Błąd odczytu – np. źle podłączony czujnik
    display.clearDisplay();
    display.println("BLAD DHT11!");
    display.display();
    Serial.println("Blad odczytu DHT11!");
  }

  // DHT11 NIE MOŻE być odczytywany częściej niż raz na 2 sekundy!
  delay(2000);
}
```

---

## 🧠 5. Kluczowe pojęcia do omówienia na lekcji

| Pojęcie | Wyjaśnienie |
|--------|-------------|
| **I2C** | Magistrala szeregowa do komunikacji z OLED (używa SDA i SCL) |
| **GPIO** | Ogólne piny cyfrowe mikrokontrolera (tutaj: GPIO4, GPIO5, GPIO15) |
| **Pull-up** | Rezystor łączący sygnał z VCC – zapewnia stabilny stan "1" |
| **Checksum** | Prosta suma kontrolna w DHT11 – sprawdza, czy dane nie zostały zakłócane |
| **delay(2000)** | Konieczne opóźnienie – DHT11 **nie działa** bez niego! |

---

## ⚠️ 6. Typowe problemy i ich rozwiązania

| Problem | Możliwa przyczyna | Rozwiązanie |
|--------|------------------|------------|
| **"BLAD DHT11!"** | Źle podłączony czujnik | Sprawdź VCC, GND, DATA |
| | Brak rezystora pull-up | Dodaj 4.7kΩ między DATA a VCC |
| | Za częsty odczyt | Zwiększ `delay` do 2000 ms |
| **OLED nie działa** | Zły adres I2C | Sprawdź, czy adres to `0x3C` (czasem bywa `0x3D`) |
| | Złe piny I2C | Upewnij się, że `OLED_SDA = 5`, `OLED_SCL = 4` |

---

## 🎯 7. Zadania dla uczniów (rozszerzenie)

1. Zmień pin DHT11 na inny (np. GPIO 32) – co trzeba zmienić?
2. Dodaj wyświetlanie daty/godziny (symulowanej) na OLED.
3. Zrób alarm: jeśli temperatura > 30°C, wyświetl "GORĄCO!".
4. Porównaj odczyty z termometrem pokojowym – czy DHT11 jest dokładny?

---

Powodzenia na lekcji! Ten projekt doskonale wprowadza w tematy: **czujniki, komunikacja cyfrowa, obsługa wyświetlaczy i debugowanie**.
