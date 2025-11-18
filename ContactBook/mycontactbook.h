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
    // 新增聯絡人
    void on_addButton_clicked();
    
    // 匯出聯絡人
    void on_exportButton_clicked();
    
    // 匯入聯絡人
    void on_importButton_clicked();
    
    // 刪除聯絡人
    void on_deleteButton_clicked();
    
    // 編輯聯絡人
    void on_editButton_clicked();
    
    // 清除表單
    void on_clearButton_clicked();
    
    // 搜尋聯絡人
    void on_searchButton_clicked();
    
    // 結束程式
    void on_exitButton_clicked();
    
    // 表格選擇變更
    void on_tableWidget_itemSelectionChanged();

private:
    Ui::MyContactBook *ui;
    QString mFilename;  // 儲存檔案路徑
    
    // 輔助函數
    void writeFile(const QString &filename, const QString &content);
    void updateStatusBar(const QString &message);
    bool validateInput();
    void clearInputFields();
    void loadContactToForm(int row);
};
#endif // MYCONTACTBOOK_H
