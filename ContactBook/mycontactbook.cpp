#include "mycontactbook.h"
#include "ui_mycontactbook.h"
#include<QTableWidget>
#include<QFile>
#include<QDebug>
#include<QTextStream>
#include <QFileDialog>


QString mFilename ="C:/Users/user/Desktop/ex/contackbook.txt";
void Write (QString Filename, QString str)
{
    QFile mFile (Filename); //宣告QFile函數
    //寫入檔案判斷
    if(!mFile.open(QFile::WriteOnly | QFile:: Text)) { qDebug() <<"could not open file for write";
        return;
    }
    QTextStream out (&mFile);
    out<<str; //將內容輸出至txt檔
    mFile.flush(); //刷新mFile
    mFile.close(); //關閉mFile
}
MyContactBook::MyContactBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyContactBook)
{
    ui->setupUi(this);
    QStringList ColTotle;
    ui->tableWidget->setColumnCount(4);
    ColTotle<<QStringLiteral("學號")<<QStringLiteral("班級")<<QStringLiteral("姓名")<<QStringLiteral("電話");
    ui->tableWidget->setHorizontalHeaderLabels(ColTotle);
}

MyContactBook::~MyContactBook()
{
    delete ui;
}

void MyContactBook::on_pushButton_clicked()
{
    QTableWidgetItem *inputRow1, *inputRow2, *inputRow3, *inputRow4;
    inputRow1 =new QTableWidgetItem(QString (ui->lineEdit->text()));
    inputRow2 = new QTableWidgetItem(QString (ui->lineEdit_2->text()));
    inputRow3 = new QTableWidgetItem(QString (ui->lineEdit_3->text()));
    inputRow4 =new QTableWidgetItem(QString (ui->lineEdit_4->text()));
    ui->tableWidget->insertRow (ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,inputRow1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, inputRow2);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, inputRow3);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,inputRow4);
}


void MyContactBook::on_pushButton_2_clicked()
{
    QString saveFile="";
    //存福內容
    for(int i = 0 ;i<ui->tableWidget->rowCount();i++){
        for(int j = 0 ;j<ui->tableWidget->columnCount();j++) {
            saveFile+=ui->tableWidget->item(i,j)->text();
            if(!(j>=ui->tableWidget->columnCount() - 1))saveFile+=",";

        }
        saveFile+="\n";
    }
    Write (mFilename, saveFile); //呼叫Write
}

#include <QFileDialog>

void MyContactBook::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Contact File"), "", tr("Text Files (*.txt);;CSV Files (*.csv)"));

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Could not open file for reading:" << fileName;
        return;
    }

    ui->tableWidget->setRowCount(0);

    QTextStream in(&file);
    QString line;

    while (!in.atEnd()) {
        line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 4) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < fields.size(); ++col) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(fields.at(col)));
            }
        }
    }

    // Close the file
    file.close();
}



void MyContactBook::on_pushButton_4_clicked()
{
    QApplication::quit();
}

