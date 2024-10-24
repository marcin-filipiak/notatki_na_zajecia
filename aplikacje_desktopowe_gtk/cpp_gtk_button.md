# GTK+ Button

Przycisk (button) w GTK+ to interaktywny widżet, który umożliwia użytkownikowi wykonywanie akcji poprzez jego kliknięcie. Przycisk jest jednym z najczęściej używanych elementów interfejsu użytkownika, a jego wygląd i zachowanie mogą być dostosowywane. Przyciski mogą zawierać tekst, obrazy lub oba te elementy jednocześnie. Można również przypisać różne sygnały do przycisków, co pozwala na reagowanie na interakcje użytkownika, takie jak kliknięcia.

Kod aplikacji GTK+, który wyświetla przycisk i zmienia tekst etykiety po kliknięciu przycisku.

```c
#include <gtk/gtk.h>

// Funkcja wywoływana przy kliknięciu przycisku
static void on_button_clicked(GtkWidget *widget, gpointer label) {
    gtk_label_set_text(GTK_LABEL(label), "Przycisk został kliknięty!");
}

int main(int argc, char *argv[]) {
    // Inicjalizacja GTK+
    gtk_init(&argc, &argv);

    // Tworzenie głównego okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Przykład przycisku GTK+");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Tworzenie pudełka do rozmieszczania widżetów
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    
    // Tworzenie etykiety
    GtkWidget *label = gtk_label_new("Kliknij przycisk, aby zmienić ten tekst.");
    
    // Tworzenie przycisku
    GtkWidget *button = gtk_button_new_with_label("Kliknij mnie");

    // Podłączenie sygnału do funkcji on_button_clicked
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), label);
    
    // Podłączenie sygnału z zamknięciem okna do funkcji gtk_main_quit
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Dodanie etykiety i przycisku do pudełka
    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);
    
    // Dodanie pudełka do okna
    gtk_container_add(GTK_CONTAINER(window), box);

    // Wyświetlenie wszystkich widżetów
    gtk_widget_show_all(window);

    // Rozpoczęcie pętli głównej GTK+
    gtk_main();

    return 0;
}
```

### Omówienie kodu

1. **`#include <gtk/gtk.h>`**
   - Dołącza nagłówek biblioteki GTK+, co pozwala na korzystanie ze wszystkich funkcji i typów zdefiniowanych w GTK+.

2. **`static void on_button_clicked(GtkWidget *widget, gpointer label)`**
   - Definiuje funkcję `on_button_clicked`, która jest wywoływana, gdy przycisk zostanie kliknięty. Funkcja przyjmuje wskaźnik do widżetu (`widget`) i wskaźnik do etykiety (`label`). Zmienia tekst etykiety na "Przycisk został kliknięty!".

3. **`int main(int argc, char *argv[])`**
   - Główna funkcja programu, która jest punktem wejścia do aplikacji.

4. **`gtk_init(&argc, &argv);`**
   - Inicjalizuje bibliotekę GTK+, co jest niezbędne przed wywołaniem jakichkolwiek funkcji GTK.

5. **`GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);`**
   - Tworzy nowe główne okno aplikacji. `GTK_WINDOW_TOPLEVEL` oznacza, że jest to okno główne z ramkami i przyciskami systemowymi.

6. **`gtk_window_set_title(GTK_WINDOW(window), "Przykład przycisku GTK+");`**
   - Ustawia tytuł okna, który pojawia się w pasku tytułowym okna.

7. **`gtk_container_set_border_width(GTK_CONTAINER(window), 10);`**
   - Ustawia szerokość marginesu wokół zawartości okna na 10 pikseli, co tworzy przestrzeń wewnątrz okna.

8. **`GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);`**
   - Tworzy nowe pudełko, które będzie używane do rozmieszczania widżetów w pionie. Argument `5` ustawia odstęp między elementami.

9. **`GtkWidget *label = gtk_label_new("Kliknij przycisk, aby zmienić ten tekst.");`**
   - Tworzy etykietę z początkowym tekstem.

10. **`GtkWidget *button = gtk_button_new_with_label("Kliknij mnie");`**
    - Tworzy przycisk z napisem "Kliknij mnie".

