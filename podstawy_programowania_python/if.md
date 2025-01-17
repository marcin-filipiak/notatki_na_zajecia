### Instrukcja `if` w Pythonie  

Instrukcja `if` służy do podejmowania decyzji w programie na podstawie określonych warunków logicznych. Pozwala na wykonanie różnych bloków kodu w zależności od tego, czy dany warunek jest spełniony (prawdziwy), czy nie.

---

#### 1. **Podstawowa składnia**  
```python
if warunek:
    # Kod do wykonania, jeśli warunek jest prawdziwy
```

**Przykład:**
```python
x = 10
if x > 5:
    print("x jest większe od 5")  # Ten kod zostanie wykonany
```

---

#### 2. **Instrukcja `if-else`**  
Jeśli warunek w `if` nie jest spełniony, można określić blok kodu do wykonania za pomocą `else`.  
```python
if warunek:
    # Kod, gdy warunek jest prawdziwy
else:
    # Kod, gdy warunek jest fałszywy
```

**Przykład:**
```python
x = 3
if x > 5:
    print("x jest większe od 5")
else:
    print("x jest mniejsze lub równe 5")  # Ten kod zostanie wykonany
```

---

#### 3. **Instrukcja `if-elif-else`**  
Gdy istnieje wiele warunków, można użyć `elif` (skrót od "else if").  
```python
if warunek1:
    # Kod, gdy warunek1 jest prawdziwy
elif warunek2:
    # Kod, gdy warunek1 jest fałszywy, ale warunek2 jest prawdziwy
else:
    # Kod, gdy żaden z powyższych warunków nie jest prawdziwy
```

**Przykład:**
```python
x = 7
if x > 10:
    print("x jest większe od 10")
elif x > 5:
    print("x jest większe od 5, ale mniejsze lub równe 10")  # Ten kod zostanie wykonany
else:
    print("x jest mniejsze lub równe 5")
```

---

#### 4. **Warunki logiczne**  
Warunki w `if` mogą opierać się na operatorach porównania:  
- `==` – równość  
- `!=` – różność  
- `<`, `>`, `<=`, `>=` – porównania  

**Przykład:**
```python
x = 10
if x % 2 == 0:
    print("x jest parzyste")
else:
    print("x jest nieparzyste")
```

---

#### 5. **Łączenie warunków**  
Warunki można łączyć za pomocą operatorów logicznych:  
- `and` – oba warunki muszą być prawdziwe  
- `or` – przynajmniej jeden warunek musi być prawdziwy  
- `not` – negacja warunku  

**Przykład:**
```python
x = 8
if x > 5 and x < 10:
    print("x jest większe od 5 i mniejsze od 10")  # Ten kod zostanie wykonany
```

---

#### 6. **Zagnieżdżone instrukcje `if`**  
Instrukcje `if` można zagnieżdżać w celu bardziej złożonej logiki:  
```python
x = 15
if x > 10:
    if x < 20:
        print("x jest między 10 a 20")
```

---

#### 7. **Wyrażenie warunkowe (skrócony `if`)**  
Można zapisać instrukcję warunkową w jednej linii:  
```python
wynik = "parzysta" if x % 2 == 0 else "nieparzysta"
print(wynik)
```

---

#### 8. **Falsy i Truthy**  
Python interpretuje pewne wartości jako **prawdziwe (truthy)**, a inne jako **fałszywe (falsy)**:
- **Falsy**: `0`, `None`, puste kolekcje (`[]`, `{}`, `""`)  
- **Truthy**: Wszystko inne  

**Przykład:**
```python
x = []
if x:
    print("Lista nie jest pusta")
else:
    print("Lista jest pusta")  # Ten kod zostanie wykonany
```

---

Instrukcja `if` jest jednym z podstawowych narzędzi sterowania przepływem programu w Pythonie, a jej elastyczność pozwala na implementację nawet skomplikowanej logiki.
