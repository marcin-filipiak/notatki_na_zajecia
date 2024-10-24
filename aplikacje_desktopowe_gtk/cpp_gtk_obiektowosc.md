GTK+ (GIMP Toolkit) został napisany w języku **C**, a nie w **C++**, z kilku kluczowych powodów, które łączą zarówno aspekty techniczne, jak i potrzeby projektu. Oto omówienie tych powodów z uwzględnieniem obiektowości GTK+:

### 1. **Przenośność (Portability)**
C jest bardziej przenośnym językiem niż C++, co miało kluczowe znaczenie dla GTK+:
- **C** był szeroko stosowany w programowaniu systemów i jest obsługiwany na większości platform, co ułatwia tworzenie przenośnych aplikacji.
- W czasach powstawania GTK+ (lata 90.) wsparcie dla **C++** nie było tak powszechne jak dla **C**, zwłaszcza w systemach operacyjnych innych niż Unix/Linux.

### 2. **Kompatybilność (ABI Stability)**
Interfejs binarny aplikacji (ABI – Application Binary Interface) jest znacznie bardziej stabilny w C:
- C ma ustalone zasady dotyczące ABI, co oznacza, że kod skompilowany z użyciem jednej wersji kompilatora będzie kompatybilny z kodem zbudowanym z użyciem innej wersji. W przypadku **C++** ABI często się zmienia, co może prowadzić do problemów z kompatybilnością.
- Dla GTK+, który miał być szeroko stosowaną biblioteką, stabilność ABI była kluczowa, aby użytkownicy mogli bez problemów korzystać z różnych wersji biblioteki.

### 3. **Interoperacyjność z innymi językami**
- **C** jest językiem, który można łatwo integrować z innymi językami programowania, co ułatwia tworzenie wiązań (bindings) do różnych języków, takich jak Python, Perl, Ruby itp. Dzięki temu GTK+ jest dostępne dla programistów korzystających z różnych języków.
- C++ wprowadza bardziej złożone mechanizmy obiektowe, które mogą skomplikować tworzenie wiązań z innymi językami.

### 4. **Prostota (Simplicity)**
- **C** jest prostszy i bardziej bezpośredni, co czyni go bardziej przystępnym dla szerokiego kręgu programistów, szczególnie tych, którzy pracują w obszarach związanych z systemami operacyjnymi.
- C++ wprowadza bardziej skomplikowane koncepcje, takie jak dziedziczenie i polimorfizm, które mogą utrudnić debugowanie i zrozumienie kodu w dużych projektach, takich jak GTK+.

### 5. **Wydajność (Performance)**
- **C** oferuje precyzyjne zarządzanie zasobami systemowymi, co jest istotne w kontekście aplikacji graficznych. Choć **C++** również pozwala na optymalizację, wprowadza pewne narzuty związane z obiektowością.
- GTK+ musi być bardzo wydajny, zwłaszcza w kontekście aplikacji graficznych, które wymagają płynnego działania.

### 6. **Historia i potrzeby projektu**
- GTK+ został pierwotnie stworzony w połowie lat 90. jako zestaw narzędzi dla GIMP (GNU Image Manipulation Program), który miał być otwartym odpowiednikiem Photoshopa. W tym czasie programowanie obiektowe w C++ nie było jeszcze tak rozwinięte, a C było bardziej powszechnie używane.
- Zespół projektujący GTK+ wybrał C, aby zapewnić szeroką kompatybilność i maksymalną wydajność.

### Obiektowość GTK+
GTK+ osiąga obiektowość poprzez użycie systemu **GObject**, który dodaje obiektowe mechanizmy do programowania w C:

1. **GObject** – System programowania obiektowego, który dodaje cechy obiektowe do języka C, takie jak:
   - **Struktury**: Obiekty w GTK+ są reprezentowane jako struktury, które mogą zawierać wskaźniki do innych obiektów, co umożliwia dziedziczenie.
   - **Dziedziczenie**: GTK+ wykorzystuje dziedziczenie przez GObject. Na przykład, `GtkWindow` dziedziczy po `GtkWidget`, co pozwala na korzystanie z metod i właściwości obiektu `GtkWidget`.
   - **Polimorfizm**: Możliwość używania różnych typów obiektów w kontekście funkcji przyjmujących wskaźniki do `GtkWidget`, co umożliwia elastyczne projektowanie interfejsu.

2. **Sygnały**: GTK+ wprowadza system sygnałów, który pozwala na reagowanie na różne zdarzenia, takie jak kliknięcia przycisków czy zamykanie okien. Umożliwia to przypisywanie funkcji obsługi do konkretnych sygnałów, co przypomina system zdarzeń w językach obiektowych.

3. **Zarządzanie pamięcią**: GObject wprowadza automatyczne zarządzanie pamięcią poprzez system referencji, co pozwala na skuteczne zarządzanie cyklem życia obiektów.

### Podsumowanie
GTK+ zostało napisane w **C** głównie ze względu na przenośność, stabilność ABI, prostotę oraz wydajność. Chociaż **C++** jest bardziej naturalnym językiem dla programowania obiektowego, wybór **C** pozwolił na większą kompatybilność i prostotę w implementacji. GObject wprowadza odpowiednie mechanizmy obiektowe, co umożliwia korzystanie z obiektowości w C, co czyni GTK+ potężnym narzędziem do tworzenia graficznych interfejsów użytkownika.
