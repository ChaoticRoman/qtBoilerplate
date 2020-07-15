#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
    ui(new Ui::MainWindow), instance(new ExampleLibrary(this))
{
    ui->setupUi(this);

    connect(instance, &ExampleLibrary::tick, this, &MainWindow::appendText);
    instance->set_message(".");
}

MainWindow::~MainWindow() {
    delete ui;
    delete instance;
}

void MainWindow::clearText() {
    ui->label->clear();
}

void MainWindow::setText(QString text) {
    ui->label->setText(text);
}

void MainWindow::appendText(QString text) {
    setText(ui->label->text() + text);
}
