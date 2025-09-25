### Markery i zmienne w EcoStruxure Machine Expert

1. **Marker / Flaga**

   * Zmienna używana wyłącznie **wewnętrznie w programie**, nie jest powiązana z fizycznym wejściem/wyjściem.
   * Służy do **przechowywania stanów logicznych** lub liczb do sterowania sekwencjami w programie.
   * Typowym przykładem jest **%MB** lub %MW, które pełnią rolę flag/markerów.

---

### Typy zmiennych

| Typ     | Rozmiar | Zakres                 | Zastosowanie                                         |
| ------- | ------- | ---------------------- | ---------------------------------------------------- |
| **%MB** | 1 bit   | 0 lub 1                | Flagi, markery bitowe, stany logiczne                |
| **%MW** | 16 bit  | -32768…32767 / 0…65535 | Liczby całkowite, markery słowne                     |
| **%MD** | 32 bit  | większy zakres         | Duże liczby całkowite, markery podwójne słowo        |
| **%ML** | 64 bit  | bardzo duży zakres     | Specjalistyczne zastosowania, duże wartości liczbowe |

---

### Podsumowanie

* **Marker** = zmienna używana wewnętrznie w programie (flagowa lub licznikowa).
* **%MB** = pojedynczy bit, najczęściej używany jako flaga/marker.
* **%MW, %MD, %ML** = słowa/duże słowa do przechowywania wartości liczbowych, mogą też pełnić rolę markerów.
