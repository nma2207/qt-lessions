#ifndef IMODEL_H
#define IMODEL_H
#include<QList>
#include<QString>

class IModel
{
public:
    virtual void addPerson(QString name)=0;
    virtual QList<QString> getPersons() const =0;
};

#endif // IMODEL_H
