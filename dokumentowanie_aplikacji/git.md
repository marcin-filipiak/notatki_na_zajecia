# Notatka do zajęć – Git krok po kroku

**1. Wstęp – czym jest Git i do czego służy**

* Git to system kontroli wersji, który pozwala śledzić zmiany w plikach projektu.
* Umożliwia współpracę wielu osób nad tym samym kodem, tworzenie kopii zapasowych oraz cofanie błędów.
* Historia zmian jest przechowywana lokalnie, a zmiany można synchronizować ze zdalnymi repozytoriami (np. GitHub, GitLab).
* Każda zmiana w projekcie jest zapisywana w postaci commita, który ma unikalny identyfikator SHA-1 (hash).

**2. Podstawowe operacje – tworzenie i pobieranie repozytoriów**

* `git init` – inicjuje nowe repozytorium w bieżącym katalogu.
* `git clone [adres_repozytorium]` – kopiuje zdalne repozytorium na lokalny komputer.
* Po sklonowaniu repozytorium masz pełną historię i wszystkie gałęzie lokalnie.

**3. Przegląd stanu repozytorium i historii**

* `git status` – pokazuje zmodyfikowane pliki, pliki dodane do indeksu oraz pliki nieśledzone.
* `git log` – wyświetla historię commitów wraz z hashami, autorami i opisami zmian.
* SHA-1 hash identyfikuje jedno konkretne zatwierdzenie, np. `45a87f152c80bda8a15ea4a19d73e249a0c9759f`.

**4. Gałęzie (branches) i przełączanie między nimi**

* Gałąź to odrębna linia rozwoju, która pozwala eksperymentować i rozwijać różne funkcje niezależnie od głównej gałęzi (`main`).
* `git branch` – wyświetla listę gałęzi lokalnych.
* `git checkout nazwa_gałęzi` lub `git switch nazwa_gałęzi` – przełącza na wskazaną gałąź.


**5. Dodawanie i zatwierdzanie zmian**

* `git add plik.cpp` – dodaje plik do obszaru indeksu (staging area), przygotowując go do zatwierdzenia.
* `git commit -m "opis zmian"` – zapisuje zmiany w repozytorium lokalnym jako commit.
* `git push` – wysyła lokalne commity do repozytorium zdalnego.

**6. Aktualizacja zmian ze zdalnego repozytorium**

* `git fetch` – pobiera zmiany ze zdalnego repozytorium, nie łącząc ich automatycznie z lokalnymi plikami.
* `git pull` – pobiera zmiany i scala je z bieżącą gałęzią (`fetch + merge`).

**7. Łączenie zmian między gałęziami**

* `git merge nazwa_gałęzi` – scala całą gałąź do bieżącej, zachowując historię commitów.
* `git rebase nazwa_gałęzi` – włącza zmiany z innej gałęzi, "przesuwając" twoje commity na szczyt historii docelowej gałęzi.
* `git cherry-pick <hash>` – wybiera pojedynczy commit z innej gałęzi i dodaje go do bieżącej.
* Użycie: merge przydaje się do zachowania pełnej historii, rebase do liniowej historii, cherry-pick do wybranych zmian.

**8. Cofanie zmian i przywracanie wersji**

* `git checkout <hash> plik.cpp` – przywraca plik z określonego commita.
* `git reset plik.cpp` – wycofuje zmiany w pliku do ostatniego zatwierdzenia.
* `git revert <hash>` – tworzy nowy commit cofający zmiany z wybranego commita.

**9. Automatyzacja i skrypty w Git (Git Hooks)**

* Git hooks to skrypty uruchamiane automatycznie przy określonych zdarzeniach, np. przed commit (`pre-commit`) lub po push (`post-push`).
* Mogą służyć do sprawdzania jakości kodu, testowania, weryfikacji wiadomości commitów, blokowania złych commitów.
* Pliki hooków znajdują się w `.git/hooks` (np. `pre-commit.sample`). Można je edytować lub tworzyć własne skrypty.

**10. Wyszukiwanie błędów i czyszczenie historii**

* `git bisect` – automatycznie pomaga znaleźć commit, który wprowadził błąd w projekcie. Działa metodą „dziel i zwyciężaj”.
* `git filter-branch` – pozwala zmienić historię repozytorium, np. usunąć pliki lub zmienić autora commitów.

**Zastosowania Git**

* Bezpieczna praca zespołowa nad projektem.
* Eksperymentowanie w oddzielnych gałęziach bez ryzyka uszkodzenia głównego kodu.
* Automatyzacja procesów kontroli jakości dzięki hookom.
* Precyzyjne śledzenie zmian, szybkie cofanie błędów i tworzenie kopii zapasowych.

---

# Rozwiązywanie konfliktów przy pobieraniu PULL

W tym przypadku masz sytuację typowego **konfliktu przy synchronizacji lokalnego pliku z repozytorium zdalnym**. Oto, jak można to rozwiązać krok po kroku:

**1. Co się stało**

* Masz lokalny plik `test.cpp` z własnymi zmianami.
* Ktoś inny zmienił ten sam plik w repozytorium zdalnym i zatwierdził te zmiany.
* Gdy próbujesz wykonać `git pull`, Git wykrywa, że nie może automatycznie scalić zmian, bo te same linie zostały zmodyfikowane lokalnie i zdalnie. To powoduje **konflikt**.


