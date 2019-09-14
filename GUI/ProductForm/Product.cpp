#include "Product.h"

#include <QDebug>

Product::Product() : m_name(""), m_description(""), m_price(0.00)
{
    m_dateValid = QDate::currentDate();
}

Product::Product(QString name,
                 QString description,
                 double price,
                 QDate date) : m_name(name), m_description(description), m_price(price)
{
    m_dateValid = date;
}

Product::~Product()
{
#if !defined (NDEBUG)
    qDebug() << "called Product::~Product()" << endl;
#endif
    // delete m_dateValid;     /* cannot delete expression of type 'QDate' */
}

Product& Product::operator=(const Product &other)
{
    m_name = other.m_name;
    m_description = other.m_description;
    m_price = other.m_price;
    m_dateValid = other.m_dateValid;
    return *this;
}

void Product::setName(QString name)
{
    m_name = name;
}

void Product::setDescription(QString desc)
{
    m_description = desc;
}

void Product::setDateAdded(QDate date)
{
    m_dateValid = date;
}

void Product::setPrice(double price)
{
    m_price = price;
}

QString Product::name()
{
    return m_name;
}

double Product::price()
{
    return m_price;
}

QDate Product::dateAdded()
{
    return m_dateValid;
}

QString Product::description()
{
    return m_description;
}
