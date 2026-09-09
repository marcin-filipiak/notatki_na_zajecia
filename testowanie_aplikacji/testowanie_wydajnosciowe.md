# Testowanie wydajnościowe

**Testowanie wydajności** (ang. *performance testing*) to rodzaj testów niefunkcjonalnych, który sprawdza, jak szybko i stabilnie system odpowiada na zapytania, jak skaluje się pod obciążeniem oraz czy nie ulega awarii w warunkach ekstremalnych.

---

## Dlaczego testujemy wydajność?

- **Zadowolenie użytkowników** – wolna aplikacja zniechęca użytkowników.
- **Stabilność systemu** – uniknięcie awarii przy dużym obciążeniu.
- **Optymalizacja kosztów** – wykrycie wąskich gardeł pozwala optymalizować infrastrukturę.
- **Weryfikacja wymagań** – np. "system ma obsłużyć 1000 równoczesnych użytkowników".

---

## Kluczowe metryki wydajności

### Czas odpowiedzi (response time)
Czas, jaki upływa od wysłania zapytania do otrzymania odpowiedzi. Mierzy się go zwykle w milisekundach (ms) lub sekundach.

### Przepustowość (throughput)
Liczba zapytań lub transakcji, które system może obsłużyć w jednostce czasu (np. zapytania na sekundę – requests per second).

### Liczba równoczesnych użytkowników
Ilu użytkowników może korzystać z systemu jednocześnie, bez znaczącego spadku wydajności.

### Wykorzystanie zasobów
Poziom wykorzystania procesora (CPU), pamięci RAM, dysku i sieci podczas pracy systemu.

### Wskaźnik błędów (error rate)
Odsetek zapytań zakończonych błędem.

---

## Rodzaje testów wydajnościowych

### Test obciążeniowy (load testing)
Sprawdza zachowanie systemu przy **przewidywanym, normalnym obciążeniu**.

**Przykład:** System powinien obsługiwać 1000 użytkowników. Testujemy go z 1000 użytkowników i sprawdzamy, czy czasy odpowiedzi mieszczą się w normie.

### Test przeciążeniowy / stresowy (stress testing)
Sprawdza zachowanie systemu przy obciążeniu **większym niż normalne** – aż do granic wytrzymałości.

**Cel:** Określenie, kiedy system "pada", i jak się zachowuje (czy się odzyskuje).

### Test wytrzymałościowy (soak testing / endurance testing)
Sprawdza stabilność systemu przy **długotrwałym obciążeniu** (np. przez kilka godzin lub dni), aby wykryć wycieki pamięci.

### Test skalowalności (scalability testing)
Sprawdza, jak system reaguje na **zwiększanie zasobów** (np. dodawanie serwerów) – czy wydajność rośnie proporcjonalnie.

### Test szczytowy (spike testing)
Symuluje nagły, gwałtowny wzrost obciążenia (np. podczas wyprzedaży "Black Friday") i sprawdza reakcję systemu.

---

## Narzędzia do testów wydajnościowych

| Narzędzie | Opis |
|-----------|------|
| **Apache JMeter** | Popularne, darmowe narzędzie do testów obciążeniowych aplikacji webowych |
| **Gatling** | Wydajne narzędzie o zwięzłej składni, dobre dla skalowalnych testów |
| **k6** | Nowoczesne narzędzie open source o podejściu kodowym |
| **LoadRunner** | Komercyjne narzędzie dużych firm |
| **Locust** | Testy obciążeniowe pisane w Pythonie |
| **siege / ab** | Proste narzędzia linii poleceń do szybkich testów HTTP |

---

## Przykład scenariusza testu obciążeniowego

1. **Cel:** Serwis API ma obsłużyć 500 równoczesnych zapytań w czasie < 2 sekundy.
2. **Plan:** Testujemy wzrastającą liczbę użytkowników: 50, 100, 200, 500, 1000.
3. **Metryki:** czas odpowiedzi, przepustowość, wykorzystanie CPU i pamięci, liczba błędów.
4. **Wynik:** raport pokazujący, przy jakim obciążeniu czasy odpowiedzi przekraczają 2 sekundy.

```
Użytkownicy   Średni czas odpowiedzi   Przepustowość rps   Błędy
50            350 ms                    180                 0
100           520 ms                    320                 0
200           830 ms                    540                 0
500           1950 ms                   980                 12
1000          6400 ms                   1100                340
```

Wniosek: przy 500 użytkowników system nadal spełnia wymagania, ale przy 1000 ulega przeciążeniu.

---

## Najczęstsze błędy przy testach wydajności

1. **Test bez planu** – brak jasno zdefiniowanych celów i metryk.
2. **Test w środowisku testowym różnym od produkcyjnego** – wyniki niemiarodajne.
3. **Symulacja nierealistycznego obciążenia** – np. brak symulacji czasu myślenia użytkownika.
4. **Brak czyszczenia danych między testami** – nagromadzone dane zawyżają obciążenie.
5. **Ignorowanie monitorowania systemu** – bez monitorowania CPU/RAM nie wiemy, dlaczego system zwalnia.

---

## Podsumowanie

- Testy wydajnościowe sprawdzają szybkość, stabilność i skalowalność systemu.
- Mierzymy czasy odpowiedzi, przepustowość, liczbę użytkowników i wykorzystanie zasobów.
- Rodzaje testów: obciążeniowy, stresowy, wytrzymałościowy, skalowalności, szczytowy.
- Narzędzia takie jak JMeter czy k6 ułatwiają automatyzację testów wydajnościowych.
- Wyniki testów wydajności musi zostać zinterpretowany w kontekście wymagań systemu.
