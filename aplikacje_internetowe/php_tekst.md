#Praca z tekstami

W PHP praca z tekstem jest prosta dzięki wielu funkcjom wbudowanym w język, które umożliwiają manipulację ciągami znaków (stringami). Poniżej znajdziesz podstawowe informacje i najważniejsze funkcje do pracy z tekstami.

#### Tworzenie i wyświetlanie tekstu

W PHP teksty umieszczamy między cudzysłowami (`"` lub `'`). Możemy wyświetlić tekst za pomocą funkcji `echo` lub `print`.

```php
$imie = "Jan";
echo "Cześć, $imie!"; // Wyświetli: Cześć, Jan!
echo 'Cześć, ' . $imie . '!'; // Wyświetli to samo
```

#### Najważniejsze funkcje do pracy z tekstami

1. **strlen()** – Zwraca długość tekstu.

    ```php
    $tekst = "Hello, world!";
    echo strlen($tekst); // Wyświetli: 13
    ```

2. **str_replace()** – Zamienia określone fragmenty tekstu na inne.

    ```php
    $tekst = "kot i pies";
    $nowyTekst = str_replace("kot", "ptak", $tekst);
    echo $nowyTekst; // Wyświetli: ptak i pies
    ```

3. **strpos()** – Znajduje pozycję pierwszego wystąpienia tekstu w ciągu.

    ```php
    $tekst = "Hello, world!";
    echo strpos($tekst, "world"); // Wyświetli: 7
    ```

4. **substr()** – Wycina fragment tekstu, począwszy od danej pozycji.

    ```php
    $tekst = "Hello, world!";
    echo substr($tekst, 0, 5); // Wyświetli: Hello
    ```

5. **strtolower()** i **strtoupper()** – Zamienia tekst na małe lub wielkie litery.

    ```php
    $tekst = "PHP";
    echo strtolower($tekst); // Wyświetli: php
    echo strtoupper($tekst); // Wyświetli: PHP
    ```

6. **trim()** – Usuwa białe znaki (np. spacje, nowe linie) z początku i końca tekstu.

    ```php
    $tekst = "  PHP  ";
    echo trim($tekst); // Wyświetli: PHP
    ```

#### Sklejanie tekstów

Teksty w PHP można łączyć za pomocą kropki (`.`):

```php
$imie = "Anna";
$powitanie = "Cześć, " . $imie . "!";
echo $powitanie; // Wyświetli: Cześć, Anna!
```

#### Praca z danymi użytkownika (np. formularze)

W przypadku pracy z tekstami pochodzącymi od użytkownika (np. z formularza) należy być ostrożnym, by uniknąć ataków (np. SQL Injection). Funkcja `htmlspecialchars()` zamienia specjalne znaki na bezpieczne encje HTML, co pomaga zabezpieczyć aplikację:

```php
$dane = "<script>alert('Niebezpieczny kod');</script>";
$bezpiecznyTekst = htmlspecialchars($dane);
echo $bezpiecznyTekst; // Wyświetli: &lt;script&gt;alert('Niebezpieczny kod');&lt;/script&gt;
```

#### Formatowanie tekstu

PHP umożliwia formatowanie tekstu przy użyciu funkcji `printf()` lub `sprintf()` (ta druga zwraca sformatowany ciąg znaków zamiast go wyświetlać):

```php
$cena = 25.50;
printf("Cena: %.2f zł", $cena); // Wyświetli: Cena: 25.50 zł
```

#### Podsumowanie

Praca z tekstami w PHP jest elastyczna i szybka dzięki szerokiemu zestawowi funkcji. Umożliwia łatwe manipulowanie tekstami, wyszukiwanie i zamianę fragmentów, a także zabezpieczanie danych wprowadzanych przez użytkowników.
