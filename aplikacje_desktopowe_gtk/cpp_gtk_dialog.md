# GTK+ Dialog

**GtkDialog** w GTK+ to typ okna, które jest używane do wyświetlania informacji lub zbierania danych od użytkownika. Dialogi mogą być modalne (blokujące interakcję z innymi oknami aplikacji) lub niemodalne, a ich celem jest interakcja z użytkownikiem w prosty sposób.

### Kluczowe właściwości **GtkDialog**:
- **Modalność**: Możliwość ustawienia dialogu jako modalnego, co blokuje interakcję z innymi oknami.
- **Przyciski akcji**: Możliwość dodawania przycisków do okna dialogowego, co pozwala użytkownikowi na podjęcie decyzji.
- **Zawartość**: Dialogi mogą zawierać różnorodne widżety, takie jak etykiety, pola tekstowe, przyciski, itp.

### Kluczowe funkcje:
- `gtk_dialog_new()`: Tworzy nowy dialog.
- `gtk_dialog_add_button()`: Dodaje przycisk do dialogu.
- `gtk_dialog_run()`: Uruchamia dialog i oczekuje na interakcję użytkownika.

### Przykład

```c
#include <gtk/gtk.h>

// Funkcja wywoływana po kliknięciu przycisku
void on_button_clicked(GtkWidget *widget, gpointer user_data) {
    // Tworzenie nowego dialogu
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Dialog Example",
                                                    GTK_WINDOW(user_data),
                                                    GTK_DIALOG_MODAL,
                                                    "_OK", GTK_RESPONSE_OK,
                                                    "_Cancel", GTK_RESPONSE_CANCEL,
                                                    NULL);

    // Tworzenie etykiety
    GtkWidget *label = gtk_label_new("To jest przykład dialogu. Czy chcesz kontynuować?");
    
    // Dodanie etykiety do kontenera dialogu
    gtk_container_add(GTK_CONTAINER(gtk_dialog_get_content_area(GTK_DIALOG(dialog))), label);

    // Wyświetlenie widżetów w dialogu
    gtk_widget_show_all(dialog);

    // Uruchomienie dialogu i oczekiwanie na odpowiedź użytkownika
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));

    // Sprawdzenie odpowiedzi użytkownika
    if (response == GTK_RESPONSE_OK) {
        g_print("Użytkownik wybrał OK.\n");
    } else {
        g_print("Użytkownik anulował.\n");
    }

    // Zniszczenie dialogu
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie głównego okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Dialog Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Tworzenie przycisku do otwierania dialogu
    GtkWidget *button = gtk_button_new_with_label("Otwórz dialog");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), window);

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

1. **Tworzenie dialogu**:
   - `gtk_dialog_new_with_buttons("Dialog Example", GTK_WINDOW(user_data), GTK_DIALOG_MODAL, "_OK", GTK_RESPONSE_OK, "_Cancel", GTK_RESPONSE_CANCEL, NULL)` tworzy nowy modalny dialog z przyciskami "OK" i "Anuluj".

2. **Dodanie zawartości**:
   - `gtk_label_new("To jest przykład dialogu...")` tworzy etykietę, która informuje użytkownika o celu dialogu.
   - `gtk_container_add()` dodaje etykietę do głównego obszaru zawartości dialogu.

3. **Uruchomienie dialogu**:
   - `gtk_dialog_run(GTK_DIALOG(dialog))` uruchamia dialog i czeka na interakcję użytkownika. Po podjęciu decyzji przez użytkownika, wartość zwrócona przez tę funkcję wskazuje, który przycisk został kliknięty.

4. **Sprawdzenie odpowiedzi**:
   - `if (response == GTK_RESPONSE_OK)` sprawdza, czy użytkownik wybrał przycisk "OK" i wykonuje odpowiednie działania.

5. **Zamknięcie dialogu**:
   - `gtk_widget_destroy(dialog)` zamyka i niszczy dialog po zakończeniu interakcji.

### Dodatkowe funkcje dla **GtkDialog**

- **`gtk_dialog_set_default_response(GtkDialog *dialog, gint response_id)`**: Ustawia domyślną odpowiedź dla dialogu, co pozwala na szybszą interakcję (np. naciśnięcie klawisza Enter).
- **`gtk_dialog_response(GtkDialog *dialog, gint response_id)`**: Zamyka dialog z określoną odpowiedzią.

Dialogi GTK+ są niezwykle użyteczne w aplikacjach, które wymagają interakcji z użytkownikiem, takich jak potwierdzenia, wprowadzenie danych lub wyświetlanie komunikatów. Dzięki ich prostocie i elastyczności, użytkownicy mogą łatwo komunikować się z aplikacją.
