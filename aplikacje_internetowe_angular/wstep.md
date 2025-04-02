**Angular - wstęp**

**1. Co to jest Angular?**
Angular to platforma i framework do budowy dynamicznych aplikacji internetowych typu SPA (Single Page Applications). Został opracowany przez Google i wykorzystuje TypeScript jako język programowania.

**2. Kluczowe cechy Angulara:**
- **Komponenty** – podstawowe bloki aplikacji, które składają się z HTML, CSS i TypeScript.
- **Moduły** – organizują aplikację w logiczne części.
- **Szablony (Templates)** – pozwalają na dynamiczne generowanie widoków.
- **Binding danych** – umożliwia łączenie danych między komponentem a widokiem.
- **Dyrektywy** – pozwalają manipulować elementami DOM.
- **Serwisy i Dependency Injection** – zarządzanie logiką biznesową i dostępem do danych.
- **Routing** – nawigacja między różnymi widokami aplikacji.
- **RxJS i Observable** – obsługa operacji asynchronicznych.

**3. Zalety Angulara:**
- **Strukturalne podejście** – modularna budowa ułatwia zarządzanie kodem.
- **Wsparcie TypeScript** – zapewnia bezpieczeństwo typów i ułatwia refaktoryzację kodu.
- **Dwukierunkowe wiązanie danych** – automatyczna synchronizacja modelu i widoku.
- **Duża społeczność i wsparcie** – framework rozwijany przez Google.
- **Rozbudowane narzędzia** – CLI (Angular Command Line Interface) ułatwia generowanie i zarządzanie projektami.

**4. Do czego można wykorzystać Angulara?**
- Tworzenie rozbudowanych aplikacji internetowych.
- Aplikacje SPA (Single Page Applications).
- Panele administracyjne i dashboardy.
- Aplikacje Progressive Web Apps (PWA).
- Systemy zarządzania treścią (CMS).
- Aplikacje mobilne i desktopowe (z użyciem Ionic lub Electron).

**5. Instalacja Angulara:**
Aby rozpocząć pracę z Angular, należy mieć zainstalowane **Node.js** oraz **npm**. Następnie można zainstalować Angular CLI:
```sh
npm install -g @angular/cli
```
Tworzenie nowego projektu:
```sh
ng new my-angular-app
cd my-angular-app
ng serve
```
Aplikacja będzie dostępna pod adresem `http://localhost:4200/`.
