#include "providerwithqml.h"

void ProviderWithQML::buttonClicked(const QString& in)
{
    qDebug() << in;//Просто выведем информацию строки in в консоль Debug. Просто так.

    //Найдем строки ввода
    QObject* textinput1 = mViewer->findChild<QObject*>("textinput1");
    QObject* textinput2 = mViewer->findChild<QObject*>("textinput2");
    //Найдем поле вывода
    QObject* memo = mViewer->findChild<QObject*>("memo");

    //Считаем информацию со строк ввода через свойство text
    QString str1=(textinput1->property("text")).toString();
    QString str2=(textinput2->property("text")).toString();

    int a = str1.toInt();//Переведем строку в число
    int b = str2.toInt();//Переведем строку в число

    int c = a + b; //Вычисления наши

    QString strResult=QString::number(c);//Переведем результат в строку

    //Ну и наконец выведем в поле вывода нашу информацию
    memo->setProperty("text", str1+" + "+str2+" = "+strResult);
}
