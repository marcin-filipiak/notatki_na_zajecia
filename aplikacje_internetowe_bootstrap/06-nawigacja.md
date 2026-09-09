# Rozdział 6: Nawigacja

Nawigacja to kluczowy element każdej strony. Bootstrap oferuje gotowe komponenty do nawigacji - navbar, tabs, pills, breadcrumb i pagination.

---

## Navbar (pasek nawigacyjny)

Navbar to główny element nawigacyjny na stronie. Jest w pełni responsywny.

```html
<nav class="navbar navbar-expand-lg bg-body-tertiary">
    <div class="container">
        <a class="navbar-brand" href="#">Kuchnia Domowa</a>
        
        <!-- Przycisk hamburger (pojawia się na małych ekranach) -->
        <button class="navbar-toggler" type="button" 
                data-bs-toggle="collapse" data-bs-target="#navbarNav" 
                aria-controls="navbarNav" aria-expanded="false" 
                aria-label="Nawigacja">
            <span class="navbar-toggler-icon"></span>
        </button>
        
        <!-- Menu -->
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav me-auto">
                <li class="nav-item">
                    <a class="nav-link active" aria-current="page" href="#">Strona główna</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="#menu">Menu</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="#o-nas">O nas</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="#kontakt">Kontakt</a>
                </li>
            </ul>
        </div>
    </div>
</nav>
```

### Navbar z wyszukiwarką i przyciskami:

```html
<nav class="navbar navbar-expand-lg bg-dark" data-bs-theme="dark">
    <div class="container">
        <a class="navbar-brand" href="#">
            <i class="bi bi-house-door"></i> Kuchnia Domowa
        </a>
        
        <button class="navbar-toggler" type="button" 
                data-bs-toggle="collapse" data-bs-target="#navbarScroll">
            <span class="navbar-toggler-icon"></span>
        </button>
        
        <div class="collapse navbar-collapse" id="navbarScroll">
            <ul class="navbar-nav me-auto my-2 my-lg-0 navbar-nav-scroll" 
                style="--bs-scroll-height: 100px;">
                <li class="nav-item">
                    <a class="nav-link active" href="#">Strona główna</a>
                </li>
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" role="button" 
                       data-bs-toggle="dropdown" aria-expanded="false">
                        Menu
                    </a>
                    <ul class="dropdown-menu">
                        <li><a class="dropdown-item" href="#">Zupy</a></li>
                        <li><a class="dropdown-item" href="#">Dania główne</a></li>
                        <li><a class="dropdown-item" href="#">Desery</a></li>
                        <li><hr class="dropdown-divider"></li>
                        <li><a class="dropdown-item" href="#">Wszystkie dania</a></li>
                    </ul>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="#">Kontakt</a>
                </li>
            </ul>
            
            <!-- Wyszukiwarka -->
            <form class="d-flex" role="search">
                <input class="form-control me-2" type="search" 
                       placeholder="Szukaj w menu..." aria-label="Szukaj">
                <button class="btn btn-outline-light" type="submit">
                    <i class="bi bi-search"></i>
                </button>
            </form>
            
            <!-- Przycisk -->
            <a href="#" class="btn btn-primary ms-2">
                <i class="bi bi-cart"></i> Zamów
            </a>
        </div>
    </div>
</nav>
```

---

## Tabs (zakładki)

```html
<!-- Podstawowe tabs -->
<ul class="nav nav-tabs" role="tablist">
    <li class="nav-item" role="presentation">
        <button class="nav-link active" data-bs-toggle="tab" 
                data-bs-target="#zupy" type="button" role="tab">
            Zupy
        </button>
    </li>
    <li class="nav-item" role="presentation">
        <button class="nav-link" data-bs-toggle="tab" 
                data-bs-target="#dania" type="button" role="tab">
            Dania główne
        </button>
    </li>
    <li class="nav-item" role="presentation">
        <button class="nav-link" data-bs-toggle="tab" 
                data-bs-target="#desery" type="button" role="tab">
            Desery
        </button>
    </li>
</ul>

<!-- Zawartość tabs -->
<div class="tab-content">
    <div class="tab-pane fade show active" id="zupy" role="tabpanel">
        <div class="p-3">
            <h4>Zupy</h4>
            <p>.lista zup...</p>
        </div>
    </div>
    <div class="tab-pane fade" id="dania" role="tabpanel">
        <div class="p-3">
            <h4>Dania główne</h4>
            <p>.lista dań...</p>
        </div>
    </div>
    <div class="tab-pane fade" id="desery" role="tabpanel">
        <div class="p-3">
            <h4>Desery</h4>
            <p>.lista deserów...</p>
        </div>
    </div>
</div>
```

---

## Pills (zakładki-badges)

