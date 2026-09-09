# Cykl życia oprogramowania (SDLC)

**Cykl życia oprogramowania** (ang. *Software Development Life Cycle*, SDLC) to model opisujący wszystkie etapy powstawania oprogramowania – od pomysłu, przez projektowanie, implementację, testowanie, aż po wdrożenie i utrzymanie.

---

## Fazy cyklu życia oprogramowania

Typowy przebieg cyklu życia oprogramowania obejmuje następujące fazy:

### 1. Analiza wymagań
- Zbieranie i dokumentowanie wymagań od klienta i użytkowników.
- Określenie, co system ma robić (wymagania funkcjonalne) i jakie ma spełniać warunki (wymagania niefunkcjonalne).
- Efekt: dokument wymagań / specyfikacja.

### 2. Projektowanie (planowanie)
- Tworzenie architektury systemu.
- Określenie technologii, struktury danych i interfejsów.
- Efekt: projekt architektoniczny i techniczny.

### 3. Implementacja (kodowanie)
- Pisanie kodu zgodnie z projektem i wymaganiami.
- Efekt: działający kod aplikacji.

### 4. Testowanie
- Weryfikacja, czy oprogramowanie spełnia wymagania i nie zawiera defektów.
- Wykonywanie testów na różnych poziomach.
- Efekt: raporty z testów, lista defektów i ich napraw.

### 5. Wdrożenie
- Instalacja gotowej aplikacji w środowisku produkcyjnym.
- Przeszkolenie użytkowników.
- Efekt: działająca aplikacja dostępna dla użytkowników końcowych.

### 6. Utrzymanie (eksploatacja)
- Naprawa błędów wykrytych po wdrożeniu.
- Wprowadzanie nowych funkcji i aktualizacji.
- Efekt: ciągłe doskonalenie i wsparcie produktu.

---

## Modele cyklu życia oprogramowania

### Model sekwencyjny (Waterfall)
- Fazy wykonywane jedna po drugiej, bez powrotu do poprzednich.
- Odpowiedni dla projektów o stabilnych i jasno określonych wymaganiach.
- Mało elastyczny – zmiana wymagań w trakcie projektu jest trudna.

### Model iteracyjny i przyrostowy
- Oprogramowanie tworzone jest w małych fragmentach (przyrostach).
- Każda iteracja obejmuje wszystkie etapy (analizę, projektowanie, kodowanie, testowanie).
- Kolejne wersje systemu są rozbudowywane o nowe funkcje.
- Bardziej elastyczny niż Waterfall.

### Model Agile (zwinny)
- Praca w krótkich cyklach (sprintach).
- Ciągła współpraca z klientem i szybkie dostarczanie działającego oprogramowania.
- Wymagania mogą ewoluować w trakcie projektu.
- Testowanie prowadzone jest ciągle, równolegle z implementacją.

### Model spiralny
- Łączy elementy modelu przyrostowego z analizą ryzyka.
- Każda iteracja obejmuje określenie celów, analizę ryzyka, implementację i weryfikację.
- Odpowiedni dla dużych projektów o wysokim ryzyku.

---

## Miejsce testowania w cyklu życia

Testowanie nie jest pojedynczym etapem – powinno być obecne na każdym etapie cyklu życia:

| Faza cyklu | Działania testowe |
|------------|-------------------|
| Analiza wymagań | Weryfikacja wymagań, przygotowanie planu testów |
| Projektowanie | Projektowanie przypadków testowych, tworzenie scenariuszy |
| Implementacja | Testy jednostkowe i integracyjne |
| Testowanie | Pełne testy systemowe i akceptacyjne |
| Wdrożenie | Testy w środowisku produkcyjnym (smoke tests) |
| Utrzymanie | Testy regresji po zmianach |

> **Złota zasada:** Im wcześniej rozpoczniemy planowanie testów, tym lepsza będzie ich skuteczność i tym taniej będzie naprawić wykryte błędy.

---

## Czym jest model "shift left"?

**Shift left testing** to podejście, które przesuwa testowanie na **wcześniejsze etapy** cyklu życia oprogramowania. Zamiast czekać na zakończenie implementacji, testerzy angażują się już na etapie analizy wymagań i projektowania.

Zalety:
- Wcześniejsze wykrywanie błędów i mniejszy koszt ich naprawy.
- Lepsza jakość kodu od początku.
- Szybsze dostarczanie finalnego produktu.

---

## Podsumowanie

- Cykl życia oprogramowania porządkuje cały proces powstawania aplikacji.
- Testowanie powinno być integralną częścią każdej fazy.
- Wybór modelu (Waterfall, Agile, iteracyjny) zależy od charakteru projektu i wymagań.
- Wczesne testowanie (shift left) znacząco obniża koszty i poprawia jakość produktu.
