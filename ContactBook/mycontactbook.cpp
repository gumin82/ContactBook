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
    , mFilename("")
{
    ui->setupUi(this);
    
    // 設定視窗標題和圖示
    setWindowTitle(QStringLiteral("📇 聯絡人管理系統"));
    
    // 設定表格
    QStringList colTitles;
    ui->tableWidget->setColumnCount(4);
    colTitles << QStringLiteral("📚 學號") << QStringLiteral("🏫 班級") 
              << QStringLiteral("👤 姓名") << QStringLiteral("📞 電話");
    ui->tableWidget->setHorizontalHeaderLabels(colTitles);
    
    // 設定表格屬性
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    
    // 設定列高
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(35);
    
    // 設定欄寬
    ui->tableWidget->setColumnWidth(0, 120);
    ui->tableWidget->setColumnWidth(1, 120);
    ui->tableWidget->setColumnWidth(2, 150);
    ui->tableWidget->setColumnWidth(3, 150);
    
    // 設定預設檔案路徑
    QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    mFilename = documentsPath + "/contactbook.txt";
    
    // 顯示歡迎訊息
    updateStatusBar(QStringLiteral("✨ 歡迎使用聯絡人管理系統！"));
}

MyContactBook::~MyContactBook()
{
    delete ui;
}

// 輔助函數：寫入檔案
void MyContactBook::writeFile(const QString &filename, const QString &content)
{
    QFile file(filename);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::critical(this, QStringLiteral("錯誤"), 
                            QStringLiteral("無法寫入檔案：") + filename);
        return;
    }
    
    QTextStream out(&file);
    out << content;
    file.flush();
    file.close();
}

// 輔助函數：更新狀態列
void MyContactBook::updateStatusBar(const QString &message)
{
    ui->statusbar->showMessage(message, 3000);
}

// 輔助函數：驗證輸入
bool MyContactBook::validateInput()
{
    if (ui->lineEdit->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, QStringLiteral("輸入錯誤"), 
                           QStringLiteral("學號不能為空！"));
        ui->lineEdit->setFocus();
        return false;
    }
    
    if (ui->lineEdit_2->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, QStringLiteral("輸入錯誤"), 
                           QStringLiteral("班級不能為空！"));
        ui->lineEdit_2->setFocus();
        return false;
    }
    
    if (ui->lineEdit_3->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, QStringLiteral("輸入錯誤"), 
                           QStringLiteral("姓名不能為空！"));
        ui->lineEdit_3->setFocus();
        return false;
    }
    
    if (ui->lineEdit_4->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, QStringLiteral("輸入錯誤"), 
                           QStringLiteral("電話不能為空！"));
        ui->lineEdit_4->setFocus();
        return false;
    }
    
    return true;
}

// 輔助函數：清除輸入欄位
void MyContactBook::clearInputFields()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit->setFocus();
}

// 輔助函數：載入聯絡人至表單
void MyContactBook::loadContactToForm(int row)
{
    if (row < 0 || row >= ui->tableWidget->rowCount()) {
        return;
    }
    
    ui->lineEdit->setText(ui->tableWidget->item(row, 0)->text());
    ui->lineEdit_2->setText(ui->tableWidget->item(row, 1)->text());
    ui->lineEdit_3->setText(ui->tableWidget->item(row, 2)->text());
    ui->lineEdit_4->setText(ui->tableWidget->item(row, 3)->text());
}

// 新增聯絡人
void MyContactBook::on_addButton_clicked()
{
    if (!validateInput()) {
        return;
    }
    
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ui->lineEdit->text().trimmed()));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(ui->lineEdit_2->text().trimmed()));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(ui->lineEdit_3->text().trimmed()));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(ui->lineEdit_4->text().trimmed()));
    
    clearInputFields();
    updateStatusBar(QStringLiteral("已新增聯絡人"));
}

// 匯出聯絡人
void MyContactBook::on_exportButton_clicked()
{
    if (ui->tableWidget->rowCount() == 0) {
        QMessageBox::information(this, QStringLiteral("提示"), 
                               QStringLiteral("沒有聯絡人可以匯出！"));
        return;
    }
    
    QString fileName = QFileDialog::getSaveFileName(this, 
                                                    QStringLiteral("匯出聯絡人"), 
                                                    mFilename,
                                                    QStringLiteral("文字檔 (*.txt);;CSV檔 (*.csv);;所有檔案 (*.*)"));
    
    if (fileName.isEmpty()) {
        return;
    }
    
    QString saveContent;
    // 儲存檔案內容
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            saveContent += ui->tableWidget->item(i, j)->text();
            if (j < ui->tableWidget->columnCount() - 1) {
                saveContent += ",";
            }
        }
        saveContent += "\n";
    }
    
    writeFile(fileName, saveContent);
    mFilename = fileName;  // 記住最後使用的檔案
    updateStatusBar(QStringLiteral("已匯出 %1 筆聯絡人").arg(ui->tableWidget->rowCount()));
}

