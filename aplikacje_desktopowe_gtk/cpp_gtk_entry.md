# GTK+ Entry

**GtkEntry** w GTK+ to widżet umożliwiający użytkownikowi wpisanie i edytowanie pojedynczej linii tekstu. Jest powszechnie używany w formularzach do wprowadzania danych, takich jak hasła, adresy e-mail, nazwy użytkowników czy inne krótkie teksty.

### Kluczowe właściwości **GtkEntry**:
- **Tekst**: Użytkownik może wpisywać i edytować tekst.
- **Maskowanie tekstu**: Przydatne do wprowadzania poufnych danych, takich jak hasła.
- **Długość**: Można ustawić maksymalną długość wprowadzanego tekstu.

### Kluczowe funkcje:
- `gtk_entry_new()`: Tworzy nowy widżet `GtkEntry`.
- `gtk_entry_set_text()`: Ustawia tekst w polu tekstowym.
- `gtk_entry_get_text()`: Pobiera bieżący tekst z pola tekstowego.
- `gtk_entry_set_visibility()`: Ustawia, czy tekst ma być widoczny (przydatne np. dla pól haseł).

### Przykład

```c
#include <gtk/gtk.h>

// Funkcja wywoływana po kliknięciu przycisku
void on_button_clicked(GtkWidget *button, gpointer entry) {
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry)); // Pobiera tekst z entry
    g_print("Wpisany tekst: %s\n", text); // Wyświetla tekst
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Tworzenie okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Entry Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Tworzenie kontenera typu box
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Tworzenie entry (pola tekstowego)
    GtkWidget *entry = gtk_entry_new();

    // Tworzenie przycisku
    GtkWidget *button = gtk_button_new_with_label("Pobierz tekst");

    // Podłączenie sygnału kliknięcia do przycisku
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), entry);

    // Dodanie entry i przycisku do okna
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);

    // Wyświetlanie widżetów
    gtk_widget_show_all(window);

    // Podłączenie sygnału do zamknięcia okna
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

### Omówienie kodu

1. **Tworzenie entry**:
   - `gtk_entry_new()` tworzy pole tekstowe, które pozwala użytkownikowi wprowadzać i edytować tekst.

2. **Podłączenie sygnału**:
   - `g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), entry)` łączy sygnał "clicked" przycisku z funkcją, która pobiera tekst z pola tekstowego po kliknięciu.

3. **Pobieranie tekstu**:
   - Funkcja `gtk_entry_get_text()` zwraca tekst wpisany przez użytkownika, który jest następnie wyświetlany w terminalu.

### Dodatkowe funkcje dla **GtkEntry**

- **`gtk_entry_set_text(GtkEntry *entry, const gchar *text)`**: Ustawia nowy tekst w polu tekstowym.
- **`gtk_entry_get_text(GtkEntry *entry)`**: Pobiera tekst wpisany w polu tekstowym.
- **`gtk_entry_set_visibility(GtkEntry *entry, gboolean visible)`**: Ustawia, czy tekst w polu ma być widoczny (przydatne dla pól haseł, gdzie tekst ma być maskowany).
- **`gtk_entry_set_max_length(GtkEntry *entry, gint max)`**: Ustawia maksymalną liczbę znaków, które można wpisać do pola tekstowego.
- **`gtk_entry_set_placeholder_text(GtkEntry *entry, const gchar *text)`**: Ustawia tekst zastępczy (np. podpowiedź w polu tekstowym, zanim użytkownik zacznie pisać).

**GtkEntry** to prosty, ale bardzo wszechstronny widżet umożliwiający użytkownikowi wprowadzanie danych tekstowych, często stosowany w formularzach i oknach dialogowych aplikacji.
