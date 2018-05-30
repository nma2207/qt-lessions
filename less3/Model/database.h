#ifndef DATABASE_H
#define DATABASE_H

//это для соединения с бд
#include <QtSql>
class DataBase
{
private:
    //для доступа к бд
    QSqlDatabase base;
    //статическая ссылка на себя
    static DataBase *instance;
    //закрытый констуктор
    DataBase();
public:
    //статический метод getInstance
    static DataBase* getInstance();
    //для добавления в базу данных
    void addPerson(QString name);
    //для извлечения из базы данных
    QList<QString> getPersons();
};

#endif // DATABASE_H
