# Rozdział 2: System siatki (Grid)

System siatki to **fundament Bootstrapa**. Dzięki niemu układasz treści w kolumnach, które automatycznie dopasowują się do rozmiaru ekranu.

---

## Jak działa siatka?

Bootstrap dzieli ekran na **12 equal-width kolumn**. Ty decydujesz, ile kolumn ma zająć dany element.

```
|---1---|---2---|---3---|---4---|---5---|---6---|---7---|---8---|---9---|--10---|--11---|--12---|
|                          Pełna szerokość (12/12)                                        |
|                    Połowa (6/12)                   |              Połowa (6/12)           |
|        Ćwierć (3/3)        |        Ćwierć (3/3)        |        Ćwierć (3/3)         |
```

### Struktura HTML:

```html
<div class="container">
    <div class="row">
        <div class="col-*">Treść 1</div>
        <div class="col-*">Treść 2</div>
    </div>
</div>
```

> **Zasada:** `container` → `row` → `col-*` - zawsze w tej kolejności.

---

## Podstawowe użycie

### Równe kolumny (bezokreślone)

Jeśli nie podasz liczby kolumn, rozłożą się równo:

```html
<div class="container">
    <div class="row">
        <div class="col">Kolumna 1</div>
        <div class="col">Kolumna 2</div>
        <div class="col">Kolumna 3</div>
    </div>
</div>
```

Result: każda kolumna zajmie 1/3 szerokości.

### Określona liczba kolumn

```html
<div class="row">
    <div class="col-8">Boczny panel (8/12)</div>
    <div class="col-4">Treść główna (4/12)</div>
</div>
```

### Mieszane szerokości

```html
<div class="row">
    <div class="col-3">Sidebar (25%)</div>
    <div class="col-6">Główna treść (50%)</div>
    <div class="col-3">Reklama (25%)</div>
</div>
```

---

## Breakpointy - responsywność

Kluczem do responsywności są **breakpointy** - punkty, w których układ się zmienia:

| Klasa | Rozmiar ekranu | Typ |
|-------|---------------|-----|
| `col` | Bez prefixa | Zawsze |
| `col-sm` | ≥576px | Telefon w pionie → poziom |
| `col-md` | ≥768px | Tablet |
| `col-lg` | ≥992px | Mały desktop |
| `col-xl` | ≥1200px | Duży desktop |
| `col-xxl` | ≥1400px | Bardzo duży monitor |

### Przykład - układ zmienia się na różnych ekranach:

```html
<!-- Na telefonie: 1 kolumna (pełna szerokość) -->
<!-- Na tablecie: 2 kolumny (pół na pół) -->
<!-- Na desktopie: 3 kolumny (trzecie) -->
<div class="row">
    <div class="col-12 col-md-6 col-lg-4">Kolumna 1</div>
    <div class="col-12 col-md-6 col-lg-4">Kolumna 2</div>
    <div class="col-12 col-md-6 col-lg-4">Kolumna 3</div>
</div>
```

**Jak to działa:**
- **Telefon (`col-12`):** każda kolumna zajmuje całą szerokość - układ pionowy
- **Tablet (`col-md-6`):** dwie kolumny w rzędzie
- **Desktop (`col-lg-4`):** trzy kolumny w rzędzie

---

## Wyrównywanie (Alignment)

### Pionowe wyrównanie wiersza:

```html
<!-- align-items-start -->
<div class="row align-items-start" style="height: 200px;">
    <div class="col">Góra</div>
    <div class="col">Góra</div>
</div>

<!-- align-items-center -->
<div class="row align-items-center" style="height: 200px;">
    <div class="col">Środek</div>
    <div class="col">Środek</div>
</div>

<!-- align-items-end -->
<div class="row align-items-end" style="height: 200px;">
    <div class="col">Dół</div>
    <div class="col">Dół</div>
</div>
```

### Poziome wyrównanie kolumn:

```html
<div class="row justify-content-start">
    <div class="col-4">Lewo</div>
</div>

<div class="row justify-content-center">
    <div class="col-4">Centrum</div>
</div>

<div class="row justify-content-end">
    <div class="col-4">Prawo</div>
</div>
```

---

## Marginesy i paddingi (Gutters)

**Gutters** to odstępy między kolumnami:

```html
<!-- Domyślne gutters -->
<div class="row">
    <div class="col">Bez odstępu</div>
    <div class="col">Bez odstępu</div>
</div>

<!-- Z gutters -->
<div class="row g-3">
    <div class="col">Z odstępem</div>
    <div class="col">Z odstępem</div>
</div>

<!-- Różne gutters poziomo i pionowo -->
<div class="row gx-5 gy-3">
    <div class="col">Odstęp 5 poziomo, 3 pionowo</div>
    <div class="col">Odstęp 5 poziomo, 3 pionowo</div>
</div>
```

### Rozmiary gutters:

| Klasa | Rozmiar |
|-------|---------|
| `g-0` | Brak |
| `g-1` | 0.25rem |
| `g-2` | 0.5rem |
| `g-3` | 1rem |
| `g-4` | 1.5rem |
| `g-5` | 3rem |

---

## Układ strony restauracji - praktyczny przykład

```php
<?php
// menu.php - Layout strony z siatką
$danja = [
    ['nazwa' => 'Zupa pomidorowa', 'cena' => '12 zł', 'kategoria' => 'Zupy'],
    ['nazwa' => 'Schabowy z ziemniakami', 'cena' => '28 zł', 'kategoria' => 'Dania główne'],
    ['nazwa' => 'Pierogi ruskie', 'cena' => '22 zł', 'kategoria' => 'Dania główne'],
    ['nazwa' => 'Szarlotka', 'cena' => '15 zł', 'kategoria' => 'Desery'],
];
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Menu - Kuchnia Domowa</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" 
          rel="stylesheet">
</head>
<body>

<div class="container">
    <h1 class="text-center my-4">Nasze Menu</h1>

    <div class="row">
        <!-- Sidebar z kategoriami - na desktopie 3 kolumny -->
        <div class="col-12 col-md-3">
            <div class="card">
                <div class="card-header">
                    <h5>Kategorie</h5>
                </div>
                <ul class="list-group list-group-flush">
                    <li class="list-group-item">Zupy</li>
                    <li class="list-group-item">Dania główne</li>
                    <li class="list-group-item">Desery</li>
                    <li class="list-group-item">Napoje</li>
                </ul>
            </div>
        </div>

        <!-- Menu - na desktopie 9 kolumn -->
        <div class="col-12 col-md-9">
            <div class="row g-3">
                <?php foreach ($danja as $danie): ?>
                    <div class="col-12 col-sm-6 col-lg-4">
                        <div class="card h-100">
                            <div class="card-body">
                                <h5 class="card-title"><?= $danie['nazwa'] ?></h5>
                                <p class="card-text text-muted"><?= $danie['kategoria'] ?></p>
                                <p class="card-text fw-bold"><?= $danie['cena'] ?></p>
                            </div>
                        </div>
                    </div>
                <?php endforeach; ?>
            </div>
        </div>
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
```

---

## Wskazówki

1. **Zacznij od `col-12`** (telefon) i dodawaj większe breakpointy - to "mobile-first"
2. **Nie używaj `col-*` bez prefixu** breakpointu jeśli chcesz responsywności
3. **Dodawaj `g-*`** do wierszy żeby uniknąć stykających się kolumn
4. **Używaj `container`** zamiast `container-fluid` - daje to lepsze spacowanie

---

## Następny rozdział

→ [Następny: Typografia i kolory](./03-typografia-i-kolory.md)
