#ifndef HAND_VIEW_H
#define HAND_VIEW_H

    #include <QWidget>

    class Hand;

    class HandView : public QWidget
    {
        Q_OBJECT
    public:
        HandView(Hand* hand);
    private:
        Hand* m_hand;
    public:
        void setModel(Hand* hand);
        void rescanHand(void);
    };

#endif  /* HAND_VIEW_H */
