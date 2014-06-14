#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardItemModel>
#include <QTime>
#include <QFileDialog>

#include "HarrixQtLibrary.h"

int CountTextEditChanging;
int linewmax;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);

    linewmax=100;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Сборка проекта Harrix Library
    QTime myTimer;
    myTimer.start();//запуск таймера работы сборки библиотеки

    CountTextEditChanging=0;

    ui->pushButton->setEnabled(false);

    ui->textEdit->clear();

    QString DS="\\";
    QString path=QDir::toNativeSeparators(QGuiApplication::applicationDirPath())+DS+".."+DS+"source_library"+DS;//путь к папке

    if (!(QDir(path).exists()==true) )
    {
        while (!(QDir(path).exists()==true) )
            path = QFileDialog::getExistingDirectory(this, "Открыть папку","",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks)+DS;
    }

    QString temp_library_path;//папка где находятся собранные файлы
    temp_library_path=QDir::toNativeSeparators(QGuiApplication::applicationDirPath())+DS+".."+DS+"temp_library"+DS;//путь к папке

    if (!(QDir(temp_library_path).exists()==true) )
    {
        QDir().mkdir(temp_library_path);
    }

    if (!(QDir(temp_library_path+DS+"images"+DS).exists()==true) )
    {
        QDir().mkdir(temp_library_path+DS+"images"+DS);
    }

    QString ResultCpp;//итоговый cpp документ
    QString ResultTpp;//сюда пишем шаблоны, которые потом воткнем в h файл
    QString ResultH;//итоговый h файл
    QString ResultTex;//итоговый cpp документ
    QString ResultTexList;//временный список функций
    QString ResultTexFunctions;//временная перемнная для справки по функциям
    QString ResultFunctionsMD;//временная перемнная для FUNCTIONS.MD
    QString Temp;//переменная для временного содержания загружаемых файлов
    QString MessageError;//Текущая ошиьбка
    QString AllMessageError;//Все ошибки
    int countoferrors=0;//количество ошибок
    int countneed;//количество рассмотренных нами файлов
    int countcpp=0;//количество функций в виде cpp файлов
    int counth=0;//количество функций в виде h файлов
    int counttex=0;//количество функций в виде tex файлов
    int countdesc=0;//количество функций в виде desc файлов
    int countpng=0;//количество функций в виде png файлов
    int countpdf=0;//количество функций в виде pdf файлов
    int countuse=0;//количество функций в виде use файлов

    int countfunction=0;//количество функций

    bool b;
    ui->textEdit->insertHtml("<font color=\"#858585\">Начало формирования файлов библиотеки...<\font><br>");

    ResultTpp += "//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    ResultTpp += "// РЕАЛИЗАЦИЯ ШАБЛОНОВ\n";//добавляем название папки (раздела)
    ResultTpp += "//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

    ResultFunctionsMD += "Список функций библиотеки \n";
    ResultFunctionsMD += "===========================================\n\n";

    ResultH += "//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    ResultH += "// ОБЪЯВЛЕНИЯ ФУНКЦИЙ\n";//добавляем название папки (раздела)
    ResultH += "//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

    //дополнительные переменные
    QString dirname,dirnameForAdd,filename,path2,exp;
    QStringList listfiles,listdirs;
    int i,j,n,m;

    //Теперь начинаем пробегать по всем папкам
    listdirs = HQt_ListDirsInDirQStringList(path);//список папок

    n=listdirs.count();//количество папок разделов
    ui->textEdit->insertHtml("<br>Было найдено  <b>"+QString::number(n)+"</b> папок - разделов библиотеки<br>");
    if (n==0) {MessageError="<font color=\"red\">Не найдены разделы библиотек. Это очень плохо.<\font><br>";AllMessageError+=MessageError;ui->textEdit->insertHtml(MessageError);countoferrors++;}
    if (CountTextEditChanging>linewmax) {ui->textEdit->clear();CountTextEditChanging = 0;}

    ResultTexList="\\newpage\n\\section{Список функций}\\label{section_listfunctions}\n";
    ResultTexFunctions="\\newpage\n\\section{Функции}\n";

    bool pubbool=false;
    bool pribool=false;

    for (i=0;i<n;i++)//пробегаем по всем разделам
    {
        dirname=listdirs.at(i);//получаем имя папки

        //Узнаем есть ли там слова private и public
        int pub=dirname.indexOf("public ");
        int pri=dirname.indexOf("private ");
        if ((pub>=0)||(pri>=0))
        {
            if ((pubbool==false)&&(pub>=0))
            {
                ResultH += "public:\n";
                ResultCpp += "[public]";
                pubbool=true;
            }
            if ((pribool==false)&&(pri>=0))
            {
                ResultH += "private:\n";
                ResultCpp += "[private]";
                pribool=true;
            }

            if (pub>=0)
            {
                dirnameForAdd=dirname.mid(7);
            }
            if (pri>=0)
            {
                dirnameForAdd=dirname.mid(8);
            }
        }
        //Узнаем есть ли там слова private и public КОНЕЦ


        path2=path+dirname+"/";
        ui->textEdit->insertHtml("<br>Рассматриваем папку <b>"+dirname+"</b>");

        listfiles=HQt_ListFilesInDirQStringList(path2);//список файлов в папке

        m=listfiles.count();//количество файлов в папке
        ui->textEdit->insertHtml("<br>Было найдено  <b>"+QString::number(m)+"</b> файлов в папке<br><br>");
        if (m==0) {MessageError="<font color=\"red\">Не найдены файлы в разделе. То есть в разделе нет функций?<\font><br>";AllMessageError+=MessageError;ui->textEdit->insertHtml(MessageError);countoferrors++;}
        if (CountTextEditChanging>linewmax) {ui->textEdit->clear();CountTextEditChanging = 0;}


        ResultCpp += "//*****************************************************************\n";
        ResultCpp += "//"+dirnameForAdd+"\n";//добавляем название папки (раздела)
        ResultCpp += "//*****************************************************************\n";

        ResultTpp += "//*****************************************************************\n";
        ResultTpp += "//"+dirnameForAdd+"\n";//добавляем название папки (раздела)
        ResultTpp += "//*****************************************************************\n";

        ResultH   += "//"+dirnameForAdd+"\n";//добавляем название папки (раздела)

        ResultFunctionsMD += dirnameForAdd+"\n----------------\n\n";

        ResultTexList += "\\textbf{"+dirnameForAdd+"}\n";
        ResultTexList += "\\begin{enumerate}\n\n";

        ResultTexFunctions += "\\subsection{"+dirnameForAdd+"}\n\n";

        countneed=0;

        for (j=0;j<m;j++)//пробегаем по файлам папки
        {
            filename=listfiles.at(j);//получаем имя файла
            exp=HQt_GetExpFromFilename(filename);//расширение файла

            if (exp=="desc")
            {
                countneed++;
                countdesc++;

                QString nameof_func=HQt_GetNameFromFilename(filename);//имя функции по названию файла
                QString nameof_func_=nameof_func;//имя функции с преобразованными знаками _
                nameof_func_=nameof_func_.replace("_","\\_");

                Temp = HQt_ReadFile(path2+filename)+"\n";//добавляем текст файла

                ResultTexList += "\\item \\textbf{\\hyperref[" + nameof_func + "]{" + nameof_func_ + "}} --- " + Temp+"\n";

                ResultTexFunctions+="\\subsubsection{" + nameof_func_ + "}\\label{"+nameof_func+"}\n\n" + Temp+"\n\n";

                ResultFunctionsMD += "- "+Temp.replace("\\_","_").replace("$","")+"\n";

                if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                else {MessageError="<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>";AllMessageError+=MessageError;ui->textEdit->insertHtml(MessageError);countoferrors++;}
                if (CountTextEditChanging>linewmax) {ui->textEdit->clear();CountTextEditChanging = 0;}

            }
            if ((exp=="cpp")||(exp=="tpp"))
            {
                countneed++;
                countcpp++;

                Temp = HQt_ReadFile(path2+filename)+"\n";//добавляем текст файла в cpp файл

                if (exp=="cpp")
                {
                    ResultCpp += Temp;
                    ResultCpp += "//---------------------------------------------------------------------------\n\n";
                    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                    else {MessageError="<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>";AllMessageError+=MessageError;ui->textEdit->insertHtml(MessageError);countoferrors++;}
                    if (CountTextEditChanging>linewmax) {ui->textEdit->clear();CountTextEditChanging = 0;}
                }

                if (exp=="tpp")
                {
                    ResultTpp += Temp;
                    ResultTpp += "//---------------------------------------------------------------------------\n\n";
                    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                    else {MessageError="<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>";AllMessageError+=MessageError;ui->textEdit->insertHtml(MessageError);countoferrors++;}
                    if (CountTextEditChanging>linewmax) {ui->textEdit->clear();CountTextEditChanging = 0;}
                }
            }
            if (exp=="h")
            {
                countneed++;
                counth++;

                QString nameof_func=HQt_GetNameFromFilename(filename);//имя функции по названию файла
                //QString nameof_func_=nameof_func;//имя функции с преобразованными знаками _
                //nameof_func_=nameof_func_.replace("_","\\_");


                Temp = HQt_ReadFile(path2+filename)+"\n";//добавляем текст файла в h файл
                ResultH += Temp;
                if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                else {MessageError="<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>";AllMessageError+=MessageError;ui->textEdit->insertHtml(MessageError);countoferrors++;}
                if (CountTextEditChanging>linewmax) {ui->textEdit->clear();CountTextEditChanging = 0;}

                countfunction+=Temp.count(";");//количество функций считаем по количеству знаков ; в h файлах

                ResultTexFunctions+="\\begin{lstlisting}[label=code_syntax_"+nameof_func+",caption=Синтаксис]\n";
                ResultTexFunctions+=Temp;
                ResultTexFunctions+="\\end{lstlisting}\n\n";

                ResultFunctionsMD += "```cpp\n"+Temp+"```\n\n";
            }
            if (exp=="tex")
            {
                countneed++;
                counttex++;

                Temp = HQt_ReadFile(path2+filename)+"\n";//добавляем текст файла

                ResultTexFunctions+=Temp+"\n\n";

                if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                else {MessageError="<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>";AllMessageError+=MessageError;ui->textEdit->insertHtml(MessageError);countoferrors++;}
            }
            if (exp=="png")
            {
                countneed++;
                countpng++;

                b=HQt_CopyFile(path2+filename, temp_library_path+DS+"images"+DS,true);
                if (b) ui->textEdit->insertHtml("Скопировали файл <b>"+filename+"</b><br>");
                else {MessageError="<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>";AllMessageError+=MessageError;ui->textEdit->insertHtml(MessageError);countoferrors++;}
                if (CountTextEditChanging>linewmax) {ui->textEdit->clear();CountTextEditChanging = 0;}
            }
            if (exp=="pdf")
            {
                countneed++;
                countpdf++;

                b=HQt_CopyFile(path2+filename, temp_library_path+DS+"images"+DS,true);
                if (b) ui->textEdit->insertHtml("Скопировали файл <b>"+filename+"</b><br>");
                else {MessageError="<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>";AllMessageError+=MessageError;ui->textEdit->insertHtml(MessageError);countoferrors++;}
                if (CountTextEditChanging>linewmax) {ui->textEdit->clear();CountTextEditChanging = 0;}
            }
            if (exp=="use")
            {
                countneed++;
                countuse++;

                QString nameof_func=HQt_GetNameFromFilename(filename);//имя функции по названию файла
                QString nameof_func_=nameof_func;//имя функции с преобразованными знаками _
                nameof_func_=nameof_func_.replace("_","\\_");

                Temp = HQt_ReadFile(path2+filename)+"\n";//добавляем текст файла

                //удаляем пробелы
                QStringList TempWithSpace = Temp.split( "\n" );
                QStringList TempWithoutSpace;

                QString FirstLine = TempWithSpace.at(0);

                QString st,StringFromTempWithoutSpace;

                int countspace=0;

                bool beginsting=true;

                for (int i=0;i<FirstLine.length();i++)
                {
                    if ((FirstLine.at(i)==' ')&&(beginsting==true))
                    {
                        countspace++;
                    }
                    if (FirstLine.at(i)!=' ')
                        beginsting=false;
                }

                QString Space;
                for (int i=0;i<countspace;i++) Space+=" ";

                for (int i=0;i<TempWithSpace.count();i++)
                {
                    st = TempWithSpace.at(i);

                    if (st.mid(0,countspace)==Space)
                        StringFromTempWithoutSpace = st.mid(countspace,-1);
                    else
                        StringFromTempWithoutSpace=st;

                    TempWithoutSpace << StringFromTempWithoutSpace;

                }

                Temp=HQt_QStringListToQString(TempWithoutSpace);
                //закончили удалять пробелы

                ResultTexFunctions+="\\begin{lstlisting}[label=code_use_"+nameof_func+",caption=Пример использования]\n";
                ResultTexFunctions+=Temp;
                ResultTexFunctions+="\\end{lstlisting}\n\n";


                if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                else {MessageError="<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>";AllMessageError+=MessageError;ui->textEdit->insertHtml(MessageError);countoferrors++;}
                if (CountTextEditChanging>linewmax) {ui->textEdit->clear();CountTextEditChanging = 0;}

            }

            QGuiApplication::processEvents();

            QTextCursor c =  ui->textEdit->textCursor();
            c.movePosition(QTextCursor::End);
            ui->textEdit->setTextCursor(c);
        }

        ui->textEdit->insertHtml("Из <b>"+QString::number(m)+"</b> файлов нужными нам оказалось <b>"+QString::number(countneed)+"</b> файлов в папке<br>");

        ResultCpp += "\n";
        ResultH   += "\n";

        ResultTexList += "\\end{enumerate}\n\n";

    }

    if ((pubbool==true)&&(pribool==true))
    {
        QString Re=ResultH.mid(ResultH.indexOf("private:"),ResultH.indexOf("public:")-ResultH.indexOf("private:"));
        ResultH=ResultH.remove(ResultH.indexOf("private:"),ResultH.indexOf("public:")-ResultH.indexOf("private:"));
        ResultH=ResultH+Re;

        Re=ResultCpp.mid(ResultCpp.indexOf("[private]"),ResultCpp.indexOf("[public]")-ResultCpp.indexOf("[private]"));
        ResultCpp=ResultCpp.remove(ResultCpp.indexOf("[private]"),ResultCpp.indexOf("[public]")-ResultCpp.indexOf("[private]"));
        ResultCpp=ResultCpp+Re;
    }
    else
    {
        ResultH += ResultTpp;
    }

    if ((pubbool==true)||(pribool==true))
    {
        ResultCpp.remove("[public]");
        ResultCpp.remove("[private]");
    }

    ResultTex+=ResultTexList+"\n";
    ResultTex+=ResultTexFunctions;


    HQt_SaveFile(ResultCpp,temp_library_path+"Library.cpp");
    ui->textEdit->insertHtml("<br>Сохранили файл <b>Library.cpp</b><br>");
    HQt_SaveFile(ResultH,temp_library_path+"Library.h");
    ui->textEdit->insertHtml("Сохранили файл <b>Library.h</b><br>");

    HQt_SaveFile(ResultTex,temp_library_path+"Library_Help.tex");
    ui->textEdit->insertHtml("Сохранили файл <b>Library_Help.tex</b><br>");

    HQt_SaveFile(ResultFunctionsMD,temp_library_path+"FUNCTIONS.md");
    ui->textEdit->insertHtml("Сохранили файл <b>FUNCTIONS.md</b><br>");

    if (countoferrors==0) ui->textEdit->insertHtml("<br>Ошибки не были зафиксированы.<br>");
    else ui->textEdit->insertHtml("<br><font color=\"red\">Ошибок <b>"+QString::number(countoferrors)+"</b> штук<\font><br>");

    ui->textEdit->insertHtml("<font color=\"#858585\">Конец формирования файлов библиотеки.<\font><br>");

    ui->textEdit->insertHtml("<font color=\"#858585\">Было обнаружено "+QString::number(countfunction)+" функций.<\font><br>");

    int nMilliseconds = myTimer.elapsed();
    ui->textEdit->insertHtml("<font color=\"#858585\">Потребовалось времени: "+HQt_WriteTime(nMilliseconds)+"</font><br>");

    if (AllMessageError.length()>2)
    {
        ui->textEdit->insertHtml("<b>Список всех ошибок</b><br>");
        ui->textEdit->insertHtml(AllMessageError);
    }

    QTextCursor c =  ui->textEdit->textCursor();
    c.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(c);

    ui->pushButton->setEnabled(true);

    //открытие папки с собранными файлами
    QDesktopServices::openUrl(QUrl::fromLocalFile(temp_library_path));

}

void MainWindow::on_textEdit_textChanged()
{
    CountTextEditChanging++;
}
