//HarrixQtLibraryForLaTeX
//Версия 1.33
//Библиотека для отображения различных данных в LaTeX файлах.
//https://github.com/Harrix/HarrixQtLibraryForLaTeX
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#ifndef HARRIXQTLIBRARYFORLATEX_H
#define HARRIXQTLIBRARYFORLATEX_H

#include "HarrixQtLibrary.h"
#include <math.h>

enum TypeOf3DPlot { Plot3D_Points, Plot3D_Surface, Plot3D_SurfaceGrid, Plot3D_TopView};//тип 3D графика в виде поверхности

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Главные загрузочные функции
QString HQt_LatexBegin();
QString HQt_LatexBeginArticle();
QString HQt_LatexBeginArticleWithPgfplots();
QString HQt_LatexBeginWithPgfplots();
QString HQt_LatexEnd();

//Графики
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double));
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, double Opacity, double AngleHorizontal, double AngleVertical, bool ColorBar, bool ForNormalSize);
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar, bool ForNormalSize);
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar);
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type);
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label);
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double));
QString THQt_LatexDraw3DPlot (double Left, double Right, int N, double (*Function)(double, double));
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, double Opacity, double AngleHorizontal, double AngleVertical, bool ColorBar, bool ForNormalSize);
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar, bool ForNormalSize);
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar);
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type);
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label);
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M);
template <class T> QString THQt_LatexShow3DPlotPoints (T *VHQt_VectorX, T *VHQt_VectorY, T *VHQt_VectorZ,  int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, bool ForNormalSize);
template <class T> QString THQt_LatexShow3DPlotPoints (T *VHQt_VectorX, T *VHQt_VectorY, T *VHQt_VectorZ,  int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, bool ForNormalSize);
template <class T> QString THQt_LatexShow3DPlotPoints (T *VHQt_VectorX, T *VHQt_VectorY, T *VHQt_VectorZ,  int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label);
template <class T> QString THQt_LatexShow3DPlotPoints (T *VHQt_VectorX, T *VHQt_VectorY, T *VHQt_VectorZ,  int VHQt_N);
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero);
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize);
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label);
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N);
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero);
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize);
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label);
template <class T> QString THQt_LatexShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine, bool ForNormalSize);
template <class T> QString THQt_LatexShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
template <class T> QString THQt_LatexShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints);
template <class T> QString THQt_LatexShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label);
template <class T> QString THQt_LatexShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N);
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle);
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label);
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M);
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle);
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label);
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M);
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle);
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label);
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M);
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle);
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label);
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2);

//Обработка текста
QString HQt_ForcedWordWrap(QString S);
QString HQt_LatexGreenText (QString String);
QString HQt_LatexRedText (QString String);
QString HQt_TextForLatexToText (QString String);
QString HQt_TextToTextForLatex (QString Text);
template <class T> QString THQt_LatexNumberToText (T VHQt_X);

//Показ математических выражений
template <class T> QString THQt_LatexShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString TitleMatrix, QString NameMatrix);
template <class T> QString THQt_LatexShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString NameMatrix);
template <class T> QString THQt_LatexShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M);
QString THQt_LatexShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString TitleMatrix, QString NameMatrix);
QString THQt_LatexShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString NameMatrix);
QString THQt_LatexShowMatrix (QStringList *VHQt_Matrix, int VHQt_N);
template <class T> QString THQt_LatexShowVector (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector);
template <class T> QString THQt_LatexShowVector (T *VHQt_Vector, int VHQt_N, QString NameVector);
template <class T> QString THQt_LatexShowVector (T *VHQt_Vector, int VHQt_N);
QString THQt_LatexShowVector (QStringList VHQt_Vector, QString TitleVector, QString NameVector);
QString THQt_LatexShowVector (QStringList VHQt_Vector, QString NameVector);
QString THQt_LatexShowVector (QStringList VHQt_Vector);
template <class T> QString THQt_LatexShowVectorT (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector);
template <class T> QString THQt_LatexShowVectorT (T *VHQt_Vector, int VHQt_N, QString NameVector);
template <class T> QString THQt_LatexShowVectorT (T *VHQt_Vector, int VHQt_N);

//Составные изображения
QString HQt_LatexBeginCompositionFigure ();
QString HQt_LatexBeginFigureInCompositionFigure ();
QString HQt_LatexEndCompositionFigure (QString TitleFigure, QString Label);
QString HQt_LatexEndCompositionFigure (QString TitleFigure);
QString HQt_LatexEndCompositionFigure ();
QString HQt_LatexEndFigureInCompositionFigure ();

//Таблицы
QString HQt_LatexShowTable (QStringList Col1, QStringList Col2, QString NameCol1, QString NameCol2, double WidthCol1, QString Title);
QString HQt_LatexShowTable (QStringList Col1, QStringList Col2, QStringList Col3, QString NameCol1, QString NameCol2, QString NameCol3, double WidthCol1, double WidthCol2, QString Title);

