### GTK+ w Programowaniu C++

#### Czym jest GTK+?

GTK+ to zestaw narzędzi do tworzenia graficznych interfejsów użytkownika (GUI) w języku C, ale może być również wykorzystywany w aplikacjach pisanych w C++. Został stworzony w 1997 roku przez Petera Mattisa i Spencera Kimballa na potrzeby edytora graficznego GIMP. GTK+ stał się fundamentem wielu aplikacji, szczególnie w systemach Linux, a jednym z najbardziej znanych środowisk graficznych korzystających z GTK+ jest GNOME.

GTK+ jest częścią ekosystemu wolnego oprogramowania i jest dostępny na licencji LGPL (Lesser General Public License), co oznacza, że może być używany zarówno w projektach open-source, jak i komercyjnych.

Obecnie biblioteka funkcjonuje jako GTK 4, natomiast starsze wersje, takie jak GTK+ 2 czy GTK+ 3, wciąż są szeroko wykorzystywane.

Uwagi językowe i historyczne:
GTK+ jest napisana w języku C, korzysta z własnego systemu obiektowego opartego na GObject.
Dla programistów C++ dostępne jest obiektowe API gtkmm, które pozwala pisać aplikacje w stylu C++.
W dokumentacji i współczesnych materiałach nazwa „GTK” zastępuje dawną „GTK+”, ale pakiety systemowe dla wersji 3 i 4 wciąż używają w pkg-config nazw takich jak gtk+-3.0.

#### Gdzie jest stosowany?

GTK+ jest stosowany w tworzeniu aplikacji desktopowych, głównie w środowiskach Linux, ale także na platformach Windows i macOS. 
Przykładowe aplikacje oparte na GTK+ to:

- **GIMP** (edytor grafiki),
- **Inkscape** (program do grafiki wektorowej),
- **GNOME** (środowisko graficzne dla systemów Linux),
- **Anjuta** (IDE),
- **Pidgin** (komunikator internetowy).

GTK+ zapewnia narzędzia do tworzenia interaktywnych i responsywnych interfejsów użytkownika, pozwalając programistom na manipulowanie widżetami oraz kontrolowanie ich wyglądu i zachowania.

#### Zasady Tworzenia Aplikacji w GTK+

Tworzenie aplikacji w GTK+ opiera się na kilku podstawowych krokach:

1. **Inicjalizacja GTK+**:
   Aplikację zaczyna się od wywołania funkcji `gtk_init()`, która przygotowuje GTK+ do działania. Funkcja ta musi być wywołana zanim utworzymy jakiekolwiek widżety.

   ```cpp
   int main(int argc, char *argv[]) {
       gtk_init(&argc, &argv);  // Inicjalizacja GTK+
   }
   ```

2. **Tworzenie widżetów**:
   Widżety to interaktywne elementy interfejsu użytkownika, takie jak okna, przyciski czy etykiety. Po utworzeniu widżetów należy je skonfigurować (np. ustawić tytuł okna), a następnie dodać do odpowiednich kontenerów.

3. **Dodawanie widżetów do kontenerów**:
   Kontenery są elementami, które organizują widżety w strukturę graficzną aplikacji. Każdy widżet musi być dodany do odpowiedniego kontenera.

4. **Obsługa zdarzeń (sygnałów)**:
   GTK+ wykorzystuje system sygnałów, aby reagować na różne zdarzenia, takie jak kliknięcie przycisku lub zamknięcie okna. Programiści mogą definiować funkcje, które zostaną wywołane w odpowiedzi na określone sygnały.

   ```cpp
   g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
   ```

5. **Rozpoczęcie głównej pętli zdarzeń**:
   Po skonfigurowaniu widżetów i obsłudze sygnałów, aplikacja uruchamia główną pętlę zdarzeń za pomocą funkcji `gtk_main()`. Pętla ta oczekuje na interakcje użytkownika i reaguje na nie.

#### Kontenery w GTK+

Kontenery to widżety, które służą do rozmieszczania innych widżetów w oknie aplikacji. Mogą ustawiać widżety obok siebie, w siatkach lub w dowolny inny sposób. Kilka popularnych kontenerów to:

- **GtkBox** – ustawia widżety w poziomym lub pionowym układzie.
- **GtkGrid** – organizuje widżety w formie siatki.
- **GtkFixed** – pozwala ręcznie ustawiać pozycje widżetów (rzadziej używany).
- **GtkWindow** – główny kontener aplikacji, który wyświetla się jako okno systemowe.

#### Sygnały w GTK+

System sygnałów w GTK+ pozwala reagować na różne zdarzenia związane z widżetami. Każdy widżet może emitować sygnały, takie jak kliknięcie, zmiana wartości, zamknięcie itp. Programiści mogą „podłączyć” funkcje zwrotne (callback), które zostaną wywołane w odpowiedzi na te sygnały.

Na przykład, sygnał „destroy” jest emitowany, gdy użytkownik zamknie okno. Możemy go obsłużyć za pomocą funkcji:

```cpp
g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
```

#### Podstawowe Metody w GTK+

- **`gtk_init()`** – Inicjalizuje bibliotekę GTK+, przygotowując ją do użycia.
- **`gtk_main()`** – Uruchamia główną pętlę zdarzeń aplikacji.
- **`gtk_main_quit()`** – Kończy działanie pętli GTK+ i zamyka aplikację.
- **`g_signal_connect()`** – Łączy sygnał emitowany przez widżet z funkcją obsługującą to zdarzenie.
- **`gtk_widget_show_all()`** – Wyświetla wszystkie widżety dodane do aplikacji.

#### Widżety w GTK+

GTK+ dostarcza widżety, które można używać do budowy interfejsu. Oto kilka najważniejszych:

- **GtkWindow** – Główne okno aplikacji.
- **GtkButton** – Przycisk, który można kliknąć.
- **GtkLabel** – Etykieta wyświetlająca tekst.
- **GtkEntry** – Pole tekstowe do wprowadzania danych.
- **GtkTextView** – Wielolinijkowe pole tekstowe.
- **GtkImage** – Widżet do wyświetlania obrazów.
- **GtkComboBox** – Lista rozwijana z opcjami do wyboru.
- **GtkProgressBar** – Pasek postępu.
  
Widżety mogą być rozmieszczane i grupowane w kontenerach, a ich zachowanie można kontrolować za pomocą sygnałów.

___
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
