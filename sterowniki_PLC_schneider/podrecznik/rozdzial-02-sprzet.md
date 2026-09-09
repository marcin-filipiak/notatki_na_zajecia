# Rozdział 2 — Sterownik Schneider M221 — przegląd sprzętu

> [Powrót do spisu treści](./README.md)

---

## 2.1 Rodzina Modicon M221

Modicon M221 to seria kompaktowych sterowników PLC firmy **Schneider Electric**, należąca do platformy **EcoStruxure Machine**. Zaprojektowana do sterowania małymi i średnimi maszynami.

### Modele M221

| Model | Wejścia cyfrowe | Wyjścia cyfrowe | Typ wyjść | Zasilanie |
|-------|-----------------|-----------------|-----------|-----------|
| **TM221CE16R** | 10 DI | 6 DO | Przekaźnikowe (relay) | 24V DC |
| **TM221CE16T** | 10 DI | 6 DO | Tranzystorowe (transistor) | 24V DC |
| **TM221CE24R** | 16 DI | 8 DO | Przekaźnikowe | 24V DC |
| **TM221CE24T** | 16 DI | 8 DO | Tranzystorowe | 24V DC |
| **TM221CE40R** | 24 DI | 16 DO | Przekaźnikowe | 24V DC |
| **TM221CE40T** | 24 DI | 16 DO | Tranzystorowe | 24V DC |
| **TM221M16R** | 10 DI | 6 DO | Przekaźnikowe | 24V DC |

> Nasz model: **TM221M16R** — 10 wejść cyfrowych, 6 wyjść cyfrowych przekaźnikowych

---

## 2.2 TM221M16R — specyfikacja techniczna

### Parametry ogólne

| Parametr | Wartość |
|----------|---------|
| Procesor | ARM Cortex-A9, 400 MHz |
| Pamięć robocza (RAM) | 128 MB |
| Pamięć danych | 64 KB (data) |
| Pamięć programu | 24 KB (ladder) |
| Czas skanowania | ~3 ms / 1000 instrukcji |
| Cykl minimalny | 1 ms |
| Zasilanie | 24V DC (19.2–28.8V) |
| Pobór prądu | max. 300 mA |
| Temperatura pracy | 0°C do +55°C |
| Montaż | szyna DIN 35mm (TH35-7.5) |
| Stopień ochrony | IP20 |
| Wymiary (sz × wys × gł) | 40 × 100 × 90 mm |
| Masa | ~180 g |

### Wejścia cyfrowe (DI) — 10 szt.

| Parametr | Wartość |
|----------|---------|
| Liczba wejść | 10 |
| Typ | Sinking / Sourcing (NJ) |
| Napięcie wejściowe | 24V DC |
| Prąd wejściowy | ~7 mA przy 24V DC |
| Czas odpowiedzi | 10 ms (filtr antydrżeniowy) |
| izolacja | 500V AC (galwaniczna) |
| Numery wejść | I0.0, I0.1, I0.2, I0.3, I0.4, I0.5, I0.6, I0.7, I1.0, I1.1 |

### Wyjścia cyfrowe (DO) — 6 szt. (przekaźnikowe)

| Parametr | Wartość |
|----------|---------|
| Liczba wyjść | 6 |
| Typ | Przekaźnik (relay) |
| Napięcie wyjściowe | 24V DC lub 240V AC |
| Prąd maks. na kanał | 2A (DC) / 2A (AC) |
| Prąd łącza | 8A |
| Żywotność | ~100 000 000 przełączeń (mechaniczna) |
| Czas przełączenia | ~10 ms |
| Numery wyjść | Q0.0, Q0.1, Q0.2, Q0.3, Q0.4, Q0.5 |

### Złącza komunikacyjne

| Złącze | Typ | Zastosowanie |
|--------|-----|-------------|
| Ethernet (RJ45) | 10/100 Mb/s | Modbus TCP, programowanie |
| USB Micro-B | USB 2.0 | Programowanie, diagnostyka |
| Serial (RS-232) | RJ12 | Modbus RTU, konsole debugowe |

---

## 2.3 Architektura wewnętrzna

