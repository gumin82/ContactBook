#include "mycontactbook.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyContactBook w;
    w.show();
    return a.exec();
}
