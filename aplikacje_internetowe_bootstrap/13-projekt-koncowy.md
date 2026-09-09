# Rozdział 13: Projekt końcowy - Strona restauracji "Kuchnia Domowa"

W tym rozdziale zbieramy wszystko, czego nauczyliśmy się w poprzednich rozdziałach, w kompletną stronę internetową restauracji.

---

## Struktura projektu

```
restauracja/
├── index.php          ← Strona główna
├── css/
│   └── style.css      ← Niestandardowe style
└── includes/
    ├── header.php     ← Nagłówek HTML + CSS
    └── footer.php     ← Stopka + JS
```

---

## Plik nagłówkowy (includes/header.php)

```php
<?php
// includes/header.php
$tytul_strony = $tytul_strony ?? "Kuchnia Domowa";
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?= $tytul_strony ?> - Kuchnia Domowa</title>
    
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" 
          rel="stylesheet">
    
    <!-- Bootstrap Icons -->
    <link rel="stylesheet" 
          href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
    
    <!-- Google Fonts -->
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link href="https://fonts.googleapis.com/css2?family=Playfair+Display:wght@400;700&family=Open+Sans:wght@300;400;600&display=swap" 
          rel="stylesheet">
    
    <!-- Niestandardowe style -->
    <link href="css/style.css" rel="stylesheet">
</head>
<body>
```

---

## Plik stopkowy (includes/footer.php)

```php
<?php
// includes/footer.php
$rok = date('Y');
?>

    <!-- FOOTER -->
    <footer class="bg-dark text-white py-5">
        <div class="container">
            <div class="row g-4">
                <div class="col-12 col-lg-4">
                    <h4 class="fw-bold mb-3">
                        <i class="bi bi-house-door-fill"></i> Kuchnia Domowa
                    </h4>
                    <p class="text-muted">
                        Od ponad 15 lat serwujemy domowe obiady przygotowywane 
                        ze świeżych, lokalnych składników.
                    </p>
                    <div class="d-flex gap-3">
                        <a href="#" class="text-muted fs-5"><i class="bi bi-facebook"></i></a>
                        <a href="#" class="text-muted fs-5"><i class="bi bi-instagram"></i></a>
                        <a href="#" class="text-muted fs-5"><i class="bi bi-tiktok"></i></a>
                    </div>
                </div>
                
                <div class="col-6 col-lg-2">
                    <h6 class="fw-bold mb-3">Menu</h6>
                    <ul class="list-unstyled">
                        <li class="mb-2"><a href="#menu" class="text-muted text-decoration-none">Nasze dania</a></li>
                        <li class="mb-2"><a href="#" class="text-muted text-decoration-none">Zestawy</a></li>
                        <li class="mb-2"><a href="#" class="text-muted text-decoration-none">Napoje</a></li>
                        <li class="mb-2"><a href="#" class="text-muted text-decoration-none">Catering</a></li>
                    </ul>
                </div>
                
                <div class="col-6 col-lg-3">
                    <h6 class="fw-bold mb-3">Informacje</h6>
                    <ul class="list-unstyled">
                        <li class="mb-2"><a href="#o-nas" class="text-muted text-decoration-none">O nas</a></li>
                        <li class="mb-2"><a href="#" class="text-muted text-decoration-none">Regulamin</a></li>
                        <li class="mb-2"><a href="#" class="text-muted text-decoration-none">Polityka prywatności</a></li>
                        <li class="mb-2"><a href="#" class="text-muted text-decoration-none">Kariera</a></li>
                    </ul>
                </div>
                
                <div class="col-12 col-lg-3">
                    <h6 class="fw-bold mb-3">Kontakt</h6>
                    <ul class="list-unstyled text-muted">
                        <li class="mb-2">
                            <i class="bi bi-geo-alt-fill text-primary"></i> 
                            ul. Przykładowa 10, Warszawa
                        </li>
                        <li class="mb-2">
                            <i class="bi bi-telephone-fill text-primary"></i> 
                            +48 123 456 789
                        </li>
                        <li class="mb-2">
                            <i class="bi bi-envelope-fill text-primary"></i> 
                            info@kuchniadomowa.pl
                        </li>
                    </ul>
                    <div class="mt-3">
                        <h6 class="small fw-bold">Godziny otwarcia</h6>
                        <p class="text-muted small mb-0">
                            Pon-Pt: 10:00 - 21:00<br>
                            Sob: 11:00 - 20:00<br>
                            Niedz: Zamknięte
                        </p>
                    </div>
                </div>
            </div>
            
            <hr class="my-4 border-secondary">
            
            <div class="row align-items-center">
                <div class="col-md-6 text-center text-md-start">
                    <p class="text-muted small mb-0">
                        &copy; <?= $rok ?> Kuchnia Domowa. Wszelkie prawa zastrzeżone.
                    </p>
                </div>
                <div class="col-md-6 text-center text-md-end mt-2 mt-md-0">
                    <span class="badge bg-success me-2">
                        <i class="bi bi-check-circle"></i> Otwarte
                    </span>
                    <span class="text-muted small">
                        Ostatnia aktualizacja: <?= date('d.m.Y') ?>
                    </span>
                </div>
            </div>
        </div>
    </footer>

    <!-- Bootstrap JS -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
    
    <!-- Niestandardowy JS -->
    <script src="js/main.js"></script>
</body>
</html>
```

