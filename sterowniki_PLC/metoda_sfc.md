# Metoda SFC – pełne notatki

## Co to jest SFC?

**SFC (Sequential Function Chart)** to graficzna metoda opisu działania układów sekwencyjnych.
Jest częścią normy **IEC 61131-3** i służy do tworzenia programów sterowników PLC oraz do opisu procesów technologicznych, które przebiegają w ustalonej kolejności.

Umożliwia przedstawienie procesu jako **ciągu kroków**, między którymi występują **przejścia** oparte o określone **warunki logiczne**.

---

# Podstawowe elementy SFC

## 1. Kroki (Steps)

Reprezentują stany działania układu.
Każdy krok może zawierać **akcje**, które wykonują polecenia sterowania.

Elementy kroku:

* symbol graficzny: prostokąt,
* nazwa kroku: np. "Start_Silnika",
* zestaw działań przypisanych do kroku.

Krok może być:

* **początkowy** – zaznaczony grubą linią lub kółkiem nad prostokątem,
* **pośredni**,
* **końcowy**.

---

## 2. Przejścia (Transitions)

Łączą kroki i określają moment zmiany stanu.

Przejście zawiera:

* linię łączącą kroki,
* poziomą kreskę,
* pod nią zapisany **warunek przejścia**.

Warunki mogą być oparte na:

* sygnałach wejściowych (czujniki, przyciski),
* licznikach,
* czasie,
* logice (AND, OR),
* wartościach analogowych.

---

## 3. Warunki przejścia

Warunek musi być spełniony, aby nastąpiło przejście do kolejnego kroku.

Przykłady:

* czujnik krańcowy "1",
* Timer upłynął (T1.Q = 1),
* temperatura > 80°C,
* naciśnięto START.

Warunki mogą składać się z kilku elementów logicznych.

---

# Działania przypisane do kroków

Działania to instrukcje wykonywane w czasie aktywności kroku.
Np. załączenie silnika, ustawienie wyjścia, sterowanie siłownikiem.

Każde działanie ma **kwalifikator**, który określa **jak długo i kiedy** dana akcja jest aktywna.

---

# Kwalifikatory działań w SFC

Kwalifikatory określają sposób aktywacji akcji w kroku.
To jeden z najważniejszych elementów, często pojawiający się na egzaminach.

## Najważniejsze kwalifikatory:

### 1. **N (Non-stored)** – działanie aktywne tylko wtedy, gdy krok jest aktywny

* Najczęściej stosowany
* Wyłącza się automatycznie po opuszczeniu kroku

### 2. **S (Set)** – działanie ustawiane jednokrotnie

* Po wejściu w krok ustawiana jest wartość (np. wyjście Q1 = 1)
* Pozostaje ustawiona nawet po wyjściu z kroku
* Aby wyłączyć, trzeba użyć kroku z kwalifikatorem reset

### 3. **R (Reset)** – resetuje stan ustawiony wcześniej

* Stosowany razem z kwalifikatorem S
* Np. wyłącza wyjście Q1 ustawione wcześniej

### 4. **P (Pulse)** – impuls jednorazowy

* Działanie aktywne tylko przez bardzo krótki czas przy wejściu do kroku
* Stosowane do wyzwalania jednorazowego: licznika, timera, zapisu, itp.

### 5. **L (Stored, Level)** – działanie pamiętane, aktywne tak długo jak krok jest aktywny, ale jego stan jest zapamiętywany po wyjściu

* Bardziej zaawansowane systemy SFC (część implementacji PLC)

### 6. **D (Delayed)** – działanie uaktywnia się po określonym czasie trwania kroku

* Rzadziej spotykane w prostych sterownikach

W większości egzaminów ELM.06 najważniejsze są kwalifikatory **N, S, R, P**.

---

# Przepływ sterowania w SFC

1. Sterownik startuje od kroku oznaczonego jako **początkowy**.
2. Wykonywane są **działania przypisane do kroku**.
3. Sterownik sprawdza **warunki przejścia**.
4. Gdy warunek zostanie spełniony:

   * aktualny krok przestaje być aktywny,
   * aktywowany jest kolejny krok.
5. Proces trwa aż do osiągnięcia kroku końcowego lub zapętlenia.

---

# Struktury logiczne SFC

## 1. Sekwencja liniowa

Krok → Przejście → Krok → Przejście

## 2. Rozdzielenie (fork)

Jeden krok aktywuje kilka równoległych kroków.

## 3. Złączenie (join)

Kilka kroków musi zostać zakończonych, aby przejść dalej.

## 4. Pętle

Pozwalają wrócić do wcześniejszego kroku (klasyczne cykle w maszynach, np. linie pakujące).

---

# Zastosowanie w elektromechanice

SFC wykorzystuje się do projektowania i opisu:

* cykli pracy maszyn,
* pracy napędów,
* sterowania transporterami, siłownikami, podnośnikami,
* maszyn CNC,
* automatów przemysłowych,
* wind, podajników, układów sortowania,
* procesów z wieloma krokami technologii.

SFC jest często stosowane w PLC:

* Siemens (Graph),
* Schneider Electric (Grafcet),
* Mitsubishi,
* Beckhoff,
* WAGO.

---

# Zasady projektowania SFC

1. Rozbij proces na jasne kroki.
2. Każdy krok powinien mieć jeden lub kilka efektów działania.
3. Warunki przejścia muszą być jednoznaczne.
4. Unika się zbędnych pętli.
5. Każda część procesu powinna mieć krok startowy i końcowy.
6. Działania muszą mieć odpowiednio dobrane kwalifikatory.

---

# Typowe pytania egzaminacyjne ELM.06

* Co oznacza kwalifikator **N / S / R / P**?
* Jak działa przejście w SFC?
* Czym różni się krok od działania?
* W jaki sposób realizuje się warunki przejścia?
* Do czego służy metoda SFC?
* Jak wygląda krok początkowy?
* Jak oznacza się działania przypisane do kroków?
* Jak opisać cykl pracy maszyny za pomocą SFC?
