QString HarrixClass_DataOfHarrixOptimizationTesting::makingLatexTable2D(QString Title, QStringList InfoForEveryExperiment)
{
    /*
    Создает текст LaTeX в виде таблицы 2D для всех экспериментов для отображения какой-нибудь информации.
    Входные параметры:
     Title - заголовок таблицы;
     InfoForEvryExperiment - информация выдаваемая в таблицу.
    Возвращаемое значение:
     Итоговая таблица в виде кода Latex.
     */
    QString Table;

    ////////////////////////////////////////////////////////
    //// ОПРЕДЕЛИМ В КАКОМ ПОРЯДКЕ И ГДЕ БУДУТ ИДТИ СТОЛБЦЫ
    ////////////////////////////////////////////////////////
    //Сколько у нас вообще параметров
    int NumberOfParametersTemp = getNumberOfParameters();

    if (NumberOfParametersTemp>0)
    {
        //массив для числа каждого параметры
        int *CountOfParametersTemp = new int [NumberOfParametersTemp];
        for (int i=0;i<NumberOfParametersTemp; i++)
            CountOfParametersTemp[i]=Data.getListOfParameterOptions(i).count();
        //в каком порядке будем располагать
        int *Order = new int [NumberOfParametersTemp];

        //Определим сколько параметров пойдет на столбцы, а сколько на строки
        int Limit=10;//сколько максимум столбцов с данными
        //сколько параметров будет в виде столбов
        int ForColsN = HML_SeparateVectorLimitOnProductElementsTwo(CountOfParametersTemp, Order, Limit, NumberOfParametersTemp);
        if (ForColsN==-1)
        {
            //Если слишком много элементов в каждом варианте, то берем самый маленький и только один
            //Пусть коряво будет, но хоть что-то будет
            HML_ReverseVector(Order,NumberOfParametersTemp);
            ForColsN = 1;
        }
        //А если все параметры решились по верхней части разместиться? Хотя бы один сместим на вертикальную часть
        if (ForColsN==NumberOfParametersTemp)
        {
            ForColsN--;
        }


        //Во второй части массива Order элементы расположим по длине текста
        int *CountForSubOrder = new int[NumberOfParametersTemp-ForColsN];
        int *SubOrder = new int[NumberOfParametersTemp-ForColsN];
        for (int i=0;i<NumberOfParametersTemp-ForColsN;i++)
        {
            SubOrder[i] = Order[i+ForColsN];
            CountForSubOrder[i] = Data.getOptionFromListOfParameterOptionsForTable(Order[i+ForColsN],0).length();
            for (int j=0;j<CountOfParametersTemp[Order[i+ForColsN]];j++)
            {
                QString Temp = Data.getOptionFromListOfParameterOptionsForTable(Order[i+ForColsN],j);
                if (Temp.length()>CountForSubOrder[i]) CountForSubOrder[i] = Temp.length();
            }
        }
        HML_BubbleSortWithConjugateVector(CountForSubOrder, SubOrder, NumberOfParametersTemp-ForColsN);
        for (int i=0;i<NumberOfParametersTemp-ForColsN;i++)
        {
            Order[i+ForColsN]=SubOrder[i];
        }
        delete [] CountForSubOrder;
        delete [] SubOrder;

        //Число столбов для контента
        int ColsForContent=1;
        for (int i=0;i<ForColsN;i++)
            ColsForContent*=Data.getListOfParameterOptions(Order[i]).count();

        //Число строк для контента
        int RowsForContent=1;
        for (int i=ForColsN;i<NumberOfParametersTemp;i++)
            RowsForContent*=Data.getListOfParameterOptions(Order[i]).count();

        //Число столбов для заголовков (слева)
        int ColsForHeader=NumberOfParametersTemp-ForColsN;
        //Число строк для заголовков (наверху)
        int RowsForHeader=ForColsN;

        ////////////////////////////////////////////////////////
        //// РИСУЕМ ВЕРХНИЕ ЗАГОЛОВКИ
        ////////////////////////////////////////////////////////
        //Начинаем отрисовывать таблицу
        Table+="\\begin{center}\n";
        Table+="{\n";
        Table+="\\renewcommand{\\arraystretch}{2}\n";

        double WidthCol=1./double(ColsForHeader+ColsForContent);

        Table+="\\tiny\n\\begin{longtable}[H]{";
        for (int i=0;i<ColsForHeader;i++)
        {
            QString Type="p";
            //if (i==ColsForHeader-1) Type="m";
            Table+="|"+Type+"{\\dimexpr"+QString::number(WidthCol)+"\\linewidth-2\\tabcolsep}";
        }
        for (int i=0;i<ColsForContent;i++)
            Table+="|p{\\dimexpr"+QString::number(WidthCol)+"\\linewidth-2\\tabcolsep}";
        Table+="|}\n";

        Table+="\\caption{"+Title+"}\n";

        int TempC=Data.getListOfParameterOptions(Order[0]).count();
        for (int j=0;j<RowsForHeader;j++)
        {
            Table+="\\tabularnewline\\cline{"+QString::number(ColsForHeader+1)+"-"+QString::number(ColsForContent+ColsForHeader)+"}\n";
            Table+="\\multicolumn{"+QString::number(ColsForHeader)+"}{c|} {\\centering \\textbf{ }} & ";

            for (int i=0;i<TempC;i++)
            {
                QString Amper;
                if (i!=TempC-1)
                    Amper=" & ";

                //Получим название настройки алгоритма оптимизации
                QString Text=HQt_ForcedWordWrap(Data.getOptionFromListOfParameterOptionsForTable(Order[j],i%(Data.getListOfParameterOptions(Order[j]).count())));

                if (j!=RowsForHeader-1)
                    Table+="\\multicolumn{"+QString::number(ColsForContent/TempC)+"}{c|} {\\centering \\textbf{"+Text+"}}"+Amper;
                else
                    Table+="\\multicolumn{"+QString::number(ColsForContent/TempC)+"}{p{\\dimexpr"+QString::number(WidthCol)+"\\linewidth-2\\tabcolsep}|} {\\centering \\textbf{"+Text+"}}"+Amper;
            }
            Table+="\n";
            TempC*=Data.getListOfParameterOptions(Order[j+1]).count();
        }

        Table+="\\tabularnewline\\hline\n";
        Table+="\\endhead\n";

        ////////////////////////////////////////////////////////
        //// ПОБОЧНЫЕ ДЕЙСТВИЯ С ТАБЛИЦЕЙ
        ////////////////////////////////////////////////////////

        //Оформляем «Продолжение следует», если не всё впорядке пойдет.
        Table+="\\hline\n\\multicolumn{"+QString::number(ColsForHeader+ColsForContent)+"}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
        Table+="\\endlastfoot\n";

        ////////////////////////////////////////////////////////
        //// ОСНОВОЕ ТЕЛО ТАБЛИЦЫ
        ////////////////////////////////////////////////////////

        int *WhatOptionInRow = new int [ColsForHeader];
        HML_FillVector(WhatOptionInRow,ColsForHeader,-1);

        int *WhatOptionInCol = new int [RowsForHeader];

        //Основное тело таблицы
        for (int j=0;j<RowsForContent;j++)
        {
            QString Row;
            //Заголовки слева

            ////////////////////////////////////////////////////////
            //// ЗАГОЛОВКИ СЛЕВА
            ////////////////////////////////////////////////////////

            //получим число всех вариантов настроек, отображаемых слева
            TempC=1;
            for (int i=0;i<ColsForHeader;i++)
                TempC*=Data.getListOfParameterOptions(Order[ForColsN+i]).count();

            int k=-1;//C какого номера на данной ячеейке начинать рисовать горизонтальную линию
            bool kDo=false;//значит, что еще не решали будет линия или нет
            for (int i=0;i<ColsForHeader;i++)
            {
                int uc=Data.getListOfParameterOptions(Order[ForColsN+i]).count();
                TempC = TempC/uc;
                int OO=j%TempC;
                if (OO==0)
                {
                    WhatOptionInRow[i]++;
                    if (WhatOptionInRow[i]==Data.getListOfParameterOptions(Order[ForColsN+i]).count())
                    {
                        WhatOptionInRow[i]=0;
                    }

                    QString Text=HQt_ForcedWordWrap(Data.getOptionFromListOfParameterOptionsForTable(Order[ForColsN+i],WhatOptionInRow[i]));

                    int dt;
                    dt=7.75*TempC;
                    if (i==ColsForHeader-1) dt=12.5*TempC;
                    //["+QString::number(dt)+"pt]

                    Row+="\\centering \\textbf{"+Text+"} & ";

                    //                if (TempC!=1)
                    //                    Row+="\\multirow{"+QString::number(TempC)+"}{\\linewidth}{\\centering \\textbf{"+Text+"}} & ";
                    //                else
                    //                    Row+="\\centering \\textbf{"+Text+"} & ";
                }
                else
                {
                    Row+=" & ";
                    if (OO==TempC-1)
                    {
                        if (kDo==false)
                        {
                            k=i+1;
                            kDo=true;
                        }
                    }
                }
            }
            if (k==-1) k=ColsForHeader;


            ////////////////////////////////////////////////////////
            //// ОСНОВНЫЕ ЯЧЕЙКИ
            ////////////////////////////////////////////////////////

            //Основное содержание
            HML_FillVector(WhatOptionInCol,RowsForHeader,-1);
            for (int i=0;i<ColsForContent;i++)
            {
                // i - номер столбца
                // j - номер строки
                //WhatOptionInRow[i] - номер i параметра по столбцам слева

                ////////////////////////////////////////////////////////
                //// ОПРЕДЕЛЯЕМ КАКИЕ ПАРАМЕТРЫ ПО СТОЛБЦАМ ИДУТ
                ////////////////////////////////////////////////////////
                {//Определяем какие параметры по столбцам идут
                    int TempC=Data.getListOfParameterOptions(Order[0]).count();
                    for (int k=0;k<RowsForHeader;k++)
                    {
                        int ii=0;
                        int wo;
                        for (int p=0;p<TempC;p++)
                        {
                            wo=p%(Data.getListOfParameterOptions(Order[k]).count());

                            for (int h=0;h<ColsForContent/TempC;h++)
                            {
                                if (ii==i)
                                {
                                    WhatOptionInCol[k]=wo;
                                }
                                ii++;
                            }
                        }
                        TempC*=Data.getListOfParameterOptions(Order[k+1]).count();
                    }
                }//Определяем какие параметры по столбцам идут

                ////////////////////////////////////////////////////////
                //// ОПРЕДЕЛЕНИЕ НОМЕРА ЭКПЕРИМЕНТА
                ////////////////////////////////////////////////////////
                int NumberExperimentInCell=-1;
                {//ОПРЕДЕЛЕНИЕ НОМЕРА ЭКПЕРИМЕНТА
                    // i - номер столбца
                    // j - номер строки

                    for (int p=0;p<Data.getNumberOfExperiments();p++)
                    {
                        bool find=true;
                        for (int k=0;k<ForColsN;k++)
                        {
                            if (WhatOptionInCol[k]!=Data.getParameter(p,Order[k]))
                                find=false;
                        }
                        for (int k=ForColsN;k<Data.getNumberOfParameters();k++)
                        {
                            if (WhatOptionInRow[k-ForColsN]!=Data.getParameter(p,Order[k]))
                                find=false;
                        }
                        if (find)
                        {
                            NumberExperimentInCell=p;
                        }
                    }

                    // NumberExperimentInCell -  теперь тут номер хранится
                }//ОПРЕДЕЛЕНИЕ НОМЕРА ЭКПЕРИМЕНТА

                ////////////////////////////////////////////////////////
                //// ОПРЕДЕЛЕНИЕ СОДЕРЖИМОГО ЯЧЕЙКИ
                ////////////////////////////////////////////////////////

                QString Content;

                Content = "\\centering " + InfoForEveryExperiment.at(NumberExperimentInCell);

                //Добавляем разделитель между ячейками
                QString Amper;
                if (i!=ColsForContent-1)
                    Amper=" & ";
                Row+=Content+Amper;

            }

            Row+="\\tabularnewline \\cline{"+QString::number(k)+"-"+QString::number(ColsForContent+ColsForHeader)+"}\n";
            Table+=Row;
        }

        Table+="\\end{longtable}\n";
        Table+="}\n";
        Table+="\\end{center}\n\n";


        delete [] CountOfParametersTemp;
        delete [] Order;
        delete [] WhatOptionInRow;
        delete [] WhatOptionInCol;
    }
    else
    {
    //Настраиваемых парметров у алгоритма нет, так что и ничего добавлять в таблицу
    }

    return Table;
}