# Rozdział 11: Utility Classes

Klasy pomocnicze (utility classes) to narzędzia do szybkiego stylowania elementów bez pisania własnego CSS. Bootstrap oferuje dziesiątki takich klas.

---

## Marginesy (Margin)

Marginesy dodają odstęp **zewnątrz** elementu.

### Rozmiary:

| Klasa | Rozmiar |
|-------|---------|
| `m-0` | 0 |
| `m-1` | 0.25rem (4px) |
| `m-2` | 0.5rem (8px) |
| `m-3` | 1rem (16px) |
| `m-4` | 1.5rem (24px) |
| `m-5` | 3rem (48px) |
| `m-auto` | Auto (wycentrowanie) |

### Kierunki:

| Klasa | Efekt |
|-------|-------|
| `mt-*` | Margin top (góra) |
| `me-*` | Margin end (prawo w LTR) |
| `mb-*` | Margin bottom (dół) |
| `ms-*` | Margin start (lewo w LTR) |
| `mx-*` | Margin lewo + prawo |
| `my-*` | Margin góra + dół |

```html
<div class="m-3">Margines ze wszystkich stron</div>
<div class="mt-5">Margines tylko z góry (duży)</div>
<div class="mb-4">Margines tylko z dołu</div>
<div class="mx-auto">Wycentrowany element (auto margines)</div>
<div class="ms-auto">Wyrównany do prawej (flex)</div>
```

### Responsywne marginesy:

```html
<!-- Na telefonie: mały margines, na desktopie: duży -->
<div class="m-2 m-md-5">Tekst</div>

<!-- Na telefonie: margines dolny, na tablecie: brak -->
<div class="mb-3 mb-md-0">Tekst</div>
```

| Prefix | Breakpoint |
|--------|------------|
| `m-sm-*` | ≥576px |
| `m-md-*` | ≥768px |
| `m-lg-*` | ≥992px |
| `m-xl-*` | ≥1200px |
| `m-xxl-*` | ≥1400px |

---

## Paddingi (Padding)

Paddingi dodają odstęp **wewnątrz** elementu.

### Rozmiary:

| Klasa | Rozmiar |
|-------|---------|
| `p-0` | 0 |
| `p-1` | 0.25rem (4px) |
| `p-2` | 0.5rem (8px) |
| `p-3` | 1rem (16px) |
| `p-4` | 1.5rem (24px) |
| `p-5` | 3rem (48px) |

### Kierunki:

| Klasa | Efekt |
|-------|-------|
| `pt-*` | Padding top |
| `pe-*` | Padding end |
| `pb-*` | Padding bottom |
| `ps-*` | Padding start |
| `px-*` | Padding lewo + prawo |
| `py-*` | Padding góra + dół |

```html
<div class="p-3">Padding ze wszystkich stron</div>
<div class="px-4">Padding tylko lewo i prawo</div>
<div class="py-5">Padding tylko góra i dół (duży)</div>
```

---

## Display (wyświetlanie)

Kontroluje czy element jest widoczny i jaki ma typ wyświetlania.

```html
<!-- Ukrycie elementu -->
<div class="d-none">Ukryty element</div>
<div class="d-none d-md-block">Ukryty na telefonie, widoczny na tablecie+</div>

<!-- Wyświetlanie jako block -->
<div class="d-block">Element jako block</div>

<!-- Wyświetlanie jako inline -->
<span class="d-inline">Element jako inline</span>

<!-- Wyświetlanie jako inline-block -->
<span class="d-inline-block">Element jako inline-block</span>

<!-- Flexbox -->
<div class="d-flex">Flex container</div>
<div class="d-inline-flex">Inline flex</div>

<!-- Grid -->
<div class="d-grid">Grid container</div>
```

### Ukrywanie na określonych breakpointach:

| Klasa | Ukryty na |
|-------|-----------|
| `d-none` | Zawsze |
| `d-sm-none` | ≥576px |
| `d-md-none` | ≥768px |
| `d-lg-none` | ≥992px |
| `d-xl-none` | ≥1200px |

```html
<!-- Widoczny tylko na telefonie -->
<div class="d-block d-md-none">Tylko na telefonie</div>

<!-- Ukryty tylko na telefonie -->
<div class="d-none d-md-block">Ukryty na telefonie</div>

<!-- Widoczny tylko na desktopie -->
<div class="d-none d-lg-block">Tylko na desktopie</div>
```

---

## Flexbox

