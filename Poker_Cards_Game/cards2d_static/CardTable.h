#ifndef CARD_TABLE_H
#define CARD_TABLE_H

    #include "CardPics.h"
    #include <QWidget>

    class CardTable : public QWidget
    {
    public:
        explicit CardTable(QWidget* parent = nullptr);
    private:
        CardPics m_deck;
    };

#endif  /* CARD_TABLE_H */
