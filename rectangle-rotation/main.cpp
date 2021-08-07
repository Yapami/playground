#include <QApplication>

#include "RectangleRotation.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    RectangleRotation rotation;
    rotation.show();
    return QCoreApplication::exec();
}