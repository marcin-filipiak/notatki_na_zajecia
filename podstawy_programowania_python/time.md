# Python – Praca z czasem (moduł `time`)

Moduł `time` w Pythonie pozwala na pracę z czasem systemowym, opóźnienia w programie oraz pomiar czasu wykonywania fragmentów kodu.

---

## Import modułu
```python
import time
````

---

## Podstawowe funkcje

### 1. Aktualny czas (timestamp)

Zwraca liczbę sekund od **1 stycznia 1970 (epoka UNIX)**.

```python
print(time.time())
```

### 2. Zatrzymanie programu (uśpienie)

```python
time.sleep(2)  # wstrzymuje wykonanie programu na 2 sekundy
```

### 3. Czas lokalny i UTC

```python
print(time.localtime())  # struktura czasu lokalnego
print(time.gmtime())     # struktura czasu UTC
```

### 4. Formatowanie czasu

```python
t = time.localtime()
print(time.strftime("%Y-%m-%d %H:%M:%S", t))
```

Najczęściej używane formaty:

* `%Y` – rok (np. 2025)
* `%m` – miesiąc (01–12)
* `%d` – dzień
* `%H` – godzina (00–23)
* `%M` – minuty
* `%S` – sekundy

### 5. Parsowanie tekstu na strukturę czasu

```python
s = "2025-09-18 09:15:00"
t = time.strptime(s, "%Y-%m-%d %H:%M:%S")
print(t)
```

### 6. Konwersja struktury czasu na timestamp

```python
t = time.localtime()
print(time.mktime(t))
```

---

## Pomiar czasu wykonywania kodu

### Metoda 1: `time.time()`

```python
start = time.time()
# kod do zmierzenia
end = time.time()
print("Czas:", end - start, "sekundy")
```

### Metoda 2: `time.perf_counter()`

Dokładniejszy licznik czasu (zalecany do benchmarków).

```python
start = time.perf_counter()
# kod do zmierzenia
end = time.perf_counter()
print("Czas:", end - start, "sekundy")
```

---

## Podsumowanie

* `time.time()` – aktualny czas w sekundach od epoki UNIX.
* `time.sleep()` – wstrzymanie programu.
* `time.localtime()`, `time.gmtime()` – struktury czasu.
* `time.strftime()` i `time.strptime()` – formatowanie i parsowanie czasu.
* `time.perf_counter()` – dokładny pomiar czasu.
