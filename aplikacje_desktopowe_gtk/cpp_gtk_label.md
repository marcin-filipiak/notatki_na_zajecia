# GTK+ Label

Etykieta (label) w GTK+ to podstawowy widżet służący do wyświetlania tekstu lub obrazów w interfejsie użytkownika. Jest używana głównie do informowania użytkownika o funkcjach innych widżetów (np. pól tekstowych) lub do prezentacji prostych komunikatów. Etykiety mogą być dostosowywane pod względem stylu, wyrównania, a także mogą obsługiwać Pango Markup, co pozwala na formatowanie tekstu (np. pogrubienie, kursywa). W GTK+ etykiety są zazwyczaj statyczne, ale mogą również być aktualizowane w czasie działania aplikacji, co czyni je elastycznym narzędziem w tworzeniu interfejsów użytkownika.

Kod aplikacji GTK+, który wyświetla tylko etykietę (label).

```c
#include <gtk/gtk.h>

// Funkcja wywoływana przy zamknięciu okna
static void on_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit(); // Kończy pętlę główną GTK+
}

int main(int argc, char *argv[]) {
    // Inicjalizacja GTK+
    gtk_init(&argc, &argv);

    // Tworzenie głównego okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Prosta etykieta GTK+");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Tworzenie etykiety
    GtkWidget *label = gtk_label_new("To jest prosta etykieta.");

    // Podłączenie sygnału z zamknięciem okna do funkcji on_destroy
    g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);

    // Dodanie etykiety do okna
    gtk_container_add(GTK_CONTAINER(window), label);

    // Wyświetlenie wszystkich widżetów
    gtk_widget_show_all(window);

    // Rozpoczęcie pętli głównej GTK+
    gtk_main();

    return 0;
}
```

### Omówienie kodu

1. **`#include <gtk/gtk.h>`**
   - Ta linia dołącza nagłówek biblioteki GTK+. Umożliwia to korzystanie ze wszystkich funkcji, typów i makr zdefiniowanych w GTK+.

2. **`static void on_destroy(GtkWidget *widget, gpointer data)`**
   - Definiuje funkcję `on_destroy`, która będzie wywoływana, gdy okno zostanie zamknięte. Funkcja przyjmuje wskaźnik do widżetu (`widget`) i wskaźnik do danych (`data`), ale w tym przypadku nie używamy tych argumentów. Używamy `static`, aby funkcja była widoczna tylko w tym pliku źródłowym.

3. **`gtk_main_quit();`**
   - Ta funkcja kończy pętlę główną GTK+. Kiedy okno jest zamykane, wywołanie tej funkcji kończy działanie aplikacji.

4. **`int main(int argc, char *argv[])`**
   - Główna funkcja programu, która jest punktem wejścia do aplikacji. `argc` to liczba argumentów wiersza poleceń, a `argv` to tablica tych argumentów.

5. **`gtk_init(&argc, &argv);`**
   - Inicjalizuje bibliotekę GTK+. Niezbędne jest to przed wywołaniem jakichkolwiek funkcji GTK. Argumenty `argc` i `argv` są przekazywane, aby GTK mogło obsługiwać argumenty wiersza poleceń, takie jak opcje związane z wyglądem.

6. **`GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);`**
   - Tworzy nowe okno główne aplikacji. `GTK_WINDOW_TOPLEVEL` oznacza, że jest to okno główne, które będzie miało ramki i przyciski systemowe.

7. **`gtk_window_set_title(GTK_WINDOW(window), "Prosta etykieta GTK+");`**
   - Ustawia tytuł okna. Tytuł ten pojawi się w pasku tytułowym okna.

8. **`gtk_container_set_border_width(GTK_CONTAINER(window), 10);`**
   - Ustawia szerokość marginesu wokół zawartości okna na 10 pikseli, co daje trochę przestrzeni wewnątrz okna.

9. **`GtkWidget *label = gtk_label_new("To jest prosta etykieta.");`**
   - Tworzy nową etykietę (label) z tekstem "To jest prosta etykieta.". Etykieta ta będzie wyświetlana w oknie.

10. **`g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);`**
    - Łączy sygnał "destroy" (związany z zamknięciem okna) z funkcją `on_destroy`. Gdy użytkownik zamknie okno, funkcja `on_destroy` zostanie wywołana.

