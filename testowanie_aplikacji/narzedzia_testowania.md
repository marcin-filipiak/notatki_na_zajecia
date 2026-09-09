# Narzędzia do testowania oprogramowania

W testowaniu oprogramowania używa się wielu narzędzi wspierających różne rodzaje testów. Poniżej przedstawiono przegląd popularnych narzędzi pogrupowanych według zastosowania.

---

## 1. Narzędzia do zarządzania testami

Służą do planowania, organizowania i śledzenia przypadków testowych oraz wyników.

- **Jira / Xray** – zarządzanie projektami i testami w podejściu Agile.
- **TestRail** – dedykowany system zarządzania przypadkami testowymi.
- **Zephyr** – integracja testów z Jirą.
- **qTest** – platforma do zarządzania jakością.

---

## 2. Narzędzia do testów jednostkowych

Służą do pisania i uruchamiania testów jednostkowych w konkretnych językach.

| Język | Narzędzie |
|-------|-----------|
| Java | JUnit, TestNG |
| C++ | Google Test, Catch2 |
| Python | pytest, unittest |
| JavaScript | Jest, Mocha, Jasmine |
| C# | NUnit, xUnit |

---

## 3. Narzędzia do testów E2E i automatycznych testów web

Automatyzują testowanie interfejsów użytkownika.

| Narzędzie | Opis |
|-----------|------|
| **Selenium** | Klasyczne narzędzie do automatyzacji przeglądarek, obsługuje wiele języków |
| **Cypress** | Nowoczesne narzędzie do testów E2E, JavaScript |
| **Playwright** | Nowoczesne narzędzie do testów przeglądarkowych (Microsoft) |
| **Appium** | Automatyzacja testów aplikacji mobilnych |
| **Robot Framework** | Elastyczny framework do testowania oparty na słowach kluczowych |

### Przykład testu w Selenium (Java):

```java
import org.openqa.selenium.*;
import org.openqa.selenium.chrome.ChromeDriver;

public class LoginTest {
    public static void main(String[] args) {
        WebDriver driver = new ChromeDriver();
        driver.get("https://example.com/login");

        driver.findElement(By.id("username")).sendKeys("jan");
        driver.findElement(By.id("password")).sendKeys("haslo123");
        driver.findElement(By.id("submit")).click();

        String title = driver.getTitle();
        if (title.equals("Strona główna")) {
            System.out.println("TEST PASSED");
        } else {
            System.out.println("TEST FAILED");
        }
        driver.quit();
    }
}
```

---

## 4. Narzędzia do testów API

Weryfikują działanie interfejsów programistycznych (API).

| Narzędzie | Opis |
|-----------|------|
| **Postman** | Popularne narzędzie graficzne do testowania API |
| **REST Assured** | Biblioteka do testów API w Javie |
| **Insomnia** | Alternatywa dla Postmana |
| **SoapUI** | Testowanie usług SOAP i REST |

---

## 5. Narzędzia do testów wydajnościowych

Symulują obciążenie i mierzą wydajność systemu.

- **Apache JMeter** – darmowe, popularne narzędzie do testów obciążeniowych.
- **Gatling** – wydajne narzędzie oparte na Scala.
- **k6** – nowoczesne narzędzie open source.
- **LoadRunner** – komercyjne narzędzie klasy enterprise.

---

## 6. Narzędzia do testów bezpieczeństwa

Służą do wykrywania luk w zabezpieczeniach.

- **OWASP ZAP** – darmowy skaner bezpieczeństwa aplikacji webowych.
- **Burp Suite** – narzędzie do testów penetracyjnych.
- **Nmap** – skanowanie sieci i portów.
- **Metasploit** – framework do eksploitacji.
- **Sqlmap** – automatyczny test SQL Injection.
- **Wireshark** – analiza ruchu sieciowego.

---

## 7. Narzędzia do pomiaru pokrycia kodu

Informują, ile kodu zostało objęte testami.

| Język | Narzędzie |
|-------|-----------|
| C/C++ | gcov, lcov |
| Java | JaCoCo |
| Python | coverage.py |
| JavaScript | Istanbul |

---

## 8. Narzędzia do ciągłej integracji (CI/CD)

Automatycznie uruchamiają testy przy każdej zmianie kodu.

- **Jenkins** – popularny, darmowy serwer CI.
- **GitHub Actions** – automatyzacja zintegrowana z GitHub.
- **GitLab CI** – ciągła integracja w GitLab.
- **CircleCI** – usługa chmurowa CI.
- **Travis CI** – usługa CI dla projektów open source.

### Idea CI (Continuous Integration)
- Programiści często (np. codziennie) łączą swoje zmiany w repozytorium.
- Przy każdej takiej zmianie automatycznie uruchamiane są: budowa aplikacji, testy jednostkowe, testy integracyjne.
- Jeśli testy zawiodą, programista natychmiast o tym wie i naprawia błąd.

---

## 9. Narzędzia do analizy statycznej kodu

Sprawdzają kod pod kątem błędów, stylu i potencjalnych problemów **bez uruchamiania** programu.

| Język | Narzędzie |
|-------|-----------|
| C/C++ | cppcheck, clang-tidy |
| Java | SonarQube, Checkstyle |
| Python | pylint, flake8 |
| JavaScript | ESLint |

---

## Podsumowanie

- Wybór narzędzi zależy od języka, rodzaju testów i potrzeb projektu.
- Istnieją narzędzia do: zarządzania testami, testów jednostkowych, E2E, API, wydajności, bezpieczeństwa, pokrycia kodu i CI/CD.
- Automatyzacja + ciągła integracja znacząco poprawiają jakość i tempo rozwoju oprogramowania.
- Narzędzia wspierają testerów, ale nie zastępują ich wiedzy i osądu.
