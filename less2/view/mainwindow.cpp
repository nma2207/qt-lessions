#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "doubler.h"
#include "tripler.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::calculate);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::calculate()
{
    //считываем текст из поля и сразу переводим его в вещественное
    double k = ui->lineEdit->text().toDouble();
    //вызываем статические методы наших классов
    double doubleK = Doubler::calc(k);
    double tripleK = Tripler::calc(k);

    //запишем в метки (я поменял названия меток)
    //QString::number переводит из числа в строку
    //это надо, т.к. setText принимает только число
    ui->doubleLabel->setText(QString::number(doubleK));
    ui->tripleLabel->setText(QString::number(tripleK));
}
