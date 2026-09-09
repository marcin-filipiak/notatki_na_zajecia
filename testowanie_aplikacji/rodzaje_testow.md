# Rodzaje testów oprogramowania

Testy oprogramowania można klasyfikować na wiele sposobów. Poniżej przedstawiono najważniejsze podziały wraz z omówieniem poszczególnych rodzajów testów.

---

## 1. Podział ze względu na cel testowania

### Testy funkcjonalne
Sprawdzają, czy oprogramowanie wykonuje określone funkcje zgodnie z wymaganiami.

Przykłady:
- Sprawdzenie, czy po kliknięciu przycisku "Zapisz" dane są poprawnie zapisywane.
- Weryfikacja, czy formularz rejestracji odrzuca niepoprawne adresy e-mail.

### Testy niefunkcjonalne
Sprawdzają, jak system działa (wydajność, bezpieczeństwo, użyteczność), a nie co robi.

Przykłady:
- Test wydajności – ile zapytań na sekundę obsłuży serwer.
- Test bezpieczeństwa – czy dane użytkowników są odpowiednio chronione.
- Test użyteczności – czy interfejs jest intuicyjny dla użytkownika.

---

## 2. Podział ze względu na poziom testowania

| Poziom | Opis |
|--------|------|
| **Testy jednostkowe** | Testują pojedyncze komponenty (funkcje, metody, klasy) w izolacji |
| **Testy integracyjne** | Sprawdzają współpracę między kilkoma modułami |
| **Testy systemowe** | Testują cały system jako jedną całość |
| **Testy akceptacyjne** | Weryfikują zgodność z wymaganiami klienta i użytkownika |

---

## 3. Podział ze względu na sposób wykonania

### Testy manualne (ręczne)
- Wykonywane przez testera, który ręcznie uruchamia aplikację i sprawdza jej działanie.
- Wymagają wiedzy i doświadczenia testera.
- Dobre do testów eksploracyjnych i oceny użyteczności.

### Testy automatyczne
- Wykonywane przez skrypty i narzędzia testowe.
- Szybkie i powtarzalne, idealne do testów regresji.
- Wymagają stworzenia i utrzymania skryptów testowych.

---

## 4. Szczegółowe rodzaje testów

### Test dymny (smoke test)
Pobieżne sprawdzenie, czy aplikacja uruchamia się i działa na tyle dobrze, że można rozpocząć pełne testy. Nazwa pochodzi z elektroniki – "jeśli urządzenie dymi przy włączeniu, nie testujemy go dalej".

### Test sanity (test poprawności)
Szybka, wąska weryfikacja, czy konkretna funkcja (np. po naprawie błędu) działa poprawnie, zanim przejdziemy do szerszych testów.

### Test regresyjny (patrz: `testowanie_regresji.md`)
Sprawdzenie, czy zmiany w kodzie nie zepsuły już działających funkcji.

### Test wydajnościowy
Ocena szybkości, skalowalności i stabilności systemu pod obciążeniem. Rodzaje:
- **Test obciążeniowy** – sprawdza zachowanie systemu przy przewidywanym obciążeniu.
- **Test przeciążeniowy** – sprawdza, ile system wytrzyma, zanim ulegnie awarii.
- **Test wytrzymałościowy** – sprawdza stabilność systemu przy długotrwałej pracy.

### Test bezpieczeństwa
Weryfikacja odporności systemu na ataki i nieautoryzowany dostęp. Należy do nich testowanie penetracyjne (patrz: `testy_penetracyjne.md`).

### Test użyteczności
Ocena, jak łatwo interfejs jest w obsłudze przez typowego użytkownika.

### Test kompatybilności
Sprawdzenie, czy aplikacja działa na różnych:
- systemach operacyjnych (Windows, Linux, macOS),
- przeglądarkach (Chrome, Firefox, Edge),
- urządzeniach (komputer, tablet, telefon),
- rozdzielczościach ekranu.

### Test eksploracyjny
Testowanie bez wcześniej przygotowanych scenariuszy – tester samodzielnie eksploruje aplikację, szukając błędów i nieoczekiwanego zachowania.

---

## 5. Testy statyczne i dynamiczne

### Testy statyczne
Analiza kodu i dokumentacji **bez uruchamiania** programu. Obejmują:
- Przeglądy kodu (code review).
- Analizę statyczną (np. narzędzia automatycznie sprawdzające kod).
- Weryfikację dokumentacji i wymagań.

### Testy dynamiczne
Wymagają uruchomienia programu i sprawdzenia jego zachowania z danymi wejściowymi.

---

## 6. Testy czarnej, białej i szarej skrzynki

| Rodzaj | Wiedza testera | Przykład |
|--------|----------------|----------|
| **Black box (czarna skrzynka)** | Brak wiedzy o wewnętrznej strukturze | Testowanie interfejsu użytkownika |
| **White box (biała skrzynka)** | Pełny dostęp do kodu źródłowego | Testy jednostkowe pisane z analizą kodu |
| **Gray box (szara skrzynka)** | Częściowa wiedza o systemie | Testowanie z dostępem do bazy danych |

---

## Podsumowanie

- Testy można klasyfikować według celu, poziomu, sposobu wykonania oraz dostępu do kodu.
- Każdy rodzaj testu ma swoje zastosowanie i dostarcza innych informacji.
- Kompletna strategia testowa wykorzystuje wiele różnych rodzajów testów.