```
┌──────────────────────────────────────────────────────────┐
│                    TM221M16R                             │
│                                                          │
│  ┌──────────┐   ┌──────────┐   ┌──────────────────────┐ │
│  │ Wejścia  │   │ Procesor │   │     Wyjścia          │ │
│  │ DI       │──▶│ ARM      │──▶│     DO (przekaźniki) │ │
│  │ (10x)    │   │ Cortex   │   │     (6x)             │ │
│  └──────────┘   │ -A9      │   └──────────────────────┘ │
│                 └────┬─────┘                             │
│                      │                                   │
│  ┌──────────┐   ┌────┴─────┐   ┌──────────────────────┐ │
│  │ Zasilacz │   │ Pamięć   │   │ Komunikacja          │ │
│  │ 24V DC   │   │ RAM/ROM  │   │ Eth + USB + Serial   │ │
│  └──────────┘   └──────────┘   └──────────────────────┘ │
│                                                          │
│  ┌──────────────────────────────────────────────────────┐│
│  │ Slot na rozszerzenia TM2 (z lewej strony)           ││
│  └──────────────────────────────────────────────────────┘│
└──────────────────────────────────────────────────────────┘
```

---

## 2.4 Zasilanie i montaż na szynie DIN

### Zasilanie

```
  Zasilacz 24V DC
  ┌───────────┐
  │  +24V  ───┼───▶ zacisk L+ (zasilacz sterownika)
  │   0V   ───┼───▶ zacisk M  (masa zasilania)
  │  PE    ───┼───▶ masa / szyna ochronna
  └───────────┘
```

**Ważne:**
- Napięcie zasilania: **24V DC ±20%** (19.2V – 28.8V)
- Zalecany zasilacz: **Schneider ABL8REM24045** (lub odpowiednik)
- Filtracja wejść wymaga zasilacza o małymripple

### Montaż na szynie DIN

```
  ┌─────────────┐
  │   TM221M16R │
  │             │
  └──┬──────┬───┘
     │      │
  ┌──┴──────┴──┐
  │  Szyna DIN │ ← TH35-7.5 (35 mm)
  │   (zatrzask)│
  └────────────┘
```

---

## 2.5 Złącze Ethernet — konfiguracja

Złącze Ethernet TM221M16R służy do:
- Programowania i diagnostyki
- Komunikacji Modbus TCP
- Hostowania wbudowanego serwera WWW

### Domyślny adres IP

| Parametr | Wartość domyślna |
|----------|-------------------|
| Adres IP | `192.168.1.1` |
| Maska podsieci | `255.255.255.0` |
| Gateway | `192.168.1.254` |
| DHCP | Włączony (domyślnie) |

> Aby zmienić adres IP: użyj SoMachine Basic → Konfiguracja → Ethernet

---

## 2.6 Diody LED statusu

TM221M16R posiada diody LED na panelu przednim:

| LED | Kolor | Znaczenie |
|-----|-------|-----------|
| **PWR** | Zielony | Zasilanie włączone |
| **RUN** | Zielony | Sterownik w trybie RUN |
| **ERR** | Czerwony | Błąd systemu / programu |
| **USB** | Zielony | Aktywne połączenie USB |
| **ETH** | Zielony | Aktywne połączenie Ethernet |
| **I0.0–I1.1** | Zielony | Stan wejścia (1 = ON) |
| **Q0.0–Q0.5** | Zielony | Stan wyjścia (1 = ON) |

---

## 2.7 Rozszerzenia modułowe TM2

TM221M16R obsługuje **do 8 modułów rozszerzeń** podłączanych z lewej strony:

| Moduł | Opis |
|-------|------|
| **TM2DI16** | 16 wejść cyfrowych (24V DC) |
| **TM2DO16** | 16 wyjść cyfrowych (24V DC, tranzystor) |
| **TM2AI4** | 4 wejścia analogowe (0–10V, 4–20mA) |
| **TM2AO2** | 2 wyjścia analogowe (0–10V, 4–20mA) |
| **TM2AM6GT** | 6 DI + 4 DO + 2 AI + Ethernet |
| **TM2HSC2** | 2 liczniki szybkie (High Speed Counter) |

---

## 2.8 Podsumowanie

- **TM221M16R** to kompaktowy sterownik: 10 DI + 6 DO (przekaźniki)
- Praca z napięciem 24V DC, montaż na szynie DIN
- Komunikacja: Ethernet (Modbus TCP), USB, RS-232
- Obsługa rozszerzeń analogowych i cyfrowych
- Wbudowany serwer WWW i diagnostyka LED

> **Następny rozdział:** [Oprogramowanie SoMachine Basic](./rozdzial-03-somachine.md)

> [Powrót do spisu treści](./README.md)
