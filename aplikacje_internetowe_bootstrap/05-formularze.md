# Rozdział 5: Formularze

Bootstrap stylizuje wszystkie elementy formularzy - inputy, selecty, checkboxy, textarea i przyciski. Dzięki temu formularze wyglądają profesjonalnie bez pisania CSS.

---

## Podstawowy formularz

```html
<form>
    <!-- Tekst -->
    <div class="mb-3">
        <label for="imie" class="form-label">Imię</label>
        <input type="text" class="form-control" id="imie" placeholder="Wpisz imię">
    </div>

    <!-- Email -->
    <div class="mb-3">
        <label for="email" class="form-label">Email</label>
        <input type="email" class="form-control" id="email" placeholder="twoj@email.pl">
    </div>

    <!-- Hasło -->
    <div class="mb-3">
        <label for="haslo" class="form-label">Hasło</label>
        <input type="password" class="form-control" id="haslo">
    </div>

    <button type="submit" class="btn btn-primary">Wyślij</button>
</form>
```

> **Klasy:** `mb-3` dodaje margines dolny, `form-label` stylizuje etykietę, `form-control` stylizuje input.

---

## Wszystkie typy inputów

```html
<!-- Tekst -->
<input type="text" class="form-control" placeholder="Tekst">

<!-- Email -->
<input type="email" class="form-control" placeholder="Email">

<!-- Hasło -->
<input type="password" class="form-control" placeholder="Hasło">

<!-- Liczba -->
<input type="number" class="form-control" placeholder="Liczba">

<!-- Data -->
<input type="date" class="form-control">

<!-- Godzina -->
<input type="time" class="form-control">

<!-- Datetime-local -->
<input type="datetime-local" class="form-control">

<!-- Telefon -->
<input type="tel" class="form-control" placeholder="+48 ...">

<!-- URL -->
<input type="url" class="form-control" placeholder="https://...">

<!-- Plik -->
<input type="file" class="form-control">

<!-- Ukryty -->
<input type="hidden" name="ukryte_pole" value="wartosc">

<!-- Checkbox -->
<div class="form-check">
    <input class="form-check-input" type="checkbox" id="check1">
    <label class="form-check-label" for="check1">Zgadzam się z regulaminem</label>
</div>

<!-- Radio -->
<div class="form-check">
    <input class="form-check-input" type="radio" name="radios" id="radio1" checked>
    <label class="form-check-label" for="radio1">Opcja 1</label>
</div>
<div class="form-check">
    <input class="form-check-input" type="radio" name="radios" id="radio2">
    <label class="form-check-label" for="radio2">Opcja 2</label>
</div>

<!-- Switch (przełącznik) -->
<div class="form-check form-switch">
    <input class="form-check-input" type="checkbox" id="switch1" checked>
    <label class="form-check-label" for="switch1">Powiadomienia email</label>
</div>

<!-- Range (suwak) -->
<label for="range1" class="form-label">Przedział: <span id="rangeValue">50</span></label>
<input type="range" class="form-range" id="range1" min="0" max="100" value="50">

<!-- Color picker -->
<input type="color" class="form-control form-control-color" value="#563d7c">

<!-- Textarea -->
<div class="mb-3">
    <label for="wiadomosc" class="form-label">Wiadomość</label>
    <textarea class="form-control" id="wiadomosc" rows="4" 
              placeholder="Napisz swoją wiadomość..."></textarea>
</div>

<!-- Select -->
<div class="mb-3">
    <label for="kategoria" class="form-label">Kategoria</label>
    <select class="form-select" id="kategoria">
        <option selected>Wybierz kategorię...</option>
        <option value="1">Zupy</option>
        <option value="2">Dania główne</option>
        <option value="3">Desery</option>
    </select>
</div>

<!-- Select wielokrotny -->
<div class="mb-3">
    <label for="skladniki" class="form-label">Składniki (wielokrotny wybór)</label>
    <select class="form-select" id="skladniki" multiple size="5">
        <option value="1">Mąka</option>
        <option value="2">Jajka</option>
        <option value="3">Mleko</option>
        <option value="4">Masło</option>
        <option value="5">Cukier</option>
    </select>
</div>
```

---

