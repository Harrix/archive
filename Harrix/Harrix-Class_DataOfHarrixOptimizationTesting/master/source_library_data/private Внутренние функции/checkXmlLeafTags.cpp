void HarrixClass_DataOfHarrixOptimizationTesting::checkXmlLeafTags()
{
    /*
    Проверяет наличие тэгов и правильное их выполнение. Внутренняя функция.
    Учитывает все "листовые" тэги кроме тэгов данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Data.getFormat()!="Harrix Optimization Testing")
    {
        HtmlMessageOfError+=HQt_ShowAlert("Неправильный формат данных. Это не Harrix Optimization Testing.");
        Error=true;
    }
    if (Data.getLink()!="https://github.com/Harrix/HarrixFileFormats")
    {
        HtmlMessageOfError+=HQt_ShowAlert("Неправильный сайт в описании. Должен быть https://github.com/Harrix/HarrixFileFormats.");
        Error=true;
    }
    if (Data.getVersion()!="1.0")
    {
        HtmlMessageOfError+=HQt_ShowAlert("Неправильная версия формата Harrix Optimization Testing. Данная функция обрабатывает версию 1.0.");
        Error=true;
    }
    if (Data.getNumberOfParameters()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_parameters.");
        Error=true;
    }
    if (Data.getNumberOfParameters()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_parameters. Минимальное число параметров 1. Подробности в описании формата данных на https://github.com/Harrix/HarrixFileFormats.");
        Error=true;
    }
    if ((Data.getNumberOfParameters()<0)&&(Data.getNumberOfParameters()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_parameters. Число параметров не может быть отрицательным.");
        Error=true;
    }
    if (Data.getNumberOfExperiments()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_experiments.");
        Error=true;
    }
    if (Data.getNumberOfExperiments()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_experiments. Минимальное число экспериментов 1.");
        Error=true;
    }
    if ((Data.getNumberOfExperiments()<0)&&(Data.getNumberOfExperiments()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_experiments. Число параметров не может быть отрицательным.");
        Error=true;
    }
    if (Data.getMaxCountOfFitness()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга max_count_of_fitness.");
        Error=true;
    }
    if (Data.getMaxCountOfFitness()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге max_count_of_fitness. Минимальное число вычислений целевой функции 1, и то это очень мало.");
        Error=true;
    }
    if ((Data.getMaxCountOfFitness()<0)&&(Data.getMaxCountOfFitness()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге max_count_of_fitness. Число вычислений целевой функции не может быть отрицательным.");
        Error=true;
    }
    if (Data.getNumberOfRuns()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_runs.");
        Error=true;
    }
    if (Data.getNumberOfRuns()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_runs. Минимальное число запусков алгоритма для усреднения 1 (желательно от 10).");
        Error=true;
    }
    if ((Data.getNumberOfRuns()<0)&&(Data.getNumberOfRuns()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_runs. Число запусков алгоритма для усреднения не может быть отрицательным.");
        Error=true;
    }
    if (Data.getNumberOfMeasuring()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_measuring.");
        Error=true;
    }
    if (Data.getNumberOfMeasuring()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_measuring. Минимальное число измерений для настройки алгоритма 1 (желательно от 10).");
        Error=true;
    }
    if ((Data.getNumberOfMeasuring()<0)&&(Data.getNumberOfMeasuring()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_measuring. Число измерений для настройки алгоритма не может быть отрицательным.");
        Error=true;
    }
    if (Data.getDimensionTestFunction()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о размерности тестовой задачи dimension_test_function.");
        Error=true;
    }
    if (Data.getDimensionTestFunction()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге dimension_test_function. Минимальная длина хромосомы 1 (желательно от 10).");
        Error=true;
    }
    if ((Data.getDimensionTestFunction()<0)&&(Data.getDimensionTestFunction()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге dimension_test_function. Длина хромосомы не может быть отрицательной.");
        Error=true;
    }
    if (Data.getFullNameTestFunction().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о полном названии тестовой функции full_name_test_function.");
        Error=true;
    }
    if (Data.getNameTestFunction().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о названии тестовой функции name_test_function.");
        Error=true;
    }
    if (Data.getNameTestFunction().contains(" "))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Идентификатор тестовой функции должен быть одним словом. Пробелы не допускаются.");
        Error=true;
    }
    if (Data.getFullNameAlgorithm().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о полном названии алгоритма full_name_algorithm.");
        Error=true;
    }
    if (Data.getNameAlgorithm().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга об названии алгоритма name_algorithm.");
        Error=true;
    }
    if (Data.getNameAlgorithm().contains(" "))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Идентификатор алгоритма оптимизации должен быть одним словом. Пробелы не допускаются.");
        Error=true;
    }
    if (Data.getDate().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о дате создания документа date.");
        Error=true;
    }
    if (Data.getAuthor().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга об авторе author");
        Error=true;
    }
    if (Data.getEmail().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга об электронной почте email. Если не хотите давать свою почту, то вставьте NULL.");
        Error=true;
    }
    if (Data.getLinkAlgorithm().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о ссылке на описание алгоритма link_algorithm.");
        Error=true;
    }
    if (Data.getLinkTestFunction().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о ссылке на описание тестовой функции link_test_function.");
        Error=true;
    }
    if (!((Data.getCheckAllCombinations()==0)||(Data.getCheckAllCombinations()==1)))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Тэг all_combinations может принимать значение 0 или 1.");
        Error=true;
    }

}