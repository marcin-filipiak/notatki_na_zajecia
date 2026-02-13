### Zadanie API kursy walut

Napisz aplikację kliencką w Pythonie (działającą w konsoli), która:

* zapyta użytkownika o:

  * adres URL API,
  * wymagane parametry (np. `currency`, `base`),
* wyśle zapytanie metodą **GET** do API napisanego w PHP,
* odbierze odpowiedź w formacie **JSON**,
* zdekoduje ją do struktury Pythona,
* wyświetli dane w czytelnej formie w konsoli,
* obsłuży błędy (brak połączenia, zły status HTTP, błędny JSON).

---

## 1. Komunikacja HTTP w Pythonie

Najwygodniej użyć biblioteki `requests`.

Instalacja:

```
pip install requests
```

Import w programie:

```python
import requests
```

---

## 2. Pobieranie danych od użytkownika (konsola)

W Pythonie dane pobiera się funkcją:

```python
url = input("Podaj adres API: ")
currency = input("Podaj kod waluty: ")
```

Można też zapytać o kilka parametrów, np.:

```python
base = input("Podaj walutę bazową: ")
```

---

## 3. Wysyłanie zapytania GET

Parametry GET przekazuje się jako słownik:

```python
params = {
    "currency": currency,
    "base": base
}
```

Wysłanie zapytania:

```python
response = requests.get(url, params=params)
```

Biblioteka sama zbuduje adres w postaci:

```
api.php?currency=EUR&base=PLN
```

---

## 4. Sprawdzanie statusu odpowiedzi HTTP

Każda odpowiedź ma kod statusu:

```python
print(response.status_code)
```

Można sprawdzić:

```python
if response.status_code == 200:
    print("OK")
else:
    print("Błąd:", response.status_code)
```

---

## 5. Odczyt i dekodowanie JSON

Jeśli API zwraca JSON, można go bezpośrednio przekształcić:

```python
data = response.json()
```

Alternatywnie:

```python
import json
data = json.loads(response.text)
```

Po dekodowaniu JSON staje się:

* słownikiem (`dict`)
* listą (`list`)

Przykładowa struktura:

```python
{
    "status": "ok",
    "data": [
        {"currency_code": "EUR", "rate": 4.32}
    ]
}
```

Dostęp do danych:

```python
print(data["status"])
print(data["data"])
```

---

## 6. Iterowanie po wynikach

Jeśli API zwraca listę kursów:

```python
for rate in data["data"]:
    print(rate["currency_code"], rate["rate"])
```

---

## 7. Obsługa wyjątków

Zapytanie HTTP może zakończyć się błędem (brak internetu, zły adres).

Dlatego warto użyć `try / except`:

```python
try:
    response = requests.get(url, params=params)
    response.raise_for_status()
    data = response.json()
except requests.exceptions.RequestException as e:
    print("Błąd połączenia:", e)
```

Może też wystąpić błąd dekodowania JSON:

```python
except ValueError:
    print("Niepoprawny format JSON")
```

---

## 8. Walidacja danych wejściowych

Można sprawdzić:

* czy URL zaczyna się od `http`
* czy kod waluty ma 3 znaki

Przykład:

```python
if len(currency) != 3:
    print("Niepoprawny kod waluty")
```

---

## 9. Struktura programu

Przykładowy podział logiczny:

* funkcja pobierająca dane od użytkownika
* funkcja wysyłająca zapytanie
* funkcja wyświetlająca dane
* główna część programu (`if __name__ == "__main__":`)

---

Taka aplikacja kliencka będzie typowym konsolowym klientem API, który komunikuje się z Twoim serwerem PHP przez HTTP i przetwarza dane w formacie JSON.
