QtHarrixLibraryForQWebView
=================

Библиотека для отображения различных данных в QWebView. Версия v.1.5.

https://github.com/Harrix/QtHarrixLibraryForQWebView

Библиотека распространяется по лицензии Apache License, Version 2.0.

Функции для получения HTML кода для вывода в webView
---------------

void **HQt_BeginHtml**(QString Path);  
Функция обнуляет переменную HTML. Требуется когда нужно перезапустить показ информации в QWebView.

void **HQt_AddHtml**(QString Html);  
Функция добавляет код html к существующему и сохраняет его в temp.html.

template <class T> QString **THQt_NumberToText** (T VMHL_X);  
Функция выводит число VMHL_X в строку.

QString **HQt_ShowText** (QString TitleX);
Функция возвращает строку с выводом некоторой строки с HTML кодами. Для добавление в html файл.

QString **HQt_ShowSimpleText** (QString String);  
Функция возвращает строку с выводом некоторой строки с HTML кодами без всякого излишеств. Для добавление в html файл.

QString **HQt_ShowH1** (QString String);  
Функция возвращает строку с выводом некоторой строки в виде заголовка. Для добавление в html файл.

QString **HQt_ShowHr** ();  
Функция возвращает строку с выводом горизонтальной линии. Для добавление в html файл.

QString **HQt_ShowAlert** (QString String);  
Функция возвращает строку с выводом некоторого предупреждения. Для добавление в html файл.

template <class T> QString **THQt_ShowNumber** (T VMHL_X, QString TitleX, QString NameX);  
Функция возвращает строку с выводом некоторого числа VMHL_X с HTML кодами.

template <class T> QString **THQt_ShowNumber** (T VMHL_X, QString NameX);  
Функция возвращает строку с выводом некоторого числа VMHL_X с HTML кодами. Для добавление в html файл.

template <class T> QString **THQt_ShowNumber** (T VMHL_X);  
Функция возвращает строку с выводом некоторого числа VMHL_X с HTML кодами. Для добавление в html файл.

template <class T> QString **THQt_ShowVector** (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);  
Функция возвращает строку с выводом некоторый вектора VMHL_Vector с HTML кодами.

template <class T> QString **THQt_ShowVector** (T *VMHL_Vector, int VMHL_N, QString NameVector);  
Функция возвращает строку с выводом некоторый вектора VMHL_Vector с HTML кодами.

template <class T> QString **THQt_ShowVector** (T *VMHL_Vector, int VMHL_N);  
Функция возвращает строку с выводом некоторый вектора VMHL_Vector с HTML кодами.

template <class T> QString **THQt_ShowVectorT** (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);  
Функция возвращает строку с выводом некоторый вектора VMHL_Vector в транспонированном виде с HTML кодами.

template <class T> QString **THQt_ShowVectorT** (T *VMHL_Vector, int VMHL_N, QString NameVector);  
Функция возвращает строку с выводом некоторый вектора VMHL_Vector в траснпонированном виде с HTML кодами.

template <class T> QString **THQt_ShowVectorT** (T *VMHL_Vector, int VMHL_N);  
Функция возвращает строку с выводом некоторый вектора VMHL_Vector в траснпонированном виде с HTML кодами.

template <class T> QString **THQt_ShowMatrix** (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix);  
Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами.

template <class T> QString **THQt_ShowMatrix** (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString NameMatrix);  
Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами.

template <class T> QString **THQt_ShowMatrix** (T *VMHL_Matrix, int VMHL_N, int VMHL_M);  
Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами.

template <class T> QString **THQt_ShowChartOfLine** (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);  
Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в HTML файл.

template <class T> QString **THQt_ShowChartOfLine** (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);  
Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в HTML файл. Отличается от основной функцией отсутствием параметра NameLine(название первого графика (для легенды)).

template <class T> QString **THQt_ShowChartOfLine** (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);  
Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Отличается от основной функцией отсутствием булевских параметров в конце - все по умолчанию делается.

template <class T> QString **THQt_ShowChartOfLine** (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N);  
Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Отличается от основной функцией отсутствием булевских параметров в конце и названий осей и графиков - для быстрого отображения графика без лишних телодвижений.

