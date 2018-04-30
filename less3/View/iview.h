#ifndef IVIEW_H
#define IVIEW_H

#include <QMainWindow>
#include<QList>
#include <QString>
class IView : public QMainWindow
{
    Q_OBJECT
public:
    virtual void showPersons(const QList<QString> & names)=0;
signals:
    void addPerson(QString name);
    void getPersons();

};

#endif // IVIEW_H