11. **`gtk_container_add(GTK_CONTAINER(window), label);`**
    - Dodaje etykietę do kontenera (w tym przypadku do okna). W ten sposób etykieta stanie się częścią okna i będzie widoczna.

12. **`gtk_widget_show_all(window);`**
    - Wyświetla wszystkie widżety w oknie. To zapewnia, że okno oraz jego zawartość (w tym przypadku etykieta) będą widoczne na ekranie.

13. **`gtk_main();`**
    - Rozpoczyna pętlę główną GTK. Pętla ta obsługuje zdarzenia, takie jak kliknięcia myszą czy inne interakcje użytkownika. Aplikacja działa w tej pętli, aż wywołana zostanie `gtk_main_quit()`.

14. **`return 0;`**
    - Zwraca 0, co oznacza, że program zakończył się pomyślnie.
   
___

Oto kilka funkcji i możliwości, które można wykorzystać do pracy z etykietami w GTK+:

### 1. Tworzenie etykiety

- **`gtk_label_new(const gchar *str)`**
  - Tworzy nową etykietę z podanym tekstem.
  - Przykład:
    ```c
    GtkWidget *label = gtk_label_new("Tekst początkowy");
    ```

### 2. Podmiana tekstu etykiety

- **`gtk_label_set_text(GtkLabel *label, const gchar *str)`**
  - Umożliwia zmianę tekstu etykiety na nowy.
  - Przykład:
    ```c
    gtk_label_set_text(GTK_LABEL(label), "Nowy tekst");
    ```

### 3. Uzyskiwanie tekstu z etykiety

- **`const gchar *gtk_label_get_text(GtkLabel *label)`**
  - Zwraca tekst aktualnie wyświetlany w etykiecie.
  - Przykład:
    ```c
    const gchar *text = gtk_label_get_text(GTK_LABEL(label));
    ```

### 4. Ustawianie i zmiana wyrównania tekstu

- **`gtk_label_set_justify(GtkLabel *label, GtkJustification j)`**
  - Umożliwia ustawienie wyrównania tekstu w etykiecie (np. `GTK_JUSTIFY_LEFT`, `GTK_JUSTIFY_CENTER`, `GTK_JUSTIFY_RIGHT`).
  - Przykład:
    ```c
    gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
    ```

### 5. Ustawianie stylu etykiety

- **`gtk_label_set_use_markup(GtkLabel *label, gboolean use_markup)`**
  - Umożliwia włączenie obsługi Pango Markup do formatowania tekstu (np. pogrubienie, kursywa).
  - Przykład:
    ```c
    gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
    gtk_label_set_text(GTK_LABEL(label), "<b>Pogrubiony tekst</b>");
    ```

### 6. Dodawanie linków

- **`gtk_label_set_use_underline(GtkLabel *label, gboolean use_underline)`**
  - Umożliwia dodanie podkreślenia do tekstu, co może być użyteczne w przypadku linków.
  - Przykład:
    ```c
    gtk_label_set_use_underline(GTK_LABEL(label), TRUE);
    ```

### 7. Wyświetlanie obrazów

- **`gtk_label_set_image(GtkLabel *label, GdkPixbuf *pixbuf)`**
  - Umożliwia dodanie obrazu obok tekstu w etykiecie.
  - Przykład:
    ```c
    GdkPixbuf *image = gdk_pixbuf_new_from_file("path/to/image.png", NULL);
    gtk_label_set_image(GTK_LABEL(label), image);
    ```

### 8. Ustawianie tekstu z interfejsem graficznym

- **`gtk_label_set_selectable(GtkLabel *label, gboolean selectable)`**
  - Umożliwia użytkownikowi zaznaczanie tekstu etykiety.
  - Przykład:
    ```c
    gtk_label_set_selectable(GTK_LABEL(label), TRUE);
    ```

### Przykład użycia etykiety z podmianą tekstu

Przykładowy kod, który ilustruje niektóre z funkcji związanych z label, w tym podmianę tekstu:

```c
#include <gtk/gtk.h>

// Funkcja do zmiany tekstu etykiety
static void change_label_text(GtkWidget *widget, gpointer label) {
    gtk_label_set_text(GTK_LABEL(label), "Tekst został zmieniony!");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Przykład etykiety GTK+");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *label = gtk_label_new("Kliknij przycisk, aby zmienić ten tekst.");
    GtkWidget *button = gtk_button_new_with_label("Zmień tekst");

    g_signal_connect(button, "clicked", G_CALLBACK(change_label_text), label);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
```
