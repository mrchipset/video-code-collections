#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Debug Click";
}


void MainWindow::on_pushButton_2_clicked()
{
    qInfo() << "Click Me!";
}

void MainWindow::on_pushButton_3_clicked()
{
    qWarning() << "I am a warning!";
}

void MainWindow::on_pushButton_4_clicked()
{
    qCritical() << "Critical!";
}


void MainWindow::on_pushButton_5_clicked()
{
    qFatal("Fatal Error!");
}

