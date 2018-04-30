#ifndef IPRESENTER_H
#define IPRESENTER_H

#include <QObject>

class IPresenter : public QObject
{
    Q_OBJECT
public:
    virtual void run() = 0;
public slots:
    virtual void addPerson(QString name) =0;
    virtual void getPersons() =0;
};

#endif // IPRESENTER_H
