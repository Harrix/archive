//HarrixClass_HarrixData
//Версия 1.2
//Класс для считывания информации формата данных Harrix Data на C++ для Qt.
//https://github.com/Harrix/HarrixClass_HarrixData
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixClass_HarrixData.h"
#include "HarrixQtLibrary.h"
#include "HarrixQtLibraryForLaTeX.h"
#include "HarrixQtLibraryForQWebView.h"

HarrixClass_HarrixData::HarrixClass_HarrixData(QString filename)
{
    /*
    Конструктор. Функция считывает данные о тестировании алгоритма оптимизации
    из файла формата HarrixData.
    Входные параметры:
     filename - полное имя считываемого файла.
 */
    try
    {
        if (HQt_GetExpFromFilename(filename)!="hdata")
        {
            ErrorLatex+=HQt_LatexShowAlert ("Расширение файла не *.hdata.");
            ErrorHtml +=HQt_ShowAlert ("Расширение файла не *.hdata.");
        }
        if (!HQt_FileExists(filename))
        {
            ErrorLatex+=HQt_LatexShowAlert ("Файл отсутствует.");
            ErrorHtml +=HQt_ShowAlert ("Файл отсутствует.");
        }

        List = HQt_ReadFileToQStringList(filename);

        if (List.isEmpty())
        {
            ErrorLatex+=HQt_LatexShowAlert ("Файл пустой.");
            ErrorHtml +=HQt_ShowAlert ("Файл пустой.");
        }

        QString String;

        String=List.at(0);

        if (HQt_TextBeforeEqualSign (String)!="HarrixFileFormat")
        {
            ErrorLatex+=HQt_LatexShowAlert ("Это не формат HarrixFileFormat.");
            ErrorHtml +=HQt_ShowAlert ("Это не формат HarrixFileFormat.");
        }
        if ((HQt_TextAfterEqualSign (String)!="Harrix Data 1.1")&&(HQt_TextAfterEqualSign (String)!="Harrix Data 1.0"))
        {
            ErrorLatex+=HQt_LatexShowAlert ("Это не версия Harrix Data 1.0 или 1.1.");
            ErrorHtml +=HQt_ShowAlert ("Это не версия Harrix Data 1.0 или 1.1.");
        }

        List.removeFirst();
        String=List.at(0);

        if (HQt_TextBeforeEqualSign (String)!="Site")
        {
            ErrorLatex+=HQt_LatexShowAlert ("Ошибка в структуре файла: нет второй строки в виде ссылки на сайт.");
            ErrorHtml +=HQt_ShowAlert ("Ошибка в структуре файла: нет второй строки в виде ссылки на сайт.");
        }
        if (HQt_TextAfterEqualSign (String)!="https://github.com/Harrix/HarrixFileFormats")
        {
            ErrorLatex+=HQt_LatexShowAlert ("Ошибка в структуре файла: сайт указан неверно во второй строке.");
            ErrorHtml +=HQt_ShowAlert ("Ошибка в структуре файла: сайт указан неверно во второй строке.");
        }

        if (ErrorLatex.isEmpty())
        {
            //параметры по умолчанию
            ShowLine=false;//графики будут отображаться в виде линий
            ShowPoints=false;//графики будут отображаться в виде точек
            ShowArea=false;//под графиком будет показываться закрашенная область
            ShowSpecPoints=false;//показывать на графике специальные точки-метки: начальную точку, максимальные и минимальные значения
            RedLine=false;//показывать на графике линию красного цвета
            MinZero=false;//гистограмму начинать с нуля (true) или с минимального значения

            //предварительные переменные
            QString TempType;
            QString TempTitle;
            QString TempAxisX;
            QString TempAxisY;
            QString TempAxisZ;
            QString TempParameters;

            QString After;
            QString Before;

            List.removeFirst();

            //проанализируем строчки на наличие тех переменных, которые могут быть необязательными
            int i=0;
            int n=List.count();
            while ((i<n)&&(String!="BeginNamesOfCharts")&&(String!="BeginData"))
            {
                String = List.at(i);
                Before = HQt_TextBeforeEqualSign (String);
                After  = HQt_TextAfterEqualSign (String);

                if (Before=="Type") TempType=After;
                if (Before=="Title") TempTitle=After;
                if (Before=="AxisX") TempAxisX=After;
                if (Before=="AxisY") TempAxisY=After;
                if (Before=="AxisZ") TempAxisZ=After;
                if (Before=="Parameters") TempParameters=After;
                i++;
            }

            for (int j=0;j<i-1;j++) List.removeFirst();//удалим строчки, которые проанализировали

            //А теперь сами переменные проанализируем
            Title=TempTitle;
            AxisX=TempAxisX;
            AxisY=TempAxisY;
            AxisZ=TempAxisZ;

            if (TempType=="Line") Type="Line";
            if (TempType=="TwoLines") Type="TwoLines";
            if (TempType=="TwoIndependentLines") Type="TwoIndependentLines";
            if (TempType=="SeveralIndependentLines") Type="SeveralIndependentLines";
            if (TempType=="SeveralLines") Type="SeveralLines";
            if (TempType=="PointsAndLine") Type="PointsAndLine";
            if (TempType=="Bar") Type="Bar";
            if (TempType=="3DPoints") Type="3DPoints";

            QStringList ListParameters = TempParameters.split( ",", QString::SkipEmptyParts );
            for (int j=0;j<ListParameters.count();j++)
            {
                String=ListParameters.at(j);
                String=String.trimmed();
                if (String=="ShowLine") ShowLine=true;
                if (String=="ShowPoints") ShowPoints=true;
                if (String=="ShowArea") ShowArea=true;
                if (String=="ShowSpecPoints") ShowSpecPoints=true;
                if (String=="RedLine") RedLine=true;
                if (String=="MinZero") MinZero=true;
            }

            if ((ShowLine==false)&&(ShowPoints==false)) ShowLine=true;


            //Теперь пытаемся поискать и обработать названия столбцов
            String=List.at(0);
            i=0;
            if (String=="BeginNamesOfCharts")
            {
                int n=List.count();
                while ((i<n)&&(String!="EndNamesOfCharts")&&(String!="BeginData"))
                {
                    String = List.at(i);

                    if ((String!="BeginNamesOfCharts")&&(String!="EndNamesOfCharts")&&(String!="BeginData")&&(String!="EndData"))
                        ListNamesOfCharts << String;

                    i++;
                }
            }

            for (int j=0;j<i;j++) List.removeFirst();//удалим строчки, которые проанализировали

            //Заберем данные непосредственно из файла
            String=List.at(0);
            if (String=="BeginData")
            {

                if (List.at(List.count()-1)!="EndData")
                {
                    ErrorLatex+=HQt_LatexShowAlert ("Ошибка в структуре файла: нет в конце строчки EndData.");
                    ErrorHtml +=HQt_ShowAlert ("Ошибка в структуре файла: нет в конце строчки EndData.");
                }
                List.removeFirst();
                List.removeLast();
                //теперь в List находится только нормальный объем данных
            }
            else
            {
                ErrorLatex+=HQt_LatexShowAlert ("Ошибка в структуре файла: нет строчки BeginData.");
                ErrorHtml +=HQt_ShowAlert ("Ошибка в структуре файла: нет строчки BeginData.");
            }

            //считываем данные
            if (ErrorLatex.isEmpty())
            {
                if (Type=="Line")
                {
                    N=HQt_CountOfRowsFromQStringList(List);
                    dataX=new double [N];
                    dataY=new double [N];
                    THQt_ReadTwoVectorFromQStringList(List,dataX,dataY);

                    if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
                }

                if (Type=="TwoLines")
                {
                    N=HQt_CountOfRowsFromQStringList(List);
                    dataX=new double [N];
                    dataY1=new double [N];
                    dataY2=new double [N];

                    THQt_ReadColFromQStringList(List,0,dataX);
                    THQt_ReadColFromQStringList(List,1,dataY1);
                    THQt_ReadColFromQStringList(List,2,dataY2);

                    if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
                    if (ListNamesOfCharts.count()<2) ListNamesOfCharts << "";
                }

                if (Type=="TwoIndependentLines")
                {
                    NX1=HQt_CountOfRowsFromQStringList(List,0);
                    NY1=HQt_CountOfRowsFromQStringList(List,1);
                    NX2=HQt_CountOfRowsFromQStringList(List,2);
                    NY2=HQt_CountOfRowsFromQStringList(List,3);
                    dataX1=new double [NX1];
                    dataY1=new double [NY1];
                    dataX2=new double [NX2];
                    dataY2=new double [NY2];

                    THQt_ReadColFromQStringList(List,0,dataX1);
                    THQt_ReadColFromQStringList(List,1,dataY1);
                    THQt_ReadColFromQStringList(List,2,dataX2);
                    THQt_ReadColFromQStringList(List,3,dataY2);

                    if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
                    if (ListNamesOfCharts.count()<2) ListNamesOfCharts << "";
                }

                if (Type=="SeveralLines")
                {
                    M=HQt_CountOfColsFromQStringList(List);

                    N_EveryCol=new int[M];

                    N=HQt_CountOfRowsFromQStringList(List,N_EveryCol);

                    X=new double*[N];
                    for (int i=0;i<N;i++) X[i]=new double[M];

                    THQt_ReadMatrixFromQStringList(List, X);

                    if (ListNamesOfCharts.count()<M-1)
                        for (int j=0;j<M-1-ListNamesOfCharts.count();j++) ListNamesOfCharts << "";

                    NameLine=new QString[M-1];
                    for (int i=0;i<M-1;i++)NameLine[i]=ListNamesOfCharts.at(i);

                    GrayStyle=false;
                    if (ShowArea) GrayStyle=true;
                }

                if (Type=="SeveralIndependentLines")
                {
                    M=HQt_CountOfColsFromQStringList(List);

                    N_EveryCol=new int[M];

                    N=HQt_CountOfRowsFromQStringList(List,N_EveryCol);

                    X=new double*[N];
                    for (int i=0;i<N;i++) X[i]=new double[M];

                    THQt_ReadMatrixFromQStringList(List, X);

                    if (ListNamesOfCharts.count()<M/2)
                        for (int j=0;j<M/2-ListNamesOfCharts.count();j++) ListNamesOfCharts << "";

                    NameLine=new QString[M/2];
                    for (int i=0;i<M/2;i++)NameLine[i]=ListNamesOfCharts.at(i);

                    GrayStyle=false;
                    if (ShowArea) GrayStyle=true;
                }

                if (Type=="PointsAndLine")
                {
                    NX1=HQt_CountOfRowsFromQStringList(List,0);
                    NY1=HQt_CountOfRowsFromQStringList(List,1);
                    NX2=HQt_CountOfRowsFromQStringList(List,2);
                    NY2=HQt_CountOfRowsFromQStringList(List,3);
                    dataX1=new double [NX1];
                    dataY1=new double [NY1];
                    dataX2=new double [NX2];
                    dataY2=new double [NY2];

                    THQt_ReadColFromQStringList(List,0,dataX1);
                    THQt_ReadColFromQStringList(List,1,dataY1);
                    THQt_ReadColFromQStringList(List,2,dataX2);
                    THQt_ReadColFromQStringList(List,3,dataY2);

                    if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
                    if (ListNamesOfCharts.count()<2) ListNamesOfCharts << "";
                }

                if (Type=="Bar")
                {
                    N=HQt_CountOfRowsFromQStringList(List);
                    data=new double [N];
                    THQt_ReadVectorFromQStringList(List,data);

                    if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
                }

                if (Type=="3DPoints")
                {
                    N=HQt_CountOfRowsFromQStringList(List,0);
                    dataX=new double [N];
                    dataY=new double [N];
                    dataZ=new double [N];

                    THQt_ReadColFromQStringList(List,0,dataX);
                    THQt_ReadColFromQStringList(List,1,dataY);
                    THQt_ReadColFromQStringList(List,2,dataZ);

                    if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
                }

                if (Type=="NPoints")
                {
                    M=HQt_CountOfColsFromQStringList(List);

                    N_EveryCol=new int[M];

                    N=HQt_CountOfRowsFromQStringList(List,N_EveryCol);

                    X=new double*[N];
                    for (int i=0;i<N;i++) X[i]=new double[M];

                    THQt_ReadMatrixFromQStringList(List, X);

                    if (ListNamesOfCharts.count()<M)
                        for (int j=0;j<M-1-ListNamesOfCharts.count();j++) ListNamesOfCharts << "";

                    NameLine=new QString[M];
                    for (int i=0;i<M;i++)NameLine[i]=ListNamesOfCharts.at(i);
                }
            }//if (ErrorLatex.isEmpty())

        }//if (ErrorLatex.isEmpty())

    }
    catch(...)
    {
        ErrorLatex+=HQt_LatexShowAlert ("Неизвестная ошибка.");
        ErrorHtml +=HQt_ShowAlert ("Неизвестная ошибка.");
    }
}
//---------------------------------------------------------------------------

