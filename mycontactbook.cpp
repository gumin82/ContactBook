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
    // Check if all fields have data
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_3->text().isEmpty() || ui->lineEdit_4->text().isEmpty()) {
        ui->statusbar->showMessage("請填寫所有欄位！", 3000);
        return;
    }

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

    // Clear input fields after adding
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    
    // Show success message
    ui->statusbar->showMessage("成功新增聯絡人！", 3000);
}


void MyContactBook::on_pushButton_2_clicked()
{
    if (ui->tableWidget->rowCount() == 0) {
        ui->statusbar->showMessage("沒有資料可以匯出！", 3000);
        return;
    }

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
    ui->statusbar->showMessage("資料已成功匯出至檔案！", 3000);
}

#include <QFileDialog>

void MyContactBook::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("開啟聯絡人檔案"), "", tr("文字檔案 (*.txt);;CSV 檔案 (*.csv)"));

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Could not open file for reading:" << fileName;
        ui->statusbar->showMessage("無法開啟檔案！", 3000);
        return;
    }

    ui->tableWidget->setRowCount(0);

    QTextStream in(&file);
    QString line;
    int importedCount = 0;

    while (!in.atEnd()) {
        line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 4) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < fields.size(); ++col) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(fields.at(col)));
            }
            importedCount++;
        }
    }

    // Close the file
    file.close();
    ui->statusbar->showMessage(QString("成功匯入 %1 筆聯絡人資料！").arg(importedCount), 3000);
}



void MyContactBook::on_pushButton_4_clicked()
{
    QApplication::quit();
}

