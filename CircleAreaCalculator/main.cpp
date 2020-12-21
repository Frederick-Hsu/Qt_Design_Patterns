#include "circle_area_calculator_dialog.hpp"
#include "CircleDialog.hpp"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if 0
    CCircleAreaCalculatorDialog w;
    w.show();
#else
    CCircleDialog dialog;
    qDebug() << "i1 = " << dialog.i1;
    dialog.show();
#endif
    return app.exec();
}
