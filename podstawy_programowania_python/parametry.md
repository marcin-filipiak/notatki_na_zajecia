### Jak w Pythonie przyjmować parametry podczas uruchamiania programu?

#### **Czym są argumenty wiersza poleceń?**  
To dane, które użytkownik podaje **od razu przy uruchamianiu skryptu**, np.:  
```bash
python pogoda.py Warszawa
```
W tym przykładzie `"Warszawa"` to argument przekazany do programu.

---

## Sposób 1: Prosty – z użyciem `sys.argv`

#### **Jak działa `sys.argv`?**
- To lista przechowująca wszystkie argumenty.
- `sys.argv[0]` → nazwa pliku skryptu.
- `sys.argv[1]`, `sys.argv[2]`, … → kolejne argumenty od użytkownika.

#### **Przykład**
```python
import sys

if len(sys.argv) < 2:
    print("Użycie: python pogoda.py <miasto>")
    sys.exit(1)

miasto = sys.argv[1]
print(f"Sprawdzam pogodę dla miasta: {miasto}")
```

---

## Sposób 2: Zaawansowany – z użyciem `argparse`

#### **Dlaczego `argparse`?**
Moduł `argparse` pozwala na:
- tworzenie czytelnej pomocy (`--help`),
- definiowanie opcjonalnych i wymaganych argumentów,
- automatyczne sprawdzanie typów i błędów.

#### 6. **Przykład z `argparse`**
```python
import argparse

parser = argparse.ArgumentParser(description="Pogoda – sprawdź prognozę dla danego miasta.")
parser.add_argument("miasto", help="Nazwa miasta, dla którego chcesz sprawdzić pogodę")
parser.add_argument("-j", "--jednostka", choices=["C", "F"], default="C",
help="Jednostka temperatury (domyślnie: C)")

args = parser.parse_args()

print(f"Sprawdzam pogodę dla miasta: {args.miasto}")
print(f"Jednostka: {args.jednostka}")
```

#### **Uruchomienie**
```bash
python pogoda.py Kraków
# lub
python pogoda.py Kraków --jednostka F
# lub
python pogoda.py --help
```
