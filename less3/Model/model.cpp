#include "model.h"


Model::Model()
{
    //получаем экземпляр
    base = DataBase::getInstance();
}
void Model::addPerson(QString name)
{
    //добавляем в конец имя
    //names.append(name);
    //вместо добавления в список
    base->addPerson(name);
}
QList<QString> Model::getPersons() const
{
    //просто вернем список
    //return names;
    //вместо возвращения списка
    return base->getPersons();
}
