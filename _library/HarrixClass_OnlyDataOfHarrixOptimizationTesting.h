//HarrixClass_DataOfHarrixOptimizationTesting
//Версия 1.25
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
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    public:
    //_Конструкторы и деструкторы
    HarrixClass_OnlyDataOfHarrixOptimizationTesting();
    ~HarrixClass_OnlyDataOfHarrixOptimizationTesting();
    
    //Возвращение данных из класса
    QString getAuthor();
    bool getCheckAllCombinations();
    QString getDate();
    qint64 getDimensionTestFunction();
    QString getEmail();
    double getErrorEx(int Number_Of_Experiment, int Number_Of_Measuring);
    double getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring);
    double getErrorR(int Number_Of_Experiment, int Number_Of_Measuring);
    QString getFormat();
    QString getFullNameAlgorithm();
    QString getFullNameTestFunction();
    QString getLink();
    QString getLinkAlgorithm();
    QString getLinkTestFunction();
    QStringList getListOfParameterOptions(int Number_Of_Parameter);
    QStringList getListOfVectorParameterOptions();
    QString getListOfVectorParameterOptions(int Number_Of_Experiment);
    qint64 getMaxCountOfFitness();
    double getMeanEx(int Number_Of_Experiment);
    double getMeanEy(int Number_Of_Experiment);
    double getMeanOfAllEx();
    double getMeanOfAllEy();
    double getMeanOfAllR();
    double getMeanR(int Number_Of_Experiment);
    QString getNameAlgorithm();
    QString getNameOption(int Number_Of_Parameter);
    QString getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter);
    QString getNameTestFunction();
    QStringList getNamesOfParameters();
    qint64 getNumberOfExperiments();
    qint64 getNumberOfMeasuring();
    qint64 getNumberOfParameters();
    qint64 getNumberOfRuns();
    QString getOptionFromListOfParameterOptions(int Number_Of_Parameter, int Number_Of_Option);
    QString getOptionFromListOfParameterOptionsForTable(int Number_Of_Parameter, int Number_Of_Option);
    int getParameter(int Number_Of_Experiment, int Number_Of_Parameter);
    bool getSuccessReading();
    double getVarianceOfAllEx();
    double getVarianceOfAllEy();
    double getVarianceOfAllR();
    double getVarianceOfEx(int Number_Of_Experiment);
    double getVarianceOfEy(int Number_Of_Experiment);
    double getVarianceOfR(int Number_Of_Experiment);
    QString getVersion();
    
    //Задание данных в класс
    void addListOfParameterOptions(QString Option, int Number_Of_Parameter);
    void addListOfVectorParameterOptions(QString Option);
    void addNameOption(QString Option);
    void addNameParameter(QString Name, int Number_Of_Experiment);
    void setAuthor(QString Author);
    void setCheckAllCombinations(bool AllCombinations);
    void setDate(QString Date);
    void setDimensionTestFunction(qint64 DimensionTestFunction);
    void setEmail(QString Email);
    void setErrorEx(double ErrorEx,int Number_Of_Experiment, int Number_Of_Measuring);
    void setErrorEy(double ErrorEy,int Number_Of_Experiment, int Number_Of_Measuring);
    void setErrorR(double ErrorR,int Number_Of_Experiment, int Number_Of_Measuring);
    void setFormat(QString Format);
    void setFullNameAlgorithm(QString FullNameAlgorithm);
    void setFullNameTestFunction(QString FullNameTestFunction);
    void setLink(QString Link);
    void setLinkAlgorithm(QString LinkAlgorithm);
    void setLinkTestFunction(QString LinkTestFunction);
    void setListOfParameterOptions(QStringList List, int Number_Of_Parameter);
    void setMaxCountOfFitness(qint64 MaxCountOfFitness);
    void setMeanEx(double MeanEx, int Number_Of_Experiment);
    void setMeanEy(double MeanEy, int Number_Of_Experiment);
    void setMeanOfAllEx(double Mean);
    void setMeanOfAllEy(double Mean);
    void setMeanOfAllR(double Mean);
    void setMeanR(double MeanR, int Number_Of_Experiment);
    void setNameAlgorithm(QString NameAlgorithm);
    void setNameTestFunction(QString NameTestFunction);
    void setNumberOfExperiments(qint64 NumberOfExperiments);
    void setNumberOfListOfVectorParameterOptions(double Num,int Number);
    void setNumberOfMeasuring(qint64 NumberOfMeasuring);
    void setNumberOfParameters(qint64 NumberOfParameters);
    void setNumberOfRuns(qint64 NumberOfRuns);
    void setParameter(int Parameter, int Number_Of_Experiment, int Number_Of_Parameter);
    void setSuccessReading(bool Success);
    void setVarianceOfAllEx(double Variance);
    void setVarianceOfAllEy(double Variance);
    void setVarianceOfAllR(double Variance);
    void setVarianceOfEx(double Variance, int Number_Of_Experiment);
    void setVarianceOfEy(double Variance, int Number_Of_Experiment);
    void setVarianceOfR(double Variance, int Number_Of_Experiment);
    void setVersion(QString Version);
    
    //Операторы
    void operator = (HarrixClass_OnlyDataOfHarrixOptimizationTesting& B);
    
    //Служебные функции
    void initializationOfVariables();
    void memoryAllocation();
	void memoryDeallocation();

    private:    
	//ПЕРЕМЕННЫЕ
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
