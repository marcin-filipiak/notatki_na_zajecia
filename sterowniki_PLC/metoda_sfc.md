## Metoda SFC – notatki

**SFC (Sequential Function Chart)** to graficzna metoda opisu działania układów sterowania sekwencyjnego. Należy do standardu **IEC 61131-3**, czyli tego samego, który określa języki programowania sterowników PLC.

### Cel metody

Metoda SFC służy do:

* przedstawiania operacji wykonywanych krok po kroku,
* opisu przejść między kolejnymi stanami układu,
* tworzenia logicznych sekwencji sterowania dla maszyn i procesów.

### Elementy SFC

1. **Kroki (Steps)**
   Reprezentują stany układu.
   W kroku mogą być uruchamiane działania, np. włączenie silnika, otwarcie zaworu, zatrzymanie napędu.

2. **Przejścia (Transitions)**
   Łączą kroki.
   Określają warunek przejścia do następnego kroku, np. sygnał z czujnika, upłynięcie czasu, spełnienie warunku logicznego.

3. **Warunki przejścia (Transition Conditions)**
   To logika decydująca o zmianie stanu, np.:

   * czujnik krańcowy aktywny,
   * temperatura osiągnęła wartość,
   * licznik wykonał określoną liczbę impulsów.

4. **Działania (Actions)**
   Instrukcje wykonywane w danym kroku, np.:

   * ustawienie wyjścia,
   * sterowanie siłownikiem,
   * załączenie przekaźnika.

### Schemat działania SFC

* System zaczyna od **kroku początkowego**.
* Wykonuje działania przypisane do tego kroku.
* Gdy spełniony zostanie warunek przejścia, program przechodzi do kolejnego kroku.
* Proces trwa do osiągnięcia końca sekwencji lub powrotu do wcześniejszych kroków (pętle).

### Zastosowanie w elektromechanice

Metoda SFC jest wykorzystywana do:

* programowania sterowników PLC obsługujących maszyny i linie technologiczne,
* tworzenia schematów sterowania napędami, transporterami, windami, prasami, maszynami pakującymi itp.,
* projektowania cykli pracy maszyn z wieloma krokami,
* analizy sekwencji w urządzeniach automatyki.

### Zalety SFC

* czytelność i szybkie zrozumienie przebiegu pracy maszyny,
* łatwe wyszukiwanie błędów w sekwencji,
* logiczny podział procesu na kroki,
* wygodne wprowadzanie zmian w schemacie sterowania.

### Co warto zapamiętać na egzamin

* SFC opisuje **sekwencyjne** działanie układów.
* Najważniejsze elementy: **kroki, przejścia, warunki przejścia, działania**.
* Metoda jest częścią normy **IEC 61131-3**.
* Wykorzystywana do programowania PLC i analizowania procesów automatyki.


Jeśli chcesz, przygotuję następny temat od razu.
