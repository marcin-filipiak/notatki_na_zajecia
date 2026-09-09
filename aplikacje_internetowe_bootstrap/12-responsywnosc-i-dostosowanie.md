# Rozdział 12: Responsywność i dostosowanie

Responsywność to zdolność strony do automatycznego dostosowywania się do rozmiaru ekranu. Bootstrap jest z natury responsywny, ale możesz dostosować jego zachowanie.

---

## Zasada mobile-first

Bootstrap używa podejścia **mobile-first** - style pisane są najpierw dla telefonów, a potem rozszerzane na większe ekrany.

```html
<!-- Domyślnie (telefon): kolumna pełna szerokość -->
<!-- Od tableta (md): dwie kolumny -->
<!-- Od desktopa (lg): trzy kolumny -->
<div class="row">
    <div class="col-12 col-md-6 col-lg-4">Kolumna 1</div>
    <div class="col-12 col-md-6 col-lg-4">Kolumna 2</div>
    <div class="col-12 col-md-6 col-lg-4">Kolumna 3</div>
</div>
```

---

## Breakpointy (punkty przejścia)

Bootstrap dzieli ekran na 5 breakpointów:

| Nazwa | Rozmiar | Typowy sprzęt |
|-------|---------|---------------|
| xs | <576px | Telefon w pionie |
| sm | ≥576px | Telefon w poziomie |
| md | ≥768px | Tablet |
| lg | ≥992px | Mały desktop |
| xl | ≥1200px | Duży desktop |
| xxl | ≥1400px | Bardzo duży monitor |

---

## Ukrywanie/pokazywanie treści

```html
<!-- Widoczny tylko na telefonach -->
<div class="d-block d-sm-none">Tylko telefon</div>

<!-- Ukryty na telefonach -->
<div class="d-none d-sm-block">Ukryty na telefonie</div>

<!-- Widoczny od tableta wzwyż -->
<div class="d-none d-md-block">Od tableta</div>

<!-- Widoczny tylko na desktopie -->
<div class="d-none d-lg-block">Tylko desktop</div>

<!-- Widoczny na telefonie i tablecie, ukryty na desktopie -->
<div class="d-block d-lg-none">Telefon i tablet</div>
```

---

## Responsive utilities w praktyce

### Ukrywanie elementów nawigacji:

```html
<!-- Na telefonie: hamburger, na desktopie: pełne menu -->
<nav class="navbar navbar-expand-lg">
    <div class="container">
        <a class="navbar-brand" href="#">Logo</a>
        
        <!-- Tylko na telefonie: przycisk koszyka -->
        <div class="d-lg-none">
            <a href="#" class="btn btn-outline-primary btn-sm">
                <i class="bi bi-cart3"></i>
            </a>
        </div>
        
        <button class="navbar-toggler" type="button" 
                data-bs-toggle="collapse" data-bs-target="#mainNav">
            <span class="navbar-toggler-icon"></span>
        </button>
        
        <div class="collapse navbar-collapse" id="mainNav">
            <ul class="navbar-nav me-auto">
                <li class="nav-item"><a class="nav-link" href="#">Menu</a></li>
                <li class="nav-item"><a class="nav-link" href="#">Kontakt</a></li>
            </ul>
            
            <!-- Tylko na desktopie: pełny koszyk -->
            <div class="d-none d-lg-block">
                <a href="#" class="btn btn-outline-primary">
                    <i class="bi bi-cart3"></i> Koszyk (2)
                </a>
            </div>
        </div>
    </div>
</nav>
```

### Responsive text:

```html
<!-- Na telefonie: tekst mały, na desktopie: duży -->
<h1 class="fs-5 fs-md-1">Nagłówek responsywny</h1>

<!-- Na telefonie: ukryty, na desktopie: widoczny -->
<p class="d-none d-lg-block">Ten tekst jest widoczny tylko na dużych ekranach.</p>
```

### Responsive images:

```html
<!-- Obrazek dostosowujący się do kontenera -->
<img src="obrazek.jpg" class="img-fluid" alt="..."

<!-- Obrazek w shape (koło, itp.) -->
<img src="obrazek.jpg" class="rounded-circle img-fluid" alt="..." 
     style="max-width: 200px;">
```

---

## Container queries (nowość Bootstrap 5.3+)

Bootstrap 5.3 wprowadził kontener queries - elementy reagują na rozmiar swojego kontenera, nie ekranu:

```html
<div class="container">
    <div class="row">
        <div class="col-lg-8">
            <div class="card">
                <div class="card-body">
                    <!-- Treść reaguje na rozmiar karty, nie ekranu -->
                    <div class="d-flex flex-column flex-sm-row gap-3">
                        <img src="obrazek.jpg" class="img-fluid" 
                             style="max-width: 200px;">
                        <div>
                            <h5>Tytuł</h5>
                            <p>Opis...</p>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
```

---

## Dostosowanie zmiennych Bootstrapa

