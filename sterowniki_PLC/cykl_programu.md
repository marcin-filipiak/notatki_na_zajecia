Jasne, oto notatka w Markdown o cyklu pracy programu w PLC:

---

# Cykl programu w PLC (scan cycle)

## Co to jest cykl programu?

* **Cykl programu (scan cycle)** to powtarzająca się sekwencja działań, którą wykonuje sterownik PLC.
* Każdy cykl obejmuje: odczyt wejść, wykonanie programu, aktualizację wyjść i czynności systemowe.
* Cykl powtarza się nieprzerwanie, aż do zatrzymania sterownika.

---

## Etapy cyklu programu

### 1. Odczyt wejść (Input Scan)

* PLC odczytuje stany wszystkich **wejść fizycznych** (np. przyciski, czujniki, krańcówki).
* Stany te są zapisywane do **obrazu wejść (input image table)** – specjalnej pamięci sterownika.
* Program korzysta z tego obrazu, a nie bezpośrednio z wejść fizycznych.

---

### 2. Wykonanie programu (Program Execution)

* Sterownik wykonuje program w języku LAD (lub innym zgodnym z IEC 61131-3).
* Szczeble (rungs) są analizowane **od góry do dołu**, każdy od lewej do prawej.
* Wyniki działań logicznych są zapisywane do **zmiennych wewnętrznych** i do **obrazu wyjść (output image table)**.

---

### 3. Aktualizacja wyjść (Output Scan)

* Po zakończeniu całego programu PLC przepisuje wartości z obrazu wyjść do **fizycznych wyjść sterownika**.
* Dzięki temu wyjścia zmieniają stan tylko raz na cykl – eliminuje to przypadkowe migotanie.

---

### 4. Czynności systemowe (Housekeeping)

* PLC może w tym czasie wykonywać dodatkowe zadania:

  * komunikację sieciową,
  * obsługę zegara czasu rzeczywistego,
  * diagnostykę błędów.

---

## Schemat cyklu

```
Odczyt wejść → Wykonanie programu → Aktualizacja wyjść → Zadania systemowe → powrót na początek
```

---

## Czas cyklu

* Cały cykl trwa zwykle od kilku do kilkudziesięciu milisekund, zależnie od:

  * długości programu,
  * szybkości sterownika,
  * ilości obsługiwanych wejść/wyjść.
  * Program zawsze działa **cyklicznie i powtarzalnie**, co gwarantuje przewidywalność sterowania.
