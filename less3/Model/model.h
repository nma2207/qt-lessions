#ifndef MODEL_H
#define MODEL_H

#include "imodel.h"
class Model: public IModel
{
private:
    //наше хранилище имен
    QList<QString> names;
public:
    Model();
    void addPerson(QString name) override;
    QList<QString> getPersons() const;
};

#endif // MODEL_H
