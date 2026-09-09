# Rozdział 10: Komponenty dodatkowe

W tym rozdziale poznasz dodatkowe komponenty Bootstrapa: accordion, carousel, badge, dropdown, offcanvas, collapse i inne.

---

## Accordion (harmonijka)

Accordion to lista rozwijalnych sekcji - jedna na raz może być otwarta.

```html
<div class="accordion" id="accordionExample">
    <!-- Sekcja 1 - otwarta -->
    <div class="accordion-item">
        <h2 class="accordion-header">
            <button class="accordion-button" type="button" 
                    data-bs-toggle="collapse" data-bs-target="#collapseOne" 
                    aria-expanded="true" aria-controls="collapseOne">
                Jak złożyć zamówienie?
            </button>
        </h2>
        <div id="collapseOne" class="accordion-collapse collapse show" 
             data-bs-parent="#accordionExample">
            <div class="accordion-body">
                Aby złożyć zamówienie, wybierz dania z menu i kliknij 
                "Zamów online". Następnie wypełnij formularz z danymi 
                dostawy i potwierdź zamówienie.
            </div>
        </div>
    </div>

    <!-- Sekcja 2 - zamknięta -->
    <div class="accordion-item">
        <h2 class="accordion-header">
            <button class="accordion-button collapsed" type="button" 
                    data-bs-toggle="collapse" data-bs-target="#collapseTwo" 
                    aria-expanded="false" aria-controls="collapseTwo">
                Ile trwa dostawa?
            </button>
        </h2>
        <div id="collapseTwo" class="accordion-collapse collapse" 
             data-bs-parent="#accordionExample">
            <div class="accordion-body">
                Standardowa dostawa trwa od 30 do 45 minut. 
                W godzinach szczytu może to potrwać do godziny.
            </div>
        </div>
    </div>

    <!-- Sekcja 3 -->
    <div class="accordion-item">
        <h2 class="accordion-header">
            <button class="accordion-button collapsed" type="button" 
                    data-bs-toggle="collapse" data-bs-target="#collapseThree" 
                    aria-expanded="false" aria-controls="collapseThree">
                Jakie metody płatności akceptujecie?
            </button>
        </h2>
        <div id="collapseThree" class="accordion-collapse collapse" 
             data-bs-parent="#accordionExample">
            <div class="accordion-body">
                Akceptujemy płatność gotówką przy odbiorze, 
                kartą płatniczą, BLIK oraz przelewem bankowym.
            </div>
        </div>
    </div>
</div>
```

### Accordion z PHP:

```php
<?php
// faq.php
$faq = [
    ['pytanie' => 'Jak złożyć zamówienie?', 'odpowiedz' => 'Wybierz dania z menu...'],
    ['pytanie' => 'Ile trwa dostawa?', 'odpowiedz' => 'Od 30 do 45 minut...'],
    ['pytanie' => 'Jakie metody płatności?', 'odpowiedz' => 'Gotówka, karta, BLIK...'],
    ['pytanie' => 'Czy mogę anulować zamówienie?', 'odpowiedz' => 'Tak, do 10 minut od złożenia.'],
];
?>

<div class="accordion" id="faqAccordion">
    <?php foreach ($faq as $i => $item): ?>
        <div class="accordion-item">
            <h2 class="accordion-header">
                <button class="accordion-button <?= $i > 0 ? 'collapsed' : '' ?>" 
                        type="button" data-bs-toggle="collapse" 
                        data-bs-target="#faq<?= $i ?>" 
                        aria-expanded="<?= $i === 0 ? 'true' : 'false' ?>">
                    <?= $item['pytanie'] ?>
                </button>
            </h2>
            <div id="faq<?= $i ?>" 
                 class="accordion-collapse collapse <?= $i === 0 ? 'show' : '' ?>" 
                 data-bs-parent="#faqAccordion">
                <div class="accordion-body">
                    <?= $item['odpowiedz'] ?>
                </div>
            </div>
        </div>
    <?php endforeach; ?>
</div>
```

