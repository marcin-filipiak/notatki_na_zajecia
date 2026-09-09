# Projekt 1 — Sterowanie oświetleniem

> [Powrót do spisu treści](./README.md)

---

## Cel projektu

Zrealizować układ sterowania oświetleniem z **dwóch miejsc** za pomocą przycisków bistabilnych (bimetalicznych) i przekaźnika w sterowniku PLC.

---

## Zadanie

W budynku biurowym lampa (Q0.0) powinna być sterowana z **dwóch przełączników** (I0.0 i I0.1):
- Przełączenie **dowolnego** przełącznika zmienia stan lampy (ON ↔ OFF)
- System powinien działać jak **typowy włącznik schodowy**

---

## Analiza problemu

### Tabela prawdy

| I0.0 | I0.1 | Q0.0 (poprzedni) | Q0.0 (nowy) |
|------|------|-------------------|--------------|
| 0 | 0 | 0 | 0 (bez zmian) |
| 0 | 0 | 1 | 1 (bez zmian) |
| 1 | 0 | 0 | 1 (zmiana) |
| 1 | 0 | 1 | 0 (zmiana) |
| 0 | 1 | 0 | 1 (zmiana) |
| 0 | 1 | 1 | 0 (zmiana) |

### Implementacja

```
  Rung 1 — Zapamiętaj stan przełącznika I0.0:
  ═══| |═══(M0)═══
     I0.0

  Rung 2 — Zapamiętaj stan przełącznika I0.1:
  ═══| |═══(M1)═══
     I0.1

  Rung 3 — Wykryj zmianę I0.0 (zbocze):
  ═══| |═══|/|═══(M2)═══
     I0.0  M0

  Rung 4 — Wykryj zmianę I0.1 (zbocze):
  ═══| |═══|/|═══(M3)═══
     I0.1  M1

  Rung 5 — Przełącz lampkę:
  ═══| |═══|/|═══(S)═══
     M2    Q0.0  Q0.0

  ═══| |═══(R)═══
     M3    Q0.0

  ═══| |═══(R)═══
     M2    Q0.0

  ═══| |═══(S)═══
     M3    Q0.0
```

---

## Rozwiązanie uproszczone (XOR)

```
  Rung 1:
  ═══| |═══| |═══┬═══| |═══(Q0.0)═══
     I0.0  Q0.0  │
                 │
  ═══| |═══| |═══┘
     I0.1  Q0.0
```

**Wyjaśnienie:** Q0.0 = (I0.0 XOR I0.1) — jeśli tylko jeden z przełączników jest zmieniony, stan lampki się przełącza.

---

## Tabela zmiennych

| Nazwa | Adres | Typ | Opis |
|-------|-------|-----|------|
| Przelacz1 | %I0.0 | BOOL | Przełącznik 1 (schodowy) |
| Przelacz2 | %I0.1 | BOOL | Przełącznik 2 (schodowy) |
| Lampa | %Q0.0 | BOOL | Lampa oświetleniowa |

---

## Schemat połączeń

```
  ┌─────────────────────────────────────────────┐
  │                 TM221M16R                   │
  │                                             │
  │   I0.0 ◀── Przełącznik 1 (bistabilny)     │
  │   I0.1 ◀── Przełącznik 2 (bistabilny)     │
  │                                             │
  │   Q0.0 ──▶ Lampa (przez przekaźnik)       │
  │                                             │
  │   24V+ ◀── Zasilacz 24V DC                 │
  │   0V  ◀── masa                              │
  └─────────────────────────────────────────────┘
```

---

## Symulacja i testowanie

### Testy

| # | Akcja | Oczekiwany wynik |
|---|-------|------------------|
| 1 | Przełącz I0.0 | Lampa zmienia stan |
| 2 | Przełącz I0.1 | Lampa zmienia stan |
| 3 | Przełącz I0.0 | Lampa zmienia stan |
| 4 | Reset obu | Lampa zachowuje stan |

### Realizacja w SoMachine Basic

1. Utwórz nowy projekt → TM221M16R
2. Dodaj zmienne do tabeli
3. Wprowadź program drabinkowy
4. Skompiluj (F7)
5. Pobierz do sterownika
6. Monitoruj online
7. Przetestuj sekwencję

---

> [Powrót do spisu treści](./README.md)
