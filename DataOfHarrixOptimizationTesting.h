#ifndef DATAOFHARRIXOPTIMIZATIONTESTING_H
#define DATAOFHARRIXOPTIMIZATIONTESTING_H

#include <QFile>

class DataOfHarrixOptimizationTesting
{
public:
    DataOfHarrixOptimizationTesting(QString filename);
    ~DataOfHarrixOptimizationTesting();
    bool getSuccessReading();//Получение значения переменной SuccessReading о удачности или неудачности прочитывания файла.
    QString getHtml();//Получение текста переменной Html
    QString getLatex();//Получение текста переменной Latex
    QString getAuthor();//Получение текста переменной XML_Author - Автор документа
    QString getDate();//Получение текста переменной  XML_Date - Дата создания документа
    QString getNameAlgorithm();//Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации
    QString getFullNameAlgorithm();//Получение текста переменной  XML_Full_Name_Algorithm - Полное название алгоритма оптимизации
    QString getNameTestFunction();//Получение текста переменной  XML_Name_Test_Function - Название тестовой функции
    QString getFullNameTestFunction();//Получение текста переменной  XML_Full_Name_Test_Function - Полное название тестовой функции
    int getChromosomeLength();//Получение текста переменной  XML_Chromosome_Length - Размерность тестовой задачи (длина хромосомы решения)
    int getNumberOfMeasuring();//Получение текста переменной  XML_Number_Of_Measuring - Размерность тестовой задачи (длина хромосомы решения)
    int getNumberOfRuns();//Получение текста переменной  XML_Number_Of_Runs - Количество прогонов по которому делается усреднение для эксперимента
    int getMaxCountOfFitness();//Получение текста переменной  Max_Count_Of_Fitness - Максимальное допустимое число вычислений целевой функции для алгоритма
    int getNumberOfParameters();//Получение текста переменной  XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации
    int getNumberOfExperiments();//Получение текста переменной  XML_Number_Of_Experiments - Количество комбинаций вариантов настроек
    double getErrorEx(int Number_Of_Experiment, int Number_Of_Measuring);//Получение значения ошибки Ex.
    double getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring);//Получение значения ошибки Ey.
    double getErrorR(int Number_Of_Experiment, int Number_Of_Measuring);//Получение значения надежности R.
    int getParameter(int Number_Of_Experiment, int Number_Of_Parameter);//Получение значения параметра настройки какой-то.
    QString getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter);//Получение значения параметра настройки какой-то в виде полного наименования.
    QString getNameOption(int Number_Of_Parameter);//Получение имени параметра алгоритма по его номеру.
    int getNumberOfOption(QString NameOption);//Получение номера параметра алгоритма по его имени.
private:
    QString XML_Author;//Автор документа
    QString XML_Date;//Дата создания документа
    QString XML_Name_Algorithm;//Название алгоритма оптимизации
    QString XML_Full_Name_Algorithm;//Полное название алгоритма оптимизации
    QString XML_Name_Test_Function;//Название тестовой функции
    QString XML_Full_Name_Test_Function;//Полное название тестовой функции
    int XML_Chromosome_Length;//Размерность тестовой задачи (длина хромосомы решения)
    int XML_Number_Of_Measuring;//Количество экспериментов для каждого набора параметров алгоритма
    int XML_Number_Of_Runs;//Количество прогонов по которому делается усреднение для эксперимента
    int XML_Max_Count_Of_Fitness;//Максимальное допустимое число вычислений целевой функции для алгоритма
    int XML_Number_Of_Parameters;//Количество проверяемых параметров алгоритма оптимизации
    int XML_Number_Of_Experiments;//Количество комбинаций вариантов настроек

    //Строка с возвращаемым HTML кодом
    QString Html;

    //Строка с возвращаемым кодом  Latex для добавления в https://github.com/Harrix/Harrix-Document-Template-LaTeX
    QString Latex;

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

    //Вектор названий вариантов параметров алгоритма оптимизации.
    //Число элементов равно числу проверяемых параметров алгоритма оптимизации.
    //Элементы будут заноситься по мере обнаружений новых вариантов алгоритма.
    //Номера вариантов параметров алгоритма в конкретном списке QStringList будет совпадать
    //с номерами из MatrixOfParameters. То есть, что записано в MatrixOfParameters в
    //ListOfParameterOptions находится под номером соответствующим.
    QStringList *ListOfParameterOptions;

    //Сюда будем записывать названия параметров алгоритма оптимизации.
    QStringList NamesOfParameters;

	//данные в порядке или нет
    bool SuccessReading;

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Элементы не в виде чисел, а в виде наименований этих параметров.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    QStringList *MatrixOfNameParameters;
};

#endif // DATAOFHARRIXOPTIMIZATIONTESTING_H
