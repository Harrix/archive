void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexAnalysis()
{
    /*
    Создает текст LaTeX для отображения первоначального анализа данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexAnalysis, которую можно вызвать getLatexAnalysis.
     */
    LatexAnalysis+="\\subsection {Первоначальный анализ данных}\n\n";
    LatexAnalysis+="В данном разделе представлен первоначальный анализ данных исследования эффективности алгоритма оптимизации <<"+Data.getFullNameAlgorithm()+">> на рассматриваемой тестовой функции <<"+Data.getFullNameTestFunction()+">> (размерность "+QString::number(Data.getDimensionTestFunction())+"). ";
    if (Data.getNumberOfExperiments()==1)
    {
        //Алгоритм имеет только один эксперимент

        if (Data.getCheckAllCombinations()==true)
        {
            LatexAnalysis+="Исследуемый алгоритм оптимизации относится к алгоритмам множества варьируемых параметров самого алгоритма. Поэтому при исследовании алгоритма на тестовой функции надо было провести <<эксперимент>> только один раз (многократно его повторяя). Мы можем сделать полный анализ работы алгоритма в рассматриваемых условиях.\n\n";
        }
        else
        {
            LatexAnalysis+="Данное исследование является частичным, так как рассмотрено не всё множество возможных настроек алгоритма. Поэтому ниже будут представлены неполные выводы, так как при нерассмотренных настройках алгоритм мог показать себя лучше или хуже.\n\n";
        }
    }
    else
    {
        if (Data.getCheckAllCombinations()==true)
        {
            LatexAnalysis+="При данном исследовании было рассмотрено всё множество возможных настроек алгоритма. Поэтому можно сделать полный анализ работы алгоритма в рассматриваемых условиях.\n\n";
        }
        else
        {
            LatexAnalysis+="Данное исследование является частичным, так как рассмотрено не всё множество возможных настроек алгоритма. Поэтому ниже будут представлены неполные выводы, так как при нерассмотренных настройках алгоритм мог показать себя лучше или хуже.\n\n";
        }

        LatexAnalysis+="В таблице ниже приведены значения характеристик эффективности алгоритма оптимизации на множестве всех проведенных экспериментов. На основании их можно ценить среднюю эффективность алгоритма.\n\n";

        QStringList Col1, Col2, Col3;
        Col1 << "Ошибка по входным параметрам, $E_x$";
        Col2 << QString::number(Data.getMeanOfAllEx());
        Col3 << QString::number(Data.getVarianceOfAllEx());

        Col1 << "Ошибка по значениям целевой функции, $E_y$";
        Col2 << QString::number(Data.getMeanOfAllEy());
        Col3 << QString::number(Data.getVarianceOfAllEy());

        Col1 << "Надёжность, $R$";
        Col2 << QString::number(Data.getMeanOfAllR());
        Col3 << QString::number(Data.getVarianceOfAllR());

        LatexAnalysis+=HQt_LatexShowTable (Col1, Col2, Col3, "Измеряемая характеристика", "Выборочное среднее", "Выборочная дисперсия", 60,20, "Значения характеристик эффективности алгоритма оптимизации на множестве всех проведенных экспериментов");

        LatexAnalysis+="Построим теперь графики характеристик эффективности алгоритма по выборочным средним для каждой комбинации настроек алгоритма оптимизации.\n\n";

        double *MOEx=new double[Data.getNumberOfExperiments()];
        for (int i=0;i<Data.getNumberOfExperiments();i++) MOEx[i]=Data.getMeanEx(i);
        LatexAnalysis += THQt_LatexShowChartOfLine (NumberOfListOfVectorParameterOptions, MOEx, Data.getNumberOfExperiments(), "Ошибка по входным параметрам по порядку номеров комбинаций", "N, Номер комбинации настроек", "E_x", "Ошибка по входным параметрам", "MeanOfEx"+HQt_RandomString(5), true, true, false, true, false , true);

        double *MOEy=new double[Data.getNumberOfExperiments()];
        for (int i=0;i<Data.getNumberOfExperiments();i++) MOEy[i]=Data.getMeanEy(i);
        LatexAnalysis += THQt_LatexShowChartOfLine (NumberOfListOfVectorParameterOptions, MOEy, Data.getNumberOfExperiments(), "Ошибка по значениям целевой функции по порядку номеров комбинаций", "N, Номер комбинации настроек", "E_y", "Ошибка по значениям целевой функции", "MeanOfEy"+HQt_RandomString(5), true, true, false, true, false , true);

        double *MOR=new double[Data.getNumberOfExperiments()];
        for (int i=0;i<Data.getNumberOfExperiments();i++) MOR[i]=Data.getMeanR(i);
        LatexAnalysis += THQt_LatexShowChartOfLine (NumberOfListOfVectorParameterOptions, MOR, Data.getNumberOfExperiments(), "Надёжность по порядку номеров комбинаций", "N, Номер комбинации настроек", "R", "Надёжность", "MeanOfR"+HQt_RandomString(5), true, true, false, true, false , true);

        int Temp;
        double Q;
        Q=0.2;

        int iBestEx = TMHL_NumberOfMinimumOfVector(MOEx,Data.getNumberOfExperiments());
        LatexAnalysis += "На основании этих графиков можно выделить оптимальные комбинации настроек алгоритмов.\n\n";
        LatexAnalysis += "В нашем случае относительно ошибки по входным параметра наименьшее значение наблюдается у комбинации настройки под номером "+QString::number(iBestEx+1)+", а именно: <<\\textbf{"+Data.getListOfVectorParameterOptions(iBestEx).trimmed()+"}>>. ";
        //Найдем те экмперименты, которые по критерию Вилкоксона не хуже, чем лучшее.
        double *BestExperimentEx = new double [Data.getNumberOfMeasuring()];
        double *TempExperimentEx = new double [Data.getNumberOfMeasuring()];
        int *NumbersBestEx= new int[Data.getNumberOfExperiments()];
        //Как минимум один эксперимент у нас уже есть
        NumbersBestEx[0] = iBestEx;
        int NumberOfBest=1;

        for (int j=0;j<Data.getNumberOfMeasuring();j++)
            BestExperimentEx[j] = Data.getErrorEx(iBestEx,j);

        for (int i=0;i<Data.getNumberOfExperiments();i++)
        {
            if (i!=iBestEx)
            {
                for (int j=0;j<Data.getNumberOfMeasuring();j++)
                    TempExperimentEx[j] = Data.getErrorEx(i,j);
                Temp = MHL_WilcoxonW(BestExperimentEx, TempExperimentEx, Data.getNumberOfMeasuring(), Data.getNumberOfMeasuring(), Q);
                if (Temp==1)
                {
                    NumbersBestEx[NumberOfBest] = i;
                    NumberOfBest++;
                }
            }
        }

        if (NumberOfBest>1)
        {
            LatexAnalysis += "При критерию Вилкосона при $Q="+QString::number(Q)+"$ есть другие комбинации настроек алгоритма, которые бы статистически не отличались от наилучшей комбинации, рассмотренной выше, в количестве "+QString::number(NumberOfBest-1)+" штук. ";
        }
        else
        {
            LatexAnalysis += "При критерию Вилкосона при $Q="+QString::number(Q)+"$ нет других комбинаций настроек алгоритма, которые бы статистически не отличались от наилучшей комбинации, рассмотренной выше. ";
        }

        LatexAnalysis += "В таблице ниже представлено множество лучших комбинаций настроек алгоритма по $Ex$.\n\n";

        Col1.clear();
        Col2.clear();

        for (int j=0;j<NumberOfBest;j++)
        {
            Col1 << QString::number(NumbersBestEx[j]);
            Col2 << Data.getListOfVectorParameterOptions(NumbersBestEx[j]).trimmed();
        }

        LatexAnalysis+=HQt_LatexShowTable (Col1, Col2, "№ эксперимента", "Комбинация настроек",20, "Множество лучших комбинаций настроек алгоритма по $Ex$");

        QStringList List;
        for (int i=0;i<Data.getNumberOfExperiments();i++)
            List <<QString::number(i+1);
        LatexAnalysis+=makingLatexTable2D("Номера настроек",List);


        QStringList InfoForEveryExperiment;
        for (int i=0;i<Data.getNumberOfExperiments();i++)
        {
//            if (TMHL_SearchElementInVector (NumbersBestEx, i, NumberOfBest)!=-1)
//                InfoForEveryExperiment <<HQt_LatexGreenText("\\checkmark");
//            else
//                InfoForEveryExperiment <<"-";
            InfoForEveryExperiment <<QString::number(Data.getMeanEx(i));
        }
        LatexAnalysis+=makingLatexTable2D("Ошибка по Ex",InfoForEveryExperiment);



        delete [] BestExperimentEx;
        delete [] TempExperimentEx;
        delete [] NumbersBestEx;


        delete [] MOEx;
        delete [] MOEy;
        delete [] MOR;

    }
}