#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Hello, World1!\n";

    QString S = QCoreApplication::arguments().at(0);
    cout << "S "<< S.toStdString() <<"\n";

    //S = QCoreApplication::arguments().at(1);
    cout << "S "<< S.toStdString() <<"\n";

    //system("pause");
    return a.exec();
}
