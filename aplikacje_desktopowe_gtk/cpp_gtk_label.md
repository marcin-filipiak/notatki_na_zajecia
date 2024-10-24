# GTK+ Label

## Kluczowe elementy

- **Etykieta (label)** w GTK+ to podstawowy widżet służący do wyświetlania tekstu lub obrazów.
- Może być dostosowywana pod kątem stylu, wyrównania oraz obsługiwać Pango Markup do formatowania tekstu (np. pogrubienie, kursywa).
- Etykiety są zazwyczaj statyczne, ale mogą być aktualizowane dynamicznie podczas działania aplikacji.
  
## Przykład

```c
#include <gtk/gtk.h>

static void on_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Prosta etykieta GTK+");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    GtkWidget *label = gtk_label_new("To jest prosta etykieta.");

    g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);
    gtk_container_add(GTK_CONTAINER(window), label);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
```

## Omówienie kodu

1. **`gtk_init(&argc, &argv);`** – Inicjalizuje bibliotekę GTK+. Wymagana przed korzystaniem z innych funkcji GTK+.
2. **`GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);`** – Tworzy główne okno aplikacji.
3. **`gtk_window_set_title(GTK_WINDOW(window), "Prosta etykieta GTK+");`** – Ustawia tytuł okna.
4. **`GtkWidget *label = gtk_label_new("To jest prosta etykieta.");`** – Tworzy etykietę z wyświetlanym tekstem.
5. **`g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);`** – Obsługuje zamykanie okna i kończy pętlę główną.
6. **`gtk_container_add(GTK_CONTAINER(window), label);`** – Dodaje etykietę do okna.
7. **`gtk_widget_show_all(window);`** – Wyświetla okno i jego zawartość.
8. **`gtk_main();`** – Uruchamia pętlę główną obsługującą zdarzenia GUI.

## Przydatne funkcje

1. **`gtk_label_new(const gchar *str)`** – Tworzy etykietę z tekstem.
   ```c
   GtkWidget *label = gtk_label_new("Przykładowy tekst");
   ```

2. **`gtk_label_set_text(GtkLabel *label, const gchar *str)`** – Zmienia tekst etykiety.
   ```c
   gtk_label_set_text(GTK_LABEL(label), "Nowy tekst");
   ```

3. **`gtk_label_get_text(GtkLabel *label)`** – Pobiera aktualny tekst z etykiety.
   ```c
   const gchar *text = gtk_label_get_text(GTK_LABEL(label));
   ```

4. **`gtk_label_set_justify(GtkLabel *label, GtkJustification j)`** – Ustawia wyrównanie tekstu (np. lewo, prawo, środek).
   ```c
   gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
   ```

5. **`gtk_label_set_use_markup(GtkLabel *label, gboolean use_markup)`** – Umożliwia użycie Pango Markup do formatowania tekstu.
   ```c
   gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
   gtk_label_set_text(GTK_LABEL(label), "<b>Pogrubiony tekst</b>");
   ```

6. **`gtk_label_set_selectable(GtkLabel *label, gboolean selectable)`** – Pozwala użytkownikowi zaznaczać tekst w etykiecie.
   ```c
   gtk_label_set_selectable(GTK_LABEL(label), TRUE);
   ```
