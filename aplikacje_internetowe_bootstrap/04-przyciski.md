# Rozdział 4: Przyciski (Buttons)

Przyciski to jeden z najczęściej używanych komponentów Bootstrapa. Są gotowe do użycia od razu po dodaniu odpowiedniej klasy.

---

## Podstawowe przyciski

Aby stworzyć przycisk, dodaj klasę `btn` do elementu `<button>`, `<a>` lub `<input>`:

```html
<!-- Przyciski wariantów kolorystycznych -->
<button type="button" class="btn btn-primary">Primary</button>
<button type="button" class="btn btn-secondary">Secondary</button>
<button type="button" class="btn btn-success">Success</button>
<button type="button" class="btn btn-danger">Danger</button>
<button type="button" class="btn btn-warning">Warning</button>
<button type="button" class="btn btn-info">Info</button>
<button type="button" class="btn btn-light">Light</button>
<button type="button" class="btn btn-dark">Dark</button>

<!-- Przycisk outline (z ramką, bez wypełnienia) -->
<button type="button" class="btn btn-outline-primary">Primary</button>
<button type="button" class="btn btn-outline-secondary">Secondary</button>
<button type="button" class="btn btn-outline-success">Success</button>
<button type="button" class="btn btn-outline-danger">Danger</button>
<button type="button" class="btn btn-outline-warning">Warning</button>
<button type="button" class="btn btn-outline-info">Info</button>
```

---

## Linki jako przyciski

Możesz sprawić, że link `<a>` będzie wyglądał jak przycisk:

```html
<a href="#" class="btn btn-primary">Link jako przycisk</a>
<a href="#" class="btn btn-outline-secondary">Drugi link</a>

<!-- Nieaktywny link -->
<a href="#" class="btn btn-primary disabled" tabindex="-1" aria-disabled="true">
    Nieaktywny
</a>
```

> **Ważne:** Dodaj `disabled` (dla `<button>`) lub `disabled` + `tabindex="-1"` + `aria-disabled="true"` (dla `<a>`), aby link wyglądał na nieaktywny.

---

## Rozmiary przycisków

```html
<!-- Mały -->
<button type="button" class="btn btn-primary btn-sm">Mały</button>

<!-- Normalny (domyślny) -->
<button type="button" class="btn btn-primary">Normalny</button>

<!-- Duży -->
<button type="button" class="btn btn-primary btn-lg">Duży</button>
```

---

## Pełna szerokość

```html
<button type="button" class="btn btn-primary w-100">Pełna szerokość</button>
```

---

## Przyciski z ikonami

Możesz dodawać ikony (np. z Font Awesome lub Bootstrap Icons) do przycisków:

```html
<!-- Bootstrap Icons (podłącz CSS w <head>) -->
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">

<button type="button" class="btn btn-primary">
    <i class="bi bi-cart"></i> Dodaj do koszyka
</button>

<button type="button" class="btn btn-success">
    <i class="bi bi-check-lg"></i> Zamów
</button>

<button type="button" class="btn btn-danger">
    <i class="bi bi-trash"></i> Usuń
</button>

<button type="button" class="btn btn-outline-primary">
    <i class="bi bi-pencil"></i> Edytuj
</button>
```

---

## Grupy przycisków

Łączysz przyciski w grupy za pomocą `btn-group`:

```html
<div class="btn-group" role="group" aria-label="Podstawowa grupa">
    <button type="button" class="btn btn-primary">Lewo</button>
    <button type="button" class="btn btn-primary">Środek</button>
    <button type="button" class="btn btn-primary">Prawo</button>
</div>

<!-- Grupa z rozmiarami -->
<div class="btn-group btn-group-sm" role="group">
    <button type="button" class="btn btn-outline-dark">1</button>
    <button type="button" class="btn btn-outline-dark">2</button>
    <button type="button" class="btn btn-outline-dark">3</button>
</div>
```

---

## Toolbar (pasek narzędzi)

Grupy przycisków w jednym rzędzie:

```html
<div class="btn-toolbar" role="toolbar" aria-label="Pasek narzędzi">
    <div class="btn-group me-2" role="group">
        <button type="button" class="btn btn-outline-secondary">
            <i class="bi bi-text-left"></i>
        </button>
        <button type="button" class="btn btn-outline-secondary">
            <i class="bi bi-text-center"></i>
        </button>
        <button type="button" class="btn btn-outline-secondary">
            <i class="bi bi-text-right"></i>
        </button>
    </div>

    <div class="btn-group me-2" role="group">
        <button type="button" class="btn btn-outline-secondary">
            <i class="bi bi-list"></i>
        </button>
        <button type="button" class="btn btn-outline-secondary">
            <i class="bi bi-grid"></i>
        </button>
    </div>
</div>
```

---

## Dropdown z przyciskiem

