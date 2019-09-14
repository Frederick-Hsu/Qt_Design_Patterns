#include <QApplication>
#include "OrderForm.h"
#include "Order.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Order myOrder("Apple", QDate::currentDate(), 5, 5.95);
    OrderForm form(&myOrder, nullptr);
    form.show();

    return a.exec();
}
