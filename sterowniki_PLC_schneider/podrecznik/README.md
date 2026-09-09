# Programowanie Sterowników PLC — Schneider M221 TM221M16R

## Podręcznik do języka drabinkowego (Ladder Diagram) w SoMachine Basic

---

## Spis treści

### Część I — Podstawy

1. [Wstęp do sterowników PLC](./rozdzial-01-wstep.md)
   - Czym jest sterownik PLC?
   - Historia i ewolucja sterowników
   - Rola PLC w automatyce przemysłowej
   - Porównanie PLC z systemami sterowania opartymi na komputerze
   - Cykl pracy sterownika PLC (cykl skanowania)

2. [Sterownik Schneider M221 — przegląd sprzętu](./rozdzial-02-sprzet.md)
   - Rodzina TM221
   - Model TM221M16R — specyfikacja techniczna
   - Architektura wewnętrzna
   - Wejścia cyfrowe (DI) i wyjścia cyfrowe (DO)
   - Zasilanie i montaż na szynie DIN
   - Złącza komunikacyjne (Ethernet, serial, USB)
   - Rozszerzenia modułowe (TM2 expansion)
   - Diody LED statusu

3. [Oprogramowanie SoMachine Basic](./rozdzial-03-somachine.md)
   - Instalacja i wymagania systemowe
   - Struktura interfejsu
   - Tworzenie nowego projektu
   - Konfiguracja sterownika w projekcie
   - Połączenie z sterownikiem (USB / Ethernet)
   - Kompilacja, pobranie i uruchomienie programu
   - Tryb online / offline — monitorowanie w czasie rzeczywistym

### Część II — Język drabinkowy (Ladder Diagram)

4. [Podstawy języka drabinkowego](./rozdzial-04-ladder-podstawy.md)
   - Filozofia języka drabinkowego
   - Zasilacz (Power Rail) i sieci (Rungs)
   - Styki: NO (normalnie otwarty) i NC (normalnie zamknięty)
   - Cewki wyjściowe (Coils)
   - Przekaźniki pomocnicze (Markers / Internal Relays)
   - Zasady kolejności oceniania (lewo → prawo, góra → dół)
   - Adresowanie zmiennych w M221
   - Tabela zmiennych (Symbol Table / DTT)

5. [Bramki logiczne i kombinacje](./rozdzial-05-bramki-logiczne.md)
   - Funkcja AND (szeregowe)
   - Funkcja OR (równoległe)
   - Funkcja NOT (styki NC)
   - Złożone kombinacje logiczne
   - Bloki funkcyjne: SET (S) i RESET (R)
   - Negacja na wyjściach (NC coil)
   - Ćwiczenia praktyczne

### Część III — Bloki funkcyjne i operacje

6. [Timery (Opóźnienia czasowe)](./rozdzial-06-timery.md)
   - Przegląd timerów w M221
   - TON — opóźnienie załączenia (On-Delay)
   - TOF — opóźnienie wyłączenia (Off-Delay)
   - TP — monostabilny (Pulse Timer)
   - RTIM — reset timera
   - Jednostki czasowe i rozdzielczość
   - Przykłady zastosowań timera
   - Ćwiczenia praktyczne

7. [Liczniki (Counters)](./rozdzial-07-liczniki.md)
   - Przegląd liczników w M221
   - CTU — licznik w górę (Count Up)
   - CTD — licznik w dół (Count Down)
   - CTUD — licznik w obie strony (Count Up/Down)
   - Reset licznika (R)
   - Przepływ licznika (overflow / underflow)
   - Przykłady zastosowań
   - Ćwiczenia praktyczne

8. [Operacje na danych i rejestry](./rozdzial-08-dane.md)
   - Typy danych w M221 (BOOL, INT, UINT, DINT, REAL, STRING)
   - Rejestry funkcyjne (GD — Global Data, LD — Local Data)
   - Bloki MOVE i porównawcze
   - Arytmetyka: ADD, SUB, MUL, DIV, MOD
   - Operacje porównania: =, <>, <, >, <=, >=
   - Konwersja typów danych
   - Indeksowanie i tablice

### Część IV — Komunikacja

9. [Komunikacja w M221](./rozdzial-09-komunikacja.md)
   - Ethernet / TCP-IP
   - Modbus TCP
   - Modbus RTU (port szeregowy)
   - Web server wbudowany w sterownik
   - Wymiana danych z innymi urządzeniami
   - Przykład: komunikacja M221 ↔ HMI
   - Przykład: komunikacja M221 ↔ M221

### Część V — Zaawansowane tematy

10. [Funkcje specjalne](./rozdzial-10-funkcje-specjalne.md)
    - Przetwornik analogowy (jeśli rozszerzenie)
    - Funkcja PWM i sterowanie silnikiem
    - Funkcja rampy (RAMP)
    - Funkcja fermentatora (PID-like w M221)
    - Przerwania i HSC (High Speed Counter)
    - Watchdog i nadzór programu

11. [Diagnostyka i debugowanie](./rozdzial-11-diagnostyka.md)
    - Wskaźniki LED na sterowniku
    - Diagnostyka w SoMachine Basic
    - Tryb monitorowania online
    - Wymuszanie stanów (Forcing I/O)
    - Logi zdarzeń i bufor zdarzeń
    - Najczęstsze błędy i sposoby ich usuwania
    - Backup i przywracanie projektu

### Część VI — Projekty praktyczne

12. [Projekt 1 — Sterowanie oświetleniem](./projekt-01-oswietlenie.md)
    - Zadanie: włączanie/wyłączanie lampek z dwóch miejsc
    - Schemat drabinkowy
    - Symulacja i testowanie

13. [Projekt 2 — Sekwencja sterowań z timerami](./projekt-02-sekwencja.md)
    - Zadanie: automatyczna sekwencja uruchamiania urządzeń
    - Wykorzystanie TON/TOF
    - Praca w trybie automatycznym i ręcznym

14. [Projekt 3 — Sterowanie silnikiem krokowym](./projekt-03-silnik.md)
    - Zadanie: sterowanie prędkością i kierunkiem
    - Wyjścia cyfrowe jako impulsy
    - HSC jako enkoder

15. [Projekt 4 — System liczenia i sortowania](./projekt-04-sortowanie.md)
    - Zadanie: liczenie elementów na taśmie i sortowanie
    - Czujniki, liczniki, timery
    - Wyjścia sterujące sortownikiem

---

## Załączniki

- [Słownik terminów](./zalaczniki/slowownik.md)
- [Mapa adresów TM221M16R](./zalaczniki/mapa-adresow.md)
- [Ściągawka — bloki funkcyjne](./zalaczniki/ściagawka-bloki.md)

---

> **Uwaga:** Podręcznik dotyczy sterownika **Schneider Electric Modicon M221 TM221M16R** oraz oprogramowania **SoMachine Basic** (aktualna wersja). Treść może wymagać aktualizacji wraz z nowymi wersjami oprogramowania.
