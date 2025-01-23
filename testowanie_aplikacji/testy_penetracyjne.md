### Notatka na zajęcia: Testowanie aplikacji – testy penetracyjne

#### Czym jest testowanie penetracyjne?
Testowanie penetracyjne to symulowany atak mający na celu wykrycie luk w zabezpieczeniach systemu. Pozwala zidentyfikować słabe punkty, które mogłyby zostać wykorzystane przez potencjalnych atakujących.

---

#### Etapy testowania penetracyjnego:
1. **Rekonesans** – zbieranie informacji o celu. Dzieli się na:
   - **Rekonesans pasywny** – polega na gromadzeniu danych bez interakcji z celem, np. przeglądanie publicznych stron internetowych. Jest trudny do wykrycia.
   - **Rekonesans aktywny** – obejmuje działania takie jak pingowanie serwera, które mogą zostać wykryte.

2. **Eksploatacja** – wykorzystanie wykrytych luk w zabezpieczeniach.

3. **Raportowanie** – dokumentacja wyników, opis wykorzystanych technik i rekomendacje dotyczące poprawy bezpieczeństwa.

---

#### Kluczowe pojęcia:
- **Payload** – dane lub kod używane do przeprowadzenia ataku.
- **Zero-day** – luka w oprogramowaniu nieznana producentowi.
- **Lateral movement** – przemieszczanie się w sieci w celu eskalacji uprawnień.
- **Eskalacja uprawnień** – uzyskanie większych uprawnień w systemie niż posiada użytkownik.

---

#### Rodzaje testów:
- **Test czarnej skrzynki** – tester nie ma wiedzy o wewnętrznej strukturze systemu.
- **Test białej skrzynki** – tester ma pełen dostęp do kodu i systemu.
- **Test szarej skrzynki** – tester ma ograniczoną wiedzę o systemie.

---

#### Popularne narzędzia:
- **Nmap** – skanowanie portów.
- **Burp Suite** – testy penetracyjne aplikacji webowych.
- **Wireshark** – przechwytywanie ruchu sieciowego.
- **Metasploit** – framework do eksploitacji luk w zabezpieczeniach.
- **Sqlmap** – automatyczne przeprowadzanie ataków SQL Injection.
- **John the Ripper** – narzędzie do łamania haseł.

---

#### Przykłady ataków i luk:
1. **SQL Injection** – wstrzykiwanie złośliwych zapytań SQL.
2. **Cross-Site Scripting (XSS)** – wstrzykiwanie złośliwego kodu JavaScript.
3. **Man-in-the-middle** – podszywanie się pod inną stronę w celu przechwycenia danych.
4. **Brute force** – metoda prób i błędów przy zgadywaniu haseł.
5. **DDoS** – wyczerpywanie zasobów serwera przez wysyłanie ogromnej liczby żądań.

---

#### OWASP:
- **OWASP (Open Web Application Security Project)** to organizacja zajmująca się bezpieczeństwem aplikacji webowych. Publikuje listę najczęstszych luk w zabezpieczeniach – **OWASP Top 10**, w której znajdują się m.in.:
  - SQL Injection,
  - Cross-Site Scripting (XSS).

---

#### Działania w rekonesansie aktywnym:
- Pingowanie serwerów.
- Skanowanie portów.
- Analiza odpowiedzi serwera.

#### Fuzzing:
Automatyczne wysyłanie nieoczekiwanych lub losowych danych do aplikacji w celu wykrycia potencjalnych błędów lub luk.

#### Cel testowania penetracyjnego:
Identyfikacja luk w zabezpieczeniach systemu i dostarczenie rekomendacji dotyczących poprawy bezpieczeństwa.
