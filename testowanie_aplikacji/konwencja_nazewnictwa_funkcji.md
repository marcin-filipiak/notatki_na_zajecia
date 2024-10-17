# Konwencje Nazewnictwa w Programowaniu

W programowaniu istnieje wiele konwencji nazewnictwa, które mają swoje specyficzne zastosowania. Oto przegląd najczęściej spotykanych sposobów nazywania funkcji, zmiennych, klas oraz innych elementów kodu.

#### 1. **CamelCase (notacja wielbłądzia)**
   - **Opis**: Każde kolejne słowo w nazwie zaczyna się od dużej litery, natomiast pierwsze słowo od małej.
   - **Przykłady**: `myVariable`, `calculateSum`, `isFinished`.
   - **Zastosowanie**: Stosowana głównie w nazwach metod i zmiennych lokalnych w wielu językach programowania, takich jak Java, JavaScript, czy C++.

#### 2. **PascalCase**
   - **Opis**: Podobnie jak CamelCase, ale pierwsze słowo również zaczyna się od wielkiej litery.
   - **Przykłady**: `MyClass`, `EmployeeList`, `UserData`.
   - **Zastosowanie**: Zwykle stosowana do nazw klas, obiektów i typów w językach takich jak C#, Java, oraz w niektórych frameworkach.

#### 3. **snake_case**
   - **Opis**: Wszystkie wyrazt są pisane małymi literami, a poszczególne słowa oddzielone są znakiem podkreślenia (_).
   - **Przykłady**: `my_variable`, `calculate_sum`, `is_finished`.
   - **Zastosowanie**: Powszechnie używana w Pythonie, a także w nazwach plików lub zmiennych globalnych w C.

#### 4. **SCREAMING_SNAKE_CASE**
   - **Opis**: Wersja snake_case, gdzie wszystkie wyrazy są pisane wielkimi literami.
   - **Przykłady**: `MAX_SIZE`, `DEFAULT_VALUE`, `TOTAL_SUM`.
   - **Zastosowanie**: Często stosowana dla stałych (constant) lub makr w C/C++.

#### 5. **kebab-case**
   - **Opis**: Wszystkie słowa są pisane małymi literami, a zamiast spacji stosowane są myślniki (-).
   - **Przykłady**: `my-variable`, `calculate-sum`, `is-finished`.
   - **Zastosowanie**: Najczęściej spotykana w URL-ach, nazwach plików, czy plikach konfiguracyjnych (np. YAML).

#### 6. **Hungarian Notation (notacja węgierska)**
   - **Opis**: Nazwa zmiennej zaczyna się od prefiksu określającego typ danych (np. `strName` dla stringa, `iCount` dla zmiennej typu int).
   - **Przykłady**: `strUserName`, `iAge`, `fPrice`.
   - **Zastosowanie**: Była szeroko stosowana w starszych projektach, zwłaszcza w języku C i C++, ale obecnie rzadziej używana.

### Dlaczego warto stosować konwencje nazewnictwa?
- **Czytelność kodu**: Stosowanie spójnych konwencji nazewnictwa ułatwia odczytywanie i zrozumienie kodu przez innych programistów.
- **Łatwiejsza konserwacja**: Dzięki ustandaryzowanemu nazewnictwu łatwiej jest utrzymać i rozwijać kod, zwłaszcza w większych zespołach.
- **Zgodność ze stylem języka**: Niektóre języki programowania mają preferowane konwencje nazewnictwa, które warto przestrzegać, aby zachować dobre praktyki.

#### Podsumowanie
Wybór odpowiedniej konwencji nazewnictwa zależy od języka programowania, środowiska pracy i preferencji zespołu. Ważne jest jednak, aby zachować spójność w całym projekcie, co ułatwi zarówno tworzenie, jak i utrzymywanie kodu.
