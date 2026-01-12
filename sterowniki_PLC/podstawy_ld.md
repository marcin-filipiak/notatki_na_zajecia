

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

```
blk %tm0
    ld %i0.0
    in
    out_blk
    ld q
    st %q0.0
end_blk
```

**Opis:**

* Naciśnięcie przycisku na i0.0 powoduje włączenie po określonym czasie lampki na q0.0
