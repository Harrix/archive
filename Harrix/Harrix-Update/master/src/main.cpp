#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QStringList>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("Harrix Updater");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("The program allows you to copy files to other folders to update existing files.");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addPositionalArgument("filename", QCoreApplication::translate("main", "Binary file to disassemble."));

    QCommandLineOption noListOption(QStringList() << "n" << "no-list", QCoreApplication::translate("main", "Don't list instruction bytes (make output suitable for assembler)."));
    parser.addOption(noListOption);

    parser.process(a);

    const QStringList args = parser.positionalArguments();

    if (args.size() != 1) {
       // fprintf(stderr, "%s\n", qPrintable(QCoreApplication::translate("main", "Error: Must specify one filename argument.")));
        cout << qPrintable(QCoreApplication::translate("main", "Error: Must specify one filename argument."));
        parser.showHelp(1);
    }
    else {
        qDebug() << "filename:  " << args.at(0);
            qDebug() << "no list:   " << parser.isSet(noListOption);
    }

    system("pause");

    return 0;
    //return a.exec();
}
