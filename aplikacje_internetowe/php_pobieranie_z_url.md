# Pobieranie treści z adresu URL

## **1. Prosta metoda: `file_get_contents`**

```php
<?php
$url = "https://example.com";

$options = [
    "http" => [
        "method" => "GET",
        "header" => "User-Agent: PHP\r\n"
    ]
];

$context = stream_context_create($options);
$content = file_get_contents($url, false, $context);

if ($content !== false) {
    echo $content;
} else {
    echo "Nie udało się pobrać strony.";
}
```

**Omówienie:**

* `file_get_contents($url, false, $context)` – pobiera zawartość URL.
* `stream_context_create` pozwala ustawić nagłówki HTTP, np. User-Agent.
* Metoda prosta, ale nie obsługuje np. przekierowań ani SSL z pełną kontrolą.

---

## **2. Bardziej elastyczna metoda: cURL**

```php
<?php
$url = "https://example.com";

$ch = curl_init($url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true); // wynik jako string
curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true); // podążaj za przekierowaniami
curl_setopt($ch, CURLOPT_USERAGENT, "PHP script"); // User-Agent
curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false); // jeśli SSL może być problemem

$content = curl_exec($ch);

if ($content === false) {
    echo "Błąd cURL: " . curl_error($ch);
} else {
    echo $content;
}

curl_close($ch);
```

**Omówienie:**

* `curl_init($url)` – inicjalizacja sesji cURL dla podanego adresu.
* `CURLOPT_RETURNTRANSFER` – wynik nie wyświetlany od razu, tylko zapisany do zmiennej.
* `CURLOPT_FOLLOWLOCATION` – automatyczne podążanie za przekierowaniami.
* `CURLOPT_USERAGENT` – niektóre serwery odrzucają żądania bez User-Agent.
* `CURLOPT_SSL_VERIFYPEER` – wyłącza weryfikację SSL (przydatne do testów, ale w produkcji lepiej pozostawić włączone).

---

### **Którą metodę wybrać?**

* `file_get_contents` – szybka i prosta do prostych zadań.
* `cURL` – bardziej elastyczna, pozwala obsługiwać przekierowania, nagłówki, ciasteczka, metody POST itp.
