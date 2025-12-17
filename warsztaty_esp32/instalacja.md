Aby móc programować płytki ESP32 w Arduino IDE, musisz dodać odpowiedni **URL do menedżera dodatkowych płyt** (Additional Boards Manager URLs). Oto kroki i poprawny adres:

### 🔧 Krok 1: Otwórz Arduino IDE  
Uruchom swoje Arduino IDE (wersja 2.x lub 1.8.x — instrukcja działa dla obu).

### 🔧 Krok 2: Wejdź w ustawienia  
- W Arduino IDE 2.x:  
  **File → Preferences**  
- W Arduino IDE 1.8.x:  
  **File → Preferences**

### 🔧 Krok 3: Dodaj URL do ESP32  
W polu **"Additional Boards Manager URLs"** wpisz (lub dodaj, jeśli już coś tam jest):

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

> 💡 Jeśli masz już inne adresy (np. do ESP8266), oddziel je **średnikiem** (`;`). Przykład:
> ```
> https://arduino.esp8266.com/stable/package_esp8266com_index.json;https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
> ```

### 🔧 Krok 4: Zainstaluj płytkę ESP32  
1. Przejdź do: **Tools → Board → Boards Manager**  
2. Wyszukaj **"esp32"**  
3. Zainstaluj pakiet od **Espressif Systems** (najnowszą wersję)

Po instalacji pojawią się wszystkie dostępne płytki ESP32 (np. ESP32 Dev Module, Node32s, WEMOS Lolin32 itp.).

---

✅ To wszystko! Teraz możesz wybrać swoją płytkę ESP32 i programować ją przez Arduino IDE.
