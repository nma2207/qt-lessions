#include "presenter.h"
#include "view.h"
#include "model.h"
Presenter::Presenter()
{
    view = new View;
    model = new Model;
    connect(view, &IView::addPerson,
            this, &Presenter::addPerson);
    connect(view, &IView::getPersons,
            this, &Presenter::getPersons);
}

Presenter::~Presenter()
{
    delete view;
    delete model;
}
void Presenter::addPerson(QString name)
{
    //добавляем в модель имя, не знаем как оно там дальше будет храниться
    model->addPerson(name);
}
void Presenter::getPersons()
{
    //получаем список
    QList<QString> names = model->getPersons();
    //не знаем, что с ним дальше
    view->showPersons(names);
}
void Presenter::run()
{
    //запускаем
    view->show();
}
