#ifndef HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H
#define HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H

#include <QFile>
#include <QXmlStreamReader>

//После описания класса идут функции по работе с данным классом. Не пропустите!

class HarrixClass_DataOfHarrixOptimizationTesting
{
public:
    HarrixClass_DataOfHarrixOptimizationTesting(QString filename);
    ~HarrixClass_DataOfHarrixOptimizationTesting();
    bool getSuccessReading();//Получение значения переменной SuccessReading о удачности или неудачности прочитывания файла.
    QString getHtml();//Получение текста переменной Html
    QString getHtmlReport();//Получение текста переменной HtmlReport. Это часть html документа в виде отчета о проделанной работе.
    QString getHtmlMessageOfError();//Получение текста переменной HtmlMessageOfError. Это часть html документа в виде кода о сообщениях ошибок.

    QString getLatex();//Получение текста переменной Latex
    QString getLatexTable();//Получение текста переменной LatexTable - всё без анализа
    QString getLatexTableEx();//Получение текста переменной LatexTableEx - отображение таблицы данных о ошибке Ex.
    QString getLatexTableEy();//Получение текста переменной LatexTableEy - отображение сырых данных ошибки по значениям целевой функции в виде полной таблицы.
    QString getLatexTableR();//Получение текста переменной LatexTableR - отображение сырых данных по надежности в виде полной таблицы.
    QString getLatexInfo();//Получение текста переменной LatexTableR - отображение информации о исследовании.
    QString getLatexAboutParameters();//Получение текста переменной LatexAboutParameters - отображение данных о обнаруженных параметрах алгоритма и какие они бывают.
    QString getLatexAnalysis();//Получение текста переменной LatexAnalysis - отображение первоначального анализа данных.

    QString getFullLatex();//Получение текста переменной Latex в полном составе с началом и концовкой в Latex файле.
    QString getFullLatexTable();//Получение текста переменной LatexTable - всё без анализа - в полном составе с началом и концовкой в Latex файле
    QString getFullLatexTableEx();//Получение текста переменной LatexTableEx - отображение сырых данных таблицы данных о ошибке Ex с началом и концовкой в Latex файле.
    QString getFullLatexTableEy();//Получение текста переменной LatexTableEy - отображение сырых данных таблицы данных о ошибке Ey с началом и концовкой в Latex файле.
    QString getFullLatexTableR();//Получение текста переменной LatexTableR - отображение сырых данных по надежности в виде полной таблицы с началом и концовкой в Latex файле.
    QString getFullLatexInfo();//Получение текста переменной LatexInfo - отображение информации о исследовании с началом и концовкой в Latex файле.
    QString getFullLatexAboutParameters();//Получение текста переменной LatexAboutParameters - отображение данных о обнаруженных параметрах алгоритма и какие они бывают с началом и концовкой в Latex файле.
    QString getFullLatexAnalysis();//Получение текста переменной LatexAnalysis - отображение данных первоначального анализа данных.

