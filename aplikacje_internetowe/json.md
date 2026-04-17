# Format JSON, struktura, zastosowanie i przesyłanie danych

## 1. Czym jest JSON?
- **Skrót:** `J`ava`S`cript `O`bject `N`otation
- **Natura:** Lekki, tekstowy format wymiany i przechowywania danych.
- **Niezależność:** Działa w każdym języku programowania (JS, Python, PHP, Java, C#, itp.), choć natywnie zintegrowany z JavaScript.
- **Standaryzacja:** Oficjalna specyfikacja to **RFC 8259** wydawana przez IETF.
- **Porównanie z XML:** JSON jest bardziej zwięzły, szybszy w parsowaniu i łatwiejszy do odczytu dla człowieka. Nie używa znaczników otwierających/zamykających.

---

## 2. Zasady strukturyzacji danych w JSON
| Element | Zasada | Przykład |
|:---|:---|:---|
| **Obiekt** | Ujęty w nawiasy klamrowe `{}` | `{"imie": "Jan", "wiek": 20}` |
| **Klucz** | ZAWSZE ciąg znaków w **podwójnych cudzysłowach** | `"nazwa"` (nie `nazwa` ani `'nazwa'`) |
| **Unikalność** | Klucze nie mogą się powtarzać w tym samym obiekcie | ❌ `{"a":1, "a":2}` |
| **Separator klucza** | Dwukropek `:` | `"klucz": "wartość"` |
| **Separator elementów** | Przecinek `,` | `"a":1, "b":2` |
| **Trailing comma** | ❌ Ostatni element **nie może** kończyć się przecinkiem | `{"x":1,}` → błąd parsowania |
| **Komentarze** | ❌ Specyfikacja JSON **nie obsługuje** komentarzy (`//`, `/* */`, `#`) | |
| **Znaki specjalne** | Wymagają znaku ucieczki `\` | `"cytat": \"Cześć\""` |
| **Zagnieżdżanie** | Obiekt może zawierać inne obiekty lub tablice | `{"adres": {"miasto": "Waw"}}` |

---

## 3. Obsługiwane typy danych
| Typ | Zapis | Uwagi |
|:---|:---|:---|
| `string` | `"tekst"` | Zawsze w podwójnych cudzysłowach |
| `number` | `42`, `3.14`, `-7` | Bez cudzysłowów, obsługuje całkowite i zmiennoprzecinkowe |
| `boolean` | `true`, `false` | **Tylko małe litery**, bez cudzysłowów |
| `null` | `null` | Reprezentuje celowy brak wartości |
| `array` | `["a", "b", 3]` | Uporządkowana lista w `[]` |
| `object` | `{"klucz": "wartość"}` | Mapa klucz-wartość w `{}` |

⚠️ **Nieobsługiwane natywnie:** `undefined`, `NaN`, funkcje (`function`), daty (należy serializować do stringu lub tablicy).

---

## 4. Zastosowania JSON
- 🌐 **API REST** – główny format wymiany danych między klientem (przeglądarka/aplikacja) a serwerem.
- ⚙️ **Pliki konfiguracyjne** – `package.json` (Node.js), `tsconfig.json`, `composer.json` (PHP), `.prettierrc`.
- 🗄️ **Bazy NoSQL** – np. MongoDB przechowuje dokumenty w formacie zbliżonym do JSON (BSON).
- 🔄 **Testy i walidacja** – JSON służy jako nośnik wzorców pytań, schematów odpowiedzi oraz konfiguracji testów integracyjnych.

---

## 5. Przesyłanie danych JSON przez sieć
| Aspekt | Opis |
|:---|:---|
| **Protokół** | HTTP/HTTPS (standard w architekturze REST) |
| **Nagłówek** | `Content-Type: application/json` |
| **Metody HTTP** | `POST` (tworzenie), `GET` (pobieranie), `PUT/PATCH` (aktualizacja), `DELETE` |
| **Status 200** | Sukces – serwer zwrócił żądane dane JSON |
| **Bezpieczeństwo** | JSON to czysty tekst. Do ochrony danych służy **TLS/SSL (HTTPS)**. Same dane nie są szyfrowane wewnątrz formatu. |
| **Kompresja** | `GZIP` lub `Brotli` zmniejszają rozmiar przesyłanego tekstu, przyspieszając transfer |
| **Mechanizmy klienta** | `Fetch API`, `AJAX (XMLHttpRequest)` – pozwalają na asynchroniczne pobieranie/wysyłanie JSON bez przeładowania strony |

---

## 6. JSON w programowaniu i testowaniu
### 🛠️ Operacje w JavaScript
```js
// String → Obiekt
const obj = JSON.parse('{"a": 1}');

// Obiekt → String
const str = JSON.stringify({ a: 1 });
```

### ✅ Walidacja i testy
- **JSON Schema** – formalny standard opisujący wymaganą strukturę, typy i zakresy wartości. Używany do automatycznej walidacji przed zapisem lub przetwarzaniem.
- **Testy integracyjne** – polegają na wysłaniu zapytania do API, odebraniu odpowiedzi JSON i porównaniu jej kluczy/wartości z oczekiwanym schematem.
- **Format pytań testowych w JSON** – pytania zamknięte zawierają listę odpowiedzi z punktacją (`"points": "0"` lub `"1"`). Pytania otwarte oznaczane są `{?}` w treści i posiadają dokładnie jedną odpowiedź z `"points": "1"`.

---

## 7. 📌 Checklist: Kluczowe zasady do zapamiętania
- Klucze zawsze w `"podwójnych cudzysłowach"`
- `true`, `false`, `null` zapisywane **małymi literami** i bez cudzysłowów
- Przecinek między elementami, ale **nigdy po ostatnim**
- JSON **nie obsługuje komentarzy** w standardzie RFC 8259
- Do transmisji używaj nagłówka `Content-Type: application/json`
- Wrażliwe dane chroni **HTTPS**, nie sam format JSON
- `JSON.parse()` → odczyt, `JSON.stringify()` → wysyłka
- JSON to format **tekstowy**, niezależny od platformy i języka
- W testach: pytania zamknięte = lista opcji + punktacja, pytania otwarte = `{?}` + 1 poprawna odpowiedź
