# GTK+ ProgressBar

**ProgressBar** w GTK+ to widżet służący do wizualizacji postępu operacji, takich jak kopiowanie plików, ładowanie danych lub wykonywanie długotrwałych zadań. Umożliwia użytkownikowi śledzenie, jak daleko proces przeszedł w odniesieniu do całości. Widżet ten może być używany zarówno w trybie deterministycznym, gdzie wartości są znane, jak i w trybie nieokreślonym, gdzie postęp jest nieprzewidywalny. ProgressBar można łatwo dostosować do różnych zastosowań, zmieniając jego styl i zachowanie.

## Kod aplikacji GTK+, który wyświetla ProgressBar

```c
#include <gtk/gtk.h>

// Funkcja wywoływana przy zamknięciu okna
static void on_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit(); // Kończy pętlę główną GTK+
}

int main(int argc, char *argv[]) {
    // Inicjalizacja GTK+
    gtk_init(&argc, &argv);

    // Tworzenie głównego okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Prosty ProgressBar GTK+");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Tworzenie kontenera box
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Tworzenie ProgressBar
    GtkWidget *progressbar = gtk_progress_bar_new();
    gtk_box_pack_start(GTK_BOX(box), progressbar, TRUE, TRUE, 0);

    // Ustawienie wartości ProgressBar
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar), 0.0);
    
    // Podłączenie sygnału z zamknięciem okna do funkcji on_destroy
    g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);

    // Wyświetlenie wszystkich widżetów
    gtk_widget_show_all(window);

    // Rozpoczęcie pętli głównej GTK+
    gtk_main();

    return 0;
}
```

### Omówienie kodu

1. **`#include <gtk/gtk.h>`**
   - Dołącza nagłówek biblioteki GTK+. Umożliwia korzystanie z funkcji, typów i makr zdefiniowanych w GTK+.

2. **`static void on_destroy(GtkWidget *widget, gpointer data)`**
   - Definiuje funkcję `on_destroy`, która będzie wywoływana przy zamknięciu okna. Używa `static`, aby funkcja była widoczna tylko w tym pliku źródłowym.

3. **`gtk_main_quit();`**
   - Kończy pętlę główną GTK+. Wywołana, gdy użytkownik zamknie okno.

4. **`int main(int argc, char *argv[])`**
   - Główna funkcja programu. `argc` to liczba argumentów wiersza poleceń, a `argv` to tablica tych argumentów.

5. **`gtk_init(&argc, &argv);`**
   - Inicjalizuje bibliotekę GTK+. Niezbędne przed wywołaniem jakichkolwiek funkcji GTK. Argumenty są przekazywane, aby GTK mogło obsługiwać argumenty wiersza poleceń.

6. **`GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);`**
   - Tworzy nowe okno główne aplikacji. `GTK_WINDOW_TOPLEVEL` oznacza, że jest to okno główne, które będzie miało ramki i przyciski systemowe.

7. **`gtk_window_set_title(GTK_WINDOW(window), "Prosty ProgressBar GTK+");`**
   - Ustawia tytuł okna.

8. **`gtk_container_set_border_width(GTK_CONTAINER(window), 10);`**
   - Ustawia szerokość marginesu wokół zawartości okna na 10 pikseli.

9. **`GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);`**
   - Tworzy kontener typu `box`, który organizuje zawartość w pionie. Wartość `5` oznacza odstęp między widżetami w boxie.

10. **`gtk_container_add(GTK_CONTAINER(window), box);`**
    - Dodaje kontener box do okna, aby zorganizować inne widżety.

11. **`GtkWidget *progressbar = gtk_progress_bar_new();`**
    - Tworzy nowy widżet ProgressBar.

12. **`gtk_box_pack_start(GTK_BOX(box), progressbar, TRUE, TRUE, 0);`**
    - Dodaje ProgressBar do kontenera box. Umożliwia to dostosowanie, jak będzie się rozciągał w pionie i poziomie, a ostatni argument `0` oznacza, że nie ma dodatkowego marginesu.

13. **`gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar), 0.0);`**
    - Ustawia wartość początkową ProgressBar na 0.0 (brak postępu).

14. **`g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);`**
    - Łączy sygnał "destroy" z funkcją `on_destroy`. Wywołana, gdy użytkownik zamknie okno.

15. **`gtk_widget_show_all(window);`**
    - Wyświetla wszystkie widżety w oknie.

16. **`gtk_main();`**
    - Rozpoczyna pętlę główną GTK, która obsługuje zdarzenia, takie jak kliknięcia myszą.

17. **`return 0;`**
    - Zwraca 0, co oznacza, że program zakończył się pomyślnie.

### Możliwości widżetu ProgressBar

1. **Ustawianie postępu**
   - **`gtk_progress_bar_set_fraction(GtkProgressBar *progressbar, gdouble fraction)`**
     - Umożliwia ustawienie postępu w skali od 0.0 do 1.0.
     - Przykład:
       ```c
       gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar), 0.5); // 50% postępu
       ```

2. **Zmienianie stylu**
   - **`gtk_progress_bar_set_pulse_step(GtkProgressBar *progressbar, gdouble step)`**
     - Umożliwia ustawienie kroku dla pulsacji, co jest użyteczne w trybie nieokreślonym.
     - Przykład:
       ```c
       gtk_progress_bar_set_pulse_step(GTK_PROGRESS_BAR(progressbar), 0.1);
       ```

3. **Pulsowanie postępu**
   - **`gtk_progress_bar_pulse(GtkProgressBar *progressbar)`**
     - Umożliwia animowanie postępu w trybie nieokreślonym. Przydaje się, gdy postęp nie jest znany.
     - Przykład:
       ```c
       gtk_progress_bar_pulse(GTK_PROGRESS_BAR(progressbar));
       ```

4. **Zmienianie orientacji**
   - **`gtk_progress_bar_set_orientation(GtkProgressBar *progressbar, GtkProgressBarOrientation orientation)`**
     - Umożliwia zmianę orientacji ProgressBar na poziomą lub pionową.
     - Przykład:
       ```c
       gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progressbar), GTK_PROGRESS_BAR_ORIENTATION_VERTICAL);
       ```

5. **Dodawanie tekstu**
   - **`gtk_progress_bar_set_text(GTKProgressBar *progressbar, const gchar *text)`**
     - Umożliwia wyświetlenie tekstu na ProgressBarze, informując użytkownika o aktualnym stanie.
     - Przykład:
       ```c
       gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progressbar), "Ładowanie...");
       ```

Dzięki tym funkcjom i możliwościom, ProgressBar w GTK+ jest elastycznym narzędziem do wizualizacji postępu operacji w aplikacjach.