```html
<!-- Podstawowy flex -->
<div class="d-flex">Elementy w rzędzie</div>

<!-- Kierunek -->
<div class="d-flex flex-column">Elementy w kolumnie</div>
<div class="d-flex flex-row">Elementy w rzędzie</div>
<div class="d-flex flex-row-reverse">Elementy w rzędzie (odwrotnie)</div>

<!-- Wyrównanie w poprzek (cross-axis) -->
<div class="d-flex align-items-start">Wyrównanie do góry</div>
<div class="d-flex align-items-center">Wyrównanie do środka</div>
<div class="d-flex align-items-end">Wyrównanie do dołu</div>
<div class="d-flex align-items-stretch">Rozciąganie do pełnej wysokości</div>

<!-- Wyrównanie wzdłuż (main-axis) -->
<div class="d-flex justify-content-start">Do lewej</div>
<div class="d-flex justify-content-center">Do środka</div>
<div class="d-flex justify-content-end">Do prawej</div>
<div class="d-flex justify-content-between">Rozłożone równomiernie (bez marginesów na krańcach)</div>
<div class="d-flex justify-content-around">Równomiernie z marginesami</div>
<div class="d-flex justify-content-evenly">Równomiernie z jednakowymi odstępami</div>

<!-- Zawijanie -->
<div class="d-flex flex-wrap">Elementy zawijają się do nowej linii</div>

<!-- Odstęp między elementami -->
<div class="d-flex gap-1">Odstęp 1</div>
<div class="d-flex gap-2">Odstęp 2</div>
<div class="d-flex gap-3">Odstęp 3</div>
```

---

## Text Alignment (wyrównanie tekstu)

```html
<p class="text-start">Do lewej</p>
<p class="text-center">Do środka</p>
<p class="text-end">Do prawej</p>

<!-- Na określonych breakpointach -->
<p class="text-md-center">Centrum od tableta</p>
<p class="text-lg-end">Do prawej od desktopa</p>
```

---

## Float (unoszenie)

```html
<div class="float-start">Unoszę się do lewej</div>
<div class="float-end">Unoszę się do prawej</div>
<div class="float-none">Bez unoszenia</div>
```

---

## Overflow (przelewanie się treści)

```html
<div class="overflow-auto">Treść z scrollbarem gdy za długa</div>
<div class="overflow-hidden">Ukryta nadmiarowa treść</div>
<div class="overflow-visible">Treść widoczna poza kontenerem</div>
<div class="overflow-scroll">Zawsze z scrollbarem</div>
```

---

## Position (pozycjonowanie)

```html
<div class="position-static">Static (domyślne)</div>
<div class="position-relative">Relative</div>
<div class="position-absolute">Absolute</div>
<div class="position-fixed">Fixed</div>
<div class="position-sticky">Sticky</div>
```

### Umiejscowienie:

```html
<!-- Top/Bottom/Start/End -->
<div class="position-absolute top-0 start-0">Lewy górny róg</div>
<div class="position-absolute top-0 end-0">Prawy górny róg</div>
<div class="position-absolute bottom-0 start-0">Lewy dolny róg</div>
<div class="position-absolute bottom-0 end-0">Prawy dolny róg</div>
<div class="position-absolute top-50 start-50 translate-middle">Środek</div>
```

---

## Shadow (cienie)

```html
<div class="shadow-none">Bez cienia</div>
<div class="shadow-sm">Mały cień</div>
<div class="shadow">Normalny cień</div>
<div class="shadow-lg">Duży cień</div>
```

---

## Sizing (rozmiar)

```html
<!-- Szerokość -->
<div class="w-25">25% szerokości</div>
<div class="w-50">50% szerokości</div>
<div class="w-75">75% szerokości</div>
<div class="w-100">100% szerokości</div>
<div class="w-auto">Automatyczna szerokość</div>

<!-- Wysokość -->
<div class="h-25">25% wysokości</div>
<div class="h-50">50% wysokości</div>
<div class="h-75">75% wysokości</div>
<div class="h-100">100% wysokości</div>
<div class="h-auto">Automatyczna wysokość</div>

<!-- Min/Max -->
<div class="mw-100">Maksymalna szerokość 100%</div>
<div class="mh-100">Maksymalna wysokość 100%</div>
```

---

## Stosowanie (z-index)

```html
<div class="z-n1">Pod spodem (z-index: -1)</div>
<div class="z-0">Na poziomie 0</div>
<div class="z-1">Na poziomie 1</div>
<div class="z-2">Na poziomie 2</div>
<div class="z-3">Na poziomie 3</div>
```

---

## Opacity (przezroczystość)

```html
<div class="opacity-100">100% - w pełni widoczny</div>
<div class="opacity-75">75%</div>
<div class="opacity-50">50%</div>
<div class="opacity-25">25%</div>
<div class="opacity-0">0% - niewidoczny</div>
```

---

## Pełny przykład - strona z utility classes

