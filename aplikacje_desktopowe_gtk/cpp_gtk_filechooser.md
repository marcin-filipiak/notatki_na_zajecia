# GTK+ FileChooser

**GtkFileChooser** w GTK+ to widżet, który pozwala użytkownikom na wybór plików lub folderów z systemu plików. Jest to istotny element interfejsu, który umożliwia wygodne przeglądanie i wybieranie zasobów w aplikacjach.

### Kluczowe właściwości **GtkFileChooser**:
- **Wybór plików i folderów**: Umożliwia wybór zarówno plików, jak i całych folderów.
- **Widok**: Oferuje różne widoki, takie jak widok ikon, lista czy lista z informacjami o plikach.
- **Filtrowanie plików**: Możliwość definiowania filtrów, które ograniczają widoczność plików do określonych typów.

### Kluczowe funkcje:
- `gtk_file_chooser_dialog_new()`: Tworzy nowy dialog wyboru plików.
- `gtk_file_chooser_get_filename()`: Pobiera wybraną nazwę pliku z dialogu.
- `gtk_file_chooser_set_filter()`: Ustawia filtry, które ograniczają wybór plików do określonych typów.

### Przykład

```c
#include <gtk/gtk.h>

// Funkcja wywoływana po wybraniu pliku
void on_file_chosen(GtkWidget *widget, gpointer user_data) {
    GtkFileChooser *chooser = GTK_FILE_CHOOSER(widget);
    char *filename = gtk_file_chooser_get_filename(chooser); // Pobiera nazwę pliku
    g_print("Wybrany plik: %s\n", filename);
    g_free(filename); // Zwolnienie pamięci
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "FileChooser Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Tworzenie przycisku do otwierania dialogu wyboru plików
    GtkWidget *button = gtk_button_new_with_label("Wybierz plik");

    // Tworzenie filtra plików
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Pliki tekstowe (*.txt)");
    gtk_file_filter_add_pattern(filter, "*.txt");

    // Funkcja otwierająca dialog wyboru plików
    g_signal_connect(button, "clicked", G_CALLBACK(+[](GtkWidget *button, gpointer user_data) {
        GtkWidget *dialog = gtk_file_chooser_dialog_new("Wybierz plik", GTK_WINDOW(user_data),
            GTK_FILE_CHOOSER_ACTION_OPEN,
            "_Cancel", GTK_RESPONSE_CANCEL,
            "_Otwórz", GTK_RESPONSE_ACCEPT,
            NULL);
        
        // Ustawienie filtra
        gtk_file_chooser_set_filter(GTK_FILE_CHOOSER(dialog), filter);

        // Wyświetlenie dialogu
        if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
            on_file_chosen(dialog, user_data); // Wywołanie funkcji po wyborze pliku
        }
        gtk_widget_destroy(dialog); // Zniszczenie dialogu
    }), window);

    // Dodanie przycisku do okna
    gtk_container_add(GTK_CONTAINER(window), button);

    // Wyświetlanie widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału do zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Omówienie kodu

1. **Tworzenie GtkFileChooser**:
   - `gtk_file_chooser_dialog_new()` tworzy nowy dialog wyboru plików, który umożliwia użytkownikowi przeglądanie i wybieranie plików.

2. **Tworzenie filtra plików**:
   - `gtk_file_filter_new()` tworzy nowy filtr, a następnie `gtk_file_filter_set_name()` ustawia jego nazwę oraz `gtk_file_filter_add_pattern()` dodaje wzór plików do filtrowania (np. tylko pliki tekstowe).

3. **Obsługa przycisku**:
   - Gdy użytkownik kliknie przycisk, otwierany jest dialog wyboru plików, a po zaakceptowaniu wyboru wywoływana jest funkcja `on_file_chosen()`, która pobiera i wyświetla wybraną nazwę pliku.

4. **Zwolnienie pamięci**:
   - `g_free(filename)` zwalnia pamięć po pobraniu nazwy pliku.

### Dodatkowe funkcje dla **GtkFileChooser**

- **`gtk_file_chooser_set_action(GtkFileChooser *chooser, GtkFileChooserAction action)`**: Ustawia akcję dialogu (np. wybór pliku, zapisywanie pliku).
- **`gtk_file_chooser_set_current_folder(const gchar *folder)`**: Ustawia bieżący folder w dialogu.
- **`gtk_file_chooser_add_shortcut_folder(const gchar *folder)`**: Dodaje folder do skrótów w dialogu.

Widżet **GtkFileChooser** jest niezwykle przydatny w aplikacjach, które wymagają interakcji z systemem plików, ułatwiając użytkownikom wybór plików lub folderów do otwarcia, zapisania lub przetworzenia.
