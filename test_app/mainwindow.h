#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include "exampleLibrary.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

public slots:
    void clearText();
    void setText(QString text);
    void appendText(QString text);

private:
    Ui::MainWindow *ui;
    ExampleLibrary *instance;
};
#endif // MAINWINDOW_H