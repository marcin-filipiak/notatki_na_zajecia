# Rozdział 9: Modalne okna i alerty

Bootstrap oferuje gotowe komponenty do wyświetlania okien modalnych, alertów, powiadomień toast i pasków postępu.

---

## Modal (okno modalne)

Modal to wyskakujące okno, które pojawia się nad treścią strony.

### Podstawowy modal

```html
<!-- Przycisk otwierający modal -->
<button type="button" class="btn btn-primary" 
        data-bs-toggle="modal" data-bs-target="#exampleModal">
    Otwórz modal
</button>

<!-- Modal -->
<div class="modal fade" id="exampleModal" tabindex="-1" 
     aria-labelledby="exampleModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h1 class="modal-title fs-5" id="exampleModalLabel">
                    Tytuł modala
                </h1>
                <button type="button" class="btn-close" 
                        data-bs-dismiss="modal" aria-label="Zamknij">
                </button>
            </div>
            <div class="modal-body">
                Treść modala. Możesz tu umieścić dowolny HTML.
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-secondary" 
                        data-bs-dismiss="modal">Anuluj</button>
                <button type="button" class="btn btn-primary">Zapisz</button>
            </div>
        </div>
    </div>
</div>
```

---

## Rozmiary modalów

```html
<!-- Mały modal -->
<div class="modal fade" id="smallModal" tabindex="-1">
    <div class="modal-dialog modal-sm">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title">Mały modal</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
            </div>
            <div class="modal-body">
                Treść małego modala.
            </div>
        </div>
    </div>
</div>

<!-- Duży modal -->
<div class="modal fade" id="largeModal" tabindex="-1">
    <div class="modal-dialog modal-lg">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title">Duży modal</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
            </div>
            <div class="modal-body">
                Treść dużego modala.
            </div>
        </div>
    </div>
</div>

<!-- Bardzo duży modal -->
<div class="modal fade" id="xlModal" tabindex="-1">
    <div class="modal-dialog modal-xl">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title">Bardzo duży modal</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
            </div>
            <div class="modal-body">
                Treść bardzo dużego modala.
            </div>
        </div>
    </div>
</div>

<!-- Pełnoekranowy modal -->
<div class="modal fade" id="fullModal" tabindex="-1">
    <div class="modal-dialog modal-fullscreen">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title">Pełnoekranowy</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
            </div>
            <div class="modal-body">
                Treść na pełnym ekranie.
            </div>
        </div>
    </div>
</div>
```

---

## Modal z formularzem

```html
<!-- Przycisk -->
<button type="button" class="btn btn-success" data-bs-toggle="modal" 
        data-bs-target="#orderModal">
    <i class="bi bi-cart-plus"></i> Zamów
</button>

<!-- Modal zamówienia -->
<div class="modal fade" id="orderModal" tabindex="-1">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header bg-primary text-white">
                <h5 class="modal-title">
                    <i class="bi bi-bag"></i> Nowe zamówienie
                </h5>
                <button type="button" class="btn-close btn-close-white" 
                        data-bs-dismiss="modal"></button>
            </div>
            <form method="POST" action="zamowienie.php">
                <div class="modal-body">
                    <div class="mb-3">
                        <label for="imię" class="form-label">Imię i nazwisko</label>
                        <input type="text" class="form-control" name="imie" required>
                    </div>
                    <div class="mb-3">
                        <label for="telefon" class="form-label">Telefon</label>
                        <input type="tel" class="form-control" name="telefon" required>
                    </div>
                    <div class="mb-3">
                        <label for="adres" class="form-label">Adres dostawy</label>
                        <textarea class="form-control" name="adres" rows="2" required></textarea>
                    </div>
                    <div class="mb-3">
                        <label for="uwagi" class="form-label">Uwagi</label>
                        <textarea class="form-control" name="uwagi" rows="2" 
                                  placeholder="Opcjonalnie..."></textarea>
                    </div>
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-secondary" 
                            data-bs-dismiss="modal">Anuluj</button>
                    <button type="submit" class="btn btn-primary">
                        <i class="bi bi-check-lg"></i> Potwierdź zamówienie
                    </button>
                </div>
            </form>
        </div>
    </div>
</div>
```

---

## Modal z potwierdzeniem usunięcia

