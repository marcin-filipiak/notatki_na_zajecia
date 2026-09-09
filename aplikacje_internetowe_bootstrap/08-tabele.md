# Rozdział 8: Tabele

Bootstrap stylizuje tabele HTML, dodając obramowania, pasy (stripes), efekty hover i konteksty kolorystyczne.

---

## Podstawowa tabela

```html
<table class="table">
    <thead>
        <tr>
            <th>#</th>
            <th>Nazwa dania</th>
            <th>Kategoria</th>
            <th>Cena</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>Zupa pomidorowa</td>
            <td>Zupy</td>
            <td>12 zł</td>
        </tr>
        <tr>
            <td>2</td>
            <td>Schabowy</td>
            <td>Dania główne</td>
            <td>28 zł</td>
        </tr>
        <tr>
            <td>3</td>
            <td>Szarlotka</td>
            <td>Desery</td>
            <td>15 zł</td>
        </tr>
    </tbody>
</table>
```

---

## Varianty tabel

### Pasy (Striped rows):

```html
<table class="table table-striped">
    <!-- ... -->
</table>
```

### Pasy w kolumnach:

```html
<table class="table table-striped-columns">
    <!-- ... -->
</table>
```

### Hover:

```html
<table class="table table-hover">
    <!-- ... -->
</table>
```

### Borderowane:

```html
<table class="table table-bordered">
    <!-- ... -->
</table>
```

### Bez obramowania:

```html
<table class="table table-borderless">
    <!-- ... -->
</table>
```

### Mała tabela:

```html
<table class="table table-sm">
    <!-- ... -->
</table>
```

### Kombinacja:

```html
<table class="table table-striped table-hover table-bordered table-sm">
    <!-- ... -->
</table>
```

---

## Konteksty kolorystyczne

Każdy wiersz może mieć kolor kontekstowy:

```html
<table class="table">
    <thead>
        <tr>
            <th>Wiersz</th>
            <th>Opis</th>
        </tr>
    </thead>
    <tbody>
        <tr class="table-primary">
            <td>Primary</td>
            <td>Wiersz w kolorze primary</td>
        </tr>
        <tr class="table-secondary">
            <td>Secondary</td>
            <td>Wiersz w kolorze secondary</td>
        </tr>
        <tr class="table-success">
            <td>Success</td>
            <td>Wiersz w kolorze success (zielony)</td>
        </tr>
        <tr class="table-danger">
            <td>Danger</td>
            <td>Wiersz w kolorze danger (czerwony)</td>
        </tr>
        <tr class="table-warning">
            <td>Warning</td>
            <td>Wiersz w kolorze warning (żółty)</td>
        </tr>
        <tr class="table-info">
            <td>Info</td>
            <td>Wiersz w kolorze info</td>
        </tr>
        <tr class="table-light">
            <td>Light</td>
            <td>Wiersz w kolorze light</td>
        </tr>
        <tr class="table-dark">
            <td>Dark</td>
            <td>Wiersz w kolorze dark</td>
        </tr>
    </tbody>
</table>
```

### Ciemna tabela (dark mode):

```html
<table class="table table-dark table-striped">
    <!-- ... -->
</table>
```

---

## Aktywna kolumna

```html
<table class="table">
    <thead>
        <tr>
            <th>#</th>
            <th class="table-active">Aktywna kolumna</th>
            <th>Zwykła kolumna</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td class="table-active">Komórka aktywna</td>
            <td>Dane</td>
            <td>Dane</td>
        </tr>
    </tbody>
</table>
```

---

## Responsywna tabela

Jeśli tabela jest za szeroka na ekran, zawijaj ją w kontener:

```html
<div class="table-responsive">
    <table class="table">
        <!-- Bardzo szeroka tabela -->
    </table>
</div>

<!-- Lub z cut-point na określonym ekranie -->
<div class="table-responsive-lg">
    <table class="table">
        <!-- Responsywna od breakpointa lg -->
    </table>
</div>
```

---

## Tabela z nagłówkiem i stopką

```html
<table class="table">
    <caption class="caption-top">
        Tabela 1: Menu restauracji - ceny z VAT
    </caption>
    <thead>
        <tr>
            <th scope="col">#</th>
            <th scope="col">Nazwa</th>
            <th scope="col">Cena netto</th>
            <th scope="col">Cena brutto</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>Zupa</td>
            <td>9.76 zł</td>
            <td>12.00 zł</td>
        </tr>
    </tbody>
    <tfoot>
        <tr>
            <td colspan="3" class="text-end fw-bold">Średnia:</td>
            <td class="fw-bold">18.33 zł</td>
        </tr>
    </tfoot>
</table>
```

