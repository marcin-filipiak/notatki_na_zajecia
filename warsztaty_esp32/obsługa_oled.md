## 📺 `OledHelper` – metody do użytku w projekcie

Podłączając w projekcie bibliotekę sensor_kit:
```cpp
#include "../sensor_kit.cpp"
```
możesz w szybki sposób obsługiwać ekran OLED.

### ✅ 1. **Tworzenie obiektu**
```cpp
OledHelper oled;              // domyślne piny: SDA=5, SCL=4 (dla HW-724)
OledHelper oled(21, 22);      // własne piny: SDA=21, SCL=22
```
> **Uwaga**: konstruktor **nie inicjalizuje wyświetlacza** — to robi `begin()`.

---

### ✅ 2. **`bool begin()`** – uruchom ekran
```cpp
if (!oled.begin()) {
  for (;;); // awaria – OLED nie podłączony lub zły adres
}
```
- **Robi wszystko**: inicjalizuje I2C, uruchamia OLED, ustawia kolor tekstu.
- **Zwraca `true`**, jeśli ekran działa.
- **Wywołuj raz w `setup()`**.

---

### ✅ 3. **`void clear()`** – wyczyść ekran i ustaw kursor na (0,0)
```cpp
oled.clear();
```
> ✅ Automatycznie ustawia kolor na biały i kursor na początek.

---

### ✅ 4. **`void print(...)`** – wyświetl tekst, liczbę lub zmienną

#### a) Tekst z nowymi liniami (`\n`):
```cpp
oled.print("Temp: 23\nWil: 45");
```
→ wyświetli dwie linie. **`\n` działa jak w edytorze!**

#### b) Liczby:
```cpp
oled.print(42);         // liczba całkowita
oled.print(23.5);       // liczba zmiennoprzecinkowa (domyślnie 1 miejsce po przecinku)
oled.print(23.567, 2);  // → "23.57"
```

#### c) `String` (np. z metod jak `relay.getState()`):
```cpp
oled.print("Stan: ");
oled.print(relay.getState()); // jeśli getState() zwraca "ON" lub "OFF"
```

> ✅ **Nie ma metody `println()`** – używaj `\n` w tekście, jeśli chcesz nowej linii.

---

### ✅ 5. **`void setCursor(int x, int y)`** – ręczne ustawienie pozycji tekstu
```cpp
oled.setCursor(0, 32);
oled.print("Tekst na środku");
```
> **Uwaga**: po `print("...\n")` kursor jest automatycznie przenoszony.

---

### ✅ 6. **`void setTextSize(uint8_t size)`** – zmień rozmiar czcionki
```cpp
oled.setTextSize(1); // mały (domyślny)
oled.setTextSize(2); // duży (np. dla "ALERT!")
```
> Wysokość linii:  
> - `size = 1` → 8 pikseli  
> - `size = 2` → 16 pikseli  

---

### ✅ 7. **`void update()`** – pokaż zmiany na ekranie
```cpp
oled.clear();
oled.print("Nowy tekst");
oled.update(); // ← bez tego – nie zobaczysz niczego!
```
> **Ważne**: `showText()` i `showLevel()` **samodzielnie wywołują `update()`**.

---

### ✅ 8. **`void showText(const char* text)`** – szybki sposób na wyświetlenie tekstu
```cpp
oled.showText("Start\nsystemu");
```
Równoważne:
```cpp
oled.clear();
oled.print("Start\nsystemu");
oled.update();
```
> ✅ **Idealne do komunikatów startowych, błędów, prostych danych.**

---

### ✅ 9. **`void showLevel(const char* label, int value, int threshold = -1)`** – pasek postępu (0–100%)
```cpp
oled.showLevel("Glos", 75, 60); // jeśli >=60 → "ALERT!"
```
- Automatycznie rysuje **pasek wizualizujący wartość**,
- Jeśli `value >= threshold`, wyświetla **"ALERT!"** dużą czcionką,
- **Wartość musi być w procentach (0–100)**.

> ✅ Idealne dla:  
> - czujnika dźwięku (`KY037`),  
> - światła,  
> - wilgotności,  
> - poziomu wody, itp.

---

### ✅ 10. **Grafika: `drawRect`, `fillRect`** – do własnych rysunków
```cpp
oled.drawRect(10, 10, 50, 20);   // rama: x=10, y=10, szer=50, wys=20
oled.fillRect(12, 12, 46, 16);  // wypełniony prostokąt (pasek, ikona)
```
> Używane wewnętrznie przez `showLevel()`, ale możesz je używać bezpośrednio.

---

## 🧩 Podsumowanie – kiedy co używać?

| Cel | Metoda |
|-----|--------|
| **Szybki komunikat** | `oled.showText("Tekst\nz nową linią");` |
| **Wartość z czujnika (0–100%)** | `oled.showLevel("Etykieta", wartosc, prog);` |
| **Wiele zmiennych w jednym tekście** | `oled.clear(); oled.print("A: "); oled.print(a); oled.print("\nB: "); oled.print(b); oled.update();` |
| **Duży napis (np. "ALARM")** | `oled.setTextSize(2); oled.setCursor(0, 32); oled.print("ALARM"); oled.update();` |
| **Własny pasek / wykres** | `oled.fillRect(...)` + `drawRect(...)` |

---

## 💡 Wskazówki edukacyjne

- **Nie używaj `snprintf`**, jeśli nie masz liczb zmiennoprzecinkowych — `print()` + `print(zmienna)` wystarczy.
- **Zawsze kończ sekwencję wyświetlania przez `update()`**, chyba że używasz `showText()` lub `showLevel()`.
- **`showLevel()` można zmodyfikować**, np. zmienić `"ALERT!"` na `"LOUD!"` — to Twój kod!

---

Teraz masz **pełną kontrolę nad ekranem**, ale **bez złożoności**.
Każdy Twój projekt z OLED może być teraz **krótszy, czytelniejszy i bardziej niezawodny**.
