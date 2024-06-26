# Вариант 8: «Цветочная оранжерея»

## Описание 
Цветочная оранжерея выращивает различные виды цветов и продает на заказ составленные из них композиции. Каждая композиция имеет свое название и может состоять как из цветов одного вида, так и из цветов разного вида. Заказ обычно выполняется в течение нескольких дней.

### Дирекция оранжереи владеет информацией:
*О цветах:*
-  название цветка
-  сорт
-  стоимость одного цветка

*О композициях:*
- название композиции
- название входящего в композицию цветка
- сорт
- количество единиц

*О выполнении заказов:*
- дата принятия заказа
- дата выполнения заказа
- название композиции
- количество единиц
- покупатель

### Покупатель владеет информацией:
- данные о своих заказах (по пункту, помеченному * (звездочкой)).

Поле | Информация
------------ | -------------
по всем заказам | сумма полученных денег за указанный период `*`
по композиции, пользующейся максимальным спросом | все сведения о ней
по всем заказам | сведения о количестве выполненных заказов за указанный период 
по всем заказам | ведения о количестве использованных цветов по видам и сортам за указанный период
по всем заказам | сведения о количестве проданных композиций и сумме полученных денег по видам композиций

### Выполнено:
1. Таблицы БД с учетом ограничений целостности данных
2. Оператор Select 
3. Обновление информации в указанных таблицах с помощью операторов Insert, Update, Delete 
4. Функция, которая осуществляет внесение информации в таблицу заказов, затем рассчитывает стоимость заказа и вносит сведения о нем в специальную таблицу.
5. Функция, которая на указанную дату выводит всю информацию о полученных заказах.

## Установка:
- Сборка проекта:
  - Склонировать данный репозиторий
    ```Shell
    git clone https://github.com/fpmi-tp2024/tpmp-rvn-lab5-flowers_team.git
    ```
  - Склонировать и собрать библиотеку SQLiteCpp
    ```Shell
    git clone https://github.com/SRombauts/SQLiteCpp.git
    mkdir -p SQLiteCpp/build
    cd SQLiteCpp/build
    cmake ..
    make
    ```
  - Создать бд для приложения и тестов
    ```Shell
    ./db_migrations
    ```
  - Собрать приложение
    ```Shell
    cmake CMakeLists.txt
    make
    ```
- Сборка тестов:
  - Перейти в директорию tests
    ```Shell
    cd tests
    ```
  - Если тестовая бд не создана, то создать ее
    ```Shell
    ./db_migrations
    ```
  - Скопировать библиотеку SQLiteCpp в текущую директорию
    ```Shell
    cp -r ../SQLiteCpp/ .
    ```
  - Собрать тесты
    ```Shell
    cmake CMakeLists.txt
    make
    ```

## Использование приложения после установки:
  - Запуск приложения
  ```Shell
    ./bin/main
  ```
  - Запуск тестов
  ```Shell
    ./tests/tests
  ```
  - Анализ покрытия кода тестами
    - Создание отчета
    ```Shell
    ./tests/tests_coverage_script 
    ```
    - Отчет можно просмотреть, открыв файл ./tests/tests_coverage_report/index.html
  - Проверка утечек памяти
    - Собрать приложение
      ```Shell
      g++ -O0 -g ./src/*.cpp ./SQLiteCpp/build/libSQLiteCpp.a -ldl -lsqlite3 -lpthread -o app
      ```
    - Проверить утечку памяти с помощью valgrind
      ```Shell
      valgrind --leak-check=full ./app 
      ``` 
## Сведения об авторах проекта и какие задачи реализовывали:
1. Андреева София:
- Создание UML диаграмм
- Написание кода
- Проектирование и реализация базы данных
- Написание тестов
- Проверка покрытия кода тестами
- Проверка приложения на наличие утечек памяти
2. Кшнякина Валентина:
- Создание UML диаграмм
- Создание базовой структуры репозитория
- Создание доски задач
- Создание Wiki
- Создание README
- Написание Github Actions

