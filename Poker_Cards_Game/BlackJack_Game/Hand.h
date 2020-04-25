#ifndef HAND_H
#define HAND_H

    class QString;
    class Card;

    class Hand
    {
    public:
        Hand(QString name);
    public:
        Hand& operator<<(Card* card);
    protected:
        void handChanged();
    };

#endif  /* HAND_H */