template <class T> QString **THQt_ShowTwoChartsOfLine** (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);  
Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в HTML файл.

template <class T> QString **THQt_ShowTwoChartsOfLine** (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);  
Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Отличается отсутствием параметров NameLine1 и NameLine2. То есть нет легенды у графика.

template <class T> QString **THQt_ShowTwoChartsOfLine** (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);  
Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в HTML файл. Отличается от основной функции отсутствием булевских переменных - все по умолчанию.

template <class T> QString **THQt_ShowTwoChartsOfLine** (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N);  
Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Отличается от основной функции отсутствием булевских переменных и названий графика, осей, линий - все по умолчанию.

template <class T> QString **THQt_ShowTwoIndependentChartsOfLine** (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);  
Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.

template <class T> QString **THQt_ShowTwoIndependentChartsOfLine** (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);  
Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Отличается от основной функции отсутствием легенды, то есть параметров NameLine1, NameLine2.

template <class T> QString **THQt_ShowTwoIndependentChartsOfLine** (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);  
Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Отличается от основной функции отсутствием булевых параметров - все по умолчанию.

template <class T> QString **THQt_ShowTwoIndependentChartsOfLine** (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2);  
Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами.Отличается от основной функции отсутствием булевых параметров и подписей - все по умолчанию.

template <class T> QString **THQt_ShowChartsOfLineFromMatrix** (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);  
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Первый столбец - это значения вектора X, одинакового для всех графиков. Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.

template <class T> QString **THQt_ShowChartsOfLineFromMatrix** (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);  
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл. Первый столбец - это значения вектора X, одинакового для всех графиков. Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов. Отличается от основной библиотеки отсутствием легенды (нет параметра NewLine).

template <class T> QString **THQt_ShowChartsOfLineFromMatrix** (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine);//Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл. Отличается от основной функции отсутствием булевых переменных - все по умолчанию.

template <class T> QString **THQt_ShowChartsOfLineFromMatrix** (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M);  
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл. Отличается от основной функции отсутствием булевых переменных и названий осей, графиков - все по умолчанию.

template <class T> QString **THQt_ShowIndependentChartsOfLineFromMatrix** (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);  
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл. Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие значения Y. То есть графики друг от друга независимы. Количество графиков равно половине столбцов в матрице.

template <class T> QString **THQt_ShowIndependentChartsOfLineFromMatrix** (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);  
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Отличается от основной функции отсутствием легенды на графике.

template <class T> QString **THQt_ShowIndependentChartsOfLineFromMatrix** (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine);  
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл. Отличается от основной функции отсутствием булевых переменных - все по умолчанию.

template <class T> QString **THQt_ShowIndependentChartsOfLineFromMatrix** (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M);  
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Отличается от основной функции отсутствием булевых переменных, названий осей, графиков - все по умолчанию.

template <class T> QString **THQt_ShowTwoIndependentChartsOfPointsAndLine** (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);  
Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий. Для добавление в html файл.

template <class T> QString **THQt_ShowTwoIndependentChartsOfPointsAndLine** (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);  
Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий. Отличается от основной функции отсутствием легенды, то есть параметров NameLine1, NameLine2.

template <class T> QString **THQt_ShowTwoIndependentChartsOfPointsAndLine** (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);  
Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий. Отличается от основной функции отсутствием булевых параметров - все по умолчанию.

template <class T> QString **THQt_ShowTwoIndependentChartsOfPointsAndLine** (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2);  
Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий. Отличается от основной функции отсутствием булевых параметров и подписей - все по умолчанию.

QString **HQt_ReadHdataToHtmlChart** (QString filename);  
Функция возвращает строку с HTML кодом графика в результате считывания информации из *.hdata. Для добавление в html файл.

QString **HQt_DrawLine** (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);  
Функция возвращает строку с HTML кодом отрисовки линии по функции Function. Для добавление в html файл.

QString **HQt_DrawLine** (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);  
Функция возвращает строку с HTML кодом отрисовки линии по функции Function. Для добавление в html файл. Отличается от основной функцией отсутствием параметра NameLine(название графика (для легенды)).

QString **HQt_DrawLine** (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);  
Функция возвращает строку с HTML кодом отрисовки линии по функции Function. Для добавление в html файл. Отличается от основной функцией отсутствием булевских параметров в конце - все по умолчанию делается.

