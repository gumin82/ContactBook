#ifndef MYCONTACTBOOK_H
#define MYCONTACTBOOK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyContactBook;
}
QT_END_NAMESPACE

class MyContactBook : public QMainWindow
{
    Q_OBJECT

public:
    MyContactBook(QWidget *parent = nullptr);
    ~MyContactBook();

private:
    Ui::MyContactBook *ui;
};
#endif // MYCONTACTBOOK_H
