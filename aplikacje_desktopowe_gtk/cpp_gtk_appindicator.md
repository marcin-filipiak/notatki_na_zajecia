# AppIndicator w GTK — prosty aplet systemowy w C

### **1. Co to jest AppIndicator**

AppIndicator (nazywany też **Application Indicator**) to biblioteka służąca do tworzenia ikon i menu w **obszarze powiadomień** (tray, panel systemowy).
W odróżnieniu od przestarzałych `GtkStatusIcon`, AppIndicator działa poprawnie w nowoczesnych środowiskach graficznych (GNOME, Unity, MATE) i korzysta z usługi `Ayatana Indicators`.

Biblioteka ta umożliwia:

* wyświetlenie ikony w pasku systemowym,
* dodanie menu kontekstowego (np. informacje, opcje, zakończenie programu),
* interakcję z użytkownikiem bez tworzenia głównego okna aplikacji.

---

### **2. Wymagane pakiety**

Na Debianie lub Ubuntu należy doinstalować pakiety:

```bash
sudo apt install libgtk-3-dev libayatana-appindicator3-dev
```

Dodatkowo środowisko wsparcia dla AppIndicator:

```bash
sudo apt install ayatana-indicator-application
```

---

### **3. Kod źródłowy z komentarzami**

```c
#define VERSION "0.1"

#include <gtk/gtk.h>
#include <libayatana-appindicator/app-indicator.h>

int main(int argc, char *argv[])
{
    // Inicjalizacja biblioteki GTK
    gtk_init(&argc, &argv);

    // Utworzenie nowego wskaźnika (ikony w trayu)
    // "weather-applet" – identyfikator programu
    // "weather-clear" – nazwa ikony z systemowego katalogu /usr/share/icons
    // APP_INDICATOR_CATEGORY_APPLICATION_STATUS – typ wskaźnika
    AppIndicator *indicator = app_indicator_new(
        "weather-applet",
        "weather-clear",
        APP_INDICATOR_CATEGORY_APPLICATION_STATUS
    );

    // Ustawienie wskaźnika jako aktywny (widoczny)
    app_indicator_set_status(indicator, APP_INDICATOR_STATUS_ACTIVE);

    // Tworzymy menu po kliknięciu prawym przyciskiem na ikonę
    GtkWidget *menu = gtk_menu_new();

    // Pozycja menu z informacją
    GtkWidget *item_temp = gtk_menu_item_new_with_label("Temperatura: 20°C, Kraków");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), item_temp);

    // Pozycja menu do zamykania programu
    GtkWidget *item_quit = gtk_menu_item_new_with_label("Zamknij");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), item_quit);

    // Podłączenie sygnału do zamknięcia aplikacji
    g_signal_connect(item_quit, "activate", G_CALLBACK(gtk_main_quit), NULL);

    // Wyświetlenie wszystkich elementów menu
    gtk_widget_show_all(menu);

    // Przypisanie menu do wskaźnika
    app_indicator_set_menu(indicator, GTK_MENU(menu));

    // Uruchomienie głównej pętli programu GTK
    gtk_main();
    return 0;
}
```

---

### **4. Kompilacja programu**

Aby skompilować kod, użyj `g++` lub `gcc` z `pkg-config`, które automatycznie doda potrzebne flagi kompilacji i linkowania.

```bash
g++ main.cpp -o weather_applet $(pkg-config --cflags --libs gtk+-3.0 libayatana-appindicator3-0.1)
```

lub (jeśli plik ma rozszerzenie `.c`):

```bash
gcc main.c -o weather_applet $(pkg-config --cflags --libs gtk+-3.0 libayatana-appindicator3-0.1)
```

---

### **5. Uruchamianie**

Po kompilacji uruchom:

```bash
./weather_applet
```

Na panelu systemowym pojawi się ikona pogody („weather-clear”).
Po kliknięciu prawym przyciskiem myszy otworzy się menu z napisem „Temperatura: 20°C, Kraków” oraz opcją „Zamknij”.

---

### **6. Dodatkowe uwagi**

* Ikony, takie jak `"weather-clear"`, pochodzą z systemowych zestawów ikon (`/usr/share/icons/`).
* Program nie otwiera klasycznego okna — działa w tle i zarządza się nim przez ikonę w trayu.
* Biblioteka `Ayatana AppIndicator` jest nowszym i aktywnie rozwijanym zamiennikiem dla starego `libappindicator`.
