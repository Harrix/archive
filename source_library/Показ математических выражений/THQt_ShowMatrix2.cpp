QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><b>"+TitleMatrix+":</b>";

    VHQt_Result+="<table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+=NameMatrix;
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
        for (int j=0;j<VHQt_Matrix[i].count();j++)
        {
            QString B=VHQt_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VHQt_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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
QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+=NameMatrix;
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
        for (int j=0;j<VHQt_Matrix[i].count();j++)
        {
            QString B=VHQt_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VHQt_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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
QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+="";
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
        for (int j=0;j<VHQt_Matrix[i].count();j++)
        {
            QString B=VHQt_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VHQt_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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