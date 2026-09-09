# Rozdział 7: Karty (Cards)

Karty to wszechstronny komponent do wyświetlania treści - produktów, artykułów, danych użytkownika. Są elastyczne i łatwo się je konfiguruje.

---

## Podstawowa karta

```html
<div class="card">
    <div class="card-body">
        <h5 class="card-title">Tytuł karty</h5>
        <p class="card-text">Treść karty z podstawowym opisem.</p>
        <a href="#" class="btn btn-primary">Akcja</a>
    </div>
</div>
```

---

## Karta z nagłówkiem, treścią i stopką

```html
<div class="card">
    <div class="card-header">
        Nagłówek karty
    </div>
    <div class="card-body">
        <h5 class="card-title">Tytuł</h5>
        <p class="card-text">Treść karty.</p>
        <a href="#" class="btn btn-primary">Przycisk</a>
    </div>
    <div class="card-footer text-muted">
        Stopka karty
    </div>
</div>
```

---

## Karta z obrazkiem

```html
<!-- Obrazek na górze -->
<div class="card">
    <img src="https://via.placeholder.com/400x200" class="card-img-top" 
         alt="Obrazek dania">
    <div class="card-body">
        <h5 class="card-title">Zupa pomidorowa</h5>
        <p class="card-text">Świeża zupa z grzankami i bazylią.</p>
        <a href="#" class="btn btn-primary">Zamów - 12 zł</a>
    </div>
</div>

<!-- Obrazek na dole -->
<div class="card">
    <div class="card-body">
        <h5 class="card-title">Szarlotka</h5>
        <p class="card-text">Ciepła szarlotka z lodami.</p>
        <a href="#" class="btn btn-primary">Zamów - 15 zł</a>
    </div>
    <img src="https://via.placeholder.com/400x200" class="card-img-bottom" 
         alt="Obrazek szarlotki">
</div>
```

---

## Nakładka obrazka (Card overlay)

```html
<div class="card bg-dark text-white">
    <img src="https://via.placeholder.com/400x300" class="card-img" 
         alt="Tło">
    <div class="card-img-overlay">
        <h5 class="card-title">Specjalna oferta</h5>
        <p class="card-text">Tylko dziś - 20% zniżki na wszystkie dania!</p>
        <a href="#" class="btn btn-primary">Zamów teraz</a>
    </div>
</div>
```

---

## Kolory kart

```html
<div class="card text-bg-primary">
    <div class="card-body">
        <h5 class="card-title">Primary</h5>
        <p class="card-text">Karta w kolorze primary.</p>
    </div>
</div>

<div class="card text-bg-success">
    <div class="card-body">
        <h5 class="card-title">Success</h5>
        <p class="card-text">Karta w kolorze success.</p>
    </div>
</div>

<div class="card text-bg-danger">
    <div class="card-body">
        <h5 class="card-title">Danger</h5>
        <p class="card-text">Karta w kolorze danger.</p>
    </div>
</div>

<div class="card text-bg-warning">
    <div class="card-body">
        <h5 class="card-title">Warning</h5>
        <p class="card-text">Karta w kolorze warning.</p>
    </div>
</div>

<div class="card text-bg-info">
    <div class="card-body">
        <h5 class="card-title">Info</h5>
        <p class="card-text">Karta w kolorze info.</p>
    </div>
</div>

<div class="card text-bg-light">
    <div class="card-body">
        <h5 class="card-title">Light</h5>
        <p class="card-text">Karta w kolorze light.</p>
    </div>
</div>

<div class="card text-bg-dark">
    <div class="card-body">
        <h5 class="card-title">Dark</h5>
        <p class="card-text">Karta w kolorze dark.</p>
    </div>
</div>
```

---

## Obramowanie karty

```html
<div class="card border-primary">
    <div class="card-body text-primary">
        <h5 class="card-title">Primary border</h5>
    </div>
</div>

<div class="card border-success border-2">
    <div class="card-body text-success">
        <h5 class="card-title">Grubszy border success</h5>
    </div>
</div>

<div class="card border-0 shadow">
    <div class="card-body">
        <h5 class="card-title">Bez obramowania, z cieniem</h5>
    </div>
</div>
```

