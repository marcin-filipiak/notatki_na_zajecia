
___

W GTK+ nie istnieje bezpośrednio widżet, który ogranicza wprowadzanie wyłącznie do cyfr, jednak można użyć widżetu **GtkEntry** (pole tekstowe) i zaimplementować własne ograniczenie, które pozwoli wpisywać tylko cyfry.

Aby to zrobić, można skorzystać z sygnału **"insert-text"**, który reaguje na każdą próbę wprowadzenia danych do pola tekstowego. Następnie w funkcji obsługującej ten sygnał można filtrować znaki tak, by akceptowane były tylko cyfry.

Przykład implementacji pola tekstowego przyjmującego tylko cyfry:

```c
#include <gtk/gtk.h>

// Funkcja obsługująca sygnał insert-text
static void only_digits(GtkEditable *editable, const gchar *text, gint length, gint *position, gpointer data) {
    // Sprawdzanie, czy wprowadzone znaki są cyframi
    for (gint i = 0; i < length; i++) {
        if (!g_ascii_isdigit(text[i])) {
            // Jeśli znak nie jest cyfrą, przerywamy jego wstawianie
            g_signal_stop_emission_by_name(editable, "insert-text");
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie głównego okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Pole tylko na cyfry");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 100);

    // Tworzenie pola tekstowego
    GtkWidget *entry = gtk_entry_new();

    // Podłączenie sygnału "insert-text" do funkcji only_digits
    g_signal_connect(entry, "insert-text", G_CALLBACK(only_digits), NULL);

    // Dodanie pola tekstowego do okna
    gtk_container_add(GTK_CONTAINER(window), entry);

    // Podłączenie sygnału zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Wyświetlenie wszystkich widżetów
    gtk_widget_show_all(window);

    // Uruchomienie pętli GTK+
    gtk_main();

    return 0;
}
```

#### Omówienie:
- **GtkEntry**: To podstawowe pole tekstowe, które domyślnie akceptuje wszystkie znaki.
- **Sygnał "insert-text"**: Jest emitowany, gdy użytkownik próbuje wprowadzić tekst. Używamy go, aby sprawdzić, czy wprowadzone znaki są cyframi.
- **Funkcja `only_digits`**: Przechwytuje wprowadzany tekst, a jeśli jakikolwiek znak nie jest cyfrą, przerywa jego wprowadzenie za pomocą funkcji `g_signal_stop_emission_by_name`.

Ten sposób pozwala na ograniczenie pola tekstowego wyłącznie do cyfr.
