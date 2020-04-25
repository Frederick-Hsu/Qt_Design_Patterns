#include "QObjectBrowserControl.h"
#include "Ui_QObjectBrowser.h"
#include "QOB_signal_record.h"

#include <QList>
#include <QHeaderView>
#include <QMetaProperty>
#include <QSignalMapper>

QObjectBrowserControl::QObjectBrowserControl(QWidget* parent) : QWidget(parent),
                                                                ui(new Ui_QObjectBrowser)
{
    ui->setupUi(this);
    m_obj = nullptr;

    QObject::connect(ui->updatechildrenButton, SIGNAL(clicked()), this, SLOT(on_update_children()));
    connect(ui->updatepropertiesButton, SIGNAL(clicked()), this, SLOT(on_update_properties()));
    connect(ui->uptoprentButton, SIGNAL(clicked()), this, SLOT(on_up_to_parent()));
    connect(ui->childrenTable, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(on_children_table_cell_clicked(int, int)));
    set_object(parent);
}

QObjectBrowserControl::~QObjectBrowserControl()
{
    delete ui;
    clear_signal_records();
}

void QObjectBrowserControl::clear_signal_records()
{
    for (int cnt = 0; cnt < m_signal_records.count(); ++cnt)
    {
        delete m_signal_records[cnt];
    }
    m_signal_records.clear();
}

void QObjectBrowserControl::clear()
{
    ui->childrenTable->clearContents();
    ui->childrenTable->setRowCount(1);

    ui->propertiesTable->clearContents();
    ui->propertiesTable->setRowCount(1);

    ui->signalsTable->clearContents();
    ui->signalsTable->setRowCount(1);

    ui->slotsTable->clearContents();
    ui->slotsTable->setRowCount(1);

    ui->methodsTable->clearContents();
    ui->methodsTable->setRowCount(1);

    ui->classnameLabel->setText(QString());
    ui->baseclassnameLabel->setText("");
    clear_signal_records();

    repaint();
}

bool QObjectBrowserControl::has_descendent(QObject *obj)
{
    while (obj)
    {
        if (obj == this)
        {
            return true;
        }
        obj = obj->parent();
    }
    return false;
}

void QObjectBrowserControl::on_object_destroyed()
{
    m_obj = nullptr;
    clear();
}

void QObjectBrowserControl::set_object(QObject *obj_in)
{
    if (obj_in)
    {
        disconnect(m_obj, SIGNAL(destroyed()), this, SLOT(on_object_destroyed()));
    }
    m_obj = obj_in;
    clear();
    if (!m_obj)
    {
        return;
    }
    connect(m_obj, SIGNAL(destroyed()), this, SLOT(on_object_destroyed()));

    const QMetaObject* metaobj = m_obj->metaObject();
    if (!metaobj)
    {
        return;
    }
    ui->classnameLabel->setText(metaobj->className());
    if (metaobj->superClass())
    {
        ui->baseclassnameLabel->setText(metaobj->superClass()->className());
    }
    else
    {
        ui->baseclassnameLabel->setText(QString());
    }
    if (m_obj->parent())
    {
        ui->uptoprentButton->setEnabled(true);
    }
    else
    {
        ui->uptoprentButton->setEnabled(false);
    }
    if ( (m_obj->parent()) && (m_obj->parent()->metaObject()) )
    {
        ui->parentclassnameLabel->setText(m_obj->parent()->metaObject()->className());
    }
    else
    {
        ui->parentclassnameLabel->setText(QString());
    }

    set_children();
    set_properties();
    set_signals();
    set_slots();
    set_methods();
    emit object_changed();
}

