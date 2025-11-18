#include "mycontactbook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // 設定應用程式樣式
    a.setStyle("Fusion");
    
    // 設定應用程式資訊
    a.setApplicationName("ContactBook");
    a.setApplicationVersion("2.0");
    a.setOrganizationName("ContactBook");
    
    MyContactBook w;
    w.resize(900, 650);  // 設定視窗大小
    w.show();
    
    return a.exec();
}
