W GTK+ widżety są podstawowymi elementami interfejsu użytkownika, takimi jak przyciski, etykiety, pola tekstowe i inne. Aby stworzyć aplikację, która ma okno z widżetami, musimy umieszczać je w odpowiednich kontenerach i hierarchii, co pozwala na organizację elementów wizualnych na ekranie.

### Hierarchia widżetów w GTK+

Każda aplikacja w GTK+ opiera się na hierarchii widżetów. **GtkWindow** jest na szczycie tej hierarchii – jest to główne okno aplikacji. Wewnątrz okna umieszcza się **kontenery**, które służą do organizacji widżetów. Kontenery mogą zawierać inne widżety, takie jak przyciski, pola tekstowe, etykiety lub nawet inne kontenery. 

Hierarchia w GTK+ wygląda w uproszczeniu tak:

1. **GtkWindow** (główne okno aplikacji)
   - Kontenery (np. GtkBox, GtkGrid)
     - Widżety (np. GtkButton, GtkLabel, GtkEntry)

### Okno w GTK+ (GtkWindow)

**GtkWindow** to główny kontener, który reprezentuje okno systemowe. Jest to najczęściej używany element GTK+, ponieważ prawie każda aplikacja graficzna potrzebuje okna. Okno może zawierać inne widżety, które są do niego dodawane za pośrednictwem kontenerów.

Przykład stworzenia okna:

```c
GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window), "Przykładowe Okno");
gtk_widget_set_size_request(window, 400, 300);
```

- **gtk_window_new()**: Tworzy nowe okno.
- **gtk_window_set_title()**: Ustawia tytuł okna.
- **gtk_widget_set_size_request()**: Ustawia minimalne wymiary okna.

### Kontenery w GTK+

Kontenery to widżety, które mogą zawierać inne widżety. Używane są do rozmieszczania elementów interfejsu w określony sposób. Przykładami kontenerów są:

- **GtkBox**: Umożliwia ustawienie widżetów w linii poziomej (HBox) lub pionowej (VBox).
- **GtkGrid**: Organizuje widżety w układzie siatki (podobnie jak tabele w HTML).
- **GtkFixed**: Pozwala na ręczne ustawianie pozycji widżetów.

#### Użycie GtkBox (Układ liniowy)

**GtkBox** to jeden z najczęściej używanych kontenerów, który pozwala na ustawianie widżetów jeden za drugim, poziomo lub pionowo.

Przykład:

```c
GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);  // Tworzenie boxa pionowego z odstępem 5 pikseli

GtkWidget *button1 = gtk_button_new_with_label("Przycisk 1");
GtkWidget *button2 = gtk_button_new_with_label("Przycisk 2");

// Dodanie przycisków do kontenera
gtk_box_pack_start(GTK_BOX(box), button1, TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(box), button2, TRUE, TRUE, 0);
```

- **gtk_box_new()**: Tworzy nowy kontener box.
- **gtk_box_pack_start()**: Dodaje widżet do kontenera na początku listy elementów.

**GtkBox** może być użyty w wersji pionowej lub poziomej:
- **GtkOrientation.VERTICAL**: Widżety są rozmieszczone pionowo.
- **GtkOrientation.HORIZONTAL**: Widżety są rozmieszczone poziomo.

#### Użycie GtkGrid (Układ siatki)

**GtkGrid** to bardziej elastyczny kontener, który pozwala rozmieszczać widżety w formie tabeli. Każdy widżet można umieścić w określonej pozycji siatki, podając współrzędne wiersza i kolumny.

Przykład:

```c
GtkWidget *grid = gtk_grid_new();  // Tworzenie nowej siatki

GtkWidget *label = gtk_label_new("Etykieta:");
GtkWidget *entry = gtk_entry_new();

// Umieszczenie etykiety i pola tekstowego w siatce
gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);  // Wiersz 0, kolumna 0
gtk_grid_attach(GTK_GRID(grid), entry, 1, 0, 1, 1);  // Wiersz 0, kolumna 1
```

- **gtk_grid_new()**: Tworzy nowy kontener grid.
- **gtk_grid_attach()**: Dodaje widżet do siatki, określając pozycję (wiersz, kolumna) oraz liczbę zajmowanych komórek.

### Sygnały i Funkcje Callback

GTK+ używa systemu sygnałów, który pozwala reagować na interakcje użytkownika. Sygnały są emitowane przez widżety w momencie, gdy zachodzi określone zdarzenie, takie jak kliknięcie przycisku, zamknięcie okna, wpisanie tekstu itp.

Sygnały są obsługiwane przez tzw. **funkcje callback** – funkcje, które są wywoływane automatycznie, gdy sygnał zostanie odebrany.

Przykład obsługi sygnału zamknięcia okna:

```c
g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
```

- **g_signal_connect()**: Łączy sygnał emitowany przez widżet (np. „destroy”) z funkcją, która ma być wywołana, gdy sygnał zostanie wysłany (np. `gtk_main_quit()`).
- **gtk_main_quit()**: Funkcja kończąca główną pętlę zdarzeń GTK+ i zamykająca aplikację.

### Proces Umieszczania Widżetów

Podstawowy proces umieszczania widżetów w GTK+ wygląda następująco:

1. **Tworzenie okna**:
   Na początku tworzy się okno za pomocą `gtk_window_new()`, które stanowi kontener najwyższego poziomu.

2. **Tworzenie kontenerów**:
   Następnie do okna dodajemy kontener (np. GtkBox, GtkGrid), który będzie organizował rozmieszczenie widżetów.

3. **Tworzenie widżetów**:
   Kolejnym krokiem jest tworzenie widżetów, takich jak przyciski, etykiety, pola tekstowe itd.

4. **Dodawanie widżetów do kontenera**:
   Po utworzeniu widżetów dodaje się je do kontenera, a ten z kolei do okna.

Przykładowa hierarchia:

```c
GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
GtkWidget *button = gtk_button_new_with_label("Kliknij mnie");

gtk_container_add(GTK_CONTAINER(window), box);
gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);
```
