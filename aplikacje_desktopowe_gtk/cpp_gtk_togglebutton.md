# GTK+ Switch (toggle button)

Oto przykład użycia przycisku dwustanowego (tzw. switch lub toggle button) w GTK+. Taki przycisk może być używany do przełączania między dwoma stanami (np. włączony/wyłączony), 
a użytkownik może zobaczyć, jaki stan jest aktywny.

### Kluczowe elementy:

- **Tworzenie przełącznika**: Używamy `gtk_toggle_button_new_with_label()` do stworzenia przełącznika.
- **Reagowanie na zmianę stanu**: Sygnał `toggled` jest wywoływany, gdy stan przycisku się zmieni.
- **Sprawdzenie stanu**: Za pomocą `gtk_toggle_button_get_active()` możemy sprawdzić, czy przycisk jest włączony (TRUE) lub wyłączony (FALSE).

### Przykład:

```c
#include <gtk/gtk.h>

// Funkcja wywoływana po naciśnięciu przycisku
void on_toggle_button_toggled(GtkToggleButton *toggle_button, gpointer user_data) {
    if (gtk_toggle_button_get_active(toggle_button)) {
        // Jeśli przycisk jest włączony (stan wciśnięty)
        g_print("Przycisk: Włączony\n");
        gtk_button_set_label(GTK_BUTTON(toggle_button), "Włączony");
    } else {
        // Jeśli przycisk jest wyłączony (stan niewciśnięty)
        g_print("Przycisk: Wyłączony\n");
        gtk_button_set_label(GTK_BUTTON(toggle_button), "Wyłączony");
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Przycisk dwustanowy");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // Tworzenie przełącznika (toggle button)
    GtkWidget *toggle_button = gtk_toggle_button_new_with_label("Wyłączony");

    // Podłączanie sygnału, który będzie wywoływany po zmianie stanu przycisku
    g_signal_connect(toggle_button, "toggled", G_CALLBACK(on_toggle_button_toggled), NULL);

    // Dodanie przełącznika do okna
    gtk_container_add(GTK_CONTAINER(window), toggle_button);

    // Wyświetlanie wszystkich widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału do zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Omówienie kodu

1. **Tworzenie Toggle Button**:
   - `gtk_toggle_button_new_with_label("Wyłączony")` tworzy przycisk, który początkowo ma etykietę "Wyłączony".

2. **Obsługa sygnału `toggled`**:
   - Funkcja `on_toggle_button_toggled()` jest wywoływana za każdym razem, gdy przycisk zmienia swój stan (czyli gdy użytkownik go kliknie).
   - `gtk_toggle_button_get_active()` sprawdza, czy przycisk jest aktywny (czyli wciśnięty). W zależności od tego, ustawiamy etykietę "Włączony" lub "Wyłączony" oraz wyświetlamy odpowiednią informację w konsoli.

3. **Uruchomienie**:
   - Aplikacja tworzy okno z przyciskiem dwustanowym, a kliknięcia użytkownika zmieniają tekst przycisku i stan.

### Funkcje przydatne przy przyciskach dwustanowych:

- **`gtk_toggle_button_get_active(GtkToggleButton *toggle_button)`**: Sprawdza, czy przycisk jest aktywny (TRUE) czy nieaktywny (FALSE).
- **`gtk_button_set_label(GtkButton *button, const gchar *label)`**: Zmienia etykietę przycisku.
- **`gtk_widget_set_sensitive(GtkWidget *widget, gboolean sensitive)`**: Możemy wyłączyć przełącznik (aby był nieaktywny) za pomocą tej funkcji.

Przycisk dwustanowy jest bardzo przydatny w sytuacjach, gdzie chcemy, aby użytkownik włączał lub wyłączał funkcję aplikacji, np. tryb nocny, pauza/odtwarzanie itp.
