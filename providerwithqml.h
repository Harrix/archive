#ifndef PROVIDERWITHQML_H
#define PROVIDERWITHQML_H

#include <QObject>
#include <QDebug>

class ProviderWithQML : public QObject
{
    Q_OBJECT
public:
     ProviderWithQML(QObject *QMLObject) : mViewer(QMLObject) {}

signals:

public slots:
     void buttonClicked(const QString& in);
 protected:
     QObject *mViewer;
};

#endif // PROVIDERWITHQML_H