---

## Tabela z linkami i akcjami

```html
<table class="table table-hover">
    <thead class="table-dark">
        <tr>
            <th>ID</th>
            <th>Nazwa</th>
            <th>Kategoria</th>
            <th>Cena</th>
            <th>Akcje</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>
                <a href="#" class="text-decoration-none">Zupa pomidorowa</a>
            </td>
            <td><span class="badge bg-info">Zupy</span></td>
            <td>12 zł</td>
            <td>
                <div class="btn-group btn-group-sm">
                    <a href="#" class="btn btn-outline-primary">
                        <i class="bi bi-eye"></i>
                    </a>
                    <a href="#" class="btn btn-outline-warning">
                        <i class="bi bi-pencil"></i>
                    </a>
                    <a href="#" class="btn btn-outline-danger">
                        <i class="bi bi-trash"></i>
                    </a>
                </div>
            </td>
        </tr>
        <tr>
            <td>2</td>
            <td>
                <a href="#" class="text-decoration-none">Schabowy</a>
            </td>
            <td><span class="badge bg-primary">Dania główne</span></td>
            <td>28 zł</td>
            <td>
                <div class="btn-group btn-group-sm">
                    <a href="#" class="btn btn-outline-primary">
                        <i class="bi bi-eye"></i>
                    </a>
                    <a href="#" class="btn btn-outline-warning">
                        <i class="bi bi-pencil"></i>
                    </a>
                    <a href="#" class="btn btn-outline-danger">
                        <i class="bi bi-trash"></i>
                    </a>
                </div>
            </td>
        </tr>
    </tbody>
</table>
```

---

## Pełny przykład - tabela zamówień restauracji

