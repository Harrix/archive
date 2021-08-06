void HarrixClass_DataOfHarrixOptimizationTesting::readXmlDataTags()
{
    /*
    Считывает и проверяет тэги данных. Внутренняя функция.
    Учитывает все "листовые" тэги кроме тэгов данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */

    //Теперь должны пойти данные об экспериментах
    int i=0;//номер варианта настройки алгоритма
    bool bool_ex;
    bool bool_ey;
    bool bool_r;
    bool is_number;
    while(!Rxml.atEnd())
    {
        if(Rxml.isStartElement())
        {
            NameOfElement=Rxml.name().toString().toLower();

            if (NameOfElement=="experiment")
            {
                //если параметров нет, то имитируем один NULL парметр
                if (Zero_Number_Of_Parameters)
                {
                    Data.addNameOption("NULL");
                    Data.setParameter(0,0,0);
                    Data.addNameParameter("NULL",0);
                }
                else
                {
                    for (int k=0;k<Data.getNumberOfParameters();k++)
                    {
                        //считаем массив параметров алгоритма
                        NameOfAttr="parameters_of_algorithm_"+QString::number(k+1);
                        AttrOfElement = Rxml.attributes().value(NameOfAttr).toString();

                        //считывает названия параметров алгоритма
                        if (i==0) Data.addNameOption(HQt_TextBeforeEqualSign(AttrOfElement));

                        //теперь значения параметров алгоритма
                        Data.setListOfParameterOptions(HQt_AddUniqueQStringInQStringList (Data.getListOfParameterOptions(k), HQt_TextAfterEqualSign(AttrOfElement)),k);

                        Data.setParameter(HQt_SearchQStringInQStringList (Data.getListOfParameterOptions(k), HQt_TextAfterEqualSign(AttrOfElement)),i,k);

                        Data.addNameParameter(HQt_TextAfterEqualSign(AttrOfElement),i);
                    }
                }

                for (int k=0;k<Data.getNumberOfMeasuring();k++)
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
                        TextOfElement=Rxml.readElementText();
                        is_number=HQt_IsNumeric(TextOfElement);
                        if (!is_number)
                        {
                            HtmlMessageOfError+=HQt_ShowAlert("Ошибка Ex не является числом. Вместо числа получили вот это: "+TextOfElement);
                            Error=true;
                        }

                        if (NameOfElement=="ex")
                        {
                            Data.setErrorEx(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ex=true;
                        }

                        if (NameOfElement=="ey")
                        {
                            Data.setErrorEy(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ey=true;
                        }

                        if (NameOfElement=="r")
                        {
                            Data.setErrorR(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_r=true;
                        }

                        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
                        NameOfElement=Rxml.name().toString().toLower();
                        TextOfElement=Rxml.readElementText();
                        is_number=HQt_IsNumeric(TextOfElement);
                        if (!is_number)
                        {
                            HtmlMessageOfError+=HQt_ShowAlert("Ошибка Ex не является числом. Вместо числа получили вот это: "+TextOfElement);
                            Error=true;
                        }

                        if (NameOfElement=="ex")
                        {
                            Data.setErrorEx(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ex=true;
                        }

                        if (NameOfElement=="ey")
                        {
                            Data.setErrorEy(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ey=true;
                        }

                        if (NameOfElement=="r")
                        {
                            Data.setErrorR(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_r=true;
                        }

                        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
                        NameOfElement=Rxml.name().toString().toLower();
                        TextOfElement=Rxml.readElementText();
                        is_number=HQt_IsNumeric(TextOfElement);
                        if (!is_number)
                        {
                            HtmlMessageOfError+=HQt_ShowAlert("Ошибка Ex не является числом. Вместо числа получили вот это: "+TextOfElement);
                            Error=true;
                        }

                        if (NameOfElement=="ex")
                        {
                            Data.setErrorEx(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ex=true;
                        }

                        if (NameOfElement=="ey")
                        {
                            Data.setErrorEy(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ey=true;
                        }

                        if (NameOfElement=="r")
                        {
                            Data.setErrorR(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_r=true;

                            if ((Data.getErrorR(i,k)<0)||(Data.getErrorR(i,k)>1))
                            {
                                HtmlMessageOfError+=HQt_ShowAlert("Сейчас просматривался тэг нажедности R. Надежность это величина от 0 до 1. У вас это не так.");
                                Error=true;
                            }
                        }

                        if (!((bool_ex)&&(bool_ey)&&(bool_r)))
                        {
                            HtmlMessageOfError+=HQt_ShowAlert("В тэге measuring были не все три тэга ex, ey, r (или вообще не было).");
                            Error=true;
                        }
                    }
                    else
                    {
                        //должен быть тэг measuring, а его нет
                        HtmlMessageOfError+=HQt_ShowAlert("Анализатор ожидал тэга measuring. Что не так в структуре или данных файла.");
                        Error=true;
                    }
                }

            }
            else
            {
                //должен быть тэг experiment, а его нет
                HtmlMessageOfError+=HQt_ShowAlert("Анализатор ожидал тэга experiment. Что не так в структуре или данных файла.");
                Error=true;
            }

        }

        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
        i++;
    }

    if (i!=Data.getNumberOfExperiments())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Число экспериментов в тэге number_of_experiments не равно реальному числу экспериментов в xml файле.");
        Error=true;
    }
}