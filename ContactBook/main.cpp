#include "mycontactbook.h"
#include <QApplication>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // 設定應用程式樣式
    a.setStyle("Fusion");
    
    // 設定應用程式資訊
    a.setApplicationName("ContactBook");
    a.setApplicationVersion("2.0");
    a.setOrganizationName("ContactBook");
    
    // 設定顏色主題
    QString styleSheet = R"(
        QMainWindow {
            background-color: #f5f5f5;
        }
        
        QTableWidget {
            background-color: white;
            alternate-background-color: #f0f8ff;
            gridline-color: #d3d3d3;
            border: 2px solid #4a90e2;
            border-radius: 5px;
            font-size: 11pt;
        }
        
        QTableWidget::item:selected {
            background-color: #4a90e2;
            color: white;
        }
        
        QTableWidget QHeaderView::section {
            background-color: #4a90e2;
            color: white;
            padding: 8px;
            border: none;
            font-weight: bold;
            font-size: 11pt;
        }
        
        QGroupBox {
            border: 2px solid #4a90e2;
            border-radius: 8px;
            margin-top: 12px;
            font-weight: bold;
            font-size: 11pt;
            padding-top: 10px;
            background-color: white;
        }
        
        QGroupBox::title {
            subcontrol-origin: margin;
            subcontrol-position: top center;
            padding: 5px 15px;
            background-color: #4a90e2;
            color: white;
            border-radius: 5px;
        }
        
        QLabel {
            font-size: 10pt;
            font-weight: bold;
            color: #333333;
        }
        
        QLineEdit {
            padding: 8px;
            border: 2px solid #d3d3d3;
            border-radius: 5px;
            background-color: white;
            font-size: 10pt;
        }
        
        QLineEdit:focus {
            border: 2px solid #4a90e2;
        }
        
        QPushButton {
            background-color: #4a90e2;
            color: white;
            border: none;
            border-radius: 5px;
            padding: 8px 16px;
            font-size: 10pt;
            font-weight: bold;
            min-width: 80px;
        }
        
        QPushButton:hover {
            background-color: #357abd;
        }
        
        QPushButton:pressed {
            background-color: #2c5fa8;
        }
        
        QPushButton#addButton {
            background-color: #5cb85c;
        }
        
        QPushButton#addButton:hover {
            background-color: #4cae4c;
        }
        
        QPushButton#editButton {
            background-color: #f0ad4e;
        }
        
        QPushButton#editButton:hover {
            background-color: #ec971f;
        }
        
        QPushButton#deleteButton {
            background-color: #d9534f;
        }
        
        QPushButton#deleteButton:hover {
            background-color: #c9302c;
        }
        
        QPushButton#clearButton {
            background-color: #5bc0de;
        }
        
        QPushButton#clearButton:hover {
            background-color: #46b8da;
        }
        
        QPushButton#searchButton {
            background-color: #9b59b6;
        }
        
        QPushButton#searchButton:hover {
            background-color: #8e44ad;
        }
        
        QPushButton#exitButton {
            background-color: #777777;
        }
        
        QPushButton#exitButton:hover {
            background-color: #666666;
        }
        
        QStatusBar {
            background-color: #4a90e2;
            color: white;
            font-weight: bold;
        }
        
        QMenuBar {
            background-color: #4a90e2;
            color: white;
            font-weight: bold;
        }
        
        QMenuBar::item:selected {
            background-color: #357abd;
        }
    )";
    
    a.setStyleSheet(styleSheet);
    
    MyContactBook w;
    w.resize(1000, 700);  // 稍微調大視窗
    w.show();
    
    return a.exec();
}