HarrixClass_HarrixData::~HarrixClass_HarrixData()
{
    if ((Type=="Line")&&(ErrorLatex.isEmpty()))
    {
        delete []dataX;
        delete []dataY;
    }

    if ((Type=="TwoLines")&&(ErrorLatex.isEmpty()))
    {
        delete []dataX;
        delete []dataY1;
        delete []dataY2;
    }

    if ((Type=="TwoIndependentLines")&&(ErrorLatex.isEmpty()))
    {
        delete []dataX1;
        delete []dataX2;
        delete []dataY1;
        delete []dataY2;
    }

    if ((Type=="SeveralLines")&&(ErrorLatex.isEmpty()))
    {
        for (int i=0;i<N;i++) delete [] X[i];
        delete [] X;
        delete [] N_EveryCol;
        delete [] NameLine;
    }

    if ((Type=="SeveralIndependentLines")&&(ErrorLatex.isEmpty()))
    {
        for (int i=0;i<N;i++) delete [] X[i];
        delete [] X;
        delete [] N_EveryCol;
        delete [] NameLine;
    }

    if ((Type=="PointsAndLine")&&(ErrorLatex.isEmpty()))
    {
        delete []dataX1;
        delete []dataX2;
        delete []dataY1;
        delete []dataY2;
    }

    if ((Type=="Bar")&&(ErrorLatex.isEmpty()))
    {
        delete []data;
    }

    if ((Type=="3DPoints")&&(ErrorLatex.isEmpty()))
    {
        delete []dataX;
        delete []dataY;
        delete []dataZ;
    }
    if ((Type=="NPoints")&&(ErrorLatex.isEmpty()))
    {
        for (int i=0;i<N;i++) delete [] X[i];
        delete [] X;
        delete [] N_EveryCol;
        delete [] NameLine;
    }
}
//---------------------------------------------------------------------------

