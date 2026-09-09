# Raportowanie i śledzenie błędów (defektów)

Kiedy tester wykryje błąd w oprogramowaniu, musi go odpowiednio **zgłosić i opisać**, aby programista mógł go odtworzyć i naprawić. Proces ten nazywamy **raportowaniem defektów** i śledzeniem ich aż do rozwiązania.

---

## Jak wygląda dobre zgłoszenie błędu?

Dobre zgłoszenie (bug report) musi być tak napisane, aby **programista mógł odtworzyć błąd**, zrozumieć jego wpływ i naprawić go szybko.

### Kluczowe elementy zgłoszenia błędu

| Element | Opis |
|---------|------|
| **Tytuł** | Zwięzłe, jednoznaczne streszczenie problemu |
| **ID/priorytet/powaga** | Numer, jak ważny i jak poważny jest błąd |
| **Środowisko** | System operacyjny, przeglądarka, wersja aplikacji, sprzęt |
| **Kroki do odtworzenia** | Kolejne czynności, które doprowadziły do błędu |
| **Oczekiwany wynik** | Co powinno się wydarzyć |
| **Rzeczywisty wynik** | Co faktycznie się wydarzyło |
| **Załączniki** | Zrzuty ekranu, filmy, logi, pliki danych |

---

## Przykład zgłoszenia błędu

**Tytuł:** Przycisk "Zapisz" nie działa po zmianie nazwy użytkownika  
**Priorytet:** Wysoki  
**Powaga:** Poważny  

**Środowisko:**
- System: Windows 11
- Przeglądarka: Chrome 120
- Wersja aplikacji: 2.4.1

**Kroki do odtworzenia:**
1. Zaloguj się na konto.
2. Przejdź do ustawień profilu.
3. Zmień nazwę użytkownika na "nowa_nazwa".
4. Kliknij przycisk "Zapisz".

**Oczekiwany wynik:** System zapisuje nową nazwę i pokazuje komunikat "Zmiany zapisane".

**Rzeczywisty wynik:** Nic się nie dzieje, przycisk nie reaguje. Po odświeżeniu strony nazwa nie jest zmieniona.

**Załączniki:** `zrzut_ekranu.png`, `logi_aplikacji.txt`

---

## Priorytet a powaga (Severity vs Priority)

Dwa kluczowe pojęcia przy ocenie błędów:

| Pojęcie | Znaczenie | Przykład |
|---------|-----------|----------|
| **Powaga (severity)** | Jak duży jest wpływ błędu na działanie systemu | Aplikacja się nie uruchamia |
| **Priorytet (priority)** | Jak szybko błąd musi być naprawiony | Błąd u producenta (duża firma) – naprawiamy natychmiast |

### Skale priorytetów
- **P1 / Krytyczny** – system nie działa, blokada wydania.
- **P2 / Wysoki** – ważna funkcja uszkodzona, ale system działa.
- **P3 / Średni** – funkcja działa, ale z błędem.
- **P4 / Niski** – kosmetyczny problem, nie wpływa na działanie.

### Skale powagi
- **Blocker** – uniemożliwia dalszą pracę / wydanie.
- **Critical** – poważna awaria funkcji.
- **Major** – duży defekt, ale z obejściem.
- **Minor** – drobny defekt.
- **Trivial** – kosmetyczny (np. literówka).

---

## Cykl życia defektu

Typowy cykl życia zgłoszonego błędu:

```
NOWY ──► OTWARTY ──► W NAPRAWIE ──► NAPRAWIONY
         │                            │
         ▼                            ▼
      ODRZUCONY                     W WERYFIKACJI
      (niejednoznaczny,             (tester sprawdza,
       nie do odtworzenia)           czy naprawa działa)
                                        │
                                  ┌─────┴─────┐
                                  ▼           ▼
                              ZAMKNIĘTY    PONOWNIE OTWARTY
                             (naprawa      (błąd nadal
                              potwierdzona) występuje)
```

### Opis stanów:
1. **NOWY (New)** – błąd zgłoszony, czeka na przydzielenie.
2. **OTWARTY (Open)** – programista przyjął zgłoszenie do naprawy.
3. **W NAPRAWIE (In Progress)** – trwa naprawa.
4. **NAPRAWIONY (Fixed)** – programista naprawił błąd.
5. **W WERYFIKACJI (In Verification)** – tester sprawdza, czy naprawa działa.
6. **ZAMKNIĘTY (Closed)** – naprawa potwierdzona, błąd rozwiązany.
7. **PONOWNIE OTWARTY (Reopened)** – naprawa nie zadziałała, błąd wraca do naprawy.
8. **ODRZUCONY (Rejected)** – zgłoszenie niejednoznaczne, nie dało się odtworzyć lub zduplikowane.

---

## Systemy śledzenia błędów (bug trackers)

| Narzędzie | Opis |
|-----------|------|
| **Jira** | Najpopularniejsze narzędzie Agile, z systemem śledzenia zgłoszeń |
| **GitHub Issues** | Prosty system zgłoszeń zintegrowany z GitHub |
| **GitLab Issues** | Analogiczne narzędzie w GitLab |
| **Bugzilla** | Klasyczne, darmowe narzędzie do śledzenia błędów |
| **Trello / Asana** | Tablice do zarządzania zadaniami (w tym defektami) |

Systemy te pozwalają:
- przypisywać defekty konkretnym osobom,
- śledzić status i historię,
- kategoryzować (priorytet, powaga, typ, komponent),
- dodawać komentarze i załączniki,
- generować raporty i statystyki.

---

## Zasady pisania dobrych zgłoszeń

1. **Jeden błąd = jedno zgłoszenie.**
2. **Tytuł krótki i opisowy** – od razu wiadomo, o co chodzi.
3. **Dokładne kroki reprodukcji** – aby programista mógł odtworzyć błąd.
4. **Podaj dane testowe** – login, hasło, pliki, wartości.
5. **Zrzuty ekranu** – warto wstawić obraz, to przyspiesza analizę.
6. **Opisz oczekiwany i rzeczywisty wynik.**
7. **Podaj środowisko** (system, przeglądarka, wersja).
8. **Bądź zwięzły, ale kompletny.**
9. **Sprawdź, czy błąd już nie został zgłoszony** (unikaj duplikatów).

---

## Podsumowanie

- Dobry raport błędu pozwala programiście szybko odtworzyć i naprawić problem.
- Zgłoszenie zawiera: tytuł, środowisko, kroki, oczekiwany/rzeczywisty wynik, załączniki.
- Warto rozróżniać **priorytet** (jak szybko naprawić) i **powagę** (jak bardzo błąd szkodzi).
- Cykl życia defektu kończy się weryfikacją naprawy i zamknięciem.
- Systemy śledzenia błędów (Jira, GitHub Issues) porządkują cały proces.
