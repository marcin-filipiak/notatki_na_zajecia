INF.04-01-21.06-SG  
Czas: 80minut

# Opis działania aplikacji mobilnej


## Opis wyglądu aplikacji

- **Napis** „Rejestruj konto”.
- **Napis** „Podaj e-mail:”, a pod nim pole edycyjne z podpowiedzią o treści „email”.
- **Napis** „Podaj hasło:”, a pod nim pole edycyjne do wprowadzenia hasła, realizuje ukrywanie hasła.
- **Napis** „Powtórz hasło:”, a pod nim pole edycyjne do wprowadzenia hasła, realizuje ukrywanie hasła.
- **Przycisk** o treści „ZATWIERDŹ”, jest on wyśrodkowany.
- **Obszar do wyświetlania komunikatów**, jest on wyśrodkowany.


## Działanie aplikacji

Po wybraniu przycisku **ZATWIERDŹ** jest sprawdzane:

1. Czy e-mail zawiera znak `@`.
2. Czy podane hasło jest równe powtórzonemu hasłu.

W obszarze do wyświetlania komunikatów pojawia się napis:

- **Na początku działania aplikacji**: „Autor”, dalej wstawiony numer PESEL zdającego.
- **Po zatwierdzeniu, gdy e-mail jest niepoprawny**: „Nieprawidłowy adres e-mail”.
- **Po zatwierdzeniu, gdy hasła się różnią**: „Hasła się różnią”.
- **Po zatwierdzeniu, gdy nie wystąpiły błędy**: „Witaj `<e-mail>`”, gdzie `<e-mail>` oznacza aktualnie wprowadzony adres e-mail.

## Założenia aplikacji

- **Interfejs użytkownika** zapisany za pomocą języka znaczników wspieranego w danym środowisku (np. XAML, XML).
- **Zastosowany typ rozkładu**: liniowy (Linear / Stack lub inny o tej idei).
- **Kolor tła napisu „Rejestruj konto”**: **Teal** (`#008080`), zgodnie z obrazem 1a.
- **Kolory czcionki**: czarny.
- **Czcionka napisu „Rejestruj konto”**: większa od pozostałych.
- **Pola edycyjne**: rozciągnięte na całą szerokość ekranu.
- **Kod aplikacji**: czytelny, zgodny z zasadami czystego formatowania, stosujący znaczące nazwy zmiennych i funkcji.

