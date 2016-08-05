#include "handlersignals.h"

HandlerSignals::HandlerSignals(QObject *parent) : QObject(parent)
{

}

void HandlerSignals::cppSlot(const QString &msg) {

    //Найдем строки ввода
    QObject* field1 = this->parent()->findChild<QObject*>("field1");
    QObject* field2 = this->parent()->findChild<QObject*>("field2");
    //Найдем поле вывода
    QObject* textArea = this->parent()->findChild<QObject*>("textArea");

    //Считаем информацию со строк ввода через свойство text
    QString str1=(field1->property("text")).toString();
    QString str2=(field2->property("text")).toString();

    int a = str1.toInt();//Переведем строку в число
    int b = str2.toInt();//Переведем строку в число

    int c = a + b; //Вычисления наши

    QString strResult=QString::number(c);//Переведем результат в строку

    //Ну и наконец выведем в поле вывода нашу информацию
    textArea->setProperty("text", str1+" + "+str2+" = "+strResult+" "+msg);
}
