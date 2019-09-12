
#include <QApplication>
#include "InputForm.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InputForm form;
    form.show();

    return a.exec();
}
