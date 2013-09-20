HarrixHtmlForQWebView
=====================

Версия 1.1

Html страница для отображения информации в QWebView через ajax запросы.

https://github.com/Harrix/HarrixHtmlForQWebView

Библиотека распространяется по лицензии Apache License, Version 2.0.

Механизм работы
---------------

В **index.html** есть слой, куда с помощью ajax добавляется контент:

    <div id="content"></div>

В этот слой копируется содержимое файла из файла **temp.html**. При этом копирование содержимого производится только в том случае, если содержимое файла **temp.html** поменялось. Это делается для того, чтобы обновление страницы происходило только когда это нужно, а не каждую секунду.

Итак, вы автоматически генерируете контент в файл **temp.html**. После этого **index.html**, открытая в QWebView автоматически обновит свое содержимое и отскроллит окно к низу.

Предупреждение
--------------

Данная страница не будет работать на локальном компьютере через браузеры. То есть, если вы откроете файл **index.html**, например, в Chrome, то откроется пустая страница. Это связано с тем, что в браузерах обычно стоит запрет на ajax в локальных файлах. Но если загрузите на сервер, то все будет отображаться.

Проекты для работы с данной библиотекой и с примерами работы с ней
------------------------------------------------------------------

 * **HarrixQtLibraryForQWebView** - библиотека для отображения различных данных в QWebView: https://github.com/Harrix/HarrixQtLibraryForQWebView
 * **HarrixChart** - приложение по отображению графиков из данных формата *.hdata: https://github.com/Harrix/HarrixChart
 * **HarrixClass_DataOfHarrixOptimizationTesting** - класс HarrixClass_DataOfHarrixOptimizationTesting для считывания информации формата данных Harrix Optimization Testing на C++ для Qt: https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting
 * **HarrixMathLibrary** - сборник различных математических функций и шаблонов с открытым кодом на языке C++: https://github.com/Harrix/HarrixMathLibrary

Подключенные библиотеки
-----------------------
 * **jQuery** - для скролла страниц: http://jquery.com
 * **JSXGraph** - для отображения графиков: https://github.com/jsxgraph/jsxgraph

Пример использования
--------------------

Пример использования в Qt можно посмотреть в справке к проекту HarrixQtLibraryForQWebView:

https://github.com/Harrix/HarrixQtLibraryForQWebView

История проекта
---------------

Подробный список изменений в файле CHANGELOG.md.

Контакты
--------

Автор: Сергиенко Антон Борисович.

С автором можно связаться по адресу sergienkoanton@mail.ru или  http://vk.com/harrix .

Сайт автора, где публикуются последние новости: http://blog.harrix.org, а проекты располагаются по адресу http://harrix.org .