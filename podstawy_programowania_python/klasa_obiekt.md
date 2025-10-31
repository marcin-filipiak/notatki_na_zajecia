# Klasa, obiekt, metoda i atrybut w Pythonie

---

### **Klasa**

* Klasa to **szablon (wzorzec)**, który opisuje jak będą wyglądać i zachowywać się obiekty danego typu.
* Zawiera definicje **atrybutów** (czyli danych) i **metod** (czyli funkcji działających na tych danych).

Przykład:

```python
class Samochod:
    def __init__(self, marka, kolor):
        self.marka = marka      # atrybut
        self.kolor = kolor      # atrybut

    def jedz(self):              # metoda
        print("Samochód jedzie")
```

---

### **Obiekt**

* Obiekt to **konkretna instancja klasy**, czyli „rzeczywisty egzemplarz” zbudowany według wzorca klasy.
* Każdy obiekt ma swoje własne dane (atrybuty).

Przykład tworzenia obiektu:

```python
auto1 = Samochod("Toyota", "czerwony")
auto2 = Samochod("BMW", "czarny")
```

---

### **Atrybut**

* Atrybut to **zmienna przypisana do obiektu** lub klasy, która przechowuje dane.
* Można je odczytać lub zmienić przez notację kropkową.

Przykład:

```python
print(auto1.marka)     # wyświetli: Toyota
auto1.kolor = "biały"  # zmiana atrybutu
```

---

### **Metoda**

* Metoda to **funkcja zdefiniowana wewnątrz klasy**, która może korzystać z atrybutów obiektu.
* Pierwszy parametr metody to zawsze `self` – odniesienie do konkretnego obiektu.

Przykład:

```python
auto1.jedz()    # wywołanie metody
```

---

### **Podsumowanie pojęć**

| Pojęcie     | Znaczenie            | Przykład                                 |
| ----------- | -------------------- | ---------------------------------------- |
| **Klasa**   | Wzorzec dla obiektów | `class Samochod:`                        |
| **Obiekt**  | Egzemplarz klasy     | `auto1 = Samochod("Toyota", "czerwony")` |
| **Atrybut** | Dane obiektu         | `auto1.kolor`                            |
| **Metoda**  | Funkcja klasy        | `auto1.jedz()`                           |

