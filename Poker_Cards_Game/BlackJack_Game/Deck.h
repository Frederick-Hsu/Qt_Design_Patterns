#ifndef DECK_H
#define DECK_H

    class Card;
    class QString;

    class Deck
    {
    public:
        Deck();
    public:
        void shuffle(void);
        void reset(void);
        Card* pick();
        QString toString();
    protected:
        void cardsLeft(int num);
    };

#endif  /* DECK_H */
