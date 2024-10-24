# GTK+ AboutDialog

**GtkAboutDialog** w GTK+ to specjalny typ dialogu używanego do wyświetlania informacji o aplikacji, takich jak jej nazwa, wersja, autorzy oraz inne szczegóły. Jest to przydatny sposób na udostępnienie użytkownikom informacji o programie oraz prawach autorskich.

### Kluczowe właściwości **GtkAboutDialog**:
- **Informacje o aplikacji**: Możliwość ustawienia nazwy, wersji i opisu aplikacji.
- **Autorzy**: Umożliwia dodanie listy autorów, co jest istotne dla uznania ich wkładu.
- **Linki**: Możliwość dodania linków do strony internetowej lub repozytoriów.

### Kluczowe funkcje:
- `gtk_about_dialog_new()`: Tworzy nowy dialog informacyjny.
- `gtk_about_dialog_set_program_name()`: Ustawia nazwę programu.
- `gtk_about_dialog_set_version()`: Ustawia wersję programu.

### Przykład

```c
#include <gtk/gtk.h>

// Funkcja wywoływana po kliknięciu przycisku "O programie"
void on_about_button_clicked(GtkWidget *widget, gpointer user_data) {
    // Tworzenie nowego dialogu "O programie"
    GtkWidget *about_dialog = gtk_about_dialog_new();

    // Ustawienie właściwości dialogu
    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(about_dialog), "Przykładowa Aplikacja");
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(about_dialog), "1.0");
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(about_dialog), "To jest przykładowa aplikacja do demonstrowania działania GtkAboutDialog.");
    gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(about_dialog), (const char *[]){"Jan Kowalski", "Anna Nowak", NULL});
    gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(about_dialog), "https://example.com");

    // Wyświetlenie dialogu
    gtk_dialog_run(GTK_DIALOG(about_dialog));

    // Zniszczenie dialogu po zamknięciu
    gtk_widget_destroy(about_dialog);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie głównego okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Przykład AboutDialog");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Tworzenie przycisku do otwierania dialogu "O programie"
    GtkWidget *about_button = gtk_button_new_with_label("O programie");
    g_signal_connect(about_button, "clicked", G_CALLBACK(on_about_button_clicked), NULL);

    // Dodanie przycisku do okna
    gtk_container_add(GTK_CONTAINER(window), about_button);

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
   - `gtk_about_dialog_new()` tworzy nowy dialog informacyjny, który wyświetli informacje o aplikacji.

2. **Ustawienie właściwości**:
   - `gtk_about_dialog_set_program_name()` ustawia nazwę programu, co jest wyświetlane na górze dialogu.
   - `gtk_about_dialog_set_version()` ustawia wersję programu, co pozwala użytkownikom na identyfikację używanej wersji.
   - `gtk_about_dialog_set_comments()` dodaje krótki opis aplikacji.
   - `gtk_about_dialog_set_authors()` ustawia listę autorów, co jest ważne dla uznania ich wkładu.
   - `gtk_about_dialog_set_website()` dodaje link do strony internetowej aplikacji.

3. **Wyświetlenie dialogu**:
   - `gtk_dialog_run(GTK_DIALOG(about_dialog))` uruchamia dialog i czeka na interakcję użytkownika.

4. **Zamknięcie dialogu**:
   - `gtk_widget_destroy(about_dialog)` zamyka dialog po jego zamknięciu przez użytkownika.

### Dodatkowe funkcje dla **GtkAboutDialog**

- **`gtk_about_dialog_set_logo(GtkAboutDialog *dialog, GdkPixbuf *logo)`**: Ustawia logo aplikacji, które będzie wyświetlane w dialogu.
- **`gtk_about_dialog_set_license(GtkAboutDialog *dialog, const char *license)`**: Ustawia informacje o licencji aplikacji.

**GtkAboutDialog** to przydatny komponent w aplikacjach GTK+, pozwalający na łatwe udostępnienie informacji o programie użytkownikom. Dzięki niemu użytkownicy mogą szybko uzyskać dostęp do ważnych informacji, takich jak wersja, autorzy czy linki do dalszych zasobów.
