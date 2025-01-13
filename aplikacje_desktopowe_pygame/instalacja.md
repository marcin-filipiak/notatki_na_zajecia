### Instalacja Pygame na Debianie

1. **Sprawdzenie obecności Pythona 3**  
   Upewnij się, że Python 3 jest zainstalowany na systemie. Sprawdź jego wersję za pomocą polecenia:  
   ```bash
   python3 --version
   ```  
   Jeśli Python 3 nie jest zainstalowany, zainstaluj go za pomocą:  
   ```bash
   sudo apt install python3
   ```

2. **Instalacja menedżera pakietów pip**  
   Jeśli pip (Python Package Installer) nie jest zainstalowany, wykonaj następujące polecenie:  
   ```bash
   sudo apt install python3-pip
   ```

3. **Zainstalowanie Pygame za pomocą pip**  
   Wprowadź poniższe polecenie, aby zainstalować bibliotekę Pygame:  
   ```bash
   pip3 install pygame
   ```  

4. **Sprawdzenie instalacji**  
   Aby upewnić się, że Pygame zostało poprawnie zainstalowane, uruchom Python 3 w terminalu i wpisz:  
   ```python
   import pygame
   print(pygame.ver)
   ```  
   Jeśli nie pojawią się żadne błędy, oznacza to, że instalacja przebiegła pomyślnie.

5. **Alternatywna metoda instalacji (opcjonalnie)**  
   Jeśli preferujesz instalację za pomocą menedżera pakietów Debian, możesz spróbować:  
   ```bash
   sudo apt install python3-pygame
   ```  
   Jednak ta metoda może nie oferować najnowszej wersji biblioteki.
