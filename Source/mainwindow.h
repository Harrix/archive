#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0,QString FileNameFromArgv="");
    ~MainWindow();

    QString DS;//разделитель между папками: слэш или иное в данной ОС
    QString Path;//путь к папке с программой
    QString Html;//сюда кладется выводимый текст
    
private slots:

    void on_action_triggered();

    void on_action_LaTeX_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
