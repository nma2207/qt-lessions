#include "presenter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IPresenter *presenter = new Presenter;
    presenter->run();
    //не очищаем память, иначе даже не запустится :D
    return a.exec();
}
