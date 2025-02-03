## Markdown na GitHub

Markdown to lekki język znaczników używany do formatowania tekstu na GitHub i innych platformach. Pliki README.md są domyślnie otwierane na GitHub jako główne informacje o repozytorium.

### Podstawowe formatowanie

- **Pogrubienie**: `**tekst**` lub `__tekst__` → **tekst**
- *Kursywa*: `*tekst*` lub `_tekst_` → *tekst*
- ~~Przekreślenie~~: `~~tekst~~` → ~~tekst~~
- `Kod w linii`: `` `kod` `` → `kod`
- Blok kodu:
  ```
  ```język
  kod
  ```
  ```
- Cytat: `> tekst` →
  > tekst

### Nagłówki

Nagłówki tworzy się za pomocą `#`:
```markdown
# Nagłówek 1
## Nagłówek 2
### Nagłówek 3
```

### Listy

- Lista nienumerowana:
  ```markdown
  - Element 1
  - Element 2
  ```
- Lista numerowana:
  ```markdown
  1. Element 1
  2. Element 2
  ```

### Linkowanie

- Link do strony: `[tekst](https://example.com)` → [tekst](https://example.com)
- Link do pliku w repozytorium: `[README](README.md)` → [README](README.md)

### Obrazki

- Wstawianie obrazka: `![alt text](ścieżka_do_obrazu.jpg)`
- Można użyć obrazków z repozytorium lub URL.

### Tabele

```
| Nagłówek 1 | Nagłówek 2 |
|------------|------------|
| Wartość 1  | Wartość 2  |
| Wartość 3  | Wartość 4  |
```

Wynik:
| Nagłówek 1 | Nagłówek 2 |
|------------|------------|
| Wartość 1  | Wartość 2  |
| Wartość 3  | Wartość 4  |

### Listy zadań

- `[ ] Zadanie nieukończone`
- `[x] Zadanie ukończone`

```markdown
- [ ] Pierwsze zadanie
- [x] Drugie zadanie (zrobione)
```

### Skróty GitHub

- `@nazwa_użytkownika` – oznaczenie użytkownika
- `#123` – odwołanie do zgłoszenia (issue) lub pull requesta
- `:emoji:` – emoji np. `:smile:` → 😄

