# GTK+ Button

**GtkButton** w GTK+ to interaktywny widżet, który reaguje na kliknięcia użytkownika. Jest powszechnie używany do uruchamiania akcji, takich jak otwieranie okien dialogowych, wykonywanie operacji lub zamykanie aplikacji.

### Kluczowe właściwości **GtkButton**
- **Etykieta (Label)**: Przycisk może wyświetlać tekst, np. "OK", "Zapisz" itp.
- **Obraz (Image)**: Można ustawić grafikę jako zawartość przycisku zamiast tekstu.
- **Stan aktywacji**: Przycisk może być włączony lub wyłączony (nieaktywny).

### Kluczowe funkcje
- `gtk_button_new_with_label()`: Tworzy nowy przycisk z tekstem.
- `gtk_button_set_label()`: Ustawia tekst przycisku.
- `g_signal_connect()`: Łączy sygnały z funkcjami wywoławczymi.

### Przykład

```c
#include <gtk/gtk.h>

// Funkcja wywoływana po kliknięciu przycisku
void on_button_clicked(GtkWidget *button, gpointer user_data) {
    g_print("Przycisk został kliknięty!\n");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Button Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // Tworzenie przycisku z etykietą "Kliknij mnie"
    GtkWidget *button = gtk_button_new_with_label("Kliknij mnie");

    // Podłączenie sygnału kliknięcia do funkcji obsługującej
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

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

1. **Tworzenie przycisku**:
   - `gtk_button_new_with_label("Kliknij mnie")` tworzy przycisk z tekstem "Kliknij mnie", który będzie wyświetlany na jego powierzchni.

2. **Podłączenie sygnału**:
   - `g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL)` łączy sygnał "clicked" z funkcją `on_button_clicked()`, która wywołuje się po kliknięciu.

3. **Obsługa kliknięcia**:
   - Funkcja `on_button_clicked()` zawiera logikę do wykonania po kliknięciu. W tym przykładzie wyświetla komunikat "Przycisk został kliknięty!" w terminalu.

### Dodatkowe funkcje dla **GtkButton**

- **`gtk_button_set_label(GtkButton *button, const gchar *label)`**: Ustawia nową etykietę tekstową na przycisku.
- **`gtk_button_get_label(GtkButton *button)`**: Pobiera aktualną etykietę tekstową przycisku.
- **`gtk_button_new()`**: Tworzy przycisk bez etykiety, który można następnie wypełnić własnymi widżetami (np. obrazkami).
- **`gtk_button_set_image(GtkButton *button, GtkWidget *image)`**: Ustawia obraz na przycisku zamiast tekstu.
- **`gtk_widget_set_sensitive(GtkWidget *widget, gboolean sensitive)`**: Włącza lub wyłącza interakcję z przyciskiem (ustawia, czy przycisk jest aktywny).

Przycisk to podstawowy widżet interfejsu użytkownika, który pozwala na interakcję z użytkownikiem, służąc jako mechanizm uruchamiania określonych akcji w aplikacji.
