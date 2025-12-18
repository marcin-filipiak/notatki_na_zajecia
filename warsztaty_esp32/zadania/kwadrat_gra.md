# 📝 **Zadanie: Sterowanie kwadratem za pomocą joysticka KY-023**

## 🎯 Cel zadania
Napisz program, który **wyświetli mały czarny kwadrat na OLED** i pozwoli **przesuwać go po ekranie**, używając **joysticka KY-023**.  
Kwadrat ma być **wypełniony** by był dobrze widoczny.

---

## 📄 Gotowy kod – `main.ino`

```cpp
// main.ino – Sterowanie kwadratem przez joystick KY-023
#include "../sensor_kit.cpp"

// Joystick podłączony do: X=26, Y=25, przycisk=16
KY023 joystick(26, 25, 16);
OledHelper oled;

// Początkowa pozycja kwadratu (blisko środka ekranu)
int playerX = 60;
int playerY = 28;

// Rozmiar kwadratu – 6 pikseli na 6 pikseli
const int PLAYER_SIZE = 6;

void setup() {
  if (!oled.begin()) for (;;); // jeśli OLED nie działa – zatrzymaj program
  oled.showText("Steruj\nkwadratem!");
  delay(1000);
}

void loop() {
  // 1. Odczytaj pozycję joysticka (-100 do +100)
  int dx = joystick.x(); // lewo = ujemne, prawo = dodatnie
  int dy = joystick.y(); // dół = ujemne, góra = dodatnie

  // 2. Przesuń kwadrat – im bardziej nachylony joystick, tym dalej jedzie
  playerX += dx / 20;  // dzielimy, żeby ruch nie był zbyt szybki
  playerY -= dy / 20;  // minus, bo na ekranie "góra" to mniejsza wartość Y

  // 3. Nie pozwól kwadratowi wyjechać poza ekran
  playerX = constrain(playerX, 0, 128 - PLAYER_SIZE);
  playerY = constrain(playerY, 0, 64 - PLAYER_SIZE);

  // 4. Narysuj ekran od nowa
  oled.clear();
  oled.fillRect(playerX, playerY, PLAYER_SIZE, PLAYER_SIZE); // wypełniony kwadrat
  oled.drawRect(playerX, playerY, PLAYER_SIZE, PLAYER_SIZE);  // ramka wokół
  oled.update(); // pokaż zmiany

  delay(50); // mała przerwa – bez niej ekran mogłby migać
}
```

---

## 🧠 Jak to działa? – wyjaśnienie dla ucznia

1. **`joystick.x()` i `joystick.y()`**  
   Zwracają liczbę od **-100 do +100**:  
   - **X**: lewo → ujemne, prawo → dodatnie  
   - **Y**: dół → ujemne, góra → dodatnie  

2. **`playerX += dx / 20;`**  
   Dzielenie przez 20 **spowalnia ruch** – bez tego kwadrat "skakałby" z jednej strony ekranu na drugą.

3. **`playerY -= dy / 20;`**  
   Minus jest potrzebny, bo **na ekranie współrzędna Y rośnie w dół**, a my chcemy, by **pociągnięcie joysticka w górę** = **ruch w górę na ekranie**.

4. **`constrain(...)`**  
   Funkcja ta **nie pozwala wartości wyjść poza zadany zakres**.  
   Dzięki temu kwadrat **nie zniknie poza krawędzią OLED**.

5. **`fillRect` i `drawRect`**  
   - `fillRect` – rysuje **wypełniony prostokąt**,  
   - `drawRect` – rysuje **tylko obwód**.  
   Razem dają ładny, wyraźny kwadrat.

6. **`oled.update()`**  
   Bez tej linii **nic się nie pojawi na ekranie** – to jak „zatwierdzenie” rysunku.

---

## 💡 Co możesz zmienić?

- **Zwiększ `PLAYER_SIZE`** – np. do 10, by był większy.
- **Zmień prędkość**: zamiast `/ 20`, spróbuj `/ 10` (szybciej) lub `/ 50` (wolniej).
- **Dodaj reset**: jeśli chcesz, by przycisk **przenosił kwadrat na środek**, dodaj:
  ```cpp
  if (joystick.isPressed()) {
    playerX = 60;
    playerY = 28;
  }
  ```
  zaraz po odczycie `dx`, `dy`.
