#ifndef HARRIXCLASS_HARRIXDATA_H
#define HARRIXCLASS_HARRIXDATA_H

#include <QFile>
#include <QStringList>
#include <QString>

class HarrixClass_HarrixData
{
public:
    HarrixClass_HarrixData(QString filename);
    ~HarrixClass_HarrixData();

    QString getChartLatexCode ();//получить код Latex по отображению того или иного графика
    QString getChartHtmlCode ();//получить код Html по отображению того или иного графика
    QString getErrorLatex ();//получить код Latex ошибок, которые накопились при считывании
    QString getErrorHtml ();//получить код Html ошибок, которые накопились при считывании

private:
    QStringList List;//сюда считываем наш файл (после конструктора тут только данные находятся)
    QStringList ListNamesOfCharts;//список названий столбцов или линий (согласно считываемому типу)

    QString ErrorLatex;//Переменная для сохарнения сообщений об ошибках в формате Latex
    QString ErrorHtml;//Переменная для сохарнения сообщений об ошибках в формате Html

    //считываемые параметры
    QString Type;//тип формат данных, содержащихся в данном файле
    QString Title;//название данного набора данных или графика
    QString AxisX;//название оси Ox для отображения на графике
    QString AxisY;//название оси Oy для отображения на графике
    QString AxisZ;//название оси Oz для отображения на графике
    bool ShowLine;//графики будут отображаться в виде линий
    bool ShowPoints;//графики будут отображаться в виде точек
    bool ShowArea;//под графиком будет показываться закрашенная область
    bool ShowSpecPoints;//показывать на графике специальные точки-метки: начальную точку, максимальные и минимальные значения
    bool RedLine;//показывать на графике линию красного цвета
    bool MinZero;//гистограмму начинать с нуля (true) или с минимального значения

    //Массивы для считываемых данных по типам данных
    //Type=="Line"
    int N;//кjличество точек
    double *dataX;//данные коодинат по оси Ox
    double *dataY;//данные коодинат по оси Oy

    //Type=="TwoLines
    //int N;//количество точек
    //double *dataX;//данные коодинат по оси Ox
    double *dataY1;//данные коодинат по оси Oy первой линии
    double *dataY2;//данные коодинат по оси Ox второй линии

    //Type=="TwoIndependentLines"
    int NX1;//количество точек первой линии
    int NY1;//количество точек первой линии Зачем ввел разные переменные?
    int NX2;//количество точек второй линии
    int NY2;//количество точек второй линии Зачем ввел разные переменные?
    double *dataX1;//данные коодинат по оси Ox первой линии
    //double *dataY1;//данные коодинат по оси Oy первой линии
    double *dataX2;//данные коодинат по оси Ox второй линии
    //double *dataY2;//данные коодинат по оси Oy второй линии

    //Type=="SeveralLines
    //int N;//количество элементов
    int M;//количество столбцов
    int *N_EveryCol;//Сколько точек содержится в каждом столбце
    double **X;//матрица данных
    QString *NameLine;//названия каждого столбца
    bool GrayStyle;//рисовать ли серым графики

    //Type=="SeveralIndependentLines"
    //int N;//количество элементов
    //int M;//количество столбцов
    //int *N_EveryCol;//Сколько точек содержится в каждом столбце
    //double **X;//матрица данных
    //QString *NameLine;//названия каждого столбца
    //bool GrayStyle;//рисовать ли серым графики

    //Type=="PointsAndLine"
    //int NX1;//количество точек первой линии
    //int NY1;//количество точек первой линии Зачем ввел разные переменные?
    //int NX2;//количество точек второй линии
    //int NY2;//количество точек второй линии Зачем ввел разные переменные?
    //double *dataX1;//данные коодинат по оси Ox первой линии
    //double *dataY1;//данные коодинат по оси Oy первой линии
    //double *dataX2;//данные коодинат по оси Ox второй линии
    //double *dataY2;//данные коодинат по оси Oy второй линии

    //Type=="Bar"
    //int N;//количество столбцов
    double *data;//значения высоты столбцов

    //Type=="3DPoints"
    //int N;//количество точек
    //double *dataX;//данные коодинат по оси Ox
    //double *dataY;//данные коодинат по оси Oy
    double *dataZ;//данные коодинат по оси Oz
};

#endif // HARRIXCLASS_HARRIXDATA_H
