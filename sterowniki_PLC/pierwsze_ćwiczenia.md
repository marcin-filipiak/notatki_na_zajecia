# Zadania PLC – wejścia/wyjścia (bez liczników i timerów)

Uczeń wybiera **10 zadań** do realizacji.  
Za każde zadanie przyznawane są punkty w zależności od trudności.  
Na podstawie sumy punktów wystawiana jest ocena.  

## Punktacja i progi ocen
- 0–9 pkt → niedostateczny  
- 10–13 pkt → dopuszczający  
- 14–17 pkt → dostateczny  
- 18–21 pkt → dobry  
- 22 i więcej pkt → bardzo dobry  

---

## Zadania

### Zadanie 1 (1 pkt)  
Sterowanie pojedynczą lampką.  
- Wejście: S1 – przycisk.  
- Wyjście: L1 – lampka.  
Treść: Po naciśnięciu przycisku lampka ma się zapalić, po puszczeniu – zgasnąć.  

---

### Zadanie 2 (1 pkt)  
Logika AND.  
- Wejścia: S1, S2 – przyciski.  
- Wyjście: L1 – lampka.  
Treść: Lampka świeci tylko wtedy, gdy oba przyciski są wciśnięte jednocześnie.  

---

### Zadanie 3 (1 pkt)  
Logika OR.  
- Wejścia: S1, S2 – przyciski.  
- Wyjście: L1 – lampka.  
Treść: Lampka świeci, jeśli wciśnięty jest przycisk S1 lub S2 (albo oba naraz).  

---

### Zadanie 4 (2 pkt)  
Sterowanie wieloma lampkami.  
- Wejścia: S1, S2 – przyciski.  
- Wyjścia: L1, L2, L3 – lampki.  
Treść:  
- Jeśli S1 = 1 → świeci L1.  
- Jeśli S2 = 1 → świeci L2.  
- Jeśli oba przyciski są wciśnięte → dodatkowo zapala się L3.  

---

### Zadanie 5 (2 pkt)  
Bramki logiczne w PLC.  
- Wejścia: S1, S2 – przyciski.  
- Wyjście: L1 – lampka.  
Treść:  
Zaprogramuj układ tak, aby można było zobaczyć działanie trzech funkcji logicznych:  
- NOT (odwrócenie sygnału S1),  
- AND (S1 i S2),  
- OR (S1 lub S2).  

---

### Zadanie 6 (2 pkt)  
Sterowanie Start/Stop bez podtrzymania.  
- Wejścia: S1 – Start, S2 – Stop.  
- Wyjście: L1 – lampka.  
Treść: Lampka świeci, gdy S1 jest wciśnięty, i gaśnie, gdy S2 jest wciśnięty.  

---

### Zadanie 7 (2 pkt)  
Lampka alarmowa.  
- Wejścia: S1 – czujnik drzwi, S2 – czujnik okna.  
- Wyjście: L1 – lampka alarmowa.  
Treść: Alarm (L1) zapala się, gdy otwarte są drzwi lub okno (S1=1 lub S2=1).  

---

### Zadanie 8 (3 pkt)  
Sterowanie korytarzowe (xor).  
- Wejścia: S1, S2 – przyciski.  
- Wyjście: L1 – lampka.  
Treść: Lampka świeci tylko wtedy, gdy dokładnie jeden przycisk jest wciśnięty (S1 ≠ S2).  

---

### Zadanie 9 (3 pkt)  
Priorytet wejścia.  
- Wejścia: S1, S2 – przyciski.  
- Wyjście: L1 – lampka.  
Treść: Jeśli oba przyciski są wciśnięte, lampka reaguje tylko na S1 (priorytet S1).  

---

### Zadanie 10 (3 pkt)  
Proste sterowanie sygnalizacją.  
- Wejścia: S1 – czujnik obecności, S2 – wyłącznik ręczny.  
- Wyjścia: L1 – lampka zielona, L2 – lampka czerwona.  
Treść:  
- Jeśli S1 = 1 → świeci L1 (zielone).  
- Jeśli S1 = 0 → świeci L2 (czerwone).  
- Jeśli S2 = 1 → oba światła gasną (awaryjne wyłączenie).  

---

### Zadanie 11 (3 pkt)  
Sterowanie silnikiem wentylatora.  
- Wejścia: S1 – Start, S2 – Stop, S3 – Awaria.  
- Wyjście: L1 – lampka (symulacja pracy silnika).  
Treść:  
- Po naciśnięciu S1 lampka świeci.  
- Po naciśnięciu S2 lampka gaśnie.  
- Jeśli S3 = 1, lampka gaśnie i nie można jej włączyć, dopóki S3 nie wróci do 0.  

---

### Zadanie 12 (3 pkt)  
Sterowanie bramą wjazdową.  
- Wejścia: S1 – otwieranie, S2 – zamykanie, S3 – czujnik bezpieczeństwa.  
- Wyjścia: L1 – lampka otwierania, L2 – lampka zamykania.  
Treść:  
- Gdy wciśnięte S1 → świeci L1.  
- Gdy wciśnięte S2 → świeci L2.  
- Gdy S3 = 1 (przeszkoda), oba wyjścia gasną.  

---

### Zadanie 13 (4 pkt)  
Sterowanie windą (uproszczone).  
- Wejścia: S1 – przycisk góra, S2 – przycisk dół, S3 – krańcówka góra, S4 – krańcówka dół.  
- Wyjścia: L1 – lampka jazda w górę, L2 – lampka jazda w dół.  
Treść:  
- Gdy wciśnięty S1 i S3 = 0 → świeci L1 (jazda w górę).  
- Gdy wciśnięty S2 i S4 = 0 → świeci L2 (jazda w dół).  
- Jeśli krańcówka = 1 → dany kierunek jest zablokowany.  

---

### Zadanie 14 (4 pkt)  
Sygnalizacja skrzyżowania (uproszczona).  
- Wejścia: S1 – tryb dzień/noc.  
- Wyjścia: L1 – czerwone, L2 – żółte, L3 – zielone.  
Treść:  
- W trybie dzień (S1=0) świeci tylko L1 (czerwone).  
- W trybie noc (S1=1) miga L2 (żółte). *(miganie można zasymulować ręcznie przez włączanie/wyłączanie przycisku w rytmie)*.  

---

### Zadanie 15 (5 pkt)  
Sterowanie pompą wody.  
- Wejścia: S1 – czujnik poziomu dolnego, S2 – czujnik poziomu górnego, S3 – tryb ręczny.  
- Wyjście: L1 – pompa.  
Treść:  
- Jeśli poziom niski (S1=1) i S2=0 → pompa się włącza.  
- Jeśli S2=1 → pompa się wyłącza.  
- W trybie ręcznym (S3=1) → pompa włącza się niezależnie od poziomu.  

---
