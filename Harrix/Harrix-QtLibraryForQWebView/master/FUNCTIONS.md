Список функций библиотеки HarrixQtLibraryForQWebView
====================================================

Главные загрузочные функции
----------------

- Функция добавляет код html к существующему и сохраняет его в temp.html.

```cpp
void HQt_AddHtml(QString Html);
```

- Функция обнуляет переменную HTML. Требуется когда нужно перезапустить показ информации в QWebView.

```cpp
void HQt_BeginHtml(QString Path);
```

Показ графиков
----------------

- Функция возвращает строку с HTML кодом отрисовки линии по функции Function. Для добавление в html файл.

```cpp
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double));
```

- Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.

```cpp
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N);
```

- Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.

```cpp
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine);
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M);
```

- Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.

```cpp
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine);
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M);
```

- Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл. У обоих графиков одинаковый массив значений X.

```cpp
template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);
template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N);
```

- Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.

```cpp
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2);
```

- Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий. У обоих графиков разные массивы значений X и Y.

```cpp
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2);
```

Показ математических выражений
----------------

- Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с HTML кодами. Для добавление в html файл.

```cpp
template <class T> QString THQt_ShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString TitleMatrix, QString NameMatrix);
template <class T> QString THQt_ShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString NameMatrix);
template <class T> QString THQt_ShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M);
```

- Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с HTML кодами. Для добавление в html файл. В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый QStringList --- это одна строка.

```cpp
QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString TitleMatrix, QString NameMatrix);
QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString NameMatrix);
QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N);
```

- Функция возвращает строку с выводом некоторого числа VHQt_X с HTML кодами. Для добавление в html файл.

```cpp
template <class T> QString THQt_ShowNumber (T VHQt_X, QString TitleX, QString NameX);
template <class T> QString THQt_ShowNumber (T VHQt_X, QString NameX);
template <class T> QString THQt_ShowNumber (T VHQt_X);
```

- Функция возвращает строку с выводом некоторого вектора VHQt_Vector с HTML кодами. Для добавление в html файл.

```cpp
template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector);
template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N, QString NameVector);
template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N);
```

- Функция возвращает строку с выводом некоторого списка строк VHQt_Vector с HTML кодами. Для добавление в html файл.

```cpp
QString THQt_ShowVector (QStringList VHQt_Vector, QString TitleVector, QString NameVector);
QString THQt_ShowVector (QStringList VHQt_Vector, QString NameVector);
QString THQt_ShowVector (QStringList VHQt_Vector);
```

- Функция возвращает строку с выводом некоторого вектора VHQt_Vector в траснпонированном виде с HTML кодами. Для добавление в html файл.

```cpp
template <class T> QString THQt_ShowVectorT (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector);
template <class T> QString THQt_ShowVectorT (T *VHQt_Vector, int VHQt_N, QString NameVector);
template <class T> QString THQt_ShowVectorT (T *VHQt_Vector, int VHQt_N);
```

Показ текста
----------------

- Функция возвращает строку с выводом некоторого предупреждения. Для добавление в html файл.

```cpp
QString HQt_ShowAlert (QString String);
```

- Функция возвращает строку с выводом некоторой строки в виде заголовка. Для добавление в html файл.

```cpp
QString HQt_ShowH1 (QString String);
```

- Функция возвращает строку с выводом горизонтальной линии. Для добавление в html файл.

```cpp
QString HQt_ShowHr ();
```

- Функция возвращает строку с выводом некоторой строки с HTML кодами без всякого излишества. Для добавление в html файл.

```cpp
QString HQt_ShowSimpleText (QString String);
```

- Функция возвращает строку с выводом некоторой строки с HTML кодами. Для добавление в html файл.

```cpp
QString HQt_ShowText (QString TitleX);
```

- Функция выводит число VHQt_X в строку.

```cpp
template <class T> QString THQt_NumberToText (T VHQt_X);
```