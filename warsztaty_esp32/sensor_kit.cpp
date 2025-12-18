// sensor_kit.cpp


#ifndef KY015_CPP_INCLUDED
#define KY015_CPP_INCLUDED

#include <Arduino.h>

// ==================================================
// KY037 – Analogowy czujnik dźwięku (tylko A0)
// Zwraca głośność w procentach (0–100%)
// ==================================================
class KY037 {
private:
  uint8_t pin;

public:
  KY037(uint8_t p) : pin(p) {
    // Pin analogowy – nie ustawiamy pinMode (ESP32: 32-39 to tylko INPUT)
  }

  // Zwraca poziom dźwięku jako procent (0–100)
  // Zakłada maks. wartość ADC = 4095 → 100%
  int read() {
    int raw = analogRead(pin);
    // Ogranicz do 0–4095, by uniknąć ujemnych wartości
    raw = max(0, min(raw, 4095));
    return map(raw, 0, 4095, 0, 100);
  }

  // Czy dźwięk przekracza próg (w procentach)?
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
