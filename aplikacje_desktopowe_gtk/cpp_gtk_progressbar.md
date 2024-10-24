# GTK+ ProgressBar

**GtkProgressBar** w GTK+ to widżet używany do przedstawienia postępu trwającej operacji. Może działać w trybie determistycznym, gdzie wartość postępu jest znana, lub w trybie nieokreślonym (indeterminate), gdzie pokazuje, że operacja trwa, ale nie wiadomo, jak długo to potrwa.

### Kluczowe właściwości **GtkProgressBar**:
- **Wartość postępu**: Można ustawić i aktualizować wartość postępu w zakresie od 0 do 1.
- **Orientacja**: Progress bar może być poziomy lub pionowy.
- **Nieokreślony postęp**: Wyświetla animowany pasek, gdy dokładny postęp nie jest znany.

### Kluczowe funkcje:
- `gtk_progress_bar_new()`: Tworzy nowy widżet `GtkProgressBar`.
- `gtk_progress_bar_set_fraction()`: Ustawia aktualną wartość postępu (od 0 do 1).
- `gtk_progress_bar_set_pulse_step()`: Ustawia krok postępu w trybie nieokreślonym.
- `gtk_progress_bar_pulse()`: Aktualizuje pasek w trybie nieokreślonym.

### Przykład

```c
#include <gtk/gtk.h>

// Funkcja aktualizująca wartość postępu
gboolean update_progress(GtkProgressBar *progress_bar) {
    gdouble fraction = gtk_progress_bar_get_fraction(progress_bar);
    fraction += 0.1; // Zwiększenie postępu o 10%
    
    if (fraction > 1.0)
        fraction = 0.0; // Zresetowanie postępu po osiągnięciu 100%

    gtk_progress_bar_set_fraction(progress_bar, fraction); // Ustawienie nowej wartości
    return TRUE; // Kontynuacja aktualizacji
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ProgressBar Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 100);

    // Tworzenie progressbara
    GtkWidget *progress_bar = gtk_progress_bar_new();
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), 0.0); // Ustawienie początkowej wartości postępu

    // Dodanie progressbara do okna
    gtk_container_add(GTK_CONTAINER(window), progress_bar);

    // Wywoływanie funkcji aktualizującej co 500 ms
    g_timeout_add(500, (GSourceFunc)update_progress, progress_bar);

    // Wyświetlanie widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału do zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Omówienie kodu

1. **Tworzenie ProgressBar**:
   - `gtk_progress_bar_new()` tworzy nowy pasek postępu, którego wartość początkowa wynosi 0.

2. **Ustawienie wartości postępu**:
   - `gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), fraction)` ustawia bieżącą wartość postępu. Wartość musi być liczbą zmiennoprzecinkową w zakresie od 0 do 1, gdzie 0 oznacza brak postępu, a 1 oznacza 100%.

3. **Aktualizacja postępu**:
   - Funkcja `update_progress()` jest wywoływana co 500 ms, zwiększając wartość postępu o 0.1 (10%). Po osiągnięciu wartości 1 (100%) postęp jest resetowany do 0.

### Dodatkowe funkcje dla **GtkProgressBar**

- **`gtk_progress_bar_set_fraction(GtkProgressBar *pbar, gdouble fraction)`**: Ustawia bieżącą wartość postępu (0-1).
- **`gtk_progress_bar_get_fraction(GtkProgressBar *pbar)`**: Pobiera bieżącą wartość postępu.
- **`gtk_progress_bar_pulse(GtkProgressBar *pbar)`**: Animuje pasek w trybie nieokreślonym.
- **`gtk_progress_bar_set_pulse_step(GtkProgressBar *pbar, gdouble step)`**: Ustawia krok dla trybu nieokreślonego (określa, o ile ma przesuwać się pasek po każdym wywołaniu `pulse`).
- **`gtk_progress_bar_set_orientation(GtkProgressBar *pbar, GtkOrientation orientation)`**: Ustawia orientację paska (pionową lub poziomą).

Pasek postępu to powszechnie używany widżet w aplikacjach, które wymagają informowania użytkownika o postępie wykonywanych operacji, takich jak ładowanie plików, przetwarzanie danych czy instalacja oprogramowania.