void QObjectBrowserControl::set_children()
{
    ui->childrenTable->clear();
    QHeaderView* childrenTableHeader = ui->childrenTable->horizontalHeader();
    childrenTableHeader->setSectionResizeMode(QHeaderView::Stretch);
    ui->childrenTable->setColumnCount(2);
    ui->childrenTable->setHorizontalHeaderLabels(QStringList() << tr("Type") << tr("Name"));

    if (!m_obj)
    {
        return;
    }
    QObjectList objlist = m_obj->children();
    ui->childrenTable->setRowCount(objlist.count());
    QTableWidgetItem* item;
    for (int cnt = 0; cnt < objlist.count(); ++cnt)
    {
        QString txt = "[   ]";
        const QMetaObject* metaobj = objlist[cnt]->metaObject();
        if (metaobj)
        {
            txt = metaobj->className();
        }
        item = new QTableWidgetItem;
        item->setText(txt);
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->childrenTable->setItem(cnt, 0, item);

        item = new QTableWidgetItem;
        item->setText(objlist[cnt]->objectName());
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->childrenTable->setItem(cnt, 1, item);
    }
}

void QObjectBrowserControl::set_properties()
{
    ui->propertiesTable->clear();
    ui->propertiesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->propertiesTable->setColumnCount(3);
    ui->propertiesTable->setHorizontalHeaderLabels(QStringList() << tr("Type") << tr("Name") << tr("Value"));
    if (!m_obj)
    {
        return;
    }
    const QMetaObject* metaobj = m_obj->metaObject();
    if (!metaobj)
    {
        return;
    }
    ui->propertiesTable->setRowCount(metaobj->propertyCount());
    QTableWidgetItem* item;
    for (int cnt = 0; cnt < metaobj->propertyCount(); ++cnt)
    {
        QMetaProperty property = metaobj->property(cnt);

        item = new QTableWidgetItem;
        item->setText(property.typeName());
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->propertiesTable->setItem(cnt, 0, item);

        item = new QTableWidgetItem;
        item->setText(property.name());
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->propertiesTable->setItem(cnt, 1, item);

        item = new QTableWidgetItem;
        item->setText(property.read(m_obj).toString());
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->propertiesTable->setItem(cnt, 2, item);
    }
}

void QObjectBrowserControl::set_signals()
{
    ui->signalsTable->clear();
    clear_signal_records();
    ui->signalsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->signalsTable->setColumnCount(2);
    ui->signalsTable->setHorizontalHeaderLabels(QStringList() << tr("Signal") << tr("Count"));

    if (m_obj == static_cast<QObject*>(ui->signalsTable))
    {   /* DO NOT map the signals fot the signal table, due to recursive */
        return;
    }
    if (!m_obj)
    {
        return;
    }
    const QMetaObject* metaobj = m_obj->metaObject();
    if (!metaobj)
    {
        return;
    }
    int accummulate = 0;
    for (int cnt = 0; cnt < metaobj->methodCount(); cnt++)
    {
        if (metaobj->method(cnt).methodType() == QMetaMethod::Signal)
        {
            accummulate++;
        }
    }
    ui->signalsTable->setRowCount(accummulate);

    QTableWidgetItem* item;
    int ordernum = 0;
    for (int count = 0; count < metaobj->methodCount(); ++count)
    {
        QMetaMethod method = (metaobj->method(count));
        if (method.methodType() == QMetaMethod::Signal)
        {
            QOB_signal_record* ptr = new QOB_signal_record();
            ptr->m_sigmapper = new QSignalMapper();
            ptr->m_sigmapper->setMapping(m_obj, count);

            char holdstr[1024];
            sprintf(holdstr, "2%s", method.methodSignature().data());
            connect(m_obj, holdstr, ptr->m_sigmapper, SLOT(map()));
            connect(ptr->m_sigmapper, SIGNAL(mapped(int)), this, SLOT(on_signal_triggered(int)));
            m_signal_records.append(ptr);

            item = new QTableWidgetItem;
            item->setText(method.methodSignature().data());
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            ui->signalsTable->setItem(ordernum, 0, item);

            ordernum++;
        }
    }
    update_signal_values();
}

void QObjectBrowserControl::update_signal_values()
{
    if (!m_obj)
    {
        return;
    }
    const QMetaObject* metaobj = m_obj->metaObject();
    if (!metaobj)
    {
        return;
    }
    int num = 0;
    for (int count = 0; count < metaobj->methodCount(); ++count)
    {
        QMetaMethod method = metaobj->method(count);
        if (method.methodType() == QMetaMethod::Signal)
        {
            update_signal_value(num);
            num++;
        }
    }
}

