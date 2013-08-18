//Класс DataOfHarrixOptimizationTesting для считывания информации формата данных Harrix Optimization Testing
//Версия 1.0

#include "QtHarrixLibrary.h"
#include "QtHarrixLibraryForQWebView.h"
#include "MathHarrixLibrary.h"
#include "DataOfHarrixOptimizationTesting.h"

DataOfHarrixOptimizationTesting::DataOfHarrixOptimizationTesting(QString filename)
{
    /*
    Конструктор. Функция считывает данные о тестировании алгоритма оптимизации
    из файла формата HarrixOptimizationTesting.
    Входные параметры:
     filename - полное имя считываемого файла;
 */
    SuccessReading=true;
    Html="";
    Latex="";
    //++++++++++++ Конец возвращаемых переменных ++++++++

    //++++++++++++ Переменные итоговые ++++++++++++++++++
    XML_Chromosome_Length=0;//Размерность тестовой задачи (длина хромосомы решения)
    XML_Number_Of_Measuring=0;//Количество экспериментов для каждого набора параметров алгоритма
    XML_Number_Of_Runs=0;//Количество прогонов по которому деляется усреднение для эксперимента
    XML_Max_Count_Of_Fitness=0;//Максимальное допустимое число вычислений целевой функции для алгоритма
    XML_Number_Of_Parameters=0;//Количество проверяемых параметров алгоритма оптимизации
    XML_Number_Of_Experiments=0;//Количество комбинаций вариантов настроек
    //++++++++++++ Конец переменных итоговых ++++++++++++

    QXmlStreamReader Rxml;//непосредственно анализируемый xml файл
    QFile file(filename);//для открытия файла и запихивания его в Rxml
    bool Error=false;//типа вначале нет ошибок в файле

    QString NameOfElement;//имя тэга
    QString TextOfElement;//содержимое тэга
    QString AttrOfElement;//содержимое аттрибута тэга
    QString NameOfAttr;//название атрибута тэга

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        Html+=HQt_ShowAlert("Файл "+HQt_GetFilenameFromFullFilename(filename)+" не открывается");
        Error=true;
    }
    else
    {
        Html+=HQt_ShowText("Файл <font color=\"#00b400\">"+HQt_GetFilenameFromFullFilename(filename)+"</font> загружен");

        //первоначальные действия
        Rxml.setDevice(&file);
        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}//первый нормальный элемент

        //Начнем анализ документа

        //проверка тэга document
        if (!Rxml.atEnd())
        {
            NameOfElement=Rxml.name().toString().toLower();
            if (NameOfElement!="document")
            {
                Html+=HQt_ShowAlert("Отсутствует основной тэг document");
                Error=true;
            }
            else
            {
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга harrix_file_format
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            if (NameOfElement!="harrix_file_format")
            {
                Html+=HQt_ShowAlert("Отсутствует тэг описания формата данных harrix_file_format");
                Error=true;
            }
            else
            {
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга format
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if ((NameOfElement!="format")||(TextOfElement!="Harrix Optimization Testing"))
            {
                Html+=HQt_ShowAlert("Неправильный формат данных. Это не Harrix Optimization Testing");
                Error=true;
            }
            else
            {
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга format
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if ((NameOfElement!="version")||(TextOfElement!="1.0"))
            {
                Html+=HQt_ShowAlert("Неправильная версия формата Harrix Optimization Testing. Данная функция обрабатывает версию 1.0");
                Error=true;
            }
            else
            {
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга site
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if ((NameOfElement!="site")||(TextOfElement!="https://github.com/Harrix/HarrixFileFormats"))
            {
                Html+=HQt_ShowAlert("Неправильный сайт в описании. Должен быть https://github.com/Harrix/HarrixFileFormats");
                Error=true;
            }
            else
            {
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга about
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            if (NameOfElement!="about")
            {
                Html+=HQt_ShowAlert("Нет тэга about");
                Error=true;
            }
            else
            {
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга author
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="author")
            {
                Html+=HQt_ShowAlert("Нет тэга об авторе");
                Error=true;
            }
            else
            {
                XML_Author=TextOfElement;
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга date
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="date")
            {
                Html+=HQt_ShowAlert("Нет тэга о дате создания документа");
                Error=true;
            }
            else
            {
                XML_Date=TextOfElement;
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга about_data
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            if (NameOfElement!="about_data")
            {
                Html+=HQt_ShowAlert("Нет тэга about_data");
                Error=true;
            }
            else
            {
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга name_algorithm
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="name_algorithm")
            {
                Html+=HQt_ShowAlert("Нет тэга об названии алгоритма name_algorithm");
                Error=true;
            }
            else
            {
                XML_Name_Algorithm=TextOfElement;
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга full_name_algorithm
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="full_name_algorithm")
            {
                Html+=HQt_ShowAlert("Нет тэга о полном названии алгоритма full_name_algorithm");
                Error=true;
            }
            else
            {
                XML_Full_Name_Algorithm=TextOfElement;
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга name_test_function
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="name_test_function")
            {
                Html+=HQt_ShowAlert("Нет тэга о названии тестовой функции name_test_function");
                Error=true;
            }
            else
            {
                XML_Name_Test_Function=TextOfElement;
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга full_name_test_function
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="full_name_test_function")
            {
                Html+=HQt_ShowAlert("Нет тэга о полном названии тестовой функции full_name_test_function");
                Error=true;
            }
            else
            {
                XML_Full_Name_Test_Function=TextOfElement;
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга chromosome_length
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="chromosome_length")
            {
                Html+=HQt_ShowAlert("Нет тэга о размерности тестовой задачи chromosome_length");
                Error=true;
            }
            else
            {
                XML_Chromosome_Length=TextOfElement.toInt();
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга number_of_measuring
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="number_of_measuring")
            {
                Html+=HQt_ShowAlert("Нет тэга number_of_measuring");
                Error=true;
            }
            else
            {
                XML_Number_Of_Measuring=TextOfElement.toInt();
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга number_of_runs
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="number_of_runs")
            {
                Html+=HQt_ShowAlert("Нет тэга number_of_runs");
                Error=true;
            }
            else
            {
                XML_Number_Of_Runs=TextOfElement.toInt();
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга max_count_of_fitness
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="max_count_of_fitness")
            {
                Html+=HQt_ShowAlert("Нет тэга max_count_of_fitness");
                Error=true;
            }
            else
            {
                XML_Max_Count_Of_Fitness=TextOfElement.toInt();
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга number_of_parameters
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="number_of_parameters")
            {
                Html+=HQt_ShowAlert("Нет тэга number_of_parameters");
                Error=true;
            }
            else
            {
                XML_Number_Of_Parameters=TextOfElement.toInt();
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга number_of_experiments
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            TextOfElement=Rxml.readElementText();
            if (NameOfElement!="number_of_experiments")
            {
                Html+=HQt_ShowAlert("Нет тэга number_of_experiments");
                Error=true;
            }
            else
            {
                XML_Number_Of_Experiments=TextOfElement.toInt();
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //проверка тэга data
        if ((!Rxml.atEnd())&&(!Error))
        {
            NameOfElement=Rxml.name().toString().toLower();
            if (NameOfElement!="data")
            {
                Html+=HQt_ShowAlert("Нет тэга data");
                Error=true;
            }
            else
            {
                Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            }
        }

        //////////////// ВЫДЕЛЕНИЕ ПАМЯТИ ПОД МАССИВЫ //////////////////////////////////

        //Матрица значений ошибок Ex алгоритма оптимизации.
        //Число строк равно числу комбинаций вариантов настроек.
        //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
        MatrixOfEx=new double*[XML_Number_Of_Experiments];
        for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfEx[i]=new double[XML_Number_Of_Measuring];

        //Матрица значений ошибок Ey алгоритма оптимизации.
        //Число строк равно числу комбинаций вариантов настроек.
        //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
        MatrixOfEy=new double*[XML_Number_Of_Experiments];
        for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfEy[i]=new double[XML_Number_Of_Measuring];

        //Матрица значений ошибок R алгоритма оптимизации.
        //Число строк равно числу комбинаций вариантов настроек.
        //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
        MatrixOfR=new double*[XML_Number_Of_Experiments];
        for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfR[i]=new double[XML_Number_Of_Measuring];

        //Матрица значений параметров для каждой комбинации вариантов настроек.
        //Число строк равно числу комбинаций вариантов настроек.
        //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
        MatrixOfParameters=new int*[XML_Number_Of_Experiments];
        for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfParameters[i]=new int[XML_Number_Of_Parameters];

        //Вектор названий вариантов параметров алгоритма оптимизации.
        //Число элементов равно числу проверяемых параметров алгоритма оптимизации.
        //Элементы будут заноситься по мере обнаружений новых вариантов алгоритма.
        //Номера вариантов параметров алгоритма в конкретном списке QStringList будет совпадать
        //с номерами из MatrixOfParameters. То есть, что записано в MatrixOfParameters в ListOfParameterOptions
        //находится под номером соответствующим.
        ListOfParameterOptions=new QStringList[XML_Number_Of_Parameters];

        //Матрица значений параметров для каждой комбинации вариантов настроек.
        //Элементы не в виде чисел, а в виде наименований этих параметров.
        //Число строк равно числу комбинаций вариантов настроек.
        //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
        MatrixOfNameParameters=new QStringList[XML_Number_Of_Experiments];
        //////////////// ВЫДЕЛЕНИЕ ПАМЯТИ ПОД МАССИВЫ //////////////////////////////////

        //"Обнулим" матрицы
        TMHL_FillMatrix(MatrixOfEx, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);
        TMHL_FillMatrix(MatrixOfEy, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);
        TMHL_FillMatrix(MatrixOfR,  XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);
        TMHL_FillMatrix(MatrixOfParameters,  XML_Number_Of_Experiments, XML_Number_Of_Parameters, -1);
        for (int k=0;k<XML_Number_Of_Parameters;k++) ListOfParameterOptions[k].clear();
        (NamesOfParameters).clear();

        //Теперь должны пойти данные об экспериментах
        int i=0;//номер варианта настройки алгоритма
        bool bool_ex;
        bool bool_ey;
        bool bool_r;
        while(!Rxml.atEnd())
        {
            if(Rxml.isStartElement())
            {
                NameOfElement=Rxml.name().toString().toLower();

                if (NameOfElement=="experiment")
                {
                    for (int k=0;k<XML_Number_Of_Parameters;k++)
                    {
                        //считаем массив параметров алгоритма
                        NameOfAttr="parameters_of_algorithm_"+QString::number(k+1);
                        AttrOfElement = Rxml.attributes().value(NameOfAttr).toString();

                        //считываеv названия параметров алгорима
                        if (i==0) NamesOfParameters << HQt_TextBeforeEqualSign(AttrOfElement);

                        //теперь значения параметров алгоритма
                        ListOfParameterOptions[k] = HQt_AddUniqueQStringInQStringList (ListOfParameterOptions[k], HQt_TextAfterEqualSign(AttrOfElement));

                        MatrixOfParameters[i][k]=HQt_SearchQStringInQStringList (ListOfParameterOptions[k], HQt_TextAfterEqualSign(AttrOfElement));
                        MatrixOfNameParameters[i] << HQt_TextAfterEqualSign(AttrOfElement);
                    }

                    for (int k=0;k<XML_Number_Of_Measuring;k++)
                    {
                        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
                        NameOfElement=Rxml.name().toString().toLower();

                        if (NameOfElement=="measuring")
                        {
                            bool_ex = false;
                            bool_ey = false;
                            bool_r = false;

                            Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
                            NameOfElement=Rxml.name().toString().toLower();

                            if (NameOfElement=="ex")
                            {
                                MatrixOfEx[i][k]=(Rxml.readElementText()).toDouble();
                                bool_ex=true;
                            }

                            if (NameOfElement=="ey")
                            {
                                MatrixOfEy[i][k]=(Rxml.readElementText()).toDouble();
                                bool_ey=true;
                            }

                            if (NameOfElement=="r")
                            {
                                MatrixOfR[i][k]=(Rxml.readElementText()).toDouble();
                                bool_r=true;
                            }

                            Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
                            NameOfElement=Rxml.name().toString().toLower();

                            if (NameOfElement=="ex")
                            {
                                MatrixOfEx[i][k]=(Rxml.readElementText()).toDouble();
                                bool_ex=true;
                            }

                            if (NameOfElement=="ey")
                            {
                                MatrixOfEy[i][k]=(Rxml.readElementText()).toDouble();
                                bool_ey=true;
                            }

                            if (NameOfElement=="r")
                            {
                                MatrixOfR[i][k]=(Rxml.readElementText()).toDouble();
                                bool_r=true;
                            }

                            Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
                            NameOfElement=Rxml.name().toString().toLower();

                            if (NameOfElement=="ex")
                            {
                                MatrixOfEx[i][k]=(Rxml.readElementText()).toDouble();
                                bool_ex=true;
                            }

                            if (NameOfElement=="ey")
                            {
                                MatrixOfEy[i][k]=(Rxml.readElementText()).toDouble();
                                bool_ey=true;
                            }

                            if (NameOfElement=="r")
                            {
                                MatrixOfR[i][k]=(Rxml.readElementText()).toDouble();
                                bool_r=true;
                            }

                            if (!((bool_ex)&&(bool_ey)&&(bool_r)))
                            {
                                Html+=HQt_ShowAlert("В тэге measuring были не все три тэга ex, ee, r (или вообще не было).");
                                Error=true;
                            }
                        }
                        else
                        {
                            //должен быть тэг measuring, а его нет
                            Html+=HQt_ShowAlert("Анализатор ожидал тэга measuring. Что не так в струтуре или данных файла.");
                            Error=true;
                        }
                    }

                }
                else
                {
                    //должен быть тэг experiment, а его нет
                    Html+=HQt_ShowAlert("Анализатор ожидал тэга experiment. Что не так в струтуре или данных файла.");
                    Error=true;
                }

            }

            Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            i++;
        }

        if ((Rxml.hasError())||(Error))
        {
            Html+=HQt_ShowAlert("В процессе разбора файла обнаружены ошибки. Помните, что для этой функции обработки XML файла требуется правильный порядок следования тэгов.");
            SuccessReading=false;
        }
        else
        {
            //++++++++++++++ Обработка полученной информации Html ++++++++++++++++
            Html+=HQt_ShowHr();
            Html+=HQt_ShowH1("Данные о файле");
            Html+=HQt_ShowSimpleText("<b>Автор документа:</b> "+XML_Author+".");
            Html+=HQt_ShowSimpleText("<b>Дата создания документа:</b> "+XML_Date+".");
            Html+=HQt_ShowHr();
            Html+=HQt_ShowH1("Данные о собранных данных");
            Html+=HQt_ShowSimpleText("<b>Обозначение алгоритма:</b> "+XML_Name_Algorithm+".");
            Html+=HQt_ShowSimpleText("<b>Полное название алгоритма:</b> "+XML_Full_Name_Algorithm+".");
            Html+=HQt_ShowSimpleText("<b>Название тестовой функции:</b> "+XML_Name_Test_Function+".");
            Html+=HQt_ShowSimpleText("<b>Полное название тестовой функции:</b> "+XML_Full_Name_Test_Function+".");
            Html+=HQt_ShowSimpleText("<b>Размерность задачи оптимизации:</b> "+QString::number(XML_Chromosome_Length)+".");
            Html+=HQt_ShowSimpleText("<b>Количество измерений для каждого варианта настроек алгоритма:</b> "+QString::number(XML_Number_Of_Measuring)+".");
            Html+=HQt_ShowSimpleText("<b>Количество запусков алгоритма в каждом из экспериментов:</b> "+QString::number(XML_Number_Of_Runs)+".");
            Html+=HQt_ShowSimpleText("<b>Максимальное допустимое число вычислений целевой функции:</b> "+QString::number(XML_Max_Count_Of_Fitness)+".");
            Html+=HQt_ShowSimpleText("<b>Количество проверяемых параметров алгоритма оптимизации:</b> "+QString::number(XML_Number_Of_Parameters)+".");
            Html+=HQt_ShowSimpleText("<b>Количество комбинаций вариантов настроек:</b> "+QString::number(XML_Number_Of_Experiments)+".");
            Html+=HQt_ShowHr();
            Html+=HQt_ShowH1("Собранные данные");
            Html+=THQt_ShowMatrix(MatrixOfEx,XML_Number_Of_Experiments,XML_Number_Of_Measuring,"Ошибки по входным параметрам","Ex");
            Html+=THQt_ShowMatrix(MatrixOfEy,XML_Number_Of_Experiments,XML_Number_Of_Measuring,"Ошибки по значениям целевой функции","Ey");
            Html+=THQt_ShowMatrix(MatrixOfR, XML_Number_Of_Experiments,XML_Number_Of_Measuring,"Надежности","R");
            Html+=THQt_ShowVector(NamesOfParameters,"Вектора названий параметров алгоримта","NamesOfParameters");
            for (int j=0;j<XML_Number_Of_Parameters;j++)
                Html+=THQt_ShowVector(ListOfParameterOptions[j],(NamesOfParameters).at(j) + "(возможные принимаемые значения)","ParameterOptions");
            Html+=THQt_ShowMatrix(MatrixOfParameters,XML_Number_Of_Experiments,XML_Number_Of_Parameters,"Матрица параметров по номерам","MatrixOfParameters");
            //Html+=THQt_ShowMatrix(MatrixOfNameParameters,XML_Number_Of_Experiments,"Матрица параметров по именам","MatrixOfParameters");


            //++++++++++++++ Конец обработки полученной информации Html ++++++++++

            Html+=HQt_ShowHr();
            Html+=HQt_ShowText("Обработка файла завершена. Ошибки не обнаружены");
        }
    }

    file.close();
}
//--------------------------------------------------------------------------

DataOfHarrixOptimizationTesting::~DataOfHarrixOptimizationTesting()
{
    /*
     Деконструктор класса.
     */
    for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfEx[i];
    delete [] MatrixOfEx;
    for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfEy[i];
    delete [] MatrixOfEy;
    for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfR[i];
    delete [] MatrixOfR;
    for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfParameters[i];
    delete [] MatrixOfParameters;
    delete [] ListOfParameterOptions;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getHtml()
{
    /*
     Получение текста переменной Html
     */
    return Html;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getLatex()
{
    /*
     Получение текста переменной Latex.
     */
    return Latex;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getAuthor()
{
    /*
     Получение текста переменной XML_Author - Автор документа
     */
    return XML_Author;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getDate()
{
    /*
     Получение текста переменной  XML_Date - Дата создания документа
     */
    return XML_Date;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getNameAlgorithm()
{
    /*
     Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации
     */
    return XML_Name_Algorithm;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getFullNameAlgorithm()
{
    /*
     Получение текста переменной  XML_Full_Name_Algorithm - Полное название алгоритма оптимизации
     */
    return XML_Full_Name_Algorithm;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getNameTestFunction()
{
    /*
     Получение текста переменной  XML_Name_Test_Function - Название тестовой функции
     */
    return XML_Name_Test_Function;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getFullNameTestFunction()
{
    /*
     Получение текста переменной  XML_Full_Name_Test_Function - Полное название тестовой функции
     */
    return XML_Full_Name_Test_Function;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getChromosomeLength()
{
    /*
     Получение текста переменной  XML_Chromosome_Length - Размерность тестовой задачи (длина хромосомы решения)
     */
    return XML_Chromosome_Length;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getNumberOfMeasuring()
{
    /*
     Получение текста переменной  XML_Number_Of_Measuring - Размерность тестовой задачи (длина хромосомы решения)
     */
    return XML_Number_Of_Measuring;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getNumberOfRuns()
{
    /*
     Получение текста переменной  XML_Number_Of_Runs - Количество прогонов по которому деляется усреднение для эксперимента
     */
    return XML_Number_Of_Runs;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getMaxCountOfFitness()
{
    /*
     Получение текста переменной  Max_Count_Of_Fitness - Максимальное допустимое число вычислений целевой функции для алгоритма
     */
    return XML_Max_Count_Of_Fitness;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getNumberOfParameters()
{
    /*
     Получение текста переменной  XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации
     */
    return XML_Number_Of_Parameters;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getNumberOfExperiments()
{
    /*
     Получение текста переменной  XML_Number_Of_Experiments - Количество комбинаций вариантов настроек
     */
    return XML_Number_Of_Experiments;
}
//--------------------------------------------------------------------------

double DataOfHarrixOptimizationTesting::getErrorEx(int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Получение значения ошибки Ex.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Значения ошибки Ex.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    return MatrixOfEx[Number_Of_Experiment][Number_Of_Measuring];
}
//--------------------------------------------------------------------------

double DataOfHarrixOptimizationTesting::getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Получение значения ошибки Ey.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Значения ошибки Ey.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    return MatrixOfEy[Number_Of_Experiment][Number_Of_Measuring];
}
//--------------------------------------------------------------------------

double DataOfHarrixOptimizationTesting::getErrorR(int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Получение значения надежности R.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Значения надежности R.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    return MatrixOfR[Number_Of_Experiment][Number_Of_Measuring];
}
//--------------------------------------------------------------------------

bool DataOfHarrixOptimizationTesting::getSuccessReading()
{
    /*
    Получение значения переменной SuccessReading о удачности или неудачности прочитывания файла.
     */
    return SuccessReading;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getParameter(int Number_Of_Experiment, int Number_Of_Parameter)
{
    /*
    Получение значения параметра настройки какой-то.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Значения параметра в виде числа (соответствие находим в ListOfParameterOptions).
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    return MatrixOfParameters[Number_Of_Experiment][Number_Of_Parameter];
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter)
{
    /*
    Получение значения параметра настройки какой-то в виде полного наименования.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Значения параметра в виде наименования.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    return MatrixOfNameParameters[Number_Of_Experiment][Number_Of_Parameter];
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getNameOption(int Number_Of_Parameter)
{
    /*
    Получение имени параметра алгоритма по его номеру.
    Входные параметры:
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Значения параметра в виде наименования.
     */
    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    return NamesOfParameters[Number_Of_Parameter];
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getNumberOfOption(QString NameOption)
{
    /*
    Получение номера параметра алгоритма по его имени.
    Входные параметры:
     NameOption - имя параметра.
    Возвращаемое значение:
     Значения параметра в виде номера (если не найдено, то возвращается -1.
     */
    int VMHL_Result=-1;

    VMHL_Result = HQt_SearchQStringInQStringList (NamesOfParameters, NameOption);

    return VMHL_Result;
}
//--------------------------------------------------------------------------