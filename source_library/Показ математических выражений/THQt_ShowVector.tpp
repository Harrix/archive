template <class T> QString THQt_ShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><b>"+TitleVector+":</b>";

    VMHL_Result+="<table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+=NameVector;
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VMHL_N;i++)
    {
        VMHL_Result+="<tr>\n";
        VMHL_Result+="<td class=\"number\">"+QString::number(VMHL_Vector[i])+"</td>\n";

        VMHL_Result+="</tr>\n";
    }

    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";
    VMHL_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table></p>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowVector (T *VMHL_Vector, int VMHL_N, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+=NameVector;
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VMHL_N;i++)
    {
        VMHL_Result+="<tr>\n";
        VMHL_Result+="<td class=\"number\">"+QString::number(VMHL_Vector[i])+"</td>\n";

        VMHL_Result+="</tr>\n";
    }

    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";
    VMHL_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table></p>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowVector (T *VMHL_Vector, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+="x";
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VMHL_N;i++)
    {
        VMHL_Result+="<tr>\n";
        VMHL_Result+="<td class=\"number\">"+QString::number(VMHL_Vector[i])+"</td>\n";

        VMHL_Result+="</tr>\n";
    }

    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";
    VMHL_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table></p>\n";

    return VMHL_Result;
}