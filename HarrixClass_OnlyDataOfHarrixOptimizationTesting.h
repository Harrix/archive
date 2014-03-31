//HarrixClass_DataOfHarrixOptimizationTesting
//Версия 1.19
//Класс для считывания информации формата данных Harrix Optimization Testing на C++ для Qt.
//https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#ifndef HARRIXCLASS_ONLYDATAOFHARRIXOPTIMIZATIONTESTING_H
#define HARRIXCLASS_ONLYDATAOFHARRIXOPTIMIZATIONTESTING_H

//Класс, который только содержит сырые данные исследований, которые считываются
//классом HarrixClass_DataOfHarrixOptimizationTesting. В данном классе нет ни проверки
//корректности ввоод информации и др. Это служебный класс.
class HarrixClass_OnlyDataOfHarrixOptimizationTesting
{
public:
    HarrixClass_OnlyDataOfHarrixOptimizationTesting();
    ~HarrixClass_OnlyDataOfHarrixOptimizationTesting();
    void operator = (HarrixClass_OnlyDataOfHarrixOptimizationTesting& B);

    void memoryAllocation();//Выделяет память под необходимые массивы.
    void memoryDeallocation();//Удаляет память из-под массивов. Внутренняя функция.
    void initializationOfVariables();//Обнуление пемеренных. Внутренняя функция.

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
    qint64 getNumberOfRuns();//Получение текста переменной XML_Number_Of_Runs - Количество прогонов по которому деляется усреднение для эксперимента
    void setNumberOfRuns(qint64 NumberOfRuns);//Задание текста переменной XML_Number_Of_Runs - Количество прогонов по которому деляется усреднение для эксперимента
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

    //Матрица значений ошибок Ex алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    double **MatrixOfEx;

    //Матрица значений ошибок Ey алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    double **MatrixOfEy;

    //Матрица значений ошибок R алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    double **MatrixOfR;

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    int **MatrixOfParameters;

    //Сюда будем записывать названия параметров алгоритма оптимизации.
    //Например, тип скрещивания или тип селекции.
    QStringList NamesOfParameters;

    //Вектор названий вариантов параметров алгоритма оптимизации.
    //Число элементов равно числу проверяемых параметров алгоритма оптимизации.
    //Элементы будут заноситься по мере обнаружений новых вариантов алгоритма.
    //Номера вариантов параметров алгоритма в конкретном списке QStringList будет совпадать
    //с номерами из MatrixOfParameters. То есть, что записано в MatrixOfParameters в
    //ListOfParameterOptions находится под номером соответствующим.
    //То есть какие бывают типы скрещивания и так далее
    QStringList *ListOfParameterOptions;
};

#endif // HARRIXCLASS_ONLYDATAOFHARRIXOPTIMIZATIONTESTING_H
