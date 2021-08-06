void HarrixClass_DataOfHarrixOptimizationTesting::makingAnalysis()
{
    /*
    Выполняет анализ считанных данных. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    for (int i=0;i<Data.getNumberOfExperiments();i++)
    {
        //заполним значениями вектор средних значений критериев и дисперсий
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
        {
            Data.setMeanEx(Data.getMeanEx(i)+Data.getErrorEx(i,j),i);
            Data.setMeanEy(Data.getMeanEy(i)+Data.getErrorEy(i,j),i);
            Data.setMeanR (Data.getMeanR (i)+Data.getErrorR (i,j),i);

            //для общих дисперсий
            Data.setMeanOfAllEx(Data.getMeanOfAllEx()+Data.getErrorEx(i,j));
            Data.setMeanOfAllEy(Data.getMeanOfAllEy()+Data.getErrorEy(i,j));
            Data.setMeanOfAllR (Data.getMeanOfAllR ()+Data.getErrorR (i,j));
        }
        Data.setMeanEx(Data.getMeanEx(i)/double(Data.getNumberOfMeasuring()),i);
        Data.setMeanEy(Data.getMeanEy(i)/double(Data.getNumberOfMeasuring()),i);
        Data.setMeanR (Data.getMeanR (i)/double(Data.getNumberOfMeasuring()),i);

        Data.setVarianceOfEx(0,i);
        Data.setVarianceOfEy(0,i);
        Data.setVarianceOfR (0,i);
        double sd;
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
        {
            sd=(Data.getErrorEx(i,j)-Data.getMeanEx(i))*(Data.getErrorEx(i,j)-Data.getMeanEx(i));
            Data.setVarianceOfEx(Data.getVarianceOfEx(i)+sd,i);
            sd=(Data.getErrorEy(i,j)-Data.getMeanEy(i))*(Data.getErrorEy(i,j)-Data.getMeanEy(i));
            Data.setVarianceOfEy(Data.getVarianceOfEy(i)+sd,i);
            sd=(Data.getErrorR(i,j) -Data.getMeanR (i))*(Data.getErrorR(i,j) -Data.getMeanR (i));
            Data.setVarianceOfR(Data.getVarianceOfR(i)+sd,i);
        }
        Data.setVarianceOfEx(Data.getVarianceOfEx(i)/double(Data.getNumberOfMeasuring()-1),i);
        Data.setVarianceOfEy(Data.getVarianceOfEy(i)/double(Data.getNumberOfMeasuring()-1),i);
        Data.setVarianceOfR (Data.getVarianceOfR (i)/double(Data.getNumberOfMeasuring()-1),i);
    }

    //посчитаем общие средние значения
    Data.setMeanOfAllEx(Data.getMeanOfAllEx()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()));
    Data.setMeanOfAllEy(Data.getMeanOfAllEy()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()));
    Data.setMeanOfAllR (Data.getMeanOfAllR ()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()));

    double sd;
    //посчитаем дисперсии
    for (int i=0;i<Data.getNumberOfExperiments();i++)
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
        {
            sd=(Data.getErrorEx(i,j)-Data.getMeanOfAllEx())*(Data.getErrorEx(i,j)-Data.getMeanOfAllEx());
            Data.setVarianceOfAllEx(Data.getVarianceOfAllEx()+sd);
            sd=(Data.getErrorEy(i,j)-Data.getMeanOfAllEy())*(Data.getErrorEy(i,j)-Data.getMeanOfAllEy());
            Data.setVarianceOfAllEy(Data.getVarianceOfAllEy()+sd);
            sd=(Data.getErrorR(i,j) -Data.getMeanOfAllR() )*(Data.getErrorR(i,j) -Data.getMeanOfAllR() );
            Data.setVarianceOfAllR (Data.getVarianceOfAllR ()+sd);
        }
    Data.setVarianceOfAllEx(Data.getVarianceOfAllEx()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()-1));
    Data.setVarianceOfAllEy(Data.getVarianceOfAllEy()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()-1));
    Data.setVarianceOfAllR (Data.getVarianceOfAllR ()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()-1));
}