```html
<!-- Podstawowe pills -->
<ul class="nav nav-pills mb-3" id="pills-tab" role="tablist">
    <li class="nav-item" role="presentation">
        <button class="nav-link active" data-bs-toggle="pill" 
                data-bs-target="#pills-home" type="button">Wszystkie</button>
    </li>
    <li class="nav-item" role="presentation">
        <button class="nav-link" data-bs-toggle="pill" 
                data-bs-target="#pills-profile" type="button">Popularne</button>
    </li>
    <li class="nav-item" role="presentation">
        <button class="nav-link" data-bs-toggle="pill" 
                data-bs-target="#pills-contact" type="button">Nowości</button>
    </li>
</ul>

<!-- Zawartość pills -->
<div class="tab-content">
    <div class="tab-pane fade show active" id="pills-home">
        <p>Treść zakladki "Wszystkie"</p>
    </div>
    <div class="tab-pane fade" id="pills-profile">
        <p>Treść zakladki "Popularne"</p>
    </div>
    <div class="tab-pane fade" id="pills-contact">
        <p>Treść zakladki "Nowości"</p>
    </div>
</div>
```

### Pills w pionie:

```html
<div class="d-flex align-items-start">
    <div class="nav flex-column nav-pills me-3" role="tablist">
        <button class="nav-link active" data-bs-toggle="pill" 
                data-bs-target="#v-home">Strona główna</button>
        <button class="nav-link" data-bs-toggle="pill" 
                data-bs-target="#v-profile">Profil</button>
        <button class="nav-link" data-bs-toggle="pill" 
                data-bs-target="#v-messages">Wiadomości</button>
    </div>
    <div class="tab-content">
        <div class="tab-pane fade show active" id="v-home">
            <p>Treść strony głównej</p>
        </div>
        <div class="tab-pane fade" id="v-profile">
            <p>Treść profilu</p>
        </div>
        <div class="tab-pane fade" id="v-messages">
            <p>Treść wiadomości</p>
        </div>
    </div>
</div>
```

---

## Breadcrumb (okruszki chleba)

Pokazuje ścieżkę nawigacji:

```html
<nav aria-label="breadcrumb">
    <ol class="breadcrumb">
        <li class="breadcrumb-item"><a href="#">Strona główna</a></li>
        <li class="breadcrumb-item"><a href="#">Menu</a></li>
        <li class="breadcrumb-item"><a href="#">Dania główne</a></li>
        <li class="breadcrumb-item active" aria-current="page">Schabowy</li>
    </ol>
</nav>
```

---

## Pagination (stronicowanie)

```html
<!-- Podstawowe stronicowanie -->
<nav aria-label="Stronicowanie">
    <ul class="pagination">
        <li class="page-item">
            <a class="page-link" href="#">&laquo; Poprzednia</a>
        </li>
        <li class="page-item"><a class="page-link" href="#">1</a></li>
        <li class="page-item"><a class="page-link" href="#">2</a></li>
        <li class="page-item"><a class="page-link" href="#">3</a></li>
        <li class="page-item">
            <a class="page-link" href="#">Następna &raquo;</a>
        </li>
    </ul>
</nav>

<!-- Z aktywną stroną i disabled -->
<nav aria-label="Stronicowanie">
    <ul class="pagination">
        <li class="page-item disabled">
            <a class="page-link" href="#">&laquo;</a>
        </li>
        <li class="page-item active" aria-current="page">
            <a class="page-link" href="#">1</a>
        </li>
        <li class="page-item"><a class="page-link" href="#">2</a></li>
        <li class="page-item"><a class="page-link" href="#">3</a></li>
        <li class="page-item">
            <a class="page-link" href="#">&raquo;</a>
        </li>
    </ul>
</nav>
```

---

## Pełny przykład - strona restauracji z nawigacją

