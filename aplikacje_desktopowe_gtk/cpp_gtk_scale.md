# GTK+ Scale

**GtkScale** w GTK+ to widżet umożliwiający użytkownikowi wybór wartości liczbowej z określonego zakresu poprzez przesuwanie wskaźnika (suwa). Jest to wygodny sposób na wprowadzanie wartości w aplikacjach, które wymagają precyzyjnego ustawienia parametrów, takich jak głośność, jasność itp.

### Kluczowe właściwości **GtkScale**:
- **Zakres wartości**: Możliwość określenia minimalnej i maksymalnej wartości suwaka.
- **Krok**: Umożliwia ustawienie kroków, o które wartość ma być zmieniana przy przesuwaniu.
- **Orientacja**: Możliwość ustawienia suwaka w orientacji poziomej lub pionowej.

### Kluczowe funkcje:
- `gtk_scale_new_with_range()`: Tworzy nowy `GtkScale` z określonym zakresem wartości.
- `gtk_scale_get_value()`: Pobiera bieżącą wartość suwaka.
- `gtk_scale_set_value_pos()`: Ustawia pozycję wyświetlanej wartości.

### Przykład

```c
#include <gtk/gtk.h>

// Funkcja wywoływana po zmianie wartości w suwaku
void on_scale_value_changed(GtkScale *scale, gpointer user_data) {
    gdouble value = gtk_scale_get_value(scale); // Pobiera bieżącą wartość suwaka
    g_print("Nowa wartość suwaka: %.2f\n", value);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie głównego okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Przykład Scale");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 100);

    // Tworzenie suwaka z zakresem od 0 do 100
    GtkWidget *scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);

    // Podłączenie sygnału do suwaka (zmiana wartości)
    g_signal_connect(scale, "value-changed", G_CALLBACK(on_scale_value_changed), NULL);

    // Dodanie suwaka do okna
    gtk_container_add(GTK_CONTAINER(window), scale);

    // Wyświetlanie widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału do zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Omówienie kodu

1. **Tworzenie suwaka**:
   - `gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1)` tworzy suwak z zakresem wartości od 0 do 100, z krokiem co 1 jednostkę. Suwak będzie ustawiony w orientacji poziomej.

2. **Podłączenie sygnału**:
   - `g_signal_connect(scale, "value-changed", G_CALLBACK(on_scale_value_changed), NULL)` sprawia, że funkcja `on_scale_value_changed()` zostanie wywołana przy każdej zmianie wartości suwaka.

3. **Pobieranie wartości**:
   - W `on_scale_value_changed()` za pomocą `gtk_scale_get_value()` pobieramy bieżącą wartość suwaka.

4. **Wyświetlanie wartości**:
   - `g_print("Nowa wartość suwaka: %.2f\n", value)` wyświetla bieżącą wartość w terminalu z dokładnością do dwóch miejsc po przecinku.

### Dodatkowe funkcje dla **GtkScale**

- **`gtk_scale_set_value_pos(GtkScale *scale, GtkPositionType pos)`**: Ustawia pozycję wyświetlanej wartości (np. nad lub pod suwakiem).
- **`gtk_scale_set_digits(GtkScale *scale, guint digits)`**: Ustawia liczbę miejsc po przecinku dla wyświetlanej wartości.
- **`gtk_scale_set_draw_value(GtkScale *scale, gboolean draw_value)`**: Określa, czy wartość ma być wyświetlana na suwaku.

**GtkScale** to wszechstronny widżet, który pozwala użytkownikom na intuicyjne ustawianie wartości w aplikacjach GTK+. Dzięki różnym możliwościom konfiguracyjnym, suwak może być łatwo dostosowany do potrzeb aplikacji, co sprawia, że jest to często stosowany komponent interfejsu użytkownika.