```html
<div class="btn-group">
    <button type="button" class="btn btn-primary dropdown-toggle" 
            data-bs-toggle="dropdown" aria-expanded="false">
        Opcje
    </button>
    <ul class="dropdown-menu">
        <li><a class="dropdown-item" href="#">Akcja 1</a></li>
        <li><a class="dropdown-item" href="#">Akcja 2</a></li>
        <li><hr class="dropdown-divider"></li>
        <li><a class="dropdown-item" href="#">Coś innego</a></li>
    </ul>
</div>
```

---

## Przyciski toggle (przełączniki)

```html
<!-- Single toggle -->
<button type="button" class="btn btn-primary" data-bs-toggle="button" 
        aria-pressed="false">
    Przełącz mnie
</button>

<!-- Checkbox buttons -->
<div class="btn-group" role="group">
    <input type="checkbox" class="btn-check" id="btncheck1" autocomplete="off">
    <label class="btn btn-outline-primary" for="btncheck1">Opcja 1</label>

    <input type="button" class="btn-check" id="btncheck2" autocomplete="off">
    <label class="btn btn-outline-primary" for="btncheck2">Opcja 2</label>

    <input type="checkbox" class="btn-check" id="btncheck3" autocomplete="off">
    <label class="btn btn-outline-primary" for="btncheck3">Opcja 3</label>
</div>

<!-- Radio buttons -->
<div class="btn-group" role="group">
    <input type="radio" class="btn-check" name="btnradio" id="btnradio1" 
           autocomplete="off" checked>
    <label class="btn btn-outline-primary" for="btnradio1">Radio 1</label>

    <input type="radio" class="btn-check" name="btnradio" id="btnradio2" 
           autocomplete="off">
    <label class="btn btn-outline-primary" for="btnradio2">Radio 2</label>

    <input type="radio" class="btn-check" name="btnradio" id="btnradio3" 
           autocomplete="off">
    <label class="btn btn-outline-primary" for="btnradio3">Radio 3</label>
</div>
```

---

## Pełny przykład - sekcja CTA restauracji

```php
<?php
// cta.php
$promocje = [
    ['tytul' => 'Zestaw Dnia', 'cena' => '25 zł', 'opis' => 'Zupa + Danie główne + Napój'],
    ['tytul' => 'Rodzinny Obiad', 'cena' => '89 zł', 'opis' => '4 dania + Deser dla 4 osób'],
    ['tytul' => 'Weekendowy Bufet', 'cena' => '45 zł', 'opis' => 'Nielimitowane jedzenie w weekend'],
];
?>

<section class="bg-primary text-white py-5">
    <div class="container">
        <div class="text-center mb-4">
            <h2 class="display-5 fw-bold">Specjalne Oferty</h2>
            <p class="lead">Skorzystaj z naszych promocji!</p>
        </div>

        <div class="row g-4">
            <?php foreach ($promocje as $promocja): ?>
                <div class="col-12 col-md-4">
                    <div class="card bg-white text-dark h-100">
                        <div class="card-body text-center">
                            <h3 class="card-title fw-bold"><?= $promocja['tytul'] ?></h3>
                            <p class="display-6 text-primary fw-bold"><?= $promocja['cena'] ?></p>
                            <p class="card-text text-muted"><?= $promocja['opis'] ?></p>
                            
                            <div class="d-grid gap-2">
                                <a href="#" class="btn btn-primary btn-lg">
                                    <i class="bi bi-cart-plus"></i> Zamów Teraz
                                </a>
                                <a href="#" class="btn btn-outline-secondary">
                                    <i class="bi bi-info-circle"></i> Więcej Info
                                </a>
                            </div>
                        </div>
                    </div>
                </div>
            <?php endforeach; ?>
        </div>
    </div>
</section>
```

---

## Atrybut `disabled`

```html
<!-- Nieaktywny przycisk -->
<button type="button" class="btn btn-primary" disabled>Nieaktywny</button>

<!-- Nieaktywny outline -->
<button type="button" class="btn btn-outline-secondary" disabled>Nieaktywny</button>

<!-- Loading state (z spinnerem) -->
<button class="btn btn-primary" type="button" disabled>
    <span class="spinner-border spinner-border-sm" role="status" aria-hidden="true"></span>
    Ładowanie...
</button>
```

---

## Podsumowanie klas

| Klasa | Opis |
|-------|------|
| `btn` | Podstawowa klasa przycisku |
| `btn-{color}` | Kolor (primary, secondary, success, danger, warning, info, light, dark) |
| `btn-outline-{color}` | Przycisk z ramką |
| `btn-sm` | Mały rozmiar |
| `btn-lg` | Duży rozmiar |
| `btn-block` / `d-grid` | Pełna szerokość |
| `disabled` | Nieaktywny |
| `btn-group` | Grupa przycisków |
| `btn-toolbar` | Pasek narzędzi |

---

## Następny rozdział

→ [Następny: Formularze](./05-formularze.md)
