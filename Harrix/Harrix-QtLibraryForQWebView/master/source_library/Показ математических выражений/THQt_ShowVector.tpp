template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><b>"+TitleVector+":</b>";

    VHQt_Result+="<table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+=NameVector;
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+="<tr>\n";
        VHQt_Result+="<td class=\"number\">"+QString::number(VHQt_Vector[i])+"</td>\n";

        VHQt_Result+="</tr>\n";
    }

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+=NameVector;
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+="<tr>\n";
        VHQt_Result+="<td class=\"number\">"+QString::number(VHQt_Vector[i])+"</td>\n";

        VHQt_Result+="</tr>\n";
    }

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+="x";
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+="<tr>\n";
        VHQt_Result+="<td class=\"number\">"+QString::number(VHQt_Vector[i])+"</td>\n";

        VHQt_Result+="</tr>\n";
    }

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}