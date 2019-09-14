#include <QApplication>
#include "cards2d_static/CardTable.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CardTable ct;
    ct.show();

    return a.exec();
}
