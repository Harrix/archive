Список функций библиотеки HarrixClass_DataOfHarrixOptimizationTesting
=====================================================================

Файл Functions_For_HarrixClass_DataOfHarrixOptimizationTesting.cpp
==================================================================

Блок функций проверки равенства переменных нескольких исследований
----------------

- Проверяет по критерию Вилкосона два исследования алгоритмов.

```cpp
int HCDOHOT_CompareOfDataByWilcoxonW (HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data1, HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data2, double Q);
```

- Проверяет равенство авторов исследований.

```cpp
bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство переменной, которая говорит все ли рассмотрены функции в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство дат исследований.

```cpp
bool HCDOHOT_CompareOfDataForDate (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForDate (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForDate (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство размерностей тестовой задачи (длина хромосомы решения) в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForDimensionTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForDimensionTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForDimensionTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство email авторов исследований.

```cpp
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство форматов файлов в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство полных названий алгоритмов в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство полных названий тестовых функций в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForFullNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForFullNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForFullNameTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство ссылок на описание версий формата файла в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForLink (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForLink (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForLink (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство максимальных допустимых чисел вычислений целевой функции для алгоритма в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство идентификаторов алгоритмов оптимизации: в данных содержится один и тот же алгоритм или же нет.

```cpp
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство идентификаторов тестовых функций в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNameTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство количества комбинаций вариантов настроек в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство количества экспериментов для каждого набора параметров алгоритма в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство количества проверяемых параметров алгоритма оптимизации в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство количества прогонов, по которому делается усреднение для эксперимента в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

- Проверяет равенство версий формата файла в исследованиях.

```cpp
bool HCDOHOT_CompareOfDataForVersion (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForVersion (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForVersion (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
```

Генерация отчетов
----------------

- Генерирует отчет-анализ Latex по алгоритму по файлу *.hdata.

```cpp
void HCDOHOT_GeneratedAnalysisReportFromFile(QString filename, QString pathForSave, QString pathForTempHtml);
void HCDOHOT_GeneratedAnalysisReportFromFile(QString filename, QString pathForSave);
```

- Генерирует отчет Latex по алгоритму по файлам *.hdata алгоритма, просматривая все файлы в папке. То, чтобы в папке были файлы только одного алгоритма, вы берете на себя.

```cpp
void HCDOHOT_GeneratedReportAboutAlgorithmFromDir(QString path, QString pathForSave, QString pathForTempHtml);
void HCDOHOT_GeneratedReportAboutAlgorithmFromDir(QString path, QString pathForSave);
```

- Генерирует простой отчет Latex по алгоритму по файлу *.hdata.

```cpp
void HCDOHOT_GeneratedSimpleReportFromFile(QString filename, QString pathForSave, QString pathForTempHtml);
void HCDOHOT_GeneratedSimpleReportFromFile(QString filename, QString pathForSave);
```

Функции по работе с классом
----------------

- Подсчитывает число HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.

```cpp
int HCDOHOT_NumberFilesInDir(QString path);
```

- Заполняет массив SeveralData данными из всех файлов *.hdata из папки.

```cpp
int HCDOHOT_ReadFilesInDir(HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, QString path, QString pathForTempHtml);
int HCDOHOT_ReadFilesInDir(HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, QString path);
```

- Заполняет массив SeveralData данными (только исследования) из всех файлов *.hdata из папки.

```cpp
int HCDOHOT_ReadFilesOnlyDataInDir(HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, QString path, QString pathForTempHtml);
int HCDOHOT_ReadFilesOnlyDataInDir(HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, QString path);
```

Файл HarrixClass_OnlyDataOfHarrixOptimizationTesting.cpp
========================================================

_Конструкторы и деструкторы
----------------

- Конструктор. Создает пустой экземпляр.

```cpp
HarrixClass_OnlyDataOfHarrixOptimizationTesting();
```

- Деструктор класса.

```cpp
~HarrixClass_OnlyDataOfHarrixOptimizationTesting();
```

Возвращение данных из класса
----------------

- Получение текста переменной XML_Author - Автор документа.

```cpp
QString getAuthor();
```

- Получение текста переменной  XML_All_Combinations --- Все ли комбинации вариантов настроек просмотрены: 0 или 1.

```cpp
bool getCheckAllCombinations();
```

- Получение текста переменной  XML_Date - Дата создания документа.

```cpp
QString getDate();
```

- Получение текста переменной  XML_DimensionTestFunction --- Размерность тестовой задачи.

```cpp
qint64 getDimensionTestFunction();
```

- Получение текста переменной  XML_Email - Email автора, чтобы можно было с ним связаться.

```cpp
QString getEmail();
```

- Получение значения ошибки Ex.

```cpp
double getErrorEx(int Number_Of_Experiment, int Number_Of_Measuring);
```

- Получение значения ошибки Ey.

```cpp
double getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring);
```

- Получение значения надежности R.

```cpp
double getErrorR(int Number_Of_Experiment, int Number_Of_Measuring);
```

- Получение переменной XML_Format, то есть возвращает название формата документа.

```cpp
QString getFormat();
```

- Получение текста переменной  XML_Full_Name_Algorithm --- Полное название алгоритма оптимизации.

```cpp
QString getFullNameAlgorithm();
```

- Получение текста переменной  XML_Full_Name_Test_Function --- Полное название тестовой функции.

```cpp
QString getFullNameTestFunction();
```

- Получение переменной XML_Link, то есть возвращает ссылку на описание формата файла.

```cpp
QString getLink();
```

- Получение текста переменной  XML_Link_Algorithm --- Ссылка на описание алгоритма оптимизации.

```cpp
QString getLinkAlgorithm();
```

- Получение текста переменной  XML_Link_Test_Function --- Ссылка на описание тестовой функции.

```cpp
QString getLinkTestFunction();
```

- Получение списка вектора названий вариантов параметров алгоритма оптимизации.

```cpp
QStringList getListOfParameterOptions(int Number_Of_Parameter);
```

- Получение списка вектора названий вариантов параметров алгоритма оптимизации --- это сборник строк из MatrixOfNameParameters, где объединены столбцы. Получение строки параметров эксперимента из списка вектора названий вариантов параметров алгоритма оптимизации --- это сборник строк из MatrixOfNameParameters, где объединены столбцы.

```cpp
QStringList getListOfVectorParameterOptions();
QString getListOfVectorParameterOptions(int Number_Of_Experiment);
```

- Получение текста переменной  Max_Count_Of_Fitness --- Максимальное допустимое число вычислений целевой функции для алгоритма.

```cpp
qint64 getMaxCountOfFitness();
```

- Получение среднего значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getMeanEx(int Number_Of_Experiment);
```

- Получение среднего значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getMeanEy(int Number_Of_Experiment);
```

- Получение значения переменной MeanOfAllEx --- среднее значение ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще

```cpp
double getMeanOfAllEx();
```

- Получение значения переменной MeanOfAllEy --- среднее значение ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще.

```cpp
double getMeanOfAllEy();
```

- Получение значения переменной MeanOfAllR --- среднее значение надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще.

```cpp
double getMeanOfAllR();
```

- Получение среднего значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getMeanR(int Number_Of_Experiment);
```

- Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации.

```cpp
QString getNameAlgorithm();
```

- Получение имени параметра алгоритма по его номеру.

```cpp
QString getNameOption(int Number_Of_Parameter);
```

- Получение значения параметра настройки какой-то в виде полного наименования.

```cpp
QString getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter);
```

- Получение текста переменной  XML_Name_Test_Function --- Название тестовой функции.

```cpp
QString getNameTestFunction();
```

- Получение списка параметров алгоритма (тип селекции, тип скрещивания).

```cpp
QStringList getNamesOfParameters();
```

- Получение текста переменной  XML_Number_Of_Experiments --- Количество комбинаций вариантов настроек.

```cpp
qint64 getNumberOfExperiments();
```

- Получение текста переменной  XML_Number_Of_Measuring --- Размерность тестовой задачи (длина хромосомы решения).

```cpp
qint64 getNumberOfMeasuring();
```

- Получение текста переменной  XML_Number_Of_Parameters --- Количество проверяемых параметров алгоритма оптимизации.

```cpp
qint64 getNumberOfParameters();
```

- Получение текста переменной  XML_Number_Of_Runs --- Количество прогонов по которому делается усреднение для эксперимента.

```cpp
qint64 getNumberOfRuns();
```

- Получение названия вариантов параметров алгоритма оптимизации.

```cpp
QString getOptionFromListOfParameterOptions(int Number_Of_Parameter, int Number_Of_Option);
```

- Получение названия вариантов параметров алгоритма оптимизации. Но старается где-то сокращать, а где-то добавлять строки.

```cpp
QString getOptionFromListOfParameterOptionsForTable(int Number_Of_Parameter, int Number_Of_Option);
```

- Получение значения параметра настройки какой-то.

```cpp
int getParameter(int Number_Of_Experiment, int Number_Of_Parameter);
```

- Получение текста переменной SuccessReading --- Успешно ли прошло считывание.

```cpp
bool getSuccessReading();
```

- Получение значения переменной VarianceOfAllEx --- дисперсия ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще.

```cpp
double getVarianceOfAllEx();
```

- Получение значения переменной VarianceOfAllEy --- дисперсия ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще

```cpp
double getVarianceOfAllEy();
```

- Получение значения переменной VarianceOfAllR --- дисперсия надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще.

```cpp
double getVarianceOfAllR();
```

- Получение дисперсии значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getVarianceOfEx(int Number_Of_Experiment);
```

- Получение дисперсии значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getVarianceOfEy(int Number_Of_Experiment);
```

- Получение дисперсии значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getVarianceOfR(int Number_Of_Experiment);
```

- Получение переменной Version, то есть возвращает версию формата документа.

```cpp
QString getVersion();
```

Задание данных в класс
----------------

- Добавление списка вектора названий вариантов параметров алгоритма оптимизации.

```cpp
void addListOfParameterOptions(QString Option, int Number_Of_Parameter);
```

- Добавление строки параметров эксперимента из списка вектора названий вариантов параметров алгоритма оптимизации --- это сборник строк из MatrixOfNameParameters, где объединены столбцы.

```cpp
void addListOfVectorParameterOptions(QString Option);
```

- Добавление имени параметра алгоритма.

```cpp
void addNameOption(QString Option);
```

- Получение значения параметра настройки какой-то в виде полного наименования.

```cpp
void addNameParameter(QString Name, int Number_Of_Experiment);
```

- Задание текста переменной XML_Author - Автор документа.

```cpp
void setAuthor(QString Author);
```

- Задание текста переменной  XML_All_Combinations --- Все ли комбинации вариантов настроек просмотрены: 0 или 1.

```cpp
void setCheckAllCombinations(bool AllCombinations);
```

- Задание текста переменной  XML_Date - Дата создания документа.

```cpp
void setDate(QString Date);
```

- Задание текста переменной  XML_DimensionTestFunction --- Размерность тестовой задачи.

```cpp
void setDimensionTestFunction(qint64 DimensionTestFunction);
```

- Задание текста переменной  XML_Email - Email автора, чтобы можно было с ним связаться

```cpp
void setEmail(QString Email);
```

- Задание значения ошибки Ex.

```cpp
void setErrorEx(double ErrorEx,int Number_Of_Experiment, int Number_Of_Measuring);
```

- Задание значения ошибки Ey.

```cpp
void setErrorEy(double ErrorEy,int Number_Of_Experiment, int Number_Of_Measuring);
```

- Задание значения надежности R.

```cpp
void setErrorR(double ErrorR,int Number_Of_Experiment, int Number_Of_Measuring);
```

- Задание переменной XML_Format --- название формата документа.

```cpp
void setFormat(QString Format);
```

- Задание текста переменной  XML_Full_Name_Algorithm --- Полное название алгоритма оптимизации.

```cpp
void setFullNameAlgorithm(QString FullNameAlgorithm);
```

- Задание текста переменной  XML_Full_Name_Test_Function --- Полное название тестовой функции.

```cpp
void setFullNameTestFunction(QString FullNameTestFunction);
```

- Задание переменной XML_Link --- ссылка на описание формата файла.

```cpp
void setLink(QString Link);
```

- Задание текста переменной  XML_Link_Algorithm --- Ссылка на описание алгоритма оптимизации.

```cpp
void setLinkAlgorithm(QString LinkAlgorithm);
```

- Задание текста переменной  XML_Link_Test_Function --- Ссылка на описание тестовой функции.

```cpp
void setLinkTestFunction(QString LinkTestFunction);
```

- Задание списка вектора названий вариантов параметров алгоритма оптимизации.

```cpp
void setListOfParameterOptions(QStringList List, int Number_Of_Parameter);
```

- Задание текста переменной  Max_Count_Of_Fitness --- Максимальное допустимое число вычислений целевой функции для алгоритма.

```cpp
void setMaxCountOfFitness(qint64 MaxCountOfFitness);
```

- Задание среднего значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
void setMeanEx(double MeanEx, int Number_Of_Experiment);
```

- Задание среднего значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
void setMeanEy(double MeanEy, int Number_Of_Experiment);
```

- Задание значения переменной MeanOfAllEx - среднее значение ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще

```cpp
void setMeanOfAllEx(double Mean);
```

- Задание значения переменной MeanOfAllEy - среднее значение ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще.

```cpp
void setMeanOfAllEy(double Mean);
```

- Задание значения переменной MeanOfAllR --- среднее значение надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще.

```cpp
void setMeanOfAllR(double Mean);
```

- Задание среднего значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
void setMeanR(double MeanR, int Number_Of_Experiment);
```

- Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации.

```cpp
void setNameAlgorithm(QString NameAlgorithm);
```

- Задание текста переменной  XML_Name_Test_Function --- Название тестовой функции.

```cpp
void setNameTestFunction(QString NameTestFunction);
```

- Задание текста переменной  XML_Number_Of_Experiments --- Количество комбинаций вариантов настроек.

```cpp
void setNumberOfExperiments(qint64 NumberOfExperiments);
```

- Задание значения элемента массива NumberOfListOfVectorParameterOptions.

```cpp
void setNumberOfListOfVectorParameterOptions(double Num,int Number);
```

- Задание текста переменной  XML_Number_Of_Measuring --- Размерность тестовой задачи (длина хромосомы решения).

```cpp
void setNumberOfMeasuring(qint64 NumberOfMeasuring);
```

- Задание текста переменной  XML_Number_Of_Parameters --- Количество проверяемых параметров алгоритма оптимизации.

```cpp
void setNumberOfParameters(qint64 NumberOfParameters);
```

- Задание текста переменной  XML_Number_Of_Runs --- Количество прогонов по которому делается усреднение для эксперимента.

```cpp
void setNumberOfRuns(qint64 NumberOfRuns);
```

- Задание значения параметра настройки какой-то.

```cpp
void setParameter(int Parameter, int Number_Of_Experiment, int Number_Of_Parameter);
```

- Задание текста переменной SuccessReading --- Успешно ли прошло считывание.

```cpp
void setSuccessReading(bool Success);
```

- Задание значения переменной VarianceOfAllEx --- дисперсия ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще

```cpp
void setVarianceOfAllEx(double Variance);
```

- Задание значения переменной VarianceOfAllEy --- дисперсия ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще.

```cpp
void setVarianceOfAllEy(double Variance);
```

- Задание значения переменной VarianceOfAllR --- дисперсия надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще.

```cpp
void setVarianceOfAllR(double Variance);
```

- Получение дисперсии значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
void setVarianceOfEx(double Variance, int Number_Of_Experiment);
```

- Получение дисперсии значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
void setVarianceOfEy(double Variance, int Number_Of_Experiment);
```

- Получение дисперсии значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
void setVarianceOfR(double Variance, int Number_Of_Experiment);
```

- Задание переменной XML_Version --- версия формата документа.

```cpp
void setVersion(QString Version);
```

Операторы
----------------

- Оператор присваивания.

```cpp
void operator = (HarrixClass_OnlyDataOfHarrixOptimizationTesting& B);
```

Служебные функции
----------------

- Обнуление переменных. Внутренняя функция.

```cpp
void initializationOfVariables();
```

- Выделяет память под необходимые массивы.

```cpp
void memoryAllocation();
```

- Удаляет память из-под массивов. Внутренняя функция.

```cpp
void memoryDeallocation();
```

Файл HarrixClass_DataOfHarrixOptimizationTesting.cpp
====================================================

Внутренние функции
----------------

- Проверяет наличие тэгов и правильное их выполнение. Внутренняя функция. Учитывает все "листовые" тэги кроме тэгов данных.

```cpp
void checkXmlLeafTags();
```

- Внутренняя функция. Возвращает начало для полноценного Latex файла.

```cpp
QString getLatexBegin();
```

- Внутренняя функция. Возвращает концовку для полноценного Latex файла.

```cpp
QString getLatexEnd();
```

- Обнуление переменных. Внутренняя функция.

```cpp
void initializationOfVariables();
```

- Заполняет список вектора названий вариантов параметров алгоритма оптимизации.

```cpp
void makingListOfVectorParameterOptions();
```

- Выделяет память под необходимые массивы. Внутренняя функция.

```cpp
void memoryAllocation();
```

- Удаляет память из-под массивов. Внутренняя функция.

```cpp
void memoryDeallocation();
```

- Считывание XML файла и осуществление всех остальных анализов и др.

```cpp
void readXml();
```

- Считывает и проверяет тэги данных. Внутренняя функция. Учитывает все "листовые" тэги кроме тэгов данных.

```cpp
void readXmlDataTags();
```

- Считывает и проверяет тэг, который должен являться "листом", то есть самым глубоким. Внутренняя функция. Учитывает все "листовые" тэги кроме тэгов данных.

```cpp
void readXmlLeafTag();
```

- Считывает и проверяет тэг, который содержит внутри себя другие тэги. Внутренняя функция.

```cpp
bool readXmlTreeTag(QString tag);
```

- Обнуляет массивы, в котрые записывается информация о данных из файла. Внутренняя функция.

```cpp
void zeroArray();
```

Создание содержимого отчетов LaTeX и HTML
----------------

- Создает текст Html для отображения отчета о считывании XML файла.

```cpp
void makingHtmlReport();
```

- Создает текст LaTeX для отображения данных о обнаруженных параметрах алгоритма и какие они бывают.

```cpp
void makingLatexAboutParameters();
```

- Создает текст LaTeX для отображения первоначального анализа данных.

```cpp
void makingLatexAnalysis();
```

- Создает текст LaTeX для отображения информации о исследовании.

```cpp
void makingLatexInfo();
```

- Создает текст LaTeX для отображения списка вектора названий вариантов параметров алгоритма оптимизации.

```cpp
void makingLatexListOfVectorParameterOptions();
```

- Создает текст LaTeX для отображения сырых данных ошибки по входным параметрам в виде полной таблицы.

```cpp
void makingLatexTableEx();
```

- Создает текст LaTeX для отображения сырых данных ошибки по значениям целевой функции в виде полной таблицы.

```cpp
void makingLatexTableEy();
```

- Создает текст LaTeX для отображения сырых данных по надежности в виде полной таблицы.

```cpp
void makingLatexTableR();
```

Функции анализа данных
----------------

- Выполняет анализ считанных данных. Внутренняя функция.

```cpp
void makingAnalysis();
```

_Конструкторы и деструкторы
----------------

- Конструктор. Функция считывает данные о тестировании алгоритма оптимизации из файла формата HarrixOptimizationTesting. Во второй реализации это конструктор., который создает пустой экземпляр.

```cpp
HarrixClass_DataOfHarrixOptimizationTesting(QString filename);
HarrixClass_DataOfHarrixOptimizationTesting();
```

- Деструктор класса.

```cpp
~HarrixClass_DataOfHarrixOptimizationTesting();
```

Возвращение HTML данных из класса
----------------

- Получение текста переменной Html. Это итоговый Html документ. Помните, что это не полноценный Html код. Его нужно применять в виде temp.html для макета:      https://github.com/Harrix/QtHarrixLibraryForQWebView.

```cpp
QString getHtml();
```

- Получение текста переменной HtmlMessageOfError. Это часть html документа в виде кода о сообщениях ошибок. Помните, что это не полноценный Html код. Его нужно применять в виде temp.html для макета: https://github.com/Harrix/QtHarrixLibraryForQWebView.

```cpp
QString getHtmlMessageOfError();
```

- Получение текста переменной HtmlReport. Это часть html документа в виде отчета о проделанной работе. Помните, что это не полноценный Html код. Его нужно применять в виде temp.html для макета: https://github.com/Harrix/QtHarrixLibraryForQWebView.

```cpp
QString getHtmlReport();
```

Возвращение LaTeX данных из класса
----------------

- Получение текста переменной Latex в полном составе с началом и концовкой в Latex файле. Здесь собран полный файл анализа данных из считываемого xml файла. Это полноценный Latex код. Его нужно применять с файлами из макета: https://github.com/Harrix/Harrix-Document-Template-LaTeX.

```cpp
QString getFullLatex();
```

- Получение текста переменной LatexAboutParameters --- отображение данных о обнаруженных параметрах алгоритма и какие они бывают с началом и концовкой в Latex файле.

```cpp
QString getFullLatexAboutParameters();
```

- Получение текста переменной LatexAnalysis --- отображение данных первоначального анализа данных.

```cpp
QString getFullLatexAnalysis();
```

- Получение текста переменной LatexInfo --- отображение информации о исследовании с началом и концовкой в Latex файле.

```cpp
QString getFullLatexInfo();
```

- Получение текста переменной LatexTable в полном составе с началом и концовкой в Latex файле.

```cpp
QString getFullLatexTable();
```

- Получение текста переменной LatexTableEx --- отображение сырых данных таблицы данных о ошибке Ex с началом и концовкой в Latex файле.

```cpp
QString getFullLatexTableEx();
```

- Получение текста переменной LatexTableEy --- отображение сырых данных таблицы данных о ошибке Ey с началом и концовкой в Latex файле.

```cpp
QString getFullLatexTableEy();
```

- Получение текста переменной LatexTableR --- отображение сырых данных по надежности в виде полной таблицы с началом и концовкой в Latex файле.

```cpp
QString getFullLatexTableR();
```

- Получение текста переменной Latex. Здесь собран полный файл анализа данных из считываемого xml файла. Помните, что это не полноценный Latex код. Его нужно применять внутри файла из макета: https://github.com/Harrix/Harrix-Document-Template-LaTeX.

```cpp
QString getLatex();
```

- Получение текста переменной LatexAboutParameters --- отображение данных о обнаруженных параметрах алгоритма и какие они бывают.

```cpp
QString getLatexAboutParameters();
```

- Получение текста переменной LatexAnalysis --- отображение первоначального анализа данных.

```cpp
QString getLatexAnalysis();
```

- Получение текста переменной LatexInfo --- отображение информации о исследовании.

```cpp
QString getLatexInfo();
```

- Получение текста переменной LatexTable.

```cpp
QString getLatexTable();
```

- Получение текста переменной LatexTableEx --- отображение сырых данных таблицы данных о ошибке Ex.

```cpp
QString getLatexTableEx();
```

- Получение текста переменной LatexTableEy --- отображение сырых данных ошибки по значениям целевой функции в виде полной таблицы.

```cpp
QString getLatexTableEy();
```

- Получение текста переменной LatexTableR --- отображение сырых данных по надежности в виде полной таблицы.

```cpp
QString getLatexTableR();
```

Возвращение переменных из класса
----------------

- Получение текста переменной XML_Author --- Автор документа.

```cpp
QString getAuthor();
```

- Получение текста переменной  XML_All_Combinations --- Все ли комбинации вариантов настроек просмотрены: 0 или 1.

```cpp
bool getCheckAllCombinations();
```

- Возвращает содержимое исследований в виде экземпляра класса.

```cpp
HarrixClass_OnlyDataOfHarrixOptimizationTesting& getData();
```

- Получение текста переменной  XML_Date --- Дата создания документа.

```cpp
QString getDate();
```

- Получение текста переменной  XML_DimensionTestFunction --- Размерность тестовой задачи.

```cpp
qint64 getDimensionTestFunction();
```

- Получение текста переменной  XML_Email --- Email автора, чтобы можно было с ним связаться

```cpp
QString getEmail();
```

- Получение значения ошибки Ex.

```cpp
double getErrorEx(int Number_Of_Experiment, int Number_Of_Measuring);
```

- Получение значения ошибки Ey.

```cpp
double getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring);
```

- Получение значения надежности R.

```cpp
double getErrorR(int Number_Of_Experiment, int Number_Of_Measuring);
```

- Получение переменной XML_Format, то есть возвращает название формата документа.

```cpp
QString getFormat();
```

- Получение текста переменной  XML_Full_Name_Algorithm --- Полное название алгоритма оптимизации.

```cpp
QString getFullNameAlgorithm();
```

- Получение текста переменной  XML_Full_Name_Test_Function --- Полное название тестовой функции.

```cpp
QString getFullNameTestFunction();
```

- Получение переменной XML_Link, то есть возвращает ссылку на описание формата файла.

```cpp
QString getLink();
```

- Получение текста переменной  XML_Link_Algorithm --- Ссылка на описание алгоритма оптимизации.

```cpp
QString getLinkAlgorithm();
```

- Получение текста переменной  XML_Link_Test_Function --- Ссылка на описание тестовой функции.

```cpp
QString getLinkTestFunction();
```

- Получение текста переменной  Max_Count_Of_Fitness --- Максимальное допустимое число вычислений целевой функции для алгоритма.

```cpp
qint64 getMaxCountOfFitness();
```

- Получение среднего значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getMeanEx(int Number_Of_Experiment);
```

- Получение среднего значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getMeanEy(int Number_Of_Experiment);
```

- Получение среднего значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getMeanR(int Number_Of_Experiment);
```

- Получение текста переменной  XML_Name_Algorithm --- Название алгоритма оптимизации.

```cpp
QString getNameAlgorithm();
```

- Получение значения параметра настройки какой-то в виде полного наименования.

```cpp
QString getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter);
```

- Получение текста переменной  XML_Name_Test_Function --- Название тестовой функции.

```cpp
QString getNameTestFunction();
```

- Получение текста переменной  XML_Number_Of_Experiments --- Количество комбинаций вариантов настроек.

```cpp
qint64 getNumberOfExperiments();
```

- Получение текста переменной  XML_Number_Of_Measuring --- Размерность тестовой задачи (длина хромосомы решения).

```cpp
qint64 getNumberOfMeasuring();
```

- Получение номера параметра алгоритма по его имени.

```cpp
int getNumberOfOption(QString NameOption);
```

- Получение текста переменной  XML_Number_Of_Parameters --- Количество проверяемых параметров алгоритма оптимизации

```cpp
qint64 getNumberOfParameters();
```

- Получение текста переменной  XML_Number_Of_Runs --- Количество прогонов, по которому делается усреднение для эксперимента.

```cpp
qint64 getNumberOfRuns();
```

- Получение значения параметра настройки какой-то.

```cpp
int getParameter(int Number_Of_Experiment, int Number_Of_Parameter);
```

- Получение значения переменной SuccessReading о удачности или не удачности считывания файла.

```cpp
bool getSuccessReading();
```

- Получение дисперсии значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getVarianceOfEx(int Number_Of_Experiment);
```

- Получение дисперсии значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getVarianceOfEy(int Number_Of_Experiment);
```

- Получение дисперсии значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).

```cpp
double getVarianceOfR(int Number_Of_Experiment);
```

- Получение переменной XML_Version, то есть возвращает версию формата документа.

```cpp
QString getVersion();
```

Операторы
----------------

- Оператор присваивания.

```cpp
void operator = (HarrixClass_DataOfHarrixOptimizationTesting& B);
```

Специализированные функции
----------------

- Создает текст LaTeX в виде таблицы 2D для всех экспериментов для отображения какой-нибудь информации.

```cpp
QString makingLatexTable2D(QString Title, QStringList InfoForEveryExperiment);
```