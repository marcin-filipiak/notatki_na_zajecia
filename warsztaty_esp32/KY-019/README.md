# 📝 **Lekcja: Sterowanie przekaźnikiem KY-019 i wyświetlanie jego stanu na OLED**

## 🔍 1. Co to jest moduł KY-019?

<img src="KY-019.jpg" width="50%">

**KY-019** to **moduł przekaźnika** – element wykonawczy, który pozwala na **włączanie/wyłączanie urządzeń o dużym poborze mocy** (np. lampy, wentylatory, grzałki) za pomocą mikrokontrolera o niskim napięciu (np. ESP32).

- **Napięcie sterujące (IN)**: 3.3V – kompatybilne z ESP32  
- **Napięcie zasilania przekaźnika (VCC)**: 3.3V lub 5V (zależnie od wersji modułu)  
- **Prąd przełączany**: zwykle do 10A przy 250V AC (sprawdź oznaczenia na przekaźniku!)  
- **Tryb pracy**: **aktywny wysoki** – `HIGH` = przekaźnik **ZAŁĄCZONY**, `LOW` = **WYŁĄCZONY**

> ⚠️ **Uwaga bezpieczeństwa**:  
> Przekaźnik może przełączać prąd sieciowy! W szkołach **należy używać tylko niskiego napięcia** (np. LED, mały silnik na 5–12V).

---

## 🔌 2. Jak podłączyć KY-019 i OLED do ESP32?

| Element       | ESP32        | Uwagi |
|---------------|--------------|-------|
| **KY-019 VCC** | `3.3V` lub `5V` | Jeśli przekaźnik nie działa na 3.3V → użyj 5V |
| **KY-019 GND** | `GND`        |       |
| **KY-019 IN**  | `GPIO 13`    | Sygnał sterujący (3.3V logic!) |


> ✅ Większość modułów KY-019 ma **diodę sygnalizacyjną** – świeci, gdy przekaźnik jest załączony.

---

## 💻 3. Struktura projektu

W projekcie mamy **dwa pliki**:
- `main.ino` – główny program (poniżej)
- `sensor_kit.cpp` – nasz własny moduł z klasą `KY019`

---

## 📄 4. Kod z komentarzami – `main.ino`

```cpp

#include "../sensor_kit.cpp"  // zawiera: KY019, OledHelper

// Przekaźnik na GPIO13
KY019 relay(13);

// Czas ostatniego przełączenia
unsigned long lastToggle = 0;

// Ekran OLED – domyślne piny (SDA=5, SCL=4)
OledHelper oled;

void setup() {
  if (!oled.begin()) {
    for (;;); // awaria OLED
  }
  oled.showText("KY-019\nOLED");
  delay(1000);
}

void loop() {
  // Obsługa automatycznego wyłączania przekaźnika
  relay.update();

  // Co 5 sekund włącz na 2 sekundy
  if (millis() - lastToggle > 5000) {
    relay.on(2000);
    lastToggle = millis();
  }

  // --- Wyświetl stan przekaźnika – BEZ bufora! ---
  oled.clear();
  oled.print("Relay: ");
  oled.print(relay.getState()); // zwraca "ON " lub "OFF"
  oled.update();

  delay(100);
}
```

---

## 🧠 5. Kluczowe pojęcia do omówienia na lekcji

| Pojęcie | Wyjaśnienie |
|--------|-------------|
| **Przekaźnik** | Elektromechaniczne „przekaźnikowe” przełącznik – pozwala na sterowanie dużym obciążeniem małym sygnałem |
| **GPIO** | Ogólne piny cyfrowe mikrokontrolera (tutaj: GPIO13 dla przekaźnika, GPIO4/5 dla OLED) |
| **`millis()`** | Funkcja zwracająca czas od uruchomienia (w ms) – pozwala na nieblokujące opóźnienia |
| **`update()`** | Metoda, która **musi być wywoływana w `loop()`** – obsługuje funkcję „włącz na czas” |
| **Aktywny wysoki** | Przekaźnik załącza się przy sygnale `HIGH` (niektóre moduły działają odwrotnie!) |

---

## ⚠️ 6. Typowe problemy i ich rozwiązania

| Problem | Możliwa przyczyna | Rozwiązanie |
|--------|------------------|------------|
| **Przekaźnik nie klika** | Zasilanie 3.3V zbyt słabe | Podłącz **VCC do 5V**, **IN nadal do GPIO13 (3.3V!)** |
| | Błędny pin | Sprawdź, czy `KY019 relay(13);` i fizyczne podłączenie |
| **Stan "ON" nie znika** | Nie wywołano `update()` często | Upewnij się, że `relay.update()` jest w `loop()` |

---

## 🎯 7. Zadania dla uczniów (rozszerzenie)

1. **Dodaj przycisk** – jeśli naciśnięty, włącz przekaźnik na 3 sekundy.
2. **Zmodyfikuj kod**, by przekaźnik włączał się **ręcznie** (bez automatycznego testu).
3. **Połącz z czujnikiem** – jeśli temperatura > 25°C, włącz wentylator (przekaźnik).
4. **Dodaj dźwięk** – użyj buzzerka, by sygnalizować załączenie przekaźnika.
5. **Zbadaj, czy Twój przekaźnik działa na 3.3V** – podłącz VCC do 3.3V i 5V, sprawdź, czy słychać „klik”.

