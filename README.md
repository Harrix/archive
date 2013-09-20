HarrixClass_DataOfHarrixOptimizationTesting
===============================

Версия 1.12

Класс HarrixClass_DataOfHarrixOptimizationTesting для считывания информации формата данных Harrix Optimization Testing на C++ для Qt.

https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting

Библиотека распространяется по лицензии Apache License, Version 2.0.

Описание формата Harrix Optimization Testing вы найдете тут:

https://github.com/Harrix/HarrixFileFormats

Пример файла данного формата представлен в этом проекте как Example.xml.

Пример использования
---------------
Скопируйте файлы из списка в папку с исходниками вашего проекта.
- HarrixClass_DataOfHarrixOptimizationTesting.cpp
- HarrixClass_DataOfHarrixOptimizationTesting.h
- HarrixQtLibraryForQWebView.cpp
- HarrixQtLibraryForQWebView.h
- HarrixQtLibrary.cpp
- HarrixQtLibrary.h
- HarrixMathLibrary.cpp
- HarrixMathLibrary.h

А файлы из списка в папку с *.exe файлом вашего проекта.
- папка images
- index.html
- jquery.js
- jsxgraphcore.js
- style.css

Добавьте  соответствующие инклуды:

	#include "HarrixClass_DataOfHarrixOptimizationTesting.h"
    #include "HarrixMathLibrary.h"
    #include "HarrixQtLibrary.h"
    #include "HarrixQtLibraryForQWebView.h"

Объявите, например, в mainwindow.h глобальные переменные:

    QString DS;//разделитель между папками: слэш или иное в данной ОС
    QString Path;//путь к папке с программой
    QString Html;//сюда кладется выводимый текст

Вам нужно вызвать данные 4 строчки, например, в конструкторе MainWindow::MainWindow(QWidget *parent):

    DS=QDir::separator();//какой разделитель используется в пути между папками
    Path=QGuiApplication::applicationDirPath()+DS;//путь к папке, где находится приложение
    HQt_BeginHtml(Path);
	ui->webView->setUrl(QUrl::fromLocalFile(Path+"index.html"));// и в webView отображаем index.html (его вообще не трогаем)
	
Теперь в любом месте, где хотите добавить текст html и его отобразить, пишите (filename - путь к файлу, который анализируется):

	QString Html;//сюда записывается код  HTML по анализу файла данных
    HarrixClass_DataOfHarrixOptimizationTesting Data(filename);
    if (Data.getSuccessReading())
    {
        Html=Data.getHtml();
        HQt_AddHtml(Html);
    }
	
И соответствующий текст должен отобразиться в QWebView максимум за 1 секунду: каждую секунду происходит проверка на наличие обновления. Желательно добавлять текст Html не самостоятельно, а за счет функций данной библиотеки.

Изменения в последней версии
---------------

1.12

[*] Переименование проекта на HarrixClass_DataOfHarrixOptimizationTesting.

[*] Полная история перенесена в History.txt.

Подробный список изменений в файле History.txt.

Контакты
---------------

Автор: Сергиенко Антон Борисович.

С автором можно связаться по адресу sergienkoanton@mail.ru или  http://vk.com/harrix .

Сайт автора, где публикуются последние новости: http://blog.harrix.org, а проекты располагаются по адресу http://harrix.org .
