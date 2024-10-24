# GTK+ Label

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

### Podsumowanie
Ten minimalistyczny kod tworzy prostą aplikację GTK+, która wyświetla okno z etykietą. Każda linia ma swoje znaczenie i przyczynia się do funkcjonalności aplikacji. Dzięki temu kodowi można zobaczyć, jak w prosty sposób można stworzyć graficzny interfejs użytkownika w GTK+.
