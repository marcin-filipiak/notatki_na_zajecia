# Język drabinkowy (LAD) – podstawy

## Co to jest język drabinkowy?

* **LAD (Ladder Diagram)** to jeden z języków programowania PLC opisanych w normie **IEC 61131-3**.
* Jest przeznaczony głównie dla elektryków i automatyków – wygląda jak **schemat obwodu elektrycznego**.
* Program składa się z **szczebli (rungs)** ułożonych w pionowej „drabince”.
* Każdy szczebel reprezentuje **logiczne równanie**: warunki (styki) → wynik (cewka, wyjście).

---

## Dlaczego przypomina schematy elektryczne?

* Historycznie, zanim pojawiły się PLC, maszyny były sterowane przy użyciu **przekaźników**.
* Sterowanie budowano jako obwody elektryczne: styki przycisków, krańcówek, przekaźniki, lampy, styczniki.
* LAD odwzorowuje ten sposób myślenia:

  * **Styki (contacts)** w LAD odpowiadają stykowi przycisku albo krańcówki.
  * **Cewki (coils)** odpowiadają przekaźnikom lub wyjściom sterującym.
* Dzięki temu elektryk, który umiał czytać schematy przekaźnikowe, mógł łatwo nauczyć się programować PLC.

---

## Jak wygląda program w LAD?

* Dwa pionowe „szyny zasilania”: lewa (początek logiki) i prawa (rezultat).
* **Szczeble** ułożone poziomo

---

## Struktura szczebla

Każdy **szczebel (rung)** składa się z:

* **warunków po lewej stronie** – styki (contacts), które reprezentują wejścia, markery, bity pomocnicze, stany wyjść,
* **operacji końcowej po prawej stronie** – najczęściej cewka (coil), czyli wynik działania warunków.

Schematycznie:

```
|---[ I1 ]---[ I2 ]---( Q1 )---|
```

Interpretacja: jeśli **I1 AND I2 = TRUE**, to załącz Q1.

---

## Logika w LAD

* **Styki szeregowo** = funkcja **AND** (wszystkie muszą być spełnione).
* **Styki równolegle** = funkcja **OR** (wystarczy jeden warunek spełniony).
* **Styk NC (normalnie zamknięty)** działa jak NOT – neguje sygnał.

---

## Cykl wykonywania programu w PLC

1. **Odczyt wejść** – PLC pobiera aktualne stany wejść fizycznych.
2. **Wykonanie programu** – sterownik przechodzi kolejno przez wszystkie szczeble: Rung 0, Rung 1, itd.
3. **Aktualizacja wyjść** – po zakończeniu całego programu ustalane są nowe stany wyjść.
4. **Powtarzanie cyklu** – wszystko wykonuje się w pętli, bardzo szybko (kilka ms).

To oznacza, że program w LAD działa **ciągle i cyklicznie**, a nie liniowo „raz od początku do końca” jak zwykły kod w C++.

---

## Dlaczego LAD jest użyteczny?

* Jest **intuicyjny** dla osób znających schematy elektryczne.
* **Czytelność** – łatwo zobaczyć logikę działania maszyny.
* **Standaryzacja** – LAD jest częścią normy IEC 61131-3, więc podobnie wygląda w sterownikach różnych producentów.
