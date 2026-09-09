# Rozdział 3: Typografia i kolory

Bootstrap dostarcza gotowe style dla tekstu, nagłówków, list i kolorów. Dzięki temu Twój tekst wygląda profesjonalnie bez pisania własnego CSS.

---

## Nagłówki

Bootstrap resetuje style nagłówków HTML i dodaje payload:

```html
<h1>Nagłówek H1</h1>
<h2>Nagłówek H2</h2>
<h3>Nagłówek H3</h3>
<h4>Nagłówek H4</h4>
<h5>Nagłówek H5</h5>
<h6>Nagłówek H6</h6>
```

### Display headings - większe nagłówki:

```html
<h1 class="display-1">Bardzo duży nagłówek</h1>
<h1 class="display-2">Duży nagłówek</h1>
<h1 class="display-3">Nagłówek display</h1>
<h1 class="display-4">Nagłówek display</h1>
<h1 class="display-5">Nagłówek display</h1>
<h1 class="display-6">Nagłówek display</h1>
```

### Nagłówki z PHP:

```php
<?php
$sekcje = [
    ['tytul' => 'Nasze Menu', 'poziom' => 1],
    ['tytul' => 'Zupy', 'poziom' => 2],
    ['tytul' => 'Dania Główne', 'poziom' => 2],
];

foreach ($sekcje as $sekcja):
?>
    <h<?= $sekcja['poziom'] ?>>
        <?= $sekcja['tytul'] ?>
    </h<?= $sekcja['poziom'] ?>>
<?php endforeach; ?>
```

---

## Tekst

### Podstawowe style tekstu:

```html
<p class="lead">Tekst wyróżniony (lead) - większy i grubszy</p>
<p class="small">Tekst mały (small)</p>
<p class="text-muted">Tekst wyciszony (muted) - szary kolor</p>
<p class="fst-italic">Tekst kursywą</p>
<p class="fst-normal">Tekst normalny (bez kursywy)</p>
<p class="fw-bold">Tekst pogrubiony</p>
<p class="fw-semibold">Tekst semi-bold</p>
<p class="fw-light">Tekst lekki</p>
```

### Tekst这家伙 -装饰器:

```html
<p class="text-decoration-none">Bez dekoracji</p>
<p class="text-decoration-underline">Podkreślony</p>
<p class="text-decoration-line-through">Przekreślony</p>
```

---

## Wyrównanie tekstu

```html
<p class="text-start">Wyrównany do lewej</p>
<p class="text-center">Wycentrowany</p>
<p class="text-end">Wyrównany do prawej</p>

<!-- Na konkretnych breakpointach -->
<p class="text-md-center">Centrum tylko na tabletach i większych</p>
<p class="text-lg-end">Do prawej tylko na desktopach</p>
```

---

## Listy

Bootstrap stylizuje listy HTML:

```html
<!-- Lista nieuporządkowana -->
<ul class="list-unstyled">
    <li>Element 1</li>
    <li>Element 2</li>
    <li>Element 3</li>
</ul>

<!-- Lista inline (w jednej linii) -->
<ul class="list-inline">
    <li class="list-inline-item">Element 1</li>
    <li class="list-inline-item">Element 2</li>
    <li class="list-inline-item">Element 3</li>
</ul>

<!-- Lista z opisami -->
<dl class="row">
    <dt class="col-sm-3">Termin 1</dt>
    <dd class="col-sm-9">Opis terminu 1</dd>

    <dt class="col-sm-3">Termin 2</dt>
    <dd class="col-sm-9">Opis terminu 2</dd>
</dl>
```

### Lista menu z PHP:

```php
<?php
$ingredients = ['Mąka', 'Jajka', 'Mleko', 'Masło', 'Sól'];
?>

<ul class="list-group list-group-flush">
    <?php foreach ($ingredients as $skladnik): ?>
        <li class="list-group-item d-flex justify-content-between align-items-center">
            <?= $skladnik ?>
            <span class="badge bg-primary rounded-pill">1</span>
        </li>
    <?php endforeach; ?>
</ul>
```

---

## Kolory tła (Backgrounds)

Bootstrap oferuje wbudowaną paletę kolorów:

```html
<div class="bg-primary p-3 text-white">Primary (główny kolor)</div>
<div class="bg-secondary p-3 text-white">Secondary</div>
<div class="bg-success p-3 text-white">Success (sukces/zielony)</div>
<div class="bg-danger p-3 text-white">Danger (błąd/czerwony)</div>
<div class="bg-warning p-3 text-dark">Warning (ostrzeżenie/żółty)</div>
<div class="bg-info p-3 text-white">Info (informacja/niebieski)</div>
<div class="bg-light p-3">Light (jasny)</div>
<div class="bg-dark p-3 text-white">Dark (ciemny)</div>
<div class="bg-body-secondary p-3">Body secondary</div>
<div class="bg-body-tertiary p-3">Body tertiary</div>
<div class="bg-white p-3">Biały</div>
<div class="bg-black p-3 text-white">Czarny</div>
```

