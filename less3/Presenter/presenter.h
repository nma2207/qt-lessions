#ifndef PRESENTER_H
#define PRESENTER_H

#include "ipresenter.h"
#include "iview.h"
#include "imodel.h"
class Presenter:public IPresenter
{
    Q_OBJECT
private:
    IView  *view;
    IModel *model;

public:
    Presenter();
    ~Presenter();
    void run() override;
public slots:
    void addPerson(QString name) override;
    void getPersons() override;
};

#endif // PRESENTER_H
