

### 🔧 **Zadania 1–10: Podstawy sterowania wejściami i wyjściami**

1. **Lampka kontrolna** – lampka %Q0.0 świeci, gdy przycisk %I0.0 jest wciśnięty.
2. **Lampka z pamięcią** – po wciśnięciu %I0.0 lampka %Q0.0 zapala się i **zapamiętuje stan**; gasi się dopiero po wciśnięciu %I0.1.
3. **Przełącznik naprzemienny** – jednym przyciskiem %I0.0 naprzemiennie włączaj/wyłączaj lampkę %Q0.0.
4. **Dwie lampki naprzemienne** – po każdym wciśnięciu %I0.0 przełączaj stan między %Q0.0 i %Q0.1.
5. **Lampka ostrzegawcza** – lampka %Q0.0 miga z częstotliwością 1 Hz (użyj timera TON 500 ms + XOR).
6. **Start bez pamięci** – elektrozawór %Q0.0 aktywny tylko **podczas** trzymania przycisku %I0.0.
7. **Start z pamięcią** – elektrozawór %Q0.0 włączony po naciśnięciu %I0.0, wyłączony po %I0.1.
8. **Samopodtrzymanie siłownika** – elektrozawór %Q0.0 włączony po %I0.0, ale **automatycznie wyłączony**, gdy siłownik osiągnie pozycję krańcową %I0.2.
9. **Bezpieczeństwo mechaniczne** – elektrozawór %Q0.0 może być włączony tylko, gdy siłownik jest **w pozycji początkowej** (%I0.3 = 1).
10. **Sygnalizacja ruchu** – lampka %Q0.1 świeci, gdy siłownik **jest w ruchu** (czyli %Q0.0 = 1 i żaden z czujników krańcowych nie jest aktywny).

---

### 🔧 **Zadania 11–20: Sterowanie siłownikiem z czujnikami krańcowymi**

11. **Automatyczne wysunięcie** – po naciśnięciu %I0.0 siłownik wysuwa się (elektrozawór %Q0.0), a po dotarciu do %I0.2 **automatycznie się cofa** (elektrozawór %Q0.1) i zatrzymuje w %I0.3.
12. **Cykl jednokrotny** – jak wyżej, ale cykl uruchamia się **raz** po naciśnięciu %I0.0.
13. **Cykl ciągły** – po naciśnięciu %I0.0 siłownik wykonuje **ciągłe ruchy tam i z powrotem**, dopóki nie wciśniesz %I0.1.
14. **Czasowy limit ruchu** – siłownik może działać maks. **3 sekundy** (użyj timera TON); po tym czasie zostaje wyłączony, nawet jeśli nie osiągnął krańców.
15. **Blokada przeciwwypadkowa** – siłownik **nie może się ruszyć**, jeśli oba czujniki krańcowe (%I0.2 i %I0.3) są jednocześnie aktywne (błąd mechaniczny).
16. **Sygnalizacja błędu** – jeśli siłownik nie osiągnie krańca w ciągu 5 s, zapal lampkę %Q0.2 jako alarm.
17. **Ręczne sterowanie** – %I0.0 = wysuń, %I0.1 = wsuń; elektrozawory %Q0.0/%Q0.1 aktywne tylko podczas trzymania przycisków.
18. **Półautomatyczne sterowanie** – %I0.0 = wysuń i zatrzymaj w %I0.2; %I0.1 = wsuń i zatrzymaj w %I0.3.
19. **Zabezpieczenie przed jednoczesnym włączeniem** – upewnij się, że **%Q0.0 i %Q0.1 nigdy nie są włączone jednocześnie** (bezpieczeństwo!).
20. **Potwierdzenie pozycji** – lampka %Q0.0 świeci, gdy siłownik jest w %I0.3; %Q0.1 – gdy w %I0.2.

---

### 🔧 **Zadania 21–30: Timery i sekwencje czasowe**

21. **Opóźnione włączenie** – po naciśnięciu %I0.0 elektrozawór %Q0.0 włącza się po **2 sekundach**.
22. **Opóźnione wyłączenie** – po puszczeniu %I0.0 elektrozawór %Q0.0 działa jeszcze **1 sekundę**.
23. **Migająca lampka alarmu** – po aktywacji %I0.0 lampka %Q0.2 miga **do momentu wciśnięcia %I0.1**.
24. **Czasowy test ruchu** – po naciśnięciu %I0.0 siłownik wysuwa się na 3 s, potem cofa na 3 s, niezależnie od czujników.
25. **Sygnalizacja gotowości** – po uruchomieniu systemu (%S1 = 1) lampka %Q0.0 świeci przez 5 s, potem gaśnie.
26. **Limit czasu pracy** – elektrozawór %Q0.0 może być aktywny max **10 s na raz**; po tym czasie musi zostać wyłączony i odczekany 5 s przed ponownym użyciem.
27. **Impuls startowy** – po naciśnięciu %I0.0 generuj **impuls 500 ms** na %Q0.0 (np. do testu elektrozaworu).
28. **Opóźniona sygnalizacja** – po osiągnięciu %I0.2 zapal lampkę %Q0.1 dopiero po **1 s**.
29. **Czasowy reset alarmu** – po aktywacji alarmu (%Q0.2) można go zresetować **dopiero po 3 s** trzymania %I0.1.
30. **Sekwencja: włącz → czekaj → wyłącz** – %I0.0 → włącz %Q0.0 → czekaj 2 s → wyłącz %Q0.0.

---

### 🔧 **Zadania 31–40: Logika kombinacyjna i bezpieczeństwo**

31. **Start tylko z dwóch przycisków** – elektrozawór %Q0.0 włącza się tylko, gdy **jednocześnie** wciśnięte są %I0.0 i %I0.4 (bezpieczeństwo dwuręczne).
32. **Blokada awaryjna** – jeśli %I0.5 (STOP awaryjny) = 0, **wszystkie wyjścia są wyłączone**.
33. **Tryb serwisowy** – gdy %I0.6 = 1, wszystkie funkcje automatyczne są **wyłączone**, działa tylko ręczne sterowanie.
34. **Zliczanie cykli** – po każdym pełnym cyklu (wysunięcie + cofnięcie) zwiększ licznik w pamięci (np. %MW0); wyświetl jego LSB na lampkach %Q0.0–%Q0.3.
35. **Alarm przy braku ruchu** – jeśli siłownik nie zmienił pozycji w ciągu 5 s od włączenia %Q0.0, zapal %Q0.2.
36. **Zabezpieczenie przed przegrzaniem** – po 5 cyklach pracy wymuś **przerwę 10 s** (blokada nowych startów).
37. **Sygnalizacja trybu pracy** – %Q0.0 = ręczny, %Q0.1 = automatyczny (ustal tryb przyciskiem %I0.7).
38. **Test czujników** – po naciśnięciu %I0.0 sprawdź, czy oba czujniki krańcowe **kiedykolwiek były aktywne**; jeśli tak, zapal %Q0.2.
39. **Logika bezpieczeństwa** – elektrozawór %Q0.0 może działać **tylko**, gdy:  
   - siłownik w %I0.3,  
   - brak STOP awaryjnego (%I0.5 = 1),  
   - nie ma alarmu (%Q0.2 = 0).
40. **Symulacja braku powietrza** – jeśli %I0.2 i %I0.3 są **obie nieaktywne przez >2 s**, uznaj to za brak ciśnienia i zapal alarm %Q0.2.
