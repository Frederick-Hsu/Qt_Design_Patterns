#include "PuzzleView.h"
#include "PuzzleModel.h"

#include <QPushButton>
#include <QString>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

PuzzleView::PuzzleView(PuzzleModel* model) : m_Model(model)
{
    setWindowTitle(tr("15 digits Puzzle"));

    QPushButton* digit_button[15];
    for (int label_index = 0; label_index < 15; ++label_index)
    {
        digit_button[label_index] = new QPushButton(QString("%1").arg(label_index+1));
        m_Buttons.addButton(digit_button[label_index]);
    }

    m_Layout = new QGridLayout();
    m_Layout->addWidget(digit_button[0], 0, 0, Qt::Alignment());
    m_Layout->addWidget(digit_button[1], 0, 1);
    m_Layout->addWidget(digit_button[2], 0, 2);
    m_Layout->addWidget(digit_button[3], 0, 3);
    m_Layout->addWidget(digit_button[4], 1, 0);
    m_Layout->addWidget(digit_button[5], 1, 1);
    m_Layout->addWidget(digit_button[6], 1, 2);
    m_Layout->addWidget(digit_button[7], 1, 3);
    m_Layout->addWidget(digit_button[8], 2, 0);
    m_Layout->addWidget(digit_button[9], 2, 1);
    m_Layout->addWidget(digit_button[10], 2, 2);
    m_Layout->addWidget(digit_button[11], 2, 3);
    m_Layout->addWidget(digit_button[12], 3, 0);
    m_Layout->addWidget(digit_button[13], 3, 1);
    m_Layout->addWidget(digit_button[14], 3, 2);

    QPushButton* shuffleBtn = new QPushButton(tr("Shuffle"));
    QPushButton* quitBtn    = new QPushButton(tr("Quit"));

    QVBoxLayout* btnCol = new QVBoxLayout();
    btnCol->addStretch(2);
    btnCol->addWidget(shuffleBtn);
    btnCol->addSpacing(1);
    btnCol->addWidget(quitBtn);
    btnCol->addStretch(1);

    QHBoxLayout* panel_layout = new QHBoxLayout();
    panel_layout->addLayout(m_Layout);
    panel_layout->addLayout(btnCol);
    setLayout(panel_layout);

    connect(shuffleBtn, SIGNAL(clicked()), this, SLOT(shuffle()), Qt::AutoConnection);
    connect(quitBtn, SIGNAL(clicked()), this, SLOT(close()), Qt::AutoConnection);
}

void PuzzleView::shuffle()
{

}

void PuzzleView::tryToSlide(QAbstractButton *button)
{
    QPushButton* currentBtn = static_cast<QPushButton*>(button);
    QString label = currentBtn->text();
    int row, col, rowSpan, colSpan;
    m_Layout->getItemPosition(label.toInt(), &row, &col, &rowSpan, &colSpan);

    m_Buttons.removeButton(button);
    m_Layout->removeWidget(currentBtn);

    // QPushButton* movedBtn = new QPushButton(label);
}
