HarrixClass_HarrixData
===========================================

Версия 1.0

Класс HarrixClass_HarrixData для считывания информации формата данных Harrix Data на C++ для Qt.

https://github.com/Harrix/HarrixClass_HarrixData

Библиотека распространяется по лицензии [Apache License, Version 2.0](../master/LICENSE.txt).

Описание формата [**Harrix Data 1.1**](../master/Harrix Data 1.1/) вы найдете тут:

https://github.com/Harrix/HarrixFileFormats

Примеры файлов данного формата представлены в папке [Examples](../master/Examples).

Пример использования
--------------------
Скопируйте файлы из списка в папку с исходниками вашего проекта.
- [HarrixClass_HarrixData.cpp](../master/HarrixClass_HarrixData.cpp)
- [HarrixClass_HarrixData.h](../master/HarrixClass_HarrixData.h)
- [HarrixQtLibraryForQWebView.cpp](../master/HarrixQtLibraryForQWebView.cpp)
- [HarrixQtLibraryForQWebView.h](../master/HarrixQtLibraryForQWebView.h)
- [HarrixQtLibrary.cpp](../master/HarrixQtLibrary.cpp)
- [HarrixQtLibrary.h](../master/HarrixQtLibrary.h)

Добавьте эти файлы в ваш проект через правый клик мыши по проекту в Qt Creator и выбрав пункт Add Exsisting Files...

А файлы из списка в папку с *.exe файлом вашего проекта.
- папка [images](../master/images)
- [index.html](../master/index.html)
- [jquery.js](../master/jquery.js)
- [jsxgraphcore.js](../master/jsxgraphcore.js)
- [style.css](../master/style.css)

Добавьте  соответствующие инклуды:

```cpp
#include "HarrixClass_HarrixData.h"
#include "HarrixQtLibrary.h"
#include "HarrixQtLibraryForQWebView.h"
```

Объявите, например, в mainwindow.h глобальные переменные:

```cpp
QString DS;//разделитель между папками: слэш или иное в данной ОС
QString Path;//путь к папке с программой
QString Html;//сюда кладется выводимый текст
```

В проекте должен быть экземпляр QWebView.

Вам нужно вызвать данные 4 строчки, например, в конструкторе ``MainWindow::MainWindow(QWidget *parent)``:

```cpp
DS=QDir::separator();//какой разделитель используется в пути между папками
Path=QGuiApplication::applicationDirPath()+DS;//путь к папке, где находится приложение
HQt_BeginHtml(Path);
// и в webView отображаем index.html (его вообще не трогаем)
ui->webView->setUrl(QUrl::fromLocalFile(Path+"index.html"));
```
	
Теперь в любом месте, где хотите добавить текст html и его отобразить, пишите (filename - путь к файлу, который анализируется):

```cpp
QString Html;//сюда записывается код  HTML по анализу файла данных
HarrixClass_HarrixData Data(filename);
if (Data.getSuccessReading())
	{
	Html=Data.getChartHtmlCode();
	HQt_AddHtml(Html);
	}
```

Аналогично выводится Latex код через функцию getChartLatexCode();
	
И соответствующий текст должен отобразиться в QWebView максимум за 1 секунду: каждую секунду происходит проверка на наличие обновления.

Скриншоты применения библиотеки
-------------------------------

![alt text](../master/imagesforgithub/example2.png "Пример вывода")

![alt text](../master/imagesforgithub/example3.png "Пример вывода")

![alt text](../master/imagesforgithub/example24.png "Пример вывода")

![alt text](../master/imagesforgithub/example5.png "Пример вывода")

![alt text](../master/imagesforgithub/example6.png "Пример вывода")

![alt text](../master/imagesforgithub/example7.png "Пример вывода")

![alt text](../master/imagesforgithub/example8.png "Пример вывода")

![alt text](../master/imagesforgithub/example9.png "Пример вывода")

История проекта
---------------

Подробный список изменений в файле [CHANGELOG.md](../master/CHANGELOG.md).

Контакты
--------

Автор: Сергиенко Антон Борисович.

С автором можно связаться по адресу sergienkoanton@mail.ru или  http://vk.com/harrix.

Сайт автора, где публикуются последние новости: http://blog.harrix.org, а проекты располагаются по адресу: http://harrix.org.
