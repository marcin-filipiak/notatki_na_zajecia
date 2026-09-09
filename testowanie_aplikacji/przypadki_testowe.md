# Pisanie przypadków testowych

**Przypadek testowy** (ang. *test case*) to szczegółowy opis jednego warunku, który należy sprawdzić w testowanej aplikacji. Zawiera dane wejściowe, warunki wykonania oraz oczekiwane rezultaty.

---

## Elementy przypadku testowego

Dobrze napisany przypadek testowy zawiera następujące elementy:

| Element | Opis |
|---------|------|
| **Identyfikator** | Unikalny numer lub kod (np. TC-001) |
| **Nazwa** | Krótka, zwięzła nazwa opisująca, co testujemy |
| **Warunki wstępne** | Stan systemu przed rozpoczęciem testu |
| **Dane wejściowe** | Dane, które zostaną użyte podczas testu |
| **Kroki do wykonania** | Kolejne czynności wykonywane przez testera |
| **Oczekiwane wyniki** | Co powinno się wydarzyć po wykonaniu kroków |
| **Priorytet** | Jak ważny jest dany test (wysoki, średni, niski) |
| **Status** | Czy test został wykonany i z jakim wynikiem |

---

## Przykład przypadku testowego

### Test logowania do aplikacji

**Identyfikator:** TC-001  
**Nazwa:** Poprawne logowanie z prawidłowymi danymi  
**Warunki wstępne:** Użytkownik posiada aktywne konto (login: `jan`, hasło: `haslo123`)

**Kroki do wykonania:**
1. Otwórz aplikację.
2. W polu "Nazwa użytkownika" wpisz `jan`.
3. W polu "Hasło" wpisz `haslo123`.
4. Kliknij przycisk "Zaloguj".

**Oczekiwane wyniki:**
- System wyświetla stronę główną konta użytkownika.
- Użytkownik widzi swój login w nagłówku aplikacji.

---

## Techniki projektowania przypadków testowych

### Podział na klasy równoważności (equivalence partitioning)
Dzielimy dane wejściowe na grupy (klasy), które według nas zachowają się w ten sam sposób. Wystarczy przetestować po jednym przedstawicielu z każdej klasy.

**Przykład:** Pole na wiek użytkownika (18–65 lat)
- Klasa poprawna: wiek 18–65 (np. 30)
- Klasa za mała: wiek < 18 (np. 15)
- Klasa za duża: wiek > 65 (np. 70)

### Analiza wartości granicznych (boundary value analysis)
Testujemy wartości znajdujące się dokładnie na granicach zakresów oraz tuż obok nich (min-1, min, max, max+1).

**Przykład:** Pole akceptujące liczby 1–100
- Wartości do przetestowania: 0, 1, 2, 99, 100, 101

### Tablica decyzyjna (decision table)
Tabela, która mapuje kombinacje warunków wejściowych na odpowiednie akcje systemu.

| Warunek: wiek >= 18 | Warunek: ma zgodę rodzica | Akcja |
|---------------------|--------------------------|-------|
| Tak | – | Zarejestruj |
| Nie | Tak | Zarejestruj |
| Nie | Nie | Odrzuć |

### Testowanie przejść między stanami (state transition)
Sprawdzamy, jak system przechodzi między różnymi stanami (np. zamówienie: nowe → opłacone → wysłane → dostarczone).

---

## Dobrze napisany przypadek testowy

### Cechy dobrego przypadku testowego:
1. **Jednoznaczny** – każdy krok jest jasno opisany.
2. **Powtarzalny** – każdy tester wykona go tak samo.
3. **Kompletny** – zawiera wszystkie potrzebne dane i warunki wstępne.
4. **Niezależny** – można go wykonać w dowolnej kolejności.
5. **Weryfikowalny** – oczekiwane wyniki są jednoznaczne.

### Najczęstsze błędy przy pisaniu testów:
- Zbyt ogólny opis kroków ("wpisz dane" zamiast "wpisz login: jan").
- Brak danych wejściowych.
- Nieprecyzyjne oczekiwane wyniki ("strona się zmieni" zamiast "system wyświetli komunikat 'Zalogowano'").
- Brak warunków wstępnych.
- Zależność od innych testów (kolejność wykonania ma znaczenie).

---

## Zestaw testowy (test suite) i pakiet testowy (test case)

- **Zestaw testowy (test suite)** – zbiór powiązanych przypadków testowych.
- **Przypadek testowy (test case)** – pojedynczy, konkretny test.
- **Plan testów (test plan)** – nadrzędny dokument opisujący całą strategię testowania.

---

## Podsumowanie

- Przypadek testowy to podstawa procesu testowania.
- Zawiera warunki wstępne, kroki, dane i oczekiwane wyniki.
- Techniki takie jak klasy równoważności i analiza wartości granicznych pozwalają zaprojektować skuteczne testy przy ograniczonej liczbie przypadków.
- Dobre przypadki testowe są jednoznaczne, powtarzalne i weryfikowalne.
