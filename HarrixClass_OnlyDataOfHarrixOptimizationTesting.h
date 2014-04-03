//HarrixClass_DataOfHarrixOptimizationTesting
//Версия 1.21
//Класс для считывания информации формата данных Harrix Optimization Testing на C++ для Qt.
//https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#ifndef HARRIXCLASS_ONLYDATAOFHARRIXOPTIMIZATIONTESTING_H
#define HARRIXCLASS_ONLYDATAOFHARRIXOPTIMIZATIONTESTING_H

//Класс, который только содержит сырые данные исследований, которые считываются
//классом HarrixClass_DataOfHarrixOptimizationTesting. В данном классе нет ни проверки
//корректности ввода информации и др. Это служебный класс.
class HarrixClass_OnlyDataOfHarrixOptimizationTesting
{
public:
    HarrixClass_OnlyDataOfHarrixOptimizationTesting();
    ~HarrixClass_OnlyDataOfHarrixOptimizationTesting();
    void operator = (HarrixClass_OnlyDataOfHarrixOptimizationTesting& B);

    void memoryAllocation();//Выделяет память под необходимые массивы.
    void memoryDeallocation();//Удаляет память из-под массивов. Внутренняя функция.
    void initializationOfVariables();//Обнуление переменных. Внутренняя функция.

