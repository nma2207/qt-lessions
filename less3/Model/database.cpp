#include "database.h"
#include <QList>
#include <QString>
//в с++ статические поля инициализируются вне класса
DataBase *DataBase::instance = NULL;
DataBase::DataBase()
{
    //говорим, что хотим добавить базу данных  SQLite v3
    base =  QSqlDatabase::addDatabase("QSQLITE");
    //называем нашу db
    base.setDatabaseName("my_db.sqlite");
    //открываем
    base.open();
}

DataBase* DataBase::getInstance()
{
    //если нет ни одного экземпляра, то создаем
    if(instance==NULL)
    {
        instance = new DataBase;
    }
    //возвращаем ссылку на экземпляр
    return instance;
}

void DataBase::addPerson(QString name)
{
    //запрос
    //QString insertStr = "INSERT INTO persons(name)"
    //                    "VALUES('%1');";
    //заменяем %1 на имя
    //insertStr = insertStr.arg(name);
    //создаем SqlQuery
    QSqlQuery query;
    //подготавливаем запрос
    query.prepare("INSERT INTO persons(name)"
                  "VALUES(:name)");
    //пишешм что заменяем и на что заменяем
    query.bindValue(":name", name);
    //выполняем его
    query.exec();
}
QList<QString> DataBase::getPersons()
{
//    QList<QString> names;

//    QSqlQuery selectQuery;
//    //нам нужен только столбец имен
//    selectQuery.prepare("SELECT name FROM persons;");
//    //выполнили
//    selectQuery.exec();
//    //пока есть данные
//    while(selectQuery.next())
//    {
//        // получаем имя с нужного столбца и приводим к строке
//        QString name = selectQuery.value("name").toString();
//        names.append(name);
//    }
//    return names;
    QList<QString> names;
    QSqlQueryModel model;
    model.setQuery("SELECT name FROM persons;");
    for(int i=0;i<model.rowCount(); i++)
    {
        QString name = model.record(i).value("name").toString();
        names.append(name);

    }
    return names;
}