---

## Carousel (karuzela/slajder)

### Podstawowa karuzela ze zdjęciami:

```html
<div id="myCarousel" class="carousel slide" data-bs-ride="carousel">
    <!-- Indicators (kropki) -->
    <div class="carousel-indicators">
        <button type="button" data-bs-target="#myCarousel" data-bs-slide-to="0" 
                class="active" aria-current="true"></button>
        <button type="button" data-bs-target="#myCarousel" 
                data-bs-slide-to="1"></button>
        <button type="button" data-bs-target="#myCarousel" 
                data-bs-slide-to="2"></button>
    </div>

    <!-- Slajdy -->
    <div class="carousel-inner">
        <div class="carousel-item active">
            <img src="https://via.placeholder.com/1200x400?text=Slajd+1" 
                 class="d-block w-100" alt="Slajd 1">
            <div class="carousel-caption d-none d-md-block">
                <h5>Pierwszy slajd</h5>
                <p>Opis pierwszego slajdu.</p>
            </div>
        </div>
        <div class="carousel-item">
            <img src="https://via.placeholder.com/1200x400?text=Slajd+2" 
                 class="d-block w-100" alt="Slajd 2">
            <div class="carousel-caption d-none d-md-block">
                <h5>Drugi slajd</h5>
                <p>Opis drugiego slajdu.</p>
            </div>
        </div>
        <div class="carousel-item">
            <img src="https://via.placeholder.com/1200x400?text=Slajd+3" 
                 class="d-block w-100" alt="Slajd 3">
            <div class="carousel-caption d-none d-md-block">
                <h5>Trzeci slajd</h5>
                <p>Opis trzeciego slajdu.</p>
            </div>
        </div>
    </div>

    <!-- Strzałki nawigacyjne -->
    <button class="carousel-control-prev" type="button" 
            data-bs-target="#myCarousel" data-bs-slide="prev">
        <span class="carousel-control-prev-icon" aria-hidden="true"></span>
        <span class="visually-hidden">Poprzedni</span>
    </button>
    <button class="carousel-control-next" type="button" 
            data-bs-target="#myCarousel" data-bs-slide="next">
        <span class="carousel-control-next-icon" aria-hidden="true"></span>
        <span class="visually-hidden">Następny</span>
    </button>
</div>
```

### Karuzela z PHP:

```php
<?php
// carousel.php
$slajdy = [
    ['obrazek' => 'https://via.placeholder.com/1200x400?text=Zupy', 'tytul' => 'Świeże Zupy', 'opis' => 'Codziennie nowe zupy sezonowe'],
    ['obrazek' => 'https://via.placeholder.com/1200x400?text=Dania+główne', 'tytul' => 'Dania Główne', 'opis' => 'Tradycyjne polskie smaki'],
    ['obrazek' => 'https://via.placeholder.com/1200x400?text=Desery', 'tytul' => 'Desery', 'opis' => 'Domowe wypieki i ciasta'],
];
?>

<div id="restauracjaCarousel" class="carousel slide" data-bs-ride="carousel">
    <div class="carousel-indicators">
        <?php foreach ($slajdy as $i => $slajd): ?>
            <button type="button" data-bs-target="#restauracjaCarousel" 
                    data-bs-slide-to="<?= $i ?>" 
                    class="<?= $i === 0 ? 'active' : '' ?>" 
                    aria-current="<?= $i === 0 ? 'true' : 'false' ?>">
            </button>
        <?php endforeach; ?>
    </div>

    <div class="carousel-inner">
        <?php foreach ($slajdy as $i => $slajd): ?>
            <div class="carousel-item <?= $i === 0 ? 'active' : '' ?>">
                <img src="<?= $slajd['obrazek'] ?>" class="d-block w-100" 
                     alt="<?= $slajd['tytul'] ?>">
                <div class="carousel-caption d-none d-md-block bg-dark bg-opacity-50 rounded p-3">
                    <h3><?= $slajd['tytul'] ?></h3>
                    <p><?= $slajd['opis'] ?></p>
                </div>
            </div>
        <?php endforeach; ?>
    </div>

    <button class="carousel-control-prev" type="button" 
            data-bs-target="#restauracjaCarousel" data-bs-slide="prev">
        <span class="carousel-control-prev-icon"></span>
    </button>
    <button class="carousel-control-next" type="button" 
            data-bs-target="#restauracjaCarousel" data-bs-slide="next">
        <span class="carousel-control-next-icon"></span>
    </button>
</div>
```