QString HarrixClass_HarrixData::getChartLatexCode ()
{
    /*
    Получить код Latex по отображению того или иного графика
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Код LaTeX графика
     */

    QString VMHL_Result;

    if (ErrorLatex.isEmpty())
    {
        if (Type=="Line")
        {
            VMHL_Result += THQt_LatexShowChartOfLine (dataX,dataY,N,Title,AxisX,AxisY,ListNamesOfCharts.at(0),"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints,RedLine,true);
        }
        if (Type=="TwoLines")
        {
            VMHL_Result += THQt_LatexShowTwoChartsOfLine (dataX,dataY1,dataY2,N,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints, true, true);
        }
        if (Type=="TwoIndependentLines")
        {
            VMHL_Result += THQt_LatexShowTwoIndependentChartsOfLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints, true, true);
        }
        if (Type=="SeveralLines")
        {
            VMHL_Result += THQt_LatexShowChartsOfLineFromMatrix (X,N,M,Title,AxisX,AxisY,NameLine,"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints, true, GrayStyle, false,false);
        }
        if (Type=="SeveralIndependentLines")
        {
            VMHL_Result += THQt_LatexShowIndependentChartsOfLineFromMatrix (X,N_EveryCol,M, Title,AxisX,AxisY,NameLine,"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints, true, GrayStyle, false,false);
        }
        if (Type=="PointsAndLine")
        {
            VMHL_Result += THQt_LatexShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints, true, false);
        }
        if (Type=="Bar")
        {
            VMHL_Result += THQt_LatexShowBar (data, N, Title, ListNamesOfCharts, AxisY, "Chart"+HQt_RandomString(8), true, MinZero);
        }
        if (Type=="3DPoints")
        {
            VMHL_Result +=THQt_LatexShow3DPlotPoints (dataX, dataY, dataZ, N, Title, AxisX, AxisY, AxisZ, "Chart"+HQt_RandomString(8), "mathcad",true);
        }
        if (Type=="NPoints")
        {
            VMHL_Result += HQt_LatexShowAlert ("Формат данных NPoints не поддерживается для вывода в график, так как данные представляют собой многомерную точку. Файлы данного формата предназначены для считывания данных, а не для отображения графика.");
        }

        if (VMHL_Result.isEmpty()) VMHL_Result +=ErrorLatex;
    }
    else
        VMHL_Result +=ErrorLatex;

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HarrixClass_HarrixData::getChartHtmlCode ()
{
    /*
    Получить код Html по отображению того или иного графика
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Код Html графика
     */

    QString VMHL_Result;

    if (ErrorLatex.isEmpty())
    {
        if (Type=="Line")
        {
            VMHL_Result += THQt_ShowChartOfLine (dataX,dataY,N,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ShowLine,ShowPoints,ShowArea,ShowSpecPoints,RedLine);
        }
        if (Type=="TwoLines")
        {
            VMHL_Result += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),ShowLine,ShowPoints,ShowArea,ShowSpecPoints);
        }
        if (Type=="TwoIndependentLines")
        {
            VMHL_Result += THQt_ShowTwoIndependentChartsOfLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),ShowLine,ShowPoints,ShowArea,ShowSpecPoints);
        }
        if (Type=="SeveralLines")
        {
            VMHL_Result += THQt_ShowChartsOfLineFromMatrix (X,N,M,Title,AxisX,AxisY,NameLine,ShowLine,ShowPoints,ShowArea,ShowSpecPoints);
        }
        if (Type=="SeveralIndependentLines")
        {
            VMHL_Result += THQt_ShowIndependentChartsOfLineFromMatrix (X,N_EveryCol,M, Title,AxisX,AxisY,NameLine,ShowLine,ShowPoints,ShowArea,ShowSpecPoints);
        }
        if (Type=="PointsAndLine")
        {
            VMHL_Result += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),ShowLine,ShowPoints,ShowArea,ShowSpecPoints);
        }
        if (Type=="Bar")
        {
            VMHL_Result += HQt_ShowAlert ("Формат данных Bar в текущей версии для отображения в HTML не поддерживается. <br>Отображение в формат кода LaTeX поддерживается.");
        }
        if (Type=="3DPoints")
        {
            VMHL_Result += HQt_ShowAlert ("Формат данных 3DPoints в текущей версии для отображения в HTML не поддерживается. <br> Отображение в формат кода LaTeX поддерживается.");
        }
        if (Type=="NPoints")
        {
            VMHL_Result += HQt_ShowAlert ("Формат данных NPoints не поддерживается для вывода в график, так как данные представляют собой многомерную точку.<br> Файлы данного формата предназначены для считывания данных, а не для отображения графика.");
        }

        if (VMHL_Result.isEmpty()) VMHL_Result +=ErrorHtml;
    }
    else
        VMHL_Result +=ErrorHtml;

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HarrixClass_HarrixData::getErrorLatex ()
{
    /*
    Получить код Latex по отображению ошибок,  которые накопились при считывании
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Код LaTeX графика.
     */

    QString VMHL_Result;

    VMHL_Result +=ErrorLatex;

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HarrixClass_HarrixData::getErrorHtml()
{
    /*
    Получить код Html по отображению ошибок,  которые накопились при считывании.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Код Html графика.
     */

    QString VMHL_Result;

    VMHL_Result +=ErrorHtml;

    return VMHL_Result;
}
//---------------------------------------------------------------------------

int HarrixClass_HarrixData::getNumberOfRows()
{
    /*
    Узнать сколько строчек данных содержится в файле.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Количество строчек данных, которое содержится в файле.
     */
    if (ErrorLatex.isEmpty())
    {
        if (Type=="Line")
        {
            return N;
        }

        if (Type=="TwoLines")
        {
            return N;
        }

        if (Type=="TwoIndependentLines")
        {
            int MaxN = NX1;

            if (NY1>MaxN) MaxN=NY1;
            if (NX2>MaxN) MaxN=NX2;
            if (NY2>MaxN) MaxN=NY2;

            return MaxN;
        }

        if (Type=="SeveralLines")
        {
            return N;
        }

        if (Type=="SeveralIndependentLines")
        {
            return N;
        }

        if (Type=="PointsAndLine")
        {
            int MaxN = NX1;

            if (NY1>MaxN) MaxN=NY1;
            if (NX2>MaxN) MaxN=NX2;
            if (NY2>MaxN) MaxN=NY2;

            return MaxN;
        }

        if (Type=="Bar")
        {
            return N;
        }

        if (Type=="3DPoints")
        {
            return N;
        }

        if (Type=="NDPoints")
        {
            return N;
        }
    }//if (ErrorLatex.isEmpty())

    return 0;
}
//---------------------------------------------------------------------------

int HarrixClass_HarrixData::getNumberOfCols()
{
    /*
    Узнать сколько столбцов данных содержится в файле.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Количество столбцов данных, которое содержится в файле.
     */
    if (ErrorLatex.isEmpty())
    {
        if (Type=="Line")
        {
            return 2;
        }

        if (Type=="TwoLines")
        {
            return 4;
        }

        if (Type=="TwoIndependentLines")
        {
            return 4;
        }

        if (Type=="SeveralLines")
        {
            return M;
        }

        if (Type=="SeveralIndependentLines")
        {
            return M;
        }

        if (Type=="PointsAndLine")
        {
            return 4;
        }

        if (Type=="Bar")
        {
            return 1;
        }

        if (Type=="3DPoints")
        {
            return 3;
        }

        if (Type=="NDPoints")
        {
            return M;
        }
    }//if (ErrorLatex.isEmpty())

    return 0;
}
//---------------------------------------------------------------------------

QString HarrixClass_HarrixData::getType()
{
    /*
    Узнать тип формата данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Название типа вормата данных.
     */
    return Type;
}
//---------------------------------------------------------------------------

int HarrixClass_HarrixData::getNumberElementsInCol(int j)
{
    /*
    Узнать сколько элементов содержится в данном столбце данных.
    Входные параметры:
     j - столбец в данных.
    Возвращаемое значение:
     Количество элементов данных, которое содержится в данном столбце данных.
     */
    if (ErrorLatex.isEmpty())
    {
        int MM=getNumberOfCols();

        if (j<0)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер столбца в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер столбца в данных указан неверно");
            return 0;
        }
        if (j>=MM)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер столбца в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер столбца в данных указан неверно");
            return 0;
        }

        if (Type=="Line")
        {
            return N;
        }

        if (Type=="TwoLines")
        {
            return N;
        }

        if (Type=="TwoIndependentLines")
        {
            if (j==0) return NX1;
            if (j==1) return NY1;
            if (j==2) return NX2;
            if (j==3) return NY2;
        }

        if (Type=="SeveralLines")
        {
            return N;
        }

        if (Type=="SeveralIndependentLines")
        {
            return N_EveryCol[j];
        }

        if (Type=="PointsAndLine")
        {
            if (j==0) return NX1;
            if (j==1) return NY1;
            if (j==2) return NX2;
            if (j==3) return NY2;
        }

        if (Type=="Bar")
        {
            return N;
        }

        if (Type=="3DPoints")
        {
            return N;
        }

        if (Type=="NPoints")
        {
            return N;
        }

    }//if (ErrorLatex.isEmpty())

    return 0;
}
//---------------------------------------------------------------------------

