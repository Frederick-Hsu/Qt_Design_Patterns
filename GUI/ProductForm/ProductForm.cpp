#include "ProductForm.h"
#include "Product.h"
#include "Ui_ProductForm.h"

#include <QWidget>
#include <QDebug>
#include <QTextDocument>

ProductForm::ProductForm(Product* product, QWidget* parent) : QDialog(parent),
                                                              m_ui(new Ui::ProductForm),
                                                              m_model(product)
{
    m_ui->setupUi(this);
    update();
}

ProductForm::~ProductForm()
{
#if !defined (NDEBUG)
    qDebug() << "called ProductForm::~ProductForm()" << endl;
#endif
    delete m_ui;
    delete m_model;
}

void ProductForm::setModel(Product *model)
{
    m_model = model;
}

void ProductForm::accept()
{
    commit();
    QDialog::accept();
}

void ProductForm::commit()
{
    if (m_model == nullptr)
    {
        return;
    }
    qDebug() << "commit()";
    m_model->setName(m_ui->nameLineEdit->text());
    QTextDocument* doc = m_ui->descriptionEdit->document();
    m_model->setDescription(doc->toPlainText());
    m_model->setDateAdded(m_ui->dateEdit->date());
    m_model->setPrice(m_ui->priceSpinBox->value());
}

void ProductForm::update()
{
    if (m_model == nullptr)
    {
        return;
    }
    qDebug() << "update()";
    m_ui->nameLineEdit->setText(m_model->name());
    m_ui->priceSpinBox->setValue(m_model->price());
    m_ui->dateEdit->setDate(m_model->dateAdded());
    m_ui->descriptionEdit->setText(m_model->description());
}
