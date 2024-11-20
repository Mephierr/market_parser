# market_parser
That's will be parser of trading lots from some platforms
    Platform architecture
ru_v:
### 1. Модуль извлечения данных (Parser)
   - Класс HtmlParser
     - Методы: fetchPage(), parseHtml()
     - Зависимости: Библиотеки для работы с HTTP (например, libcurl) и парсинга HTML (например, Gumbo).

### 2. Модуль хранения данных (Storage)
   - Класс Database
     - Методы: connect(), saveProduct(), getProduct()
     - Зависимости: Система управления базами данных (например, SQLite, PostgreSQL).

### 3. Модуль анализа данных (Analyzer)
   - Класс ProductAnalyzer
     - Методы: analyzePricing(), compareProducts()
     - Зависимости: Логика анализа и алгоритмы (например, для сравнения цен и определения трендов).

### 4. Модуль взаимодействия с пользователем (UI)
   - Класс UserInterface
     - Методы: showResults(), getUserInput()
     - Зависимости: Библиотека для графического интерфейса (например, Qt), или командная строка.

### 5. Модуль конфигурации (Config)
   - Класс ConfigManager
     - Методы: loadConfig(), saveConfig()
     - Зависимости: Работа с файлами (например, JSON или XML).

### 6. Главный модуль (Main)
   - Точка входа в приложение.
   - Создает объекты вышеуказанных классов и управляет их взаимодействием.

### Основные потоки взаимодействия:
1. Скачивание страниц с помощью HtmlParser.
2. Парсинг и сохранение данных в Database.
3. Анализ данных через ProductAnalyzer.
4. Вывод результатов через UserInterface.

Эта архитектура может быть дополнена обработкой ошибок, логированием и тестированием для повышения надежности системы.

eng_v:
### 1. Data Extraction Module (Parser)
   - Class HtmlParser
     - Methods: fetchPage(), parseHtml()
     - Dependencies: Libraries for HTTP handling (e.g., libcurl) and HTML parsing (e.g., Gumbo).

### 2. Data Storage Module (Storage)
   - Class Database
     - Methods: connect(), saveProduct(), getProduct()
     - Dependencies: Database management system (e.g., SQLite, PostgreSQL).

### 3. Data Analysis Module (Analyzer)
   - Class ProductAnalyzer
     - Methods: analyzePricing(), compareProducts()
     - Dependencies: Analysis logic and algorithms (e.g., for price comparison and trend identification).

### 4. User Interaction Module (UI)
   - Class UserInterface
     - Methods: showResults(), getUserInput()
     - Dependencies: GUI library (e.g., Qt) or command line.

### 5. Configuration Module (Config)
   - Class ConfigManager
     - Methods: loadConfig(), saveConfig()
     - Dependencies: File handling (e.g., JSON or XML).

### 6. Main Module (Main)
   - Entry point of the application.
   - Creates instances of the above classes and manages their interaction.

### Main Interaction Flows:
1. Downloading pages using HtmlParser.
2. Parsing and saving data in Database.
3. Analyzing data through ProductAnalyzer.
4. Displaying results via UserInterface.

This architecture can be enhanced with error handling, logging, and testing to improve the system's reliability.