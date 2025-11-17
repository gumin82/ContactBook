#ifndef MYCONTACTBOOK_H
#define MYCONTACTBOOK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyContactBook;
}
QT_END_NAMESPACE

/**
 * @brief The MyContactBook class - Main window for contact book application
 * 
 * This class manages a contact book interface that allows users to:
 * - Add new contacts with student ID, class, name, and phone
 * - Import contacts from CSV/TXT files
 * - Export contacts to CSV/TXT files
 * - Display contacts in a table format
 */
class MyContactBook : public QMainWindow
{
    Q_OBJECT

public:
    MyContactBook(QWidget *parent = nullptr);
    ~MyContactBook();

private slots:
    /**
     * @brief Add a new contact to the table
     */
    void on_pushButton_clicked();

    /**
     * @brief Export contacts to a file
     */
    void on_pushButton_2_clicked();

    /**
     * @brief Import contacts from a file
     */
    void on_pushButton_3_clicked();

    /**
     * @brief Exit the application
     */
    void on_pushButton_4_clicked();

private:
    Ui::MyContactBook *ui;
    
    /**
     * @brief Write content to a file
     * @param filename The target file path
     * @param content The content to write
     * @return true if successful, false otherwise
     */
    bool writeToFile(const QString &filename, const QString &content);
};

#endif // MYCONTACTBOOK_H
