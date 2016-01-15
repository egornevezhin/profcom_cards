#include "profkom.h"
#include <QApplication>
#include "ui_profkom.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Profkom w;
    w.show();

    return a.exec();
}
