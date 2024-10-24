#GTK+ Switch

W GTK+ możesz używać widżetu **GtkSwitch**, który reprezentuje typowy przełącznik dwustanowy, podobny do tych stosowanych w interfejsach mobilnych, np. włączanie/wyłączanie ustawienia.

### Kluczowe elementy

- **Tworzenie przełącznika**: Używamy `gtk_switch_new()` do utworzenia przełącznika.
- **Reagowanie na zmianę stanu**: Używamy sygnału `state-set`, który reaguje, gdy przełącznik zmieni stan.
- **Sprawdzanie stanu**: Można uzyskać bieżący stan przełącznika za pomocą `gtk_switch_get_active()`.

### Przykład

```c
#include <gtk/gtk.h>

// Funkcja wywoływana po zmianie stanu przełącznika
gboolean on_switch_state_set(GtkSwitch *switch_widget, gboolean state, gpointer user_data) {
    if (state) {
        g_print("Switch: Włączony\n");
    } else {
        g_print("Switch: Wyłączony\n");
    }
    // Zwracamy FALSE, aby GTK mogło ustawić stan przełącznika
    return FALSE;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Przełącznik (Switch)");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // Tworzenie przełącznika (switch)
    GtkWidget *switch_widget = gtk_switch_new();

    // Podłączanie sygnału do przełącznika
    g_signal_connect(switch_widget, "state-set", G_CALLBACK(on_switch_state_set), NULL);

    // Dodanie przełącznika do okna
    gtk_container_add(GTK_CONTAINER(window), switch_widget);

    // Wyświetlanie wszystkich widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału do zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Omówienie kodu

1. **Tworzenie przełącznika (switch)**:
   - `gtk_switch_new()` tworzy przełącznik, który można ręcznie włączać i wyłączać.

2. **Obsługa sygnału `state-set`**:
   - Funkcja `on_switch_state_set()` reaguje na zmianę stanu przełącznika.
   - Argument `state` to nowy stan przełącznika (TRUE = włączony, FALSE = wyłączony).
   - `g_print()` wyświetla odpowiedni komunikat w konsoli, informujący o stanie przełącznika.

3. **Podłączenie sygnału**:
   - `g_signal_connect(switch_widget, "state-set", G_CALLBACK(on_switch_state_set), NULL)` ustawia reakcję na zmianę stanu.

4. **Zwracanie FALSE w callbacku**:
   - `return FALSE` pozwala GTK+ kontynuować zmianę stanu przełącznika, czyli faktycznie go przełączyć. Gdybyśmy zwrócili TRUE, przełącznik nie zmieniłby swojego stanu.

### Funkcje przydatne dla `GtkSwitch`

- **`gtk_switch_get_active(GtkSwitch *switch)`**: Zwraca, czy przełącznik jest włączony (TRUE) czy wyłączony (FALSE).
- **`gtk_switch_set_active(GtkSwitch *switch, gboolean is_active)`**: Ustawia stan przełącznika ręcznie.

Przełącznik typu switch świetnie nadaje się do zastosowań związanych z włączaniem/wyłączaniem opcji w aplikacjach, np. tryb ciemny, włączanie powiadomień, itp.
