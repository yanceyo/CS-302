#include "imageui.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    imageUI w;
    w.show();
    return a.exec();
}
