# Przetworniki analogowo–cyfrowe (A/C, ADC)

---

### 1. Zastosowanie

Przetwornik A/C służy do zamiany sygnału analogowego (ciągłego) na sygnał cyfrowy (dyskretne wartości w postaci bitów).
Dzięki temu mikrokontrolery, komputery i układy cyfrowe mogą przetwarzać sygnały rzeczywiste, np. napięcie z czujnika temperatury, mikrofonu czy fotodiody.

---

### 2. Budowa ogólna

Przetwornik A/C składa się z kilku podstawowych bloków:

* **Układ próbkująco-pamiętający (Sample & Hold)** – pobiera w danym momencie wartość napięcia wejściowego i utrzymuje ją na czas konwersji.
* **Komparator(y)** – porównują napięcie wejściowe z napięciami wzorcowymi.
* **Źródło napięcia odniesienia (Vref)** – określa maksymalny zakres przetwornika i jego dokładność.
* **Układ logiczny (rejestry, liczniki)** – przetwarza wyniki porównań na postać binarną.
* **Interfejs wyjściowy** – wysyła wynik konwersji do układu cyfrowego (np. mikrokontrolera).

---

### 3. Zasada działania

1. Na wejście podawany jest sygnał analogowy (napięcie).
2. Układ próbkujący pobiera jego wartość.
3. Komparatory i układ logiczny porównują tę wartość z napięciami wzorcowymi.
4. Wynik zostaje zamieniony na kod binarny (np. 8-bitowy, 10-bitowy, 12-bitowy).
5. Na wyjściu pojawia się liczba całkowita odpowiadająca wartości napięcia wejściowego.

---

### 4. Ważne parametry

* **Rozdzielczość** – liczba bitów wyniku (np. 8 bitów → 256 poziomów, 10 bitów → 1024 poziomy).
* **Czas konwersji** – ile czasu potrzeba na wykonanie pojedynczego pomiaru.
* **Dokładność** – jak blisko wynik odpowiada rzeczywistej wartości napięcia.
* **Zakres napięć wejściowych** – zwykle od 0 do napięcia odniesienia (Vref).

---

### 5. Typy przetworników A/C

* **Successive Approximation (SAR)** – najczęściej spotykane w mikrokontrolerach, kompromis między szybkością a dokładnością.
* **Równoległe (flash)** – bardzo szybkie, używane w oscyloskopach i systemach wideo, wymagają wielu komparatorów.
* **Sigma-Delta (ΔΣ)** – wysoka dokładność, często stosowane w pomiarach precyzyjnych i audio.
* **Integracyjne (np. podwójnego całkowania)** – używane w miernikach uniwersalnych, bardzo dokładne, ale wolne.

---


### 6. Zakres pomiarowy i rozdzielczość

Załóżmy, że przetwornik pracuje w pełnej skali pomiaru od **–10 V do +10 V**.

* **Rozdzielczość**: 14 bitów → liczba poziomów kwantyzacji:
  2^14 = **16384 poziomy**.
* **Rozdzielczość napięciowa (tzw. LSB)**:
  (20 V) / (16384) = **0,00122 V = 1,22 mV**.

Oznacza to, że najmniejsza różnica napięcia, jaką potrafi odróżnić ten przetwornik, wynosi **1,22 mV**.

W praktyce jednak dokładność zależy nie tylko od teoretycznej rozdzielczości, ale także od:

* **szumów** w układzie,
* **jakości źródła napięcia odniesienia**,
* **parametrów komparatorów i układu próbkującego**.

Stąd ważny jest **stosunek sygnału do szumu (SNR)** – im lepszy, tym użyteczna rozdzielczość jest bliższa tej teoretycznej.

---

### 7. Budowa prostego przetwornika – metoda równoległa (Flash ADC)

To najprostsza koncepcja, dobrze nadająca się do zrozumienia działania:

1. **Wejście analogowe** → podawane jest napięcie, które chcemy zamienić na kod cyfrowy.
2. **Źródło napięcia odniesienia (Vref)** → ustala zakres przetwarzania (np. 0–5 V).
3. **Dzielnik rezystorowy** → dzieli napięcie odniesienia na wiele poziomów (np. dla 3-bitowego przetwornika 2^3 – 1 = 7 poziomów).
4. **Komparatory** – każdy porównuje napięcie wejściowe z jednym z napięć z dzielnika.
5. **Układ logiczny (dekoder priorytetowy)** – zamienia wyniki komparatorów na kod binarny.

#### 8. Przykład – Flash ADC 3-bitowy (0–5 V):

* Dzielnik rezystorowy tworzy progi co 0,625 V (5 V / 8 poziomów).
* Jeśli na wejściu jest 2,1 V:

  * komparatory „poniżej 2,1 V” dają sygnał 1,
  * komparatory „powyżej 2,1 V” dają sygnał 0,
  * układ logiczny koduje wynik jako **011** (czyli poziom 3 → 1,875 V).

Widać, że wynik nie jest dokładnie równy 2,1 V – różnica to **błąd kwantyzacji**.