    QString getAuthor();//Получение текста переменной XML_Author - Автор документа
    QString getDate();//Получение текста переменной  XML_Date - Дата создания документа
    QString getNameAlgorithm();//Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации
    QString getFullNameAlgorithm();//Получение текста переменной  XML_Full_Name_Algorithm - Полное название алгоритма оптимизации
    QString getNameTestFunction();//Получение текста переменной  XML_Name_Test_Function - Название тестовой функции
    QString getFullNameTestFunction();//Получение текста переменной  XML_Full_Name_Test_Function - Полное название тестовой функции
    int getDimensionTestFunction();//Получение текста переменной  XML_DimensionTestFunction - Размерность тестовой задачи (длина хромосомы решения)
    int getNumberOfMeasuring();//Получение текста переменной  XML_Number_Of_Measuring - Размерность тестовой задачи (длина хромосомы решения)
    int getNumberOfRuns();//Получение текста переменной  XML_Number_Of_Runs - Количество прогонов по которому делается усреднение для эксперимента
    int getMaxCountOfFitness();//Получение текста переменной  Max_Count_Of_Fitness - Максимальное допустимое число вычислений целевой функции для алгоритма
    int getNumberOfParameters();//Получение текста переменной  XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации
    int getNumberOfExperiments();//Получение текста переменной  XML_Number_Of_Experiments - Количество комбинаций вариантов настроек
    bool getCheckAllCombinations();//Получение текста переменной  XML_All_Combinations - Все ли комбинации вариантов настроек просмотрены: 0 bли 1
    double getErrorEx(int Number_Of_Experiment, int Number_Of_Measuring);//Получение значения ошибки Ex.
    double getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring);//Получение значения ошибки Ey.
    double getErrorR(int Number_Of_Experiment, int Number_Of_Measuring);//Получение значения надежности R.
    double getMeanEx(int Number_Of_Experiment);//Получение среднего значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    double getMeanEy(int Number_Of_Experiment);//Получение среднего значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    double getMeanR(int Number_Of_Experiment);//Получение среднего значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).
    double getVarianceOfEx(int Number_Of_Experiment);//Получение дисперсии значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    double getVarianceOfEy(int Number_Of_Experiment);//Получение дисперсии значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    double getVarianceOfR(int Number_Of_Experiment);//Получение дисперсии значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).
    int getParameter(int Number_Of_Experiment, int Number_Of_Parameter);//Получение значения параметра настройки какой-то.
    QString getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter);//Получение значения параметра настройки какой-то в виде полного наименования.
    QString getNameOption(int Number_Of_Parameter);//Получение имени параметра алгоритма по его номеру.
    int getNumberOfOption(QString NameOption);//Получение номера параметра алгоритма по его имени.
    QString getFormat();//Получение переменной XML_Format, то есть возвращает название формата документа.
    QString getVersion();//Получение переменной XML_Version, то есть возвращает версию формата документа.
    QString getLink();//Получение переменной XML_Site, то есть возвращает ссылку на описание формата файла.



