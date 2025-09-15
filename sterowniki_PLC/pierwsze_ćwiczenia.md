# Zadania PLC – wejścia/wyjścia (bez timerów i liczników)

Każde zadanie ma przypisaną punktację. Uczeń wybiera 10 zadań.  
Oceny:  
- 2: 10–14 pkt  
- 3: 15–19 pkt  
- 4: 20–24 pkt  
- 5: 25–30 pkt  

---

## 1. Proste sterowanie lampką (1 pkt)
Wejście: S1  
Wyjście: L1  
Po naciśnięciu przycisku lampka ma się zapalić, po puszczeniu – zgasnąć.  

---

## 2. Włączanie dwoma przyciskami (1 pkt)
Lampka świeci tylko wtedy, gdy oba przyciski są wciśnięte.  

---

## 3. Logika OR (1 pkt)
Lampka świeci, jeśli S1=1 lub S2=1.  

---

## 4. Lampka kontrolna (2 pkt)
Dwa przyciski, trzy lampki – przy obu wciśniętych zapala się dodatkowa L3.  

---

## 5. Bramki logiczne (2 pkt)
Zrealizuj w PLC NOT, AND, OR.  

---

## 6. Sterowanie „Start/Stop” (2 pkt)
Start włącza, Stop wyłącza lampkę.  

---

## 7. Lampka alarmowa (2 pkt)
Alarm zapala się, jeśli drzwi lub okno są otwarte.  

---

## 8. Sterowanie „korytarzowe” (3 pkt)
Lampka świeci tylko wtedy, gdy S1 ≠ S2.  

---

## 9. Priorytet wejścia (3 pkt)
Jeśli oba przyciski są wciśnięte, lampka reaguje tylko na S1.  

---

## 10. Proste sterowanie sygnalizacją (3 pkt)
Zielona przy obecności, czerwona przy braku. Awaryjne wyłączenie – oba gasną.  

---

## 11. Sterowanie wentylatorem i lampką (3 pkt)
S3 wyłącza wszystko, reszta działa niezależnie.  

---

## 12. „Selekcja źródła” (3 pkt)
Zależnie od stanu wejść świeci L1 lub L2, przy obu – tylko L1.  

---

## 13. Sygnalizacja „otwarte/zamknięte” (2 pkt)
Zielona przy zamkniętych drzwiach i oknie, czerwona gdy coś otwarte.  

---

## 14. Trzy przyciski – jeden wybór (3 pkt)
Tylko jeden przycisk wybiera jedną lampkę. Jeśli kilka naraz – wszystko gaśnie.  

---

## 15. Bramki XOR i XNOR (3 pkt)
XOR – świeci gdy jeden przycisk wciśnięty, XNOR – świeci gdy oba takie same.  

---

## 16. Sygnalizacja ewakuacyjna (3 pkt)
Alarm przy dymie, lampka kierunkowa przy dymie i ruchu.  

---

## 17. Priorytet bezpieczeństwa (3 pkt)
Start włącza lampkę, Stop awaryjny zawsze gasi.  

---

## 18. Sygnalizacja dwustopniowa (3 pkt)
S1 włącza L1, S1+S2 włącza L1 i L2, samo S2 nic.  

---

## 19. Kontrola drzwi dwuskrzydłowych (2 pkt)
Zamknięte – L1, otwarte – L2.  

---

## 20. Proste zabezpieczenie maszynowe (3 pkt)
Maszyna działa tylko przy zamkniętej osłonie i naciśniętym Start.  

---

## 21. Kontrola dwóch pomp (4 pkt)
Dwie pompy sterowane dwoma czujnikami, mogą działać jednocześnie.  

---

## 22. Sygnalizacja wejścia do hali (3 pkt)
Zielona gdy drzwi zamknięte i brak ruchu, inaczej czerwona.  

---

## 23. System wyboru trybu (3 pkt)
AUTO ma priorytet nad RĘCZNYM.  

---

## 24. Kontrola temperatury (3 pkt)
Zależnie od czujników zimno/gorąco – włącza się grzanie lub chłodzenie.  

---

## 25. Sterowanie wentylatorem (2 pkt)
Wentylator działa przy ręcznym włączeniu lub dymie.  

---

## 26. Bramki logiczne w praktyce (4 pkt)
Zrealizuj układ:  
- L1 = (S1 AND S2)  
- L2 = (S1 OR S3)  
- L3 = NOT S2  

---

## 27. Sterowanie syreną alarmową (3 pkt)
Syrena działa, gdy aktywny jest dowolny czujnik.  

---

## 28. „Interlock” dwóch urządzeń (4 pkt)
Nie można uruchomić obu maszyn jednocześnie.  

---

## 29. Układ bezpieczeństwa bramy (4 pkt)
Sygnalizacja otwarcia/zamknięcia + alarm w przypadku błędu (oba 1).  

---

## 30. Sygnalizacja priorytetowa (5 pkt)
Trzy stany wejściowe, trzy lampki, działa tylko ta o najwyższym priorytecie.  
