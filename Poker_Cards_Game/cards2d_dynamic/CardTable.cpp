#include "CardTable.h"
#include "Card.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

CardTable::CardTable(QWidget* parent) : QWidget(parent)
{
    QHBoxLayout* first_row = new QHBoxLayout();
    first_row->addWidget(new Card("ah"));
    first_row->addWidget(new Card("qd"));
    first_row->addWidget(new Card("ks"));
    first_row->addWidget(new Card("8c"));

    QHBoxLayout* second_row = new QHBoxLayout();
    second_row->addWidget(new Card("qs"));
    second_row->addWidget(new Card("js"));
    second_row->addWidget(new Card("td"));

    QVBoxLayout* rows = new QVBoxLayout();
    rows->addLayout(first_row);
    rows->addLayout(second_row);

    QVBoxLayout* buttons = new QVBoxLayout();
    buttons->addWidget(new QPushButton("Deal"));
    buttons->addWidget(new QPushButton("Shuffle"));

    QHBoxLayout* cols = new QHBoxLayout();
    setLayout(cols);
    cols->addLayout(rows);
    cols->addLayout(buttons);
}