---

## Style niestandardowe (css/style.css)

```css
/* css/style.css */

/* Zmienne */
:root {
    --moja-primary: #d35400;
    --moja-secondary: #e67e22;
    --moja-dark: #2c3e50;
    --moja-font-heading: 'Playfair Display', serif;
    --moja-font-body: 'Open Sans', sans-serif;
}

/* Nadpisanie zmiennych Bootstrapa */
:root {
    --bs-primary: var(--moja-primary);
    --bs-primary-rgb: 211, 84, 0;
    --bs-link-color: var(--moja-primary);
    --bs-font-sans-serif: var(--moja-font-body);
}

/* Body */
body {
    font-family: var(--moja-font-body);
    color: #333;
}

/* Nagłówki */
h1, h2, h3, h4, h5, h6 {
    font-family: var(--moja-font-heading);
}

/* Hero section */
.hero {
    background: linear-gradient(135deg, var(--moja-primary), var(--moja-secondary));
    color: white;
    padding: 5rem 0;
    position: relative;
    overflow: hidden;
}

.hero::before {
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
    background: url('https://via.placeholder.com/1920x600?text=+') center/cover;
    opacity: 0.1;
}

/* Karty menu */
.menu-card {
    transition: transform 0.3s ease, box-shadow 0.3s ease;
    border: none;
}

.menu-card:hover {
    transform: translateY(-8px);
    box-shadow: 0 12px 24px rgba(0, 0, 0, 0.15) !important;
}

/* Sidebar */
.sidebar-sticky {
    position: sticky;
    top: 80px;
}

/* Sekcje */
section {
    scroll-margin-top: 70px;
}

/* Przycisk primary */
.btn-primary {
    background-color: var(--moja-primary);
    border-color: var(--moja-primary);
}

.btn-primary:hover {
    background-color: var(--moja-secondary);
    border-color: var(--moja-secondary);
}

/* Formularz */
.form-control:focus,
.form-select:focus {
    border-color: var(--moja-primary);
    box-shadow: 0 0 0 0.25rem rgba(211, 84, 0, 0.25);
}

/* Navbar */
.navbar {
    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
}

/* Badge koszyka */
.cart-badge {
    position: absolute;
    top: -8px;
    right: -8px;
    font-size: 0.65rem;
}

/* Animacje */
@keyframes fadeInUp {
    from {
        opacity: 0;
        transform: translateY(20px);
    }
    to {
        opacity: 1;
        transform: translateY(0);
    }
}

.fade-in-up {
    animation: fadeInUp 0.6s ease forwards;
}

/* Responsive */
@media (max-width: 767.98px) {
    .hero {
        padding: 3rem 0;
    }
    
    .hero h1 {
        font-size: 2rem;
    }
    
    .card-body {
        padding: 1rem;
    }
}

/* Scrollbar */
::-webkit-scrollbar {
    width: 8px;
}

::-webkit-scrollbar-track {
    background: #f1f1f1;
}

::-webkit-scrollbar-thumb {
    background: var(--moja-primary);
    border-radius: 4px;
}

::-webkit-scrollbar-thumb:hover {
    background: var(--moja-secondary);
}
```