```html
<!-- Przycisk usuwania -->
<button type="button" class="btn btn-danger btn-sm" data-bs-toggle="modal" 
        data-bs-target="#deleteModal" data-item-id="123">
    <i class="bi bi-trash"></i>
</div>

<!-- Modal potwierdzenia -->
<div class="modal fade" id="deleteModal" tabindex="-1">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header bg-danger text-white">
                <h5 class="modal-title">Potwierdzenie usunięcia</h5>
                <button type="button" class="btn-close btn-close-white" 
                        data-bs-dismiss="modal"></button>
            </div>
            <div class="modal-body">
                <p class="mb-0">Czy na pewno chcesz usunąć ten element?</p>
                <p class="text-muted small">Tej operacji nie można cofnąć.</p>
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-secondary" 
                        data-bs-dismiss="modal">Anuluj</button>
                <a href="#" class="btn btn-danger" id="confirmDelete">
                    <i class="bi bi-trash"></i> Tak, usuń
                </a>
            </div>
        </div>
    </div>
</div>

<!-- JS do przekazania ID -->
<script>
document.getElementById('deleteModal').addEventListener('show.bs.modal', function (event) {
    var button = event.relatedTarget;
    var itemId = button.getAttribute('data-item-id');
    var confirmBtn = document.getElementById('confirmDelete');
    confirmBtn.href = 'usun.php?id=' + itemId;
});
</script>
```

---

## Alert (powiadomienie)

Alerty to komunikaty informujące użytkownika o czymś.

### Podstawowe alerty

```html
<!-- Primary -->
<div class="alert alert-primary" role="alert">
    To jest alert primary.
</div>

<!-- Success -->
<div class="alert alert-success" role="alert">
    Zamówienie zostało przyjęte!
</div>

<!-- Danger -->
<div class="alert alert-danger" role="alert">
    Wystąpił błąd podczas przetwarzania zamówienia.
</div>

<!-- Warning -->
<div class="alert alert-warning" role="alert">
    Uwaga: brakujące składniki w magazynie.
</div>

<!-- Info -->
<div class="alert alert-info" role="alert">
    Nowe menu dostępne od poniedziałku.
</div>

<!-- Light i Dark -->
<div class="alert alert-light" role="alert">
    Alert light - delikatny komunikat.
</div>
<div class="alert alert-dark" role="alert">
    Alert dark - ciemny komunikat.
</div>
```

### Alert z zamknięciem (dismissible)

```html
<div class="alert alert-success alert-dismissible fade show" role="alert">
    <i class="bi bi-check-circle-fill"></i> Zamówienie #1001 zostało zrealizowane!
    <button type="button" class="btn-close" data-bs-dismiss="alert" 
            aria-label="Zamknij"></button>
</div>
```

### Alert z tytułem i linkiem

```html
<div class="alert alert-warning alert-dismissible fade show" role="alert">
    <h4 class="alert-heading">
        <i class="bi bi-exclamation-triangle-fill"></i> Uwaga!
    </h4>
    <p>
        Twoje zamówienie zostało opóźnione o 15 minut. 
        Przepraszamy za utrudnienia.
    </p>
    <hr>
    <p class="mb-0">
        Jeśli masz pytania, <a href="#" class="alert-link">skontaktuj się z nami</a>.
    </p>
    <button type="button" class="btn-close" data-bs-dismiss="alert"></button>
</div>
```

---

## Toast (powiadomienie wyskakujące)

Toast to delikatne powiadomienie, które pojawia się w rogu ekranu.

```html
<!-- Container na toasty -->
<div class="toast-container position-fixed bottom-0 end-0 p-3">
    
    <!-- Toast success -->
    <div id="liveToast" class="toast" role="alert" 
         aria-live="assertive" aria-atomic="true">
        <div class="toast-header">
            <i class="bi bi-check-circle-fill text-success me-2"></i>
            <strong class="me-auto">Sukces</strong>
            <small>Teraz</small>
            <button type="button" class="btn-close" 
                    data-bs-dismiss="toast" aria-label="Zamknij"></button>
        </div>
        <div class="toast-body">
            Zamówienie zostało złożone pomyślnie!
        </div>
    </div>
    
    <!-- Toast danger -->
    <div id="errorToast" class="toast" role="alert">
        <div class="toast-header bg-danger text-white">
            <i class="bi bi-x-circle-fill me-2"></i>
            <strong class="me-auto">Błąd</strong>
            <small>Teraz</small>
            <button type="button" class="btn-close btn-close-white" 
                    data-bs-dismiss="toast"></button>
        </div>
        <div class="toast-body">
            Nie udało się złożyć zamówienia. Spróbuj ponownie.
        </div>
    </div>
</div>

<!-- Przycisk pokazujący toast -->
<button class="btn btn-primary" type="button" 
        id="showToast">Pokaż powiadomienie</button>

<!-- JS -->
<script>
var toastTrigger = document.getElementById('showToast');
var toastLive = document.getElementById('liveToast');

if (toastTrigger) {
    toastTrigger.addEventListener('click', function () {
        var toast = new bootstrap.Toast(toastLive);
        toast.show();
    });
}
</script>
```

