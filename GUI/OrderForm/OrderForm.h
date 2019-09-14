#ifndef ORDERFORM_H
#define ORDERFORM_H

    #include <QDialog>

    class Ui_OrderForm;
    class Order;

    class OrderForm : public QDialog
    {
        Q_OBJECT
    public:
        explicit OrderForm(Order* order, QWidget* parent = nullptr);
        ~OrderForm();
        void setOrder(Order* order);
    private:
        Ui_OrderForm* m_UI;
        Order* m_Order;
    public slots:
        void accept();
        void commit();
        void update();
    };

#endif  /* ORDERFORM_H */