    QString getAuthor();//Получение текста переменной XML_Author - Автор документа
    void setAuthor(QString Author);//Задание текста переменной XML_Author - Автор документа
    QString getDate();//Получение текста переменной  XML_Date - Дата создания документа
    void setDate(QString Date);//Задание текста переменной  XML_Date - Дата создания документа
    QString getEmail();//Получение текста переменной  XML_Email - Email автора, чтобы можно было с ним связаться
    void setEmail(QString Email);//Задание текста переменной  XML_Email - Email автора, чтобы можно было с ним связаться
    QString getNameAlgorithm();//Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации
    void setNameAlgorithm(QString NameAlgorithm);//Задание текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации
    QString getFullNameAlgorithm();//Получение текста переменной  XML_Full_Name_Algorithm - Полное название алгоритма оптимизации
    void setFullNameAlgorithm(QString FullNameAlgorithm);//Задание текста переменной  XML_Full_Name_Algorithm - Полное название алгоритма оптимизации
    QString getNameTestFunction();//Получение текста переменной  XML_Name_Test_Function - Название тестовой функции
    void setNameTestFunction(QString NameTestFunction);//Задание текста переменной  XML_Name_Test_Function - Название тестовой функции
    QString getFullNameTestFunction();//Получение текста переменной  XML_Full_Name_Test_Function - Полное название тестовой функции
    void setFullNameTestFunction(QString FullNameTestFunction);//Задание текста переменной  XML_Full_Name_Test_Function - Полное название тестовой функции
    qint64 getDimensionTestFunction();//Получение текста переменной XML_DimensionTestFunction - Размерность тестовой задачи
    void setDimensionTestFunction(qint64 DimensionTestFunction);//Задание текста переменной XML_DimensionTestFunction - Размерность тестовой задачи
    qint64 getNumberOfMeasuring();//Получение текста переменной XML_Number_Of_Measuring - Размерность тестовой задачи (длина хромосомы решения)
    void setNumberOfMeasuring(qint64 NumberOfMeasuring);//Задание текста переменной XML_Number_Of_Measuring - Размерность тестовой задачи (длина хромосомы решения)
    qint64 getNumberOfRuns();//Получение текста переменной XML_Number_Of_Runs - Количество прогонов по которому делается усреднение для эксперимента
    void setNumberOfRuns(qint64 NumberOfRuns);//Задание текста переменной XML_Number_Of_Runs - Количество прогонов по которому делается усреднение для эксперимента
    qint64 getMaxCountOfFitness();//Получение текста переменной Max_Count_Of_Fitness - Максимальное допустимое число вычислений целевой функции для алгоритма
    void setMaxCountOfFitness(qint64 MaxCountOfFitness);//Задание текста переменной Max_Count_Of_Fitness - Максимальное допустимое число вычислений целевой функции для алгоритма
    qint64 getNumberOfParameters();//Получение текста переменной XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации
    void setNumberOfParameters(qint64 NumberOfParameters);//Задание текста переменной  XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации
    qint64 getNumberOfExperiments();//Получение текста переменной XML_Number_Of_Experiments - Количество комбинаций вариантов настроек
    void setNumberOfExperiments(qint64 NumberOfExperiments);//Задание текста переменной XML_Number_Of_Experiments - Количество комбинаций вариантов настроек
    QString getLinkTestFunction();//Получение текста переменной  XML_Link_Test_Function - Ссылка на описание тестовой функции
    void setLinkTestFunction(QString LinkTestFunction);//Задание текста переменной  XML_Link_Test_Function - Ссылка на описание тестовой функции
    QString getLinkAlgorithm();//Получение текста переменной  XML_Link_Algorithm - Ссылка на описание алгоритма оптимизации
    void setLinkAlgorithm(QString LinkAlgorithm);//Задание текста переменной  XML_Link_Algorithm - Ссылка на описание алгоритма оптимизации
    QString getFormat();//Получение переменной XML_Format, то есть возвращает название формата документа.
    void setFormat(QString Format);//Задание переменной XML_Format, то есть возвращает название формата документа.
    QString getVersion();//Получение переменной XML_Version, то есть возвращает версию формата документа.
    void setVersion(QString Version);//Задание переменной XML_Version, то есть возвращает версию формата документа.
    QString getLink();//Получение переменной XML_Link, то есть возвращает ссылку на описание формата файла.
    void setLink(QString Link);//Задание переменной XML_Link, то есть возвращает ссылку на описание формата файла.
    bool getCheckAllCombinations();//Получение текста переменной  XML_All_Combinations - Все ли комбинации вариантов настроек просмотрены: 0 или 1
    void setCheckAllCombinations(bool AllCombinations);//Задание текста переменной  XML_All_Combinations - Все ли комбинации вариантов настроек просмотрены: 0 или 1
    bool getSuccessReading();//Получение текста переменной SuccessReading - Успешно ли прошло считывание
    void setSuccessReading(bool Success);//Задание текста переменной SuccessReading - Успешно ли прошло считывание
    double getErrorEx(int Number_Of_Experiment, int Number_Of_Measuring);//Получение значения ошибки Ex.
    void setErrorEx(double ErrorEx,int Number_Of_Experiment, int Number_Of_Measuring);//Задание значения ошибки Ex.
    double getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring);//Получение значения ошибки Ey.
    void setErrorEy(double ErrorEx,int Number_Of_Experiment, int Number_Of_Measuring);//Задание значения ошибки Ey.
    double getErrorR(int Number_Of_Experiment, int Number_Of_Measuring);//Получение значения ошибки R.
    void setErrorR(double ErrorEx,int Number_Of_Experiment, int Number_Of_Measuring);//Задание значения ошибки R.
    int getParameter(int Number_Of_Experiment, int Number_Of_Parameter);//Получение значения параметра настройки какой-то.
    void setParameter(int Parameter, int Number_Of_Experiment, int Number_Of_Parameter);//Задание значения параметра настройки какой-то.
    QString getNameOption(int Number_Of_Parameter);//Получение имени параметра алгоритма по его номеру.
    void addNameOption(QString Option);//Добавление имени параметра алгоритма по его номеру.
    QStringList getNamesOfParameters();//Получение списка параметров алгоритма (тип селекции, тип скрещивания).
    QStringList getListOfParameterOptions(int Number_Of_Parameter);//Получение списка вектора названий вариантов параметров алгоритма оптимизации.
    QString getOptionFromListOfParameterOptions(int Number_Of_Parameter, int Number_Of_Option);//Получение названия вариантов параметров алгоритма оптимизации.
    void addListOfParameterOptions(QString Option, int Number_Of_Parameter);//Добавление списка вектора названий вариантов параметров алгоритма оптимизации.
    void setListOfParameterOptions(QStringList List, int Number_Of_Parameter);//Задание списка вектора названий вариантов параметров алгоритма оптимизации.
    double getNumberOfListOfVectorParameterOptions(int Number);//Получение значения элемента массива NumberOfListOfVectorParameterOptions
    void setNumberOfListOfVectorParameterOptions(double Num,int Number);//Задание значения элемента массива NumberOfListOfVectorParameterOptions
    QString getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter);//Получение значения параметра настройки какой-то в виде полного наименования.
    void addNameParameter(QString Name, int Number_Of_Experiment);//Получение значения параметра настройки какой-то в виде полного наименования.
    QStringList getListOfVectorParameterOptions();//Получение списка вектора названий вариантов параметров алгоритма оптимизации - это сборник строк из MatrixOfNameParameters, где объединены столбцы.
    QString getListOfVectorParameterOptions(int Number_Of_Experiment);//Получение строки параметров эксперимента из списка вектора названий вариантов параметров алгоритма оптимизации - это сборник строк из MatrixOfNameParameters, где объединены столбцы.
    void addListOfVectorParameterOptions(QString Option);//Добавление строки параметров эксперимента из списка вектора названий вариантов параметров алгоритма оптимизации - это сборник строк из MatrixOfNameParameters, где объединены столбцы.    
    double getMeanEx(int Number_Of_Experiment);//Получение среднего значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    void setMeanEx(double MeanEx, int Number_Of_Experiment);//Задание среднего значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    double getMeanEy(int Number_Of_Experiment);//Получение среднего значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    void setMeanEy(double MeanEy, int Number_Of_Experiment);//Задание среднего значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    double getMeanR(int Number_Of_Experiment);//Получение среднего значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).
    void setMeanR(double MeanR, int Number_Of_Experiment);//Задание среднего значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    double getVarianceOfEx(int Number_Of_Experiment);//Получение дисперсии значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    void setVarianceOfEx(double Variance, int Number_Of_Experiment);//Получение дисперсии значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    double getVarianceOfEy(int Number_Of_Experiment);//Получение дисперсии значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    void setVarianceOfEy(double Variance, int Number_Of_Experiment);//Получение дисперсии значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    double getVarianceOfR(int Number_Of_Experiment);//Получение дисперсии значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).
    void setVarianceOfR(double Variance, int Number_Of_Experiment);//Получение дисперсии значения ошибки R по измерениям для настройки (сколько точек было по столько и усредняем).
    double getMeanOfAllEx();//Получение значения переменной MeanOfAllEx - среднее значение ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще
    void setMeanOfAllEx(double Mean);//Задание значения переменной MeanOfAllEx - среднее значение ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще
    double getMeanOfAllEy();//Получение значения переменной MeanOfAllEy - среднее значение ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще
    void setMeanOfAllEy(double Mean);//Задание значения переменной MeanOfAllEy - среднее значение ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще
    double getMeanOfAllR();//Получение значения переменной MeanOfAllR - среднее значение надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще
    void setMeanOfAllR(double Mean);//Задание значения переменной MeanOfAllR - среднее значение надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще
    double getVarianceOfAllEx();//Получение значения переменной VarianceOfAllEx - дисперсия ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще
    void setVarianceOfAllEx(double Variance);//Задание значения переменной VarianceOfAllEx - дисперсия ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще
    double getVarianceOfAllEy();//Получение значения переменной VarianceOfAllEy - дисперсия ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще
    void setVarianceOfAllEy(double Variance);//Задание значения переменной VarianceOfAllEy - дисперсия ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще
    double getVarianceOfAllR();//Получение значения переменной VarianceOfAllR - дисперсия надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще
     void setVarianceOfAllR(double Variance);//Задание значения переменной VarianceOfAllR - дисперсия надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще

