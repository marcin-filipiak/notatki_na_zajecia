// sensor_kit.cpp


#ifndef KY015_CPP_INCLUDED
#define KY015_CPP_INCLUDED

#include <Arduino.h>


//////////////////////// WYŚWIETLACZ //////////////////////////////

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OledHelper {
private:
  Adafruit_SSD1306 *display;
  uint8_t sda, scl;
  bool ready = false;

  // Pomocnicza: drukuje tekst z \n (bez dodawania nowej linii na końcu!)
  void printWithNewlines(const char* text) {
    if (!text) return;

    const char* start = text;
    while (*start) {
      const char* end = start;
      while (*end && *end != '\n') end++;

      // Wyświetl fragment do bufora
      if (end > start) {
        char buffer[128];
        int len = end - start;
        if (len >= 127) len = 127;
        strncpy(buffer, start, len);
        buffer[len] = '\0';
        display->print(buffer); // drukujemy FRAGMENT
      }

      // Jeśli był \n, przechodzimy do nowej linii
      if (*end == '\n') {
        display->println(); // to przenosi kursor na początek nowej linii
      }

      start = (*end == '\n') ? end + 1 : end;
    }
  }

public:
  OledHelper() : OledHelper(5, 4) {}
  OledHelper(uint8_t sdaPin, uint8_t sclPin) {
    sda = sdaPin;
    scl = sclPin;
  }

  bool begin() {
    Wire.begin(sda, scl);
    display = new Adafruit_SSD1306(128, 64, &Wire, -1);
    if (!display->begin(SSD1306_SWITCHCAPVCC, 0x3C)) return false;
    display->setTextColor(SSD1306_WHITE);
    ready = true;
    clear();
    return true;
  }

  void clear() {
    if (ready) {
        display->clearDisplay();
        display->setTextColor(SSD1306_WHITE);
        setCursor(0, 0);
    }
  }

  void setCursor(int x, int y) {
    if (ready) display->setCursor(x, y);
  }

  void setTextSize(uint8_t size) {
    if (ready) display->setTextSize(size);
  }

  
  
  // Dla tekstu – obsługuje \n
  void print(const char* text) {
    if (!ready) return;
    if (text && strchr(text, '\n')) {
      printWithNewlines(text);
    } else {
      display->print(text);
    }
  }

  // Obsługa Arduino String (ważne dla kompatybilności z metodami zwracającymi String)
  void print(const String& s) {
      if (!ready) return;
      // Konwertujemy String na const char*
      print(s.c_str()); // → wywołuje naszą wersję z \n!
    }

  // Dla liczb – normalne drukowanie (bez \n, bo to nie tekst)
  void print(int n) {
    if (ready) display->print(n);
  }

  void print(float f, int decimals = 1) {
    if (ready) display->print(f, decimals);
  }

  // --- Grafika (dla showLevel) ---
  void drawRect(int x, int y, int w, int h) {
    if (ready) display->drawRect(x, y, w, h, SSD1306_WHITE);
  }

  void fillRect(int x, int y, int w, int h) {
    if (ready) display->fillRect(x, y, w, h, SSD1306_WHITE);
  }

  // --- Gotowe funkcje ---
  void showLevel(const char* label, int value, int threshold = -1) {
    if (!ready) return;
    clear();
    setTextSize(1);
    print(label);
    print(": ");
    print(value);
    print("%\n"); // ← \n = nowa linia!

    int bar = constrain(value, 0, 100);
    bar = map(bar, 0, 100, 0, 120);
    drawRect(2, 20, 124, 8);
    fillRect(4, 22, bar, 4);

    if (threshold >= 0 && value >= threshold) {
      setCursor(0, 40);
      setTextSize(2);
      print("ALERT!\n");
    }
    update();
  }

  void update() {
    if (ready) display->display();
  }

  // showText – czyszczenie + print + odświeżenie
  void showText(const char* text) {
    clear();
    print(text); // obsługuje \n!
    update();
  }
};


//////////////////////// MODUŁY ///////////////////////////////