---

## Progress Bar (pasek postępu)

```html
<!-- Podstawowy -->
<div class="progress mb-3">
    <div class="progress-bar" role="progressbar" style="width: 25%" 
         aria-valuenow="25" aria-valuemin="0" aria-valuemax="100">
        25%
    </div>
</div>

<!-- Z etykietą -->
<div class="progress mb-3">
    <div class="progress-bar" role="progressbar" style="width: 50%" 
         aria-valuenow="50" aria-valuemin="0" aria-valuemax="100">
        50% - Przygotowanie
    </div>
</div>

<!-- Kolorowe -->
<div class="progress mb-3">
    <div class="progress-bar bg-success" style="width: 35%"></div>
    <div class="progress-bar bg-warning" style="width: 20%"></div>
    <div class="progress-bar bg-danger" style="width: 10%"></div>
</div>

<!-- Z paskami (striped) -->
<div class="progress mb-3">
    <div class="progress-bar progress-bar-striped" style="width: 60%"></div>
</div>

<!-- Z paskami i animacją -->
<div class="progress mb-3">
    <div class="progress-bar progress-bar-striped progress-bar-animated" 
         style="width: 75%">
        75% - Dostawa w drodze
    </div>
</div>

<!-- Nieokreślony (nieznany postęp) -->
<div class="progress">
    <div class="progress-bar progress-bar-striped progress-bar-animated" 
         style="width: 100%">
        Ładowanie...
    </div>
</div>
```

---

## Pełny przykład - panel zamówień z modalem i alertami

