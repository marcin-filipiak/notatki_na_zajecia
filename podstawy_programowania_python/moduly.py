### Importowanie modułów w Pythonie  

W Pythonie moduły to pliki z kodem, które zawierają funkcje, klasy i zmienne, pomagając w organizacji i ponownym wykorzystaniu kodu. Moduły mogą być wbudowane, napisane przez użytkownika lub pobrane z zewnętrznych źródeł.  

---

#### 1. **Importowanie modułów w Pythonie**
Aby zaimportować moduł, używamy instrukcji `import`. Oto podstawowe sposoby:  

- Import całego modułu:  
  ```python
  import math
  print(math.sqrt(16))  # Wypisze 4.0
  ```
- Import wybranej funkcji lub klasy:  
  ```python
  from math import sqrt
  print(sqrt(16))  # Wypisze 4.0
  ```
- Nadanie aliasu modułowi lub funkcji:  
  ```python
  import math as m
  print(m.sqrt(16))  # Wypisze 4.0
  ```

---

#### 2. **Przykładowe moduły wbudowane**
Python dostarcza wiele wbudowanych modułów, które można od razu wykorzystać:  
- `math` – funkcje matematyczne: pierwiastki, logarytmy, trygonometria.  
- `random` – generowanie liczb losowych.  
- `datetime` – praca z datą i czasem.  
- `os` – operacje na systemie plików.  
- `sys` – dostęp do parametrów i funkcji interpretera.  

Przykład użycia:  
```python
import datetime
now = datetime.datetime.now()
print(f"Obecna data i czas: {now}")
```

---

#### 3. **Instalowanie modułów zewnętrznych**
Niektóre moduły wymagają instalacji, np. `requests` do obsługi HTTP. Można to zrobić za pomocą menedżera pakietów `pip` lub systemowego menedżera pakietów.  

##### Instalowanie modułów za pomocą `pip`:  
1. Sprawdź, czy masz zainstalowany `pip`:  
   ```bash
   python3 -m pip --version
   ```
2. Zainstaluj moduł:  
   ```bash
   python3 -m pip install requests
   ```
3. Użycie modułu w kodzie:  
   ```python
   import requests
   response = requests.get("https://api.github.com")
   print(response.status_code)
   ```

##### Instalowanie modułów za pomocą `apt` w Debianie:  
Niektóre moduły można zainstalować jako pakiety systemowe:  
- Instalacja modułu:  
  ```bash
  sudo apt update
  sudo apt install python3-requests
  ```
- Użycie w kodzie:  
  ```python
  import requests
  ```

---

#### 4. **Tworzenie własnych modułów**
Możesz pisać własne moduły, tworząc plik `.py`. Przykład:  
1. Utwórz plik `my_module.py`:  
   ```python
   def greet(name):
       return f"Hello, {name}!"
   ```
2. Zaimportuj i użyj modułu w innym skrypcie:  
   ```python
   import my_module
   print(my_module.greet("Alice"))  # Wypisze: Hello, Alice!
   ```

---

#### 5. **Przykładowe moduły do instalacji przez `apt`**
- **`python3-numpy`** – obliczenia numeryczne:  
  ```bash
  sudo apt install python3-numpy
  ```
- **`python3-matplotlib`** – tworzenie wykresów:  
  ```bash
  sudo apt install python3-matplotlib
  ```
- **`python3-pandas`** – analiza danych:  
  ```bash
  sudo apt install python3-pandas
  ```

Dzięki modułom Python staje się niezwykle elastyczny i umożliwia szybkie tworzenie nawet zaawansowanych aplikacji.
