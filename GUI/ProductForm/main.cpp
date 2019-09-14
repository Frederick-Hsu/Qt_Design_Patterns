#include <QApplication>
#include <QDate>

#include "ProductForm.h"
#include "Product.h"

#define INSTANTIATE_OBJECT1     1
#define INSTANTIATE_OBJECT2     2
#define INSTANTIATE_OBJECT      INSTANTIATE_OBJECT2

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDate today = QDate::currentDate();
    QDate yesterday(today.year(), today.month(), today.day()-1);

#if (INSTANTIATE_OBJECT == INSTANTIATE_OBJECT1)
    Product *prod = new Product("Frederique Hsu", "It is my name", 1.25, yesterday);
    ProductForm form(prod, nullptr);
    form.show();

    delete prod;
#elif (INSTANTIATE_OBJECT == INSTANTIATE_OBJECT2)
    Product movie("Fast & Furious",
                  "The name of one famous movie, its ticket price is: RMB70.90",
                  70.90,
                  yesterday);
    ProductForm form(&movie, nullptr);
    form.show();
#else
    ProductForm form(new Product(), nullptr);
    form.show();
#endif


    return a.exec();
}