> **Klasa `p-3`** dodaje padding (odstęp wewnętrzny) ze wszystkich stron.

---

## Kolory tekstu

```html
<p class="text-primary">Tekst primary</p>
<p class="text-secondary">Tekst secondary</p>
<p class="text-success">Tekst success (zielony)</p>
<p class="text-danger">Tekst danger (czerwony)</p>
<p class="text-warning">Tekst warning (żółty)</p>
<p class="text-info">Tekst info</p>
<p class="text-light">Tekst light</p>
<p class="text-dark">Tekst dark</p>
<p class="text-body">Tekst body</p>
<p class="text-white">Tekst biały</p>
<p class="text-black-50">Tekst czarny 50% przezroczystości</p>
<p class="text-white-50">Tekst biały 50% przezroczystości</p>
```

---

## Kolorystyka Unicode i gradient

```html
<!-- Unicode kolorystyka -->
<div class="text-bg-primary p-3">Tło primary, tekst biały automatycznie</div>
<div class="text-bg-success p-3">Tło success, tekst biały automatycznie</div>
<div class="text-bg-warning p-3">Tło warning, tekst ciemny automatycznie</div>
```

> **`text-bg-*`** to kombinacja `bg-*` + automatyczny kolor tekstu (biały lub ciemny w zależności od jasności tła).

---

## Separatory (Dividers)

```html
<hr class="my-4">

<!-- Grubszy separator -->
<hr class="border border-2 border-primary">

<!-- Separator z tekstem -->
<div class="d-flex align-items-center">
    <hr class="flex-grow-1">
    <span class="px-3 text-muted">Lub</span>
    <hr class="flex-grow-1">
</div>
```

---

## Blockquote - cytat

```html
<figure class="text-center">
    <blockquote class="blockquote">
        <p>Jedzenie to język, którym wszyscy rozumieją.</p>
    </blockquote>
    <figcaption class="blockquote-footer">
        Nieznany kucharz
    </figcaption>
</figure>
```

---

## Pełny przykład - sekcja "O nas" restauracji

```php
<?php
// info.php
$fakty = [
    ['wartosc' => '15+', 'opis' => 'Lat doświadczenia'],
    ['wartosc' => '500+', 'opis' => 'Zadowolonych klientów miesięcznie'],
    ['wartosc' => '50', 'opis' => 'Potraw w menu'],
    ['wartosc' => '4.8', 'opis' => 'Średnia ocena Google'],
];
?>

<section class="bg-light py-5">
    <div class="container">
        <div class="row">
            <div class="col-12 col-md-6">
                <h2 class="display-5 fw-bold">O Naszej Restauracji</h2>
                <p class="lead">
                    Kuchnia Domowa to miejsce, gdzie tradycja spotyka się z nowoczesnością.
                </p>
                <p class="text-muted">
                    Od ponad 15 lat serwujemy domowe obiady przygotowywane ze świeżych, 
                    lokalnych składników. Nasze dania to przepisy przekazywane z pokolenia 
                    na pokolenie, dostosowane do współczesnych gustów.
                </p>
                <p>
                    Wierzymy, że <strong>dobry posiłek</strong> to nie tylko smak, 
                    ale también <em>doświadczenie</em> i <em>atmosfera</em>.
                </p>
            </div>

            <div class="col-12 col-md-6">
                <div class="row g-3">
                    <?php foreach ($fakty as $fakt): ?>
                        <div class="col-6">
                            <div class="card text-center border-0 bg-white shadow-sm">
                                <div class="card-body">
                                    <h3 class="display-6 fw-bold text-primary">
                                        <?= $fakt['wartosc'] ?>
                                    </h3>
                                    <p class="text-muted mb-0">
                                        <?= $fakt['opis'] ?>
                                    </p>
                                </div>
                            </div>
                        </div>
                    <?php endforeach; ?>
                </div>
            </div>
        </div>
    </div>
</section>
```

---

## Klasy do zapamiętania

| Klasa | Efekt |
|-------|-------|
| `display-1` do `display-6` | Bardzo duże nagłówki |
| `lead` | Większy tekst akapitu |
| `text-muted` | Szary kolor tekstu |
| `text-bg-*` | Tło + automatyczny kolor tekstu |
| `bg-*` | Kolor tła |
| `text-*` | Kolor tekstu |
| `fw-bold` | Pogrubienie |
| `fst-italic` | Kursywa |
| `list-unstyled` | Lista bez znaczników |
| `list-inline` | Lista w jednej linii |

---

## Następny rozdział

→ [Następny: Przyciski (Buttons)](./04-przyciski.md)
