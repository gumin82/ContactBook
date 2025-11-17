#include "mycontactbook.h"
#include "ui_mycontactbook.h"
#include <QTableWidget>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QHeaderView>

// Helper function to write data to file
bool Write(const QString &filename, const QString &str)
{
    QFile mFile(filename);
    if(!mFile.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "Could not open file for write:" << filename;
        return false;
    }
    QTextStream out(&mFile);
    out << str;
    mFile.flush();
    mFile.close();
    return true;
}
MyContactBook::MyContactBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyContactBook)
{
    ui->setupUi(this);
    
    // Set window properties
    setWindowTitle("通訊錄管理系統 - Contact Book Manager");
    
    // Configure table widget
    QStringList headers;
    ui->tableWidget->setColumnCount(4);
    headers << QStringLiteral("學號") << QStringLiteral("班級") 
            << QStringLiteral("姓名") << QStringLiteral("電話");
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    
    // Improve table appearance
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setSortingEnabled(true);
    
    // Set column widths
    ui->tableWidget->setColumnWidth(0, 100); // Student ID
    ui->tableWidget->setColumnWidth(1, 100); // Class
    ui->tableWidget->setColumnWidth(2, 150); // Name
    
    // Update contact count
    updateContactCount();
    
    // Show welcome message
    showStatusMessage("歡迎使用通訊錄管理系統！", 5000);
}

MyContactBook::~MyContactBook()
{
    delete ui;
}

void MyContactBook::on_pushButton_clicked()
{
    // Validate input before adding
    if (!validateInput()) {
        return;
    }
    
    // Create table items
    QTableWidgetItem *inputRow1 = new QTableWidgetItem(ui->lineEdit->text().trimmed());
    QTableWidgetItem *inputRow2 = new QTableWidgetItem(ui->lineEdit_2->text().trimmed());
    QTableWidgetItem *inputRow3 = new QTableWidgetItem(ui->lineEdit_3->text().trimmed());
    QTableWidgetItem *inputRow4 = new QTableWidgetItem(ui->lineEdit_4->text().trimmed());
    
    // Insert new row
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, inputRow1);
    ui->tableWidget->setItem(row, 1, inputRow2);
    ui->tableWidget->setItem(row, 2, inputRow3);
    ui->tableWidget->setItem(row, 3, inputRow4);
    
    // Clear input fields after adding
    clearInputFields();
    
    // Update contact count
    updateContactCount();
    
    // Show success message
    showStatusMessage("聯絡人新增成功！");
}


void MyContactBook::on_pushButton_2_clicked()
{
    // Check if there are contacts to export
    if (ui->tableWidget->rowCount() == 0) {
        QMessageBox::warning(this, "匯出失敗", "沒有可匯出的聯絡人資料！");
        return;
    }
    
    // Open file dialog for export location
    QString fileName = QFileDialog::getSaveFileName(this, 
        tr("匯出聯絡人"), 
        "", 
        tr("文字檔案 (*.txt);;CSV檔案 (*.csv);;所有檔案 (*.*)"));
    
    if (fileName.isEmpty()) {
        return;
    }
    
    // Build save content
    QString saveFile;
    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for(int j = 0; j < ui->tableWidget->columnCount(); j++) {
            if (ui->tableWidget->item(i, j)) {
                saveFile += ui->tableWidget->item(i, j)->text();
            }
            if(j < ui->tableWidget->columnCount() - 1) {
                saveFile += ",";
            }
        }
        saveFile += "\n";
    }
    
    // Write to file
    if (Write(fileName, saveFile)) {
        showStatusMessage("聯絡人匯出成功！檔案：" + fileName);
        QMessageBox::information(this, "匯出成功", "聯絡人已成功匯出到：\n" + fileName);
    } else {
        QMessageBox::critical(this, "匯出失敗", "無法寫入檔案：\n" + fileName);
    }
}

void MyContactBook::on_pushButton_3_clicked()
{
    // Confirm if table has existing data
    if (ui->tableWidget->rowCount() > 0) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, 
            "確認匯入", 
            "匯入將會清除現有資料，是否繼續？",
            QMessageBox::Yes | QMessageBox::No);
        if (reply != QMessageBox::Yes) {
            return;
        }
    }
    
    QString fileName = QFileDialog::getOpenFileName(this, 
        tr("匯入聯絡人"), 
        "", 
        tr("文字檔案 (*.txt);;CSV檔案 (*.csv);;所有檔案 (*.*)"));

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, "匯入失敗", "無法開啟檔案：\n" + fileName);
        return;
    }

    // Clear existing data
    ui->tableWidget->setRowCount(0);

    QTextStream in(&file);
    int importCount = 0;
    
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        
        QStringList fields = line.split(",");
        if (fields.size() == 4) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < fields.size(); ++col) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(fields.at(col).trimmed()));
            }
            importCount++;
        }
    }

    file.close();
    
    // Update contact count
    updateContactCount();
    
    // Show result message
    showStatusMessage(QString("成功匯入 %1 筆聯絡人！").arg(importCount));
    QMessageBox::information(this, "匯入成功", 
        QString("已成功匯入 %1 筆聯絡人資料！").arg(importCount));
}



