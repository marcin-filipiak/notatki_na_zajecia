### Instalacja Pygame na Debianie

1. **Zaloguj się jako root**
   ```bash
   su -
   ```

3. **Sprawdzenie obecności Pythona 3**  
   Upewnij się, że Python 3 jest zainstalowany na systemie. Sprawdź jego wersję za pomocą polecenia:  
   ```bash
   python3 --version
   ```  
   Jeśli Python 3 nie jest zainstalowany, zainstaluj go za pomocą:  
   ```bash
   apt install python3
   ```

4. **Zainstalowanie Pygame**  
   Wprowadź poniższe polecenie, aby zainstalować bibliotekę Pygame:  
   ```bash
   apt install python3-pygame
   ```  

5. **Sprawdzenie instalacji**  
   Aby upewnić się, że Pygame zostało poprawnie zainstalowane, uruchom Python 3 w terminalu i wpisz:  
   ```python
   import pygame
   print(pygame.ver)
   ```  
   Jeśli nie pojawią się żadne błędy, oznacza to, że instalacja przebiegła pomyślnie.
