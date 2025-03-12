### **Zadanie: Najkrótsza droga w grafie**  

#### **Treść zadania:**  
Napisz program w C++, który znajdzie **najkrótszą ścieżkę** między wierzchołkami **A** i **B** w grafie:  

```
     (A)
     /   \
   4 /     \ 1
    /       \
  (B) ---- (C)
      2
```

Program powinien:  
1. **Pobrać od użytkownika wagi krawędzi** dla:  
   - A → B  
   - A → C  
   - B → C  
2. **Znaleźć najkrótszą drogę z A do B** algorytmem Dijkstry.  
3. **Wypisać wynik**: najkrótszy dystans oraz ścieżkę.  

---

### **Przykładowe dane wejściowe:**  
```
Podaj wagę A → B: 4
Podaj wagę A → C: 1
Podaj wagę B → C: 2
```

### **Przykładowe wyjście:**  
```
Najkrótsza droga z A do B: A -> C -> B, koszt: 3
```