---

## Strona główna (index.php)

```php
<?php
// index.php
$tytul_strony = "Strona główna";
require_once 'includes/header.php';

// Dane menu
$menu = [
    'zupy' => [
        'tytul' => 'Zupy',
        'ikona' => 'bi-cup-hot',
        'dania' => [
            ['nazwa' => 'Zupa pomidorowa', 'cena' => 12, 'opis' => 'Świeża zupa z grzankami i bazylią', 'kalorie' => 180],
            ['nazwa' => 'Żurek', 'cena' => 14, 'opis' => 'Tradycyjny żurek z białą kiełbasą', 'kalorie' => 250],
            ['nazwa' => 'Rosół z makaronem', 'cena' => 10, 'opis' => 'Domowy rosoł z włoskim makaronem', 'kalorie' => 150],
        ]
    ],
    'glowne' => [
        'tytul' => 'Dania główne',
        'ikona' => 'bi-egg-fried',
        'dania' => [
            ['nazwa' => 'Schabowy z ziemniakami', 'cena' => 28, 'opis' => 'Klasyczny schabowy z ziemniakami i surówką', 'kalorie' => 650],
            ['nazwa' => 'Pierogi ruskie', 'cena' => 22, 'opis' => '8 sztuk z podsmażoną cebulką', 'kalorie' => 480],
            ['nazwa' => 'Kotlet schabowy', 'cena' => 26, 'opis' => 'Podany z sałatką i frytkami', 'kalorie' => 600],
            ['nazwa' => 'Kurczak curry', 'cena' => 25, 'opis' => 'Z ryżem i warzywami', 'kalorie' => 520],
        ]
    ],
    'desery' => [
        'tytul' => 'Desery',
        'ikona' => 'bi-cake',
        'dania' => [
            ['nazwa' => 'Szarlotka', 'cena' => 15, 'opis' => 'Ciepła z lodami waniliowymi', 'kalorie' => 380],
            ['nazwa' => 'Sernik', 'cena' => 16, 'opis' => 'Klasyczny sernik babci', 'kalorie' => 420],
            ['nazwa' => 'Lody (3 kulki)', 'cena' => 12, 'opis' => 'Wybierz 3 smaki z 8 dostępnych', 'kalorie' => 280],
        ]
    ]
];

// Promocje
$promocje = [
    ['tytul' => 'Zestaw Dnia', 'cena' => 25, 'opis' => 'Zupa + Danie główne + Napój', 'badge' => 'Bestseller', 'kolor' => 'danger'],
    ['tytul' => 'Rodzinny Obiad', 'cena' => 89, 'opis' => '4 dania + Deser dla 4 osób', 'badge' => 'Oszczędzasz 20%', 'kolor' => 'success'],
    ['tytul' => 'Weekendowy Bufet', 'cena' => 45, 'opis' => 'Nielimitowane jedzenie w weekend', 'badge' => 'Nowość', 'kolor' => 'info'],
];

// Opinie klientów
$opinie = [
    ['autor' => 'Anna K.', 'ocena' => 5, 'tekst' => 'Najlepszy schabowy w mieście! domowa atmosfera.', 'data' => '2 dni temu'],
    ['autor' => 'Piotr M.', 'ocena' => 5, 'tekst' => 'Świeże składniki i szybka dostawa. Polecam!', 'data' => '5 dni temu'],
    ['autor' => 'Maria W.', 'ocena' => 4, 'tekst' => 'Bardzo dobre pierogi. Na pewno wrócę.', 'data' => '1 tydzień temu'],
];
?>

<!-- HERO SECTION -->
<section class="hero text-center position-relative">
    <div class="container position-relative" style="z-index: 1;">
        <h1 class="display-3 fw-bold mb-3 fade-in-up">Kuchnia Domowa</h1>
        <p class="lead mb-4 fs-4 fade-in-up" style="animation-delay: 0.2s;">
            Tradycyjne polskie smaki w nowoczesnym wydaniu
        </p>
        <div class="d-grid d-sm-flex justify-content-center gap-3 fade-in-up" style="animation-delay: 0.4s;">
            <a href="#menu" class="btn btn-light btn-lg px-4">
                <i class="bi bi-book"></i> Zobacz Menu
            </a>
            <a href="#kontakt" class="btn btn-outline-light btn-lg px-4">
                <i class="bi bi-telephone"></i> Zadzwoń
            </a>
        </div>
        
        <!-- Mini statystyki -->
        <div class="row mt-5 g-3 justify-content-center fade-in-up" style="animation-delay: 0.6s;">
            <div class="col-6 col-md-3">
                <div class="text-white">
                    <h3 class="fw-bold mb-0">15+</h3>
                    <small class="opacity-75">Lat doświadczenia</small>
                </div>
            </div>
            <div class="col-6 col-md-3">
                <div class="text-white">
                    <h3 class="fw-bold mb-0">50+</h3>
                    <small class="opacity-75">Potraw w menu</small>
                </div>
            </div>
            <div class="col-6 col-md-3">
                <div class="text-white">
                    <h3 class="fw-bold mb-0">4.8★</h3>
                    <small class="opacity-75">Średnia ocena</small>
                </div>
            </div>
            <div class="col-6 col-md-3">
                <div class="text-white">
                    <h3 class="fw-bold mb-0">30min</h3>
                    <small class="opacity-75">Czas dostawy</small>
                </div>
            </div>
        </div>
    </div>
</section>

<!-- PROMOCJE -->
<section class="py-5 bg-light">
    <div class="container">
        <div class="text-center mb-4">
            <h2 class="display-6 fw-bold">Specjalne Oferty</h2>
            <p class="text-muted">Skorzystaj z naszych promocji!</p>
        </div>
        
        <div class="row g-4">
            <?php foreach ($promocje as $i => $promocja): ?>
                <div class="col-12 col-md-4">
                    <div class="card h-100 border-0 shadow-sm menu-card">
                        <div class="card-body text-center p-4">
                            <span class="badge bg-<?= $promocja['kolor'] ?> mb-3">
                                <?= $promocja['badge'] ?>
                            </span>
                            <h4 class="card-title fw-bold"><?= $promocja['tytul'] ?></h4>
                            <p class="display-5 fw-bold text-primary my-3">
                                <?= $promocja['cena'] ?> zł
                            </p>
                            <p class="text-muted"><?= $promocja['opis'] ?></p>
                            <a href="#" class="btn btn-primary">
                                <i class="bi bi-cart-plus"></i> Zamów Teraz
                            </a>
                        </div>
                    </div>
                </div>
            <?php endforeach; ?>
        </div>
    </div>
</section>

<!-- MENU Z TABS -->
<section id="menu" class="py-5">
    <div class="container">
        <div class="text-center mb-4">
            <h2 class="display-6 fw-bold">Nasze Menu</h2>
            <p class="text-muted">Odkryj nasze domowe smaki</p>
        </div>

        <!-- Tabs -->
        <ul class="nav nav-pills justify-content-center mb-4" role="tablist">
            <?php $first = true; ?>
            <?php foreach ($menu as $klucz => $kategoria): ?>
                <li class="nav-item" role="presentation">
                    <button class="nav-link <?= $first ? 'active' : '' ?>" 
                            data-bs-toggle="pill" 
                            data-bs-target="#tab-<?= $klucz ?>" 
                            type="button">
                        <i class="bi <?= $kategoria['ikona'] ?>"></i> 
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
                    <div class="row row-cols-1 row-cols-sm-2 row-cols-lg-3 row-cols-xl-4 g-3">
                        <?php foreach ($kategoria['dania'] as $danie): ?>
                            <div class="col">
                                <div class="card h-100 border-0 shadow-sm menu-card">
                                    <div class="card-body">
                                        <div class="d-flex justify-content-between align-items-start mb-2">
                                            <h5 class="card-title mb-0"><?= $danie['nazwa'] ?></h5>
                                            <span class="badge bg-primary rounded-pill">
                                                <?= $danie['kalorie'] ?> kcal
                                            </span>
                                        </div>
                                        <p class="card-text text-muted small">
                                            <?= $danie['opis'] ?>
                                        </p>
                                    </div>
                                    <div class="card-footer bg-transparent border-0 pt-0 d-flex justify-content-between align-items-center">
                                        <span class="h5 mb-0 text-primary fw-bold">
                                            <?= $danie['cena'] ?> zł
                                        </span>
                                        <button class="btn btn-outline-primary btn-sm">
                                            <i class="bi bi-cart-plus"></i> Zamów
                                        </button>
                                    </div>
                                </div>
                            </div>
                        <?php endforeach; ?>
                    </div>
                </div>
            <?php $first = false; endforeach; ?>
        </div>
    </div>
</section>

<!-- O NAS -->
<section id="o-nas" class="py-5 bg-light">
    <div class="container">
        <div class="row align-items-center g-5">
            <div class="col-12 col-lg-6">
                <h2 class="display-6 fw-bold mb-3">O Naszej Restauracji</h2>
                <p class="lead">
                    Kuchnia Domowa to miejsce, gdzie tradycja spotyka się 
                    z nowoczesnością.
                </p>
                <p class="text-muted">
                    Od ponad 15 lat serwujemy domowe obiady przygotowywane 
                    ze świeżych, lokalnych składników. Nasze dania to przepisy 
                    przekazywane z pokolenia na pokolenie, dostosowane do 
                    współczesnych gustów.
                </p>
                <p class="text-muted">
                    Wierzymy, że <strong>dobry posiłek</strong> to nie tylko 
                    smak, ale także <em>doświadczenie</em> i <em>atmosfera</em>.
                </p>
                <a href="#kontakt" class="btn btn-primary">
                    <i class="bi bi-telephone"></i> Skontaktuj się
                </a>
            </div>
            <div class="col-12 col-lg-6">
                <div class="card border-0 shadow">
                    <div class="card-body p-4">
                        <h5 class="card-title mb-3">
                            <i class="bi bi-info-circle text-primary"></i> 
                            Nasze wartości
                        </h5>
                        <ul class="list-unstyled">
                            <li class="mb-2">
                                <i class="bi bi-check-circle-fill text-success me-2"></i>
                                Świeże, lokalne składniki
                            </li>
                            <li class="mb-2">
                                <i class="bi bi-check-circle-fill text-success me-2"></i>
                                Tradycyjne przepisy
                            </li>
                            <li class="mb-2">
                                <i class="bi bi-check-circle-fill text-success me-2"></i>
                                Szybka dostawa (30-45 min)
                            </li>
                            <li class="mb-2">
                                <i class="bi bi-check-circle-fill text-success me-2"></i>
                                Przystępne ceny
                            </li>
                            <li class="mb-2">
                                <i class="bi bi-check-circle-fill text-success me-2"></i>
                                Przyjazna atmosfera
                            </li>
                        </ul>
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>

<!-- OPINIE -->
<section class="py-5">
    <div class="container">
        <div class="text-center mb-4">
            <h2 class="display-6 fw-bold">Co mówią nasi klienci</h2>
        </div>
        
        <div class="row g-4">
            <?php foreach ($opinie as $opinia): ?>
                <div class="col-12 col-md-4">
                    <div class="card h-100 border-0 shadow-sm">
                        <div class="card-body p-4">
                            <div class="mb-2">
                                <?php for ($i = 0; $i < $opinia['ocena']; $i++): ?>
                                    <i class="bi bi-star-fill text-warning"></i>
                                <?php endfor; ?>
                            </div>
                            <p class="card-text">"<?= $opinia['tekst'] ?>"</p>
                            <div class="d-flex justify-content-between align-items-center">
                                <strong><?= $opinia['autor'] ?></strong>
                                <small class="text-muted"><?= $opinia['data'] ?></small>
                            </div>
                        </div>
                    </div>
                </div>
            <?php endforeach; ?>
        </div>
    </div>
</section>

<!-- FAQ -->
<section class="py-5 bg-light">
    <div class="container">
        <div class="text-center mb-4">
            <h2 class="display-6 fw-bold">Najczęściej zadawane pytania</h2>
        </div>
        
        <div class="row justify-content-center">
            <div class="col-12 col-lg-8">
                <div class="accordion" id="faqAccordion">
                    <div class="accordion-item">
                        <h2 class="accordion-header">
                            <button class="accordion-button" type="button" 
                                    data-bs-toggle="collapse" data-bs-target="#faq1">
                                Jak złożyć zamówienie online?
                            </button>
                        </h2>
                        <div id="faq1" class="accordion-collapse collapse show" 
                             data-bs-parent="#faqAccordion">
                            <div class="accordion-body">
                                Wybierz dania z menu, kliknij "Zamów" przy wybranych 
                                potrawach, a następnie wypełnij formularz z danymi 
                                dostawy i potwierdź zamówienie.
                            </div>
                        </div>
                    </div>
                    
                    <div class="accordion-item">
                        <h2 class="accordion-header">
                            <button class="accordion-button collapsed" type="button" 
                                    data-bs-toggle="collapse" data-bs-target="#faq2">
                                Ile trwa dostawa?
                            </button>
                        </h2>
                        <div id="faq2" class="accordion-collapse collapse" 
                             data-bs-parent="#faqAccordion">
                            <div class="accordion-body">
                                Standardowa dostawa trwa od 30 do 45 minut. 
                                W godzinach szczytu (12:00-14:00) może to potrwać 
                                do godziny.
                            </div>
                        </div>
                    </div>
                    
                    <div class="accordion-item">
                        <h2 class="accordion-header">
                            <button class="accordion-button collapsed" type="button" 
                                    data-bs-toggle="collapse" data-bs-target="#faq3">
                                Jakie metody płatności akceptujecie?
                            </button>
                        </h2>
                        <div id="faq3" class="accordion-collapse collapse" 
                             data-bs-parent="#faqAccordion">
                            <div class="accordion-body">
                                Akceptujemy płatność gotówką przy odbiorze, 
                                kartą płatniczą, BLIK oraz przelewem bankowym.
                            </div>
                        </div>
                    </div>
                    
                    <div class="accordion-item">
                        <h2 class="accordion-header">
                            <button class="accordion-button collapsed" type="button" 
                                    data-bs-toggle="collapse" data-bs-target="#faq4">
                                Czy mogę anulować zamówienie?
                            </button>
                        </h2>
                        <div id="faq4" class="accordion-collapse collapse" 
                             data-bs-parent="#faqAccordion">
                            <div class="accordion-body">
                                Tak, możesz anulować zamówienie do 10 minut od 
                                jego złożenia. Po tym czasie zamówienie jest już 
                                w przygotowaniu.
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>

<!-- KONTAKT Z FORMULARZEM -->
<section id="kontakt" class="py-5">
    <div class="container">
        <div class="row g-5">
            <div class="col-12 col-lg-6">
                <h2 class="display-6 fw-bold mb-3">Skontaktuj się z nami</h2>
                <p class="text-muted mb-4">
                    Masz pytania? Chcesz zarezerwować stolik? 
                    Napisz do nas!
                </p>
                
                <div class="card border-0 shadow-sm">
                    <div class="card-body p-4">
                        <form>
                            <div class="row g-3">
                                <div class="col-12 col-sm-6">
                                    <label class="form-label">Imię</label>
                                    <input type="text" class="form-control" required>
                                </div>
                                <div class="col-12 col-sm-6">
                                    <label class="form-label">Email</label>
                                    <input type="email" class="form-control" required>
                                </div>
                                <div class="col-12">
                                    <label class="form-label">Temat</label>
                                    <select class="form-select">
                                        <option>Rezerwacja stolika</option>
                                        <option>Catering</option>
                                        <option>Pytanie o menu</option>
                                        <option>Inne</option>
                                    </select>
                                </div>
                                <div class="col-12">
                                    <label class="form-label">Wiadomość</label>
                                    <textarea class="form-control" rows="4" required></textarea>
                                </div>
                                <div class="col-12">
                                    <button type="submit" class="btn btn-primary w-100">
                                        <i class="bi bi-send"></i> Wyślij wiadomość
                                    </button>
                                </div>
                            </div>
                        </form>
                    </div>
                </div>
            </div>
            
            <div class="col-12 col-lg-6">
                <h2 class="display-6 fw-bold mb-3">Nasza lokalizacja</h2>
                
                <!-- Mapa (placeholder) -->
                <div class="card border-0 shadow-sm mb-4">
                    <div class="card-body p-0">
                        <div class="bg-secondary bg-opacity-10 d-flex align-items-center justify-content-center" 
                             style="height: 250px;">
                            <div class="text-center text-muted">
                                <i class="bi bi-geo-alt fs-1"></i>
                                <p class="mb-0">ul. Przykładowa 10, Warszawa</p>
                                <small>Mapa Google tutaj</small>
                            </div>
                        </div>
                    </div>
                </div>
                
                <!-- Informacje kontaktowe -->
                <div class="row g-3">
                    <div class="col-12 col-sm-6">
                        <div class="card border-0 shadow-sm h-100">
                            <div class="card-body text-center">
                                <i class="bi bi-telephone-fill text-primary fs-3 mb-2"></i>
                                <h6>Telefon</h6>
                                <p class="mb-0">+48 123 456 789</p>
                            </div>
                        </div>
                    </div>
                    <div class="col-12 col-sm-6">
                        <div class="card border-0 shadow-sm h-100">
                            <div class="card-body text-center">
                                <i class="bi bi-envelope-fill text-primary fs-3 mb-2"></i>
                                <h6>Email</h6>
                                <p class="mb-0">info@kuchniadomowa.pl</p>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>

<?php require_once 'includes/footer.php'; ?>
```

