//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

public:
//_Конструкторы и деструкторы
HarrixClass_DataOfHarrixOptimizationTesting(QString filename);
HarrixClass_DataOfHarrixOptimizationTesting();
~HarrixClass_DataOfHarrixOptimizationTesting();

//Возвращение HTML данных из класса
QString getHtml();
QString getHtmlMessageOfError();
QString getHtmlReport();

//Возвращение LaTeX данных из класса
QString getFullLatex();
QString getFullLatexAboutParameters();
QString getFullLatexAnalysis();
QString getFullLatexInfo();
QString getFullLatexTable();
QString getFullLatexTableEx();
QString getFullLatexTableEy();
QString getFullLatexTableR();
QString getLatex();
QString getLatexAboutParameters();
QString getLatexAnalysis();
QString getLatexInfo();
QString getLatexTable();
QString getLatexTableEx();
QString getLatexTableEy();
QString getLatexTableR();

//Возвращение переменных из класса
QString getAuthor();
bool getCheckAllCombinations();
HarrixClass_OnlyDataOfHarrixOptimizationTesting& getData();
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
qint64 getMaxCountOfFitness();
double getMeanEx(int Number_Of_Experiment);
double getMeanEy(int Number_Of_Experiment);
double getMeanR(int Number_Of_Experiment);
QString getNameAlgorithm();
QString getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter);
QString getNameTestFunction();
qint64 getNumberOfExperiments();
qint64 getNumberOfMeasuring();
int getNumberOfOption(QString NameOption);
qint64 getNumberOfParameters();
qint64 getNumberOfRuns();
int getParameter(int Number_Of_Experiment, int Number_Of_Parameter);
bool getSuccessReading();
double getVarianceOfEx(int Number_Of_Experiment);
double getVarianceOfEy(int Number_Of_Experiment);
double getVarianceOfR(int Number_Of_Experiment);
QString getVersion();

//Операторы
void operator = (HarrixClass_DataOfHarrixOptimizationTesting& B);

//Специализированные функции
QString makingLatexTable2D(QString Title, QStringList InfoForEveryExperiment);

private:
//Внутренние функции
void checkXmlLeafTags();
QString getLatexBegin();
QString getLatexEnd();
void initializationOfVariables();
void makingListOfVectorParameterOptions();
void memoryAllocation();
void memoryDeallocation();
void readXml();
void readXmlDataTags();
void readXmlLeafTag();
bool readXmlTreeTag(QString tag);
void zeroArray();

//Создание содержимого отчетов LaTeX и HTML
void makingHtmlReport();
void makingLatexAboutParameters();
void makingLatexAnalysis();
void makingLatexInfo();
void makingLatexListOfVectorParameterOptions();
void makingLatexTableEx();
void makingLatexTableEy();
void makingLatexTableR();

//Функции анализа данных
void makingAnalysis();

