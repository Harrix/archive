//Класс DataOfHarrixOptimizationTesting для считывания информации формата данных Harrix Optimization Testing
//Версия 1.1

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
    Error=false;//типа вначале нет ошибок в файле
    Un=HQt_RandomString(5);//уникальная строка для Latex

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Файл "+HQt_GetFilenameFromFullFilename(filename)+" не открывается");
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
                HtmlMessageOfError+=HQt_ShowAlert("Отсутствует основной тэг document");
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
                HtmlMessageOfError+=HQt_ShowAlert("Отсутствует тэг описания формата данных harrix_file_format");
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
                HtmlMessageOfError+=HQt_ShowAlert("Неправильный формат данных. Это не Harrix Optimization Testing");
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
                HtmlMessageOfError+=HQt_ShowAlert("Неправильная версия формата Harrix Optimization Testing. Данная функция обрабатывает версию 1.0");
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
                HtmlMessageOfError+=HQt_ShowAlert("Неправильный сайт в описании. Должен быть https://github.com/Harrix/HarrixFileFormats");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга about");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга об авторе");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о дате создания документа");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга about_data");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга об названии алгоритма name_algorithm");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о полном названии алгоритма full_name_algorithm");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о названии тестовой функции name_test_function");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о полном названии тестовой функции full_name_test_function");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о размерности тестовой задачи chromosome_length");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_measuring");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_runs");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга max_count_of_fitness");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_parameters");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_experiments");
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
                HtmlMessageOfError+=HQt_ShowAlert("Нет тэга data");
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

        //Вектор средних значений ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
        //Число элементов равно числу комбинаций вариантов настроек.
        MeanOfEx=new double[XML_Number_Of_Experiments];

        //Вектор средних ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
        //Число элементов равно числу комбинаций вариантов настроек.
        MeanOfEy=new double[XML_Number_Of_Experiments];

        //Вектор средних ошибок R алгоритма оптимизации по измерениям для каждой настройки.
        //Число элементов равно числу комбинаций вариантов настроек.
        MeanOfR=new double[XML_Number_Of_Experiments];

        //Вектор дисперсий ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
        //Число элементов равно числу комбинаций вариантов настроек.
        VarianceOfEx=new double[XML_Number_Of_Experiments];

        //Вектор дисперсий ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
        //Число элементов равно числу комбинаций вариантов настроек.
        VarianceOfEy=new double[XML_Number_Of_Experiments];

        //Вектор дисперсий ошибок R алгоритма оптимизации по измерениям для каждой настройки.
        //Число элементов равно числу комбинаций вариантов настроек.
        VarianceOfR=new double[XML_Number_Of_Experiments];

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
        TMHL_ZeroVector(MeanOfEx,XML_Number_Of_Experiments);
        TMHL_ZeroVector(MeanOfEy,XML_Number_Of_Experiments);
        TMHL_ZeroVector(MeanOfR ,XML_Number_Of_Experiments);
        TMHL_ZeroVector(VarianceOfEx,XML_Number_Of_Experiments);
        TMHL_ZeroVector(VarianceOfEy,XML_Number_Of_Experiments);
        TMHL_ZeroVector(VarianceOfR ,XML_Number_Of_Experiments);

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
                                HtmlMessageOfError+=HQt_ShowAlert("В тэге measuring были не все три тэга ex, ee, r (или вообще не было).");
                                Error=true;
                            }
                        }
                        else
                        {
                            //должен быть тэг measuring, а его нет
                            HtmlMessageOfError+=HQt_ShowAlert("Анализатор ожидал тэга measuring. Что не так в струтуре или данных файла.");
                            Error=true;
                        }
                    }

                }
                else
                {
                    //должен быть тэг experiment, а его нет
                    HtmlMessageOfError+=HQt_ShowAlert("Анализатор ожидал тэга experiment. Что не так в струтуре или данных файла.");
                    Error=true;
                }

            }

            Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
            i++;
        }

        if ((Rxml.hasError())||(Error))
        {
            HtmlMessageOfError+=HQt_ShowAlert("В процессе разбора файла обнаружены ошибки. Помните, что для этой функции обработки XML файла требуется правильный порядок следования тэгов.");
            Html+=HtmlMessageOfError;
            SuccessReading=false;
        }
        else
        {
            //++++++++++++++ Обработка полученной информации  ++++++++++++++++++++
            for (int i=0;i<XML_Number_Of_Experiments;i++)
            {
                //заполним значениями вектор средних значений критериев и


                for (int j=0;j<XML_Number_Of_Measuring;j++)
                {
                    MeanOfEx[i]+=MatrixOfEx[i][j];
                    MeanOfEy[i]+=MatrixOfEy[i][j];
                    MeanOfR[i] +=MatrixOfR[i][j];
                }

                MeanOfEx[i]/=double(XML_Number_Of_Measuring);
                MeanOfEy[i]/=double(XML_Number_Of_Measuring);
                MeanOfR[i] /=double(XML_Number_Of_Measuring);

                VarianceOfEx[i]+=TMHL_Variance(MatrixOfEx[i],XML_Number_Of_Measuring);
                VarianceOfEy[i]+=TMHL_Variance(MatrixOfEx[i],XML_Number_Of_Measuring);
                VarianceOfR [i]+=TMHL_Variance(MatrixOfR [i],XML_Number_Of_Measuring);
            }

            //++++++++++++++ Конец обработки полученной информации  ++++++++++++++


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

            //++++++++++++++ Обработка полученной информации Latex ++++++++++++++++
            NameForHead="алгоритма оптимизации <<"+HQt_StringForLaTeX(XML_Full_Name_Algorithm)+">>на тестовой функции <<"+HQt_StringForLaTeX(XML_Full_Name_Test_Function)+">> (размерность равна "+QString::number(XML_Chromosome_Length)+")";

            makingLatexInfo();
            makingLatexAboutParameters();
            makingLatexTableEx();//заполняем LatexTableEx
            makingLatexTableEy();//заполняем LatexTableEy
            makingLatexTableR();//заполняем LatexTableR

            Latex+=LatexInfo+LatexAboutParameters+LatexTableEx+LatexTableEy+LatexTableR;
            //++++++++++++++ Конец обработки полученной информации Latex ++++++++++

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
    delete [] MeanOfEx;
    delete [] MeanOfEy;
    delete [] MeanOfR;
    delete [] VarianceOfEx;
    delete [] VarianceOfEy;
    delete [] VarianceOfR;
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

void DataOfHarrixOptimizationTesting::makingLatexTableR()
{
    /*
    Создает текст LaTeX для отображения сырых данных по надежности в виде полной таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableR, которую можно вызвать getLatexTableR
     */
    //////////////////Сырые данные по R ///////////
    ////////////////////////////////////////////////
    LatexTableR+="\\subsection {Надёжность $R$}\n\n";
    LatexTableR+="Третьим критерием, по которому происходит сравнение алгоритмов оптимизации является надёжность $R$. ";
    LatexTableR+="Конкретные формулы, по которым происходило подсчитывание критерия в виде ошибки по значениям целевой функции вы можете найти на сайте в описании конкретной тестовой функции: \n";
    LatexTableR+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}.";
    LatexTableR+="\\begin{center}\n";
    LatexTableR+="{\\renewcommand{\\arraystretch}{1.5}\n";
    LatexTableR+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{2in}|m{0.2\\linewidth}|m{0.18\\linewidth}|m{0.18\\linewidth}|}\n";
    LatexTableR+="\\caption{Значения надёжности $R$ "+NameForHead+"}\n";
    LatexTableR+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":TableR}\n";
    LatexTableR+="\\tabularnewline\\hline\n";
    LatexTableR+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма}    & \\centering \\textbf{Значения ошибки $R$} & \\centering \\textbf{Среднее значение} & \\centering \\textbf{Дисперсия}  \\centering \\tabularnewline \\hline \\endhead\n";
    LatexTableR+="\\hline \\multicolumn{5}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexTableR+="\\hline \\endlastfoot";

    for (int i=0;i<XML_Number_Of_Experiments;i++)
    {
        Cell1.clear();
        Cell2.clear();
        Cell3.clear();
        Cell4.clear();
        Cell5.clear();
        //получим номер
        Cell1=QString::number(i+1);
        Cell1="\\centering "+Cell1;

        //получим значения параметров алгоритма
        Cell2="\\specialcelltwoin{";

        for (int j=0;j<XML_Number_Of_Parameters;j++)
        {
            Cell2+=MatrixOfNameParameters[i][j] +" \\\\ ";
        }

        Cell2+="}";
        Cell2="\\centering "+Cell2;

        //получим значения критерий
        Cell3="\\specialcell{";

        for (int j=0;j<XML_Number_Of_Measuring;j++)
        {
            Cell3+=QString::number(MatrixOfR[i][j])+" \\\\ ";
        }

        Cell3+="}";

        Cell3="\\centering "+Cell3;

        //получим средние значения критерия
        Cell4=QString::number(MeanOfR[i]);

        Cell4="\\centering "+Cell4;

        //получим значения дисперсии
        Cell5=QString::number(VarianceOfR[i]);

        Cell5="\\centering "+Cell5;

        LatexTableR+=Cell1+" & "+Cell2+" & "+Cell3+" & "+Cell4+" & "+Cell5+"\\tabularnewline \\hline\n";
    }

    LatexTableR+="\\end{longtable}\n";
    LatexTableR+="}\n";
    LatexTableR+="\\end{center}\n\n";

}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::makingLatexTableEy()
{
    /*
    Создает текст LaTeX для отображения сырых данных ошибки по значениям целевой функции в виде полной таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEy, которую можно вызвать getLatexTableEy
     */
    //////////////////Сырые данные по Ey ///////////
    ////////////////////////////////////////////////
    LatexTableEy+="\\subsection {Ошибка по значениям целевой функции $E_y$}\n\n";
    LatexTableEy+="Другим критерием, по которому происходит сравнение алгоритмов оптимизации является ошибка по значениям целевой функции $E_y$. ";
    LatexTableEy+="Конкретные формулы, по которым происходило подсчитывание критерия в виде ошибки по значениям целевой функции вы можете найти на сайте в описании конкретной тестовой функции: \n";
    LatexTableEy+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}.";
    LatexTableEy+="\\begin{center}\n";
    LatexTableEy+="{\\renewcommand{\\arraystretch}{1.5}\n";
    LatexTableEy+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{2in}|m{0.2\\linewidth}|m{0.18\\linewidth}|m{0.18\\linewidth}|}\n";
    LatexTableEy+="\\caption{Значения ошибки по значениям целевой функции $E_y$ "+NameForHead+"}\n";
    LatexTableEy+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":TableEy}\n";
    LatexTableEy+="\\tabularnewline\\hline\n";
    LatexTableEy+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма}    & \\centering \\textbf{Значения ошибки $E_y$} & \\centering \\textbf{Среднее значение} & \\centering \\textbf{Дисперсия}  \\centering \\tabularnewline \\hline \\endhead\n";
    LatexTableEy+="\\hline \\multicolumn{5}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexTableEy+="\\hline \\endlastfoot";

    for (int i=0;i<XML_Number_Of_Experiments;i++)
    {
        Cell1.clear();
        Cell2.clear();
        Cell3.clear();
        Cell4.clear();
        Cell5.clear();
        //получим номер
        Cell1=QString::number(i+1);
        Cell1="\\centering "+Cell1;

        //получим значения параметров алгоритма
        Cell2="\\specialcelltwoin{";

        for (int j=0;j<XML_Number_Of_Parameters;j++)
        {
            Cell2+=MatrixOfNameParameters[i][j] +" \\\\ ";
        }

        Cell2+="}";
        Cell2="\\centering "+Cell2;

        //получим значения критерий
        Cell3="\\specialcell{";

        for (int j=0;j<XML_Number_Of_Measuring;j++)
        {
            Cell3+=QString::number(MatrixOfEy[i][j])+" \\\\ ";
        }

        Cell3+="}";

        Cell3="\\centering "+Cell3;

        //получим средние значения критерия
        Cell4=QString::number(MeanOfEy[i]);

        Cell4="\\centering "+Cell4;

        //получим значения дисперсии
        Cell5=QString::number(VarianceOfEy[i]);

        Cell5="\\centering "+Cell5;

        LatexTableEy+=Cell1+" & "+Cell2+" & "+Cell3+" & "+Cell4+" & "+Cell5+"\\tabularnewline \\hline\n";
    }

    LatexTableEy+="\\end{longtable}\n";
    LatexTableEy+="}\n";
    LatexTableEy+="\\end{center}\n\n";
}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::makingLatexTableEx()
{
    /*
    Создает текст LaTeX для отображения сырых данных ошибки по входным параметрам в виде полной таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEx, которую можно вызвать getLatexTableEx
     */
    //////////////////Сырые данные по Ex ///////////
    ////////////////////////////////////////////////
    LatexTableEx+="\\subsection {Ошибка по входным параметрам $E_x$}\n\n";
    LatexTableEx+="Одним из критериев, по которому происходит сравнение алгоритмов оптимизации является ошибка по входным параметрам $E_x$. ";
    LatexTableEx+="В результате проделанных экспериментов были получены следующие данные, представленные ниже в таблице. ";
    LatexTableEx+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}.";
    LatexTableEx+="\\begin{center}\n";
    LatexTableEx+="{\\renewcommand{\\arraystretch}{1.5}\n";
    LatexTableEx+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{2in}|m{0.2\\linewidth}|m{0.18\\linewidth}|m{0.18\\linewidth}|}\n";
    LatexTableEx+="\\caption{Значения ошибки по выходным параметрам $E_x$ "+NameForHead+"}\n";
    LatexTableEx+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":TableEx}\n";
    LatexTableEx+="\\tabularnewline\\hline\n";
    LatexTableEx+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма}    & \\centering \\textbf{Значения ошибки $E_x$} & \\centering \\textbf{Среднее значение} & \\centering \\textbf{Дисперсия}  \\centering \\tabularnewline \\hline \\endhead\n";
    LatexTableEx+="\\hline \\multicolumn{5}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexTableEx+="\\hline \\endlastfoot";

    for (int i=0;i<XML_Number_Of_Experiments;i++)
    {
        Cell1.clear();
        Cell2.clear();
        Cell3.clear();
        Cell4.clear();
        Cell5.clear();
        //получим номер
        Cell1=QString::number(i+1);
        Cell1="\\centering "+Cell1;

        //получим значения параметров алгоритма
        Cell2="\\specialcelltwoin{";

        for (int j=0;j<XML_Number_Of_Parameters;j++)
        {
            Cell2+=MatrixOfNameParameters[i][j] +" \\\\ ";
        }

        Cell2+="}";
        Cell2="\\centering "+Cell2;

        //получим значения критерий
        Cell3="\\specialcell{";

        for (int j=0;j<XML_Number_Of_Measuring;j++)
        {
            Cell3+=QString::number(MatrixOfEx[i][j])+" \\\\ ";
        }

        Cell3+="}";

        Cell3="\\centering "+Cell3;

        //получим средние значения критерия
        Cell4=QString::number(MeanOfEx[i]);

        Cell4="\\centering "+Cell4;

        //получим значения дисперсии
        Cell5=QString::number(VarianceOfEx[i]);

        Cell5="\\centering "+Cell5;

        LatexTableEx+=Cell1+" & "+Cell2+" & "+Cell3+" & "+Cell4+" & "+Cell5+"\\tabularnewline \\hline\n";
    }

    LatexTableEx+="\\end{longtable}\n";
    LatexTableEx+="}\n";
    LatexTableEx+="\\end{center}\n\n";
}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::makingLatexInfo()
{
    /*
    Создает текст LaTeX для отображения информации о исследовании.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEx, которую можно вызвать getLatexInfo
     */
    LatexInfo+="\\section{Исследование эффективности "+NameForHead+"}\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":Name_Algorithm}\n\n";
    LatexInfo+="В данной работе, автором проведено исследование алгоритма <<"+HQt_StringForLaTeX(XML_Full_Name_Algorithm)+">>. Ниже приведена информация об этом исследовании.\n\n";
    LatexInfo+="\\subsection {Информация об исследовании}\n\n";
    LatexInfo+="\\begin{tabularwide}\n";
    LatexInfo+="\\textbf{Автор исследования}: & "+HQt_StringForLaTeX(XML_Author)+". \\\\ \n";
    LatexInfo+="\\textbf{Дата создания исследования}: & "+HQt_StringForLaTeX(XML_Date)+". \\\\ \n";
    LatexInfo+="\\textbf{Идентификатор алгоритма}: & "+HQt_StringForLaTeX(XML_Name_Algorithm)+". \\\\ \n";
    LatexInfo+="\\textbf{Полное название алгоритма}: & "+HQt_StringForLaTeX(XML_Full_Name_Algorithm)+". \\\\ \n";
    LatexInfo+="\\textbf{Идентификатор исследуемой тестовой функции}: & "+HQt_StringForLaTeX(XML_Name_Test_Function)+". \\\\ \n";
    LatexInfo+="\\textbf{Полное название тестовой функции}: & "+HQt_StringForLaTeX(XML_Full_Name_Test_Function)+". \\\\ \n";
    LatexInfo+="\\end{tabularwide}\n\n";
    LatexInfo+="\\begin{tabularwide08}\n";
    LatexInfo+="\\textbf{Размерность тестовой функции:} & "+QString::number(XML_Chromosome_Length)+" \\\\ \n";
    LatexInfo+="\\textbf{Количество измерений для каждого варианта настроек алгоритма}: & "+QString::number(XML_Number_Of_Measuring)+" \\\\ \n";
    LatexInfo+="\\textbf{Количество запусков алгоритма в каждом из экспериментов}: & "+QString::number(XML_Number_Of_Runs)+" \\\\ \n";
    LatexInfo+="\\textbf{Максимальное допустимое число вычислений целевой функции}: & "+QString::number(XML_Max_Count_Of_Fitness)+" \\\\ \n";
    LatexInfo+="\\textbf{Количество проверяемых параметров алгоритма оптимизации}: & "+QString::number(XML_Number_Of_Parameters)+" \\\\ \n";
    LatexInfo+="\\textbf{Количество проверяемых параметров алгоритма оптимизации}: & "+QString::number(XML_Number_Of_Experiments)+" \\\\ \n";
    LatexInfo+="\\textbf{Общий объем максимального числа вычислений целевой функции во всем исследовании}: & "+QString::number(XML_Number_Of_Experiments*XML_Max_Count_Of_Fitness*XML_Number_Of_Measuring*XML_Number_Of_Runs)+" \\\\ \n";
    LatexInfo+="\\end{tabularwide08}\n\n";
    LatexInfo+="Информацию о исследуемой функции можно найти по адресу:\n\n";
    LatexInfo+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}\n\n";
    LatexInfo+="Информацию о исследуемом алгоритме оптимизации можно найти по адресу:\n\n";
    LatexInfo+="\\href{https://github.com/Harrix/HarrixOptimizationAlgorithms}{https://github.com/Harrix/HarrixOptimizationAlgorithms}\n\n";
}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::makingLatexAboutParameters()
{
    /*
    Создает текст LaTeX для отображения данных о обнаруженных параметрах алгоритма и какие они бывают.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEx, которую можно вызвать getLatexAboutParameters
     */
    LatexAboutParameters+="\\subsection {Параметры алгоритма оптимизации}\n\n";
    LatexAboutParameters+="Исследуемый алгоритм оптимизации проверялся по эффективности по некоторому конечному множеству возможных настроек алгоритма. ";
    LatexAboutParameters+="Как написано выше, всего возможных параметров алгоритма было "+QString::number(XML_Number_Of_Parameters)+" штук. ";
    LatexAboutParameters+="В формуле \\ref{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":Parameters} показано множество проверяемых параметров алгоритма.\n\n";
    LatexAboutParameters+="\\begin{equation}\n";
    LatexAboutParameters+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":Parameters}\n";
    LatexAboutParameters+="Parameters = \\left( \\begin{array}{c} ";
    if (HQt_MaxCountOfQStringList(NamesOfParameters)>57)
        Parbox="\\parbox{\\dimexpr \\linewidth-3in}";
    else
        Parbox="";
    for (int i=0;i<NamesOfParameters.count();i++)
    {
        LatexAboutParameters+=Parbox+"{\\centering\\textit{"+HQt_StringForLaTeX(NamesOfParameters.at(i))+"}} ";
        if (i!=NamesOfParameters.count()-1) LatexAboutParameters+="\\\\ ";
    }
    LatexAboutParameters+="\\end{array}\\right). ";
    LatexAboutParameters+="\\end{equation}\n\n";
    LatexAboutParameters+="Теперь рассмотрим, какие значения может принимать каждый из параметров.";

    for (int j=0;j<XML_Number_Of_Parameters;j++)
    {
        LatexAboutParameters+="\\begin{equation}\n";
        LatexAboutParameters+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":parameter_"+QString::number(j+1)+"}\n";
        LatexAboutParameters+="Parameters^{"+QString::number(j+1)+"} \\in \\left\\lbrace  \\begin{array}{c} ";
        if (HQt_MaxCountOfQStringList(ListOfParameterOptions[j])>57)
            Parbox="\\parbox{\\dimexpr \\linewidth-3in}";
        else
            Parbox="";
        for (int i=0;i<ListOfParameterOptions[j].count();i++)
        {
            LatexAboutParameters+=Parbox+"{\\centering\\textit{"+HQt_StringForLaTeX(ListOfParameterOptions[j].at(i))+"}} ";
            if (i!=ListOfParameterOptions[j].count()-1) LatexAboutParameters+="\\\\ ";
        }
        LatexAboutParameters+="\\end{array}\\right\\rbrace . ";
        LatexAboutParameters+="\\end{equation}\n\n";
    }
}
//--------------------------------------------------------------------------