---

## Karty w grupach (Card Group)

Karty w jednym rzędzie z jednakową wysokością:

```html
<div class="card-group">
    <div class="card">
        <img src="https://via.placeholder.com/300x200" class="card-img-top" alt="...">
        <div class="card-body">
            <h5 class="card-title">Zupa dnia</h5>
            <p class="card-text">Krem z brokułów.</p>
            <p class="card-text"><small class="text-muted">12 zł</small></p>
        </div>
    </div>
    <div class="card">
        <img src="https://via.placeholder.com/300x200" class="card-img-top" alt="...">
        <div class="card-body">
            <h5 class="card-title">Danie główne</h5>
            <p class="card-text">Schabowy z ziemniakami.</p>
            <p class="card-text"><small class="text-muted">28 zł</small></p>
        </div>
    </div>
    <div class="card">
        <img src="https://via.placeholder.com/300x200" class="card-img-top" alt="...">
        <div class="card-body">
            <h5 class="card-title">Deser</h5>
            <p class="card-text">Szarlotka z lodami.</p>
            <p class="card-text"><small class="text-muted">15 zł</small></p>
        </div>
    </div>
</div>
```

---

## Karty w siatce (Card Grid)

Najczęściej używany wariant - karty w siatce z użyciem systemu kolumn:

```html
<div class="row row-cols-1 row-cols-md-2 row-cols-lg-3 g-4">
    <div class="col">
        <div class="card h-100">
            <img src="https://via.placeholder.com/300x200" class="card-img-top" alt="...">
            <div class="card-body">
                <h5 class="card-title">Danie 1</h5>
                <p class="card-text">Opis dania 1.</p>
            </div>
            <div class="card-footer">
                <small class="text-muted">25 zł</small>
            </div>
        </div>
    </div>
    <div class="col">
        <div class="card h-100">
            <img src="https://via.placeholder.com/300x200" class="card-img-top" alt="...">
            <div class="card-body">
                <h5 class="card-title">Danie 2</h5>
                <p class="card-text">Opis dania 2.</p>
            </div>
            <div class="card-footer">
                <small class="text-muted">30 zł</small>
            </div>
        </div>
    </div>
    <div class="col">
        <div class="card h-100">
            <img src="https://via.placeholder.com/300x200" class="card-img-top" alt="...">
            <div class="card-body">
                <h5 class="card-title">Danie 3</h5>
                <p class="card-text">Opis dania 3.</p>
            </div>
            <div class="card-footer">
                <small class="text-muted">20 zł</small>
            </div>
        </div>
    </div>
</div>
```

> **`h-100`** sprawia, że karta zajmuje 100% wysokości kontenera - wszystkie karty w wierszu mają jednakową wysokość.

---

## Horizontal Card (karta pozioma)

```html
<div class="card mb-3">
    <div class="row g-0">
        <div class="col-md-4">
            <img src="https://via.placeholder.com/300x300" 
                 class="img-fluid rounded-start" alt="...">
        </div>
        <div class="col-md-8">
            <div class="card-body">
                <h5 class="card-title">Schabowy z ziemniakami</h5>
                <p class="card-text">
                    Klasyczny polski schabowy podawany z ziemniakami 
                    i surówką z marchewki.
                </p>
                <p class="card-text">
                    <small class="text-muted">Cena: 28 zł</small>
                </p>
                <a href="#" class="btn btn-primary">Zamów</a>
            </div>
        </div>
    </div>
</div>
```

---

## Karta jako link

Cała karta jako klikalny link:

```html
<a href="#" class="card text-decoration-none">
    <div class="card-body">
        <h5 class="card-title">Kliknij mnie</h5>
        <p class="card-text">Cała karta jest linkiem.</p>
    </div>
</a>
```

---

## Pełny przykład - menu restauracji z kartami

