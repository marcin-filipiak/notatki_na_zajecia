# Proces testowania oprogramowania

Proces testowania to uporządkowany zbiór działań mających na celu planowanie, przygotowanie i wykonanie testów oraz ocenę ich wyników. Dobrze zorganizowany proces testowania zwiększa wykrywalność defektów i poprawia jakość oprogramowania.

---

## Etapy procesu testowania

### 1. Planowanie testów
- Określenie **celów testowania** (co chcemy osiągnąć).
- Analiza **wymagań** oraz **ryzyka**.
- Określenie **zakresu testów** (co będzie testowane, a co nie).
- Wybór **strategii testowania** i **rodzajów testów**.
- Szacowanie zasobów (czas, ludzie, środowisko, narzędzia).

**Efekt:** Plan testów (ang. *Test Plan*).

### 2. Projektowanie testów
- Tworzenie **przypadków testowych** (scenariuszy) na podstawie wymagań.
- Określenie **danych testowych**.
- Ustalenie **kolejności i priorytetów** wykonywania testów.

**Efekt:** Zestaw przypadków testowych.

### 3. Przygotowanie środowiska i danych
- Konfiguracja środowiska testowego (sprzęt, system, aplikacja).
- Przygotowanie **danych testowych** (np. kont testowych użytkowników, rekordów w bazie danych).

### 4. Wykonanie testów
- Uruchamianie testów zgodnie z planem i przypadkami testowymi.
- Rejestrowanie wyników.
- Porównanie rzeczywistych wyników z wynikami oczekiwanymi.

### 5. Zgłaszanie i śledzenie defektów
- Rejestrowanie wykrytych defektów w systemie śledzenia błędów (np. Jira, Bugzilla).
- Opisanie kroków reprodukcji błędu, priorytetu i powagi (patrz: `raportowanie_bledow.md`).
- Monitorowanie statusu defektów aż do ich naprawy i weryfikacji.

### 6. Raportowanie wyników
- Opracowanie **raportu z testów** – podsumowanie wykonanych testów, liczby wykrytych defektów, oceny jakości.
- Informowanie zespołu i kierownictwa o gotowości produktu do wydania.

### 7. Zakończenie testów (closure)
- Zebranie wniosków z całego procesu.
- Archiwizacja przypadków testowych i raportów.
- Identyfikacja obszarów do doskonalenia procesu testowania na przyszłość.

---

## Dokumenty w procesie testowania

| Dokument | Opis |
|----------|------|
| **Plan testów** | Cel, zakres, strategia, zasoby i harmonogram testów |
| **Specyfikacja przypadku testowego** | Szczegółowy opis kroków, danych i oczekiwanych wyników |
| **Raport z wykonania testów** | Wyniki wykonanych testów i ich status |
| **Raport defektów** | Szczegółowy opis znalezionych błędów |
| **Raport końcowy z testów** | Podsumowanie całego procesu testowania i ocena gotowości produktu |

---

## Wejście i wyjście procesu testowania

### Wejścia (co potrzebujemy, aby zacząć testować):
- **Wymagania funkcjonalne i niefunkcjonalne** – co system ma robić.
- **Dokumentacja projektowa** – jak system jest zbudowany.
- **Kod aplikacji** – co będziemy testować.
- **Środowisko testowe** – sprzęt, oprogramowanie, dane.
- **Plan testów** – jak będziemy testować.

### Wyjścia (co otrzymujemy z procesu testowania):
- **Raporty z testów** – co zostało przetestowane i z jakim wynikiem.
- **Lista defektów** – błędy, które należy naprawić.
- **Ocena jakości** – czy produkt jest gotowy do wydania.
- **Wnioski i rekomendacje** – co poprawić w przyszłości.

---

## Kryteria rozpoczęcia i zakończenia testów

### Czynniki decydujące o rozpoczęciu testów ("readiness"):
- Dostępna jest stabilna wersja kodu do testowania.
- Przygotowane jest środowisko testowe.
- Dostępne są wymagania i przypadki testowe.

### Kryteria zakończenia testów:
- Wszystkie zaplanowane testy zostały wykonane.
- Liczba otwartych defektów o wysokim priorytecie jest równa zero.
- Osiągnięto założony poziom pokrycia testami (np. 90% pokrycia kodu).
- Zgodnie z harmonogramem i budżetem projektu.

---

## Czym jest pokrycie testami (test coverage)?

**Pokrycie testami** to miara informująca, jak duża część systemu została przetestowana. Przykłady:
- **Pokrycie kodu** – procent linii kodu, które zostały wykonane podczas testów.
- **Pokrycie funkcji** – procent funkcji, które zostały przetestowane.
- **Pokrycie wymagań** – procent wymagań, dla których istnieją i zostały wykonane testy.

Wysokie pokrycie zwiększa pewność, że system działa poprawnie, ale **nie gwarantuje braku błędów**.

---

## Podsumowanie

- Proces testowania składa się z planowania, projektowania, wykonania i raportowania.
- Wymaga dobrze zdefiniowanej dokumentacji (plan testów, przypadki testowe, raporty).
- Odpowiednio prowadzony proces pozwala systematycznie wykrywać i eliminować defekty.
- Pokrycie testami pomaga ocenić kompletność testowania.