//Текст
QString HQt_LatexShowAlert (QString String);
QString HQt_LatexShowHr ();
QString HQt_LatexShowSection (QString String);
QString HQt_LatexShowSimpleText (QString String);
QString HQt_LatexShowSubsection (QString String);
QString HQt_LatexShowText (QString TitleX);
template <class T> QString THQt_LatexShowNumber (T VHQt_X, QString TitleX, QString NameX);
template <class T> QString THQt_LatexShowNumber (T VHQt_X, QString NameX);
template <class T> QString THQt_LatexShowNumber (T VHQt_X);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//*****************************************************************
//Главные загрузочные функции
//*****************************************************************
//*****************************************************************
//Графики
//*****************************************************************
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, double Opacity, double AngleHorizontal, double AngleVertical, bool ColorBar, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху;
     Opacity - прозначность графика. Может изменяться от 0 до 1;
     AngleHorizontal - угол поворота графика по горизонтали в градусах от -180 до 180. Рекомендуется 25;
     AngleVertical - угол поворота графика по вертикали в градусах от -180 до 180. Рекомендуется 30;
     ColorBar - рисоватm с графиком колонку с градациями цветов или нет;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j;

    if (ForNormalSize)
        VHQt_Result+="% Вывод графика\n";
    else
        VHQt_Result+="% Вывод подграфика\n";

    //Обработаем текст подписи к осям.
    QString NameVectorXnew=NameVectorX,NameVectorYnew=NameVectorY, NameVectorZnew=NameVectorZ, subStr;

    subStr=",";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorZnew.contains(subStr))
        NameVectorZnew="$"+NameVectorZnew.replace(NameVectorZnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorZnew.contains(subStr))
        NameVectorZnew="$"+NameVectorZnew.replace(NameVectorZnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorXnew.contains(","))&&(!NameVectorXnew.contains(".")))
        if (!HQt_CheckRus(NameVectorXnew))
            NameVectorXnew="$"+NameVectorXnew+"$";

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    if ((!NameVectorZnew.contains(","))&&(!NameVectorZnew.contains(".")))
        if (!HQt_CheckRus(NameVectorZnew))
            NameVectorZnew="$"+NameVectorZnew+"$";

    NameVectorXnew=NameVectorXnew.replace(";","");
    NameVectorYnew=NameVectorYnew.replace(";","");
    NameVectorZnew=NameVectorZnew.replace(";","");

    NameVectorXnew=NameVectorXnew.replace("&","\\");
    NameVectorYnew=NameVectorYnew.replace("&","\\");
    NameVectorZnew=NameVectorZnew.replace("&","\\");

    //рисуем область графика и оси
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    VHQt_Result+="{\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="xlabel={"+NameVectorXnew+"},\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";
    VHQt_Result+="zlabel={"+NameVectorZnew+"},\n";
    if (ForNormalSize)
    {
        VHQt_Result+="height=12cm,\n";
        VHQt_Result+="width=12cm,\n";
    }
    else
    {
        VHQt_Result+="height=5.8cm,\n";
        VHQt_Result+="width=5.8cm,\n";
    }
    VHQt_Result+="z buffer=sort,\n";
    VHQt_Result+="colormap name="+ColorMap+",\n";
    if (!ForNormalSize) VHQt_Result+="label style={font=\\tiny},\n";
    if (ForNormalSize)  VHQt_Result+="label style={font=\\small},\n";
    if (!ForNormalSize) VHQt_Result+="tick label style={font=\\tiny},\n";
    if (ColorBar) VHQt_Result+="colorbar,\n";
    if (ColorBar) VHQt_Result+="colorbar style={axis lines=box},\n";
    if (Type==Plot3D_TopView) VHQt_Result+="view={0}{90},\n";
    if (Type==Plot3D_TopView) VHQt_Result+="grid=none,\n";
    if (Type!=Plot3D_TopView) VHQt_Result+="view/h="+QString::number(AngleHorizontal)+",\n";
    if (Type!=Plot3D_TopView) VHQt_Result+="view/h="+QString::number(AngleVertical)+",\n";
    VHQt_Result+="]\n\n";

    //соберем в массивы данные точек
    QString SData;
    for (i=0;i<VHQt_N;i++)
        for (j=0;j<VHQt_M;j++)
        SData+=" (" + QString::number(VHQt_VectorX[i]) + ", " + QString::number(VHQt_VectorY[j])+", " + QString::number(VHQt_VectorZ[i][j]) + ") \n";

    QString MarkSize;
    if (!ForNormalSize) MarkSize=",mark size=1pt";

    if (Type==Plot3D_Points)
    {
    //Добавим график
    VHQt_Result+="\\addplot3[only marks,scatter"+MarkSize+", opacity="+QString::number(Opacity)+"] coordinates {\n"+SData+"\n};\n";
    }

    if (Type==Plot3D_Surface)
    {
    //поверхность с непрерывной заливкой
    VHQt_Result+="\\addplot3[surf,shader=interp,mesh/cols="+QString::number(VHQt_M)+", opacity="+QString::number(Opacity)+"] coordinates {\n"+SData+"\n};\n";
    }

    if (Type==Plot3D_SurfaceGrid)
    {
    //поверхность с сеточной заливкой
    VHQt_Result+="\\addplot3[surf,shader=faceted,mesh/cols="+QString::number(VHQt_M)+", opacity="+QString::number(Opacity)+"] coordinates {\n"+SData+"\n};\n";
    }

    if (Type==Plot3D_TopView)
    {
    //вид сверху
    VHQt_Result+="\\addplot3[surf,shader=interp,mesh/cols="+QString::number(VHQt_M)+", opacity="+QString::number(Opacity)+"] coordinates {\n"+SData+"\n};\n";
    }

    VHQt_Result+="\\end{axis}\n";
    VHQt_Result+="\\end{tikzpicture}\n";

    VHQt_Result+="}\n";

    if (!TitleChart.isEmpty())
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{"+TitleChart+"}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{"+TitleChart+"}\n";
    }
    else
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{График}\\label{"+Label+"}\n\n";
        else
            VHQt_Result+="\\caption{График}\n\n";
    }
    if (ForNormalSize) VHQt_Result+="\\end{figure}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху;
     ColorBar - рисоватm с графиком колонку с градациями цветов или нет;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VHQt_Result = THQt_LatexShow3DPlot (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, VHQt_M, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, ColorBar,  ForNormalSize);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical и ForNormalSize.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху;
     ColorBar - рисовать с графиком колонку с градациями цветов или нет.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VHQt_Result = THQt_LatexShow3DPlot (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, VHQt_M, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, ColorBar,  true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical и ForNormalSize, ColorBar.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VHQt_Result = THQt_LatexShow3DPlot (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, VHQt_M, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, true,  true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical и ForNormalSize, ColorBar, ColorMap, Type.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;

    VHQt_Result = THQt_LatexShow3DPlot (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, VHQt_M, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, "mathcad", Plot3D_Surface, 1.0, AngleHorizontalNew, AngleVerticalNew, true,  true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    По сравнению с основным сайтом отсутствуют все дополнительные параметры.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;

    VHQt_Result = THQt_LatexShow3DPlot (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, VHQt_M, "График", "x", "y", "z", "Plot3D"+HQt_RandomString(8), "mathcad", Plot3D_Surface, 1.0, AngleHorizontalNew, AngleVerticalNew, true,  true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_LatexShow3DPlotPoints (T *VHQt_VectorX, T *VHQt_VectorY, T *VHQt_VectorZ,  int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде множества точек.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_VectorZ - указатель на вектор координат Z точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad.
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата
    int i;

    if (ForNormalSize)
        VHQt_Result+="% Вывод графика\n";
    else
        VHQt_Result+="% Вывод подграфика\n";

    //Обработаем текст подписи к осям.
    QString NameVectorXnew=NameVectorX,NameVectorYnew=NameVectorY, NameVectorZnew=NameVectorZ, subStr;

    subStr=",";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorZnew.contains(subStr))
        NameVectorZnew="$"+NameVectorZnew.replace(NameVectorZnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorZnew.contains(subStr))
        NameVectorZnew="$"+NameVectorZnew.replace(NameVectorZnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorXnew.contains(","))&&(!NameVectorXnew.contains(".")))
        if (!HQt_CheckRus(NameVectorXnew))
            NameVectorXnew="$"+NameVectorXnew+"$";

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    if ((!NameVectorZnew.contains(","))&&(!NameVectorZnew.contains(".")))
        if (!HQt_CheckRus(NameVectorZnew))
            NameVectorZnew="$"+NameVectorZnew+"$";

    NameVectorXnew=NameVectorXnew.replace(";","");
    NameVectorYnew=NameVectorYnew.replace(";","");
    NameVectorZnew=NameVectorZnew.replace(";","");

    NameVectorXnew=NameVectorXnew.replace("&","\\");
    NameVectorYnew=NameVectorYnew.replace("&","\\");
    NameVectorZnew=NameVectorZnew.replace("&","\\");

    //рисуем область графика и оси
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    VHQt_Result+="{\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="xlabel={"+NameVectorXnew+"},\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";
    VHQt_Result+="zlabel={"+NameVectorZnew+"},\n";
    if (ForNormalSize)
    {
        VHQt_Result+="height=12cm,\n";
        VHQt_Result+="width=12cm,\n";
    }
    else
    {
        VHQt_Result+="height=5.8cm,\n";
        VHQt_Result+="width=5.8cm,\n";
    }
    VHQt_Result+="z buffer=sort,\n";
    VHQt_Result+="colormap name="+ColorMap+",\n";
    if (!ForNormalSize) VHQt_Result+="label style={font=\\tiny},\n";
    if (ForNormalSize)  VHQt_Result+="label style={font=\\small},\n";
    if (!ForNormalSize) VHQt_Result+="tick label style={font=\\tiny},\n";
    VHQt_Result+="]\n\n";

    //соберем в массивы данные точек
    QString SData;
    for (i=0;i<VHQt_N;i++)
        SData+=" (" + QString::number(VHQt_VectorX[i]) + ", " + QString::number(VHQt_VectorY[i])+", " + QString::number(VHQt_VectorZ[i]) + ") \n";

    QString MarkSize;
    if (!ForNormalSize) MarkSize=",mark size=1pt";

    //Добавим график
    VHQt_Result+="\\addplot3[only marks,scatter"+MarkSize+"] coordinates {\n"+SData+"\n};\n";

    VHQt_Result+="\\end{axis}\n";
    VHQt_Result+="\\end{tikzpicture}\n";

    VHQt_Result+="}\n";

    if (!TitleChart.isEmpty())
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{"+TitleChart+"}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{"+TitleChart+"}\n";
    }
    else
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{График}\\label{"+Label+"}\n\n";
        else
            VHQt_Result+="\\caption{График}\n\n";
    }
    if (ForNormalSize) VHQt_Result+="\\end{figure}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlotPoints (T *VHQt_VectorX, T *VHQt_VectorY, T *VHQt_VectorZ,  int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде множества точек.
    В отличии от основной функции отсутствует параметр ColorMap.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_VectorZ - указатель на вектор координат Z точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShow3DPlotPoints (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, "mathcad", ForNormalSize);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlotPoints (T *VHQt_VectorX, T *VHQt_VectorY, T *VHQt_VectorZ,  int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде множества точек.
    В отличии от основной функции отсутствует параметры ColorMap и ForNormalSize.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_VectorZ - указатель на вектор координат Z точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShow3DPlotPoints (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, "mathcad", true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlotPoints (T *VHQt_VectorX, T *VHQt_VectorY, T *VHQt_VectorZ,  int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде множества точек.
    В отличии от основной функции отсутствует все дополнительные параметры.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_VectorZ - указатель на вектор координат Z точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShow3DPlotPoints (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, "График", "x", "y", "z", "Plot3D"+HQt_RandomString(8), "mathcad", true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается;
     MinZero - гистограмму начинать с нуля (true) или с минимального значения среди VHQt_Vector (false).
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата
    int i;

    //посчитаем границы изменения параметров

    T MinY=VHQt_Vector[0];
    for (i=1;i<VHQt_N;i++)
        if (VHQt_Vector[i]<MinY)
            MinY=VHQt_Vector[i];

    T MaxY=VHQt_Vector[0];
    for (i=1;i<VHQt_N;i++)
        if (VHQt_Vector[i]>MaxY)
            MaxY=VHQt_Vector[i];

    T LengthY=MaxY-MinY;

    if (ForNormalSize)
        VHQt_Result+="% Вывод графика\n";
    else
        VHQt_Result+="% Вывод подграфика\n";


    //Обработаем текст подписи к осям.
    QString NameVectorYnew=NameVectorY, subStr;

    subStr=",";
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    NameVectorYnew=NameVectorYnew.replace(";","");

    NameVectorYnew=NameVectorYnew.replace("&","\\");

    QString *NameVectorXnew=new QString[VHQt_N];
    for (i=0;i<VHQt_N;i++)
    {
        NameVectorXnew[i]=NameVectorX[i];

        subStr=",";
        if (NameVectorXnew[i].contains(subStr))
            NameVectorXnew[i]="$"+NameVectorXnew[i].replace(NameVectorXnew[i].indexOf(subStr), (subStr).size(), "$,");

        subStr=".";
        if (NameVectorXnew[i].contains(subStr))
            NameVectorXnew[i]="$"+NameVectorXnew[i].replace(NameVectorXnew[i].indexOf(subStr), (subStr).size(), "$,");

        if ((!NameVectorXnew[i].contains(","))&&(!NameVectorXnew[i].contains(".")))
            if (!HQt_CheckRus(NameVectorXnew[i]))
                NameVectorXnew[i]="$"+NameVectorXnew[i]+"$";

        NameVectorXnew[i]=NameVectorXnew[i].replace(";","");
        NameVectorXnew[i]=NameVectorXnew[i].replace("&","\\");
    }

    //рисуем область графика и оси
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    VHQt_Result+="{\n";
    VHQt_Result+="\\pgfplotsset{x axis line style={-},}\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="ybar,\n";
    VHQt_Result+="xmajorgrids=false,\n";
    VHQt_Result+="xminorgrids=false,\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";

    double MinD=10;
    if (!ForNormalSize) MinD=5;

    if ((MinY>=0)&&(MaxY>=0)&&(MinY!=MaxY))
    {

        VHQt_Result+="ymax="+QString::number(MaxY+LengthY/15.)+",\n";
        if (MinZero)
            VHQt_Result+="ymin=0,\n";
        else
            VHQt_Result+="ymin="+QString::number(MinY-LengthY/MinD)+",\n";
    }

    if ((MinY<0)&&(MaxY>=0))
    {

        VHQt_Result+="ymin="+QString::number(MinY-LengthY/MinD)+",\n";
        VHQt_Result+="ymax="+QString::number(MaxY+LengthY/15.)+",\n";
    }

    if ((MinY<0)&&(MaxY<0)&&(MinY!=MaxY))
    {

        VHQt_Result+="ymin="+QString::number(MinY-LengthY/MinD)+",\n";
        if (MinZero)
            VHQt_Result+="ymax=0,\n";
        else
            VHQt_Result+="ymax="+QString::number(MaxY+LengthY/15.)+",\n";
    }

    if ((MinY==MaxY)&&(MinY>=0))
    {
        if (MinZero)
        {
            VHQt_Result+="ymax="+QString::number(MaxY+(fabs(MinY)/MinD))+",\n";
            VHQt_Result+="ymin=0,\n";
        }
        else
        {
            VHQt_Result+="ymax="+QString::number(MaxY+(fabs(MinY)/MinD)/MinD)+",\n";
            VHQt_Result+="ymin="+QString::number(MinY-fabs(MinY)/MinD)+",\n";
        }
    }

    if ((MinY==MaxY)&&(MinY<0))
    {

        if (MinZero)
        {
            VHQt_Result+="ymax=0,\n";
            VHQt_Result+="ymin="+QString::number(MinY-(fabs(MinY)/MinD))+",\n";
        }
        else
        {
            VHQt_Result+="ymax="+QString::number(MaxY+fabs(MinY)/MinD)+",\n";
            VHQt_Result+="ymin="+QString::number(MinY-(fabs(MinY)/MinD)/MinD)+",\n";
        }
    }


    if (ForNormalSize)
    {
        VHQt_Result+="height=10cm,\n";
        VHQt_Result+="width=17cm,\n";
    }
    else
    {
        VHQt_Result+="height=5.8cm,\n";
        VHQt_Result+="width=8.5cm,\n";
    }

    VHQt_Result+="xticklabels={";
    for (i=0;i<VHQt_N-1;i++) VHQt_Result+=NameVectorXnew[i]+", ";
    VHQt_Result+=NameVectorXnew[VHQt_N-1]+"},\n";

    VHQt_Result+="xtick=data,\n";
    VHQt_Result+="minor x tick num=0,\n";
    VHQt_Result+="nodes near coords,\n";
    VHQt_Result+="nodes near coords align={vertical},\n";

    if (ForNormalSize)
    {
        if (VHQt_N>10)
            VHQt_Result+="every node near coord/.style={color=black,font=\\tiny},\n";
        else
            VHQt_Result+="every node near coord/.style={color=black},\n";
    }
    else
        VHQt_Result+="every node near coord/.style={color=black,font=\\tiny},\n";

    QString BarWidth;
    QString TextWidth;
    QString XLimits;
    if (ForNormalSize)
    {
        BarWidth="bar width=2.0cm,\n";
        TextWidth="x tick label style={font=\\small,text width=1.7cm,align=center},\n";
        XLimits="enlarge x limits=.15,\n";

        if (VHQt_N==1)
        {
            BarWidth="bar width=3.0cm,\n";
            TextWidth="x tick label style={font=\\small,text width=15cm,align=center},\n";
        }

        if (VHQt_N==2)
        {
            BarWidth="bar width=3.0cm,\n";
            TextWidth="x tick label style={font=\\small,text width=7cm,align=center},\n";
            XLimits="enlarge x limits=.4,\n";
        }

        if (VHQt_N==3)
        {
            BarWidth="bar width=2.5cm,\n";
            TextWidth="x tick label style={font=\\small,text width=4cm,align=center},\n";
        }

        if (VHQt_N==4)
        {
            BarWidth="bar width=2cm,\n";
            TextWidth="x tick label style={font=\\small,text width=1.9cm,align=center},\n";
        }

        if (VHQt_N==6)
        {
            BarWidth="bar width=2cm,\n";
            TextWidth="x tick label style={font=\\small,text width=1.7cm,align=center},\n";
        }

        if (VHQt_N==7)
        {
            BarWidth="bar width=1.8cm,\n";
            TextWidth="x tick label style={font=\\small,text width=1.5cm,align=center},\n";
        }

        if (VHQt_N==8)
        {
            BarWidth="bar width=1.5cm,\n";
            TextWidth="x tick label style={font=\\tiny,text width=1.4cm,align=center},\n";
        }

        if (VHQt_N==9)
        {
            BarWidth="bar width=1.2cm,\n";
            TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
        }

        if (VHQt_N==10)
        {
            BarWidth="bar width=1.0cm,\n";
            TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
        }

        if (VHQt_N==11)
        {
            BarWidth="bar width=0.8cm,\n";
        }

        if (VHQt_N>=11)
        {
            TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
            XLimits="enlarge x limits=.05,\n";
        }

        if (VHQt_N==12)
        {
            BarWidth="bar width=0.75cm,\n";
        }

        if (VHQt_N==13)
        {
            BarWidth="bar width=0.65cm,\n";
        }

        if (VHQt_N>=14)
        {
            BarWidth="";
        }


    }
    else
    {
        BarWidth="bar width=0.8cm,\n";
        TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
        XLimits="enlarge x limits=.15,\n";

        if (VHQt_N==1)
        {
            BarWidth="bar width=1.0cm,\n";
            TextWidth="x tick label style={font=\\tiny,text width=8cm,align=center},\n";
        }

        if (VHQt_N==2)
        {
            BarWidth="bar width=1.0cm,\n";
            TextWidth="x tick label style={font=\\small,text width=4cm,align=center},\n";
            XLimits="enlarge x limits=.4,\n";
        }

        if (VHQt_N==8)
        {
            BarWidth="bar width=0.6cm,\n";
        }

        if (VHQt_N>=9)
        {
            BarWidth="";
        }

        if (VHQt_N>=11)
        {
            XLimits="enlarge x limits=.05,\n";
        }
    }
    VHQt_Result+=BarWidth;
    VHQt_Result+=TextWidth;
    VHQt_Result+=XLimits;


    VHQt_Result+="]\n\n";


    //соберем в массивы данные точек
    QString SData;
    for (i=0;i<VHQt_N;i++)
        SData+=" ("+QString::number(i)+", "+QString::number(VHQt_Vector[i])+") \n";

    //добавим график
    VHQt_Result+="\\addplot[color=plotmain,fill] coordinates {\n";
    VHQt_Result+=SData;
    VHQt_Result+="};\n";

    VHQt_Result+="\\end{axis}\n";
    VHQt_Result+="\\end{tikzpicture}\n";

    VHQt_Result+="}\n";

    if (!TitleChart.isEmpty())
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{"+TitleChart+"}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{"+TitleChart+"}\n";
    }
    else
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{График}\\label{"+Label+"}\n\n";
        else
            VHQt_Result+="\\caption{График}\n\n";
    }
    if (ForNormalSize) VHQt_Result+="\\end{figure}\n\n";

    delete [] NameVectorXnew;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается отсутствием параметра MinZero.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, TitleChart, NameVectorX, NameVectorY, Label, ForNormalSize, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается отсутствием параметра MinZero и ForNormalSize.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, TitleChart, NameVectorX, NameVectorY, Label, true, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается отсутствием параметра MinZero и ForNormalSize и всех текстовых параметров.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    QString *NameVectorX = new QString[VHQt_N];
    for (int i=0;i<VHQt_N;i++) NameVectorX[i] = "№ " + QString::number(i+1);

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, "График", NameVectorX, "y",  "Chart"+HQt_RandomString(8), true, false);

    delete [] NameVectorX;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается тем, что список наименований хранится в QStringList, а не массиве.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается;
     MinZero - гистограмму начинать с нуля (true) или с минимального значения среди VHQt_Vector (false).
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    QString *NameVectorXArray = new QString [VHQt_N];
    for (int i=0;i<VHQt_N;i++) NameVectorXArray[i]=NameVectorX.at(i);

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, TitleChart, NameVectorXArray, NameVectorY, Label, ForNormalSize, MinZero);

    delete [] NameVectorXArray;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается тем, что список наименований хранится в QStringList, а не массиве. Еще нет переменой MinZero.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    QString *NameVectorXArray = new QString [VHQt_N];
    for (int i=0;i<VHQt_N;i++) NameVectorXArray[i]=NameVectorX.at(i);

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, TitleChart, NameVectorXArray, NameVectorY, Label, ForNormalSize, true);

    delete [] NameVectorXArray;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается тем, что список наименований хранится в QStringList, а не массиве. Еще нет переменых MinZero и ForNormalSize.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    QString *NameVectorXArray = new QString [VHQt_N];
    for (int i=0;i<VHQt_N;i++) NameVectorXArray[i]=NameVectorX.at(i);

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, TitleChart, NameVectorXArray, NameVectorY, Label, true, true);

    delete [] NameVectorXArray;

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_LatexShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - название первого графика (для легенды);
     Label - label для графика
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j;

    //посчитаем границы изменения параметров
    T MinX=VHQt_VectorX[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorX[i]<MinX)
            MinX=VHQt_VectorX[i];

    T MinY=VHQt_VectorY[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY[i]<MinY)
            MinY=VHQt_VectorY[i];

    T MaxX=VHQt_VectorX[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorX[i]>MaxX)
            MaxX=VHQt_VectorX[i];

    T MaxY=VHQt_VectorY[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY[i]>MaxY)
            MaxY=VHQt_VectorY[i];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/15.;
    T LeftYBoundingBox=MinY-LengthY/15.;
    T RightXBoundingBox=MaxX+LengthX/15.;
    T RightYBoundingBox=MaxY+LengthY/15.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;VHQt_Result+="\n";}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;VHQt_Result+="\n";}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    if (ForNormalSize)
        VHQt_Result+="% Вывод графика\n";
    else
        VHQt_Result+="% Вывод подграфика\n";

    //Если график маленький, то дополнительные настройки:
    if (!ForNormalSize)
    {
        VHQt_Result+="{\\pgfplotsset{every axis legend/.append style={at={(0.5,-0.25)},anchor=north,legend cell align=left},}\n";
    }

    //Обработаем текст подписи к осям.
    QString NameVectorXnew=NameVectorX,NameVectorYnew=NameVectorY, subStr;

    subStr=",";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorXnew.contains(","))&&(!NameVectorXnew.contains(".")))
        if (!HQt_CheckRus(NameVectorXnew))
            NameVectorXnew="$"+NameVectorXnew+"$";

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    NameVectorXnew=NameVectorXnew.replace(";","");
    NameVectorYnew=NameVectorYnew.replace(";","");

    NameVectorXnew=NameVectorXnew.replace("&","\\");
    NameVectorYnew=NameVectorYnew.replace("&","\\");

    //рисуем область графика и оси
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="xlabel={"+NameVectorXnew+"},\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";
    //if (ForNormalSize)
    VHQt_Result+="xmax="+SRightXBoundingBox+",\n";
    //if (ForNormalSize)
    VHQt_Result+="ymax="+SRightYBoundingBox+",\n";
    if (ForNormalSize)
    {
        VHQt_Result+="height=10cm,\n";
        VHQt_Result+="width=17cm,\n";
    }
    else
    {
        VHQt_Result+="height=5.8cm,\n";
        VHQt_Result+="width=8.5cm,\n";
    }
    VHQt_Result+="]\n\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VHQt_VectorX=new T[VHQt_N];
    T *Temp_VHQt_VectorY=new T[VHQt_N];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_VectorX[i]=VHQt_VectorX[i];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_VectorY[i]=VHQt_VectorY[i];

    //отсортируем массивы
    for(i=VHQt_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX[j]>Temp_VHQt_VectorX[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX[j+1];
                Temp_VHQt_VectorX[j+1]=Temp_VHQt_VectorX[j];
                Temp_VHQt_VectorX[j]=x;

                x=Temp_VHQt_VectorY[j+1];
                Temp_VHQt_VectorY[j+1]=Temp_VHQt_VectorY[j];
                Temp_VHQt_VectorY[j]=x;
            }

    //соберем в массивы данные точек
    QString SData;
    for (i=0;i<VHQt_N;i++)
        SData+=" ("+QString::number(Temp_VHQt_VectorX[i])+", "+QString::number(Temp_VHQt_VectorY[i])+") \n";

    if ((ShowArea)&&((ShowPoints)||(ShowLine)))
    {
        //нарисуем закрашенную область
        VHQt_Result+="\\addplot[color=plotmain, draw=none,fill, fill opacity = 0.5,forget plot] coordinates {\n";
        VHQt_Result+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
        VHQt_Result+=SData;
        VHQt_Result+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
        VHQt_Result+="};\n\n";
    }

    if ((ShowArea)&&(!ShowPoints)&&(!ShowLine))
    {
        //нарисуем закрашенную область
        VHQt_Result+="\\addplot[color=plotmain, draw=none,fill, fill opacity = 0.5] coordinates {\n";
        VHQt_Result+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
        VHQt_Result+=SData;
        VHQt_Result+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
        VHQt_Result+="};\n";
        VHQt_Result+="\\addlegendentry{"+NameLine+"};\n\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        QString MarkSize;
        if (VHQt_N>100) MarkSize=",mark size=1.5pt";

        //Нарисуем график
        if (RedLine==false)
            VHQt_Result+="\\addplot[color=plotmain, mark=*,mark options={plotmain,opacity = 1, fill=white,thick}"+MarkSize+",very thick] coordinates {\n";
        else
            VHQt_Result+="\\addplot[color=red, mark=*,mark options={red,opacity = 1, fill=white,very thin}"+MarkSize+",very thin] coordinates {\n";
        VHQt_Result+=SData;
        VHQt_Result+="};\n";
        VHQt_Result+="\\addlegendentry{"+NameLine+"};\n\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        QString MarkSize;
        if (VHQt_N>100) MarkSize=",mark size=1.5pt";

        //Нарисуем график
        if (RedLine==false)
            VHQt_Result+="\\addplot[color=plotmain, mark=*,mark options={plotmain,opacity = 1, fill=white,thick}"+MarkSize+",only marks] coordinates {\n";
        else
            VHQt_Result+="\\addplot[color=red, mark=*,mark options={red,opacity = 1, fill=white,very thin}"+MarkSize+",only marks] coordinates {\n";
        VHQt_Result+=SData;
        VHQt_Result+="};\n";
        VHQt_Result+="\\addlegendentry{"+NameLine+"};\n\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        if (RedLine==false)
            VHQt_Result+="\\addplot[color=plotmain, no markers,very thick] coordinates {\n";
        else
            VHQt_Result+="\\addplot[color=red, no markers,very thin] coordinates {\n";
        VHQt_Result+=SData;
        VHQt_Result+="};\n";
        VHQt_Result+="\\addlegendentry{"+NameLine+"};\n\n";
    }

    if (ShowSpecPoints)
    {
        //Определим что писать в виде min_x и др.
        QString LabelX="Ox",LabelY="Oy";
        if (NameVectorX.length()<100) LabelX=NameVectorX;else LabelX="Ox";
        if (NameVectorY.length()<100) LabelY=NameVectorY;else LabelY="Oy";

        if (LabelX.contains(",")) LabelX=LabelX.mid(0,LabelX.indexOf(","));
        if (LabelY.contains(",")) LabelY=LabelY.mid(0,LabelY.indexOf(","));

        if (LabelX.contains(".")) LabelX=LabelX.mid(0,LabelX.indexOf("."));
        if (LabelY.contains(".")) LabelY=LabelY.mid(0,LabelY.indexOf("."));

        if (HQt_CheckRus(LabelX)) LabelX="Ox";
        if (HQt_CheckRus(LabelY)) LabelY="Oy";

        LabelX=LabelX.replace(";","");
        LabelY=LabelY.replace(";","");

        LabelX=LabelX.replace("&","\\");
        LabelY=LabelY.replace("&","\\");

        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\min_{"+LabelX+"}="+QString::number(MinX)+"; \\min_{"+LabelY+"}="+QString::number(MinY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="]\n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MinY)+")};\n";

        //Максимальная по Y
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelY+"} = "+QString::number(MaxY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MaxY)+")};\n";

        //Максимальная по X
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelX+"} = "+QString::number(MaxX)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=north west,font=\\tiny, rotate=90},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MaxX)+","+QString::number(MinY)+")};\n";
    }

    VHQt_Result+="\\end{axis}\n";
    VHQt_Result+="\\end{tikzpicture}\n";

    if (!ForNormalSize)
    {
        VHQt_Result+="}\n";
    }

    if (!TitleChart.isEmpty())
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{"+TitleChart+"}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{"+TitleChart+"}\n";
    }
    else
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{График}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{График}\n";
    }
    if (ForNormalSize) VHQt_Result+="\\end{figure}\n";

    delete [] Temp_VHQt_VectorX;
    delete [] Temp_VHQt_VectorY;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.
    По сравнению с основной функцией тут отсутствует параметр ForNormalSize.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - название первого графика (для легенды);
     Label - label для графика
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowChartOfLine (VHQt_VectorX, VHQt_VectorY, VHQt_N, TitleChart, NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, RedLine, true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.
    По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - название первого графика (для легенды);
     Label - label для графика
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowChartOfLine (VHQt_VectorX, VHQt_VectorY, VHQt_N, TitleChart, NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, false, true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.
    По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - название первого графика (для легенды);
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowChartOfLine (VHQt_VectorX, VHQt_VectorY, VHQt_N, TitleChart, NameVectorX, NameVectorY, NameLine, Label, true, true, true, true, false, true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.
    По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные, а также все переменные названий.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowChartOfLine (VHQt_VectorX, VHQt_VectorY, VHQt_N, "", "x", "y", "Линия", "Chart"+HQt_RandomString(8), true, true, true, true, false, true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M-1 (так как первый столбец - это X значения);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается;
     GrayStyle - серый стиль графиков;
     SolidStyle - линии делать сплошными или разными по типу (точками, тире и др.);
     CircleStyle - точки все делать кругляшками или нет.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j,k;

    //цвета
    QString *Color=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) Color[j]="97BBCD";

    QString *ColorArea=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) ColorArea[j]="plot1";

    QString *TypeLine=new QString [VHQt_M-1];
    //for (j=0;j<VHQt_M-1;j++) TypeLine[j]="";

    QString *FaceOfLine=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) FaceOfLine[j]="*";

    QString Opacity="0.5";

    QString Legend;
    if (VHQt_M-1>3) Legend="legend columns=2,\n";

    if (GrayStyle)
    {
        if (VHQt_M-1==2)//если два графика
        {
            Color[1]="CCCCCC";
        }
        if (VHQt_M-1==3)//если три графика
        {
            Color[0]="799BAC";
            Color[1]="97BBCD";
            Color[2]="CCCCCC";
        }
        if (VHQt_M-1==4)//если 4 графика
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="CCCCCC";
        }
        if (VHQt_M-1==5)//если 5 графика
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="ADC2CD";
            Color[4]="CCCCCC";
        }
        if (VHQt_M-1==6)//если 6 графика
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="ADC2CD";
            Color[4]="BEC7CD";
            Color[5]="CCCCCC";
        }
        if (VHQt_M-1==7)//если 7 графика
        {
            Color[0]="6A8795";
            Color[1]="799BAC";
            Color[2]="83A6B7";
            Color[3]="97BBCD";
            Color[4]="ADC2CD";
            Color[5]="BEC7CD";
            Color[6]="CCCCCC";
        }
        if (VHQt_M-1==8)//если 8 графика
        {
            Color[0]="6A8795";
            Color[1]="799BAC";
            Color[2]="83A6B7";
            Color[3]="8EB1C3";
            Color[4]="97BBCD";
            Color[5]="ADC2CD";
            Color[6]="BEC7CD";
            Color[7]="CCCCCC";
        }
        if (VHQt_M-1==9)//если 9 графика
        {
            Color[0]="6a8795";
            Color[1]="799BAC";
            Color[2]="83A6B7";
            Color[3]="8EB1C3";
            Color[4]="97BBCD";
            Color[5]="ADC2CD";
            Color[6]="B6C5CD";
            Color[7]="BEC7CD";
            Color[8]="CCCCCC";
        }
        if (VHQt_M-1>9)//если больше 9 графика
        {
            double position;
            for (j=0;j<VHQt_M-1;j++)
            {
                position=j/double(VHQt_M-1);
                Color[j]=(THQt_ColorFromGradient(position,"#6A8795","#CCCCCC")).mid(1).toUpper();//"537c90";
            }

            Opacity="0.1";
        }

        for (j=0;j<VHQt_M-1;j++) ColorArea[j]="plot"+QString::number(j+1);
    }
    else
    {
        double position;
        for (j=0;j<VHQt_M-1;j++)
        {
            position=j/double(VHQt_M-1);
            Color[j]=(THQt_AlphaBlendingColorToColor(0.2,THQt_GiveRainbowColorRGB(position),"#000000")).mid(1).toUpper();//"537c90";
        }

        Opacity="0.3";

        for (j=0;j<VHQt_M-1;j++) ColorArea[j]="plotmain";

        if (VHQt_M-1==1)
        {
            Color[0]="97BBCD";
            ColorArea[0]="plotmain";

            Opacity="0.5";
        }

        if (VHQt_M-1==2)
        {
            Color[0]="97BBCD";
            ColorArea[0]="plotmain";

            Color[1]="FF0000";
            ColorArea[1]="plotsecond";

            Opacity="0.5";
        }

        if (VHQt_M-1==3)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E06C65";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==4)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E7CC4C";
            Color[3]="E06C65";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==5)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E7CC4C";
            Color[3]="E06C65";
            Color[4]="9D50C8";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==6)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="B5D24E";
            Color[3]="E7CC4C";
            Color[4]="E06C65";
            Color[5]="9D50C8";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==7)
        {
            Color[0]="6250C9";
            Color[1]="97BBCD";
            Color[2]="4AC955";
            Color[3]="B5D24E";
            Color[4]="E7CC4C";
            Color[5]="E06C65";
            Color[6]="9D50C8";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==8)
        {
            Color[0]="6250C9";
            Color[1]="97BBCD";
            Color[2]="4AC955";
            Color[3]="B5D24E";
            Color[4]="E7CC4C";
            Color[5]="E06C65";
            Color[6]="9D50C8";
            Color[7]="C64F8F";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==9)
        {
            Color[0]="6250C9";
            Color[1]="97BBCD";
            Color[2]="4AC955";
            Color[3]="B5D24E";
            Color[4]="E7CC4C";
            Color[5]="E9AC4C";
            Color[6]="E06C65";
            Color[7]="9D50C8";
            Color[8]="C64F8F";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
    }

    for (j=0;j<VHQt_M-1;j++)
    {
        if (j%6==1) TypeLine[j]=",dashed";
        if (j%6==2) TypeLine[j]=",dotted";
        if (j%6==3) TypeLine[j]=",dashdotted";
        if (j%6==4) TypeLine[j]=",dashdotdotted";
        if (j%6==5) TypeLine[j]=",loosely dotted";
    }

    for (j=0;j<VHQt_M-1;j++)
    {
        if (j%5==1) FaceOfLine[j]="square*";
        if (j%5==2) FaceOfLine[j]="triangle*";
        if (j%5==3) FaceOfLine[j]="diamond*";
        if (j%5==4) FaceOfLine[j]="triangle*, every mark/.append style={rotate=90}";
    }

    if (CircleStyle) for (j=0;j<VHQt_M-1;j++) FaceOfLine[j]="*";
    if (SolidStyle)  for (j=0;j<VHQt_M-1;j++) TypeLine[j]="";

    //посчитаем гарницы изменения параметров
    T MinX=VHQt_MatrixXY[0][0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_MatrixXY[i][0]<MinX)
            MinX=VHQt_MatrixXY[i][0];

    T MaxX=VHQt_MatrixXY[0][0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_MatrixXY[i][0]>MaxX)
            MaxX=VHQt_MatrixXY[i][0];

    T MinY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M-1;j++)
        for (int i=0;i<VHQt_N;i++)
            if (VHQt_MatrixXY[i][j+1]<MinY)
                MinY=VHQt_MatrixXY[i][j+1];

    T MaxY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M-1;j++)
        for (int i=0;i<VHQt_N;i++)
            if (VHQt_MatrixXY[i][j+1]>MaxY)
                MaxY=VHQt_MatrixXY[i][j+1];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/15.;
    T LeftYBoundingBox=MinY-LengthY/15.;
    T RightXBoundingBox=MaxX+LengthX/15.;
    T RightYBoundingBox=MaxY+LengthY/15.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    if (ForNormalSize)
        VHQt_Result+="% Вывод графика\n{\n";
    else
        VHQt_Result+="% Вывод подграфика\n{\n";

    //Если график маленький, то дополнительные настройки:
    if (!ForNormalSize)
    {
        VHQt_Result+="\\pgfplotsset{every axis legend/.append style={at={(0.5,-0.25)},anchor=north,legend cell align=left},}\n";
    }

    //Обработаем текст подписи к осям.
    QString NameVectorXnew=NameVectorX,NameVectorYnew=NameVectorY, subStr;

    subStr=",";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorXnew.contains(","))&&(!NameVectorXnew.contains(".")))
        if (!HQt_CheckRus(NameVectorXnew))
            NameVectorXnew="$"+NameVectorXnew+"$";

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    NameVectorXnew=NameVectorXnew.replace(";","");
    NameVectorYnew=NameVectorYnew.replace(";","");

    NameVectorXnew=NameVectorXnew.replace("&","\\");
    NameVectorYnew=NameVectorYnew.replace("&","\\");

    //рисуем область графика и оси
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="xlabel={"+NameVectorXnew+"},\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";
    //if (ForNormalSize)
    VHQt_Result+="xmax="+SRightXBoundingBox+",\n";
    //if (ForNormalSize)
    VHQt_Result+="ymax="+SRightYBoundingBox+",\n";
    if (ForNormalSize)
    {
        QString HeightPlot="10cm";

        if (VHQt_M-1>10) HeightPlot="9cm";

        if (VHQt_M-1>19) HeightPlot="8cm";

        if (VHQt_M-1>25) HeightPlot="12cm";

        if (VHQt_M-1>35) HeightPlot="10cm";

        VHQt_Result+="height="+HeightPlot+",\n";
        VHQt_Result+="width=17cm,\n";
    }
    else
    {
        QString HeightPlot="5.8cm";

        if (VHQt_M-1>10) HeightPlot="4.8cm";

        if (VHQt_M-1>17) HeightPlot="6.8cm";


        VHQt_Result+="height="+HeightPlot+",\n";
        VHQt_Result+="width=8.5cm,\n";
    }
    VHQt_Result+=Legend;
    VHQt_Result+="]\n\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T **Temp_VHQt_MatrixXY;
    Temp_VHQt_MatrixXY=new double*[VHQt_N];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_MatrixXY[i]=new double[VHQt_M];
    for (i=0;i<VHQt_N;i++)
        for (j=0;j<VHQt_M;j++)
            Temp_VHQt_MatrixXY[i][j]=VHQt_MatrixXY[i][j];

    //отсортируем массивы
    for(i=VHQt_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_MatrixXY[j][0]>Temp_VHQt_MatrixXY[j+1][0])
            {
                for (k=0;k<VHQt_M;k++)
                {
                    T x;
                    x=Temp_VHQt_MatrixXY[j+1][k];
                    Temp_VHQt_MatrixXY[j+1][k]=Temp_VHQt_MatrixXY[j][k];
                    Temp_VHQt_MatrixXY[j][k]=x;
                }
            }

    QString *SData = new QString[VHQt_M-1];

    QString *Plot = new QString[VHQt_M-1];

    for (j=0;j<VHQt_M-1;j++)
    {
        for (i=0;i<VHQt_N-1;i++)
            SData[j]+=" ("+QString::number(Temp_VHQt_MatrixXY[i][0])+", "+QString::number(Temp_VHQt_MatrixXY[i][j+1])+") \n";
        SData[j]+=" ("+QString::number(Temp_VHQt_MatrixXY[VHQt_N-1][0])+", "+QString::number(Temp_VHQt_MatrixXY[VHQt_N-1][j+1])+") \n";
    }

    QString MarkSize;
    if (VHQt_N>100) MarkSize=",mark size=1.5pt";

    if ((ShowArea)&&((ShowPoints)||(ShowLine)))
    {
        //нарисуем закрашенную область
        for (j=0;j<VHQt_M-1;j++)
        {
            Plot[j]+="\\addplot[color="+ColorArea[j]+", draw=none,fill, fill opacity = "+Opacity+",forget plot] coordinates {\n";
            Plot[j]+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
            Plot[j]+=SData[j];
            Plot[j]+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
            Plot[j]+="};\n\n";
        }
    }

    if ((ShowArea)&&(!ShowPoints)&&(!ShowLine))
    {
        //нарисуем закрашенную область
        for (j=0;j<VHQt_M-1;j++)
        {
            Plot[j]+="\\addplot[color="+ColorArea[j]+", draw=none,fill, fill opacity = "+Opacity+"] coordinates {\n";
            Plot[j]+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
            Plot[j]+=SData[j];
            Plot[j]+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        for (j=0;j<VHQt_M-1;j++)
        {
            //Нарисуем график
            Plot[j]+="\\addplot[color=plot"+QString::number(j+1)+",mark options={plot"+QString::number(j+1)+",opacity = 1, fill=white,thick,solid}"+MarkSize+",very thick"+TypeLine[j]+", mark="+FaceOfLine[j]+"] coordinates {\n";
            Plot[j]+=SData[j];
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки
        for (j=0;j<VHQt_M-1;j++)
        {
            Plot[j]+="\\addplot[color=plot"+QString::number(j+1)+",mark options={plot"+QString::number(j+1)+",opacity = 1, fill=white,thick}"+MarkSize+",only marks, mark="+FaceOfLine[j]+"] coordinates {\n";
            Plot[j]+=SData[j];
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию
        for (j=0;j<VHQt_M-1;j++)
        {
            Plot[j]+="\\addplot[color=plot"+QString::number(j+1)+", no markers,very thick"+TypeLine[j]+"] coordinates {\n";
            Plot[j]+=SData[j];
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    //Цвета соберем
    for (j=0;j<VHQt_M-1;j++)
    {
        VHQt_Result+="\\definecolor{plot"+QString::number(j+1)+"}{HTML}{"+Color[j]+"}\n";
    }
    VHQt_Result+="\n";

    //собираем общий график
    for (j=0;j<VHQt_M-1;j++)
        VHQt_Result+=Plot[VHQt_M-1-j-1];

    if (ShowSpecPoints)
    {
        //Определим что писать в виде min_x и др.
        QString LabelX="Ox",LabelY="Oy";
        if (NameVectorX.length()<100) LabelX=NameVectorX;else LabelX="Ox";
        if (NameVectorY.length()<100) LabelY=NameVectorY;else LabelY="Oy";

        if (LabelX.contains(",")) LabelX=LabelX.mid(0,LabelX.indexOf(","));
        if (LabelY.contains(",")) LabelY=LabelY.mid(0,LabelY.indexOf(","));

        if (LabelX.contains(".")) LabelX=LabelX.mid(0,LabelX.indexOf("."));
        if (LabelY.contains(".")) LabelY=LabelY.mid(0,LabelY.indexOf("."));

        if (HQt_CheckRus(LabelX)) LabelX="Ox";
        if (HQt_CheckRus(LabelY)) LabelY="Oy";

        LabelX=LabelX.replace(";","");
        LabelY=LabelY.replace(";","");

        LabelX=LabelX.replace("&","\\");
        LabelY=LabelY.replace("&","\\");

        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\min_{"+LabelX+"}="+QString::number(MinX)+"; \\min_{"+LabelY+"}="+QString::number(MinY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="]\n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MinY)+")};\n";

        //Максимальная по Y
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelY+"} = "+QString::number(MaxY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MaxY)+")};\n";

        //Максимальная по X
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelX+"} = "+QString::number(MaxX)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=north west,font=\\tiny, rotate=90},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MaxX)+","+QString::number(MinY)+")};\n";
    }

    VHQt_Result+="\\end{axis}\n";
    VHQt_Result+="\\end{tikzpicture}\n";

    if (!TitleChart.isEmpty())
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{"+TitleChart+"}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{"+TitleChart+"}\n";
    }
    else
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{График}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{График}\n";
    }
    if (ForNormalSize) VHQt_Result+="\\end{figure}\n";

    VHQt_Result+="}\n\n";

    delete [] SData;
    delete [] Plot;
    delete [] Color;
    delete [] ColorArea;
    delete [] TypeLine;
    delete [] FaceOfLine;

    for (i=0;i<VHQt_N;i++) delete [] Temp_VHQt_MatrixXY[i];
    delete [] Temp_VHQt_MatrixXY;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    По сравнению с основной функцией отсутствуют параметры GrayStyle, SolidStyle, CircleStyle.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M-1 (так как первый столбец - это X значения);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N, VHQt_M, TitleChart, NameVectorX,  NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints,  ForNormalSize,  false,  false,  false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    По сравнению с основной функцией отсутствуют параметры GrayStyle, SolidStyle, CircleStyle, ForNormalSize.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M-1 (так как первый столбец - это X значения);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N, VHQt_M, TitleChart, NameVectorX,  NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints,  true,  false,  false,  false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    По сравнению с основной функцией отсутствуют все булевские переменные.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M-1 (так как первый столбец - это X значения);
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N, VHQt_M, TitleChart, NameVectorX,  NameVectorY, NameLine, Label, true, true, false, true,  true,  false,  false,  false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    По сравнению с основной функцией отсутствуют все булевские переменные и текстовые. Все устанавливается по умолчанию.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков).
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    QString *NameLine;

    NameLine = new QString[VHQt_M-1];

    for (int i=0;i<VHQt_M-1;i++) NameLine[i]="График "+QString::number(i+1);

    VHQt_Result = THQt_LatexShowChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N, VHQt_M, "", "x", "y", NameLine, "Chart"+HQt_RandomString(8), true, true, false, true,  true,  false,  false,  false);

    delete [] NameLine;

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки;
 ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается;
 GrayStyle - серый стиль графиков;
 SolidStyle - линии делать сплошными или разными по типу (точками, тире и др.);
 CircleStyle - точки все делать кругляшками или нет.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VHQt_Result;//переменная итогового результата
    int i,j,k;

    //цвета
    QString *Color=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) Color[j]="97BBCD";

    QString *ColorArea=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) ColorArea[j]="plot1";

    QString *TypeLine=new QString [VHQt_M/2];
    //for (j=0;j<VHQt_M/2;j++) TypeLine[j]="";

    QString *FaceOfLine=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) FaceOfLine[j]="*";

    QString Opacity="0.5";

    QString Legend;
    if (VHQt_M/2>3) Legend="legend columns=2,\n";

    if (GrayStyle)
    {
        if (VHQt_M/2==2)//если два графика
        {
            Color[1]="CCCCCC";
        }
        if (VHQt_M/2==3)//если три графика и показаны закрашенные области
        {
            Color[0]="799BAC";
            Color[1]="97BBCD";
            Color[2]="CCCCCC";
        }
        if (VHQt_M/2==4)//если 4 графика и показаны закрашенные области
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="CCCCCC";
        }
        if (VHQt_M/2==5)//если 5 графика и показаны закрашенные области
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="ADC2CD";
            Color[4]="CCCCCC";
        }
        if (VHQt_M/2==6)//если 6 графика и показаны закрашенные области
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="ADC2CD";
            Color[4]="BEC7CD";
            Color[5]="CCCCCC";
        }
        if (VHQt_M/2==7)//если 7 графика и показаны закрашенные области
        {
            Color[0]="6A8795";
            Color[1]="799BAC";
            Color[2]="83A6B7";
            Color[3]="97BBCD";
            Color[4]="ADC2CD";
            Color[5]="BEC7CD";
            Color[6]="CCCCCC";
        }
        if (VHQt_M/2==8)//если 8 графика и показаны закрашенные области
        {
            Color[0]="6A8795";
            Color[1]="799BAC";
            Color[2]="83A6B7";
            Color[3]="8EB1C3";
            Color[4]="97BBCD";
            Color[5]="ADC2CD";
            Color[6]="BEC7CD";
            Color[7]="CCCCCC";
        }
        if (VHQt_M/2==9)//если 9 графика и показаны закрашенные области
        {
            Color[0]="6a8795";
            Color[1]="799BAC";
            Color[2]="83A6B7";
            Color[3]="8EB1C3";
            Color[4]="97BBCD";
            Color[5]="ADC2CD";
            Color[6]="B6C5CD";
            Color[7]="BEC7CD";
            Color[8]="CCCCCC";
        }
        if (VHQt_M/2>9)//если больше 9 графика и показаны закрашенные области
        {
            double position;
            for (j=0;j<VHQt_M/2;j++)
            {
                position=j/double(VHQt_M/2);
                Color[j]=(THQt_ColorFromGradient(position,"#6A8795","#CCCCCC")).mid(1).toUpper();//"537c90";
            }

            Opacity="0.1";
        }

        for (j=0;j<VHQt_M/2;j++) ColorArea[j]="plot"+QString::number(j+1);
    }
    else
    {
        double position;
        for (j=0;j<VHQt_M/2;j++)
        {
            position=j/double(VHQt_M/2);
            Color[j]=(THQt_AlphaBlendingColorToColor(0.2,THQt_GiveRainbowColorRGB(position),"#000000")).mid(1).toUpper();//"537c90";
        }

        Opacity="0.3";

        for (j=0;j<VHQt_M/2;j++) ColorArea[j]="plotmain";

        if (VHQt_M/2==1)
        {
            Color[0]="97BBCD";
            ColorArea[0]="plotmain";

            Opacity="0.5";
        }

        if (VHQt_M/2==2)
        {
            Color[0]="97BBCD";
            ColorArea[0]="plotmain";

            Color[1]="FF0000";
            ColorArea[1]="plotsecond";

            Opacity="0.5";
        }

        if (VHQt_M/2==3)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E06C65";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M/2==4)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E7CC4C";
            Color[3]="E06C65";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M/2==5)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E7CC4C";
            Color[3]="E06C65";
            Color[4]="9D50C8";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M/2==6)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="B5D24E";
            Color[3]="E7CC4C";
            Color[4]="E06C65";
            Color[5]="9D50C8";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M/2==7)
        {
            Color[0]="6250C9";
            Color[1]="97BBCD";
            Color[2]="4AC955";
            Color[3]="B5D24E";
            Color[4]="E7CC4C";
            Color[5]="E06C65";
            Color[6]="9D50C8";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M/2==8)
        {
            Color[0]="6250C9";
            Color[1]="97BBCD";
            Color[2]="4AC955";
            Color[3]="B5D24E";
            Color[4]="E7CC4C";
            Color[5]="E06C65";
            Color[6]="9D50C8";
            Color[7]="C64F8F";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M/2==9)
        {
            Color[0]="6250C9";
            Color[1]="97BBCD";
            Color[2]="4AC955";
            Color[3]="B5D24E";
            Color[4]="E7CC4C";
            Color[5]="E9AC4C";
            Color[6]="E06C65";
            Color[7]="9D50C8";
            Color[8]="C64F8F";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
    }

    for (j=0;j<VHQt_M/2;j++)
    {
        if (j%6==1) TypeLine[j]=",dashed";
        if (j%6==2) TypeLine[j]=",dotted";
        if (j%6==3) TypeLine[j]=",dashdotted";
        if (j%6==4) TypeLine[j]=",dashdotdotted";
        if (j%6==5) TypeLine[j]=",loosely dotted";
    }

    for (j=0;j<VHQt_M/2;j++)
    {
        if (j%5==1) FaceOfLine[j]="square*";
        if (j%5==2) FaceOfLine[j]="triangle*";
        if (j%5==3) FaceOfLine[j]="diamond*";
        if (j%5==4) FaceOfLine[j]="triangle*, every mark/.append style={rotate=90}";
    }

    if (CircleStyle) for (j=0;j<VHQt_M/2;j++) FaceOfLine[j]="*";
    if (SolidStyle)  for (j=0;j<VHQt_M/2;j++) TypeLine[j]="";

    //Подсчитаем максимальное число N
    int VHQt_N_Max;
    VHQt_N_Max = VHQt_N_EveryCol[0];
    for (j=0;j<VHQt_M/2;j++)
        if (VHQt_N_EveryCol[j*2]>VHQt_N_Max)
            VHQt_N_Max=VHQt_N_EveryCol[j*2];

    //посчитаем гарницы изменения параметров
    T MinX=VHQt_MatrixXY[0][0];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2];i++)
            if (VHQt_MatrixXY[i][j*2]<MinX)
                MinX=VHQt_MatrixXY[i][j*2];

    T MaxX=VHQt_MatrixXY[0][0];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2];i++)
            if (VHQt_MatrixXY[i][j*2]>MaxX)
                MaxX=VHQt_MatrixXY[i][j*2];

    T MinY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2+1];i++)
            if (VHQt_MatrixXY[i][j*2+1]<MinY)
                MinY=VHQt_MatrixXY[i][j*2+1];

    T MaxY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2+1];i++)
            if (VHQt_MatrixXY[i][j*2+1]>MaxY)
                MaxY=VHQt_MatrixXY[i][j*2+1];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/15.;
    T LeftYBoundingBox=MinY-LengthY/15.;
    T RightXBoundingBox=MaxX+LengthX/15.;
    T RightYBoundingBox=MaxY+LengthY/15.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    if (ForNormalSize)
        VHQt_Result+="% Вывод графика\n{\n";
    else
        VHQt_Result+="% Вывод подграфика\n{\n";

    //Если график маленький, то дополнительные настройки:
    if (!ForNormalSize)
    {
        VHQt_Result+="\\pgfplotsset{every axis legend/.append style={at={(0.5,-0.25)},anchor=north,legend cell align=left},}\n";
    }

    //Обработаем текст подписи к осям.
    QString NameVectorXnew=NameVectorX,NameVectorYnew=NameVectorY, subStr;

    subStr=",";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorXnew.contains(","))&&(!NameVectorXnew.contains(".")))
        if (!HQt_CheckRus(NameVectorXnew))
            NameVectorXnew="$"+NameVectorXnew+"$";

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    NameVectorXnew=NameVectorXnew.replace(";","");
    NameVectorYnew=NameVectorYnew.replace(";","");

    NameVectorXnew=NameVectorXnew.replace("&","\\");
    NameVectorYnew=NameVectorYnew.replace("&","\\");

    //рисуем область графика и оси
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="xlabel={"+NameVectorXnew+"},\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";
    //if (ForNormalSize)
    VHQt_Result+="xmax="+SRightXBoundingBox+",\n";
    //if (ForNormalSize)
    VHQt_Result+="ymax="+SRightYBoundingBox+",\n";
    if (ForNormalSize)
    {
        QString HeightPlot="10cm";

        if (VHQt_M/2>10) HeightPlot="9cm";

        if (VHQt_M/2>19) HeightPlot="8cm";

        if (VHQt_M/2>25) HeightPlot="12cm";

        if (VHQt_M/2>35) HeightPlot="10cm";

        VHQt_Result+="height="+HeightPlot+",\n";
        VHQt_Result+="width=17cm,\n";
    }
    else
    {
        QString HeightPlot="5.8cm";

        if (VHQt_M/2>10) HeightPlot="4.8cm";

        if (VHQt_M/2>17) HeightPlot="6.8cm";


        VHQt_Result+="height="+HeightPlot+",\n";
        VHQt_Result+="width=8.5cm,\n";
    }
    VHQt_Result+=Legend;
    VHQt_Result+="]\n\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T **Temp_VHQt_MatrixXY;
    Temp_VHQt_MatrixXY=new double*[VHQt_N_Max];
    for (i=0;i<VHQt_N_Max;i++) Temp_VHQt_MatrixXY[i]=new double[VHQt_M];
    for (j=0;j<VHQt_M;j++)
        for (i=0;i<VHQt_N_EveryCol[j];i++)
            Temp_VHQt_MatrixXY[i][j]=VHQt_MatrixXY[i][j];

    //отсортируем массивы
    for (k=0;k<VHQt_M/2;k++)
    {
        for(i=VHQt_N_EveryCol[2*k]-1;i>0;i--)
            for(j=0;j<i;j++)
                if(Temp_VHQt_MatrixXY[j][2*k]>Temp_VHQt_MatrixXY[j+1][2*k])
                {
                    T x;
                    x=Temp_VHQt_MatrixXY[j+1][2*k];
                    Temp_VHQt_MatrixXY[j+1][2*k]=Temp_VHQt_MatrixXY[j][2*k];
                    Temp_VHQt_MatrixXY[j][2*k]=x;

                    x=Temp_VHQt_MatrixXY[j+1][2*k+1];
                    Temp_VHQt_MatrixXY[j+1][2*k+1]=Temp_VHQt_MatrixXY[j][2*k+1];
                    Temp_VHQt_MatrixXY[j][2*k+1]=x;
                }
    }

    QString *SData = new QString[VHQt_M/2];

    QString *Plot = new QString[VHQt_M/2];

    for (j=0;j<VHQt_M/2;j++)
    {
        for (i=0;i<VHQt_N_EveryCol[2*j]-1;i++)
            SData[j]+=" ("+QString::number(Temp_VHQt_MatrixXY[i][2*j])+", "+QString::number(Temp_VHQt_MatrixXY[i][2*j+1])+") \n";
        SData[j]+=" ("+QString::number(Temp_VHQt_MatrixXY[VHQt_N_EveryCol[2*j+1]-1][2*j])+", "+QString::number(Temp_VHQt_MatrixXY[VHQt_N_EveryCol[2*j+1]-1][2*j+1])+") \n";
    }

    QString MarkSize;
    if (VHQt_N_Max>100) MarkSize=",mark size=1.5pt";


    if ((ShowArea)&&((ShowPoints)||(ShowLine)))
    {
        //нарисуем закрашенную область
        for (j=0;j<VHQt_M/2;j++)
        {
            Plot[j]+="\\addplot[color="+ColorArea[j]+", draw=none,fill, fill opacity = "+Opacity+",forget plot] coordinates {\n";
            Plot[j]+=" ("+QString::number(Temp_VHQt_MatrixXY[0][2*j])+", "+QString::number(MinY)+") \n";
            Plot[j]+=SData[j];
            Plot[j]+=" ("+QString::number(Temp_VHQt_MatrixXY[VHQt_N_EveryCol[j*2]-1][2*j])+", "+QString::number(MinY)+") \n";
            Plot[j]+="};\n\n";
        }
    }

    if ((ShowArea)&&(!ShowPoints)&&(!ShowLine))
    {
        //нарисуем закрашенную область
        for (j=0;j<VHQt_M/2;j++)
        {
            Plot[j]+="\\addplot[color="+ColorArea[j]+", draw=none,fill, fill opacity = "+Opacity+"] coordinates {\n";
            Plot[j]+=" ("+QString::number(Temp_VHQt_MatrixXY[0][2*j])+", "+QString::number(MinY)+") \n";
            Plot[j]+=SData[j];
            Plot[j]+=" ("+QString::number(Temp_VHQt_MatrixXY[VHQt_N_EveryCol[j*2]-1][2*j])+", "+QString::number(MinY)+") \n";
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        for (j=0;j<VHQt_M/2;j++)
        {
            //Нарисуем график
            Plot[j]+="\\addplot[color=plot"+QString::number(j+1)+",mark options={plot"+QString::number(j+1)+",opacity = 1, fill=white,thick,solid}"+MarkSize+",very thick"+TypeLine[j]+", mark="+FaceOfLine[j]+"] coordinates {\n";
            Plot[j]+=SData[j];
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки
        for (j=0;j<VHQt_M/2;j++)
        {
            Plot[j]+="\\addplot[color=plot"+QString::number(j+1)+",mark options={plot"+QString::number(j+1)+",opacity = 1, fill=white,thick}"+MarkSize+",only marks, mark="+FaceOfLine[j]+"] coordinates {\n";
            Plot[j]+=SData[j];
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию
        for (j=0;j<VHQt_M/2;j++)
        {
            Plot[j]+="\\addplot[color=plot"+QString::number(j+1)+", no markers,very thick"+TypeLine[j]+"] coordinates {\n";
            Plot[j]+=SData[j];
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    //Цвета соберем
    for (j=0;j<VHQt_M/2;j++)
    {
        VHQt_Result+="\\definecolor{plot"+QString::number(j+1)+"}{HTML}{"+Color[j]+"}\n";
    }
    VHQt_Result+="\n";

    //собираем общий график
    for (j=0;j<VHQt_M/2;j++)
        VHQt_Result+=Plot[VHQt_M/2-j-1];

    if (ShowSpecPoints)
    {
        //Определим что писать в виде min_x и др.
        QString LabelX="Ox",LabelY="Oy";
        if (NameVectorX.length()<100) LabelX=NameVectorX;else LabelX="Ox";
        if (NameVectorY.length()<100) LabelY=NameVectorY;else LabelY="Oy";

        if (LabelX.contains(",")) LabelX=LabelX.mid(0,LabelX.indexOf(","));
        if (LabelY.contains(",")) LabelY=LabelY.mid(0,LabelY.indexOf(","));

        if (LabelX.contains(".")) LabelX=LabelX.mid(0,LabelX.indexOf("."));
        if (LabelY.contains(".")) LabelY=LabelY.mid(0,LabelY.indexOf("."));

        if (HQt_CheckRus(LabelX)) LabelX="Ox";
        if (HQt_CheckRus(LabelY)) LabelY="Oy";

        LabelX=LabelX.replace(";","");
        LabelY=LabelY.replace(";","");

        LabelX=LabelX.replace("&","\\");
        LabelY=LabelY.replace("&","\\");

        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\min_{"+LabelX+"}="+QString::number(MinX)+"; \\min_{"+LabelY+"}="+QString::number(MinY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="]\n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MinY)+")};\n";

        //Максимальная по Y
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelY+"} = "+QString::number(MaxY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MaxY)+")};\n";

        //Максимальная по X
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelX+"} = "+QString::number(MaxX)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=north west,font=\\tiny, rotate=90},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MaxX)+","+QString::number(MinY)+")};\n";
    }

    VHQt_Result+="\\end{axis}\n";
    VHQt_Result+="\\end{tikzpicture}\n";

    if (!TitleChart.isEmpty())
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{"+TitleChart+"}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{"+TitleChart+"}\n";
    }
    else
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{График}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{График}\n";
    }
    if (ForNormalSize) VHQt_Result+="\\end{figure}\n";

    VHQt_Result+="}\n\n";

    delete [] SData;
    delete [] Plot;
    delete [] Color;
    delete [] ColorArea;
    delete [] TypeLine;
    delete [] FaceOfLine;

    for (i=0;i<VHQt_N_Max;i++) delete [] Temp_VHQt_MatrixXY[i];
    delete [] Temp_VHQt_MatrixXY;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции отличается отсутствием параметров GrayStyle, SolidStyle, CircleStyle.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки;
 ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N_EveryCol, VHQt_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, ForNormalSize, false,  false,  false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции отличается отсутствием параметров ForNormalSize, GrayStyle, SolidStyle, CircleStyle.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N_EveryCol, VHQt_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, true, false,  false,  false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции отличается отсутствием всех булевских переменных.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 Label - label для графика.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N_EveryCol, VHQt_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, true, true, false, true, true, false,  false,  false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции отличается отсутствием всех булевских переменных и переменных названия.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно).
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VHQt_Result;//переменная итогового результата

    QString *NameLine;

    NameLine = new QString[VHQt_M-1];

    for (int i=0;i<VHQt_M-1;i++) NameLine[i]="График "+QString::number(i+1);

    VHQt_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N_EveryCol, VHQt_M, "", "x", "y", NameLine, "Chart"+HQt_RandomString(8), true, true, false, true, true, false,  false,  false);

    delete [] NameLine;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции, что число элементов в каждом графике одинаковое, поэтому вместо VHQt_N_EveryCol используется одно число VHQt_N.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
 VHQt_N - количество элементов в каждом столбце. Это число точек;
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно) VHQt_M/2 - это число графиков;
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки;
 ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается;
 GrayStyle - серый стиль графиков;
 SolidStyle - линии делать сплошными или разными по типу (точками, тире и др.);
 CircleStyle - точки все делать кругляшками или нет.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VHQt_Result;//переменная итогового результата

    int *VHQt_N_EveryCol = new int[VHQt_M];
    for (int i=0;i<VHQt_M;i++) VHQt_N_EveryCol[i]=VHQt_N;

    VHQt_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N_EveryCol, VHQt_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, ForNormalSize, GrayStyle,  SolidStyle,  CircleStyle);

    delete [] VHQt_N_EveryCol;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции, что число элементов в каждом графике одинаковое, поэтому вместо VHQt_N_EveryCol используется одно число VHQt_N. От основной функции также отличается отсутствием параметров GrayStyle, SolidStyle, CircleStyle.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
 VHQt_N - количество элементов в каждом столбце. Это число точек;
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно) VHQt_M/2 - это число графиков;
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки;
 ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VHQt_Result;//переменная итогового результата

    int *VHQt_N_EveryCol = new int[VHQt_M];
    for (int i=0;i<VHQt_M;i++) VHQt_N_EveryCol[i]=VHQt_N;

    VHQt_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N_EveryCol, VHQt_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, ForNormalSize, false,  false,  false);

    delete [] VHQt_N_EveryCol;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции, что число элементов в каждом графике одинаковое, поэтому вместо VHQt_N_EveryCol используется одно число VHQt_N. От основной функции также отличается отсутствием параметров ForNormalSize, GrayStyle, SolidStyle, CircleStyle.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
 VHQt_N - количество элементов в каждом столбце. Это число точек;
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно) VHQt_M/2 - это число графиков;
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VHQt_Result;//переменная итогового результата

    int *VHQt_N_EveryCol = new int[VHQt_M];
    for (int i=0;i<VHQt_M;i++) VHQt_N_EveryCol[i]=VHQt_N;

    VHQt_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N_EveryCol, VHQt_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, true, false,  false,  false);

    delete [] VHQt_N_EveryCol;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции, что число элементов в каждом графике одинаковое, поэтому вместо VHQt_N_EveryCol используется одно число VHQt_N. От основной функции также отличается отсутствием всех булевских переменных.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
 VHQt_N - количество элементов в каждом столбце. Это число точек;
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно) VHQt_M/2 - это число графиков;
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 Label - label для графика.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VHQt_Result;//переменная итогового результата

    int *VHQt_N_EveryCol = new int[VHQt_M];
    for (int i=0;i<VHQt_M;i++) VHQt_N_EveryCol[i]=VHQt_N;

    VHQt_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N_EveryCol, VHQt_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, true, true, false, true, true, false,  false,  false);

    delete [] VHQt_N_EveryCol;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции, что число элементов в каждом графике одинаковое, поэтому вместо VHQt_N_EveryCol используется одно число VHQt_N. От основной функции также отличается отсутствием всех булевских переменных и переменных названий.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
 VHQt_N - количество элементов в каждом столбце. Это число точек;
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно) VHQt_M/2 - это число графиков.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VHQt_Result;//переменная итогового результата

    int *VHQt_N_EveryCol = new int[VHQt_M];
    for (int i=0;i<VHQt_M;i++) VHQt_N_EveryCol[i]=VHQt_N;

    QString *NameLine;
    NameLine = new QString[VHQt_M-1];
    for (int i=0;i<VHQt_M-1;i++) NameLine[i]="График "+QString::number(i+1);

    VHQt_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N_EveryCol, VHQt_M, "", "x", "y", NameLine, "Chart"+HQt_RandomString(8), true, true, false, true, true, false,  false,  false);

    delete [] VHQt_N_EveryCol;
    delete [] NameLine;


    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle)
{
    /*
	Функция возвращает строку с выводом некоторых двух графиков за раз по точкам с Latex кодами.
    У обоих графиков одинаковый массив значений X.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается;
     GrayStyle - второй график рисовать серым, а не красным.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j;

    //посчитаем границы изменения параметров
    T MinX=VHQt_VectorX[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorX[i]<MinX)
            MinX=VHQt_VectorX[i];

    T MinY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY1[i]<MinY1)
            MinY1=VHQt_VectorY1[i];

    T MinY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY2[i]<MinY2)
            MinY2=VHQt_VectorY2[i];

    T MaxX=VHQt_VectorX[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorX[i]>MaxX)
            MaxX=VHQt_VectorX[i];

    T MaxY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY1[i]>MaxY1)
            MaxY1=VHQt_VectorY1[i];

    T MaxY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY2[i]>MaxY2)
            MaxY2=VHQt_VectorY2[i];

    T MinY;
    T MaxY;

    if (MinY1<MinY2)
        MinY=MinY1;
    else
        MinY=MinY2;

    if (MaxY1>MaxY2)
        MaxY=MaxY1;
    else
        MaxY=MaxY2;

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/15.;
    T LeftYBoundingBox=MinY-LengthY/15.;
    T RightXBoundingBox=MaxX+LengthX/15.;
    T RightYBoundingBox=MaxY+LengthY/15.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    if (ForNormalSize)
        VHQt_Result+="% Вывод графика\n";
    else
        VHQt_Result+="% Вывод подграфика\n";

    //Если график маленький, то дополнительные настройки:
    if (!ForNormalSize)
    {
        VHQt_Result+="{\\pgfplotsset{every axis legend/.append style={at={(0.5,-0.25)},anchor=north,legend cell align=left},}\n";
    }

    //Обработаем текст подписи к осям.
    QString NameVectorXnew=NameVectorX,NameVectorYnew=NameVectorY, subStr;

    subStr=",";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorXnew.contains(","))&&(!NameVectorXnew.contains(".")))
        if (!HQt_CheckRus(NameVectorXnew))
            NameVectorXnew="$"+NameVectorXnew+"$";

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    NameVectorXnew=NameVectorXnew.replace(";","");
    NameVectorYnew=NameVectorYnew.replace(";","");

    NameVectorXnew=NameVectorXnew.replace("&","\\");
    NameVectorYnew=NameVectorYnew.replace("&","\\");

    //рисуем область графика и оси
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="xlabel={"+NameVectorXnew+"},\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";
    //if (ForNormalSize)
    VHQt_Result+="xmax="+SRightXBoundingBox+",\n";
    //if (ForNormalSize)
    VHQt_Result+="ymax="+SRightYBoundingBox+",\n";
    if (ForNormalSize)
    {
        VHQt_Result+="height=10cm,\n";
        VHQt_Result+="width=17cm,\n";
    }
    else
    {
        VHQt_Result+="height=5.8cm,\n";
        VHQt_Result+="width=8.5cm,\n";
    }
    VHQt_Result+="]\n\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VHQt_VectorX=new T[VHQt_N];
    T *Temp_VHQt_VectorY1=new T[VHQt_N];
    T *Temp_VHQt_VectorY2=new T[VHQt_N];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_VectorX[i]=VHQt_VectorX[i];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_VectorY1[i]=VHQt_VectorY1[i];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_VectorY2[i]=VHQt_VectorY2[i];

    //отсортируем массивы
    for(i=VHQt_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX[j]>Temp_VHQt_VectorX[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX[j+1];
                Temp_VHQt_VectorX[j+1]=Temp_VHQt_VectorX[j];
                Temp_VHQt_VectorX[j]=x;
                x=Temp_VHQt_VectorY1[j+1];
                Temp_VHQt_VectorY1[j+1]=Temp_VHQt_VectorY1[j];
                Temp_VHQt_VectorY1[j]=x;
                x=Temp_VHQt_VectorY2[j+1];
                Temp_VHQt_VectorY2[j+1]=Temp_VHQt_VectorY2[j];
                Temp_VHQt_VectorY2[j]=x;
            }

    QString SData1;
    for (i=0;i<VHQt_N;i++)
        SData1+=" ("+QString::number(Temp_VHQt_VectorX[i])+", "+QString::number(Temp_VHQt_VectorY1[i])+") \n";

    QString SData2;
    for (i=0;i<VHQt_N;i++)
        SData2+=" ("+QString::number(Temp_VHQt_VectorX[i])+", "+QString::number(Temp_VHQt_VectorY2[i])+") \n";

    QString Plot1,Plot2;

    QString PlotSecond="plotsecond";
    if (GrayStyle) PlotSecond="plotsecondgray";

    if ((ShowArea)&&((ShowPoints)||(ShowLine)))
    {
        //нарисуем закрашенную область
        Plot1+="\\addplot[color=plotmain, draw=none,fill, fill opacity = 0.5,forget plot] coordinates {\n";
        Plot1+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
        Plot1+=SData1;
        Plot1+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
        Plot1+="};\n\n";

        //нарисуем закрашенную область
        Plot2+="\\addplot[color="+PlotSecond+", draw=none,fill, fill opacity = 0.4,forget plot] coordinates {\n";
        Plot2+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
        Plot2+=SData2;
        Plot2+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
        Plot2+="};\n\n";
    }

    if ((ShowArea)&&(!ShowPoints)&&(!ShowLine))
    {
        //нарисуем закрашенную область
        Plot1+="\\addplot[color=plotmain, draw=none,fill, fill opacity = 0.5] coordinates {\n";
        Plot1+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
        Plot1+=SData1;
        Plot1+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine1+"};\n\n";

        //нарисуем закрашенную область
        Plot2+="\\addplot[color="+PlotSecond+", draw=none,fill, fill opacity = 0.4] coordinates {\n";
        Plot2+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
        Plot2+=SData2;
        Plot2+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine2+"};\n\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        QString MarkSize;
        if (VHQt_N>100) MarkSize=",mark size=1.5pt";

        //Нарисуем график
        Plot1+="\\addplot[color=plotmain, mark=*,mark options={plotmain,opacity = 1, fill=white,thick}"+MarkSize+",very thick] coordinates {\n";
        Plot1+=SData1;
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine1+"};\n\n";

        //Нарисуем график
        Plot2+="\\addplot[color="+PlotSecond+", mark=*,mark options={"+PlotSecond+",opacity = 1, fill=white,fill opacity = 1, thick,solid}"+MarkSize+",very thick,dashed] coordinates {\n";
        Plot2+=SData2;
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine2+"};\n\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        QString MarkSize;
        if (VHQt_N>100) MarkSize=",mark size=1.5pt";

        //Нарисуем график
        Plot1+="\\addplot[color=plotmain, mark=*,mark options={plotmain,opacity = 1, fill=white,thick}"+MarkSize+",only marks] coordinates {\n";
        Plot1+=SData1;
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine1+"};\n\n";

        //Нарисуем график
        Plot2+="\\addplot[color="+PlotSecond+", mark=square*,mark options={"+PlotSecond+",opacity = 1, fill=white,fill opacity = 1, thick,solid}"+MarkSize+",only marks] coordinates {\n";
        Plot2+=SData2;
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine2+"};\n\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        Plot1+="\\addplot[color=plotmain, no markers,very thick] coordinates {\n";
        Plot1+=SData1;
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine1+"};\n\n";

        Plot2+="\\addplot[color="+PlotSecond+", no markers,very thick] coordinates {\n";
        Plot2+=SData2;
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine2+"};\n\n";
    }


    //собираем общий график
    VHQt_Result+=Plot2;
    VHQt_Result+=Plot1;

    if (ShowSpecPoints)
    {
        //Определим что писать в виде min_x и др.
        QString LabelX="Ox",LabelY="Oy";
        if (NameVectorX.length()<100) LabelX=NameVectorX;else LabelX="Ox";
        if (NameVectorY.length()<100) LabelY=NameVectorY;else LabelY="Oy";

        if (LabelX.contains(",")) LabelX=LabelX.mid(0,LabelX.indexOf(","));
        if (LabelY.contains(",")) LabelY=LabelY.mid(0,LabelY.indexOf(","));

        if (LabelX.contains(".")) LabelX=LabelX.mid(0,LabelX.indexOf("."));
        if (LabelY.contains(".")) LabelY=LabelY.mid(0,LabelY.indexOf("."));

        if (HQt_CheckRus(LabelX)) LabelX="Ox";
        if (HQt_CheckRus(LabelY)) LabelY="Oy";

        LabelX=LabelX.replace(";","");
        LabelY=LabelY.replace(";","");

        LabelX=LabelX.replace("&","\\");
        LabelY=LabelY.replace("&","\\");

        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\min_{"+LabelX+"}="+QString::number(MinX)+"; \\min_{"+LabelY+"}="+QString::number(MinY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="]\n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MinY)+")};\n";

        //Максимальная по Y
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelY+"} = "+QString::number(MaxY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MaxY)+")};\n";

        //Максимальная по X
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelX+"} = "+QString::number(MaxX)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=north west,font=\\tiny, rotate=90},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MaxX)+","+QString::number(MinY)+")};\n";
    }

    VHQt_Result+="\\end{axis}\n";
    VHQt_Result+="\\end{tikzpicture}\n";

    if (!ForNormalSize)
    {
        VHQt_Result+="}\n";
    }

    if (!TitleChart.isEmpty())
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{"+TitleChart+"}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{"+TitleChart+"}\n";
    }
    else
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{График}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{График}\n";
    }
    if (ForNormalSize) VHQt_Result+="\\end{figure}\n";

    delete [] Temp_VHQt_VectorX;
    delete [] Temp_VHQt_VectorY1;
    delete [] Temp_VHQt_VectorY2;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с Latex кодами. У обоих графиков одинаковый массив значений X. По сравнению с основной функцией тут отсутствует параметр GrayStyle.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoChartsOfLine (VHQt_VectorX,VHQt_VectorY1,VHQt_VectorY2, VHQt_N, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, ForNormalSize, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с Latex кодами. У обоих графиков одинаковый массив значений X. По сравнению с основной функцией тут отсутствует параметр ForNormalSize.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoChartsOfLine (VHQt_VectorX,VHQt_VectorY1,VHQt_VectorY2, VHQt_N, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints,true,false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с Latex кодами. У обоих графиков одинаковый массив значений X. По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoChartsOfLine (VHQt_VectorX,VHQt_VectorY1,VHQt_VectorY2, VHQt_N, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2, Label, true, true, true, true,true,false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с Latex кодами. У обоих графиков одинаковый массив значений X. По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные, а также все переменные названий.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoChartsOfLine (VHQt_VectorX,VHQt_VectorY1,VHQt_VectorY2, VHQt_N, "", "x", "y", "График 1", "График 2", "Chart"+HQt_RandomString(8), true, true, true, true,true,false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle)
{
    /*
    Функция возвращает строку с выводом некоторых двух независимых графиков по точкам с Latex кодами.
    У обоих графиков разные массивы значений X и Y.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается;
     GrayStyle - второй график рисовать серым, а не красным.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j;

    //посчитаем границы изменения параметров
    T MinX1=VHQt_VectorX1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorX1[i]<MinX1)
            MinX1=VHQt_VectorX1[i];

    T MinX2=VHQt_VectorX2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorX2[i]<MinX2)
            MinX2=VHQt_VectorX2[i];

    T MinY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorY1[i]<MinY1)
            MinY1=VHQt_VectorY1[i];

    T MinY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorY2[i]<MinY2)
            MinY2=VHQt_VectorY2[i];

    T MaxX1=VHQt_VectorX1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorX1[i]>MaxX1)
            MaxX1=VHQt_VectorX1[i];

    T MaxX2=VHQt_VectorX2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorX2[i]>MaxX2)
            MaxX2=VHQt_VectorX2[i];

    T MaxY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorY1[i]>MaxY1)
            MaxY1=VHQt_VectorY1[i];

    T MaxY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorY2[i]>MaxY2)
            MaxY2=VHQt_VectorY2[i];

    T MinX;
    T MaxX;

    T MinY;
    T MaxY;

    if (MinX1<MinX2)
        MinX=MinX1;
    else
        MinX=MinX2;

    if (MaxX1>MaxX2)
        MaxX=MaxX1;
    else
        MaxX=MaxX2;

    if (MinY1<MinY2)
        MinY=MinY1;
    else
        MinY=MinY2;

    if (MaxY1>MaxY2)
        MaxY=MaxY1;
    else
        MaxY=MaxY2;

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/15.;
    T LeftYBoundingBox=MinY-LengthY/15.;
    T RightXBoundingBox=MaxX+LengthX/15.;
    T RightYBoundingBox=MaxY+LengthY/15.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    if (ForNormalSize)
        VHQt_Result+="% Вывод графика\n";
    else
        VHQt_Result+="% Вывод подграфика\n";

    //Если график маленький, то дополнительные настройки:
    if (!ForNormalSize)
    {
        VHQt_Result+="{\\pgfplotsset{every axis legend/.append style={at={(0.5,-0.25)},anchor=north,legend cell align=left},}\n";
    }

    //Обработаем текст подписи к осям.
    QString NameVectorXnew=NameVectorX,NameVectorYnew=NameVectorY, subStr;

    subStr=",";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorXnew.contains(","))&&(!NameVectorXnew.contains(".")))
        if (!HQt_CheckRus(NameVectorXnew))
            NameVectorXnew="$"+NameVectorXnew+"$";

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    NameVectorXnew=NameVectorXnew.replace(";","");
    NameVectorYnew=NameVectorYnew.replace(";","");

    NameVectorXnew=NameVectorXnew.replace("&","\\");
    NameVectorYnew=NameVectorYnew.replace("&","\\");

    //рисуем область графика и оси
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="xlabel={"+NameVectorXnew+"},\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";
    //if (ForNormalSize)
    VHQt_Result+="xmax="+SRightXBoundingBox+",\n";
    //if (ForNormalSize)
    VHQt_Result+="ymax="+SRightYBoundingBox+",\n";
    if (ForNormalSize)
    {
        VHQt_Result+="height=10cm,\n";
        VHQt_Result+="width=17cm,\n";
    }
    else
    {
        VHQt_Result+="height=5.8cm,\n";
        VHQt_Result+="width=8.5cm,\n";
    }
    VHQt_Result+="]\n\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VHQt_VectorX1=new T[VHQt_N1];
    T *Temp_VHQt_VectorX2=new T[VHQt_N2];
    T *Temp_VHQt_VectorY1=new T[VHQt_N1];
    T *Temp_VHQt_VectorY2=new T[VHQt_N2];
    for (i=0;i<VHQt_N1;i++) Temp_VHQt_VectorX1[i]=VHQt_VectorX1[i];
    for (i=0;i<VHQt_N2;i++) Temp_VHQt_VectorX2[i]=VHQt_VectorX2[i];
    for (i=0;i<VHQt_N1;i++) Temp_VHQt_VectorY1[i]=VHQt_VectorY1[i];
    for (i=0;i<VHQt_N2;i++) Temp_VHQt_VectorY2[i]=VHQt_VectorY2[i];

    //отсортируем массивы
    for(i=VHQt_N1-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX1[j]>Temp_VHQt_VectorX1[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX1[j+1];
                Temp_VHQt_VectorX1[j+1]=Temp_VHQt_VectorX1[j];
                Temp_VHQt_VectorX1[j]=x;
                x=Temp_VHQt_VectorY1[j+1];
                Temp_VHQt_VectorY1[j+1]=Temp_VHQt_VectorY1[j];
                Temp_VHQt_VectorY1[j]=x;
            }

    for(i=VHQt_N2-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX2[j]>Temp_VHQt_VectorX2[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX2[j+1];
                Temp_VHQt_VectorX2[j+1]=Temp_VHQt_VectorX2[j];
                Temp_VHQt_VectorX2[j]=x;
                x=Temp_VHQt_VectorY2[j+1];
                Temp_VHQt_VectorY2[j+1]=Temp_VHQt_VectorY2[j];
                Temp_VHQt_VectorY2[j]=x;
            }

    QString SData1;
    for (i=0;i<VHQt_N1;i++)
        SData1+=" ("+QString::number(Temp_VHQt_VectorX1[i])+", "+QString::number(Temp_VHQt_VectorY1[i])+") \n";

    QString SData2;
    for (i=0;i<VHQt_N2;i++)
        SData2+=" ("+QString::number(Temp_VHQt_VectorX2[i])+", "+QString::number(Temp_VHQt_VectorY2[i])+") \n";

    QString Plot1,Plot2;

    QString PlotSecond="plotsecond";
    if (GrayStyle) PlotSecond="plotsecondgray";

    QString MarkSize;
    if ((VHQt_N1>100)||(VHQt_N2>100)) MarkSize=",mark size=1.5pt";

    if ((ShowArea)&&((ShowPoints)||(ShowLine)))
    {
        //нарисуем закрашенную область
        Plot1+="\\addplot[color=plotmain, draw=none,fill, fill opacity = 0.5,forget plot] coordinates {\n";
        Plot1+=" ("+QString::number(MinX1)+", "+QString::number(MinY)+") \n";
        Plot1+=SData1;
        Plot1+=" ("+QString::number(MaxX1)+", "+QString::number(MinY)+") \n";
        Plot1+="};\n\n";

        //нарисуем закрашенную область
        Plot2+="\\addplot[color="+PlotSecond+", draw=none,fill, fill opacity = 0.4,forget plot] coordinates {\n";
        Plot2+=" ("+QString::number(MinX2)+", "+QString::number(MinY)+") \n";
        Plot2+=SData2;
        Plot2+=" ("+QString::number(MaxX2)+", "+QString::number(MinY)+") \n";
        Plot2+="};\n\n";
    }

    if ((ShowArea)&&(!ShowPoints)&&(!ShowLine))
    {
        //нарисуем закрашенную область
        Plot1+="\\addplot[color=plotmain, draw=none,fill, fill opacity = 0.5] coordinates {\n";
        Plot1+=" ("+QString::number(MinX1)+", "+QString::number(MinY)+") \n";
        Plot1+=SData1;
        Plot1+=" ("+QString::number(MaxX1)+", "+QString::number(MinY)+") \n";
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine1+"};\n\n";

        //нарисуем закрашенную область
        Plot2+="\\addplot[color="+PlotSecond+", draw=none,fill, fill opacity = 0.4] coordinates {\n";
        Plot2+=" ("+QString::number(MinX2)+", "+QString::number(MinY)+") \n";
        Plot2+=SData2;
        Plot2+=" ("+QString::number(MaxX2)+", "+QString::number(MinY)+") \n";
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine2+"};\n\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        Plot1+="\\addplot[color=plotmain, mark=*,mark options={plotmain,opacity = 1, fill=white,thick}"+MarkSize+",very thick] coordinates {\n";
        Plot1+=SData1;
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine1+"};\n\n";

        //Нарисуем график
        Plot2+="\\addplot[color="+PlotSecond+", mark=*,mark options={"+PlotSecond+",opacity = 1, fill=white,fill opacity = 1, thick,solid}"+MarkSize+",very thick,dashed] coordinates {\n";
        Plot2+=SData2;
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine2+"};\n\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем график
        Plot1+="\\addplot[color=plotmain, mark=*,mark options={plotmain,opacity = 1, fill=white,thick}"+MarkSize+",only marks] coordinates {\n";
        Plot1+=SData1;
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine1+"};\n\n";

        //Нарисуем график
        Plot2+="\\addplot[color="+PlotSecond+", mark=square*,mark options={"+PlotSecond+",opacity = 1, fill=white,fill opacity = 1, thick,solid}"+MarkSize+",only marks] coordinates {\n";
        Plot2+=SData2;
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine2+"};\n\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        Plot1+="\\addplot[color=plotmain, no markers,very thick] coordinates {\n";
        Plot1+=SData1;
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine1+"};\n\n";

        Plot2+="\\addplot[color="+PlotSecond+", no markers,very thick] coordinates {\n";
        Plot2+=SData2;
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine2+"};\n\n";
    }

    //собираем общий график
    VHQt_Result+=Plot2;
    VHQt_Result+=Plot1;


    if (ShowSpecPoints)
    {
        //Определим что писать в виде min_x и др.
        QString LabelX="Ox",LabelY="Oy";
        if (NameVectorX.length()<100) LabelX=NameVectorX;else LabelX="Ox";
        if (NameVectorY.length()<100) LabelY=NameVectorY;else LabelY="Oy";

        if (LabelX.contains(",")) LabelX=LabelX.mid(0,LabelX.indexOf(","));
        if (LabelY.contains(",")) LabelY=LabelY.mid(0,LabelY.indexOf(","));

        if (LabelX.contains(".")) LabelX=LabelX.mid(0,LabelX.indexOf("."));
        if (LabelY.contains(".")) LabelY=LabelY.mid(0,LabelY.indexOf("."));

        if (HQt_CheckRus(LabelX)) LabelX="Ox";
        if (HQt_CheckRus(LabelY)) LabelY="Oy";

        LabelX=LabelX.replace(";","");
        LabelY=LabelY.replace(";","");

        LabelX=LabelX.replace("&","\\");
        LabelY=LabelY.replace("&","\\");

        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\min_{"+LabelX+"}="+QString::number(MinX)+"; \\min_{"+LabelY+"}="+QString::number(MinY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="]\n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MinY)+")};\n";

        //Максимальная по Y
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelY+"} = "+QString::number(MaxY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MaxY)+")};\n";

        //Максимальная по X
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelX+"} = "+QString::number(MaxX)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=north west,font=\\tiny, rotate=90},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MaxX)+","+QString::number(MinY)+")};\n";
    }

    VHQt_Result+="\\end{axis}\n";
    VHQt_Result+="\\end{tikzpicture}\n";

    if (!ForNormalSize)
    {
        VHQt_Result+="}\n";
    }

    if (!TitleChart.isEmpty())
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{"+TitleChart+"}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{"+TitleChart+"}\n";
    }
    else
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{График}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{График}\n";
    }
    if (ForNormalSize) VHQt_Result+="\\end{figure}\n";

    delete [] Temp_VHQt_VectorX1;
    delete [] Temp_VHQt_VectorX2;
    delete [] Temp_VHQt_VectorY1;
    delete [] Temp_VHQt_VectorY2;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторых двух независимых графиков по точкам с Latex кодами. По сравнению с основной функцией тут отсутствует параметр GrayStyle.
    У обоих графиков разные массивы значений X и Y.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoIndependentChartsOfLine (VHQt_VectorX1, VHQt_VectorY1, VHQt_N1, VHQt_VectorX2, VHQt_VectorY2, VHQt_N2, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, ForNormalSize, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторых двух независимых графиков по точкам с Latex кодами. По сравнению с основной функцией тут отсутствует параметр ForNormalSize.
    У обоих графиков разные массивы значений X и Y.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoIndependentChartsOfLine (VHQt_VectorX1, VHQt_VectorY1, VHQt_N1, VHQt_VectorX2, VHQt_VectorY2, VHQt_N2, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, true, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторых двух независимых графиков по точкам с Latex кодами. По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные.
    У обоих графиков разные массивы значений X и Y.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoIndependentChartsOfLine (VHQt_VectorX1, VHQt_VectorY1, VHQt_N1, VHQt_VectorX2, VHQt_VectorY2, VHQt_N2, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2, Label, true, true, true, true,true, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2)
{
    /*
    Функция возвращает строку с выводом некоторых двух независимых графиков по точкам с Latex кодами. По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные, а также все переменные названий.
    У обоих графиков разные массивы значений X и Y.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoIndependentChartsOfLine (VHQt_VectorX1, VHQt_VectorY1, VHQt_N1, VHQt_VectorX2, VHQt_VectorY2, VHQt_N2, "", "x", "y", "График 1", "График 2", "Chart"+HQt_RandomString(8), true, true, true, true,true, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с Latex кодами. 
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается;
     GrayStyle - второй график рисовать серым, а не красным.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j;

    //посчитаем границы изменения параметров
    T MinX1=VHQt_VectorX1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorX1[i]<MinX1)
            MinX1=VHQt_VectorX1[i];

    T MinX2=VHQt_VectorX2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorX2[i]<MinX2)
            MinX2=VHQt_VectorX2[i];

    T MinY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorY1[i]<MinY1)
            MinY1=VHQt_VectorY1[i];

    T MinY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorY2[i]<MinY2)
            MinY2=VHQt_VectorY2[i];

    T MaxX1=VHQt_VectorX1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorX1[i]>MaxX1)
            MaxX1=VHQt_VectorX1[i];

    T MaxX2=VHQt_VectorX2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorX2[i]>MaxX2)
            MaxX2=VHQt_VectorX2[i];

    T MaxY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorY1[i]>MaxY1)
            MaxY1=VHQt_VectorY1[i];

    T MaxY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorY2[i]>MaxY2)
            MaxY2=VHQt_VectorY2[i];

    T MinX;
    T MaxX;

    T MinY;
    T MaxY;

    if (MinX1<MinX2)
        MinX=MinX1;
    else
        MinX=MinX2;

    if (MaxX1>MaxX2)
        MaxX=MaxX1;
    else
        MaxX=MaxX2;

    if (MinY1<MinY2)
        MinY=MinY1;
    else
        MinY=MinY2;

    if (MaxY1>MaxY2)
        MaxY=MaxY1;
    else
        MaxY=MaxY2;

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/15.;
    T LeftYBoundingBox=MinY-LengthY/15.;
    T RightXBoundingBox=MaxX+LengthX/15.;
    T RightYBoundingBox=MaxY+LengthY/15.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    if (ForNormalSize)
        VHQt_Result+="% Вывод графика\n";
    else
        VHQt_Result+="% Вывод подграфика\n";

    //Если график маленький, то дополнительные настройки:
    if (!ForNormalSize)
    {
        VHQt_Result+="{\\pgfplotsset{every axis legend/.append style={at={(0.5,-0.25)},anchor=north,legend cell align=left},}\n";
    }


    //Обработаем текст подписи к осям.
    QString NameVectorXnew=NameVectorX,NameVectorYnew=NameVectorY, subStr;

    subStr=",";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorXnew.contains(","))&&(!NameVectorXnew.contains(".")))
        if (!HQt_CheckRus(NameVectorXnew))
            NameVectorXnew="$"+NameVectorXnew+"$";

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    NameVectorXnew=NameVectorXnew.replace(";","");
    NameVectorYnew=NameVectorYnew.replace(";","");

    NameVectorXnew=NameVectorXnew.replace("&","\\");
    NameVectorYnew=NameVectorYnew.replace("&","\\");

    //рисуем область графика и оси
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="xlabel={"+NameVectorXnew+"},\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";
    //if (ForNormalSize)
    VHQt_Result+="xmax="+SRightXBoundingBox+",\n";
    //if (ForNormalSize)
    VHQt_Result+="ymax="+SRightYBoundingBox+",\n";
    if (ForNormalSize)
    {
        VHQt_Result+="height=10cm,\n";
        VHQt_Result+="width=17cm,\n";
    }
    else
    {
        VHQt_Result+="height=5.8cm,\n";
        VHQt_Result+="width=8.5cm,\n";
    }
    VHQt_Result+="]\n\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VHQt_VectorX1=new T[VHQt_N1];
    T *Temp_VHQt_VectorX2=new T[VHQt_N2];
    T *Temp_VHQt_VectorY1=new T[VHQt_N1];
    T *Temp_VHQt_VectorY2=new T[VHQt_N2];
    for (i=0;i<VHQt_N1;i++) Temp_VHQt_VectorX1[i]=VHQt_VectorX1[i];
    for (i=0;i<VHQt_N2;i++) Temp_VHQt_VectorX2[i]=VHQt_VectorX2[i];
    for (i=0;i<VHQt_N1;i++) Temp_VHQt_VectorY1[i]=VHQt_VectorY1[i];
    for (i=0;i<VHQt_N2;i++) Temp_VHQt_VectorY2[i]=VHQt_VectorY2[i];

    //отсортируем массивы
    for(i=VHQt_N1-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX1[j]>Temp_VHQt_VectorX1[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX1[j+1];
                Temp_VHQt_VectorX1[j+1]=Temp_VHQt_VectorX1[j];
                Temp_VHQt_VectorX1[j]=x;
                x=Temp_VHQt_VectorY1[j+1];
                Temp_VHQt_VectorY1[j+1]=Temp_VHQt_VectorY1[j];
                Temp_VHQt_VectorY1[j]=x;
            }

    for(i=VHQt_N2-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX2[j]>Temp_VHQt_VectorX2[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX2[j+1];
                Temp_VHQt_VectorX2[j+1]=Temp_VHQt_VectorX2[j];
                Temp_VHQt_VectorX2[j]=x;
                x=Temp_VHQt_VectorY2[j+1];
                Temp_VHQt_VectorY2[j+1]=Temp_VHQt_VectorY2[j];
                Temp_VHQt_VectorY2[j]=x;
            }

    QString SData1;
    for (i=0;i<VHQt_N1;i++)
        SData1+=" ("+QString::number(Temp_VHQt_VectorX1[i])+", "+QString::number(Temp_VHQt_VectorY1[i])+") \n";

    QString SData2;
    for (i=0;i<VHQt_N2;i++)
        SData2+=" ("+QString::number(Temp_VHQt_VectorX2[i])+", "+QString::number(Temp_VHQt_VectorY2[i])+") \n";

    QString Plot1,Plot2;

    QString PlotSecond="plotsecond";
    if (GrayStyle) PlotSecond="plotsecondgray";

    QString MarkSize;
    if ((VHQt_N1>100)||(VHQt_N2>100)) MarkSize=",mark size=1.5pt";

    if ((ShowArea)&&((ShowPoints)||(ShowLine)))
    {
        //нарисуем закрашенную область
        Plot1+="\\addplot[color=plotmain, draw=none,fill, fill opacity = 0.5,forget plot] coordinates {\n";
        Plot1+=" ("+QString::number(MinX2)+", "+QString::number(MinY)+") \n";
        Plot1+=SData2;
        Plot1+=" ("+QString::number(MaxX2)+", "+QString::number(MinY)+") \n";
        Plot1+="};\n\n";
    }

    if ((ShowArea)&&(!ShowPoints)&&(!ShowLine))
    {
        //нарисуем закрашенную область
        Plot1+="\\addplot[color=plotmain, draw=none,fill, fill opacity = 0.5] coordinates {\n";
        Plot1+=" ("+QString::number(MinX2)+", "+QString::number(MinY)+") \n";
        Plot1+=SData2;
        Plot1+=" ("+QString::number(MaxX2)+", "+QString::number(MinY)+") \n";
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine2+"};\n\n";

        Plot2+="\\addplot[color="+PlotSecond+", mark=*,mark options={"+PlotSecond+",opacity = 1, fill=white,fill opacity = 1, thick,solid}"+MarkSize+",only marks] coordinates {\n";
        Plot2+=SData1;
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine1+"};\n\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        Plot1+="\\addplot[color=plotmain, mark=*,mark options={plotmain,opacity = 1, fill=white,thick}"+MarkSize+",very thick] coordinates {\n";
        Plot1+=SData2;
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine2+"};\n\n";

        //Нарисуем график
        Plot2+="\\addplot[color="+PlotSecond+", mark=*,mark options={"+PlotSecond+",opacity = 1, fill=white,fill opacity = 1, thick,solid}"+MarkSize+",only marks] coordinates {\n";
        Plot2+=SData1;
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine1+"};\n\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем график
        Plot1+="\\addplot[color=plotmain, mark=*,mark options={plotmain,opacity = 1, fill=white,thick}"+MarkSize+",only marks] coordinates {\n";
        Plot1+=SData2;
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine2+"};\n\n";

        //Нарисуем график
        Plot2+="\\addplot[color="+PlotSecond+", mark=*,mark options={"+PlotSecond+",opacity = 1, fill=white,fill opacity = 1, thick,solid}"+MarkSize+",only marks] coordinates {\n";
        Plot2+=SData1;
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine1+"};\n\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        Plot1+="\\addplot[color=plotmain, no markers,very thick] coordinates {\n";
        Plot1+=SData2;
        Plot1+="};\n";
        Plot1+="\\addlegendentry{"+NameLine2+"};\n\n";

        Plot2+="\\addplot[color="+PlotSecond+", mark=*,mark options={"+PlotSecond+",opacity = 1, fill=white,fill opacity = 1, thick,solid}"+MarkSize+",only marks] coordinates {\n";
        Plot2+=SData1;
        Plot2+="};\n";
        Plot2+="\\addlegendentry{"+NameLine1+"};\n\n";
    }

    //собираем общий график
    VHQt_Result+=Plot1;
    VHQt_Result+=Plot2;


    if (ShowSpecPoints)
    {
        //Определим что писать в виде min_x и др.
        QString LabelX="Ox",LabelY="Oy";
        if (NameVectorX.length()<100) LabelX=NameVectorX;else LabelX="Ox";
        if (NameVectorY.length()<100) LabelY=NameVectorY;else LabelY="Oy";

        if (LabelX.contains(",")) LabelX=LabelX.mid(0,LabelX.indexOf(","));
        if (LabelY.contains(",")) LabelY=LabelY.mid(0,LabelY.indexOf(","));

        if (LabelX.contains(".")) LabelX=LabelX.mid(0,LabelX.indexOf("."));
        if (LabelY.contains(".")) LabelY=LabelY.mid(0,LabelY.indexOf("."));

        if (HQt_CheckRus(LabelX)) LabelX="Ox";
        if (HQt_CheckRus(LabelY)) LabelY="Oy";

        LabelX=LabelX.replace(";","");
        LabelY=LabelY.replace(";","");

        LabelX=LabelX.replace("&","\\");
        LabelY=LabelY.replace("&","\\");

        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\min_{"+LabelX+"}="+QString::number(MinX)+"; \\min_{"+LabelY+"}="+QString::number(MinY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="]\n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MinY)+")};\n";

        //Максимальная по Y
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelY+"} = "+QString::number(MaxY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MaxY)+")};\n";

        //Максимальная по X
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelX+"} = "+QString::number(MaxX)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=north west,font=\\tiny, rotate=90},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MaxX)+","+QString::number(MinY)+")};\n";
    }

    VHQt_Result+="\\end{axis}\n";
    VHQt_Result+="\\end{tikzpicture}\n";

    if (!ForNormalSize)
    {
        VHQt_Result+="}\n";
    }

    if (!TitleChart.isEmpty())
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{"+TitleChart+"}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{"+TitleChart+"}\n";
    }
    else
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{График}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{График}\n";
    }
    if (ForNormalSize) VHQt_Result+="\\end{figure}\n";

    delete [] Temp_VHQt_VectorX1;
    delete [] Temp_VHQt_VectorX2;
    delete [] Temp_VHQt_VectorY1;
    delete [] Temp_VHQt_VectorY2;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с Latex кодами. 
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    По сравнению с основной функцией тут отсутствует параметр GrayStyle.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoIndependentChartsOfPointsAndLine (VHQt_VectorX1, VHQt_VectorY1, VHQt_N1, VHQt_VectorX2, VHQt_VectorY2, VHQt_N2, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, ForNormalSize, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с Latex кодами. 
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    По сравнению с основной функцией тут отсутствует параметр GrayStyle и ForNormalSize.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoIndependentChartsOfPointsAndLine (VHQt_VectorX1, VHQt_VectorY1, VHQt_N1, VHQt_VectorX2, VHQt_VectorY2, VHQt_N2, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, true, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с Latex кодами. 
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoIndependentChartsOfPointsAndLine (VHQt_VectorX1, VHQt_VectorY1, VHQt_N1, VHQt_VectorX2, VHQt_VectorY2, VHQt_N2, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2, Label, true, true, true, true,true, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с Latex кодами. 
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
     По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные, а также все переменные названий.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowTwoIndependentChartsOfPointsAndLine (VHQt_VectorX1, VHQt_VectorY1, VHQt_N1, VHQt_VectorX2, VHQt_VectorY2, VHQt_N2, "", "x", "y", "График 1", "График 2", "Chart"+HQt_RandomString(8), true, true, true, true,true, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------

//*****************************************************************
//Обработка текста
//*****************************************************************
template <class T> QString THQt_LatexNumberToText (T VHQt_X)
{
    /*
    Функция выводит число VHQt_X в строку Latex, причем число выделено жирным.
    Входные параметры:
     VHQt_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VHQt_Result;
    VHQt_Result=" \\textbf{"+QString::number(VHQt_X)+"} ";
    return VHQt_Result;
}
//---------------------------------------------------------------------------

//*****************************************************************
//Показ математических выражений
//*****************************************************************
template <class T> QString THQt_LatexShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с Latex кодами.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     VHQt_M - количество столбцов в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n"+TitleMatrix+":\n";
    VHQt_Result+="\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VHQt_M;j++) C+="c";
    VHQt_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;

        for (int j=0;j<VHQt_M;j++)
        {
            if (j!=VHQt_M-1) H=" & "; else H="";
            VHQt_Result+=QString::number(VHQt_Matrix[i][j])+H;
        }

        if (i!=VHQt_N-1) H="\\\\"; else H="";
        VHQt_Result+=H;
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с Latex кодами.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     VHQt_M - количество столбцов в матрице;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VHQt_M;j++) C+="c";
    VHQt_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;

        for (int j=0;j<VHQt_M;j++)
        {
            if (j!=VHQt_M-1) H=" & "; else H="";
            VHQt_Result+=QString::number(VHQt_Matrix[i][j])+H;
        }

        if (i!=VHQt_N-1) H="\\\\"; else H="";
        VHQt_Result+=H;
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с Latex кодами.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     VHQt_M - количество столбцов в матрице.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="\\overline{x} = ";

    QString C;
    for (int j=0;j<VHQt_M;j++) C+="c";
    VHQt_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;

        for (int j=0;j<VHQt_M;j++)
        {
            if (j!=VHQt_M-1) H=" & "; else H="";
            VHQt_Result+=QString::number(VHQt_Matrix[i][j])+H;
        }

        if (i!=VHQt_N-1) H="\\\\"; else H="";
        VHQt_Result+=H;
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_LatexShowVector (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n"+TitleVector+":\n";
    VHQt_Result+="\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameVector+"} = ";

    VHQt_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+=QString::number(VHQt_Vector[i])+"\\\\";
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowVector (T *VHQt_Vector, int VHQt_N, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameVector+"} = ";

    VHQt_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+=QString::number(VHQt_Vector[i])+"\\\\";
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowVector (T *VHQt_Vector, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="\\overline{x} = ";

    VHQt_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+=QString::number(VHQt_Vector[i])+"\\\\";
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_LatexShowVectorT (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector в транспонированном виде с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n"+TitleVector+":\n";
    VHQt_Result+="\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameVector+"} = ";

    VHQt_Result+="\\left( ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;
        if (i!=VHQt_N-1) H="; ";
        VHQt_Result+=QString::number(VHQt_Vector[i])+H;
    }

    VHQt_Result+="\\right)^\\mathrm{T}.\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowVectorT (T *VHQt_Vector, int VHQt_N, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector в транспонированном виде с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameVector+"} = ";

    VHQt_Result+="\\left( ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;
        if (i!=VHQt_N-1) H="; ";
        VHQt_Result+=QString::number(VHQt_Vector[i])+H;
    }

    VHQt_Result+="\\right)^\\mathrm{T}.\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowVectorT (T *VHQt_Vector, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector в транспонированном виде с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="\\overline{x} = ";

    VHQt_Result+="\\left( ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;
        if (i!=VHQt_N-1) H="; ";
        VHQt_Result+=QString::number(VHQt_Vector[i])+H;
    }

    VHQt_Result+="\\right)^\\mathrm{T}.\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------

//*****************************************************************
//Составные изображения
//*****************************************************************
//*****************************************************************
//Таблицы
//*****************************************************************
//*****************************************************************
//Текст
//*****************************************************************
template <class T> QString THQt_LatexShowNumber (T VHQt_X, QString TitleX, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с Latex кодами.
    Входные параметры:
     VHQt_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n"+TitleX+":\n";
    VHQt_Result+="\\begin{equation}\n";
    VHQt_Result+=NameX+" = " + QString::number(VHQt_X) + ".\n";
    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowNumber (T VHQt_X, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с Latex кодами.
    Входные параметры:
     VHQt_X - выводимое число;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+=NameX+" = " + QString::number(VHQt_X) + ".\n";
    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowNumber (T VHQt_X)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с Latex кодами.
    Входные параметры:
     VHQt_X - выводимое число.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="x = " + QString::number(VHQt_X) + ".\n";
    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------

#endif // HARRIXQTLIBRARYFORLATEX_H
