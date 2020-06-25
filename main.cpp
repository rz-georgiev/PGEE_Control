#include "logonmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::restoreOverrideCursor();
    LogonMenu w;
    w.show();



    return a.exec();
}
