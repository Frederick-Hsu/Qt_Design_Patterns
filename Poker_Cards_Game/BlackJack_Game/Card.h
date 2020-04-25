#ifndef CARD_H
#define CARD_H

    #include <QWidget>
    #include <QLabel>

    class Card : public QWidget
    {
        Q_OBJECT
    public:
        Card(QString name);
    private:
        QLabel* m_label;
        QString m_name;
    public:
        QString& name() const;
        QLabel* lable();
        int value();
        bool isAce();
    };

#endif  /* CARD_H */
