#include "mycontactbook.h"
#include "ui_mycontactbook.h"
#include <QTableWidget>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDir>
MyContactBook::MyContactBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyContactBook)
{
    ui->setupUi(this);
    
    // Setup table widget columns
    QStringList columnTitles;
    columnTitles << QStringLiteral("學號") 
                 << QStringLiteral("班級") 
                 << QStringLiteral("姓名") 
                 << QStringLiteral("電話");
    
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(columnTitles);
    
    // Set table properties for better appearance
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
}

MyContactBook::~MyContactBook()
{
    delete ui;
}

void MyContactBook::on_pushButton_clicked()
{
    // Get input values
    QString studentId = ui->lineEdit->text().trimmed();
    QString className = ui->lineEdit_2->text().trimmed();
    QString name = ui->lineEdit_3->text().trimmed();
    QString phone = ui->lineEdit_4->text().trimmed();
    
    // Validate input - check if all fields are filled
    if (studentId.isEmpty() || className.isEmpty() || name.isEmpty() || phone.isEmpty()) {
        QMessageBox::warning(this, tr("輸入錯誤"), 
                           tr("請填寫所有欄位！\nPlease fill in all fields!"));
        return;
    }
    
    // Add new row to table
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    
    // Set items in the new row
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(studentId));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(className));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(name));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(phone));
    
    // Clear input fields for next entry
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    
    // Set focus back to first field
    ui->lineEdit->setFocus();
    
    // Show success message in status bar
    statusBar()->showMessage(tr("成功新增聯絡人！"), 3000);
}


void MyContactBook::on_pushButton_2_clicked()
{
    // Check if table has data
    if (ui->tableWidget->rowCount() == 0) {
        QMessageBox::information(this, tr("無資料"), 
                               tr("目前沒有聯絡人資料可以匯出！\nNo contact data to export!"));
        return;
    }
    
    // Get default documents directory
    QString defaultPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString defaultFileName = defaultPath + "/contactbook.csv";
    
    // Open file dialog to select save location
    QString fileName = QFileDialog::getSaveFileName(this, 
                                                    tr("匯出聯絡人"), 
                                                    defaultFileName,
                                                    tr("CSV Files (*.csv);;Text Files (*.txt);;All Files (*)"));
    
    if (fileName.isEmpty()) {
        return; // User cancelled
    }
    
    // Build content string
    QString content;
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            if (item) {
                content += item->text();
            }
            if (j < ui->tableWidget->columnCount() - 1) {
                content += ",";
            }
        }
        content += "\n";
    }
    
    // Write to file
    if (writeToFile(fileName, content)) {
        QMessageBox::information(this, tr("成功"), 
                               tr("聯絡人已成功匯出至：\n%1").arg(fileName));
        statusBar()->showMessage(tr("已匯出 %1 筆聯絡人").arg(ui->tableWidget->rowCount()), 3000);
    } else {
        QMessageBox::critical(this, tr("錯誤"), 
                            tr("無法寫入檔案：\n%1").arg(fileName));
    }
}

void MyContactBook::on_pushButton_3_clicked()
{
    // Get default documents directory
    QString defaultPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    
    // Open file dialog to select import file
    QString fileName = QFileDialog::getOpenFileName(this, 
                                                    tr("匯入聯絡人"), 
                                                    defaultPath,
                                                    tr("CSV Files (*.csv);;Text Files (*.txt);;All Files (*)"));

    if (fileName.isEmpty()) {
        return; // User cancelled
    }

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, tr("錯誤"), 
                            tr("無法開啟檔案：\n%1").arg(fileName));
        return;
    }

    // Ask for confirmation if table already has data
    if (ui->tableWidget->rowCount() > 0) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("確認"), 
                                     tr("匯入會清除現有的聯絡人資料。\n確定要繼續嗎？"),
                                     QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No) {
            file.close();
            return;
        }
    }

    // Clear existing data
    ui->tableWidget->setRowCount(0);

    // Read and parse file
    QTextStream in(&file);
    int importedCount = 0;
    
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) {
            continue; // Skip empty lines
        }
        
        QStringList fields = line.split(",");
        if (fields.size() == 4) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            
            for (int col = 0; col < fields.size(); ++col) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(fields.at(col).trimmed()));
            }
            importedCount++;
        }
    }

    file.close();

    // Show result message
    if (importedCount > 0) {
        QMessageBox::information(this, tr("成功"), 
                               tr("已成功匯入 %1 筆聯絡人資料！").arg(importedCount));
        statusBar()->showMessage(tr("已匯入 %1 筆聯絡人").arg(importedCount), 3000);
    } else {
        QMessageBox::warning(this, tr("警告"), 
                           tr("檔案中沒有找到有效的聯絡人資料！"));
    }
}
void MyContactBook::on_pushButton_4_clicked()
{
    // Ask for confirmation before exiting
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("確認"), 
                                 tr("確定要結束程式嗎？"),
                                 QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

bool MyContactBook::writeToFile(const QString &filename, const QString &content)
{
    QFile file(filename);
    
    // Try to open file for writing
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "Could not open file for writing:" << filename;
        return false;
    }
    
    // Write content to file
    QTextStream out(&file);
    out << content;
    
    // Flush and close
    file.flush();
    file.close();
    
    return true;
}

