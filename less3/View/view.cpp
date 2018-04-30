#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) :
    ui(new Ui::View)
{
    ui->setupUi(this);
    connect(ui->addButton, &QPushButton::clicked,
            this, &View::addButtonClick);
    connect(ui->showPersonsButton, &QPushButton::clicked,
            this, &View::showButtonClick);
}

View::~View()
{
    delete ui;
}
void View::addButtonClick()
{
    QString name = ui->nameLine->text();
    //очистим сразу, чтобы не было мусора
    ui->nameLine->clear();
    //эмитим сигнал о добавлении нового имени
    emit addPerson(name);
}
void View::showButtonClick()
{
    //просто говорим, что хотим получить
    emit getPersons();
}
void View::showPersons(const QList<QString> &names)
{
    //очистим наш списочек
    ui->listWidget->clear();
    //и отобразим имена
    ui->listWidget->addItems(names);
}