```php
<?php
// index.php - Strona główna restauracji
$tytul = "Kuchnia Domowa";

$menu = [
    'zupy' => [
        'tytul' => 'Zupy',
        'dania' => [
            ['nazwa' => 'Zupa pomidorowa', 'cena' => 12, 'opis' => 'Świeża zupa z grzankami'],
            ['nazwa' => 'Żurek', 'cena' => 14, 'opis' => 'Tradycyjny żurek z białą kiełbasą'],
            ['nazwa' => 'Rosół', 'cena' => 10, 'opis' => 'Rosół z makaronem'],
        ]
    ],
    'glowne' => [
        'tytul' => 'Dania główne',
        'dania' => [
            ['nazwa' => 'Schabowy', 'cena' => 28, 'opis' => 'Z ziemniakami i surówką'],
            ['nazwa' => 'Pierogi ruskie', 'cena' => 22, 'opis' => '8 sztuk z podsmażoną cebulką'],
            ['nazwa' => 'Kotlet schabowy', 'cena' => 26, 'opis' => 'Podany z sałatką'],
        ]
    ],
    'desery' => [
        'tytul' => 'Desery',
        'dania' => [
            ['nazwa' => 'Szarlotka', 'cena' => 15, 'opis' => 'Ciepła z lodami waniliowymi'],
            ['nazwa' => 'Sernik', 'cena' => 16, 'opis' => 'Klasyczny sernik babci'],
        ]
    ]
];
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?= $tytul ?></title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
</head>
<body>

    <!-- NAVBAR -->
    <nav class="navbar navbar-expand-lg bg-dark" data-bs-theme="dark">
        <div class="container">
            <a class="navbar-brand fw-bold" href="#">
                <i class="bi bi-house-door-fill"></i> <?= $tytul ?>
            </a>
            <button class="navbar-toggler" type="button" 
                    data-bs-toggle="collapse" data-bs-target="#mainNav">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="mainNav">
                <ul class="navbar-nav me-auto">
                    <li class="nav-item">
                        <a class="nav-link active" href="#">Strona główna</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="#menu">Menu</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="#kontakt">Kontakt</a>
                    </li>
                </ul>
                <a href="#" class="btn btn-primary">
                    <i class="bi bi-cart3"></i> Zamów online
                </a>
            </div>
        </div>
    </nav>

    <!-- BREADCRUMB -->
    <div class="container mt-3">
        <nav aria-label="breadcrumb">
            <ol class="breadcrumb">
                <li class="breadcrumb-item"><a href="#">Strona główna</a></li>
                <li class="breadcrumb-item active">Menu restauracji</li>
            </ol>
        </nav>
    </div>

    <!-- MENU Z TABS -->
    <section id="menu" class="container my-5">
        <h2 class="text-center mb-4">Nasze Menu</h2>

        <!-- Tabs -->
        <ul class="nav nav-tabs justify-content-center mb-4" role="tablist">
            <?php $first = true; ?>
            <?php foreach ($menu as $klucz => $kategoria): ?>
                <li class="nav-item" role="presentation">
                    <button class="nav-link <?= $first ? 'active' : '' ?>" 
                            data-bs-toggle="tab" 
                            data-bs-target="#tab-<?= $klucz ?>" 
                            type="button">
                        <?= $kategoria['tytul'] ?>
                    </button>
                </li>
            <?php $first = false; endforeach; ?>
        </ul>

        <!-- Zawartość tabs -->
        <div class="tab-content">
            <?php $first = true; ?>
            <?php foreach ($menu as $klucz => $kategoria): ?>
                <div class="tab-pane fade <?= $first ? 'show active' : '' ?>" 
                     id="tab-<?= $klucz ?>">
                    <div class="row g-3">
                        <?php foreach ($kategoria['dania'] as $danie): ?>
                            <div class="col-12 col-md-6 col-lg-4">
                                <div class="card h-100">
                                    <div class="card-body">
                                        <div class="d-flex justify-content-between">
                                            <h5 class="card-title"><?= $danie['nazwa'] ?></h5>
                                            <span class="badge bg-primary">
                                                <?= $danie['cena'] ?> zł
                                            </span>
                                        </div>
                                        <p class="card-text text-muted">
                                            <?= $danie['opis'] ?>
                                        </p>
                                        <a href="#" class="btn btn-outline-primary btn-sm">
                                            <i class="bi bi-cart-plus"></i> Zamów
                                        </a>
                                    </div>
                                </div>
                            </div>
                        <?php endforeach; ?>
                    </div>
                </div>
            <?php $first = false; endforeach; ?>
        </div>
    </section>

    <!-- PAGINATION -->
    <div class="container my-4">
        <nav aria-label="Stronicowanie menu">
            <ul class="pagination justify-content-center">
                <li class="page-item disabled">
                    <span class="page-link">&laquo;</span>
                </li>
                <li class="page-item active"><span class="page-link">1</span></li>
                <li class="page-item"><a class="page-link" href="#">2</a></li>
                <li class="page-item"><a class="page-link" href="#">3</a></li>
                <li class="page-item">
                    <a class="page-link" href="#">&raquo;</a>
                </li>
            </ul>
        </nav>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
```

---

## Podsumowanie klas

| Klasa | Opis |
|-------|------|
| `navbar` | Podstawowy pasek nawigacyjny |
| `navbar-expand-*` | Rozmiar ekranu od którego navbar się rozwija |
| `navbar-brand` | Logo/nazwa marki |
| `navbar-toggler` | Przycisk hamburger |
| `nav-link` | Link w nawigacji |
| `nav-tabs` | Zakładki (tabs) |
| `nav-pills` | Zakładki-badges (pills) |
| `breadcrumb` | Ścieżka nawigacji |
| `pagination` | Stronicowanie |
| `dropdown` | Menu rozwijane |

---

## Następny rozdział

→ [Następny: Karty (Cards)](./07-karty.md)