**2. Jak Git informuje o konflikcie**

* Po `git pull` Git wyświetli komunikat o konflikcie i nie scaleniu pliku.
* Plik `test.cpp` zostanie zmodyfikowany w następujący sposób:

```
<<<<<<< HEAD
// Twoje lokalne zmiany
int x = 5;
=======
# Zmiany w repozytorium zdalnym
int x = 10;
>>>>>>> origin/main
```

* `<<<<<<< HEAD` – oznacza początek Twoich zmian lokalnych.
* `=======` – oddziela Twoje zmiany od zmian z repozytorium zdalnego.
* `>>>>>>> origin/main` – oznacza koniec zmian z repozytorium zdalnego (w tym przypadku głównej gałęzi `main`).


**3. Rozwiązywanie konfliktu**
Masz trzy główne opcje:

1. **Zachować swoje zmiany**

   * Edytujesz plik, zostawiając tylko swoje linie i usuwasz znaczniki `<<<<<<<`, `=======`, `>>>>>>>`.
   * Następnie wykonujesz:

     ```
     git add test.cpp
     git commit -m "opis zmian"
     ```

2. **Przyjąć zmiany z repozytorium zdalnego**

   * Edytujesz plik, zostawiając tylko wersję z repozytorium i usuwasz znaczniki konfliktu.
   * Następnie:

     ```
     git add test.cpp
     git commit -m "opis zmian"
     ```

3. **Połączyć zmiany lokalne i zdalne**

   * Ręcznie scalasz oba zestawy zmian w logiczny sposób, aby plik zawierał elementy obu wersji.
   * Następnie:

     ```
     git add test.cpp
     git commit -m "opis zmian"
     ```


**4. Dodatkowe wskazówki**

* Można też użyć narzędzi graficznych do rozwiązywania konfliktów, np. VSCode, GitKraken czy meld.
* Jeśli konflikt jest bardzo skomplikowany, można tymczasowo zapisać swoje zmiany w osobnym branchu (`git stash`) i pobrać zmiany ze zdalnego repozytorium, a następnie je scalić.

---

# Rozwiązywanie konfliktów przy wysyłaniu PUSH

W tym przypadku masz sytuację typowego **konfliktu przy wysyłaniu lokalnych zmian do repozytorium zdalnego**. Oto, jak można to rozwiązać krok po kroku:

**1. Co się stało**

* Masz lokalny plik `test.cpp` z własnymi zmianami i zatwierdzeniami (commity).
* Ktoś inny zmienił ten sam plik w repozytorium zdalnym i wysłał swoje zmiany (`git push`).
* Gdy próbujesz wykonać `git push`, Git odmawia wysłania zmian, bo Twój lokalny branch nie jest aktualny względem zdalnego. To powoduje **konflikt push**.


**2. Jak Git informuje o konflikcie**

* Po `git push` Git wyświetli komunikat podobny do:

```
! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'origin/main'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
```

* Git informuje, że musisz najpierw zsynchronizować lokalną gałąź ze zdalną, aby uniknąć nadpisania czyichś zmian.


**3. Rozwiązywanie konfliktu**

Masz trzy główne opcje:

1. **Pobrać zmiany i scalić (merge)**

   * Wykonaj `git pull --rebase` lub `git pull` aby pobrać zmiany z repozytorium zdalnego i połączyć je z lokalnymi.
   * Jeśli powstanie konflikt w pliku `test.cpp`, Git oznaczy go w standardowy sposób:

```
<<<<<<< HEAD
// Twoje lokalne zmiany
int x = 5;
=======
# Zmiany w repozytorium zdalnym
int x = 10;
>>>>>>> origin/main
```

* Rozwiąż konflikt ręcznie (zachowując swoje, zdalne lub scalając obie wersje).
* Następnie:

```
git add test.cpp
git commit -m "rozwiązanie konfliktu"
git push
```

2. **Przyjąć zmiany z repozytorium i nadpisać lokalne (ostrożnie!)**

   * Jeśli chcesz nadpisać lokalne zmiany, możesz wykonać:

```
git fetch
git reset --hard origin/main
git push
```

* UWAGA: spowoduje to utratę wszystkich lokalnych commitów, które nie zostały wcześniej wysłane.

3. **Tworzenie nowego branchu i wysyłka**

   * Jeśli Twoje zmiany są istotne, a zdalne też są potrzebne, można:

```
git checkout -b moja-wersja
git push -u origin moja-wersja
```

* Dzięki temu Twoje zmiany nie nadpiszą zdalnej gałęzi, a można później dokonać merge lub pull request.


**4. Dodatkowe wskazówki**

* Konflikty push są naturalną konsekwencją pracy zespołowej – oznaczają, że ktoś inny zmienił repozytorium w tym samym czasie.
* Najbezpieczniejsza praktyka: regularnie pobieraj zmiany (`git fetch` lub `git pull`) przed wysyłką własnych commitów.
* Warto używać `git pull --rebase`, aby utrzymać liniową historię commitów i ułatwić rozwiązywanie konfliktów.



