# 📝 **Lekcja: Odczyt pozycji z joysticka KY-023 i wyświetlanie na OLED**

## 🔍 1. Co to jest moduł KY-023?

<img src="KY-023.jpg" width="50%">

**KY-023** to **analogowy joystick** – popularny element do sterowania w grach, robotach czy menu.

- Składa się z **dwóch potencjometrów** (oś X i oś Y) oraz **przycisku** w środku.
- Każdy potencjometr zwraca **napięcie od 0V do 3.3V**, które mikrokontroler odczytuje jako **liczbę (0–4095 na ESP32)**.
- **Przycisk** działa jak zwykły **button** – zwiera do masy po naciśnięciu.
- **3 wyjścia analogowe + 1 cyfrowy**:
  - **VRx** – oś pozioma (lewo/prawo),
  - **VRy** – oś pionowa (góra/dół),
  - **SW** – przycisk („klik”).
    
---

## 🔌 2. Jak podłączyć KY-023 i OLED do ESP32?

| Element          | ESP32        | Uwagi |
|------------------|--------------|-------|
| **KY-023 VCC**   | `3.3V`       | **Nie podłączaj do 5V!** |
| **KY-023 GND**   | `GND`        |       |
| **KY-023 VRx**   | `GPIO 26`    | Wejście analogowe (VP) |
| **KY-023 VRy**   | `GPIO 25`    | Wejście analogowe (VN) |
| **KY-023 SW**    | `GPIO 16`    | Dowolny pin cyfrowy (z PULLUP) |

---

## 💻 3. Struktura projektu

https://app.arduino.cc/sketches/d2268e4f-79e3-4e61-a29b-3a574ac2815f?view-mode=preview

W projekcie mamy **dwa pliki**:
- `main.ino` – główny program (poniżej)
- `sensor_kit.cpp` – nasz własny moduł z klasą `KY023` (oraz `OledHelper`, `KY012`, itp.)

---

## 📄 4. Kod z komentarzami – `main.ino`

```cpp
// main.ino – KY-023 Joystick + OLED
#include "../sensor_kit.cpp"  // zawiera: KY023, OledHelper

// Joystick: X=A0 (GPIO26), Y=A1 (GPIO25), SW=GPIO16
KY023 joystick(26, 25, 16);

// OLED – domyślne piny (SDA=5, SCL=4)
OledHelper oled;

void setup() {
  if (!oled.begin()) {
    for (;;); // awaria OLED
  }
  oled.showText("KY-023\nJoystick");
  delay(1000);
}

void loop() {
  // Czyść ekran i wyświetl:
  // - znormalizowane współrzędne (-100 do +100),
  // - kierunek jako czytelny napis
  oled.clear();
  oled.print("X: ");
  oled.print(joystick.x());        // np. -45
  oled.print("\nY: ");
  oled.print(joystick.y());        // np. 80
  oled.print("\nDir: ");
  oled.print(joystick.direction()); // np. "UP-RIGHT"
  oled.update();

  delay(100); // stabilność odczytu
}
```

---

## 🧠 5. Kluczowe pojęcia do omówienia na lekcji

| Pojęcie | Wyjaśnienie |
|--------|-------------|
| **Analogowy odczyt** | Pomiar napięcia jako liczby (0–4095 na ESP32) |
| **Normalizacja** | Przeskalowanie surowej wartości do intuicyjnego zakresu (np. -100 do +100) |
| **Martwa strefa** | Obszar wokół środka, gdzie joystick uznaje pozycję za „neutralną” |
| **Kierunek jako napis** | Uproszczenie logiki – zamiast if’ów, gotowy tekst do OLED |
| **`analogRead()`** | Funkcja Arduino do odczytu napięcia z pinu analogowego |

---

## ⚠️ 6. Typowe problemy i ich rozwiązania

| Problem | Możliwa przyczyna | Rozwiązanie |
|--------|------------------|------------|
| **X lub Y zawsze 0 lub 4095** | Zły pin analogowy (np. GPIO4) | Użyj tylko pinów **32–39** |
| **Przycisk nie działa** | Brak PULLUP lub zły pin | Upewnij się, że w klasie jest `INPUT_PULLUP` |
| **Drżenie odczytu** | Brak opóźnienia lub brak uśredniania | Dodaj `delay(50–100)` lub uśredniaj próbki |
| **Obrócony kierunek Y** | Fizyka potencjometru (góra = niskie napięcie) | W klasie `KY023` oś Y jest już odwrócona! |

---

## 🎯 7. Zadania dla uczniów (rozszerzenie)

1. **Sterowanie diodą RGB**:  
   - lewo → czerwony,  
   - prawo → niebieski,  
   - góra → zielony,  
   - dół → biały.

2. **Proste menu na OLED**:  
   - „UP” → przewiń w górę,  
   - „DOWN” → przewiń w dół,  
   - „CLICK” → zatwierdź wybór.

3. **Kontrola głośności**:  
   - oś X kontroluje głośność czujnika dźwięku (0–100%),  
   - „CLICK” zapisuje próg.

4. **Zmierz martwą strefę**:  
   - sprawdź, jak daleko trzeba odchylić joystick, by zmienił się kierunek – dostosuj `DEAD_ZONE`.

5. **Symulacja padu do gry**:  
   - wyświetl ikonę strzałki w kierunku nachylenia (↑, ↓, ←, →).

---

> 💡 **Ciekawostka**:  
> Analogowe joystiki są podobne do **dżojstików w konsolach PlayStation 1/2**!  
> Współczesne kontrolery używają już enkoderów Halla (magnetycznych), ale zasada pozostaje ta sama – **przeskalowanie ruchu na liczbę**.
