# Testowanie manualne i automatyczne

Testy oprogramowania można wykonywać na dwa sposoby: **manualnie** (ręcznie przez testera) lub **automatycznie** (przez skrypty i narzędzia). Oba podejścia mają swoje zalety i wady.

---

## Testowanie manualne

**Testowanie manualne** to wykonywanie przypadków testowych przez człowieka – testera, który ręcznie uruchamia aplikację i sprawdza jej zachowanie.

### Kiedy stosujemy testy manualne?
- Testy eksploracyjne (beze wcześniej przygotowanych scenariuszy).
- Ocena użyteczności i wyglądu interfejsu.
- Testowanie nowych, jeszcze niestabilnych funkcji.
- Małe projekty lub pojedyncze zmiany.

### Zalety testów manualnych
- **Elastyczność** – tester może natychmiast reagować na nieoczekiwane zachowania.
- **Ocena subiektywnych cech** – wykrywa problemy z użytecznością, wyglądem, intuicyjnością.
- **Niski koszt początkowy** – nie trzeba pisać skryptów.
- **Wiedza testera** – doświadczony tester potrafi znaleźć typowe słabe punkty aplikacji.

### Wady testów manualnych
- **Czasochłonne** – wykonanie pojedynczego testu może trwać długo.
- **Podatne na błędy ludzkie** – tester może przegapić szczegóły.
- **Niepowtarzalne** – różni testerzy mogą wykonać test nieco inaczej.
- **Kosztowne w dłuższej perspektywie** – powtarzanie tych samych testów zużywa czas testerów.

---

## Testowanie automatyczne

**Testowanie automatyczne** to wykonywanie testów przez skrypty i oprogramowanie testowe, często zintegrowane z procesem budowania aplikacji.

### Kiedy stosujemy testy automatyczne?
- Testy regresji (powtarzane wielokrotnie).
- Testy jednostkowe i integracyjne.
- Testowanie tej samej funkcjonalności na wielu przeglądarkach/urządzeniach.
- Ciągła integracja (CI/CD).

### Zalety testów automatycznych
- **Szybkość** – setki testów wykonuje się w kilka minut.
- **Powtarzalność** – ten sam test daje ten sam wynik za każdym razem.
- **Oszczędność czasu na dłuższą metę** – testy uruchamiają się same, bez udziału człowieka.
- **Dokładność** – ominięcie czynnika ludzkiego.

### Wady testów automatycznych
- **Koszt początkowy** – utworzenie i utrzymanie skryptów wymaga czasu i wiedzy.
- **Brak "zdrowego rozsądku"** – automat nie wykryje problemów, które nie są zaprogramowane.
- **Kruchość** – zmiany w interfejsie mogą "popsuć" testy automatyczne.
- **Nie nadaje się do testów subiektywnych** – nie oceni użyteczności ani wyglądu.

---

## Porównanie

| Kryterium | Testy manualne | Testy automatyczne |
|-----------|----------------|--------------------|
| Koszt początkowy | Niski | Wysoki |
| Szybkość wykonania | Wolne | Szybkie |
| Powtarzalność | Niska | Wysoka |
| Wykrywanie błędów użyteczności | Tak | Nie |
| Testy eksploracyjne | Tak | Nie |
| Odporność na zmiany | Wysoka | Niska (kruche) |
| Najlepsze do | testów eksploracyjnych, użyteczności | regresji, testów jednostkowych |

---

## Podejścia do automatyzacji

### Testy oparte na rekordach (record & playback)
Narzędzie nagrywa akcje testera i odtwarza je automatycznie.

**Wady:** powstałe skrypty są kruche i trudne w utrzymaniu.

### Testy oparte na kodzie (code-based)
Tester/programista pisze skrypty testowe ręcznie, z pełną kontrolą nad logiką testu.

**Zalety:** większa elastyczność i trwałość, łatwiejsze utrzymanie.

---

## Narzędzia do testów automatycznych

| Typ | Narzędzia |
|-----|-----------|
| Testy jednostkowe | JUnit, NUnit, pytest, Google Test |
| Testy E2E web | Selenium, Cypress, Playwright |
| Testy API | Postman, REST Assured |
| Testy wydajności | JMeter, k6, Gatling |
| Testy mobilne | Appium, Detox |
| CI/CD (uruchamianie testów) | Jenkins, GitHub Actions, GitLab CI |

---

## Kiedy automatyzować? (kryteria wyboru)

Automatyzacja ma sens, gdy:
- Testy są **wykonywane wielokrotnie** (np. przy każdej zmianie kodu).
- Testy wymagają **dużego zestawu danych**.
- Testy są **stabilne** (interfejs się nie zmienia często).
- Testy trwałyby **zbyt długo manualnie**.

Automatyzacja **nie ma sensu**, gdy:
- Test wykonuje się **rzadko** (np. raz na rok).
- Interfejs **zmienia się bardzo często**.
- Test dotyczy **wyglądu i użyteczności**.

---

## Podsumowanie

- Testy manualne są elastyczne i wykrywają problemy subiektywne, ale są powolne i kosztowne.
- Testy automatyczne są szybkie i powtarzalne, ale kosztowne w utrzymaniu.
- Najlepsze zespoły łączą oba podejścia – automatyzują powtarzalne testy (regresja, jednostkowe), a manualnie testują eksploracyjnie i pod kątem użyteczności.
- Decyzja o automatyzacji powinna być podjęta na podstawie analizy kosztów i częstotliwości wykonywania testów.
