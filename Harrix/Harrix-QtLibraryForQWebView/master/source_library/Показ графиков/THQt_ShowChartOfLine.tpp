template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - название первого графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
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
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y","линия",true,true,true,true,false);

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j;

    //цвета
    QString Color="#97bbcd";
    QString HighlightColor="#3c7693";
    QString CoordinateColor="#88969c";
    QString RedColor="#ff0000";
    QString HighlightRedColor="#8b0909";

    //посчитаем гарницы изменения параметров
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

    VHQt_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VHQt_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    //QString UniqueName=HQt_UniqueNameOnlyNumbers();
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX="DataX"+UniqueName;
    QString NameDataY="DataY"+UniqueName;
    QString NameDataXArea="DataXArea"+UniqueName;
    QString NameDataYArea="DataYArea"+UniqueName;
    QString NameChart="Chart"+UniqueName;


    //рисуем область графика и оси
    VHQt_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VHQt_Result+="<script type=\"text/javascript\">\n";
    VHQt_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VHQt_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VHQt_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";

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

    //соберем в массивы javascript данные точек
    QString SDataX;
    QString SDataY;
    for (i=0;i<VHQt_N-1;i++)
        SDataX+=QString::number(Temp_VHQt_VectorX[i])+", ";
    SDataX+=QString::number(Temp_VHQt_VectorX[VHQt_N-1]);
    for (i=0;i<VHQt_N-1;i++)
        SDataY+=QString::number(Temp_VHQt_VectorY[i])+", ";
    SDataY+=QString::number(Temp_VHQt_VectorY[VHQt_N-1]);

    //запишем массивы точек
    VHQt_Result+="var "+NameDataX+" = ["+SDataX+"];\n";
    VHQt_Result+="var "+NameDataY+" = ["+SDataY+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX=QString::number(MinX)+", "+SDataX+", "+QString::number(MaxX)+", "+QString::number(MinX);
        SDataY=SBeginYAxis+", "+SDataY+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VHQt_Result+="var "+NameDataXArea+" = ["+SDataX+"];\n";
        VHQt_Result+="var "+NameDataYArea+" = ["+SDataY+"];\n";
        if (!RedLine)
            VHQt_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataYArea+"],{strokeColor:'"+Color+"',highlightStrokeColor:'"+Color+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color+"',highlightFillColor:'"+Color+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
        else
            VHQt_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataYArea+"],{strokeColor:'"+RedColor+"',highlightStrokeColor:'"+RedColor+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+RedColor+"',highlightFillColor:'"+RedColor+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        VHQt_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line,point'});\n";
        if (!RedLine)
            VHQt_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        else
            VHQt_Result+=NameChart+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N)+";i++) \n";
        VHQt_Result+="    {\n";
        if (!RedLine)
            VHQt_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        else
            VHQt_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";

        VHQt_Result+="    }\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем график
        VHQt_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N)+";i++) \n";
        VHQt_Result+="    {\n";
        if (!RedLine)
            VHQt_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        else
            VHQt_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";
        VHQt_Result+="    }\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        VHQt_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line'});\n";
        if (!RedLine)
            VHQt_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        else
            VHQt_Result+=NameChart+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VHQt_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VHQt_Result+="</script>\n";

    // ЛЕГЕНДА
    if ((!(NameLine.trimmed().isEmpty())))
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;
        QString NameDataYLegend="DataYLegend"+UniqueNameLegend;
        QString NameChartLegend="ChartLegend"+UniqueNameLegend;
        QString NameTextLegend="TextLegend"+UniqueName;

        //рисуем область графика и оси
        VHQt_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:50px;\"></div>\n";
        VHQt_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox="2";
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VHQt_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        SDataX="1, 2";
        SDataY="1, 1";

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            SDataY="1, 1, 1";
        }

        //запишем массивы точек
        VHQt_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        VHQt_Result+="var "+NameDataYLegend+" = ["+SDataY+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            VHQt_Result+="var "+NameChartLegend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend+"], {chartStyle:'line,point'});\n";
            if (!RedLine)
                VHQt_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
            else
                VHQt_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VHQt_Result+="    {\n";
            if (!RedLine)
                VHQt_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            else
                VHQt_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";
            VHQt_Result+="    }\n";
        }
        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            VHQt_Result+="var "+NameChartLegend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VHQt_Result+="    {\n";
            if (!RedLine)
                VHQt_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            else
                VHQt_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";
            VHQt_Result+="    }\n";
        }
        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            VHQt_Result+="var "+NameChartLegend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend+"], {chartStyle:'line'});\n";
            if (!RedLine)
                VHQt_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
            else
                VHQt_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
        }

        //напишем текст
        VHQt_Result+=NameTextLegend+" = "+NameBoardLegend+".create('text',[2.2,1, \"- "+NameLine+".\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";

        VHQt_Result+="</script>\n";
    }

    delete [] Temp_VHQt_VectorX;
    delete [] Temp_VHQt_VectorY;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функцией отсутствием параметра NameLine(название первого графика (для легенды)).
    То есть не будет легенды у графика.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синию.
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
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y",true,true,true,true);

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowChartOfLine (VHQt_VectorX,VHQt_VectorY,VHQt_N,TitleChart,NameVectorX, NameVectorY, "", ShowLine, ShowPoints, ShowArea, ShowSpecPoints, RedLine);

}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функцией отсутствием булевских параметров в конце - все по умолчанию делается.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - название первого графика (для легенды).
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
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y","линия");

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowChartOfLine (VHQt_VectorX,VHQt_VectorY,VHQt_N,TitleChart,NameVectorX, NameVectorY, NameLine, true, true, true, true, false);

}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функцией отсутствием булевских параметров в конце и названий осей и графиков - для быстрого отображения графика без лишних телодвижений.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек.
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
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N);

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowChartOfLine (VHQt_VectorX,VHQt_VectorY,VHQt_N,"","x", "y", "", true, true, true, true, false);
}