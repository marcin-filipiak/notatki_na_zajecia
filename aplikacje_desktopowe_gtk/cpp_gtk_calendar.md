# GTK+ Calendar

**GtkCalendar** w GTK+ to widżet, który pozwala użytkownikom na wybór daty w formacie kalendarza. Umożliwia interaktywne przeglądanie miesięcy i lat oraz wybieranie konkretnych dni, co czyni go idealnym do wprowadzania danych związanych z czasem.

### Kluczowe właściwości **GtkCalendar**:
- **Przeglądanie miesięcy**: Użytkownik może przechodzić między miesiącami i latami.
- **Wybór daty**: Umożliwia użytkownikowi wybór jednej lub więcej dat.
- **Zaznaczanie dni**: Możliwość zaznaczania wielu dni, co przydaje się w aplikacjach do rezerwacji lub planowania.

### Kluczowe funkcje:
- `gtk_calendar_new()`: Tworzy nowy widżet `GtkCalendar`.
- `gtk_calendar_get_date()`: Pobiera aktualnie zaznaczoną datę z kalendarza.
- `gtk_calendar_select_month()`: Ustawia widok na określony miesiąc i rok.

### Przykład

```c
#include <gtk/gtk.h>

// Funkcja wywoływana po wybraniu daty
void on_date_changed(GtkCalendar *calendar, gpointer user_data) {
    guint year, month, day;
    gtk_calendar_get_date(calendar, &year, &month, &day); // Pobiera datę
    g_print("Wybrana data: %04d-%02d-%02d\n", year, month + 1, day); // Miesiące są indeksowane od 0
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calendar Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Tworzenie kalendarza
    GtkWidget *calendar = gtk_calendar_new();

    // Podłączenie sygnału do kalendarza (zmiana daty)
    g_signal_connect(calendar, "day-selected", G_CALLBACK(on_date_changed), NULL);

    // Dodanie kalendarza do okna
    gtk_container_add(GTK_CONTAINER(window), calendar);

    // Wyświetlanie widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału do zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Omówienie kodu

1. **Tworzenie GtkCalendar**:
   - `gtk_calendar_new()` tworzy nowy widżet kalendarza, który będzie wyświetlany w oknie.

2. **Podłączenie sygnału**:
   - `g_signal_connect(calendar, "day-selected", G_CALLBACK(on_date_changed), NULL)` sprawia, że funkcja `on_date_changed()` zostanie wywołana przy każdorazowym wyborze dnia.

3. **Pobieranie daty**:
   - W funkcji `on_date_changed()` za pomocą `gtk_calendar_get_date()` pobieramy aktualnie wybraną datę.

4. **Wyświetlanie daty**:
   - `g_print("Wybrana data: %04d-%02d-%02d\n", year, month + 1, day)` wyświetla wybraną datę w terminalu, dodając 1 do miesiąca, ponieważ miesiące są indeksowane od 0.

### Dodatkowe funkcje dla **GtkCalendar**

- **`gtk_calendar_select_month(gint month, gint year)`**: Ustawia widok kalendarza na określony miesiąc i rok.
- **`gtk_calendar_mark_day(guint day)`**: Zaznacza konkretny dzień w kalendarzu.
- **`gtk_calendar_unmark_day(guint day)`**: Usuwa zaznaczenie dnia w kalendarzu.
- **`gtk_calendar_clear_marks()`**: Czyści wszystkie zaznaczone dni.

Widżet **GtkCalendar** jest użyteczny w aplikacjach, które wymagają wyboru dat, takich jak aplikacje do planowania, rezerwacji lub zarządzania czasem, zapewniając użytkownikom intuicyjny interfejs do pracy z datami.