```php
<?php
// zamowienia.php
$zamowienia = [
    [
        'id' => 1001,
        'klient' => 'Jan Kowalski',
        'dania' => 'Zupa pomidorowa, Schabowy',
        'wartosc' => 40,
        'status' => 'done',
        'data' => '2025-01-15'
    ],
    [
        'id' => 1002,
        'klient' => 'Anna Nowak',
        'dania' => 'Pierogi ruskie x2',
        'wartosc' => 44,
        'status' => 'progress',
        'data' => '2025-01-15'
    ],
    [
        'id' => 1003,
        'klient' => 'Piotr Wiśniewski',
        'dania' => 'Żurek, Szarlotka, Kawa',
        'wartosc' => 41,
        'status' => 'pending',
        'data' => '2025-01-15'
    ],
    [
        'id' => 1004,
        'klient' => 'Maria Zielińska',
        'dania' => 'Zestaw obiadowy',
        'wartosc' => 35,
        'status' => 'done',
        'data' => '2025-01-14'
    ],
    [
        'id' => 1005,
        'klient' => 'Tomasz Lewandowski',
        'dania' => 'Rosół, Schabowy, Kompot',
        'wartosc' => 42,
        'status' => 'cancelled',
        'data' => '2025-01-14'
    ],
];

function getStatusBadge($status) {
    $map = [
        'done' => ['label' => 'Zrealizowane', 'class' => 'bg-success'],
        'progress' => ['label' => 'W przygotowaniu', 'class' => 'bg-warning text-dark'],
        'pending' => ['label' => 'Oczekuje', 'class' => 'bg-info'],
        'cancelled' => ['label' => 'Anulowane', 'class' => 'bg-danger'],
    ];
    $info = $map[$status] ?? ['label' => 'Nieznany', 'class' => 'bg-secondary'];
    return '<span class="badge ' . $info['class'] . '">' . $info['label'] . '</span>';
}
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Zamówienia - Panel administracyjny</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
</head>
<body>

<div class="container-fluid px-4 py-4">
    <!-- Nagłówek -->
    <div class="d-flex justify-content-between align-items-center mb-4">
        <h1 class="h3">
            <i class="bi bi-clipboard-data"></i> Zamówienia
        </h1>
        <div>
            <button class="btn btn-outline-secondary btn-sm">
                <i class="bi bi-download"></i> Eksportuj CSV
            </button>
            <button class="btn btn-primary btn-sm">
                <i class="bi bi-plus-lg"></i> Nowe zamówienie
            </button>
        </div>
    </div>

    <!-- Podsumowanie -->
    <div class="row g-3 mb-4">
        <div class="col-6 col-md-3">
            <div class="card text-bg-primary">
                <div class="card-body">
                    <h6 class="card-title">Wszystkie</h6>
                    <h2 class="mb-0"><?= count($zamowienia) ?></h2>
                </div>
            </div>
        </div>
        <div class="col-6 col-md-3">
            <div class="card text-bg-warning">
                <div class="card-body">
                    <h6 class="card-title">Oczekujące</h6>
                    <h2 class="mb-0">
                        <?= count(array_filter($zamowienia, fn($z) => $z['status'] === 'pending')) ?>
                    </h2>
                </div>
            </div>
        </div>
        <div class="col-6 col-md-3">
            <div class="card text-bg-success">
                <div class="card-body">
                    <h6 class="card-title">Zrealizowane</h6>
                    <h2 class="mb-0">
                        <?= count(array_filter($zamowienia, fn($z) => $z['status'] === 'done')) ?>
                    </h2>
                </div>
            </div>
        </div>
        <div class="col-6 col-md-3">
            <div class="card text-bg-info">
                <div class="card-body">
                    <h6 class="card-title">Przychód</h6>
                    <h2 class="mb-0">
                        <?= array_sum(array_column($zamowienia, 'wartosc')) ?> zł
                    </h2>
                </div>
            </div>
        </div>
    </div>

    <!-- Tabela -->
    <div class="card">
        <div class="card-header d-flex justify-content-between align-items-center">
            <span>Lista zamówień</span>
            <span class="text-muted">Ostatnia aktualizacja: <?= date('d.m.Y H:i') ?></span>
        </div>
        <div class="card-body p-0">
            <div class="table-responsive">
                <table class="table table-hover mb-0">
                    <thead class="table-dark">
                        <tr>
                            <th>#ID</th>
                            <th>Klient</th>
                            <th>Dania</th>
                            <th>Wartość</th>
                            <th>Status</th>
                            <th>Data</th>
                            <th>Akcje</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach ($zamowienia as $zamowienie): ?>
                            <tr>
                                <td>
                                    <strong>#<?= $zamowienie['id'] ?></strong>
                                </td>
                                <td><?= $zamowienie['klient'] ?></td>
                                <td>
                                    <small class="text-muted">
                                        <?= $zamowienie['dania'] ?>
                                    </small>
                                </td>
                                <td>
                                    <strong><?= $zamowienie['wartosc'] ?> zł</strong>
                                </td>
                                <td>
                                    <?= getStatusBadge($zamowienie['status']) ?>
                                </td>
                                <td>
                                    <small><?= $zamowienie['data'] ?></small>
                                </td>
                                <td>
                                    <div class="btn-group btn-group-sm">
                                        <a href="#" class="btn btn-outline-primary" title="Szczegóły">
                                            <i class="bi bi-eye"></i>
                                        </a>
                                        <a href="#" class="btn btn-outline-warning" title="Edytuj">
                                            <i class="bi bi-pencil"></i>
                                        </a>
                                        <a href="#" class="btn btn-outline-danger" title="Usuń">
                                            <i class="bi bi-trash"></i>
                                        </a>
                                    </div>
                                </td>
                            </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
        <div class="card-footer text-muted">
            Wyświetlanie <?= count($zamowienia) ?> z <?= count($zamowienia) ?> zamówień
        </div>
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
```

---

## Podsumowanie klas

| Klasa | Opis |
|-------|------|
| `table` | Podstawowa stylizacja |
| `table-striped` | Naprzemienne pasy w wierszach |
| `table-striped-columns` | Naprzemienne pasy w kolumnach |
| `table-hover` | Efekt najechania myszką |
| `table-bordered` | Obramowanie komórek |
| `table-borderless` | Bez obramowania |
| `table-sm` | Mała tabela (mniejsze paddingi) |
| `table-dark` | Ciemna tabela |
| `table-{color}` | Kontekst kolorystyczny wiersza |
| `table-active` | Aktywna kolumna/wiersz |
| `table-responsive` | Responsywna (scroll na małym ekranie) |
| `caption-top` | Podpis nad tabelą |

---

## Następny rozdział

→ [Następny: Modalne okna i alerty](./09-modalne-i-alerty.md)