QString HarrixClass_HarrixData::getNameOfLine(int i)
{
    /*
    Получить имя данной линии или столбца согласно типу данных.
    Входные параметры:
     i - номер столбца в данных.
    Возвращаемое значение:
     Названия столбца или линии согласно типу данных.
     */
    if (ErrorLatex.isEmpty())
    {
        int MM=ListNamesOfCharts.count();

        if (i<0)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер столбца в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер столбца в данных указан неверно");
            return "NULL";
        }
        if (i>=MM)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер столбца в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер столбца в данных указан неверно");
            return "NULL";
        }

        QString Result;

        if (Type=="3DPoints")
        {
            Result=Title;
        }
        else
        {
            Result=ListNamesOfCharts.at(i);
        }

        return Result;

    }//if (ErrorLatex.isEmpty())

    ErrorLatex+=HQt_LatexShowAlert("Номер столбца в данных указан неверно");
    ErrorHtml+=HQt_ShowAlert("Номер столбца в данных указан неверно");

    return "NULL";
}
//---------------------------------------------------------------------------

double HarrixClass_HarrixData::getElementOfData(int i, int j)
{
    /*
    Получить значение элемента из данных согласно типу данных.
    Входные параметры:
     i - номер строки в данных;
     j - номер столбца в данных.
    Возвращаемое значение:
     Значение элемента данных.
     */
    if (ErrorLatex.isEmpty())
    {
        if (j<0)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер столбца в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер столбца в данных указан неверно");
            return 0;
        }
        if (j>=M)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер столбца в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер столбца в данных указан неверно");
            return 0;
        }

        int NN=getNumberElementsInCol(j);

        if (i<0)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер строки в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер строки в данных указан неверно");
            return 0;
        }
        if (i>=NN)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер строки в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер строки в данных указан неверно");
            return 0;
        }

        double ElementOfData=0;

        if (Type=="Line")
        {
            if (j==0) ElementOfData=dataX[i];
            if (j==1) ElementOfData=dataY[i];
        }

        if (Type=="TwoLines")
        {
            if (j==0) ElementOfData=dataX[i];
            if (j==1) ElementOfData=dataY1[i];
            if (j==2) ElementOfData=dataY2[i];
        }

        if (Type=="TwoIndependentLines")
        {
            if (j==0) ElementOfData=dataX1[i];
            if (j==1) ElementOfData=dataY1[i];
            if (j==2) ElementOfData=dataX2[i];
            if (j==3) ElementOfData=dataY2[i];
        }

        if (Type=="SeveralLines")
        {
            ElementOfData=X[i][j];
        }

        if (Type=="SeveralIndependentLines")
        {
            ElementOfData=X[i][j];
        }

        if (Type=="PointsAndLine")
        {
            if (j==0) ElementOfData=dataX1[i];
            if (j==1) ElementOfData=dataY1[i];
            if (j==2) ElementOfData=dataX2[i];
            if (j==3) ElementOfData=dataY2[i];
        }

        if (Type=="Bar")
        {
            ElementOfData=data[i];
        }

        if (Type=="3DPoints")
        {
            if (j==0) ElementOfData=dataX[i];
            if (j==1) ElementOfData=dataY[i];
            if (j==2) ElementOfData=dataZ[i];
        }

        if (Type=="NPoints")
        {
            ElementOfData=X[i][j];
        }

        return ElementOfData;

    }//if (ErrorLatex.isEmpty())

    ErrorLatex+=HQt_LatexShowAlert("Номер столбца или строки в данных указан неверно");
    ErrorHtml+=HQt_ShowAlert("Номер столбца или строки в данных указан неверно");

    return 0;
}
//---------------------------------------------------------------------------

