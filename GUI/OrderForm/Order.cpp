#include "Order.h"

Order::Order() : m_name(""), m_quantity(0), m_unitprice(0.00)
{
    m_date = QDate::currentDate();
}

Order::Order(QString name,
             QDate date,
             unsigned qty,
             double price) : m_name(name), m_quantity(qty), m_unitprice(price)
{
    m_date = date;
}

Order::Order(const Order& other)
{
    m_name = other.m_name;
    m_date = other.m_date;
    m_quantity = other.m_quantity;
    m_unitprice = other.m_unitprice;
}

Order& Order::operator=(const Order &other)
{
    m_name = other.m_name;
    m_date = other.m_date;
    m_quantity = other.m_quantity;
    m_unitprice = other.m_unitprice;
    return  *this;
}

double Order::getTotalPrice()
{
    return m_quantity * m_unitprice;
}

QString Order::getName()
{
    return m_name;
}

QDate Order::getDate()
{
    return m_date;
}

unsigned Order::getQuantity()
{
    return m_quantity;
}

double Order::getUnitPrice()
{
    return m_unitprice;
}

void Order::setName(QString name)
{
    m_name = name;
}

void Order::setDate(QDate date)
{
    m_date = date;
}

void Order::setQuantity(unsigned int qty)
{
    m_quantity = qty;
}

void Order::setUnitPrice(double price)
{
    m_unitprice = price;
}
