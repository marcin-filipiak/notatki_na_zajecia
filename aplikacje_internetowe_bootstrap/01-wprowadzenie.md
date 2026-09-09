# Rozdział 1: Wprowadzenie do Bootstrap

## Czym jest Bootstrap?

Bootstrap to najpopularniejszy framework CSS na świecie. Został stworzony przez firmę Twitter i udostępniony jako projekt open-source. Dzięki niemu tworzysz responsywne (dostosowujące się do rozmiaru ekranu) interfejsy bez pisania zaawansowanego CSS-a od zera.

**Co daje Ci Bootstrap:**
- System siatki (grid) do układania elementów
- Gotowe komponenty (przyciski, formularze, nawigacje, karty)
- Klasy pomocnicze (marginesy, paddingi, kolory)
- Responsywność - strona wygląda dobrze na telefonie, tablecie i komputerze

---

## Instalacja Bootstrap

### Metoda 1: CDN (najszybsza)

Wklej te trzy linki w sekcji `<head>` swojego pliku HTML/PHP:

```html
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Moja strona</title>

    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" 
          rel="stylesheet" 
          integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YcnS/1M6CVok9NtX4pE1DSIH5VHzl5pQ4zH" 
          crossorigin="anonymous">
</head>
<body>

    <!-- Bootstrap JS (Bundle z Popper) -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" 
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" 
            crossorigin="anonymous"></script>
</body>
</html>
```

> **Co to jest CDN?** Content Delivery Network - serwer (np. jsDelivr) udostępnia pliki Bootstrapa. Nie musisz niczego pobierać na swój komputer.

### Metoda 2: Pobranie plików lokalnie

```bash
# Pobierz Bootstrap
curl -LO https://github.com/twbs/bootstrap/releases/download/v5.3.3/bootstrap-5.3.3-dist.zip
unzip bootstrap-5.3.3-dist.zip
```

Następnie wklej pliki do katalogu projektu:

```
moja-strona/
├── css/
│   └── bootstrap.min.css
├── js/
│   └── bootstrap.bundle.min.js
└── index.php
```

I podłącz je lokalnie:

```html
<link href="css/bootstrap.min.css" rel="stylesheet">
<script src="js/bootstrap.bundle.min.js"></script>
```

---

## Podstawowa struktura szablonu PHP/HTML

Oto szablon startowy, którego będziemy używać throughout cały podręcznik:

```php
<?php
// index.php - Podstawowy szablon Bootstrap 5
$tytul = "Kuchnia Domowa";
$opis = "Najlepsze domowe obiady w mieście";
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?= $tytul ?></title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" 
          rel="stylesheet">
</head>
<body>

    <div class="container">
        <h1><?= $tytul ?></h1>
        <p><?= $opis ?></p>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
```

### Wyjaśnienie kluczowych elementów:

| Element | Znaczenie |
|---------|-----------|
| `meta viewport` | Wymagany dla responsywności - informuje przeglądarkę o szerokości urządzenia |
| `container` | Klasa Bootstrapa - tworzy kontener z max-width i wycentrowaną treścią |
| `<?= $zmienna ?>` | Skrócony zapis PHP do wyświetlania zmiennej w HTML |

---

## Kontener (Container)

Bootstrap oferuje trzy rodzaje kontenerów:

```html
<!-- Pełna szerokość z marginesami -->
<div class="container">...</div>

<!-- Szerokość 100% na wszystkich rozmiarach -->
<div class="container-fluid">...</div>

<!-- Szerokość 100% do breakpoints, potem max-width -->
<div class="container-sm">...</div>
<div class="container-md">...</div>
<div class="container-lg">...</div>
<div class="container-xl">...</div>
<div class="container-xxl">...</div>
```

**Przykład z PHP:**

```php
<?php
$sekcje = [
    'menu' => 'Nasze Menu',
    'o_nas' => 'O Nas',
    'kontakt' => 'Kontakt'
];
?>

<div class="container">
    <?php foreach ($sekcje as $id => $tytul): ?>
        <section id="<?= $id ?>">
            <h2><?= $tytul ?></h2>
        </section>
    <?php endforeach; ?>
</div>
```

---

## Ćwiczenie praktyczne

Utwórz plik `index.php` z podstawowym szablonem i wyświetl w nim:

```php
<?php
$restauracja = [
    'nazwa' => 'Kuchnia Domowa',
    'adres' => 'ul. Przykładowa 10, Warszawa',
    'telefon' => '+48 123 456 789',
    'godziny' => 'Pon-Pt: 10:00-21:00, Sob: 11:00-20:00'
];
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?= $restauracja['nazwa'] ?></title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" 
          rel="stylesheet">
</head>
<body>

    <div class="container mt-5">
        <div class="text-center">
            <h1><?= $restauracja['nazwa'] ?></h1>
            <p class="lead"><?= $restauracja['adres'] ?></p>
            <p>Tel: <?= $restauracja['telefon'] ?></p>
            <p>Godziny otwarcia: <?= $restauracja['godziny'] ?></p>
        </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
```

> **Klasy użyte tutaj:**
> - `mt-5` - margin-top (górny margines) w rozmiarze 5
> - `text-center` - centruje tekst
> - `lead` - powiększa tekst akapitu

---

## Następny rozdział

W następnym rozdziale poznamy **system siatki (Grid)**, który jest fundamentem układania treści w Bootstrapie.

→ [Następny: System siatki (Grid)](./02-siatka.md)
