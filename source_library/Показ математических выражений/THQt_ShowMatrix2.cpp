QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><b>"+TitleMatrix+":</b>";

    VMHL_Result+="<table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+=NameMatrix;
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
        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            QString B=VMHL_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VMHL_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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
QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+=NameMatrix;
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
        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            QString B=VMHL_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VMHL_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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
QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+="";
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
        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            QString B=VMHL_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VMHL_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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