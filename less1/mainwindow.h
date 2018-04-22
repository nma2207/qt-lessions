#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //наш счетчик нажатий
    int clickCount;
    //наше закрывающее действие
    QAction *closeAction;
    //отдельный метод, в котором будем инициализировать action-ы
    void initActions();
    //наша выпадающая менюшка
    QMenu *fileMenu;
    //закрытый слот, т.е. из другого класса не могут его вызвать
private slots:
    void buttonClick();
    void tatarText();
    //слот для закрытия окна
    void closeWindow();
    //объявили сигнал.
signals:
    void makedTatarText();
};

#endif // MAINWINDOW_H
