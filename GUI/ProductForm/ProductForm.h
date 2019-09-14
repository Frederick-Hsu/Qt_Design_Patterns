#ifndef PRODUCT_FORM_H
#define PRODUCT_FORM_H

    #include <QDialog>

    class Product;
    class QWidget;
    class Ui_ProductForm;

    class ProductForm : public QDialog
    {
        Q_OBJECT
    public:
        explicit ProductForm(Product* product = nullptr, QWidget* parent = nullptr);
        ~ProductForm();

        void setModel(Product* model);
    public slots:
        void accept();
        void commit();
        void update();
    private:
        Ui_ProductForm* m_ui;
        Product* m_model;
    };

#endif  /* PRODUCT_FORM_H */
