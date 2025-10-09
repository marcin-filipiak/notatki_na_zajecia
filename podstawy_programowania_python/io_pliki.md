# Odczyt i zapis do plików w Pythonie

---

### **1. Podstawowe informacje**

Python pozwala na operacje na plikach tekstowych i binarnych.
Do pracy z plikami używa się funkcji wbudowanej `open()`, a po zakończeniu operacji plik powinien zostać zamknięty (`close()`), choć częściej stosuje się konstrukcję `with`, która automatycznie zamyka plik.

---

### **2. Tryby otwierania plików**

| Tryb   | Opis                                                     |
| ------ | -------------------------------------------------------- |
| `'r'`  | Odczyt (read), plik musi istnieć                         |
| `'w'`  | Zapis (write), tworzy nowy plik lub nadpisuje istniejący |
| `'a'`  | Dopisywanie (append), zapis na końcu pliku               |
| `'rb'` | Odczyt binarny                                           |
| `'wb'` | Zapis binarny                                            |
| `'ab'` | Dopisywanie binarne                                      |
| `'x'`  | Tworzy nowy plik, zwraca błąd jeśli istnieje             |

---

### **3. Odczyt z pliku**

**Przykład 1: odczyt całej zawartości**

```python
with open("plik.txt", "r") as f:
    zawartosc = f.read()
    print(zawartosc)
```

**Przykład 2: odczyt linia po linii**

```python
with open("plik.txt", "r") as f:
    for linia in f:
        print(linia.strip())  # .strip() usuwa znak nowej linii
```

**Przykład 3: odczyt do listy**

```python
with open("plik.txt", "r") as f:
    linie = f.readlines()  # każda linia jako element listy
```

---

### **4. Zapis do pliku**

**Przykład 1: nadpisanie pliku**

```python
with open("plik.txt", "w") as f:
    f.write("To jest pierwsza linia\n")
    f.write("To jest druga linia\n")
```

**Przykład 2: dopisywanie do istniejącego pliku**

```python
with open("plik.txt", "a") as f:
    f.write("Dodatkowa linia\n")
```

**Przykład 3: zapis listy linijek**

```python
linie = ["Pierwsza linia\n", "Druga linia\n", "Trzecia linia\n"]
with open("plik.txt", "w") as f:
    f.writelines(linie)
```

---

### **5. Odczyt i zapis plików binarnych**

**Odczyt**

```python
with open("obraz.png", "rb") as f:
    dane = f.read()
```

**Zapis**

```python
with open("kopia.png", "wb") as f:
    f.write(dane)
```

---

### **6. Dodatkowe uwagi**

* Konstrukcja `with open(...) as f:` automatycznie zamyka plik po zakończeniu bloku.
* Do odczytu dużych plików warto używać pętli po liniach zamiast `read()`, aby nie załadować całego pliku do pamięci.
* `strip()` usuwa znaki białe, w tym `\n`.
* W trybach binarnych (`rb`, `wb`, `ab`) odczyt i zapis operuje na obiektach `bytes`, a nie `str`.