void QObjectBrowserControl::update_signal_value(int sig_num)
{
    QTableWidgetItem* item = new QTableWidgetItem;
    if ((sig_num > 0) && (sig_num < m_signal_records.count()))
    {
        item->setText(QString::number(m_signal_records[sig_num]->m_count));
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    }
    ui->signalsTable->setItem(sig_num, 1, item);
}

void QObjectBrowserControl::set_slots()
{
    ui->slotsTable->clear();
    ui->slotsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->slotsTable->setColumnCount(2);
    ui->slotsTable->setHorizontalHeaderLabels(QStringList() << "Type" << "Slot");

    if (!m_obj)     return;
    const QMetaObject* metaobj = m_obj->metaObject();
    if (!metaobj)   return;

    int rowcount = 0;
    for (int cnt = 0; cnt < metaobj->methodCount(); ++cnt)
    {
        if (metaobj->method(cnt).methodType() == QMetaMethod::Slot)
        {
            rowcount++;
        }
    }
    ui->slotsTable->setRowCount(rowcount);

    int rowindex = 0;
    QTableWidgetItem* item;
    for (int cnt = 0; cnt < metaobj->methodCount(); ++cnt)
    {
        QMetaMethod method = metaobj->method(cnt);
        if (method.methodType() == QMetaMethod::Slot)
        {
            item = new QTableWidgetItem;
            QString typeName = method.typeName();
            if (typeName.isEmpty())
            {
                typeName = "void";
            }
            item->setText(typeName);
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            ui->slotsTable->setItem(rowindex, 0, item);

            item = new QTableWidgetItem;
            item->setText(method.methodSignature().data());
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            ui->slotsTable->setItem(rowindex, 2, item);

            rowindex++;
        }
    }
}

void QObjectBrowserControl::set_methods()
{
    ui->methodsTable->clear();
    ui->methodsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->methodsTable->setColumnCount(2);
    ui->methodsTable->setHorizontalHeaderLabels(QStringList() << "Type" << "Method");

    if (!m_obj)     return;
    const QMetaObject* metaobj = m_obj->metaObject();
    if (!metaobj)   return;

    int total_row_count = 0;
    for (int cnt = 0; cnt < metaobj->methodCount(); ++cnt)
    {
        if (metaobj->method(cnt).methodType() == QMetaMethod::Method)
        {
            total_row_count++;
        }
    }
    ui->methodsTable->setRowCount(total_row_count);

    int rowindex = 0;
    QTableWidgetItem* item;
    for (int cnt = 0; cnt < metaobj->methodCount(); ++cnt)
    {
        QMetaMethod method = metaobj->method(cnt);
        if (method.methodType() == QMetaMethod::Method)
        {
            item = new QTableWidgetItem;
            item->setText(method.typeName());
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            ui->methodsTable->setItem(rowindex, 0, item);

            item = new QTableWidgetItem;
            item->setText(method.methodSignature().data());
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            ui->methodsTable->setItem(rowindex, 1, item);

            rowindex++;
        }
    }
}

void QObjectBrowserControl::on_signal_triggered(int signal_num)
{
    if ((signal_num < 0) || (signal_num >= m_signal_records.count()))
    {
        return;
    }
    m_signal_records[signal_num]->m_count++;
    update_signal_value(signal_num);
}

void QObjectBrowserControl::on_update_children()
{
    set_children();
}

void QObjectBrowserControl::on_update_properties()
{
    set_properties();
}

void QObjectBrowserControl::on_up_to_parent()
{
    if (m_obj && m_obj->parent())
        set_object(m_obj->parent());
}

void QObjectBrowserControl::on_children_table_cell_clicked(int row, int column)
{
    Q_UNUSED(column)
    if (!m_obj)     return;
    QObjectList objlist = m_obj->children();
    if (row < objlist.count())
    {
        set_object(objlist[row]);
    }
}
