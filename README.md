HarrixClass_HarrixData
===========================================

Версия 1.2

Класс HarrixClass_HarrixData для считывания информации формата данных Harrix Data на C++ для Qt.

https://github.com/Harrix/HarrixClass_HarrixData

Библиотека распространяется по лицензии [Apache License, Version 2.0](../master/LICENSE.txt).

Описание формата [**Harrix Data 1.1**](../master/Harrix Data 1.1/) вы найдете тут:

https://github.com/Harrix/HarrixFileFormats

Примеры файлов данного формата представлены в папке [Examples](../master/Examples).

Установка
---------

Подробно о установке с подробным примером можно прочитать тут http://blog.harrix.org/?p=1127.

Скриншоты применения библиотеки
-------------------------------

![alt text](../master/imagesforgithub/example2.png "Пример вывода")

![alt text](../master/imagesforgithub/example3.png "Пример вывода")

![alt text](../master/imagesforgithub/example4.png "Пример вывода")

![alt text](../master/imagesforgithub/example5.png "Пример вывода")

![alt text](../master/imagesforgithub/example_6.png "Пример вывода")

![alt text](../master/imagesforgithub/example7.png "Пример вывода")

![alt text](../master/imagesforgithub/example8.png "Пример вывода")

![alt text](../master/imagesforgithub/example9.png "Пример вывода")

Как вывести все значения для использования?
-------------------------------------------

```cpp
HarrixClass_HarrixData H(filename);
double x;
for (int k=0;k<H.getNumberOfCharts();k++)//прогон по линиям
{
   for (int i=0;i<H.getNumberElementsInChart(k);i++)//прогон по точкам
   {
       for (int j=0;j<H.getNumberCoordinateInChart();j++)//прогон по координатам точки
       {
           x = H.getPointCoordinateOfData(k,i,j);
       }
   }
}
```

Использованные технологии
-------------------------

- [Html](http://ru.wikipedia.org/wiki/HTML), [jQuery](http://jquery.com/), [JSXGraph](https://github.com/jsxgraph/jsxgraph), [QWebView](http://qt-project.org/doc/qt-5/qwebview.html), [Qt](http://qt-project.org/), [LaTeX](http://ru.wikipedia.org/wiki/LaTeX), [MiKTeX](http://miktex.org/), [TeXstudio](http://texstudio.sourceforge.net/), [PSCyr](http://blog.harrix.org/?p=444), [AJAX](http://ru.wikipedia.org/wiki/AJAX), [pgfplots](http://pgfplots.sourceforge.net/).
- [HarrixQtLibrary](https://github.com/Harrix/HarrixQtLibrary), [HarrixQtLibraryForLaTeX](https://github.com/Harrix/HarrixQtLibraryForLaTeX), [HarrixQtLibraryForQWebView](https://github.com/Harrix/HarrixQtLibraryForQWebView), [HarrixHtmlForQWebView](https://github.com/Harrix/HarrixHtmlForQWebView), [HarrixLaTeXDocumentTemplate](https://github.com/Harrix/HarrixLaTeXDocumentTemplate).

Сведения для редактирования файлов
----------------------------------

Для полноценной работы редактированию LaTeX документа вам потребуются программа для компиляции \*.tex документов в \*.pdf. Автор использует для этого связку [MiKTex](http://www.miktex.org/) и [TeXstudio](http://texstudio.sourceforge.net/). 

В варианте, который использует автор, в \*.tex файлах справок для отображения русских букв используется модуль pscyr. Об его установке можно прочитать (и скачать) в статье http://blog.harrix.org/?p=444.

Подробное описание установки и настройки связки MiKTeX + TeXstudio + pscyr можно прочитать в статье http://blog.harrix.org/?p=849.

История проекта
---------------

Подробный список изменений в файле [CHANGELOG.md](../master/CHANGELOG.md).

Контакты
--------

Автор: Сергиенко Антон Борисович.

С автором можно связаться по адресу [sergienkoanton@mail.ru](mailto:sergienkoanton@mail.ru) или  [http://vk.com/harrix](http://vk.com/harrix).

Сайт автора, где публикуются последние новости: [http://blog.harrix.org](http://blog.harrix.org), а проекты располагаются по адресу: [http://harrix.org](http://harrix.org).
