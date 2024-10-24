# GTK+ SpinButton

**GtkSpinButton** w GTK+ to widżet, który umożliwia użytkownikowi wybór wartości liczbowej z określonego zakresu poprzez klikanie strzałek w górę i w dół lub ręczne wpisanie wartości.

### Kluczowe właściwości **GtkSpinButton**:
- **Zakres wartości**: Określasz minimalną i maksymalną wartość.
- **Krok**: Ustawiasz, o ile ma się zwiększać lub zmniejszać wartość przy użyciu strzałek.
- **Liczby zmiennoprzecinkowe**: Możesz ustawić dokładność (liczbę cyfr po przecinku).

### Kluczowe funkcje:
- `gtk_spin_button_new_with_range()`: Tworzy nowy `GtkSpinButton` z zakresem wartości.
- `gtk_spin_button_get_value()`: Pobiera bieżącą wartość spinbuttona.
- `gtk_spin_button_set_value()`: Ustawia wartość spinbuttona.

### Przykład

```c
#include <gtk/gtk.h>

// Funkcja wywoływana po zmianie wartości w spinbuttonie
void on_value_changed(GtkSpinButton *spin_button, gpointer user_data) {
    gdouble value = gtk_spin_button_get_value(spin_button); // Pobiera wartość
    g_print("Nowa wartość: %.2f\n", value);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "SpinButton Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // Tworzenie spinbuttona z zakresem od 0 do 100 i krokiem 1
    GtkWidget *spin_button = gtk_spin_button_new_with_range(0, 100, 1);

    // Ustawienie dokładności na 2 miejsca po przecinku
    gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_button), 2);

    // Podłączenie sygnału do spinbuttona (zmiana wartości)
    g_signal_connect(spin_button, "value-changed", G_CALLBACK(on_value_changed), NULL);

    // Dodanie spinbuttona do okna
    gtk_container_add(GTK_CONTAINER(window), spin_button);

    // Wyświetlanie widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału do zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Omówienie kodu

1. **Tworzenie SpinButtona**:
   - `gtk_spin_button_new_with_range(0, 100, 1)` tworzy spinbutton z zakresem od 0 do 100 i krokiem co 1 jednostkę. Wartość będzie zwiększana/zmniejszana o 1 przy każdym kliknięciu strzałki.
   
2. **Podłączenie sygnału**:
   - `g_signal_connect(spin_button, "value-changed", G_CALLBACK(on_value_changed), NULL)` sprawia, że funkcja `on_value_changed()` zostanie wywołana przy każdej zmianie wartości.

3. **Pobieranie wartości**:
   - W `on_value_changed()` za pomocą `gtk_spin_button_get_value()` pobieramy bieżącą wartość widżetu.

4. **Wyświetlanie wartości**:
   - `g_print("Nowa wartość: %.2f\n", value)` wyświetla bieżącą wartość w terminalu z dokładnością do dwóch miejsc po przecinku.

### Dodatkowe funkcje dla **GtkSpinButton**

- **`gtk_spin_button_set_value(GtkSpinButton *spin_button, gdouble value)`**: Ustawia wartość spinbuttona.
- **`gtk_spin_button_get_value_as_int(GtkSpinButton *spin_button)`**: Pobiera wartość jako liczbę całkowitą.
- **`gtk_spin_button_set_digits(GtkSpinButton *spin_button, guint digits)`**: Ustawia liczbę miejsc po przecinku.
- **`gtk_spin_button_set_increments(GtkSpinButton *spin_button, gdouble step, gdouble page)`**: Ustawia krok zmiany wartości (po kliknięciu strzałki lub przewijaniu).

Spinbutton to użyteczny widżet, gdy użytkownik ma wybrać wartość liczbową w określonym przedziale, np. wybór ilości sztuk towaru, ustawianie parametrów liczbowych w aplikacji itp.