## Rozmiary inputów

```html
<input class="form-control form-control-sm" type="text" placeholder="Mały input">
<input class="form-control" type="text" placeholder="Normalny input">
<input class="form-control form-control-lg" type="text" placeholder="Duży input">
```

---

## Formularz w poziomie (inline)

```html
<form class="row row-cols-lg-auto g-3 align-items-end">
    <div class="col-12">
        <label class="visually-hidden" for="inlineFormInputGroupUsername">Username</label>
        <div class="input-group">
            <span class="input-group-text">@</span>
            <input type="text" class="form-control" id="inlineFormInputGroupUsername" 
                   placeholder="Username">
        </div>
    </div>

    <div class="col-12">
        <label class="visually-hidden" for="inlineFormSelectPref">Preferencje</label>
        <select class="form-select" id="inlineFormSelectPref">
            <option selected>Wybierz...</option>
            <option value="1">Opcja 1</option>
            <option value="2">Opcja 2</option>
        </select>
    </div>

    <div class="col-12">
        <div class="form-check">
            <input class="form-check-input" type="checkbox" id="inlineFormCheck">
            <label class="form-check-label" for="inlineFormCheck">Pamiętaj mnie</label>
        </div>
    </div>

    <div class="col-12">
        <button type="submit" class="btn btn-primary">Wyślij</button>
    </div>
</form>
```

---

## Disabled i readonly

```html
<!-- Disabled (nieaktywny) -->
<input class="form-control" type="text" placeholder="Nieaktywny" disabled>
<textarea class="form-control" disabled>Nieaktywna textarea</textarea>
<select class="form-select" disabled>
    <option>Nieaktywny select</option>
</select>

<!-- Readonly (tylko do odczytu) -->
<input class="form-control" type="text" value="Tylko do odczytu" readonly>
```

---

## Walidacja formularzy

Bootstrap oferuje wbudowaną walidację wizualną:

```html
<!-- Poprawny input -->
<div class="mb-3">
    <label for="poprawny" class="form-label">Email</label>
    <input type="email" class="form-control is-valid" id="poprawny" 
           value="test@email.pl">
    <div class="valid-feedback">
        Wygląda dobrze!
    </div>
</div>

<!-- Niepoprawny input -->
<div class="mb-3">
    <label for="niepoprawny" class="form-label">Email</label>
    <input type="email" class="form-control is-invalid" id="niepoprawny" 
           value="zły-email">
    <div class="invalid-feedback">
        Wpisz poprawny adres email.
    </div>
</div>

<!-- Walidacja na formularzu (wymaga JS) -->
<form class="needs-validation" novalidate>
    <div class="mb-3">
        <label for="walidacja1" class="form-label">Wymagane pole</label>
        <input type="text" class="form-control" id="walidacja1" required>
        <div class="invalid-feedback">
            To pole jest wymagane.
        </div>
    </div>
    <button class="btn btn-primary" type="submit">Wyślij formularz</button>
</form>
```

---

## Floating labels (etykietki unoszące się)

Nowoczesny efekt - etykieta "unosi się" nad inputem:

```html
<div class="form-floating mb-3">
    <input type="email" class="form-control" id="floatingEmail" placeholder="Email">
    <label for="floatingEmail">Adres email</label>
</div>

<div class="form-floating mb-3">
    <input type="password" class="form-control" id="floatingPassword" placeholder="Hasło">
    <label for="floatingPassword">Hasło</label>
</div>

<div class="form-floating mb-3">
    <textarea class="form-control" id="floatingTextarea" placeholder="Wiadomość" 
              style="height: 100px"></textarea>
    <label for="floatingTextarea">Wiadomość</label>
</div>
```

---

## Input groups

Dodajesz tekst, przyciski lub ikony do inputa:

