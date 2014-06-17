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

