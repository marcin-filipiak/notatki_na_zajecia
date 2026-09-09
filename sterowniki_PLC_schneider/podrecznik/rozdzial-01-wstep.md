# Rozdział 1 — Wstęp do sterowników PLC

> [Powrót do spisu treści](./README.md)

---

## 1.1 Czym jest sterownik PLC?

**PLC** (ang. *Programmable Logic Controller*) to programowalny sterownik przemysłowy — komputer przystosowany do pracy w trudnych warunkach przemysłowych, zaprojektowany do sterowania maszynami i procesami technologicznymi.

Kluczowe cechy PLC:

- **Odporność** — działa w szerokim zakresie temperatur, odporny na zakłócenia elektromagnetyczne i wibracje
- **Czas rzeczywisty** — deterministyczny cykl skanowania (ok. 1–100 ms)
- **Modułowa budowa** — możliwość rozbudowy o wejścia/wyjścia analogowe, komunikacyjne itp.
- **Programowalność** — zmiana logiki sterowania bez ingerencji w okablowanie
- **Języki standardu IEC 61131-3** — drabinkowy (LD), instrukcyjny (IL), strukturalny (ST), sekwencyjny (SFC), blokowy (FBD)

---

## 1.2 Historia i ewolucja sterowników

| Era | Rozwój |
|-----|--------|
| **Lata 60.** | Pierwszy sterownik PLC — Modicon 084 (1969), zastąpił przekaźniki elektryczne w przemyśle samochodowym |
| **Lata 70.** | PLC staje się standardem w automatyce; pojawiają się programowalne terminale |
| **Lata 80.** | Standard IEC 61131; PLC z portami komunikacyjnymi (RS-232, RS-485) |
| **Lata 90.** | PLC z Ethernetem, wbudowanymi panelami HMI, obsługą analogową |
| **2000+** | Safety PLC, komunikacja IP, IoT, chmura, mini-PLC (takie jak M221) |
| **2020+** | Integracja z IT/OT, Edge Computing, cyberbezpieczeństwo |

---

## 1.3 Rola PLC w automatyce przemysłowej

PLC jest **sercem** większości systemów automatyzacji:

```
  Czujniki          STEROWNIK PLC          Aktuatory
  (wejścia)                              (wyjścia)
   ┌─────┐        ┌─────────────┐        ┌─────────┐
   │  A  │───────▶│  Program    │───────▶│ Silnik  │
   │  B  │───────▶│  drabinkowy │───────▶│ Zawór   │
   │  C  │───────▶│  (Ladder)   │───────▶│ Lampa   │
   └─────┘        └─────────────┘        └─────────┘
        ▲                                     │
        │          Panel operatorski          │
        └─────────────── HMI ◀────────────────┘
```

Przykładowe zastosowania:

- **Produkcja** — sterowanie liniami produkcyjnymi, pakowanie
- **Budynki** — sterowanie wentylacją, ogrzewaniem, oświetleniem (BMS)
- **Infrastruktura** — sterowanie pompowniami, oczyszczalniami
- **Logistyka** — sterowanie przenośnikami, sortowniami
- **Maszyny** — sterowanie obrabiarkami, wtryskarkami

---

## 1.4 PLC vs. sterowanie komputerowe

| Cecha | PLC | Komputer PC |
|-------|-----|-------------|
| Czas pracy | 24/7, bezobsługowy | Wymaga administracji |
| Determinizm | Gwarantowany cykl | Brak gwarancji czasu |
| Odporność na zakłócenia | Przemysłowa | Biurowa |
| Programowanie | IEC 61131-3 | Dowolny język |
| Koszt jednostkowy | Wyższy | Niższy |
| Niezawodność | Bardzo wysoka | Średnia |

> **Podsumowanie:** PLC jest idealnym rozwiązaniem tam, gdzie liczy się **niezawodność**, **determinizm** i **odporność na warunki przemysłowe**.

---

## 1.5 Cykl pracy sterownika PLC (cykl skanowania)

Każdy sterownik PLC wykonuje swoją pracę w **cyklu skanowania** (ang. *scan cycle*), który składa się z trzech faz:

```
┌─────────────────────────────────────────────────┐
│                CYKL SKANOWANIA                  │
│                                                 │
│  1. ODCZYT WEJŚĆ  ──▶  2. WYKONANIE PROGRAMU   │
│                          3. ZAPIS WYJŚĆ         │
│                                                 │
│         ◀──── pętla nieskończona ────▶          │
└─────────────────────────────────────────────────┘
```

### Faza 1 — Odczyt wejść
- Sterownik odczytuje stany wszystkich wejść fizycznych (DI)
- Zapisuje je do **obrazu wejść** (*Input Image Table*)

### Faza 2 — Wykonanie programu
- Program jest oceniany **od lewej do prawej**, **od góry do dołu**
- Wyniki operacji trafiają do **obrazu wyjść**
- Czas wykonania zależy od złożoności programu

### Faza 3 — Zapis wyjść
- Zawartość **obrazu wyjść** jest przesyłana do wyjść fizycznych (DO)
- Cykl powtarza się

**Typowy czas cyklu M221:** ~3–10 ms (zależnie od programu)

---

## 1.6 Podsumowanie

- PLC to niezawodny, deterministyczny sterownik przemysłowy
- Pracuje w cyklu skanowania: odczyt → program → zapis
- Programowanie w języku drabinkowym przypomina schemat elektryczny
- Schneider M221 to compact PLC z rodziny Modicon — idealny do małych i średnich aplikacji

> **Następny rozdział:** [Sterownik Schneider M221 — przegląd sprzętu](./rozdzial-02-sprzet.md)

> [Powrót do spisu treści](./README.md)
