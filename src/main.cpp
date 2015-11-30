#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "providerwithqml.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject* root = engine.rootObjects()[0];
    ProviderWithQML provider(root);
    engine.rootContext()->setContextProperty("_provider", &provider);

    return app.exec();
}