// ==================================================
// KY037 – Analogowy czujnik dźwięku z detekcją szczytu
// Zwraca względną głośność w % (0–100) na podstawie odchylenia
// ==================================================
class KY037 {
private:
  uint8_t pin;
  int baseline = 2048; // domyślna wartość spoczynkowa (połowa 0–4095)
  unsigned long lastCalibration = 0;
  const unsigned long CALIBRATION_INTERVAL = 10000; // kalibracja co 10s

  // Kalibracja poziomu spoczynkowego (w ciszy)
  void calibrate() {
    if (millis() - lastCalibration > CALIBRATION_INTERVAL) {
      int sum = 0;
      for (int i = 0; i < 100; i++) {
        sum += analogRead(pin);
        delayMicroseconds(100);
      }
      baseline = sum / 100;
      lastCalibration = millis();
    }
  }

public:
  KY037(uint8_t p) : pin(p) {
    // Pomiar początkowy poziomu spoczynkowego
    int sum = 0;
    for (int i = 0; i < 100; i++) {
      sum += analogRead(pin);
      delayMicroseconds(100);
    }
    baseline = sum / 100;
    lastCalibration = millis();
  }

  // Zwraca względną głośność w % (0–100)
  int read() {
    calibrate(); // okresowa korekta poziomu spoczynkowego

    int peak = 0;
    // Zbierz próbki przez ~20 ms (typowy czas klaśnięcia)
    for (int i = 0; i < 200; i++) {
      int sample = analogRead(pin);
      int deviation = abs(sample - baseline); // odchylenie od spoczynku
      if (deviation > peak) peak = deviation;
      delayMicroseconds(100); // 200 * 100µs = 20 ms
    }

    // Maksymalne sensowne odchylenie – dopasuj do swojego modułu!
    const int MAX_DEVIATION = 1500; // eksperymentalna wartość

    // Przeskaluj do 0–100%
    int percent = map(peak, 0, MAX_DEVIATION, 0, 100);
    return constrain(percent, 0, 100);
  }

  bool isLoud(int thresholdPercent = 50) {
    return read() > thresholdPercent;
  }
};


// ==================================================
// KY016 – RGB LED (common cathode)
// Wymaga 3 piny PWM (np. 25, 26, 27 na ESP32)
// ==================================================
class KY016 {
private:
  uint8_t pinR, pinG, pinB;

public:
  KY016(uint8_t r, uint8_t g, uint8_t b) : pinR(r), pinG(g), pinB(b) {
    pinMode(pinR, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinB, OUTPUT);
    off(); // zaczynamy z wyłączoną diodą
  }

  // Ustaw kolor: r, g, b – wartości od 0 (wyłączony) do 255 (pełna jasność)
  void setColor(uint8_t r, uint8_t g, uint8_t b) {
    analogWrite(pinR, r);
    analogWrite(pinG, g);
    analogWrite(pinB, b);
  }

  // Wyłącz wszystkie kolory
  void off() {
    setColor(0, 0, 0);
  }

  // Predefiniowane kolory (dla edukacji)
  void red()    { setColor(255, 0, 0); }
  void green()  { setColor(0, 255, 0); }
  void blue()   { setColor(0, 0, 255); }
  void yellow() { setColor(255, 255, 0); }
  void purple() { setColor(255, 0, 255); }
  void cyan()   { setColor(0, 255, 255); }
  void white()  { setColor(255, 255, 255); }
};

// ==================================================
// KY012 – PASYWNY buzzer (piezoelektryczny)
// Wymaga sygnału PWM – pozwala ustawić częstotliwość
// ==================================================
class KY012 {
private:
  uint8_t pin;
  bool state;
  unsigned long autoOffTime = 0;

public:
  KY012(uint8_t p) : pin(p), state(false) {
    pinMode(pin, OUTPUT);
    noTone(pin); // upewnij się, że jest cicho na starcie
  }

  // Włącz dźwięk z określoną częstotliwością (w Hz)
  void on(unsigned int frequency) {
    tone(pin, frequency);
    state = true;
    autoOffTime = 0;
  }

