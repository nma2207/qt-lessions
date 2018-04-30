#include "model.h"


Model::Model()
{
}
void Model::addPerson(QString name)
{
    //добавляем в конец имя
    names.append(name);
}
QList<QString> Model::getPersons() const
{
    //просто вернем список
    return names;
}
