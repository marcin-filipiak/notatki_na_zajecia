### Testowanie regresji – Notatka na lekcję

#### **Czym jest testowanie regresji?**
Testowanie regresji to proces weryfikacji, czy nowe zmiany w kodzie (np. poprawki błędów, nowe funkcje) nie wpłynęły negatywnie na już działającą część aplikacji. Jest to kluczowy etap w zapewnieniu jakości oprogramowania (QA), szczególnie w dynamicznie rozwijających się projektach.

---

#### **Jak przebiega testowanie regresji?**

1. **Identyfikacja zakresu testów**: 
   - Wybór przypadków testowych związanych z modyfikacjami oraz tych, które mogą zostać pośrednio dotknięte zmianami.
   
2. **Przygotowanie środowiska testowego**: 
   - Uruchomienie aplikacji w kontrolowanym środowisku, z odpowiednimi danymi testowymi.

3. **Wykonanie testów**:
   - Można to zrobić ręcznie (tester uruchamia aplikację i sprawdza działanie funkcji) lub automatycznie (za pomocą narzędzi takich jak Selenium, JUnit czy Cypress).

4. **Analiza wyników**:
   - Porównanie wyników testów z oczekiwanymi rezultatami.

5. **Raportowanie błędów**:
   - Jeśli testy ujawnią problem, informacja o nim trafia do zespołu programistycznego.

---

#### **Przykład**
Załóżmy, że aplikacja e-commerce otrzymuje nową funkcję: możliwość filtrowania produktów według koloru. Programista wprowadza tę funkcję, ale przypadkowo zmienia także sposób wyświetlania produktów w koszyku.  
Testowanie regresji obejmuje:
- Sprawdzenie, czy filtrowanie działa zgodnie z założeniami.
- Weryfikację, czy funkcje takie jak dodawanie produktów do koszyka lub składanie zamówienia nadal działają poprawnie.

---

#### **Zalety testowania regresji**
1. **Zapewnienie jakości**: Minimalizuje ryzyko wprowadzenia nowych błędów.
2. **Oszczędność czasu**: Automatyczne testy regresji szybko wykrywają błędy.
3. **Wsparcie rozwoju**: Ułatwia wprowadzanie nowych funkcji bez destabilizacji aplikacji.

---

#### **Wady testowania regresji**
1. **Koszty**: Automatyzacja wymaga czasu i zasobów na stworzenie testów.
2. **Czasochłonność**: Testy ręczne mogą być długotrwałe, szczególnie w dużych aplikacjach.
3. **Złożoność**: Utrzymanie i aktualizacja przypadków testowych w miarę rozwoju projektu.

---

#### **Kto stosuje testowanie regresji i do czego?**
Testowanie regresji jest stosowane przez:
- **Zespoły QA**: W celu wykrycia błędów w działających funkcjach.
- **Programistów**: Do szybkiego weryfikowania wprowadzonych zmian.
- **Firmy IT**: W procesie tworzenia aplikacji mobilnych, webowych, gier czy systemów korporacyjnych.

Przykłady zastosowania:
- Weryfikacja zmian w aplikacjach bankowych (np. nowe opcje płatności).
- Testy w systemach ERP, które muszą działać stabilnie po każdej aktualizacji.

---

#### **Podsumowanie**
Testowanie regresji to nieodzowny element tworzenia oprogramowania, szczególnie w projektach wymagających ciągłego rozwoju. Wspiera stabilność i jakość aplikacji, ale wymaga starannego planowania i zasobów. Dzięki odpowiednim narzędziom i podejściu może być efektywne zarówno w małych, jak i dużych zespołach.
