# Ciągła integracja i ciągłe dostarczanie (CI/CD)

**CI/CD** to praktyki, które automatyzują proces budowania, testowania i wdrażania oprogramowania. Dzięki nim zespoły mogą szybko i bezpiecznie dostarczać nowe wersje aplikacji.

---

## Ciągła integracja (CI – Continuous Integration)

**CI** polega na tym, że programiści **często łączą** (integrują) swoje zmiany w głównej gałęzi repozytorium, a każda integracja jest **automatycznie testowana** i budowana.

### Jak działa CI?
1. Programista wysyła zmiany do repozytorium (np. `git push`).
2. Serwer CI automatycznie pobiera nowy kod.
3. Uruchamiane są: build (kompilacja), testy jednostkowe, testy integracyjne, analiza statyczna.
4. Jeśli wszystko przejdzie – kod jest gotowy.
5. Jeśli któryś test zawiedzie – programista natychmiast otrzymuje informację i naprawia błąd.

### Korzyści CI
- **Szybkie wykrywanie błędów** – problemy znajdujemy w dniu ich powstania.
- **Mniejsze konflikty** – zmianom często łączymy, więc rzadziej dochodzi do konfliktów.
- **Wysoka pewność** – kod w głównej gałęzi jest zawsze w stanie "działającym".

---

## Ciągłe dostarczanie (CD – Continuous Delivery) i wdrażanie (Continuous Deployment)

### Ciągłe dostarczanie (CD)
Automatycznie przygotowuje kod do wydania w środowisku produkcyjnym, ale **finałowe wdrożenie** wymaga zatwierdzenia przez człowieka.

### Ciągłe wdrażanie (Continuous Deployment)
Wdrożenie do produkcji jest **w pełni automatyczne** – po przejściu testów nowa wersja trafia do produkcji bez udziału człowieka.

---

## Różnica między CI a CD

| | CI | Continuous Delivery | Continuous Deployment |
|---|----|--------------------|----------------------|
| Budowanie + testowanie | ✔ | ✔ | ✔ |
| Automatyczne przygotowanie do wydania | | ✔ | ✔ |
| Automatyczne wdrożenie do produkcji | | | ✔ |
| Udział człowieka w wdrożeniu | — | Tak (zatwierdzenie) | Nie |

---

## Przepływ CI/CD – przykład

```
    ┌────────────┐     ┌─────────────┐     ┌──────────────┐
    │ git push   │ →  │  Build       │ →  │  Testy:      │
    │ (zmiany)   │     │  (kompilacja)│     │  jednostkowe,│
    └────────────┘     └─────────────┘     │  integracyjne,│
                                           │  E2E         │
                                           └──────┬───────┘
                                                  ▼
                                           ┌──────────────┐
                                           │  Analiza     │
                                           │  statyczna   │
                                           └──────┬───────┘
                                                  ▼
                                           ┌──────────────┐
                                           │  Wdrożenie   │
                                           │  (staging →  │
                                           │  prod)       │
                                           └──────────────┘
```

Jeśli którykolwiek etap zawiedzie, proces się zatrzymuje i wysyła powiadomienie o błędzie.

---

## Narzędzia CI/CD

| Narzędzie | Typ |
|-----------|-----|
| **Jenkins** | Samodzielny serwer CI |
| **GitHub Actions** | Zintegrowany z GitHub |
| **GitLab CI** | Zintegrowany z GitLab |
| **CircleCI** | Usługa chmurowa |
| **Travis CI** | Usługa chmurowa (open source) |
| **Azure DevOps** | Platforma Microsoft |

### Przykład przepływu GitHub Actions (`.github/workflows/tests.yml`):

```yaml
name: Run tests

on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - name: Setup Python
        uses: actions/setup-python@v5
        with:
          python-version: '3.11'
      - name: Run tests
        run: |
          pip install pytest
          pytest
```

---

## Rola testowania w CI/CD

Testy są **sercem** procesu CI/CD – to one decydują, czy nowa wersja kodu jest bezpieczna do wydania:

- **Testy jednostkowe** – szybka weryfikacja poszczególnych funkcji.
- **Testy integracyjne** – sprawdzenie współpracy modułów.
- **Testy E2E** – pełne scenariusze użytkownika.
- **Testy wydajności** – czy system wytrzyma obciążenie.
- **Testy bezpieczeństwa** – brak nowych luk.

Automatyzacja tych testów w CI/CD pozwala uruchamiać je **przy każdej zmianie kodu**, co radykalnie ogranicza ryzyko błędów.

---

## Podsumowanie

- CI automatycznie buduje i testuje każdą zmianę kodu.
- CD automatycznie przygotowuje (lub wdraża) aplikację do produkcji.
- Testy automatyczne są kluczowym elementem CI/CD – pilnują, że nowe zmiany nie psują aplikacji.
- Narzędzia takie jak GitHub Actions czy Jenkins ułatwiają konfigurację całego procesu.
