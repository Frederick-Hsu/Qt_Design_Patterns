#include "CardTable.h"
#include "Card.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#define WINDOW_LAYOUT_WITHOUT_STRETCH_SPACING   1
#define WINDOW_LAYOUT_WITH_STRETCH_SPACING      2
#define WINDLOW_LAYOUT                          WINDOW_LAYOUT_WITH_STRETCH_SPACING

CardTable::CardTable(QWidget* parent) : QWidget(parent)
{
#if (WINDLOW_LAYOUT == WINDOW_LAYOUT_WITHOUT_STRETCH_SPACING)
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
#elif (WINDLOW_LAYOUT == WINDOW_LAYOUT_WITH_STRETCH_SPACING)
    QHBoxLayout* first_low = new QHBoxLayout();
    first_low->addWidget(new Card("as"));
    first_low->addWidget(new Card("ah"));
    first_low->addWidget(new Card("ad"));
    first_low->addWidget(new Card("ks"));

    QHBoxLayout* second_row = new QHBoxLayout();
    second_row->addWidget(new Card("ks"));
    second_row->addWidget(new Card("kh"));
    second_row->addWidget(new Card("kd"));

    QVBoxLayout* rows = new QVBoxLayout();
    rows->addLayout(first_low);
    rows->addLayout(second_row);
    rows->addStretch(1);

    QVBoxLayout* buttons = new QVBoxLayout();
    buttons->addStretch(1);
    buttons->addWidget(new QPushButton(tr("Deal")));
    buttons->addWidget(new QPushButton(tr("Shuffle")));
    buttons->addSpacing(20);

    QHBoxLayout* cols = new QHBoxLayout();
    setLayout(cols);

    cols->addLayout(rows);
    cols->addLayout(buttons);
    cols->addStretch(0);
#endif
}
