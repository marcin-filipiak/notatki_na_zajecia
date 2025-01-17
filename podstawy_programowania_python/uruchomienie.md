### Uruchamianie skryptów w Pythonie (Linux Debian)

Python jest językiem interpretowanym, co oznacza, że kod nie wymaga wcześniejszej kompilacji do postaci binarnej. W systemach opartych na Linuxie, takich jak Debian, uruchamianie skryptów jest proste i wymaga tylko kilku kroków.

---

#### 1. **Sprawdzenie zainstalowanej wersji Pythona**
W systemie Linux zazwyczaj Python jest zainstalowany domyślnie. Można sprawdzić dostępne wersje, wpisując w terminalu:  
```bash
python --version
```
lub dla nowszej wersji:  
```bash
python3 --version
```

Jeśli Python nie jest zainstalowany, można go dodać za pomocą polecenia:  
```bash
sudo apt update
sudo apt install python3
```

---

#### 2. **Tworzenie skryptu Python**
Skrypty w Pythonie mają rozszerzenie `.py`. Aby utworzyć prosty skrypt:  
1. Utwórz plik:  
   ```bash
   nano hello.py
   ```
2. Wprowadź kod:  
   ```python
   print("Hello, world!")
   ```
3. Zapisz plik (`Ctrl+O`, Enter, a następnie `Ctrl+X`, aby wyjść z edytora).

---

#### 3. **Uruchamianie skryptu**
Aby uruchomić skrypt, użyj polecenia:  
```bash
python3 hello.py
```

---

#### 4. **Ustawienie pliku jako wykonywalnego**
Aby skrypt działał bezpośrednio, można nadać mu prawa wykonywalne:  
1. Dodaj na początku pliku tzw. "shebang":  
   ```python
   #!/usr/bin/env python3
   print("Hello, world!")
   ```
2. Nadaj plikowi prawa wykonywalne:  
   ```bash
   chmod +x hello.py
   ```
3. Uruchom skrypt bezpośrednio:  
   ```bash
   ./hello.py
   ```

---

#### 5. **Uruchamianie w środowisku wirtualnym (opcjonalnie)**
Jeśli pracujesz nad większym projektem, warto używać wirtualnego środowiska, aby izolować zależności:  
1. Utwórz środowisko:  
   ```bash
   python3 -m venv myenv
   ```
2. Aktywuj środowisko:  
   ```bash
   source myenv/bin/activate
   ```
3. Uruchamiaj skrypty w aktywowanym środowisku.

---

To wszystko! Dzięki tym krokom możesz uruchamiać i zarządzać skryptami Python w systemie Debian.
