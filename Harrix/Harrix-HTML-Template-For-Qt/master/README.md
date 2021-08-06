HarrixHtmlForQWebView
=====================

Версия 1.1

Html страница для отображения информации в [QWebView](http://qt-project.org/doc/qt-5.0/qtwebkit/qwebview.html) через ajax запросы в системе Qt. В чем суть? Допустим, мы хотим отображать некоторую информацию в виде html контента через встроенный браузер в виде компонента QWebView. Допустим, что контент может изменяться довольно часто, например, с частотой 1  секунду. Если контент массивный, то постоянное обновление страницы будет мерцающим и не приемлемым.

Данный проект является решением проблемы и обновление происходит через ajax и только, когда содержимое файла temp.html поменялось. При этом, если что-то новое добавилось, то производится автоматический скролл вниз страницы.

[https://github.com/Harrix/HarrixHtmlForQWebView](https://github.com/Harrix/HarrixHtmlForQWebView)

Библиотека распространяется по лицензии [MIT](https://github.com/Harrix/HarrixHtmlForQWebView/blob/master/LICENSE).

Установка
---------

Подробно о установке с подробным примером можно прочитать тут [http://blog.harrix.org/?p=1059](http://blog.harrix.org/?p=1059).

О функциях добавления объектов в temp.html читайте в проекте [https://github.com/Harrix/HarrixQtLibraryForQWebView](https://github.com/Harrix/HarrixQtLibraryForQWebView).

Механизм работы
---------------

В [**index.html**](https://github.com/Harrix/HarrixHtmlForQWebView/blob/master/index.html) есть слой, куда с помощью ajax добавляется контент:

```html
<div id="content"></div>
```

В этот слой копируется содержимое файла из файла [**temp.html**](https://github.com/Harrix/HarrixHtmlForQWebView/blob/master/temp.html) (тут в библиотеке он и должен быть пустым!). При этом копирование содержимого производится только в том случае, если содержимое файла [**temp.html**](https://github.com/Harrix/HarrixHtmlForQWebView/blob/master/temp.html) поменялось. Это делается для того, чтобы обновление страницы происходило только когда это нужно, а не каждую секунду.

Итак, вы автоматически генерируете контент в файл [**temp.html**](https://github.com/Harrix/HarrixHtmlForQWebView/blob/master/temp.html). После этого [**index.html**](https://github.com/Harrix/HarrixHtmlForQWebView/blob/master/index.html), открытая в QWebView автоматически (плюс-минус одна секунда) обновит свое содержимое и отскроллит окно к низу.

Предупреждение
--------------

Данная страница не будет работать на локальном компьютере через браузеры. То есть, если вы откроете файл [**index.html**](https://github.com/Harrix/HarrixHtmlForQWebView/blob/master/index.html), например, в Chrome, то откроется пустая страница. Это связано с тем, что в браузерах обычно стоит запрет на ajax в локальных файлах. Но если загрузите на сервер, то все будет отображаться.

Учтите, что программы, которые используют данную библиотеку напрямую, не должны запускаться несколькими экземплярами одновременно, чтобы не изменять файл [temp.html](https://github.com/Harrix/HarrixHtmlForQWebView/blob/master/temp.html) одновременно.
 
Скриншоты некотрых программ с этой библиотекой
----------------------------------------------

![alt text](https://raw.github.com/Harrix/HarrixHtmlForQWebView/master/imagesforgithub/example1.png "Проект HarrixChart")

![alt text](https://raw.github.com/Harrix/HarrixHtmlForQWebView/master/imagesforgithub/example2.png "Проект HarrixMathLibrary")

Подключенные библиотеки
-----------------------
 * **jQuery** - для скролла страниц: [http://jquery.com](http://jquery.com)
 * **JSXGraph** - для отображения графиков: [https://github.com/jsxgraph/jsxgraph](https://github.com/jsxgraph/jsxgraph)
 
Использованные технологии
-------------------------

- [Html](http://ru.wikipedia.org/wiki/HTML), [jQuery](http://jquery.com/), [AJAX](http://ru.wikipedia.org/wiki/AJAX), [JSXGraph](https://github.com/jsxgraph/jsxgraph), [QWebView](http://qt-project.org/doc/qt-5/qwebview.html), [Qt](http://qt-project.org/).

История проекта
---------------

Подробный список изменений в файле [CHANGELOG.md](https://github.com/Harrix/HarrixHtmlForQWebView/blob/master/CHANGELOG.md).

Контакты
--------

Автор: Сергиенко Антон Борисович.

С автором можно связаться по адресу [sergienkoanton@mail.ru](mailto:sergienkoanton@mail.ru) или  [http://vk.com/harrix](http://vk.com/harrix).

Сайт автора, где публикуются последние новости: [http://blog.harrix.org](http://blog.harrix.org), а проекты располагаются по адресу: [http://harrix.org](http://harrix.org).