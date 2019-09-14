#include "OrderForm.h"
#include "Ui_OrderForm.h"
#include "Order.h"

OrderForm::OrderForm(Order* order, QWidget* parent) : QDialog(parent),                                                      
                                                      m_UI(new Ui::OrderForm),
                                                      m_Order(order)
{
    m_UI->setupUi(this);
    update();
}

OrderForm::~OrderForm()
{
    delete m_UI;
    delete m_Order;
}

void OrderForm::setOrder(Order* order)
{
    m_Order = order;
}

void OrderForm::accept()
{
    commit();
    QDialog::accept();
}

void OrderForm::commit()
{
    if (m_Order == nullptr)
    {
        return;
    }
    m_Order->setName(m_UI->nameEdit->text());
    m_Order->setDate(m_UI->dateEdit->date());
    m_Order->setQuantity(static_cast<unsigned>(m_UI->qtySpinBox->value()));
    m_Order->setUnitPrice(m_UI->unitpriceSpinBox->value());
}

void OrderForm::update()
{
    if (m_Order == nullptr)
    {
        return;
    }
    m_UI->nameEdit->setText(m_Order->getName());
    m_UI->dateEdit->setDate(m_Order->getDate());
    m_UI->qtySpinBox->setValue(static_cast<int>(m_Order->getQuantity()));
    m_UI->unitpriceSpinBox->setValue(m_Order->getUnitPrice());
    m_UI->totalpriceSpinBox->setValue(m_Order->getTotalPrice());

}
