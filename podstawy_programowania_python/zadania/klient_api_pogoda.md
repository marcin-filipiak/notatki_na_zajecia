### Temat zadania: **Konsolowa aplikacja pogodowa w Pythonie (parametr z linii poleceń)**

---

### Opis:

Napisz program w Pythonie, który pobiera aktualne dane pogodowe dla wybranego miasta z serwisu pogodowego i wyświetla je w czytelnej formie w konsoli.

Nazwa miasta ma być przekazywana jako **parametr przy uruchomieniu programu**.

---

### Wymagania funkcjonalne:

1. Program uruchamiany z terminala, np.:

   ```
   python weather.py Warszawa
   ```

2. Nazwa miasta pobierana z parametrów programu (np. `sys.argv`).

3. Program wysyła zapytanie HTTP GET do adresu:

   ```
   https://wttr.in/<miasto>?format=j1
   ```

4. Program odczytuje dane JSON i wyświetla:

   * nazwę miasta,
   * temperaturę (°C),
   * opis pogody,
   * wilgotność (%),
   * prędkość wiatru (km/h).

5. Dane mają być przedstawione w uporządkowanej formie, np.:

   ```
   =========================
   Pogoda dla: Warszawa
   -------------------------
   Temperatura: 15°C
   Opis: Partly cloudy
   Wilgotność: 60%
   Wiatr: 10 km/h
   =========================
   ```

6. Obsługa błędów:

   * brak podanego argumentu,
   * brak połączenia z Internetem,
   * błędna odpowiedź z serwera.

---

### Teoria:

**1. Parametry linii poleceń (`sys.argv`)**
Moduł `sys` umożliwia dostęp do argumentów przekazanych przy uruchomieniu programu:

```python
import sys

print(sys.argv)
```

* `sys.argv[0]` – nazwa skryptu
* `sys.argv[1]` – pierwszy argument (np. miasto)

---

**2. Wysyłanie zapytań HTTP w Pythonie**
Do komunikacji z API używa się biblioteki requests:

```python
import requests

response = requests.get("https://wttr.in/Warszawa?format=j1")
data = response.json()
```

---

**3. Format JSON**
Dane z serwera są w formacie JSON (słownik w Pythonie):

Najważniejsze pola:

* `current_condition[0]["temp_C"]` – temperatura
* `current_condition[0]["weatherDesc"][0]["value"]` – opis
* `current_condition[0]["humidity"]` – wilgotność
* `current_condition[0]["windspeedKmph"]` – wiatr

---

**4. Obsługa wyjątków**
Do obsługi błędów używamy `try / except`:

```python
try:
    response = requests.get(url)
    response.raise_for_status()
except:
    print("Błąd połączenia")
```