```html
<!-- Prefiks tekstowy -->
<div class="input-group mb-3">
    <span class="input-group-text" id="basic-addon1">@</span>
    <input type="text" class="form-control" placeholder="Username" 
           aria-label="Username" aria-describedby="basic-addon1">
</div>

<!-- Sufiks tekstowy -->
<div class="input-group mb-3">
    <input type="text" class="form-control" placeholder="Nazwa użytkownika">
    <span class="input-group-text">@example.com</span>
</div>

<!-- Przycisk z prawej strony -->
<div class="input-group mb-3">
    <input type="text" class="form-control" placeholder="Szukaj...">
    <button class="btn btn-outline-primary" type="button">
        <i class="bi bi-search"></i>
    </button>
</div>

<!-- Cena z prefiksem -->
<div class="input-group mb-3">
    <span class="input-group-text">PLN</span>
    <input type="number" class="form-control" placeholder="0.00" step="0.01">
    <span class="input-group-text">,00</span>
</div>

<!-- Z przyciskiem dropdown -->
<div class="input-group mb-3">
    <input type="text" class="form-control" placeholder="Szukaj dania...">
    <button class="btn btn-outline-secondary dropdown-toggle" type="button" 
            data-bs-toggle="dropdown" aria-expanded="false">
        Kategoria
    </button>
    <ul class="dropdown-menu dropdown-menu-end">
        <li><a class="dropdown-item" href="#">Wszystkie</a></li>
        <li><a class="dropdown-item" href="#">Zupy</a></li>
        <li><a class="dropdown-item" href="#">Dania główne</a></li>
    </ul>
</div>
```

---

## Layout formularza w siatce

```html
<form>
    <div class="row g-3">
        <div class="col-md-6">
            <label for="imie" class="form-label">Imię</label>
            <input type="text" class="form-control" id="imie">
        </div>

        <div class="col-md-6">
            <label for="nazwisko" class="form-label">Nazwisko</label>
            <input type="text" class="form-control" id="nazwisko">
        </div>

        <div class="col-12">
            <label for="email" class="form-label">Email</label>
            <input type="email" class="form-control" id="email" 
                   placeholder="twoj@email.pl">
        </div>

        <div class="col-md-6">
            <label for="miasto" class="form-label">Miasto</label>
            <input type="text" class="form-control" id="miasto">
        </div>

        <div class="col-md-4">
            <label for="kod" class="form-label">Kod pocztowy</label>
            <input type="text" class="form-control" id="kod">
        </div>

        <div class="col-md-2">
            <label for="nr" class="form-label">Numer</label>
            <input type="text" class="form-control" id="nr">
        </div>

        <div class="col-12">
            <label for="adres" class="form-label">Adres dostawy</label>
            <input type="text" class="form-control" id="adres" 
                   placeholder="Ulica, numer, piętro...">
        </div>

        <div class="col-12">
            <button type="submit" class="btn btn-primary btn-lg">Zamów</button>
        </div>
    </div>
</form>
```

---

## Pełny przykład - formularz zamówienia restauracji