private:
    QString XML_Author;//Автор документа
    QString XML_Date;//Дата создания документа
    QString XML_Email;//Email автора, чтобы можно было с ним связаться
    QString XML_Name_Algorithm;//Название алгоритма оптимизации
    QString XML_Full_Name_Algorithm;//Полное название алгоритма оптимизации
    QString XML_Name_Test_Function;//Название тестовой функции
    QString XML_Full_Name_Test_Function;//Полное название тестовой функции
    qint64 XML_DimensionTestFunction;//Размерность тестовой задачи (длина хромосомы решения)
    qint64 XML_Number_Of_Measuring;//Количество экспериментов для каждого набора параметров алгоритма
    qint64 XML_Number_Of_Runs;//Количество прогонов, по которому делается усреднение для эксперимента
    qint64 XML_Max_Count_Of_Fitness;//Максимальное допустимое число вычислений целевой функции для алгоритма
    qint64 XML_Number_Of_Parameters;//Количество проверяемых параметров алгоритма оптимизации
    qint64 XML_Number_Of_Experiments;//Количество комбинаций вариантов настроек
    QString XML_Link_Test_Function;//Ссылка на описание тестовой функции
    QString XML_Link_Algorithm;//Ссылка на описание алгоритма оптимизации
    QString XML_Format;//Что за формат файла
    QString XML_Version;//Какая версия формата файла
    QString XML_Link;//Ссылка на описание формата файла
    int XML_All_Combinations;//Все ли рассмотрены функции

    bool SuccessReading;//данные в порядке или нет

    //Среднее значение ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще.
    double MeanOfAllEx;

    //Среднее значение ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще.
    double MeanOfAllEy;

    //Среднее значение надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще.
    double MeanOfAllR;

    //Дисперсия надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще.
    double VarianceOfAllR;

    //Дисперсия ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще.
    double VarianceOfAllEx;

    //Дисперсия ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще.
    double VarianceOfAllEy;

    //Матрица значений ошибок Ex алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    double **MatrixOfEx;

    //Матрица значений ошибок Ey алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    double **MatrixOfEy;

    //Матрица значений надежностей R алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    double **MatrixOfR;

    //Вектор средних значений ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *MeanOfEx;

    //Вектор средних значений ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *MeanOfEy;

    //Вектор средних значений надежностей R алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *MeanOfR;

    //Вектор дисперсий ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *VarianceOfEx;

    //Вектор дисперсий ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *VarianceOfEy;

    //Вектор дисперсий надежностей R алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *VarianceOfR;

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    int **MatrixOfParameters;

    //Сюда будем записывать названия параметров алгоритма оптимизации.
    //Например, тип скрещивания или тип селекции.
    QStringList NamesOfParameters;

    //Вектор названий вариантов параметров алгоритма оптимизации.
    //Число элементов равно числу проверяемых параметров алгоритма оптимизации.
    //Элементы будут заноситься по мере обнаружения новых вариантов алгоритма.
    //Номера вариантов параметров алгоритма в конкретном списке QStringList будет совпадать
    //с номерами из MatrixOfParameters. То есть, что записано в MatrixOfParameters в
    //ListOfParameterOptions находится под номером соответствующим.
    //То есть какие бывают типы скрещивания и так далее
    QStringList *ListOfParameterOptions;

    //Номера комбинаций вариантов настроек
    //Содержит номера от 1 до XML_Number_Of_Experiments
    //Дополнительный вектор, чтобы понимать, какой номер у
    //эксперимента с настройками из ListOfVectorParameterOptions
    double *NumberOfListOfVectorParameterOptions;

    //Список вектора названий вариантов параметров алгоритма оптимизации.
    //Число элементов равно числу экспериментов алгоритма оптимизации.
    //То есть записывается вектор параметров алгоритма для каждого эксперимента
    //То есть это список комбинаций вариантов настроек
    //это сборник строк из MatrixOfNameParameters, где объединены столбцы
    QStringList ListOfVectorParameterOptions;

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Элементы не в виде чисел, а в виде наименований этих параметров.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    QStringList *MatrixOfNameParameters;
};

#endif // HARRIXCLASS_ONLYDATAOFHARRIXOPTIMIZATIONTESTING_H
