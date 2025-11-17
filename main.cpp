#include "mycontactbook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // Set application metadata
    app.setApplicationName("ContactBook");
    app.setApplicationDisplayName("Contact Book");
    app.setOrganizationName("ContactBook");
    app.setApplicationVersion("1.0");
    
    // Create and show main window
    MyContactBook window;
    window.show();
    
    return app.exec();
}