Bootstrap 5 używa zmiennych CSS (custom properties), które możesz nadpisać:

```html
<style>
:root {
    --bs-primary: #0d6efd;
    --bs-primary-rgb: 13, 110, 253;
    --bs-link-color: #0d6efd;
    --bs-border-radius: 0.5rem;
    --bs-border-radius-sm: 0.25rem;
    --bs-border-radius-lg: 0.75rem;
    --bs-border-radius-xl: 1rem;
    --bs-font-sans-serif: 'Nunito', sans-serif;
    --bs-body-font-size: 1rem;
    --bs-body-line-height: 1.6;
    --bs-spacer: 1rem;
}
</style>
```

### Custom CSS基于 Bootstrap:

```css
/* Moje zmienne */
:root {
    --moja-primary: #e74c3c;  /* Czerwony zamiast niebieskiego */
    --moja-secondary: #3498db;
    --moja-font: 'Open Sans', sans-serif;
}

/* Nadpisanie bootstrapowych zmiennych */
:root {
    --bs-primary: var(--moja-primary);
    --bs-primary-rgb: 231, 76, 60;
    --bs-link-color: var(--moja-primary);
    --bs-font-sans-serif: var(--moja-font);
}

/* Moje niestandardowe style */
.card-custom {
    border-left: 4px solid var(--moja-primary);
    transition: transform 0.2s;
}

.card-custom:hover {
    transform: translateY(-5px);
}

.hero-section {
    background: linear-gradient(135deg, var(--moja-primary), var(--moja-secondary));
    color: white;
}
```

---

## Media queries (podstawowe)

Bootstrap definiuje breakpointy w CSS, ale możesz pisać własne media queries:

```css
/* Dla ekranów < 576px (telefon) */
@media (max-width: 575.98px) {
    .card-title {
        font-size: 1.1rem;
    }
    .btn {
        width: 100%;
    }
}

/* Dla ekranów ≥ 768px (tablet) */
@media (min-width: 768px) {
    .sidebar {
        position: sticky;
        top: 80px;
    }
}

/* Dla ekranów ≥ 992px (desktop) */
@media (min-width: 992px) {
    .navbar-nav {
        gap: 0.5rem;
    }
}
```

---

## Pełny przykład - responsywna strona restauracji

