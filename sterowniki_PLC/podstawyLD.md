

### 1. Instrukcje logiczne

| Instrukcja | Znaczenie                                       | Przykład     |
| ---------- | ----------------------------------------------- | ------------ |
| **LD**     | Load – załaduj stan wejścia lub bit             | `LD %I0.0`   |
| **LDN**    | Load negated – załaduj odwrotność stanu wejścia | `LDN %I0.1`  |
| **AND**    | AND – logiczne i z kolejnym bitem               | `AND %I0.1`  |
| **ANDN**   | AND z negacją                                   | `ANDN %I0.1` |
| **OR**     | OR – logiczne lub                               | `OR %I0.2`   |
| **ORN**    | OR z negacją                                    | `ORN %I0.2`  |
| **XOR**    | XOR – wyłączające lub                           | `XOR %Q0.0`  |
| **NOT**    | Negacja                                         | `NOT %Q0.0`  |

---

### 2. Instrukcje sterujące wyjściami

| Instrukcja | Znaczenie                  | Przykład    |
| ---------- | -------------------------- | ----------- |
| **ST**     | Set – załącz wyjście       | `ST %Q0.0`  |
| **RST**    | Reset – wyłącz wyjście     | `RST %Q0.0` |
| **S**      | Set – alternatywna forma   | `S %Q0.1`   |
| **R**      | Reset – alternatywna forma | `R %Q0.1`   |

---

### 1. Start/Stop silnika

**Cel:** Włączanie silnika przycisku `Start` (%I0.0) i wyłączanie przycisku `Stop` (%I0.1), wyjście silnika na %Q0.0.

**IL:**

```
LD   %I0.0       ; Start wciśnięty
ANDN %I0.1       ; Stop nie wciśnięty
ST   %Q0.0       ; Załącz silnik
```

**Opis:**

* `%I0.0` – wejście Start
* `%I0.1` – wejście Stop
* `%Q0.0` – wyjście silnika
* Jeśli Start wciśnięty i Stop nie wciśnięty → silnik załączony.



### 2. Prosty naprzemienny włącznik pomp

**Cel:** Naprzemienne włączanie P1 (%Q0.2) i P2 (%Q0.3) przy każdym wciśnięciu przycisku Start (%I0.3).

**IL:**

```
LD   %I0.3
XOR  %Q0.2
ST   %Q0.2

LD   %I0.3
XOR  %Q0.3
ST   %Q0.3
```

**Opis:**

* Każde wciśnięcie przycisku Start zmienia stan pomp P1 i P2
* `%Q0.2` i `%Q0.3` działają naprzemiennie

### 3. Timer

Na zakładce "tools" w "software objects->timers" ustaw parametry timera %TM0 
np. type: TON, 
timer base: 1 ms,
preset: 1000.
(włączenie po 1 sekundzie)

```
blk %tm0
    ld %i0.0
    in
    out_blk
    ld q
    st %q0.0
end_blk
```

Opis działania krok po kroku:

    blk %tm0
    Rozpoczyna definicję bloku funkcyjnego typu timer (oznaczonego jako %tm0). %tm0 to instancja timera — np. typu TON (Timer ON Delay).
    
    ld %i0.0
    Ładuje (ang. load) stan wejścia cyfrowego %i0.0 (czyli przycisku) na stos logiczny. Jeśli przycisk jest wciśnięty → wartość TRUE (1), w przeciwnym razie FALSE (0).
    
    in
    Przekazuje załadowaną wartość (%i0.0) do wejścia "IN" timera %tm0. To wejście aktywuje timer — jeśli IN = 1, timer zaczyna odliczać.
    
    out_blk
    Kończy przekazywanie danych do bloku i uruchamia jego działanie. Timer %tm0 teraz działa zgodnie ze swoim typem (prawdopodobnie TON) i ustawionym czasem opóźnienia (który nie jest widoczny w tym fragmencie, ale zwykle ustawiany osobno, np. PT := T#5s).
    
    ld q
    Ładuje wartość wyjścia timera — czyli sygnał Q (dostępny po zakończeniu odliczania). Gdy upłynie ustawiony czas i wejście IN nadal jest aktywne (=1), to Q przyjmuje wartość 1.
    
    st %q0.0
    Zapisuje (ang. store) wartość Q na wyjście cyfrowe %q0.0 — czyli włącza lampkę po upływie czasu.
    
    end_blk
    Kończy definicję bloku timera.

**Opis:**

* Naciśnięcie przycisku na i0.0 powoduje włączenie po określonym czasie lampki na q0.0