  // Wyłącz dźwięk
  void off() {
    noTone(pin);
    state = false;
    autoOffTime = 0;
  }

  // Pisk o danej częstotliwości i czasie trwania (w ms)
  void beep(unsigned int frequency, unsigned long duration) {
    on(frequency);
    autoOffTime = millis() + duration;
  }

  // Aktualizuj – obsługuj automatyczne wyłączenie
  void update() {
    if (autoOffTime > 0 && millis() >= autoOffTime) {
      off();
    }
  }

  // Zwraca "ON" lub "OFF" (dla OLED)
  String getState() const {
    return state ? "ON " : "OFF";
  }

  // Czy buzzer aktualnie wydaje dźwięk?
  bool isOn() const {
    return state;
  }
};


// ==================================================
// KLASA KY019 – przekaźnik (Relay Module KY-019)
// ==================================================

class KY019 {
private:
  uint8_t pin;
  bool state;
  unsigned long autoOffTime = 0; // czas, kiedy ma się wyłączyć

public:
  KY019(uint8_t p) : pin(p), state(false) {
    pinMode(pin, OUTPUT);
    off(); // zaczynamy z przekaźnikiem wyłączonym
  }

  // Włącz przekaźnik na stałe
  void on() {
    digitalWrite(pin, HIGH);
    state = true;
    autoOffTime = 0; // brak automatycznego wyłączenia
  }

  // Włącz przekaźnik na określony czas (w milisekundach)
  void on(unsigned long milliseconds) {
    digitalWrite(pin, HIGH);
    state = true;
    autoOffTime = millis() + milliseconds;
  }

  // Wyłącz przekaźnik
  void off() {
    digitalWrite(pin, LOW);
    state = false;
    autoOffTime = 0;
  }

  // Aktualizuj stan – wywoływane w loop(), by obsłużyć auto-off
  void update() {
    if (autoOffTime > 0 && millis() >= autoOffTime) {
      off();
    }
  }

  // Zwraca "ON" lub "OFF" jako String (dla OLED)
  String getState() const {
    return state ? "ON " : "OFF";
  }

  // Zwraca surowy stan (true = ON)
  bool isOn() const {
    return state;
  }
};


// ==================================================
// KLASA KY015 – czujnik temperatury i wilgotności (DHT11)
// ==================================================

class KY015 {
private:
  uint8_t pin;
  uint8_t data[5];

  uint8_t readByte() {
    uint8_t byte = 0;
    for (int i = 0; i < 8; i++) {
      while (digitalRead(pin) == LOW);      // wait for HIGH
      delayMicroseconds(30);
      if (digitalRead(pin) == HIGH) {
        byte |= (1 << (7 - i));
      }
      while (digitalRead(pin) == HIGH);     // wait for bit to end
    }
    return byte;
  }

public:
  KY015(uint8_t p) {
    pin = p;
  }

  // Returns true if sensor data was read and checksum is valid
  bool read() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delay(20); // Send start signal (>18 ms)

    digitalWrite(pin, HIGH);
    delayMicroseconds(30);

    pinMode(pin, INPUT);

    // Wait for sensor response: 80us LOW
    unsigned long start = micros();
    while (digitalRead(pin) == HIGH) {
      if (micros() - start > 100) return false;
    }
    delayMicroseconds(80);

    // Wait for 80us HIGH – data transmission starts
    start = micros();
    while (digitalRead(pin) == LOW) {
      if (micros() - start > 100) return false;
    }
    delayMicroseconds(80);

    // Read 5 bytes: [hum_int, hum_dec, temp_int, temp_dec, checksum]
    for (int i = 0; i < 5; i++) {
      data[i] = readByte();
    }

    // Validate checksum
    return (data[4] == data[0] + data[1] + data[2] + data[3]);
  }

  // Returns temperature in degrees Celsius (e.g., 23.0)
  float temperature() {
    return data[2] + data[3] / 10.0;
  }

  // Returns relative humidity in percent (e.g., 45.0)
  float humidity() {
    return data[0] + data[1] / 10.0;
  }
};

#endif