---

## JavaScript (js/main.js)

```javascript
// js/main.js

// Potwierdzenie wysłania formularza
document.querySelectorAll('form').forEach(form => {
    form.addEventListener('submit', function(e) {
        e.preventDefault();
        
        // Pokazanie toastu
        var toast = new bootstrap.Toast(document.getElementById('successToast'));
        toast.show();
        
        // Reset formularza
        this.reset();
    });
});

// Smooth scroll do sekcji
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function(e) {
        e.preventDefault();
        var target = document.querySelector(this.getAttribute('href'));
        if (target) {
            target.scrollIntoView({ behavior: 'smooth' });
        }
    });
});

// Aktualizacja roku w stopce
var currentYear = new Date().getFullYear();
var yearElements = document.querySelectorAll('.current-year');
yearElements.forEach(el => el.textContent = currentYear);
```

---

## Podsumowanie использовanych klas Bootstrap

W tym projekcie użyliśmy:

| Rozdział | Klasy |
|----------|-------|
| Grid | `container`, `row`, `col-*`, `g-*` |
| Typography | `display-*`, `lead`, `fw-bold`, `text-muted` |
| Colors | `bg-primary`, `text-primary`, `text-bg-*` |
| Buttons | `btn`, `btn-primary`, `btn-outline-*`, `btn-lg` |
| Forms | `form-control`, `form-label`, `form-select` |
| Nav | `nav-pills`, `nav-link`, `navbar`, `navbar-expand-lg` |
| Cards | `card`, `card-body`, `card-title`, `shadow-sm` |
| Tables | `table`, `table-hover`, `table-responsive` |
| Alert | `alert`, `alert-dismissible`, `fade`, `show` |
| Modal | `modal`, `modal-dialog`, `modal-content` |
| Toast | `toast`, `toast-container` |
| Accordion | `accordion`, `accordion-item`, `accordion-collapse` |
| Badge | `badge`, `rounded-pill` |
| Utility | `d-flex`, `justify-content-*`, `align-items-*`, `gap-*` |
| Display | `d-none`, `d-block`, `d-md-flex` |

---

## Gratulacje!

Ukończyłeś podręcznik Bootstrap 5! Teraz potrafisz:

- Tworzyć responsywne layouty z systemem siatki
- Stylizować tekst, kolory i tła
- Tworzyć przyciski i formularze
- Budować nawigacje (navbar, tabs, pills)
- Używać kart, tabel i modalnych okien
- Dodawać animowane komponenty (accordion, carousel)
- Korzystać z klas pomocniczych (utility classes)
- Dostosować Bootstrap do swoich potrzeb

**Co dalej?**
- Praktykuj tworzenie stron z użyciem Bootstrapa
- Poznaj Bootstrap Icons - bibliotekę ikon
- Sprawdź Bootstrap 5 JS documentation zaawansowane komponenty
- Eksperymentuj z niestandardowymi stylami CSS

Powodzenia w nauce! 🎉
