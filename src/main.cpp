#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "handlersignals.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    QObject* root = engine.rootObjects()[0];

    HandlerSignals *handlerSignals= new HandlerSignals(root);

    QObject* ob = root->findChild<QObject*>("pageBasicComponents");
    QObject::connect(ob, SIGNAL(qmlSignal(QString)),
                     handlerSignals, SLOT(cppSlot(QString)));

    return app.exec();
}
