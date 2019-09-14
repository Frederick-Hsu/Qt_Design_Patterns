#ifndef PRODUCT_H
#define PRODUCT_H

    #include <QString>
    #include <QDate>

    class Product
    {
    public:
        Product();
        Product(QString name,
                QString description,
                double price,
                QDate date = QDate::currentDate());
        ~Product();
        Product& operator=(const Product& other);
    public:
        void setName(QString name);
        void setDescription(QString desc);
        void setDateAdded(QDate date);
        void setPrice(double price);

        QString name();
        double price();
        QDate dateAdded();
        QString description();
    private:
        QString m_name;
        QString m_description;
        double m_price;
        QDate m_dateValid;
    };

#endif  /* PRODUCT_H */
