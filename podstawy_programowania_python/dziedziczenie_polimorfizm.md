# Dziedziczenie i polimorfizm

### **Dziedziczenie**

* Dziedziczenie pozwala **tworzyć nowe klasy na podstawie już istniejących**.
* Nowa klasa (tzw. **klasa pochodna**) **przejmuje** atrybuty i metody klasy bazowej, a może też **dodawać własne** lub **nadpisywać istniejące**.

Przykład:

```python
class Zwierze:
    def __init__(self, gatunek):
        self.gatunek = gatunek

    def dzwiek(self):
        print("To zwierzę wydaje jakiś dźwięk.")

# Klasa pochodna dziedziczy po klasie Zwierze
class Pies(Zwierze):
    def __init__(self, imie):
        super().__init__("pies")  # wywołanie konstruktora klasy bazowej
        self.imie = imie

    def dzwiek(self):  # nadpisanie metody z klasy bazowej
        print("Hau hau!")
```

Tworzenie obiektów:

```python
z = Zwierze("kot")
p = Pies("Burek")

z.dzwiek()   # To zwierzę wydaje jakiś dźwięk.
p.dzwiek()   # Hau hau!
```

---

### **Słowo kluczowe `super()`**

* Umożliwia wywołanie metody z klasy bazowej w klasie pochodnej.
* Najczęściej używane w konstruktorze (`__init__`), by odziedziczyć inicjalizację atrybutów.

Przykład:

```python
super().__init__(argumenty)
```

---

### **Polimorfizm**

* Polimorfizm oznacza, że **różne klasy mogą mieć metody o tej samej nazwie**, ale działające w inny sposób.
* Pozwala pisać kod, który **działa na różnych typach obiektów w podobny sposób**.

Przykład:

```python
class Kot(Zwierze):
    def dzwiek(self):
        print("Miau!")

class Krowa(Zwierze):
    def dzwiek(self):
        print("Muu!")

# polimorficzne wywołanie tej samej metody
zwierzeta = [Pies("Reksio"), Kot("Filemon"), Krowa("Mućka")]

for z in zwierzeta:
    z.dzwiek()    # każdy obiekt wywoła własną wersję metody
```

Wynik:

```
Hau hau!
Miau!
Muu!
```

---

### **Różnice między klasą bazową a pochodną**

| Pojęcie            | Znaczenie                                                        | Przykład                                           |
| ------------------ | ---------------------------------------------------------------- | -------------------------------------------------- |
| **Klasa bazowa**   | Klasa, z której dziedziczą inne                                  | `class Zwierze:`                                   |
| **Klasa pochodna** | Klasa rozszerzająca lub modyfikująca klasę bazową                | `class Pies(Zwierze):`                             |
| **Polimorfizm**    | Wiele klas ma metodę o tej samej nazwie, ale innej implementacji | `z.dzwiek()` dla różnych zwierząt daje różny wynik |
