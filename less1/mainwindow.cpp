#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //для обращения к элементам, которые мы добавили в конструкторе пишем
    //ui->element

//    connect(ui->pushButton, SIGNAL(clicked(bool)),
//            this, SLOT(buttonClick()));
    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::buttonClick);
    clickCount=0;
    //коннектим наш сигнал к нашему слоту
    connect(this, &MainWindow::makedTatarText,
            this, &MainWindow::tatarText);
    initActions();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete closeAction;
}

void MainWindow::buttonClick()
{
    //чтобы не переполнялось
    clickCount = (clickCount+1)%3;
    switch (clickCount)
    {
    //меняем текст метки
        case 0: ui->label->setText("Hello!"); break;
        case 1: ui->label->setText("Привет!"); break;
        case 2:
            ui->label->setText("Сэлэм!");
            //кричим всем, что у нас текст на татарском стал
            emit makedTatarText();
            break;
    }
}
void MainWindow::tatarText()
{
    QMessageBox::about(NULL, "Tatar!", "Ваш текст на татарском!");
}
void MainWindow::initActions()
{
    closeAction = new QAction("Выход");
    //добавили горячую клавишу
    closeAction->setShortcut(QKeySequence::fromString("Ctrl+X"));
    //коннектим активацию к нашему слоту
    connect(closeAction, &QAction::triggered,
            this, &MainWindow::closeWindow);
    //добавляем в меню-бар
    ui->menuBar->addAction(closeAction);

    //просим создать menuBar менюшку для нас
    fileMenu = ui->menuBar->addMenu("File");
    //добавляем наш экшн в меню
    fileMenu->addAction(closeAction);
}
//слот, обрабатывающий активацию действия
void MainWindow::closeWindow()
{
    //выдаем предупреждение
    QMessageBox::warning(NULL, "Close", "Мы закрываемся");
    //закрываем
    close();
}