```php
<?php
// zamowienie.php
$dania = [
    'zupy' => ['Zupa pomidorowa' => 12, 'Żurek' => 14, 'Rosół' => 10],
    'glowne' => ['Schabowy' => 28, 'Pierogi' => 22, 'Kotlet' => 26],
    'desery' => ['Szarlotka' => 15, 'Sernik' => 16, 'Lody' => 12],
];

$dostawy = ['odbiór osobisty' => 0, 'rower' => 5, 'samochód' => 10];
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Zamów online - Kuchnia Domowa</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" 
          rel="stylesheet">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
</head>
<body>

<div class="container my-5">
    <div class="row justify-content-center">
        <div class="col-12 col-lg-8">
            <div class="card shadow">
                <div class="card-header bg-primary text-white">
                    <h2 class="mb-0">
                        <i class="bi bi-bag"></i> Zamów Online
                    </h2>
                </div>
                <div class="card-body">
                    <form method="POST" action="zamowienie_handler.php">
                        
                        <!-- Dane osobowe -->
                        <h4 class="mb-3">Dane osobowe</h4>
                        <div class="row g-3 mb-4">
                            <div class="col-md-6">
                                <label for="imie" class="form-label">Imię *</label>
                                <input type="text" class="form-control" id="imie" 
                                       name="imie" required>
                            </div>
                            <div class="col-md-6">
                                <label for="nazwisko" class="form-label">Nazwisko *</label>
                                <input type="text" class="form-control" id="nazwisko" 
                                       name="nazwisko" required>
                            </div>
                            <div class="col-12">
                                <label for="email" class="form-label">Email *</label>
                                <input type="email" class="form-control" id="email" 
                                       name="email" placeholder="twoj@email.pl" required>
                            </div>
                            <div class="col-12">
                                <label for="telefon" class="form-label">Telefon *</label>
                                <input type="tel" class="form-control" id="telefon" 
                                       name="telefon" placeholder="+48 ..." required>
                            </div>
                        </div>

                        <!-- Wybór dania -->
                        <h4 class="mb-3">Wybierz danie</h4>
                        <div class="mb-4">
                            <label for="danie" class="form-label">Danie główne *</label>
                            <select class="form-select" id="danie" name="danie" required>
                                <option value="">Wybierz danie...</option>
                                <?php foreach ($dania as $kategoria => $lista): ?>
                                    <optgroup label="<?= ucfirst($kategoria) ?>">
                                        <?php foreach ($lista as $nazwa => $cena): ?>
                                            <option value="<?= $nazwa ?>">
                                                <?= $nazwa ?> - <?= $cena ?> zł
                                            </option>
                                        <?php endforeach; ?>
                                    </optgroup>
                                <?php endforeach; ?>
                            </select>
                        </div>

                        <!-- Ilość i uwagi -->
                        <div class="row g-3 mb-4">
                            <div class="col-md-4">
                                <label for="ilosc" class="form-label">Ilość</label>
                                <input type="number" class="form-control" id="ilosc" 
                                       name="ilosc" value="1" min="1" max="20">
                            </div>
                            <div class="col-md-8">
                                <label for="uwagi" class="form-label">Uwagi do zamówienia</label>
                                <textarea class="form-control" id="uwagi" name="uwagi" 
                                          rows="2" 
                                          placeholder="Np. bez cebuli, mniej soli..."></textarea>
                            </div>
                        </div>

                        <!-- Dostawa -->
                        <h4 class="mb-3">Sposób dostawy</h4>
                        <div class="mb-4">
                            <?php foreach ($dostawy as $sposob => $koszt): ?>
                                <div class="form-check">
                                    <input class="form-check-input" type="radio" 
                                           name="dostawa" 
                                           id="dostawa_<?= md5($sposob) ?>" 
                                           value="<?= $sposob ?>"
                                           <?= $sposob === 'odbiór osobisty' ? 'checked' : '' ?>>
                                    <label class="form-check-label" 
                                           for="dostawa_<?= md5($sposob) ?>">
                                        <?= ucfirst($sposob) ?> 
                                        <?php if ($koszt > 0): ?>
                                            <span class="text-muted">
                                                (+<?= $koszt ?> zł)
                                            </span>
                                        <?php else: ?>
                                            <span class="badge bg-success">Gratis</span>
                                        <?php endif; ?>
                                    </label>
                                </div>
                            <?php endforeach; ?>
                        </div>

                        <!-- Przycisk -->
                        <div class="d-grid">
                            <button type="submit" class="btn btn-primary btn-lg">
                                <i class="bi bi-check-circle"></i> Zamawiam i płacę
                            </button>
                        </div>
                    </form>
                </div>
            </div>
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
| `form-control` | Stylizuje input/textarea/select |
| `form-label` | Stylizuje etykietę |
| `form-check` | Kontener checkboxa/radio |
| `form-check-input` | Stylizuje checkbox/radio |
| `form-check-label` | Stylizuje etykietę checkboxa/radio |
| `form-switch` | Przełącznik |
| `form-select` | Stylizuje select |
| `form-control-sm` | Mały input |
| `form-control-lg` | Duży input |
| `form-floating` | Unosząca się etykieta |
| `input-group` | Grupa input + tekst/przycisk |
| `input-group-text` | Tekst w grupie inputów |
| `is-valid` | Poprawny (zielona ramka) |
| `is-invalid` | Niepoprawny (czerwona ramka) |
| `valid-feedback` | Komunikat o poprawności |
| `invalid-feedback` | Komunikat o błędzie |
| `needs-validation` | Formularz do walidacji JS |
| `was-validated` | Formularz po walidacji |

---

## Następny rozdział

→ [Następny: Nawigacja](./06-nawigacja.md)