private:
    void makingLatexTableR();//Создает текст LaTeX для отображения сырых данных по надежности в виде полной таблицы.
    void makingLatexTableEy();//Создает текст LaTeX для отображения сырых данных ошибки по значениям целевой функции в виде полной таблицы.
    void makingLatexTableEx();//Создает текст LaTeX для отображения сырых данных ошибки по входным параметрам в виде полной таблицы.
    void makingLatexInfo();//Создает текст LaTeX для отображения информации о исследовании.
    void makingLatexAboutParameters();//Создает текст LaTeX для отображения данных о обнаруженных параметрах алгоритма и какие они бывают.
    void makingLatexAnalysis();//Создает текст LaTeX для отображения первоначального анализа данных.
    void makingHtmlReport();//Создает текст Html для отображения отчета о считывании XML файла.
    QString getLatexEnd();//Внутренняя функция. Возвращает концовку для полноценного Latex файла.
    QString getLatexBegin();//Внутренняя функция. Возвращает начало для полноценного Latex файла.

    void readXmlLeafTag();//Считывает и проверяет тэг, который должен являться "листом", то есть самым глубоким. Внутренняя функция.
    void checkXmlLeafTags();//Проверяет наличие тэгов и правильное их выполнение. Внутренняя функция.
    void memoryAllocation();//Выделяет память под необходимые массивы. Внутренняя функция.
    void readXmlDataTags();//Считывает и проверяет тэги данных. Внутренняя функция.
    bool readXmlTreeTag(QString tag);//Считывает и проверяет тэг, который содержит внутри себя другие тэги. Внутренняя функция.
    void zeroArray();//Обнуляет массивы, в котрые записывается информация о данных из файла. Внутренняя функция.
    void makingAnalysis();//Выполняет анализ считанных данных. Внутренняя функция.

    QString XML_Author;//Автор документа
    QString XML_Date;//Дата создания документа
    QString XML_Email;//Email автора, чтобы можно было с ним связаться
    QString XML_Name_Algorithm;//Название алгоритма оптимизации
    QString XML_Full_Name_Algorithm;//Полное название алгоритма оптимизации
    QString XML_Name_Test_Function;//Название тестовой функции
    QString XML_Full_Name_Test_Function;//Полное название тестовой функции
    qint64 XML_DimensionTestFunction;//Размерность тестовой задачи (длина хромосомы решения)
    qint64 XML_Number_Of_Measuring;//Количество экспериментов для каждого набора параметров алгоритма
    qint64 XML_Number_Of_Runs;//Количество прогонов по которому делается усреднение для эксперимента
    qint64 XML_Max_Count_Of_Fitness;//Максимальное допустимое число вычислений целевой функции для алгоритма
    qint64 XML_Number_Of_Parameters;//Количество проверяемых параметров алгоритма оптимизации
    qint64 XML_Number_Of_Experiments;//Количество комбинаций вариантов настроек
    QString XML_Link_Test_Function;//Ссылка на описание тестовой функции
    QString XML_Link_Algorithm;//Ссылка на описание алгоритма оптимизации
    QString XML_Format;//Что за формат файла
    QString XML_Version;//Какая версия формата файла
    QString XML_Link;//Ссылка на описание формата файла
    qint64 XML_All_Combinations;//Все ли рассмотрены функции

    //Строка с возвращаемым HTML кодом
    QString Html;
    //далее идет набор переменных для кусков Html кодов
    QString HtmlMessageOfError;// сюда записывается код о сообщениях ошибок
    QString HtmlReport;//текст Html для отображения отчета о считывании XML файла.

    //Строка с возвращаемым кодом  Latex для добавления в https://github.com/Harrix/Harrix-Document-Template-LaTeX
    QString Latex;
    QString LatexTable;//Первичная информация плюс таблицы. Без анализа
    //далее идет набор переменных для кусков Latex кодов
    QString LatexTableEx;//для отображения таблицы данных о ошибке Ex
    QString LatexTableEy;//для отображения таблицы данных о ошибке Ey
    QString LatexTableR; //для отображения таблицы данных о ошибке R
    QString LatexInfo;//Для отображения информации о исследовании
    QString LatexAboutParameters;//Для отображения данных о обнаруженных парметрах алгоритма и какие они бывают
    QString LatexAnalysis;//Для отображения первоначального анализа данных.

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

    //Вектор средних значений ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *MeanOfEx;

    //Вектор средних значений ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *MeanOfEy;

    //Вектор средних значений ошибок R алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *MeanOfR;

    //Среднее значение ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще.
    double MeanOfAllEx;

    //Среднее значение ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще.
    double MeanOfAllEy;

    //Среднее значение ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще.
    double MeanOfAllR;

    //Вектор дисперсий ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *VarianceOfEx;

    //Вектор дисперсий ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *VarianceOfEy;

    //Вектор дисперсий ошибок R алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    double *VarianceOfR;

    //Дисперсия ошибок R алгоритма оптимизации по измерениям по всем измерениям вообще.
    double VarianceOfAllR;

    //Дисперсия ошибок R алгоритма оптимизации по измерениям по всем измерениям вообще.
    double VarianceOfAllEx;

    //Дисперсия ошибок R алгоритма оптимизации по измерениям по всем измерениям вообще.
    double VarianceOfAllEy;

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

    //далее идут внутренние служебные перменные
    QString Un;//уникальная строка для использования ссылок в Latex
    QString NameForHead;//тот кусок, который будет вставляться в таблицы, заголовки: какой-то алгорим оптимизации на такой-то тестовой функции такой-то размерности.
    QString Cell1,Cell2,Cell3,Cell4,Cell5;//для записи ячеек в полные таблицы
    QString Parbox;//нужно или не нужно делать в формулах фиксированную ячейку для длииного текста
    QString NameOfElement;//имя тэга
    QString TextOfElement;//содержимое тэга
    QString AttrOfElement;//содержимое аттрибута тэга
    QString NameOfAttr;//название атрибута тэга
    bool Error;//естm ли ошибка при анализе XML файла
    QXmlStreamReader Rxml;//непосредственно анализируемый xml файл
    bool Zero_Number_Of_Parameters;//Число параметров равно нулю или нет
};

void HQt_HCDOHOT_GeneratedReportAboutAlgorithmFromDir(QString path, QString pathForSave, QString pathForTempHtml);//Генерирует отчет по алгоритму по файлам *.hdata одного алгоритма, просматривая все файлы в папке.

#endif // HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H