```php
<?php
// responsywna.php
$danja = [
    ['nazwa' => 'Zupa pomidorowa', 'cena' => 12, 'opis' => 'Świeża zupa z grzankami', 'kategoria' => 'zupy'],
    ['nazwa' => 'Schabowy', 'cena' => 28, 'opis' => 'Klasyczny schabowy z ziemniakami', 'kategoria' => 'glowne'],
    ['nazwa' => 'Pierogi ruskie', 'cena' => 22, 'opis' => '8 sztuk z cebulką', 'kategoria' => 'glowne'],
    ['nazwa' => 'Szarlotka', 'cena' => 15, 'opis' => 'Ciepła z lodami', 'kategoria' => 'desery'],
    ['nazwa' => 'Żurek', 'cena' => 14, 'opis' => 'Tradycyjny z białą kiełbasą', 'kategoria' => 'zupy'],
    ['nazwa' => 'Kotlet schabowy', 'cena' => 26, 'opis' => 'Podany z sałatką', 'kategoria' => 'glowne'],
];
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Responsywna restauracja</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
    <style>
        :root {
            --bs-primary: #d35400;
            --bs-primary-rgb: 211, 84, 0;
            --bs-font-sans-serif: 'Segoe UI', system-ui, sans-serif;
        }
        
        .hero {
            background: linear-gradient(135deg, #d35400, #e67e22);
            color: white;
            padding: 3rem 0;
        }
        
        @media (max-width: 767.98px) {
            .hero h1 { font-size: 1.8rem; }
            .card-body { padding: 1rem; }
        }
        
        @media (min-width: 768px) {
            .sidebar-sticky {
                position: sticky;
                top: 80px;
            }
        }
    </style>
</head>
<body>

    <!-- RESPONSYWNY NAVBAR -->
    <nav class="navbar navbar-expand-lg bg-dark" data-bs-theme="dark">
        <div class="container">
            <a class="navbar-brand fw-bold" href="#">
                <i class="bi bi-house-door-fill"></i> Kuchnia Domowa
            </a>
            
            <!-- Koszyk: mały na telefonie, pełny na desktopie -->
            <div class="d-flex align-items-center gap-2">
                <a href="#" class="btn btn-outline-primary btn-sm d-lg-none">
                    <i class="bi bi-cart3"></i>
                </a>
                
                <button class="navbar-toggler" type="button" 
                        data-bs-toggle="collapse" data-bs-target="#mainNav">
                    <span class="navbar-toggler-icon"></span>
                </button>
            </div>
            
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
                
                <div class="d-none d-lg-flex align-items-center gap-2">
                    <a href="#" class="btn btn-outline-light">
                        <i class="bi bi-cart3"></i> Koszyk (2)
                    </a>
                    <a href="#" class="btn btn-primary">
                        Zamów online
                    </a>
                </div>
            </div>
        </div>
    </nav>

    <!-- HERO - responsywny -->
    <section class="hero text-center">
        <div class="container">
            <h1 class="display-4 fw-bold">Kuchnia Domowa</h1>
            <p class="lead mb-4">Tradycyjne polskie smaki w nowoczesnym wydaniu</p>
            
            <!-- Na telefonie: jeden przycisk, na desktopie: dwa -->
            <div class="d-grid d-md-flex justify-content-center gap-2">
                <a href="#menu" class="btn btn-light btn-lg">
                    <i class="bi bi-book"></i> Zobacz menu
                </a>
                <a href="#" class="btn btn-outline-light btn-lg d-none d-md-inline-flex">
                    <i class="bi bi-telephone"></i> Zadzwoń
                </a>
            </div>
        </div>
    </section>

    <!-- MENU Z SIDEBAR -->
    <section id="menu" class="container my-5">
        <div class="row">
            <!-- Sidebar: ukryty na telefonie, widoczny od tableta -->
            <div class="col-lg-3 d-none d-lg-block">
                <div class="sidebar-sticky">
                    <div class="card">
                        <div class="card-header">
                            <h6 class="mb-0">Kategorie</h6>
                        </div>
                        <div class="list-group list-group-flush">
                            <a href="#" class="list-group-item list-group-item-action active">
                                Wszystkie
                            </a>
                            <a href="#" class="list-group-item list-group-item-action">Zupy</a>
                            <a href="#" class="list-group-item list-group-item-action">Dania główne</a>
                            <a href="#" class="list-group-item list-group-item-action">Desery</a>
                        </div>
                    </div>
                </div>
            </div>
            
            <!-- Menu -->
            <div class="col-12 col-lg-9">
                <h2 class="mb-4">Nasze Menu</h2>
                
                <div class="row row-cols-1 row-cols-sm-2 row-cols-lg-3 g-3">
                    <?php foreach ($danja as $danie): ?>
                        <div class="col">
                            <div class="card h-100 shadow-sm">
                                <div class="card-body">
                                    <h5 class="card-title"><?= $danie['nazwa'] ?></h5>
                                    <p class="card-text text-muted small">
                                        <?= $danie['opis'] ?>
                                    </p>
                                    <div class="d-flex justify-content-between align-items-center">
                                        <span class="h5 mb-0 text-primary">
                                            <?= $danie['cena'] ?> zł
                                        </span>
                                        <button class="btn btn-outline-primary btn-sm">
                                            <i class="bi bi-cart-plus"></i>
                                            <span class="d-none d-sm-inline"> Zamów</span>
                                        </button>
                                    </div>
                                </div>
                            </div>
                        </div>
                    <?php endforeach; ?>
                </div>
            </div>
        </div>
    </section>

    <!-- FOOTER -->
    <footer class="bg-dark text-white py-4">
        <div class="container">
            <div class="row g-4">
                <!-- Na telefonie: pełna szerokość, na desktopie: 1/3 -->
                <div class="col-12 col-md-4">
                    <h5>Kuchnia Domowa</h5>
                    <p class="text-muted">
                        Tradycyjne polskie obiady od ponad 15 lat.
                    </p>
                </div>
                
                <div class="col-6 col-md-4">
                    <h6>Kontakt</h6>
                    <ul class="list-unstyled text-muted">
                        <li><i class="bi bi-telephone"></i> +48 123 456 789</li>
                        <li><i class="bi bi-envelope"></i> info@kuchniadomowa.pl</li>
                    </ul>
                </div>
                
                <div class="col-6 col-md-4">
                    <h6>Godziny otwarcia</h6>
                    <ul class="list-unstyled text-muted">
                        <li>Pon-Pt: 10:00-21:00</li>
                        <li>Sob: 11:00-20:00</li>
                        <li>Niedz: Zamknięte</li>
                    </ul>
                </div>
            </div>
            
            <hr class="my-3">
            <p class="text-center text-muted mb-0">
                &copy; <?= date('Y') ?> Kuchnia Domowa. Wszelkie prawa zastrzeżone.
            </p>
        </div>
    </footer>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
```

---

## Wskazówki dotyczące responsywności

1. **Zawsze zaczynaj od `col-12`** - pełna szerokość na telefonie
2. **Używaj `d-none d-*-block`** zamiast `d-*-none` - to bardziej przewidywalne
3. **Testuj na prawdziwych urządzeniach** - emulatory nie zawsze pokazują wszystko
4. **Używaj `img-fluid`** na wszystkich obrazkach
5. **Kontener z `px-*`** może być za wąski na telefonach - używaj `container-fluid` lub `container-sm`
6. **Przyciski na telefonie** powinny być większe (min. 44x44px)

---

## Następny rozdział

→ [Następny: Projekt końcowy](./13-projekt-koncowy.md)
