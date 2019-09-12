#ifndef CARD_TABLE_H
#define CARD_TABLE_H

    #include "cards2d_global.h"
    #include "CardPics.h"
    #include <QWidget>

    class CARDS2DSHARED_EXPORT CardTable : public QWidget
    {
    public:
        explicit CardTable(QWidget* parent = nullptr);
    private:
        CardPics m_deck;
    };

#endif  /* CARD_TABLE_H */
