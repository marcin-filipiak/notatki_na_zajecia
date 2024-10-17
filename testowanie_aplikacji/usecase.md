### Scenariusz użytkowania (Use Case)

Scenariusz użytkowania, znany również jako **use case**, to narzędzie wykorzystywane w procesie projektowania i analizy systemów informatycznych. Jego głównym celem jest opisanie sposobu, w jaki użytkownik (lub inny system) wchodzi w interakcję z oprogramowaniem, aby osiągnąć konkretny cel. Jest to kluczowy element w analizie wymagań i służy do precyzowania funkcji, które dany system ma realizować.

#### Elementy scenariusza użytkowania:

1. **Aktor (Użytkownik)**  
   Aktor to osoba, system zewnętrzny lub inny element, który wchodzi w interakcję z systemem. Aktorem nie musi być tylko człowiek, może to być również inny system lub urządzenie, które korzysta z określonych funkcji naszego oprogramowania.

2. **Cel (Rezultat)**  
   Scenariusz użytkowania ma określać, co użytkownik chce osiągnąć, korzystając z systemu. To właśnie dążenie do tego celu motywuje działania użytkownika w opisywanym scenariuszu.

3. **Przebieg podstawowy**  
   To opis standardowej interakcji pomiędzy użytkownikiem a systemem, prowadzącej do osiągnięcia zamierzonego celu. Jest to najprostsza ścieżka działania, uwzględniająca poprawny przebieg operacji.

4. **Przebieg alternatywny**  
   Opisuje, co się dzieje, gdy pojawiają się alternatywne kroki lub ścieżki, które mogą prowadzić do celu. Może to być zmiana w interakcji spowodowana decyzjami użytkownika.

5. **Przebieg wyjątkowy (Błędy)**  
   Ten element odnosi się do sytuacji, gdy coś nie przebiega zgodnie z planem. Może to być np. awaria systemu, błąd użytkownika lub inne nieprzewidziane zdarzenia, które uniemożliwiają realizację celu.

#### Po co tworzymy scenariusze użytkowania?

Scenariusze użytkowania pomagają w zrozumieniu wymagań systemu z perspektywy użytkownika. Pozwalają na precyzyjne zdefiniowanie, jak system ma działać, co jest kluczowe w późniejszych etapach projektowania i implementacji. Tworzenie tych scenariuszy ułatwia komunikację między programistami, analitykami a interesariuszami (użytkownikami, właścicielami produktu), ponieważ dostarczają one jasnej i zrozumiałej specyfikacji funkcji systemu.

#### Znaczenie scenariuszy użytkowania w testach

Scenariusze użytkowania są niezwykle przydatne w procesie testowania, ponieważ dostarczają naturalnych przypadków testowych. Testerzy mogą wykorzystać je do symulacji realistycznych interakcji użytkownika z systemem, co pozwala na weryfikację, czy oprogramowanie zachowuje się zgodnie z oczekiwaniami. Testy oparte na scenariuszach użytkowania mogą obejmować zarówno testy funkcjonalne, jak i niefunkcjonalne, np. testy wydajnościowe lub bezpieczeństwa.

#### Podsumowanie

Scenariusze użytkowania są nieocenionym narzędziem w procesie projektowania, implementacji i testowania systemów informatycznych. Pomagają zrozumieć, jakie funkcje ma spełniać system, z punktu widzenia użytkownika, oraz zapewniają, że końcowy produkt spełnia założone wymagania.


_____

### Przykładowy scenariusz użytkowania: Proces logowania

#### 1. Aktor:
Użytkownik systemu (np. osoba posiadająca konto w aplikacji).

#### 2. Cel:
Użytkownik chce zalogować się do systemu, aby uzyskać dostęp do swojego konta.

#### 3. Przebieg podstawowy:
1. Użytkownik otwiera aplikację.
2. Aplikacja wyświetla ekran logowania z polami "nazwa użytkownika" i "hasło".
3. Użytkownik wprowadza swoją nazwę użytkownika oraz hasło.
4. Użytkownik klika przycisk "Zaloguj".
5. System weryfikuje poprawność danych logowania.
6. Jeśli dane są prawidłowe, system wyświetla stronę główną konta użytkownika.

#### 4. Przebieg alternatywny:
1. Użytkownik otwiera aplikację.
2. Aplikacja wyświetla ekran logowania.
3. Użytkownik klika przycisk "Nie pamiętam hasła".
4. System przekierowuje użytkownika do formularza resetu hasła.
5. Użytkownik podaje adres e-mail powiązany z kontem.
6. System wysyła nowe hasło na e-mail.

#### 5. Przebieg wyjątkowy:
1. Użytkownik otwiera aplikację.
2. Aplikacja wyświetla ekran logowania.
3. Użytkownik wprowadza nieprawidłową nazwę użytkownika lub hasło.
4. System wyświetla komunikat "Nieprawidłowe dane logowania" i prosi o ponowne wprowadzenie danych.

#### Wyjaśnienie
W tym scenariuszu użytkowania aktorem jest **użytkownik**, a jego **celem** jest zalogowanie się do systemu. **Przebieg podstawowy** opisuje standardową, prawidłową ścieżkę, gdy dane są poprawne. **Przebieg alternatywny** przedstawia sytuację, w której użytkownik musi zresetować hasło, ponieważ go zapomniał. Natomiast **przebieg wyjątkowy** wskazuje, co się dzieje, gdy użytkownik poda błędne dane logowania.

#### Znaczenie w testach:
Scenariusz ten można łatwo przekształcić w przypadki testowe. Testerzy mogliby sprawdzić, czy system prawidłowo reaguje na poprawne i błędne dane logowania, czy opcja resetu hasła działa zgodnie z oczekiwaniami, oraz czy komunikaty błędów są odpowiednio wyświetlane.
