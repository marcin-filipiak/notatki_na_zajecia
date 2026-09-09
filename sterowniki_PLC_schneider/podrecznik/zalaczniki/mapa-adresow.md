# Mapa adresów TM221M16R

> [Powrót do spisu treści](./README.md)

---

## Przegląd adresacji

| Typ | Zakres | Rozmiar | Opis |
|-----|--------|---------|------|
| Wejścia cyfrowe | %I0.0 – %I1.1 | 1 bit | 10 wejść |
| Wyjścia cyfrowe | %Q0.0 – %Q0.5 | 1 bit | 6 wyjść |
| Markery bitowe | %M0 – %M2047 | 1 bit | Pamięć bitowa |
| Rejestry słowa | %MW0 – %MW255 | 16 bitów | Pamięć, INT/UINT |
| Rejestry podwójne | %MD0 – %MD63 | 32 bity | DINT/UDINT |
| Rejestry pływające | %MF0 – %MF63 | 32 bity | REAL |
| Timery | %TM0 – %TM31 | struktura | Bloki timerów |
| Liczniki | %CT0 – %CT31 | struktura | Bloki liczników |
| Stałe systemowe | %S | różne | Informacje o stanie |

---

## Tablica wejść cyfrowych

| Adres | Nazwa | Aplikacja typowa |
|-------|-------|------------------|
| %I0.0 | Wejście 0 | Przycisk START |
| %I0.1 | Wejście 1 | Przycisk STOP |
| %I0.2 | Wejście 2 | Czujnik zbliżeniowy |
| %I0.3 | Wejście 3 | Czujnik krańcowy |
| %I0.4 | Wejście 4 | Przełącznik trybu |
| %I0.5 | Wejście 5 | Przycisk awaryjny |
| %I0.6 | Wejście 6 | Sygnał z HMI |
| %I0.7 | Wejście 7 | Czujnik temperatury (bin) |
| %I1.0 | Wejście 8 | Czujnik poziomu |
| %I1.1 | Wejście 9 | Rezerwa |

---

## Tablica wyjść cyfrowych

| Adres | Nazwa | Aplikacja typowa |
|-------|-------|------------------|
| %Q0.0 | Wyjście 0 | Silnik / lampa |
| %Q0.1 | Wyjście 1 | Zawór elektromagnetyczny |
| %Q0.2 | Wyjście 2 | Grzałka |
| %Q0.3 | Wyjście 3 | Sygnalizacja (buzzer) |
| %Q0.4 | Wyjście 4 | Lampa sygnalizacyjna |
| %Q0.5 | Wyjście 5 | Rezerwa |

---

## Przydział rejestrów

### Rejestry zalecane dla typowych zastosowań

| Zakres | Zastosowanie |
|--------|-------------|
| %MW0 – %MW9 | Odczyty z czujników analogowych |
| %MW10 – %MW19 | Wartości zadane (setpoint) |
| %MW20 – %MW39 | Liczniki produkcji |
| %MW40 – %MW59 | Dane komunikacyjne (Modbus) |
| %MW60 – %MW99 | Zmienne pomocnicze |
| %MW100 – %MW255 | Zarezerwowane / systemowe |

---

## Przydział markerów

| Zakres | Zastosowanie |
|--------|-------------|
| %M0 – %M9 | Pobranie zapamiętanie stanu (latches) |
| %M10 – %M19 | Zmienne pośrednie (kalkulacje) |
| %M20 – %M99 | Zmienne programowe |
| %M100 – %M255 | Zmienne bramek / sekwencji |
| %M256 – %M2047 | Zarezerwowane / systemowe |

---

## Struktura rejestru %MW

```
  %MW0 = 16-bitowy rejestr:

  Bit:    15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0
  Waga:  32768 16384 8192 4096 2048 1024 512 256 128 64 32 16 8 4 2 1

  Wartość przy wszystkich bitach = 1: 65535
  Wartość maksymalna INT: 32767
  Wartość minimalna INT: −32768
```

---

## Struktura rejestru %MD

```
  %MD0 = 32-bitowy rejestr (dwa %MW):

  ┌───────────────────┬───────────────────┐
  │  %MW1 (górne 16b) │  %MW0 (dolne 16b) │
  └───────────────────┴───────────────────┘
      bit 31 – 16          bit 15 – 0

  %MD0 = (%MW1 << 16) + %MW0
```

---

## Struktura timera

```
  %TM0:
  ├── .IN   (BOOL) — wejście sterujące
  ├── .PT   (INT)  — czas zadany (ms)
  ├── .ET   (INT)  — czas bieżący (ms)
  ├── .Q    (BOOL) — wyjście
  └── .ING  (BOOL) — wejście blokady
```

---

## Struktura licznika

```
  %CT0:
  ├── .CU   (BOOL) — zliczanie w górę
  ├── .CD   (BOOL) — zliczanie w dół
  ├── .PV   (INT)  — wartość zadana
  ├── .CV   (INT)  — wartość bieżąca
  ├── .QU   (BOOL) — wyjście górne
  ├── .QD   (BOOL) — wyjście dolne
  └── .R    (BOOL) — reset
```

---

## Adresy Modbus mapowane na M221

| Adres Modbus | M221 | Typ |
|--------------|------|-----|
| 0 – 2047 | %M0 – %M2047 | BOOL (R/W) |
| 10000 – 10009 | %I0.0 – %I1.1 | BOOL (RO) |
| 20000 – 20005 | %Q0.0 – %Q0.5 | BOOL (R/W) |
| 30000 – 30255 | %MW0 – %MW255 | INT/UINT (R/W) |
| 40000 – 40063 | %MD0 – %MD63 | DINT (R/W) |
| 40100 – 40163 | %MF0 – %MF63 | REAL (R/W) |

---

> [Powrót do spisu treści](./README.md)
