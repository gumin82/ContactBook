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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MyContactBook *ui;
};
#endif // MYCONTACTBOOK_H
