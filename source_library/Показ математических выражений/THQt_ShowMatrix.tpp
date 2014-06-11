template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     VMHL_M - количество столбцов в матрице;
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
        for (int j=0;j<VMHL_M;j++)
            VMHL_Result+="<td class=\"number\">"+QString::number(VMHL_Matrix[i][j])+"</td>\n";

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
template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     VMHL_M - количество столбцов в матрице;
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
        for (int j=0;j<VMHL_M;j++)
            VMHL_Result+="<td class=\"number\">"+QString::number(VMHL_Matrix[i][j])+"</td>\n";

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
template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     VMHL_M - количество столбцов в матрице.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой матрицей.
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
        for (int j=0;j<VMHL_M;j++)
            VMHL_Result+="<td class=\"number\">"+QString::number(VMHL_Matrix[i][j])+"</td>\n";

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