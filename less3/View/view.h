#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "iview.h"
namespace Ui {
class View;
}

class View : public IView
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();
public:
    void showPersons(const QList<QString> &names) override;
private:
    Ui::View *ui;
public slots:
    void addButtonClick();
    void showButtonClick();
};

#endif // VIEW_H
