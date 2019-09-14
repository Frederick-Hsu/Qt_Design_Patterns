#ifndef ORDER_H
#define ORDER_H

    #include <QString>
    #include <QDate>

    class Order
    {
    public:
        Order();
        ~Order() {}
        Order(QString name, QDate date, unsigned qty, double price);
        Order(const Order& other);
        Order& operator=(const Order& other);
    private:
        QString m_name;
        QDate m_date;
        unsigned m_quantity;
        double m_unitprice;
    public:
        double getTotalPrice();
        QString getName();
        QDate getDate();
        unsigned getQuantity();
        double getUnitPrice();

        void setName(QString name);
        void setDate(QDate date);
        void setQuantity(unsigned qty);
        void setUnitPrice(double price);
    };

#endif  /* ORDER_H */
