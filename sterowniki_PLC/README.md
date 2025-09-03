1. Wprowadzenie do LAD

Co to jest język drabinkowy i dlaczego przypomina schematy elektryczne.

Jak działa cykl programu w PLC (scan cycle: wejścia → logika → wyjścia).

Struktura programu w LAD: szczeble (rungs), styki (contacts), cewki (coils).

Różnica między wejściami/wyjściami fizycznymi (I/O) a zmiennymi wewnętrznymi (markery, M).

2. Podstawowe elementy LAD

Styki: NO (normalnie otwarty), NC (normalnie zamknięty).

Cewki: standardowe, negowane, SET/RESET.

Łączenie styków szeregowo (AND) i równolegle (OR).

Różnica pomiędzy stykami fizycznych wejść (np. I1, I2), markerami (M1) i stykami odzwierciedlającymi wyjścia (Q1).

3. Podstawowa logika sterowania

Tworzenie prostych równań logicznych: AND, OR, NOT.

Jak zapisać logikę w LAD i w formie równania logicznego.

Przekazywanie wyników między szczeblami (markery).

Zależności czasowe wynikające z kolejności szczebli.

4. Funkcje czasowe

Timery: TON (opóźnienie załączenia), TOF (opóźnienie wyłączenia), TP (impuls).

Typowe zastosowania timerów (np. sterowanie lampą, opóźnienie startu).

Różnice między timerami retencyjnymi (pamiętającymi czas) i nierecencyjnymi.

5. Liczniki

Counter UP (CTU – zliczanie w górę).

Counter DOWN (CTD – zliczanie w dół).

Counter UP/DOWN (CTUD – dwukierunkowy).

Przykłady: licznik cykli, zliczanie produktów, automatyczne resetowanie.

6. Operacje na bitach i zmiennych

Operacje logiczne na markerach i wyjściach.

Instrukcje SET/RESET (RS latch, pamięć przerzutnikowa).

Tworzenie przerzutników RS i bistabilnych układów pamiętających.

7. Operacje arytmetyczne

Dodawanie, odejmowanie, mnożenie, dzielenie.

Porównania (większe, mniejsze, równe).

Zastosowanie arytmetyki do prostych procesów (np. licznik czasu pracy).

8. Struktury programu

Organizacja logiki w szczeblach.

Stosowanie markerów pomocniczych do „przekazywania informacji”.

Dobre praktyki: jeden szczebel = jedna funkcja logiczna.

Czytelność programu, dokumentacja, komentarze.

9. Funkcje zaawansowane

Bloki funkcyjne (FB) i funkcje predefiniowane w sterownikach Schneidera.

Obsługa wejść analogowych.

Operacje na rejestrach i słowach (%MW).

Tworzenie prostych regulatorów, sekwencji krokowych.

10. Projekt praktyczny

Prosty program: sterowanie oświetleniem.

Trochę bardziej złożony: sterowanie silnikiem z blokadami i czasami.

Rozwinięcie: sekwencja krokowa np. automatyczne otwieranie i zamykanie bramy.

Analiza, jak wyglądałby taki sam program w innych językach IEC 61131-3 (ST, FBD).