---

## Badge (etykietka)

Badge to mała etykietka do oznaczania statusów, ilości itp.

```html
<!-- Podstawowe badge -->
<span class="badge bg-primary">Primary</span>
<span class="badge bg-secondary">Secondary</span>
<span class="badge bg-success">Success</span>
<span class="badge bg-danger">Danger</span>
<span class="badge bg-warning text-dark">Warning</span>
<span class="badge bg-info">Info</span>
<span class="badge bg-light text-dark">Light</span>
<span class="badge bg-dark">Dark</span>

<!-- Rounded pill badge -->
<span class="badge rounded-pill bg-primary">Nowe</span>
<span class="badge rounded-pill bg-danger">3</span>

<!-- Badge w linku -->
<a href="#" class="badge bg-primary text-decoration-none">
    Kategoria <span class="badge bg-white text-primary">12</span>
</a>

<!-- Badge z przycisku koszyka -->
<button class="btn btn-outline-primary position-relative">
    <i class="bi bi-cart3"></i> Koszyk
    <span class="position-absolute top-0 start-100 translate-middle badge rounded-pill bg-danger">
        3
    </span>
</button>
```

---

## Dropdown (menu rozwijane)

### Podstawowy dropdown:

```html
<div class="dropdown">
    <button class="btn btn-secondary dropdown-toggle" type="button" 
            data-bs-toggle="dropdown" aria-expanded="false">
        Opcje menu
    </button>
    <ul class="dropdown-menu">
        <li><a class="dropdown-item" href="#">Akcja 1</a></li>
        <li><a class="dropdown-item" href="#">Akcja 2</a></li>
        <li><a class="dropdown-item" href="#">Akcja 3</a></li>
        <li><hr class="dropdown-divider"></li>
        <li><a class="dropdown-item text-danger" href="#">Usuń</a></li>
    </ul>
</div>
```

### Dropdown z formularzem:

```html
<div class="dropdown">
    <button class="btn btn-primary dropdown-toggle" type="button" 
            data-bs-toggle="dropdown">
        Filtruj menu
    </button>
    <div class="dropdown-menu dropdown-menu-end p-3" style="width: 300px;">
        <form>
            <div class="mb-2">
                <label class="form-label small">Kategoria</label>
                <select class="form-select form-select-sm">
                    <option>Wszystkie</option>
                    <option>Zupy</option>
                    <option>Dania główne</option>
                    <option>Desery</option>
                </select>
            </div>
            <div class="mb-2">
                <label class="form-label small">Cena do:</label>
                <input type="range" class="form-range" min="0" max="50">
            </div>
            <button type="submit" class="btn btn-primary btn-sm w-100">
                Zastosuj
            </button>
        </form>
    </div>
</div>
```

---

## Offcanvas (panel boczny)

Panel wysuwany z boku ekranu:

```html
<!-- Przycisk otwierający -->
<button class="btn btn-primary" type="button" data-bs-toggle="offcanvas" 
        data-bs-target="#offcanvasRight">
    Otwórz panel
</button>

<!-- Offcanvas z prawej -->
<div class="offcanvas offcanvas-end" tabindex="-1" id="offcanvasRight" 
     aria-labelledby="offcanvasRightLabel">
    <div class="offcanvas-header">
        <h5 class="offcanvas-title" id="offcanvasRightLabel">Panel boczny</h5>
        <button type="button" class="btn-close" data-bs-dismiss="offcanvas" 
                aria-label="Zamknij"></button>
    </div>
    <div class="offcanvas-body">
        <p>Treść panelu bocznego.</p>
        <ul class="list-group list-group-flush">
            <li class="list-group-item">Opcja 1</li>
            <li class="list-group-item">Opcja 2</li>
            <li class="list-group-item">Opcja 3</li>
        </ul>
    </div>
</div>
```

