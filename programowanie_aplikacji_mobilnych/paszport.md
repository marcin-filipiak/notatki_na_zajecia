INF.04-01-24.01-SG
Czas: 80 minut

### Opis aplikacji desktopowej

Na obrazie 1 przedstawiono ideę aplikacji desktopowej. W zależności od użytego środowiska programistycznego wygląd może nieznacznie się różnić.

#### Opis wyglądu aplikacji

- **Okno** o nazwie:  
  **„Wprowadzenie danych do paszportu. Wykonał: ”** *+ numer zdającego*  
- **Kontrolki rozmieszczone zgodnie z obrazem 1:**
  - Pole edycyjne poprzedzone etykietą **„Numer”**
  - Pole edycyjne poprzedzone etykietą **„Imię”**
  - Pole edycyjne poprzedzone etykietą **„Nazwisko”**
  - **Grupa „Kolor oczu”**, zawierająca trzy pola wyboru:
    - **„niebieskie”** (domyślnie zaznaczone)
    - **„zielone”**
    - **„piwne”**
  - W grupie może być zaznaczone tylko jedno pole  
  - **Przycisk** o treści **„OK”**
  - **Dwa obrazy:** `000-zdjecie.jpg` oraz `000-odcisk.jpg`  
    - Obrazy mają tę samą wysokość
    - Wysokość w aplikacji: **180**
- **Kolory interfejsu:**
  - **Tło okna:** CadetBlue (`#5F9EA0`)
  - **Tło pól edycyjnych i przycisku:** Azure (`#F0FFFF`)

---

#### Działanie aplikacji

##### Po opuszczeniu pola edycyjnego **„Numer”**
- Aktualizowane są oba zdjęcia w oknie  
- **Nazwy plików graficznych tworzone są na podstawie wpisanego numeru:**
  - Obraz osoby: `<numer>-zdjecie.jpg`, np. wpisanie `333` → `333-zdjecie.jpg`
  - Obraz odcisku palca: `<numer>-odcisk.jpg`, np. wpisanie `333` → `333-odcisk.jpg`
- W przypadku wpisania numeru, który **nie odpowiada żadnemu plikowi**, obraz nie jest wyświetlany.

##### Po wybraniu przycisku **„OK”**
- **Jeśli wszystkie pola edycyjne są wypełnione:**  
  Wyświetlany komunikat:  
  **„<imie> <nazwisko> kolor oczu <kolor>”**  
  *(gdzie wartości w nawiasach <> pobierane są z kontrolek)*
- **Jeśli brakuje imienia lub nazwiska:**  
  Wyświetlany komunikat: **„Wprowadź dane”**

---

### Dodatkowe wymagania
- Aplikacja powinna być napisana **czytelnie**, zgodnie z zasadami **czystego formatowania kodu**.
- **Nazwy zmiennych i funkcji** powinny być **znaczące** i jednoznaczne.