QString HarrixClass_HarrixData::getAxisX()
{
    /*
    Узнать название оси Ox.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Название оси Ox.
     */
    return AxisX;
}
//---------------------------------------------------------------------------

QString HarrixClass_HarrixData::getAxisY()
{
    /*
    Узнать название оси Oy.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Название оси Oy.
     */
    return AxisY;
}
//---------------------------------------------------------------------------

QString HarrixClass_HarrixData::getAxisZ()
{
    /*
    Узнать название оси Oz.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Название оси Oz.
     */
    return AxisZ;
}
//---------------------------------------------------------------------------

QString HarrixClass_HarrixData::getTitle()
{
    /*
    Узнать название графика или набора данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Название графика или набора данных.
     */
    return Title;
}
//---------------------------------------------------------------------------

int HarrixClass_HarrixData::getNumberOfCharts()
{
    /*
    Cколько линий, поверхностей или наборов точек содержится в файле.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Количество линий, поверхностей или наборов точек содержится в файле.
     */
    if (ErrorLatex.isEmpty())
    {
        if (Type=="Line")
        {
            return 1;
        }

        if (Type=="TwoLines")
        {
            return 2;
        }

        if (Type=="TwoIndependentLines")
        {
            return 2;
        }

        if (Type=="SeveralLines")
        {
            return M-1;
        }

        if (Type=="SeveralIndependentLines")
        {
            return M/2;
        }

        if (Type=="PointsAndLine")
        {
            return 2;
        }

        if (Type=="Bar")
        {
            return 1;
        }

        if (Type=="3DPoints")
        {
            return 1;
        }

        if (Type=="NDPoints")
        {
            return 1;
        }
    }//if (ErrorLatex.isEmpty())

    return 0;
}
//---------------------------------------------------------------------------

