template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N,"Тестовый график","x","y","количество деревьев","количество домов",true,true,true,true);

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VMHL_Result;//переменная итогового результата
    int i,j;

    //цвета
    QString CoordinateColor="#88969c";

    QString Color="#97bbcd";
    QString HighlightColor="#3c7693";

    QString Color2="#cccccc";
    QString HighlightColor2="#7e7e7e";

    //посчитаем гарницы изменения параметров
    T MinX=VMHL_VectorX[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorX[i]<MinX)
            MinX=VMHL_VectorX[i];

    T MinY1=VMHL_VectorY1[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY1[i]<MinY1)
            MinY1=VMHL_VectorY1[i];

    T MinY2=VMHL_VectorY2[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY2[i]<MinY2)
            MinY2=VMHL_VectorY2[i];

    T MaxX=VMHL_VectorX[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorX[i]>MaxX)
            MaxX=VMHL_VectorX[i];

    T MaxY1=VMHL_VectorY1[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY1[i]>MaxY1)
            MaxY1=VMHL_VectorY1[i];

    T MaxY2=VMHL_VectorY2[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY2[i]>MaxY2)
            MaxY2=VMHL_VectorY2[i];

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
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

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

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VMHL_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VMHL_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX="DataX"+UniqueName;
    QString NameDataY1="DataY1"+UniqueName;
    QString NameDataY2="DataY2"+UniqueName;
    QString NameDataXArea="DataXArea"+UniqueName;
    QString NameDataY1Area="DataY1Area"+UniqueName;
    QString NameDataY2Area="DataY2Area"+UniqueName;
    QString NameChart1="Chart1"+UniqueName;
    QString NameChart2="Chart2"+UniqueName;

    //рисуем область графика и оси
    VMHL_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VMHL_Result+="<script type=\"text/javascript\">\n";
    VMHL_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VMHL_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VMHL_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VMHL_VectorX=new T[VMHL_N];
    T *Temp_VMHL_VectorY1=new T[VMHL_N];
    T *Temp_VMHL_VectorY2=new T[VMHL_N];
    for (i=0;i<VMHL_N;i++) Temp_VMHL_VectorX[i]=VMHL_VectorX[i];
    for (i=0;i<VMHL_N;i++) Temp_VMHL_VectorY1[i]=VMHL_VectorY1[i];
    for (i=0;i<VMHL_N;i++) Temp_VMHL_VectorY2[i]=VMHL_VectorY2[i];

    //отсортируем массивы
    for(i=VMHL_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VMHL_VectorX[j]>Temp_VMHL_VectorX[j+1])
            {
                T x;
                x=Temp_VMHL_VectorX[j+1];
                Temp_VMHL_VectorX[j+1]=Temp_VMHL_VectorX[j];
                Temp_VMHL_VectorX[j]=x;
                x=Temp_VMHL_VectorY1[j+1];
                Temp_VMHL_VectorY1[j+1]=Temp_VMHL_VectorY1[j];
                Temp_VMHL_VectorY1[j]=x;
                x=Temp_VMHL_VectorY2[j+1];
                Temp_VMHL_VectorY2[j+1]=Temp_VMHL_VectorY2[j];
                Temp_VMHL_VectorY2[j]=x;
            }

    //соберем в массивы javascript данные точек
    QString SDataX;
    QString SDataY1;
    QString SDataY2;
    for (i=0;i<VMHL_N-1;i++)
        SDataX+=QString::number(Temp_VMHL_VectorX[i])+", ";
    SDataX+=QString::number(Temp_VMHL_VectorX[VMHL_N-1]);
    for (i=0;i<VMHL_N-1;i++)
        SDataY1+=QString::number(Temp_VMHL_VectorY1[i])+", ";
    SDataY1+=QString::number(Temp_VMHL_VectorY1[VMHL_N-1]);

    for (i=0;i<VMHL_N-1;i++)
        SDataY2+=QString::number(Temp_VMHL_VectorY2[i])+", ";
    SDataY2+=QString::number(Temp_VMHL_VectorY2[VMHL_N-1]);

    //запишем массивы точек
    VMHL_Result+="var "+NameDataX+" = ["+SDataX+"];\n";
    VMHL_Result+="var "+NameDataY1+" = ["+SDataY1+"];\n";
    VMHL_Result+="var "+NameDataY2+" = ["+SDataY2+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX=QString::number(MinX)+", "+SDataX+", "+QString::number(MaxX)+", "+QString::number(MinX);
        SDataY1=SBeginYAxis+", "+SDataY1+", "+SBeginYAxis+", "+SBeginYAxis;
        SDataY2=SBeginYAxis+", "+SDataY2+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VMHL_Result+="var "+NameDataXArea+" = ["+SDataX+"];\n";
        VMHL_Result+="var "+NameDataY1Area+" = ["+SDataY1+"];\n";
        VMHL_Result+="var "+NameDataY2Area+" = ["+SDataY2+"];\n";
        VMHL_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataY2Area+"],{strokeColor:'"+Color2+"',highlightStrokeColor:'"+Color2+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color2+"',highlightFillColor:'"+Color2+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
        VMHL_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataY1Area+"],{strokeColor:'"+Color+"',highlightStrokeColor:'"+Color+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color+"',highlightFillColor:'"+Color+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";

        //Нарисуем график
        VMHL_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";

        //Нарисуем точки
        VMHL_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию 2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY2+"], {chartStyle:'line'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";

        //Нарисуем только линию
        VMHL_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY1+"], {chartStyle:'line'});\n";
        VMHL_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VMHL_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VMHL_Result+="</script>\n";

    // ЛЕГЕНДА
    if ((!(NameLine1.trimmed().isEmpty()))&& (!(NameLine2.trimmed().isEmpty())))
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;
        QString NameDataY1Legend="DataY1Legend"+UniqueNameLegend;
        QString NameDataY2Legend="DataY2Legend"+UniqueNameLegend;
        QString NameChart1Legend="Chart1Legend"+UniqueNameLegend;
        QString NameChart2Legend="Chart2Legend"+UniqueNameLegend;
        QString NameText1Legend="Text1Legend"+UniqueName;
        QString NameText2Legend="Text2Legend"+UniqueName;


        //рисуем область графика и оси
        VMHL_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:100px;\"></div>\n";
        VMHL_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox="3";
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VMHL_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        SDataX="1, 2";
        SDataY1="2, 2";
        SDataY2="1, 1";

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            SDataY1="2, 2, 2";
            SDataY2="1, 1, 1";
        }

        //запишем массивы точек
        VMHL_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        VMHL_Result+="var "+NameDataY1Legend+" = ["+SDataY1+"];\n";
        VMHL_Result+="var "+NameDataY2Legend+" = ["+SDataY2+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            VMHL_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";

            //Нарисуем график2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";
        }
        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            VMHL_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";

            //Нарисуем точки2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";
        }
        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            VMHL_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line'});\n";
            VMHL_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";

            //Нарисуем только линию 2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        }

        //напишем текст
        VMHL_Result+=NameText1Legend+" = "+NameBoardLegend+".create('text',[2.2,2, \"- "+NameLine1+";\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        VMHL_Result+=NameText2Legend+" = "+NameBoardLegend+".create('text',[2.2,1, \"- "+NameLine2+".\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";

        VMHL_Result+="</script>\n";
    }

    delete [] Temp_VMHL_VectorX;
    delete [] Temp_VMHL_VectorY1;
    delete [] Temp_VMHL_VectorY2;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается отсуствием параметров NameLine1 и NameLine2. То есть нет легенды у графика.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N,"Тестовый график","x","y",true,true,true,true);

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoChartsOfLine (VMHL_VectorX,VMHL_VectorY1,VMHL_VectorY2, VMHL_N,TitleChart,NameVectorX, NameVectorY,"", "",ShowLine,ShowPoints,ShowArea, ShowSpecPoints);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевских переменных - все по умолчанию.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N,"Тестовый график","x","y","количество деревьев","количество домов");

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoChartsOfLine (VMHL_VectorX,VMHL_VectorY1,VMHL_VectorY2, VMHL_N, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2,true,true,true,true);

}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевских переменных и названий графика, осей, линий - все по умолчанию.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N);

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoChartsOfLine (VMHL_VectorX,VMHL_VectorY1,VMHL_VectorY2, VMHL_N, "", "x", "y", "", "",true,true,true,true);
}