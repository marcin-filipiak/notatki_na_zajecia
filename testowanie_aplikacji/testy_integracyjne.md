# Testy integracyjne

**Testy integracyjne** (ang. *integration tests*) sprawdzają, czy poszczególne moduły oprogramowania poprawnie współpracują ze sobą. Podczas gdy testy jednostkowe badają pojedyncze komponenty w izolacji, testy integracyjne weryfikują, czy te komponenty **poprawnie się komunikują** i czy dane są prawidłowo przekazywane między nimi.

---

## Różnica między testami jednostkowymi a integracyjnymi

| Testy jednostkowe | Testy integracyjne |
|-------------------|--------------------|
| Testują pojedynczą funkcję/metodę | Testują współpracę kilku modułów |
| Izolują od zależności (mocki) | Używają rzeczywistych modułów |
| Bardzo szybkie | Wolniejsze (wymagają realnych komponentów) |
| Łatwe w utrzymaniu | Trudniejsze ze względu na zależności |
| Wykrywają błędy w logice modułu | Wykrywają błędy w komunikacji między modułami |

---

## Cele testów integracyjnych

1. **Wykrywanie błędów interfejsu** – problemy z przekazywaniem danych między modułami.
2. **Sprawdzenie kolejności wywołań** – czy moduły wywołują się w poprawnej kolejności.
3. **Weryfikacja obsługi błędów** – co się dzieje, gdy jeden z modułów zwraca błąd lub pustą odpowiedź.
4. **Testowanie współpracy z systemami zewnętrznymi** – bazy danych, API, usługi sieciowe.

---

## Strategie testowania integracji

### 1. Integrated testing (testowanie zintegrowane "od góry")
Wszystkie moduły łączone są naraz i testowane razem (jak BIG BANG).

- **Zalety:** Szybkie w przygotowaniu.
- **Wady:** Trudno zidentyfikować, który moduł powoduje błąd.

### 2. Top-down (od góry w dół)
Zaczynamy od modułów najwyższego poziomu (głównych) i stopniowo dołączamy moduły niższego poziomu. Moduły, których brakuje, zastępujemy **stubami**.

### 3. Bottom-up (od dołu do góry)
Zaczynamy od modułów najniższego poziomu i łączymy je na wyższych poziomach. Brakujące moduły górne zastępujemy **driverami** (obiektami wywołującymi).

---

## Typowe miejsca testowania integracyjnego

- **Integracja z bazą danych** – czy zapytania działają poprawnie z realną bazą.
- **Integracja z API / usługami sieciowymi** – czy aplikacja poprawnie korzysta z zewnętrznego API.
- **Integracja z zewnętrznymi służbami** – płatności, wysyłka e-mail, usługi chmurowe.
- **Integracja warstw aplikacji** – np. warstwa logiki biznesowej z warstwą prezentacji.

---

## Przykład testu integracyjnego

Rozważmy aplikację sklepu internetowego z modułami:
- `ProductRepository` – pobiera produkty z bazy danych.
- `CartService` – zarządza koszykiem zakupów.
- `CheckoutService` – realizuje zamówienie.

Test jednostkowy sprawdzi `CheckoutService` w izolacji (z mockiem `CartService`).  
Test integracyjny sprawdzi, czy `CheckoutService` poprawnie komunikuje się z **rzeczywistym** `CartService`, a ten z prawdziwą bazą danych.

```python
# Test integracyjny – sprawdzamy współpracę CheckoutService z bazą
def test_checkout_creates_order_in_database():
    # Arrange
    cart = CartService(database)  # prawdziwy moduł, nie mock

    # Act
    order = CheckoutService(database).checkout(cart)

    # Assert
    saved_order = database.get_order(order.id)
    assert saved_order.total == order.total
```

---

## Kiedy piszemy testy integracyjne?

Testy integracyjne piszemy, gdy:
- Moduły komunikują się ze sobą przez interfejsy / API.
- Używana jest baza danych lub zewnętrzne usługi.
- Chcemy sprawdzić pełny przepływ danych w aplikacji.
- Zachodzi ryzyko, że moduły poprawnie działają osobno, ale nie współpracują ze sobą.

---

## Wady testów integracyjnych

- **Wolniejsze** niż testy jednostkowe (wymagają uruchomienia baz i usług).
- **Trudniejsze w utrzymaniu** – zmiana jednego modułu może zepsuć wiele testów.
- **Bardziej kruche** – problemy ze środowiskiem (brak bazy, sieci) mogą powodować fałszywe porażki.
- **Trudniej jest wskazać źródło błędu.**

---

## Podejście "testowa piramida" (testing pyramid)

**Testowa piramida** to wzorzec mówiący o proporcji testów w projekcie:

```
         /\
        /  \        Testy E2E (niewiele)
       /----\
      /      \      Testy integracyjne (kilka)
     /--------\
    /          \    Testy jednostkowe (najwięcej)
   /------------\
```

- **Najwięcej** testów jednostkowych (szybkie, tanie).
- **Mniej** testów integracyjnych (zależności od środowiska).
- **Najmniej** testów end-to-end (wolnych i kosztownych).

---

## Podsumowanie

- Testy integracyjne sprawdzają współpracę między modułami.
- Różnią się od jednostkowych tym, że używają rzeczywistych komponentów.
- Istnieją różne strategie integracji (top-down, bottom-up, big bang).
- Zgodnie z piramidą testową integracyjnych testów powinno być mniej niż jednostkowych, ale są one kluczowe dla wykrywania błędów komunikacji między modułami.