// 匯入聯絡人
void MyContactBook::on_importButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, 
                                                    QStringLiteral("匯入聯絡人"), 
                                                    mFilename,
                                                    QStringLiteral("文字檔 (*.txt);;CSV檔 (*.csv);;所有檔案 (*.*)"));

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, QStringLiteral("錯誤"), 
                            QStringLiteral("無法開啟檔案：") + fileName);
        return;
    }

    // 詢問是否清除現有資料
    if (ui->tableWidget->rowCount() > 0) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, 
                                                                 QStringLiteral("確認"), 
                                                                 QStringLiteral("是否清除現有聯絡人？"),
                                                                 QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            ui->tableWidget->setRowCount(0);
        }
    }

    QTextStream in(&file);
    int importedCount = 0;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) {
            continue;
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
    mFilename = fileName;  // 記住最後使用的檔案
    updateStatusBar(QStringLiteral("已匯入 %1 筆聯絡人").arg(importedCount));
}
// 刪除聯絡人
void MyContactBook::on_deleteButton_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    
    if (currentRow < 0) {
        QMessageBox::information(this, QStringLiteral("提示"), 
                               QStringLiteral("請先選擇要刪除的聯絡人！"));
        return;
    }
    
    QString name = ui->tableWidget->item(currentRow, 2)->text();
    QMessageBox::StandardButton reply = QMessageBox::question(this, 
                                                             QStringLiteral("確認刪除"), 
                                                             QStringLiteral("確定要刪除 %1 的聯絡資訊嗎？").arg(name),
                                                             QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        ui->tableWidget->removeRow(currentRow);
        updateStatusBar(QStringLiteral("已刪除聯絡人：%1").arg(name));
    }
}

// 編輯聯絡人
void MyContactBook::on_editButton_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    
    if (currentRow < 0) {
        QMessageBox::information(this, QStringLiteral("提示"), 
                               QStringLiteral("請先選擇要編輯的聯絡人！"));
        return;
    }
    
    if (!validateInput()) {
        return;
    }
    
    ui->tableWidget->item(currentRow, 0)->setText(ui->lineEdit->text().trimmed());
    ui->tableWidget->item(currentRow, 1)->setText(ui->lineEdit_2->text().trimmed());
    ui->tableWidget->item(currentRow, 2)->setText(ui->lineEdit_3->text().trimmed());
    ui->tableWidget->item(currentRow, 3)->setText(ui->lineEdit_4->text().trimmed());
    
    clearInputFields();
    updateStatusBar(QStringLiteral("已更新聯絡人"));
}

// 清除表單
void MyContactBook::on_clearButton_clicked()
{
    clearInputFields();
    ui->tableWidget->clearSelection();
    updateStatusBar(QStringLiteral("已清除表單"));
}

// 搜尋聯絡人
void MyContactBook::on_searchButton_clicked()
{
    QString searchText = ui->lineEdit_3->text().trimmed();
    
    if (searchText.isEmpty()) {
        QMessageBox::information(this, QStringLiteral("提示"), 
                               QStringLiteral("請在姓名欄位輸入搜尋關鍵字！"));
        return;
    }
    
    int foundCount = 0;
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        bool match = false;
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            if (ui->tableWidget->item(i, j)->text().contains(searchText, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        
        if (match) {
            ui->tableWidget->showRow(i);
            foundCount++;
        } else {
            ui->tableWidget->hideRow(i);
        }
    }
    
    if (foundCount == 0) {
        QMessageBox::information(this, QStringLiteral("搜尋結果"), 
                               QStringLiteral("找不到符合 \"%1\" 的聯絡人！").arg(searchText));
        // 顯示所有列
        for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
            ui->tableWidget->showRow(i);
        }
    } else {
        updateStatusBar(QStringLiteral("找到 %1 筆符合的聯絡人").arg(foundCount));
    }
}

// 結束程式
void MyContactBook::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, 
                                                             QStringLiteral("確認結束"), 
                                                             QStringLiteral("確定要結束程式嗎？"),
                                                             QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

// 表格選擇變更
void MyContactBook::on_tableWidget_itemSelectionChanged()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow >= 0) {
        loadContactToForm(currentRow);
    }
}
