# Testy funkcjonalne i niefunkcjonalne

# 1. Testy funkcjonalne

**Testy funkcjonalne** sprawdzają, czy oprogramowanie wykonuje określone funkcje zgodnie z wymaganiami. Odpowiadają na pytanie: **"Czy system robi to, co ma robić?"**

## Przykłady testów funkcjonalnych

- Czy przycisk "Zapisz" zapisuje zmiany w bazie danych?
- Czy formularz logowania odrzuca niepoprawne hasło?
- Czy kalkulator poprawnie dodaje, odejmuje, mnoży i dzieli?
- Czy wyszukiwarka zwraca poprawne wyniki?

## Poziomy testów funkcjonalnych

Testy funkcjonalne mogą być wykonywane na różnych poziomach:
- **Testy jednostkowe** – pojedyncze funkcje.
- **Testy integracyjne** – współpraca modułów.
- **Testy systemowe** – cały system.
- **Testy akceptacyjne** – czy system spełnia wymagania klienta.

## Przykład


| ID | Funkcja | Wejście | Oczekiwany wynik |
|----|---------|---------|------------------|
| TC-001 | Logowanie | poprawny login i hasło | wyświetlenie strony głównej |
| TC-002 | Logowanie | zły login | komunikat "Nieprawidłowe dane" |
| TC-003 | Dodawanie produktu | produkt + ilość 2 | 2 sztuki w koszyku |

---

# 2. Testy niefunkcjonalne

**Testy niefunkcjonalne** sprawdzają, **jak** system działa – wydajność, bezpieczeństwo, niezawodność, użyteczność. Odpowiadają na pytanie: **"Jak dobrze system robi to, co ma robić?"**

## Rodzaje testów niefunkcjonalnych

### Testy wydajności (performance testing)
Sprawdzają, czy system działa wystarczająco szybko pod obciążeniem.

Rodzaje:
- **Test obciążeniowy** – system pracuje przy przewidywanym obciążeniu (np. 1000 użytkowników).
- **Test przeciążeniowy (stresowy)** – jak dużo system wytrzyma, zanim ulegnie awarii.
- **Test wytrzymałościowy** – czy system działa stabilnie przez długi czas.
- **Test skalowalności** – jak system reaguje na dodawanie zasobów.

**Przykład:** Serwis musi obsłużyć 500 równoczesnych zapytań w czasie poniżej 1 sekundy.

### Testy bezpieczeństwa (security testing)
Sprawdzają odporność systemu na ataki i nieautoryzowany dostęp (patrz: `testy_penetracyjne.md`).

### Testy niezawodności (reliability testing)
Sprawdzają, czy system działa bez awarii przez określony czas.

**Przykład:** System musi działać bez przestojów przez 99,9% czasu.

### Testy użyteczności (usability testing)
Oceniają, jak łatwo aplikacja jest w obsłudze dla typowego użytkownika.

**Przykład:** Czy użytkownik bez instrukcji potrafi znaleźć funkcję zmiany hasła?

### Testy kompatybilności (compatibility testing)
Sprawdzają, czy aplikacja działa w różnych środowiskach:
- systemach operacyjnych,
- przeglądarkach,
- urządzeniach,
- rozdzielczościach.

### Testy przenośności (portability testing)
Oceniają, jak łatwo można przenieść aplikację do innego środowiska.

### Testy dostępności (accessibility testing)
Sprawdzają, czy aplikacja jest użyteczna dla osób z niepełnosprawnościami (np. obsługa czytnikami ekranu, kontrast kolorów).

---

## Porównanie testów funkcjonalnych i niefunkcjonalnych

| Kryterium | Testy funkcjonalne | Testy niefunkcjonalne |
|-----------|--------------------|----------------------|
| Co sprawdzają | Czy funkcja działa | Jak dobrze działa |
| Przykład | Czy logowanie działa | Czy logowanie trwa < 2 s |
| Wymagania | Funkcjonalne | Niefunkcjonalne |
| Narzędzia | Selenium, JUnit, Postman | JMeter, LoadRunner, OWASP ZAP |
| Częstotliwość | Częste | Rzadziej (np. przy wydaniu dużych wersji) |

---

## Podsumowanie

- Testy funkcjonalne sprawdzają **co** system robi.
- Testy niefunkcjonalne sprawdzają **jak** system to robi.
- Obie grupy testów są niezbędne do pełnej oceny jakości oprogramowania.
- Zlekceważenie testów niefunkcjonalnych (np. wydajności lub bezpieczeństwa) może doprowadzić do poważnych problemów w środowisku produkcyjnym.
