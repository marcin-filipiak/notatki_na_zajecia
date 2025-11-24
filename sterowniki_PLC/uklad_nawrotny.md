# Układ nawrotny silnika

## 1. Co to jest układ nawrotny?

Układ nawrotny (rewersyjny) służy do **zmiany kierunku obrotów silnika trójfazowego**.
Realisuje się to przez **zamianę kolejności dwóch faz** zasilających silnik.

Stosowany w:

* suwnicach, wciągarkach, podajnikach,
* przenośnikach,
* maszynach wymagających pracy lewo/prawo,
* napędach z hamowaniem.

---

# 2. Podstawowe elementy układu nawrotnego

1. **Silnik trójfazowy**
   Najczęściej asynchroniczny klatkowy.

2. **Dwa styczniki**

   * K1 – praca w przód (np. L1–U, L2–V, L3–W)
   * K2 – praca w tył (zamiana dwóch faz: L1–V, L2–U, L3–W)

3. **Blokada mechaniczna**
   Uniemożliwia fizyczne załączenie obu styczników naraz.

4. **Blokada elektryczna (krzyżowa)**

   * Styk NC od K1 w obwodzie cewki K2
   * Styk NC od K2 w obwodzie cewki K1

5. **Wyłącznik główny / rozłącznik izolacyjny**

6. **Zabezpieczenia przed przeciążeniem**
   Wyłącznik przeciążeniowy (termik) z wyjściowym stykiem NC w obwodzie sterowania.

7. **Zabezpieczenia zwarciowe**
   Bezpieczniki topikowe, wyłącznik nadprądowy lub stycznik + wyłącznik mocy.

8. **Przyciski sterujące**

   * START LEWO
   * START PRAWO
   * STOP (NC)

9. **Kontrolka pracy kierunku** (opcjonalnie)

---

# 3. Zasada działania układu nawrotnego

### Kierunek PRAWO (przód)

1. Naciśnięcie przycisku START PRAWO → zasilanie cewki stycznika **K1**.
2. K1 załącza się, styki główne ustawiają kolejność faz L1-L2-L3 → silnik obraca się w kierunku PRAWO.
3. Styk pomocniczy K1 (NO) podtrzymuje zasilanie cewki po puszczeniu przycisku.
4. Jednocześnie styk NC od K1 umieszczony w obwodzie K2 **blokuje** załączenie kierunku LEWO.

### Kierunek LEWO (wstecz)

1. Naciśnięcie przycisku START LEWO → zasilanie cewki stycznika **K2**.
2. Styki główne K2 zamieniają kolejność dwóch faz → odwrotne pole → przeciwny kierunek obrotów.
3. Styk NO od K2 zapewnia podtrzymanie.
4. Styk NC K2 blokuje możliwość załączenia K1.

---

# 4. Blokady w układzie nawrotnym

## 1. Blokada elektryczna (krzyżowa)

Najważniejsza blokada.

* W obwód sterowania cewki K1 wstawia się styk **NC** od K2.
* W obwód sterowania cewki K2 – styk **NC** od K1.

Zabezpiecza przed:

* przypadkowym załączeniem obu kierunków naraz,
* zwarciem międzyfazowym,
* uszkodzeniem silnika i styczników.

## 2. Blokada mechaniczna

Fizyczne połączenie dwóch styczników.
Jeżeli jeden jest załączony, drugi nie może się stycznie zamknąć.

---

# 5. Obwód sterowania – opis krok po kroku

### Elementy typowego sterowania:

* STOP (NC) – wspólny dla obu kierunków
* START PRAWO (NO)
* START LEWO (NO)
* Termik F2 – styk NC
* Podtrzymanie z NO od K1 i K2
* Blokada z NC od K1 i K2

### Praca PRAWO:

STOP → Termik NC → NC K2 → START PRAWO → cewka K1 → podtrzymanie NO K1

### Praca LEWO:

STOP → Termik NC → NC K1 → START LEWO → cewka K2 → podtrzymanie NO K2

---

# 6. Podłączenia faz w układzie nawrotnym

### Kierunek PRAWO

L1 → U
L2 → V
L3 → W

### Kierunek LEWO

L1 → V
L2 → U
L3 → W
(czyli zamiana dwóch faz: L1 z L2)

---

# 7. Elementy zabezpieczające

## Zabezpieczenie przeciążeniowe (termik)

* Umieszczony za stycznikiem, przed silnikiem.
* Styki grzejne w torach fazowych.
* Styk NC w obwodzie sterowania → rozłącza sterowanie przy przeciążeniu.

## Zabezpieczenie zwarciowe

* Bezpieczniki topikowe (gG)
  lub
* Wyłącznik nadprądowy
  lub
* Wyłącznik silnikowy jako element łączący oba zabezpieczenia.

---

# 8. Częste błędy i wymagania praktyczne

* Brak blokady krzyżowej → ryzyko zwarcia międzyfazowego.
* Brak blokady mechanicznej → przy nacisku na oba przyciski jednocześnie może dojść do uszkodzenia.
* Brak termika w obwodzie sterowania → silnik nie wyłączy się przy przeciążeniu.
* Zbyt mała przerwa między zmianą kierunku → silnik musi zatrzymać się przed rewersem.

---

# 9. Co może pojawić się na egzaminie ELM.06

Najczęstsze zagadnienia:

* schemat obwodu mocy i sterowania układu nawrotnego,
* zastosowanie styków NC/NO w blokadach,
* kolejność faz przy zmianie kierunku,
* rola termika, bezpieczników i wyłącznika głównego,
* zasada działania rewersu,
* interpretacja schematu sterowania,
* opis podtrzymania stycznika,
* wskazanie błędów w schemacie.