```php
<?php
// panel.php
$zamowienia = [
    ['id' => 1001, 'klient' => 'Jan K.', 'status' => 'done', 'cena' => 40],
    ['id' => 1002, 'klient' => 'Anna N.', 'status' => 'progress', 'cena' => 44],
    ['id' => 1003, 'klient' => 'Piotr W.', 'status' => 'pending', 'cena' => 41],
];

$powiadomienia = [
    ['typ' => 'success', 'tekst' => 'Zamówienie #1001 zrealizowane!'],
    ['typ' => 'info', 'tekst' => 'Nowe zamówienie #1004 od Marii Z.'],
];
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Panel zamówień</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
</head>
<body>

<div class="container py-4">
    <h1 class="mb-4"><i class="bi bi-speedometer2"></i> Panel zamówień</h1>

    <!-- Alerty -->
    <?php foreach ($powiadomienia as $pow): ?>
        <div class="alert alert-<?= $pow['typ'] ?> alert-dismissible fade show" role="alert">
            <?= $pow['tekst'] ?>
            <button type="button" class="btn-close" data-bs-dismiss="alert"></button>
        </div>
    <?php endforeach; ?>

    <!-- Progress bar - realizacja dzisiejszych zamówień -->
    <div class="card mb-4">
        <div class="card-body">
            <h6 class="card-title">Postęp realizacji zamówień</h6>
            <?php
            $total = count($zamowienia);
            $done = count(array_filter($zamowienia, fn($z) => $z['status'] === 'done'));
            $percent = $total > 0 ? round(($done / $total) * 100) : 0;
            ?>
            <div class="progress">
                <div class="progress-bar progress-bar-striped progress-bar-animated 
                            <?= $percent == 100 ? 'bg-success' : 'bg-primary' ?>" 
                     style="width: <?= $percent ?>%">
                    <?= $percent ?>% (<?= $done ?>/<?= $total ?>)
                </div>
            </div>
        </div>
    </div>

    <!-- Tabela -->
    <div class="card">
        <div class="card-header d-flex justify-content-between">
            <span>Zamówienia</span>
            <button class="btn btn-primary btn-sm" data-bs-toggle="modal" 
                    data-bs-target="#newOrderModal">
                <i class="bi bi-plus-lg"></i> Nowe zamówienie
            </button>
        </div>
        <div class="table-responsive">
            <table class="table table-hover mb-0">
                <thead class="table-dark">
                    <tr>
                        <th>#ID</th>
                        <th>Klient</th>
                        <th>Status</th>
                        <th>Cena</th>
                        <th>Akcje</th>
                    </tr>
                </thead>
                <tbody>
                    <?php foreach ($zamowienia as $z): ?>
                        <tr>
                            <td>#<?= $z['id'] ?></td>
                            <td><?= $z['klient'] ?></td>
                            <td>
                                <?php
                                $statusMap = [
                                    'done' => ['Zrealizowane', 'success'],
                                    'progress' => ['W przygotowaniu', 'warning'],
                                    'pending' => ['Oczekuje', 'info'],
                                ];
                                $s = $statusMap[$z['status']] ?? ['Nieznany', 'secondary'];
                                ?>
                                <span class="badge bg-<?= $s[1] ?>"><?= $s[0] ?></span>
                            </td>
                            <td><?= $z['cena'] ?> zł</td>
                            <td>
                                <button class="btn btn-outline-danger btn-sm" 
                                        data-bs-toggle="modal" 
                                        data-bs-target="#deleteModal"
                                        data-id="<?= $z['id'] ?>">
                                    <i class="bi bi-trash"></i>
                                </button>
                            </td>
                        </tr>
                    <?php endforeach; ?>
                </tbody>
            </table>
        </div>
    </div>
</div>

<!-- Modal nowego zamówienia -->
<div class="modal fade" id="newOrderModal" tabindex="-1">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header bg-primary text-white">
                <h5 class="modal-title">Nowe zamówienie</h5>
                <button type="button" class="btn-close btn-close-white" data-bs-dismiss="modal"></button>
            </div>
            <form>
                <div class="modal-body">
                    <div class="mb-3">
                        <label class="form-label">Klient</label>
                        <input type="text" class="form-control" required>
                    </div>
                    <div class="mb-3">
                        <label class="form-label">Telefon</label>
                        <input type="tel" class="form-control" required>
                    </div>
                    <div class="mb-3">
                        <label class="form-label">Danie</label>
                        <select class="form-select" required>
                            <option value="">Wybierz danie...</option>
                            <option>Zupa pomidorowa - 12 zł</option>
                            <option>Schabowy - 28 zł</option>
                            <option>Pierogi ruskie - 22 zł</option>
                        </select>
                    </div>
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Anuluj</button>
                    <button type="submit" class="btn btn-primary">Zamów</button>
                </div>
            </form>
        </div>
    </div>
</div>

<!-- Modal usuwania -->
<div class="modal fade" id="deleteModal" tabindex="-1">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header bg-danger text-white">
                <h5 class="modal-title">Usuń zamówienie</h5>
                <button type="button" class="btn-close btn-close-white" data-bs-dismiss="modal"></button>
            </div>
            <div class="modal-body">
                Na pewno chcesz usunąć zamówienie <strong id="deleteId"></strong>?
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Anuluj</button>
                <a href="#" class="btn btn-danger">Tak, usuń</a>
            </div>
        </div>
    </div>
</div>

<!-- Toast -->
<div class="toast-container position-fixed bottom-0 end-0 p-3">
    <div id="orderToast" class="toast" role="alert">
        <div class="toast-header bg-success text-white">
            <i class="bi bi-check-circle me-2"></i>
            <strong class="me-auto">Sukces</strong>
            <button type="button" class="btn-close btn-close-white" data-bs-dismiss="toast"></button>
        </div>
        <div class="toast-body">Zamówienie zostało złożone!</div>
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
<script>
// Przekazanie ID do modala usuwania
document.getElementById('deleteModal').addEventListener('show.bs.modal', function(e) {
    var id = e.relatedTarget.getAttribute('data-id');
    document.getElementById('deleteId').textContent = '#' + id;
});

// Pokazanie toasta po przesłaniu formularza
document.querySelector('#newOrderModal form').addEventListener('submit', function(e) {
    e.preventDefault();
    var modal = bootstrap.Modal.getInstance(document.getElementById('newOrderModal'));
    modal.hide();
    var toast = new bootstrap.Toast(document.getElementById('orderToast'));
    toast.show();
});
</script>
</body>
</html>
```

---

## Podsumowanie

| Komponent | Klasa | Opis |
|-----------|-------|------|
| Modal | `modal` | Okno modalne |
| Modal | `modal-sm` / `modal-lg` / `modal-xl` | Rozmiar |
| Modal | `modal-fullscreen` | Pełny ekran |
| Modal | `modal-dialog-centered` | Wycentrowany |
| Modal | `modal-dialog-scrollable` | Scrollowalna treść |
| Alert | `alert` + `alert-{color}` | Powiadomienie |
| Alert | `alert-dismissible` | Z przyciskiem zamknięcia |
| Toast | `toast` | Powiadomienie w rogu |
| Progress | `progress` + `progress-bar` | Pasek postępu |
| Progress | `progress-bar-striped` | Z paskami |
| Progress | `progress-bar-animated` | Z animacją |

---

## Następny rozdział

→ [Następny: Komponenty dodatkowe](./10-komponenty-dodatkowe.md)
