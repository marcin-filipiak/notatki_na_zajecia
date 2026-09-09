# Rozdział 9 — Komunikacja w M221

> [Powrót do spisu treści](./README.md)

---

## 9.1 Przegląd komunikacji

TM221M16R udostępnia **3 interfejsy komunikacyjne**:

| Interfejs | Typ | Zastosowanie | Prędkość |
|-----------|-----|-------------|----------|
| **Ethernet** | RJ45, 10/100 Mb/s | Modbus TCP, programowanie, serwer WWW | 100 Mb/s |
| **USB** | Micro-B, USB 2.0 | Programowanie, diagnostyka | 480 Mb/s |
| **Serial** | RJ12 (RS-232) | Modbus RTU Master/Slave | do 115200 bps |

---

## 9.2 Ethernet — konfiguracja

### Adres IP sterownika

Domyślny adres IP: `192.168.1.1`

| Parametr | Wartość domyślna | Gdzie zmienić |
|----------|-------------------|---------------|
| Adres IP | 192.168.1.1 | SoMachine Basic → Ethernet |
| Maska podsieci | 255.255.255.0 | — |
| Gateway | 192.168.1.254 | — |
| DHCP | Włączony | — |

### Zmiana adresu IP przez SoMachine Basic

1. **Narzędzia → Konfiguracja → Ethernet**
2. Wyłącz DHCP (jeśli chcesz statyczny)
3. Wpisz nowy adres IP
4. Zapisz i pobierz konfigurację

### Zmiana adresu IP przez Web Server

1. Otwórz przeglądarkę i wpisz: `http://192.168.1.1`
2. Zaloguj się (domyślnie: `user` / `user`)
3. Przejdź do zakładki **Network Settings**
4. Zmień parametry
5. Kliknij **Apply** — sterownik restartuje się

---

## 9.3 Modbus TCP

**Modbus TCP** to najczęściej stosowany protokół komunikacji przemysłowej oparty na Ethernet.

### Jak działa Modbus TCP

```
  Klient (Master)              Serwer (Slave)
  ┌──────────────┐            ┌──────────────┐
  │  SoMachine   │            │  TM221M16R   │
  │  / PC / HMI  │◄──────────▶│  IP: .1.1    │
  └──────────────┘  TCP/IP    └──────────────┘
                     port 502
```

### Obsługiwane kody Modbus w M221

| Kod | Nazwa | Opis |
|-----|-------|------|
| 01 | Read Coils | Odczyt cewek (Q, M) |
| 02 | Read Discrete Inputs | Odczyt wejść (I) |
| 03 | Read Holding Registers | Odczyt rejestrów (MW, MD) |
| 04 | Read Input Registers | Odczyt rejestrów wejściowych |
| 05 | Write Single Coil | Zapis pojedynczej cewki |
| 06 | Write Single Register | Zapis pojedynczego rejestru |
| 0F | Write Multiple Coils | Zapis wielu cewek |
| 10 | Write Multiple Registers | Zapis wielu rejestrów |

### Mapa rejestrów Modbus

| Adres Modbus | Odpowiednik M221 | Typ |
|--------------|-------------------|-----|
| 0 – 2047 | M0 – M2047 | BOOL |
| 10000 – 10009 | I0.0 – I1.1 | BOOL (read only) |
| 20000 – 20005 | Q0.0 – Q0.5 | BOOL |
| 30000 – 30255 | MW0 – MW255 | INT/UINT |
| 40000 – 40063 | MD0 – MD63 | DINT |
| 40100 – 40163 | MF0 – MF63 | REAL |

### Przykład: Odczyt rejestrów przez Python

```python
from pymodbus.client import ModbusTcpClient

client = ModbusTcpClient('192.168.1.1', port=502)
client.connect()

# Odczyt 10 rejestrów od adresu 30000 (MW0–MW9)
result = client.read_holding_registers(address=0, count=10, unit=1)
print(result.registers)

# Zapis wartości 100 do MW0
client.write_register(address=0, value=100, unit=1)

client.close()
```

---

## 9.4 Modbus RTU (port szeregowy)

**Modbus RTU** komunikuje się przez port szeregowy RS-232 (RJ12).

### Parametry portu szeregowego

| Parametr | Wartość domyślna |
|----------|-------------------|
| Prędkość (baud rate) | 9600 bps |
| Bity danych | 8 |
| Bity stopu | 1 |
| Parzystość | Even |
| Protokół | Modbus RTU |

### Konfiguracja w SoMachine Basic

1. **Projekt → Sterownik → Port szeregowy**
2. Ustaw parametry transmisji
3. Określ rolę: **Master** lub **Slave**

### Modbus RTU Master

M221 może **odczytywać i zapisywać** dane z innych urządzeń Modbus RTU:

