### 1. **`#include` – dołączanie kodu z zewnątrz**

Służy do wczytania innego pliku kodu *przed kompilacją*. Jest dwóch głównych rodzajów:

#### a) **Biblioteki systemowe** (z Arduino lub ESP32)
```cpp
#include <Wire.h>
```
- Kątem (`< >`) – oznacza, że kompilator szuka pliku w **standardowych folderach bibliotek** (np. zainstalowanych przez Arduino IDE).
- `Wire.h` to biblioteka do komunikacji I2C – pozwala rozmawiać z czujnikami, wyświetlaczy itp.

#### b) **Własne pliki w projekcie**
```cpp
#include "../sensor_kit.cpp"
```
- Cudzysłowami (`" "`) – oznacza, że szukamy **względnie do bieżącego pliku**.
- `../` oznacza „jeden katalog wyżej”.
- **Uwaga**: zazwyczaj **nie includuje się `.cpp`**, tylko `.h` (nagłówki). Includowanie `.cpp` może powodować błędy przy kompilacji (duplikacja definicji). Lepiej trzymać logikę w `.cpp`, a deklaracje w `.h`.

---

### 2. **`#define` – stałe i makra**

Umożliwia zdefiniowanie stałej nazwy zamiast liczby/tekstu:
```cpp
#define LED_PIN 2
#define MAX_TEMP 30
```
- To **nie jest zmienna** – podczas kompilacji każde wystąpienie `LED_PIN` zostanie zastąpione `2`.
- Często pisane **WIELKIMI LITERAMI** dla czytelności.

---

### 3. **`setup()` i `loop()` – dwie główne funkcje Arduino**

- **`setup()`** – uruchamiana **raz** przy starcie (lub po restarcie). Służy do:
  - ustawienia trybów pinów (`pinMode`)
  - uruchomienia komunikacji (`Serial.begin`, `Wire.begin`)
  - inicjalizacji czujników

- **`loop()`** – uruchamiana **w nieskończoność**, raz po razie. To „ciało” programu – tu czytasz dane, włączasz diody, reagujesz na sygnały.

```cpp
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
```

---

### 4. **Zmienne i podstawowe typy danych**

Zmienna to „pudełko” z nazwą, do którego wrzucamy wartość.

#### Najczęstsze typy:
```cpp
int liczba = 42;            // liczba całkowita (-32768 do 32767)
unsigned int wiek = 25;     // tylko dodatnie (0 do 65535)
float temperatura = 23.5;   // liczba z przecinkiem
bool czy_jasno = true;      // true (1) lub false (0)
char znak = 'A';            // pojedynczy znak
String tekst = "Witaj!";    // napis (uważaj – zużywa RAM!)
```

---

### 5. **`if` – warunek**

Sprawdza, czy coś jest prawdą:
```cpp
if (temperatura > 30) {
  digitalWrite(LED_PIN, HIGH);
} else {
  digitalWrite(LED_PIN, LOW);
}
```

Można łączyć warunki:
```cpp
if (temperatura > 30 && wilgotnosc < 50) {
  // ... oba warunki muszą być spełnione
}
```

---

### 6. **Pętle: `for`, `while`**

#### `for` – robimy coś wiele razy z licznikiem:
```cpp
for (int i = 0; i < 5; i++) {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(200);
}
// mignie 5 razy
```

#### `while` – powtarzaj, dopóki warunek jest **prawdziwy**:
```cpp
while (digitalRead(przycisk) == LOW) {
  // czekaj, aż przycisk zostanie wciśnięty
}
```

---

### 7. **Funkcja – własny „blok kodu”**

Funkcja to nazwany fragment kodu, który możesz uruchomić z różnych miejsc.

```cpp
void zalaczDiode(int czas) {
  digitalWrite(LED_PIN, HIGH);
  delay(czas);
  digitalWrite(LED_PIN, LOW);
}

// później w loop():
zalaczDiode(500); // mignij na pół sekundy
```

- `void` oznacza, że funkcja **nic nie zwraca**.
- Możesz też zwracać wartości: `int odczytajTemperature()`.

---

### 8. **Sterowanie pinami**

#### a) **Ustaw tryb pinu** (w `setup()`):
```cpp
pinMode(2, OUTPUT);  // pin 2 będzie wyjściem (np. dla diody)
pinMode(4, INPUT);   // pin 4 będzie wejściem (np. z przycisku)
```

#### b) **Ustaw wartość na pinie (wyjście)**:
```cpp
digitalWrite(2, HIGH);  // podaj napięcie (3.3V na ESP32)
digitalWrite(2, LOW);   // 0V (masa)
```

#### c) **Odczytaj stan pinu (wejście)**:
```cpp
int stan = digitalRead(4);  // zwróci HIGH (1) lub LOW (0)
```

---

### 9. **Obiekt – co to i jak go używać?**

Obiekt to „rzecz”, która ma **właściwości** i **metody** (funkcje).

#### Przykład: obiekt czujnika
```cpp
DHT dht(4, DHT11);  // tworzymy obiekt 'dht' na pinie 4, typ DHT11

void setup() {
  dht.begin();  // uruchamiamy czujnik – to metoda obiektu
}

void loop() {
  float t = dht.readTemperature();  // odczytujemy – też metoda
  Serial.println(t);
}
```

#### Jak używać?
1. **Dołącz bibliotekę**: `#include <DHT.h>`
2. **Stwórz obiekt**: `DHT nazwa(pin, typ);`
3. **Wywołuj jego metody**: `nazwa.funkcja();`

Nie musisz rozumieć, **jak** obiekt działa w środku – wystarczy, że wiesz, **co robi** i jak go użyć (patrz dokumentacja biblioteki).