```php
<?php
// utilities.php
$produkty = [
    ['nazwa' => 'Zupa', 'cena' => 12, 'dostepne' => true],
    ['nazwa' => 'Schabowy', 'cena' => 28, 'dostepne' => true],
    ['nazwa' => 'Pierogi', 'cena' => 22, 'dostepne' => false],
    ['nazwa' => 'Szarlotka', 'cena' => 15, 'dostepne' => true],
];
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Utility Classes - Przykłady</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
</head>
<body>

<div class="container py-5">

    <!-- Flexbox: nagłówek z przyciskiem po prawej -->
    <div class="d-flex justify-content-between align-items-center mb-4">
        <h1 class="mb-0">Nasze Menu</h1>
        <a href="#" class="btn btn-primary">
            <i class="bi bi-cart3"></i> Koszyk
            <span class="badge bg-white text-primary ms-1">2</span>
        </a>
    </div>

    <!-- Ukrywanie na różnych ekranach -->
    <div class="alert alert-info d-none d-md-block">
        Ta informacja widoczna jest tylko na tabletach i większych ekranach.
    </div>
    <div class="alert alert-warning d-md-none">
        Ta informacja widoczna jest tylko na telefonach.
    </div>

    <!-- Shadow i padding -->
    <div class="card shadow-lg mb-4">
        <div class="card-body p-4">
            <h5 class="card-title">Dzisiejsza specjalność</h5>
            <p class="card-text mb-0">Żurek z białą kiełbasą - 14 zł</p>
        </div>
    </div>

    <!-- Flex layout z gap -->
    <div class="d-flex flex-wrap gap-3 mb-4">
        <span class="badge bg-primary p-2">Świeże składniki</span>
        <span class="badge bg-success p-2">Dostawa gratis</span>
        <span class="badge bg-info p-2">Rezerwacje online</span>
    </div>

    <!-- Tabela z hover i striped -->
    <div class="table-responsive">
        <table class="table table-striped table-hover">
            <thead class="table-dark">
                <tr>
                    <th>Danie</th>
                    <th>Cena</th>
                    <th class="text-center">Dostępność</th>
                </tr>
            </thead>
            <tbody>
                <?php foreach ($produkty as $produkt): ?>
                    <tr class="<?= $produkt['dostepne'] ? '' : 'table-danger' ?>">
                        <td class="<?= $produkt['dostepne'] ? '' : 'text-decoration-line-through text-muted' ?>">
                            <?= $produkt['nazwa'] ?>
                        </td>
                        <td><?= $produkt['cena'] ?> zł</td>
                        <td class="text-center">
                            <?php if ($produkt['dostepne']): ?>
                                <span class="badge bg-success">Dostępne</span>
                            <?php else: ?>
                                <span class="badge bg-danger">Brak</span>
                            <?php endif; ?>
                        </td>
                    </tr>
                <?php endforeach; ?>
            </tbody>
        </table>
    </div>

    <!-- Position: sticky header -->
    <div class="position-sticky top-0 bg-white py-2 shadow-sm mb-3" style="z-index: 10;">
        <h4 class="mb-0">Sekcja z sticky nagłówkiem</h4>
    </div>

    <!-- D-grid: pełna szerokość przycisków -->
    <div class="d-grid gap-2 d-md-flex justify-content-md-end">
        <button class="btn btn-outline-secondary">Kontynuuj zakupy</button>
        <button class="btn btn-primary">Zamów teraz</button>
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
```

---

## Podsumowanie najczęściej używanych klas

| Klasa | Opis |
|-------|------|
| `m-*` / `mt-*` / `mb-*` / `mx-*` / `my-*` | Marginesy |
| `p-*` / `pt-*` / `pb-*` / `px-*` / `py-*` | Paddingi |
| `d-none` / `d-block` / `d-flex` / `d-grid` | Wyświetlanie |
| `justify-content-*` | Wyrównanie wzdłuż main axis |
| `align-items-*` | Wyrównanie wzdłuż cross axis |
| `flex-wrap` | Zawijanie elementów |
| `gap-*` | Odstęp między elementami |
| `text-start` / `text-center` / `text-end` | Wyrównanie tekstu |
| `text-muted` / `text-primary` / `text-danger` | Kolor tekstu |
| `fw-bold` / `fst-italic` | Pogrubienie / kursywa |
| `shadow-*` | Cień |
| `w-*` / `h-*` | Szerokość / wysokość |
| `position-*` | Pozycjonowanie |
| `overflow-*` | Przelewanie treści |
| `opacity-*` | Przezroczystość |
| `rounded` | Zaokrąglone rogi |
| `visually-hidden` | Ukryty wizualnie (dostępny dla screenreaderów) |

---

## Następny rozdział

→ [Następny: Responsywność i dostosowanie](./12-responsywnosc-i-dostosowanie.md)