```
  M221 (Master) ──RS-232──▶ Czujnik Modbus RTU (Slave)
                              Adres: 1
                              Rejestr: 40001 (temperatura)
```

### Modbus RTU Slave

M221 może **udostępniać swoje dane** jako Slave dla innego Mastera:

```
  PC (Master) ──RS-232──▶ M221 (Slave)
                           Adres: 1
                           Rejestry: MW0–MW9
```

---

## 9.5 Web Server — konfiguracja

TM221M16R posiada **wbudowany serwer WWW** dostępny przez przeglądarkę.

### Dostęp

1. Otwórz przeglądarkę (Chrome, Firefox, Edge)
2. Wpisz adres: `http://192.168.1.1`
3. Zaloguj się:
   - **Użytkownik:** `user`
   - **Hasło:** `user`

### Dostępne zakładki

| Zakładka | Zawartość |
|----------|-----------|
| **Home** | Status sterownika (RUN/STOP, błędy) |
| **I/O Status** | Stan wejść i wyjść w czasie rzeczywistym |
| **Variables** | Podgląd zmiennych (MW, MD) |
| **Network** | Konfiguracja sieci Ethernet |
| **Firmware** | Aktualizacja oprogramowania |
| **Log** | Dziennik zdarzeń |

### Zmiana hasła

Zalecana zmiana domyślnego hasła! W SoMachine Basic → Konfiguracja → Security.

---

## 9.6 Komunikacja M221 ↔ HMI

Typowa konfiguracja: panel operatorski (HMI) komunikuje się z M221 przez **Modbus TCP**.

### Schemat połączenia

```
  ┌─────────┐        ┌────────────────┐
  │   HMI   │◄──────▶│   TM221M16R    │
  │ (Panel) │  TCP   │  IP: 192.168.1.1│
  │ .1.100  │  port  │                │
  └─────────┘  502   └────────────────┘
```

### Dane wymieniane

| Kierunek | Adresy | Przykład |
|----------|--------|---------|
| M221 → HMI | MW0–MW9 | Odczyty czujników |
| HMI → M221 | MW20–MW29 | Wartości zadane |
| M221 → HMI | Q0.0–Q0.5 | Stany wyjść |
| HMI → M221 | M0–M9 | Przyciski HMI |

### Przykład konfiguracji w HMI

W oprogramowaniu panelu (np. SoMachine HMI):
1. Dodaj urządzenie: **Modbus TCP**
2. Adres IP: `192.168.1.1`
3. Port: `502`
4. Dodaj tagi:
   - `Temperatura`: Holding Register, adres 30000 (MW0), typ INT
   - `Start`: Coil, adres 20000 (Q0.0)
   - `Przycisk`: Discrete Input, adres 10000 (I0.0)

---

## 9.7 Komunikacja M221 ↔ M221

Dwa sterowniki M221 mogą wymieniać dane przez **Modbus TCP**.

### Schemat

```
  ┌────────────────┐    Ethernet    ┌────────────────┐
  │  M221 #1       │◄──────────────▶│  M221 #2       │
  │  IP: 192.168.1.1│   Modbus TCP  │  IP: 192.168.1.2│
  │  (Master)      │               │  (Slave)        │
  └────────────────┘               └────────────────┘
```

### Konfiguracja Master (M221 #1)

W SoMachine Basic → Communication → Modbus TCP Master:
- Dodaj urządzenie docelowe: `192.168.1.2`
- Okres odczytu: 100 ms
- Rejestry do odczytu: MW0–MW4 z Slave → zapisz do MW50–MW54

### Konfiguracja Slave (M221 #2)

W SoMachine Basic → Communication → Modbus TCP Slave:
- Udostępnij rejestry: MW0–MW4
- Port: 502

---

## 9.8 Ćwiczenie — Odczyt temperatury przez Modbus

**Zadanie:** Odczytaj wartość temperatury z rejestrów M221#2 przez Modbus TCP i wyświetl na M221#1 (LED).

### Kroki:
1. Skonfiguruj M221#1 jako Master
2. Skonfiguruj M221#2 jako Slave
3. Na M221#2 zapisz temperaturę do MW0
4. Na M221#1 odczytaj MW0 z M221#2 do MW50
5. Porównaj MW50 z wartością progową
6. Wyślij alarm na Q0.0

---

## 9.9 Podsumowanie

| Interfejs | Protokół | Zastosowanie |
|-----------|----------|-------------|
| Ethernet | Modbus TCP | Komunikacja z HMI, PC, innymi PLC |
| Serial | Modbus RTU | Czujniki, aktory z RS-232 |
| Ethernet | Web Server | Diagnostyka zdalna |
| USB | Programowanie | Połączenie z SoMachine Basic |

> **Następny rozdział:** [Funkcje specjalne](./rozdzial-10-funkcje-specjalne.md)

> [Powrót do spisu treści](./README.md)
