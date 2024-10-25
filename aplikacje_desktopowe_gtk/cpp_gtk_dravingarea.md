# GTK+ DrawingArea

**GtkDrawingArea** to wszechstronny widżet w GTK+, który umożliwia rysowanie niestandardowej grafiki, takiej jak wykresy, kształty geometryczne (np. linie i okręgi), rysunki czy inne elementy wizualne generowane przez użytkownika. Jest często używany do dynamicznego rysowania grafiki, co pozwala na budowanie interaktywnych aplikacji wizualnych.

### Kluczowe właściwości **GtkDrawingArea**:
- **Powierzchnia rysowania**: Udostępnia obszar, na którym można rysować za pomocą narzędzi graficznych, takich jak Cairo.
- **Dynamiczna aktualizacja**: Obsługuje sygnały rysowania (`draw`), co pozwala na szybkie odświeżanie rysunku w odpowiedzi na zmiany danych.
- **Integracja z Cairo**: Ścisła współpraca z biblioteką Cairo umożliwia łatwe tworzenie kształtów, linii i innych elementów graficznych.

### Kluczowe funkcje:
- `gtk_drawing_area_new()`: Tworzy nowy obiekt `GtkDrawingArea`.
- `g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw), NULL)`: Podłącza funkcję rysującą do sygnału, która będzie wywoływana podczas rysowania widżetu.
- `gtk_widget_queue_draw()`: Wywołuje ponowne rysowanie widżetu, np. po zmianie danych do odświeżenia grafiki.

### Przykład

W tym przykładzie `GtkDrawingArea` jest używane do rysowania linii i okręgu.

```c
#include <gtk/gtk.h>

// Funkcja rysująca na obszarze DrawingArea
gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer data) {
    int width = gtk_widget_get_allocated_width(widget);
    int height = gtk_widget_get_allocated_height(widget);

    // Ustawienie koloru
    cairo_set_source_rgb(cr, 0.2, 0.5, 0.7);

    // Rysowanie linii przekątnej
    cairo_set_line_width(cr, 2);
    cairo_move_to(cr, 0, 0);
    cairo_line_to(cr, width, height);
    cairo_stroke(cr);

    // Rysowanie okręgu
    cairo_arc(cr, width / 2, height / 2, height / 4, 0, 2 * M_PI);
    cairo_stroke(cr);

    return FALSE;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Drawing Lines and Circles");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    // Tworzenie DrawingArea i podłączenie funkcji rysującej
    GtkWidget *drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 400, 400);
    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw), NULL);

    // Dodanie DrawingArea do okna
    gtk_container_add(GTK_CONTAINER(window), drawing_area);

    // Wyświetlanie widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Omówienie kodu

1. **Tworzenie DrawingArea**:
   - `gtk_drawing_area_new()` tworzy nowy obiekt `GtkDrawingArea`, który posłuży jako powierzchnia do rysowania linii i okręgu.

2. **Funkcja rysująca**:
   - `on_draw()` to funkcja rysująca, która zostanie wywołana przy każdym rysowaniu widżetu i wykorzystuje Cairo do rysowania linii oraz okręgu.

3. **Rysowanie linii**:
   - `cairo_move_to(cr, 0, 0); cairo_line_to(cr, width, height);` rysuje linię przekątnej od lewego górnego do prawego dolnego rogu.

4. **Rysowanie okręgu**:
   - `cairo_arc(cr, width / 2, height / 2, height / 4, 0, 2 * M_PI);` rysuje okrąg o środku w środku obszaru rysowania i promieniu równym jednej czwartej wysokości widżetu.

### Dodatkowe funkcje dla **GtkDrawingArea** do rysowania kształtów

- **Rysowanie linii**:
  - **`cairo_move_to(cairo_t *cr, double x, double y)`**: Ustawia punkt początkowy linii.
  - **`cairo_line_to(cairo_t *cr, double x, double y)`**: Rysuje linię od bieżącego punktu do podanych współrzędnych `(x, y)`.
  - **`cairo_stroke(cairo_t *cr)`**: Wykańcza i wyświetla linie, które zostały narysowane.

- **Rysowanie okręgu**:
  - **`cairo_arc(cairo_t *cr, double xc, double yc, double radius, double angle1, double angle2)`**: Rysuje łuk (część okręgu) od `angle1` do `angle2`. Aby narysować pełen okrąg, użyj zakresu kątów od `0` do `2 * M_PI`.
  - **`cairo_fill(cairo_t *cr)`**: Wypełnia obszar w okręgu kolorem.
  - **`cairo_stroke(cr)`**: Wykańcza obrys okręgu bez wypełniania.

**GtkDrawingArea** jest elastycznym widżetem do tworzenia różnorodnych kształtów, rysunków i grafiki, umożliwiając tworzenie prostych i zaawansowanych elementów wizualnych w aplikacjach GTK+.