QString **HQt_DrawLine** (double Left, double Right, double h, double (*Function)(double));  
Функция возвращает строку с HTML кодом отрисовки линии по функции Function. Для добавление в html файл. Отличается от основной функцией отсутствием булевских параметров в конце и названий осей и графиков - для быстрого отображения графика без лишних телодвижений.

Пример использования функция вывода в HTML файл
---------------
Режим постоянного отображения изменений осуществляется благодаря функции AJAX. Поэтому вы отображаете в QWebView файл **index.html**, а сохраняете данные в **temp.html**. Отображаемый файл **index.html** не трогаете.

Скопируйте файлы из списка в папку с исходниками вашего проекта.
- QtHarrixLibraryForQWebView.cpp
- QtHarrixLibraryForQWebView.h
- QtHarrixLibrary.cpp
- QtHarrixLibrary.h

А файлы из списка в папку с *.exe файлом вашего проекта.
- папка images
- index.html
- jquery.js
- jsxgraphcore.js
- style.css

Объявите, например, в mainwindow.h глобальные переменные:

    QString DS;//разделитель между папками: слэш или иное в данной ОС
    QString Path;//путь к папке с программой
    QString Html;//сюда кладется выводимый текст

Вам нужно вызвать данные 4 строчки, например, в конструкторе MainWindow::MainWindow(QWidget *parent):

    DS=QDir::separator();//какой разделитель используется в пути между папками
    Path=QGuiApplication::applicationDirPath()+DS;//путь к папке, где находится приложение
    HQt_BeginHtml(Path);
    ui->webView->setUrl(QUrl::fromLocalFile(Path+"index.html"));// и в webViewотображаем index.html (его вообще не трогаем)
	
Теперь в любом месте, где хотите добавить текст html и его отобразить, пишите:

	Html="<b>Example</b>";
	HQt_AddHtml(Html);
	
И соответствующий текст должен отобразиться в QWebView максимум за 1 секунду: каждую секунду происходит проверка на наличие обновления. Желательно добавлять текст Html не самостоятельно, а за счет функций данной библиотеки.

История проекта
---------------

**[-]** исправление

**[+]** добавление

**[*]** разное

**1.5**

**[+]** Добавлены функции template <class T> QString **THQt_ShowNumber** (T VMHL_X, QString NameX), template <class T> QString **THQt_ShowVector** (T *VMHL_Vector, int VMHL_N), template <class T> QString **THQt_ShowVectorT** (T *VMHL_Vector, int VMHL_N, QString NameVector), template <class T> QString **THQt_ShowVectorT** (T *VMHL_Vector, int VMHL_N), template <class T> QString **THQt_ShowMatrix** (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString NameMatrix), 
template <class T> QString **THQt_ShowMatrix** (T *VMHL_Matrix, int VMHL_N, int VMHL_M).

**1.4**

**[-]** Исправлены ошибки с отображением векторов.

**1.3**

**[*]** Оптимизирована работа некоторых функций.

**[-]** Иногда прокрутка не докручивалась. Вставлен костыль.

**[+]** Добавлена функция QString HQt_ShowH1 (QString String).

**[+]** Добавлена функция QString HQt_ShowHr ().

**[-]** Почти все стили вынесены в style.css.

**1.2**

**[+]** Добавлена автоматическая прокрутка отображения в QWebView при добавлении новых данных.

**1.1**

**[+]** Добавлены функции void HQt_BeginHtml(QString Path) и void HQt_AddHtml(QString Html).

**[*]** Изменение работы ajax скрипта. Теперь обновление происходит только когда появилась новая информация.

**1.0**

**[*]** Библиотека есть следствие выделения функций для отображения в QWebView данных из библиотеки QtHarrixLibrary.

**[*]** Отображение данных перешло на ajax технологию с применением JQuery библиотеки.

Контакты
---------------

Автор: Сергиенко Антон Борисович.

С автором можно связаться по адресу sergienkoanton@mail.ru или  http://vk.com/harrix .

Сайт автора, где публикуются последние новости: http://blog.harrix.org, а проекты располагаются по адресу http://harrix.org .