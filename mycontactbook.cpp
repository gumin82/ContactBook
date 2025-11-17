#include "mycontactbook.h"
#include "ui_mycontactbook.h"

MyContactBook::MyContactBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyContactBook)
{
    ui->setupUi(this);
}

MyContactBook::~MyContactBook()
{
    delete ui;
}
