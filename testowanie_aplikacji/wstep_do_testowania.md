# Wprowadzenie do testowania oprogramowania

Testowanie oprogramowania to proces oceny i weryfikacji, czy produkt lub aplikacja spełnia określone wymagania oraz działa zgodnie z oczekiwaniami. Celem testowania jest wykrycie błędów (defektów), zapewnienie jakości oprogramowania oraz potwierdzenie, że działa ono poprawnie w różnych warunkach.

---

## Cele testowania

1. **Wykrywanie defektów** – znalezienie błędów, zanim trafią do użytkownika końcowego.
2. **Weryfikacja wymagań** – sprawdzenie, czy oprogramowanie spełnia określone wymagania funkcjonalne i niefunkcjonalne.
3. **Zapewnienie jakości** – potwierdzenie, że produkt spełnia standardy jakości.
4. **Zmniejszenie ryzyka** – minimalizacja prawdopodobieństwa wystąpienia poważnych problemów.
5. **Budowanie zaufania** – zwiększenie pewności klienta i użytkowników co do poprawności działania aplikacji.

> **Ważne:** Testowanie nie polega na "pokazaniu, że oprogramowanie działa". Testowanie ma na celu *wykrycie błędów* – dobre testy to takie, które potrafią znaleźć problemy.

---

## Dlaczego testowanie jest ważne?

- **Oszczędność kosztów** – znalezienie błędu na wczesnym etapie jest znacznie tańsze niż naprawa go po wdrożeniu.
- **Ochrona reputacji** – wadliwe oprogramowanie może zniszczyć zaufanie klientów.
- **Bezpieczeństwo** – w systemach bankowych, medycznych czy przemysłowych błędy mogą mieć poważne konsekwencje.
- **Zgodność z przepisami** – niektóre branże wymagają certyfikacji i udokumentowanych testów.

---

## Podstawowe pojęcia

### Defekt (błąd, bug)
Niedoskonałość w oprogramowaniu, która powoduje, że program zachowuje się niezgodnie z oczekiwaniami. Proces powstawania defektów:

1. **Błąd (mistake/error)** – pomyłka człowieka (np. programisty) podczas tworzenia kodu.
2. **Wada (defect/fault)** – konsekwencja błędu wprowadzona do kodu lub dokumentacji.
3. **Awaria (failure)** – niepoprawne zachowanie oprogramowania wykryte podczas działania.

### Przykład
Programista popełnia **błąd**, pisząc `if (x = 5)` zamiast `if (x == 5)`. Jest to **wada** w kodzie. Gdy program zostanie uruchomiony i nieprawidłowo przypisze wartość, mamy do czynienia z **awarią**.

---

## Poziomy testowania

Testowanie prowadzi się na różnych poziomach, odpowiadających etapom tworzenia oprogramowania:

| Poziom | Opis | Przykład |
|--------|------|----------|
| **Testy jednostkowe** | Testują pojedyncze funkcje, metody lub klasy | Sprawdzenie, czy funkcja `add()` poprawnie sumuje liczby |
| **Testy integracyjne** | Sprawdzają współpracę między modułami | Sprawdzenie, czy moduł logowania poprawnie komunikuje się z bazą danych |
| **Testy systemowe** | Testują cały system jako jedną całość | Sprawdzenie pełnego przepływu zakupu w sklepie internetowym |
| **Testy akceptacyjne** | Weryfikują, czy produkt spełnia wymagania klienta | Potwierdzenie przez klienta, że aplikacja spełnia jego potrzeby |

---

## Zasada "V-model"

V-model łączy etapy tworzenia oprogramowania z odpowiadającymi im poziomami testów. Każdy etap tworzenia ma swój odpowiednik w etapie testowania:

```
Analiza wymagań ──────────── Testy akceptacyjne
        │                            │
Projektowanie systemu ─────── Testy systemowe
        │                            │
Projektowanie modułów ─────── Testy integracyjne
        │                            │
       Kodowanie ──────────── Testy jednostkowe
```

Wcześniejsze przygotowanie testów do każdego etapu pozwala wykrywać błędy jak najwcześniej.

---

## Zasady testowania

1. **Testowanie pokazuje obecność defektów, a nie ich brak** – nawet udane testy nie gwarantują, że oprogramowanie jest wolne od błędów.
2. **Testowanie wyczerpujące nie istnieje** – nie da się przetestować wszystkich kombinacji danych wejściowych.
3. **Testowanie wczesne oszczędza czas i pieniądze** – im wcześniej wykryjemy błąd, tym taniej go naprawić.
4. **Grupowanie defektów** – większość defektów koncentruje się w niewielkiej liczbie modułów (zasada Pareto 80/20).
5. **Paradoks pestycydów** – te same testy powtarzane wielokrotnie przestają wykrywać nowe błędy, dlatego stale trzeba aktualizować zestaw testów.
6. **Testowanie zależy od kontekstu** – inne testy są potrzebne dla systemu bankowego, a inne dla gry komputerowej.
7. **Brak błędów to złudzenie** – system bez błędów, ale nie spełniający potrzeb użytkownika (np. nieodpowiedni dla jego sprzętu), jest bezużyteczny.

---

## Tester a programista

| Tester | Programista |
|--------|-------------|
| Koncentruje się na wykrywaniu błędów | Koncentruje się na tworzeniu kodu |
| Patrzy na oprogramowanie z perspektywy użytkownika | Patrzy na oprogramowanie z perspektywy technicznej |
| Tworzy i wykonuje przypadki testowe | Pisze i poprawia kod |
| Analizuje i raportuje defekty | Naprawia zgłoszone defekty |

W praktyce testerzy i programiści często współpracują, a wiele organizacji stosuje podejście, w którym programiści również piszą testy (np. testy jednostkowe).

---

## Podsumowanie

- Testowanie to kluczowy element wytwarzania oprogramowania.
- Jego celem jest wykrywanie błędów, weryfikacja wymagań i zapewnienie jakości.
- Testowanie prowadzi się na wielu poziomach – od pojedynczych funkcji po cały system.
- Wczesne testowanie pozwala oszczędzić czas i koszty.
- Zasady testowania pomagają projektować skuteczne strategie testowe.
