# GTK+ Image

**GtkImage** w GTK+ to widżet używany do wyświetlania obrazów w aplikacjach. Może wyświetlać obrazy z plików, pixbuf (struktura danych dla obrazów w pamięci) lub innych źródeł. Jest to prosty sposób na dodanie grafiki do interfejsu użytkownika.

### Kluczowe właściwości **GtkImage**:
- **Źródło obrazu**: Obraz może pochodzić z pliku, zasobu lub pixbufa.
- **Skalowanie**: Domyślnie obraz jest wyświetlany w swoim oryginalnym rozmiarze, ale można go skalować, aby dopasować do innych wymiarów.
- **Dynamiczna zmiana obrazu**: Możesz zmieniać obraz w trakcie działania aplikacji.

### Kluczowe funkcje:
- `gtk_image_new_from_file()`: Tworzy nowy widżet `GtkImage` z obrazem załadowanym z pliku.
- `gtk_image_set_from_file()`: Ustawia nowy obraz z pliku dla istniejącego widżetu `GtkImage`.
- `gtk_image_clear()`: Czyści widżet, usuwając obraz.

### Przykład

```c
#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Image Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);

    // Tworzenie obrazu z pliku
    GtkWidget *image = gtk_image_new_from_file("image.png");

    // Dodanie obrazu do okna
    gtk_container_add(GTK_CONTAINER(window), image);

    // Wyświetlanie widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału do zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Omówienie kodu

1. **Tworzenie GtkImage**:
   - `gtk_image_new_from_file("image.png")` tworzy widżet `GtkImage`, który wyświetla obraz załadowany z pliku `image.png`.

2. **Dodanie obrazu do kontenera**:
   - Obraz jest dodawany do okna za pomocą `gtk_container_add(GTK_CONTAINER(window), image)`.

3. **Wyświetlanie okna**:
   - Funkcja `gtk_widget_show_all(window)` wyświetla okno wraz z jego zawartością, w tym widżetem `GtkImage`.

### Dodatkowe funkcje dla **GtkImage**

- **`gtk_image_new_from_pixbuf(GdkPixbuf *pixbuf)`**: Tworzy obraz z pixbuf (struktura obrazów w pamięci).
- **`gtk_image_set_from_pixbuf(GtkImage *image, GdkPixbuf *pixbuf)`**: Zmienia obraz dla istniejącego widżetu na obraz z pixbuf.
- **`gtk_image_set_from_file(GtkImage *image, const gchar *filename)`**: Zmienia obraz dla istniejącego widżetu, ładując obraz z pliku.
- **`gtk_image_clear(GtkImage *image)`**: Usuwa obraz z widżetu `GtkImage`.

### Skalowanie i przekształcanie obrazów
Aby zmienić rozmiar obrazu, musisz użyć pixbuf. Przykład skalowania obrazu:

```c
GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("image.png", NULL);
GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 100, 100, GDK_INTERP_BILINEAR);
gtk_image_set_from_pixbuf(GTK_IMAGE(image), scaled_pixbuf);
```

Widżet **GtkImage** jest prostym i efektywnym sposobem na wyświetlanie grafiki w aplikacjach, np. logo, ikon czy ilustracji. Można go dynamicznie zmieniać, co czyni go elastycznym narzędziem do pracy z obrazami.