int HarrixClass_HarrixData::getNumberCoordinateInChart()
{
    /*
    Cколько координат содержится в выбранной линии (и др.) в данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Количество координат содержится в выбранной линии (и др.) в данных.
     */
    if (ErrorLatex.isEmpty())
    {
        if (Type=="Line")
        {
            return 2;
        }

        if (Type=="TwoLines")
        {
            return 2;
        }

        if (Type=="TwoIndependentLines")
        {
            return 2;
        }

        if (Type=="SeveralLines")
        {
            return 2;
        }

        if (Type=="SeveralIndependentLines")
        {
            return 2;
        }

        if (Type=="PointsAndLine")
        {
            return 2;
        }

        if (Type=="Bar")
        {
            return 1;
        }

        if (Type=="3DPoints")
        {
            return 3;
        }

        if (Type=="NDPoints")
        {
            return M;
        }
    }//if (ErrorLatex.isEmpty())

    return 0;
}
//---------------------------------------------------------------------------

int HarrixClass_HarrixData::getNumberElementsInChart(int k)
{
    /*
    Сколько элементов (точек) содержится в выбранной линии (и др.) в данных.
    Чем отличается от getNumberElementsInCol? Там просто берутся данные как из таблицы по номеру строки и столба,
    бех учета их значения. Тут же получение координаты получается согласно семантики конкретного набора данных по его типу.
    Входные параметры:
     k - номер линии  (и др.).
    Возвращаемое значение:
     Количество элементов (точек) содержится в выбранной линии (и др.) в данных.
     */
    if (ErrorLatex.isEmpty())
    {
        int MM=getNumberOfCharts();

        if (k<0)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер линии (и др.) указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер линии (и др.) в данных указан неверно");
            return 0;
        }
        if (k>=MM)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер линии (и др.) указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер линии (и др.) указан неверно");
            return 0;
        }

        if (Type=="Line")
        {
            return N;
        }

        if (Type=="TwoLines")
        {
            return N;
        }

        if (Type=="TwoIndependentLines")
        {
            if (k==0) return NX1;
            if (k==1) return NX2;
        }

        if (Type=="SeveralLines")
        {
            return N;
        }

        if (Type=="SeveralIndependentLines")
        {
            return N_EveryCol[k*2];
        }

        if (Type=="PointsAndLine")
        {
            if (k==0) return NX1;
            if (k==1) return NX2;
        }

        if (Type=="Bar")
        {
            return N;
        }

        if (Type=="3DPoints")
        {
            return N;
        }

        if (Type=="NPoints")
        {
            return N;
        }
    }//if (ErrorLatex.isEmpty())

    return 0;
}
//---------------------------------------------------------------------------