### Warianty offcanvas:

```html
<!-- Z lewej -->
<div class="offcanvas offcanvas-start" tabindex="-1">...</div>

<!-- Z góry -->
<div class="offcanvas offcanvas-top" tabindex="-1">...</div>

<!-- Z dołu -->
<div class="offcanvas offcanvas-bottom" tabindex="-1">...</div>
```

---

## Collapse (zwijanie/rozwijanie)

```html
<!-- Przycisk przełączający -->
<button class="btn btn-primary" type="button" data-bs-toggle="collapse" 
        data-bs-target="#collapseContent">
    Pokaż więcej
</button>

<!-- Ukryta treść -->
<div class="collapse" id="collapseContent">
    <div class="card card-body mt-2">
        Ta treść jest ukryta i pokazuje się po kliknięciu przycisku.
        Możesz tu umieścić dowolny HTML.
    </div>
</div>
```

---

## Placeholder (skeleton loading)

Animowane szkielety ładowania:

```html
<!-- Podstawowy placeholder -->
<div class="placeholder-glow">
    <span class="placeholder col-12"></span>
</div>

<!-- Placeholder karty -->
<div class="card" aria-hidden="true">
    <img src="..." class="card-img-top" alt="...">
    <div class="card-body">
        <h5 class="card-title placeholder-glow">
            <span class="placeholder col-6"></span>
        </h5>
        <p class="card-text placeholder-glow">
            <span class="placeholder col-7"></span>
            <span class="placeholder col-4"></span>
            <span class="placeholder col-4"></span>
            <span class="placeholder col-6"></span>
        </p>
        <a class="btn btn-primary disabled placeholder col-6" 
           aria-disabled="true"></a>
    </div>
</div>
```

---

## ScrollSpy - automatyczne podświetlanie nawigacji

```html
<body data-bs-spy="scroll" data-bs-target="#navbar-example2" 
      data-bs-root-margin="0px 0px -40%" data-bs-smooth-scroll="true">
    
    <nav id="navbar-example2" class="navbar navbar-dark bg-dark">
        <div class="container">
            <a class="navbar-brand" href="#">Menu</a>
            <ul class="nav nav-pills">
                <li class="nav-item">
                    <a class="nav-link" href="#sekcja1">Sekcja 1</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="#sekcja2">Sekcja 2</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="#sekcja3">Sekcja 3</a>
                </li>
            </ul>
        </div>
    </nav>

    <div class="container my-5">
        <div id="sekcja1" style="height: 400px;">
            <h2>Sekcja 1</h2>
            <p>Treść sekcji 1...</p>
        </div>
        <div id="sekcja2" style="height: 400px;">
            <h2>Sekcja 2</h2>
            <p>Treść sekcji 2...</p>
        </div>
        <div id="sekcja3" style="height: 400px;">
            <h2>Sekcja 3</h2>
            <p>Treść sekcji 3...</p>
        </div>
    </div>
</body>
```

---

## Podsumowanie

| Komponent | Klasa | Opis |
|-----------|-------|------|
| Accordion | `accordion` | Lista rozwijalnych sekcji |
| Carousel | `carousel` | Karuzela/slajder |
| Badge | `badge` | Mała etykietka |
| Badge | `rounded-pill` | Zaokrąglony badge |
| Dropdown | `dropdown` | Menu rozwijane |
| Offcanvas | `offcanvas` | Panel boczny |
| Collapse | `collapse` | Zwijanie/rozwijanie treści |
| Placeholder | `placeholder` | Szkielet ładowania |
| ScrollSpy | `data-bs-spy` | Auto-podświetlanie nawigacji |

---

## Następny rozdział

→ [Następny: Utility Classes](./11-utility-classes.md)