```php
<?php
// menu.php
$menu = [
    [
        'nazwa' => 'Zupa pomidorowa',
        'cena' => 12,
        'kategoria' => 'Zupy',
        'opis' => 'Świeża zupa z grzankami i bazylią',
        'obrazek' => 'https://via.placeholder.com/400x250?text=Zupa+pomidorowa',
        'badge' => 'Polecamy',
        'badge_kolor' => 'success'
    ],
    [
        'nazwa' => 'Schabowy z ziemniakami',
        'cena' => 28,
        'kategoria' => 'Dania główne',
        'opis' => 'Klasyczny polski schabowy z ziemniakami i surówką',
        'obrazek' => 'https://via.placeholder.com/400x250?text=Schabowy',
        'badge' => 'Bestseller',
        'badge_kolor' => 'danger'
    ],
    [
        'nazwa' => 'Pierogi ruskie',
        'cena' => 22,
        'kategoria' => 'Dania główne',
        'opis' => '8 sztuk z podsmażoną cebulką i śmietaną',
        'obrazek' => 'https://via.placeholder.com/400x250?text=Pierogi',
        'badge' => '',
        'badge_kolor' => ''
    ],
    [
        'nazwa' => 'Szarlotka',
        'cena' => 15,
        'kategoria' => 'Desery',
        'opis' => 'Ciepła szarlotka z lodami waniliowymi',
        'obrazek' => 'https://via.placeholder.com/400x250?text=Szarlotka',
        'badge' => 'Nowość',
        'badge_kolor' => 'info'
    ],
];
?>

<section class="container my-5">
    <h2 class="text-center mb-4">Nasze Menu</h2>
    
    <div class="row row-cols-1 row-cols-md-2 row-cols-lg-3 row-cols-xl-4 g-4">
        <?php foreach ($menu as $danie): ?>
            <div class="col">
                <div class="card h-100 shadow-sm">
                    <img src="<?= $danie['obrazek'] ?>" 
                         class="card-img-top" 
                         alt="<?= $danie['nazwa'] ?>">
                    
                    <div class="card-body">
                        <div class="d-flex justify-content-between align-items-start mb-2">
                            <h5 class="card-title mb-0">
                                <?= $danie['nazwa'] ?>
                            </h5>
                            <?php if ($danie['badge']): ?>
                                <span class="badge bg-<?= $danie['badge_kolor'] ?>">
                                    <?= $danie['badge'] ?>
                                </span>
                            <?php endif; ?>
                        </div>
                        
                        <p class="card-text text-muted small">
                            <?= $danie['kategoria'] ?>
                        </p>
                        <p class="card-text">
                            <?= $danie['opis'] ?>
                        </p>
                    </div>
                    
                    <div class="card-footer bg-transparent d-flex justify-content-between align-items-center">
                        <span class="h5 mb-0 text-primary">
                            <?= $danie['cena'] ?> zł
                        </span>
                        <a href="#" class="btn btn-primary btn-sm">
                            <i class="bi bi-cart-plus"></i> Zamów
                        </a>
                    </div>
                </div>
            </div>
        <?php endforeach; ?>
    </div>
</section>
```

---

## Podsumowanie klas

| Klasa | Opis |
|-------|------|
| `card` | Podstawowy kontener karty |
| `card-body` | Treść karty |
| `card-header` | Nagłówek karty |
| `card-footer` | Stopka karty |
| `card-title` | Tytuł karty |
| `card-text` | Tekst karty |
| `card-img-top` | Obrazek na górze |
| `card-img-bottom` | Obrazek na dole |
| `card-img` | Obrazek tła (overlay) |
| `card-img-overlay` | Nakładka tekstowa na obrazku |
| `card-group` | Grupa kart w jednym rzędzie |
| `text-bg-*` | Kolor tła karty |
| `border-*` | Kolor obramowania |
| `shadow` | Cień |
| `h-100` | Pełna wysokość |

---

## Następny rozdział

→ [Następny: Tabele](./08-tabele.md)
