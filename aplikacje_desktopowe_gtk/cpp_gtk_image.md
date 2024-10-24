# GTK+ Image

**GtkImage** to widżet w GTK+, który umożliwia wyświetlanie obrazów. Jest to jeden z podstawowych elementów GUI, używany do wyświetlania plików graficznych, ikon lub innych obrazów.

### Kluczowe funkcje **GtkImage**
- **gtk_image_new()**: Tworzy nowy obiekt typu GtkImage.
- **gtk_image_new_from_file()**: Tworzy obraz z pliku.
- **gtk_image_set_from_file()**: Ustawia obraz z podanego pliku.
- **gtk_image_set_from_pixbuf()**: Ustawia obraz z obiektu `GdkPixbuf`, który może przechowywać dane obrazu.

### Przykład

```c
#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Image Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Tworzenie nowego obiektu GtkImage z pliku
    GtkWidget *image = gtk_image_new_from_file("path/to/your/image.png");

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
1. **Tworzenie GtkImage z pliku**:
   - `gtk_image_new_from_file("path/to/your/image.png")` ładuje obraz z podanego pliku. Obraz musi znajdować się w podanej ścieżce, inaczej nie zostanie załadowany.
   
2. **Dodanie do okna**:
   - `gtk_container_add(GTK_CONTAINER(window), image)` dodaje obraz do kontenera (w tym przypadku do okna).

### Przydatne funkcje

- **`gtk_image_set_from_file(GtkImage *image, const gchar *filename)`**: Ustawia nowy obraz z pliku, dzięki czemu można dynamicznie zmieniać obraz w trakcie działania programu.
- **`gtk_image_new_from_icon_name(const gchar *icon_name, GtkIconSize size)`**: Tworzy obraz na podstawie nazwy ikony (jeśli korzystasz z ikonek systemowych).
- **`gtk_image_clear(GtkImage *image)`**: Czyści obraz, usuwając wyświetlany obraz z GtkImage.

### Przykład zmiany obrazu dynamicznie

```c
#include <gtk/gtk.h>

// Funkcja wywoływana przy kliknięciu przycisku
void on_button_clicked(GtkButton *button, GtkImage *image) {
    // Zmiana obrazu na inny po kliknięciu
    gtk_image_set_from_file(image, "path/to/another/image.png");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Dynamic Image Change");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Tworzenie kontenera
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // Tworzenie obiektu GtkImage z pliku
    GtkWidget *image = gtk_image_new_from_file("path/to/your/image.png");

    // Tworzenie przycisku
    GtkWidget *button = gtk_button_new_with_label("Change Image");

    // Podłączenie sygnału do przycisku
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), image);

    // Dodanie widżetów do kontenera
    gtk_box_pack_start(GTK_BOX(box), image, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);

    // Dodanie kontenera do okna
    gtk_container_add(GTK_CONTAINER(window), box);

    // Wyświetlanie widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału do zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Wyjaśnienie
1. **Dynamiczna zmiana obrazu**: 
   - `gtk_image_set_from_file()` w funkcji `on_button_clicked()` zmienia obraz na inny po kliknięciu przycisku.
   
2. **Interakcja z przyciskiem**:
   - `g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), image)` łączy kliknięcie przycisku z funkcją, która zmienia obraz w widżecie `GtkImage`.