11. **`g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), label);`**
    - Łączy sygnał "clicked" (kliknięcie przycisku) z funkcją `on_button_clicked`. Gdy przycisk zostanie kliknięty, funkcja ta zostanie wywołana, a etykieta zostanie zaktualizowana.

12. **`g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);`**
    - Łączy sygnał "destroy" z funkcją `gtk_main_quit`, co kończy aplikację po zamknięciu okna.

13. **`gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);`**
    - Dodaje etykietę do pudełka. `TRUE` oznacza, że etykieta ma być rozciągana i zajmować dostępne miejsce.

14. **`gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);`**
    - Dodaje przycisk do pudełka w podobny sposób jak etykietę.

15. **`gtk_container_add(GTK_CONTAINER(window), box);`**
    - Dodaje pudełko do kontenera (okna), co sprawia, że etykieta i przycisk stają się częścią okna.

16. **`gtk_widget_show_all(window);`**
    - Wyświetla wszystkie widżety w oknie, zapewniając ich widoczność na ekranie.

17. **`gtk_main();`**
    - Rozpoczyna pętlę główną GTK, która obsługuje zdarzenia i interakcje użytkownika.

18. **`return 0;`**
    - Zwraca 0, co oznacza, że program zakończył się pomyślnie.
___

Oto bardziej szczegółowe omówienie funkcji związanych z manipulowaniem tekstem na przycisku oraz jego stanem (aktywność, widoczność, zablokowanie):

### 1. Zmiana tekstu na przycisku

- **Tworzenie przycisku z etykietą:**
  - **`GtkWidget* gtk_button_new_with_label(const gchar *label)`**: Tworzy nowy przycisk z etykietą, której tekst można ustawić przy inicjalizacji. 

- **Zmiana etykiety po utworzeniu:**
  - **`void gtk_button_set_label(GtkButton *button, const gchar *label)`**: Umożliwia zmianę tekstu wyświetlanego na przycisku w dowolnym momencie. Na przykład, gdy przycisk zostanie kliknięty, tekst może się zmienić, aby poinformować użytkownika o nowej akcji.

  ```c
  void on_button_clicked(GtkButton *button) {
      gtk_button_set_label(button, "Kliknięto!");
  }
  ```

### 2. Zmienianie stanu przycisku

- **Włączanie i wyłączanie przycisku:**
  - **`void gtk_widget_set_sensitive(GtkWidget *widget, gboolean sensitive)`**: Umożliwia włączenie lub wyłączenie przycisku. Ustawienie `sensitive` na `FALSE` powoduje, że przycisk staje się nieaktywny i nie można go kliknąć.

  ```c
  // Wyłączenie przycisku
  gtk_widget_set_sensitive(button, FALSE);
  
  // Włączenie przycisku
  gtk_widget_set_sensitive(button, TRUE);
  ```

### 3. Ukrywanie i pokazywanie przycisku

- **Ukrywanie przycisku:**
  - **`void gtk_widget_hide(GtkWidget *widget)`**: Ukrywa przycisk, co oznacza, że nie jest on widoczny na interfejsie użytkownika. Można go później przywrócić.

  ```c
  gtk_widget_hide(button);
  ```

- **Pokazywanie przycisku:**
  - **`void gtk_widget_show(GtkWidget *widget)`**: Przywraca widoczność ukrytego przycisku.

  ```c
  gtk_widget_show(button);
  ```

### 4. Przykład użycia

Oto przykład ilustrujący zmianę tekstu na przycisku, jego wyłączanie oraz ukrywanie:

```c
#include <gtk/gtk.h>

void on_button_clicked(GtkButton *button) {
    // Zmiana tekstu na przycisku
    gtk_button_set_label(button, "Kliknięto!");

    // Wyłączenie przycisku
    gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);

    // Ukrycie przycisku
    gtk_widget_hide(GTK_WIDGET(button));
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *button = gtk_button_new_with_label("Kliknij mnie");

    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
```

### Podsumowanie

Manipulacja tekstem oraz stanem przycisku w GTK+ pozwala na dynamiczne dostosowywanie interfejsu użytkownika. Zmiana etykiety przycisku, włączanie i wyłączanie go oraz ukrywanie i pokazywanie to kluczowe operacje, które umożliwiają interakcję z użytkownikiem w aplikacjach graficznych.
