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
    // Add new contact
    void on_pushButton_clicked();
    
    // Export contacts
    void on_pushButton_2_clicked();
    
    // Import contacts
    void on_pushButton_3_clicked();
    
    // Exit application
    void on_pushButton_4_clicked();
    
    // Delete selected contact
    void on_pushButton_delete_clicked();
    
    // Edit selected contact
    void on_pushButton_edit_clicked();
    
    // Clear input form
    void on_pushButton_clear_clicked();
    
    // Search contacts
    void on_lineEdit_search_textChanged(const QString &text);
    
    // Table row selection changed
    void on_tableWidget_itemSelectionChanged();

private:
    Ui::MyContactBook *ui;
    
    // Helper methods
    void clearInputFields();
    void updateContactCount();
    bool validateInput();
    void showStatusMessage(const QString &message, int timeout = 3000);
    void loadContactToForm(int row);
};
#endif // MYCONTACTBOOK_H