double HarrixClass_HarrixData::getPointCoordinateOfData(int k, int i, int j)
{
    /*
    Получить значение координаты точки из данных.
    Чем отличается от getElementOfData? Там просто берутся данные как из таблицы по номеру строки и столба,
    бех учета их значения. Тут же получение координаты получается согласно семантики конкретного набора данных по его типу.
    Входные параметры:
     k - номер линии, графика, набора точек  (их количество смотри getNumberOfCharts());
     i - номер элемента в выбранной линии;
     j - номер координаты.
    Возвращаемое значение:
     Значение координаты точки из данных.
     */
    if (ErrorLatex.isEmpty())
    {
        int KK=getNumberOfCharts();

        if (k<0)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер линии (и др.) в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер линии (и др.) в данных указан неверно");
            return 0;
        }
        if (k>=KK)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер линии (и др.) в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер линии (и др.) в данных указан неверно");
            return 0;
        }

        int MM=getNumberCoordinateInChart();

        if (j<0)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер столбца в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер столбца в данных указан неверно");
            return 0;
        }
        if (j>=MM)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер столбца в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер столбца в данных указан неверно");
            return 0;
        }

        int NN=getNumberElementsInChart(k);

        if (i<0)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер элемента в линии указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер  элемента в линии указан неверно");
            return 0;
        }
        if (i>=NN)
        {
            ErrorLatex+=HQt_LatexShowAlert("Номер строки в данных указан неверно");
            ErrorHtml+=HQt_ShowAlert("Номер строки в данных указан неверно");
            return 0;
        }

        double ElementOfChart=0;

        if (Type=="Line")
        {
            if (j==0) ElementOfChart=dataX[i];
            if (j==1) ElementOfChart=dataY[i];
        }

        if (Type=="TwoLines")
        {
            if (k==0)
            {
                if (j==0) ElementOfChart=dataX[i];
                if (j==1) ElementOfChart=dataY1[i];
            }
            if (k==1)
            {
                if (j==0) ElementOfChart=dataX[i];
                if (j==1) ElementOfChart=dataY2[i];
            }
        }

        if (Type=="TwoIndependentLines")
        {
            if (k==0)
            {
                if (j==0) ElementOfChart=dataX1[i];
                if (j==1) ElementOfChart=dataY1[i];
            }
            if (k==1)
            {
                if (j==0) ElementOfChart=dataX2[i];
                if (j==1) ElementOfChart=dataY2[i];
            }
        }

        if (Type=="SeveralLines")
        {
            if (j==0) ElementOfChart=X[i][0];
            if (j==1) ElementOfChart=X[i][k+1];
        }

        if (Type=="SeveralIndependentLines")
        {
            if (j==0) ElementOfChart=X[i][2*k];
            if (j==1) ElementOfChart=X[i][2*k+1];
        }

        if (Type=="PointsAndLine")
        {
            if (k==0)
            {
                if (j==0) ElementOfChart=dataX1[i];
                if (j==1) ElementOfChart=dataY1[i];
            }
            if (k==1)
            {
                if (j==0) ElementOfChart=dataX2[i];
                if (j==1) ElementOfChart=dataY2[i];
            }
        }

        if (Type=="Bar")
        {
            ElementOfChart=data[i];
        }

        if (Type=="3DPoints")
        {
            if (j==0) ElementOfChart=dataX[i];
            if (j==1) ElementOfChart=dataY[i];
            if (j==2) ElementOfChart=dataZ[i];
        }

        if (Type=="NPoints")
        {
            ElementOfChart=X[i][j];
        }

        return ElementOfChart;

    }//if (ErrorLatex.isEmpty())

    ErrorLatex+=HQt_LatexShowAlert("Что-то неправильное вы спросили");
    ErrorHtml+=HQt_ShowAlert("Что-то неправильное вы спросили");

    return 0;
}
//---------------------------------------------------------------------------
