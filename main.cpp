#include "ticTacToe.h"
#include "init.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    init w;
    w.show();
    return a.exec();
}