void MyContactBook::on_pushButton_4_clicked()
{
    // Confirm before exit if there's data
    if (ui->tableWidget->rowCount() > 0) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, 
            "確認結束", 
            "確定要結束程式嗎？\n請確保已儲存資料！",
            QMessageBox::Yes | QMessageBox::No);
        if (reply != QMessageBox::Yes) {
            return;
        }
    }
    QApplication::quit();
}

// Delete selected contact
void MyContactBook::on_pushButton_delete_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "刪除失敗", "請先選擇要刪除的聯絡人！");
        return;
    }
    
    // Get contact name for confirmation
    QString name = ui->tableWidget->item(currentRow, 2) ? 
                   ui->tableWidget->item(currentRow, 2)->text() : "此聯絡人";
    
    QMessageBox::StandardButton reply = QMessageBox::question(this, 
        "確認刪除", 
        QString("確定要刪除 %1 的資料嗎？").arg(name),
        QMessageBox::Yes | QMessageBox::No);
        
    if (reply == QMessageBox::Yes) {
        ui->tableWidget->removeRow(currentRow);
        updateContactCount();
        showStatusMessage("聯絡人已刪除！");
    }
}

// Edit selected contact
void MyContactBook::on_pushButton_edit_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "編輯失敗", "請先選擇要編輯的聯絡人！");
        return;
    }
    
    // Load selected contact to form
    loadContactToForm(currentRow);
    
    // Delete the old row (will be re-added when user clicks Add)
    ui->tableWidget->removeRow(currentRow);
    updateContactCount();
    showStatusMessage("請修改資料後點擊「新增」按鈕");
}

// Clear input form
void MyContactBook::on_pushButton_clear_clicked()
{
    clearInputFields();
    showStatusMessage("輸入欄位已清除");
}

// Search contacts
void MyContactBook::on_lineEdit_search_textChanged(const QString &text)
{
    QString searchText = text.trimmed().toLower();
    
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        bool match = false;
        
        // Search in all columns
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (item && item->text().toLower().contains(searchText)) {
                match = true;
                break;
            }
        }
        
        ui->tableWidget->setRowHidden(row, !match);
    }
    
    // Count visible rows
    int visibleCount = 0;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (!ui->tableWidget->isRowHidden(row)) {
            visibleCount++;
        }
    }
    
    if (!searchText.isEmpty()) {
        showStatusMessage(QString("找到 %1 筆符合的聯絡人").arg(visibleCount));
    }
}

// Table selection changed
void MyContactBook::on_tableWidget_itemSelectionChanged()
{
    // Enable/disable edit and delete buttons based on selection
    bool hasSelection = ui->tableWidget->currentRow() >= 0;
    // This will be connected in UI if needed
}

// Helper method: Clear input fields
void MyContactBook::clearInputFields()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit->setFocus();
}

// Helper method: Update contact count in status bar
void MyContactBook::updateContactCount()
{
    int count = ui->tableWidget->rowCount();
    ui->statusbar->showMessage(QString("總計 %1 筆聯絡人").arg(count));
}

// Helper method: Validate input
bool MyContactBook::validateInput()
{
    // Check if required fields are filled
    if (ui->lineEdit->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "輸入錯誤", "請輸入學號！");
        ui->lineEdit->setFocus();
        return false;
    }
    
    if (ui->lineEdit_3->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "輸入錯誤", "請輸入姓名！");
        ui->lineEdit_3->setFocus();
        return false;
    }
    
    // Validate phone number format (basic validation)
    QString phone = ui->lineEdit_4->text().trimmed();
    if (!phone.isEmpty()) {
        QRegularExpression phoneRegex("^[0-9\\-\\+\\(\\)\\s]+$");
        if (!phoneRegex.match(phone).hasMatch()) {
            QMessageBox::warning(this, "輸入錯誤", "電話號碼格式不正確！\n請只使用數字、空格、+、-、()");
            ui->lineEdit_4->setFocus();
            return false;
        }
    }
    
    return true;
}

// Helper method: Show status message
void MyContactBook::showStatusMessage(const QString &message, int timeout)
{
    ui->statusbar->showMessage(message, timeout);
}

// Helper method: Load contact to form for editing
void MyContactBook::loadContactToForm(int row)
{
    if (row >= 0 && row < ui->tableWidget->rowCount()) {
        if (ui->tableWidget->item(row, 0))
            ui->lineEdit->setText(ui->tableWidget->item(row, 0)->text());
        if (ui->tableWidget->item(row, 1))
            ui->lineEdit_2->setText(ui->tableWidget->item(row, 1)->text());
        if (ui->tableWidget->item(row, 2))
            ui->lineEdit_3->setText(ui->tableWidget->item(row, 2)->text());
        if (ui->tableWidget->item(row, 3))
            ui->lineEdit_4->setText(ui->tableWidget->item(row, 3)->text());
    }
}

