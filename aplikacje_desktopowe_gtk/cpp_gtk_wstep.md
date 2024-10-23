Przykład programu w GTK+, który otwiera okno z etykietą oraz szczegółowe wyjaśnienie kodu:

```c
#define VERSION "0.1"  // Definicja wersji programu

#include <gtk/gtk.h>
// Dołączenie nagłówka GTK+, który zawiera funkcje i struktury do tworzenia aplikacji GUI

// Funkcja wywoływana przy zamknięciu okna
static void destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();  // Wyjście z pętli głównej GTK+, zamyka aplikację
}

int main(int argc, char *argv[]) {
    // Inicjalizacja GTK+
    gtk_init(&argc, &argv);
    // Inicjalizuje GTK+ i przekazuje argumenty wiersza poleceń.
    // To jest niezbędne, aby GTK+ mogło skonfigurować środowisko graficzne.

    // Tworzenie głównego okna
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    // Funkcja gtk_window_new() tworzy nowe okno typu TOPLEVEL,
    // co oznacza, że będzie to główne okno aplikacji.
    
    gtk_window_set_title(GTK_WINDOW(window), "etykieta GTK+");
    // Ustawia tytuł okna, który pojawi się w jego pasku tytułowym.

    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    // Ustawia szerokość marginesu wokół wnętrza okna. 

    gtk_widget_set_size_request(window, 400, 200);
    // Ustawia minimalny rozmiar okna na 400 pikseli szerokości i 200 pikseli wysokości.

    // Tworzenie etykiety
    GtkWidget *label = gtk_label_new("To jest program z etykietą.");
    // Tworzy nową etykietę z podanym tekstem. Etykieta to widżet wyświetlający statyczny tekst.

    // Podłączenie funkcji destroy() do sygnału destroy okna
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    // Funkcja g_signal_connect() podłącza funkcję do sygnału (zdarzenia) GTK. 
    // W tym przypadku, gdy użytkownik zamknie okno (sygnał "destroy"),
    // zostanie wywołana funkcja destroy(), która kończy program.

    // Dodanie etykiety do okna
    gtk_container_add(GTK_CONTAINER(window), label);
    // Dodaje etykietę jako dziecko kontenera okna.

    // Wyświetlenie wszystkich widżetów
    gtk_widget_show_all(window);
    // Wywołanie gtk_widget_show_all() sprawia, że wszystkie widżety
    // (okno i etykieta) stają się widoczne na ekranie.

    // Rozpoczęcie pętli głównej GTK+
    gtk_main();
    // Uruchamia główną pętlę aplikacji GTK+, która oczekuje
    // na zdarzenia (np. kliknięcia) i odpowiednio je obsługuje.
    // Dopóki gtk_main() działa, aplikacja pozostaje otwarta.

    return 0;  // Zwraca 0 po zakończeniu programu
}
```
