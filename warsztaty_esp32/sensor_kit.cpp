#ifndef DHT11MODUL_CPP_INCLUDED
#define DHT11MODUL_CPP_INCLUDED

#include <Arduino.h>

//----------------------DHT11 TEMPERATURA WILGOTNOSC---------------------------
class DHT11modul {
private:
  uint8_t pin;
  uint8_t dane[5];

  uint8_t odczytajBajt() {
    uint8_t bajt = 0;
    for (int i = 0; i < 8; i++) {
      while (digitalRead(pin) == LOW);      // czekaj na HIGH
      delayMicroseconds(30);
      if (digitalRead(pin) == HIGH) {
        bajt |= (1 << (7 - i));
      }
      while (digitalRead(pin) == HIGH);     // czekaj na koniec bitu
    }
    return bajt;
  }

public:
  DHT11modul(uint8_t p) {
    pin = p;
  }

  bool odczytaj() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delay(20); // >18 ms – start

    digitalWrite(pin, HIGH);
    delayMicroseconds(30);

    pinMode(pin, INPUT);

    // Czekaj na odpowiedź: 80us LOW
    unsigned long start = micros();
    while (digitalRead(pin) == HIGH) {
      if (micros() - start > 100) return false;
    }
    delayMicroseconds(80);

    // Czekaj na 80us HIGH
    start = micros();
    while (digitalRead(pin) == LOW) {
      if (micros() - start > 100) return false;
    }
    delayMicroseconds(80);

    // Odczytaj 5 bajtów
    for (int i = 0; i < 5; i++) {
      dane[i] = odczytajBajt();
    }

    // Sprawdź sumę kontrolną
    return (dane[4] == dane[0] + dane[1] + dane[2] + dane[3]);
  }

  float temperatura() {
    return dane[2] + dane[3] / 10.0;
  }

  float wilgotnosc() {
    return dane[0] + dane[1] / 10.0;
  }
};

#endif
