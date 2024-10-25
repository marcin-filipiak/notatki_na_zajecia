# GTK+ TextView

**GtkTextView** w GTK+ to widżet służący do wyświetlania oraz edytowania tekstu wielolinijkowego. Jest szczególnie użyteczny, gdy aplikacja wymaga dużego obszaru tekstowego, np. do edycji notatek, opisu, lub dowolnych wielolinijkowych danych wejściowych.

### Kluczowe właściwości **GtkTextView**:
- **Obsługa wielu linii**: Widżet pozwala użytkownikowi na wprowadzanie tekstu w wielu liniach.
- **Skalowanie i przesuwanie**: Obsługuje paski przewijania, co jest wygodne przy pracy z większymi blokami tekstu.
- **Formatowanie tekstu**: Możliwość formatowania poszczególnych fragmentów tekstu, jak np. pogrubienie, kursywa, kolor.

### Kluczowe funkcje:
- `gtk_text_view_new()`: Tworzy nowy obiekt `GtkTextView`.
- `gtk_text_buffer_set_text()`: Ustawia tekst w buforze tekstowym `GtkTextView`.
- `gtk_text_buffer_get_text()`: Pobiera tekst z bufora `GtkTextView`.

### Przykład

```c
#include <gtk/gtk.h>

// Funkcja wywoływana po kliknięciu przycisku "Pobierz tekst"
void on_button_clicked(GtkButton *button, GtkTextView *text_view) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(text_view); // Pobiera bufor tekstu
    GtkTextIter start, end;

    // Pobiera cały tekst z bufora
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);
    gchar *text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    g_print("Tekst z TextView: %s\n", text);
    g_free(text);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Przykład TextView");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Tworzenie TextView i TextBuffer
    GtkWidget *text_view = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(buffer, "Wprowadź tekst tutaj...", -1);

    // Tworzenie przycisku
    GtkWidget *button = gtk_button_new_with_label("Pobierz tekst");

    // Podłączenie sygnału do przycisku
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), text_view);

    // Układ widżetów w kontenerze
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(box), text_view, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Wyświetlanie widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału do zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Omówienie kodu

1. **Tworzenie TextView**:
   - `gtk_text_view_new()` tworzy nowy widżet TextView. Tworzymy `GtkTextBuffer` za pomocą `gtk_text_view_get_buffer()`, co pozwala na ustawianie lub pobieranie tekstu.

2. **Ustawienie tekstu w buforze**:
   - `gtk_text_buffer_set_text(buffer, "Wprowadź tekst tutaj...", -1)` ustawia początkowy tekst widoczny w TextView.

3. **Pobieranie tekstu z bufora**:
   - `gtk_text_buffer_get_text(buffer, &start, &end, FALSE)` pobiera tekst z bufora między początkowym a końcowym indeksem, który jest wyświetlany w terminalu po kliknięciu przycisku.

4. **Wyświetlanie wartości**:
   - `g_print("Tekst z TextView: %s\n", text)` wyświetla zawartość tekstową w terminalu.

### Dodatkowe funkcje dla **GtkTextView**

- **`gtk_text_view_set_wrap_mode(GtkTextView *text_view, GtkWrapMode wrap_mode)`**: Ustawia sposób zawijania tekstu (np. zawijanie słów lub znaków).
- **`gtk_text_view_set_editable(GtkTextView *text_view, gboolean editable)`**: Określa, czy użytkownik może edytować tekst.
- **`gtk_text_view_set_cursor_visible(GtkTextView *text_view, gboolean visible)`**: Określa, czy kursor powinien być widoczny.

**GtkTextView** jest elastycznym widżetem przeznaczonym do wyświetlania i edycji tekstu wielolinijkowego, który doskonale sprawdza się w edytorach tekstu i polach komentarzy.
