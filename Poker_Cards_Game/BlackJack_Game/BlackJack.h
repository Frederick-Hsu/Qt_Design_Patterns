#ifndef BLACK_JACK_H
#define BLACK_JACK_H

    #include <QMainWindow>

    class HandView;

    class BlackJack : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit BlackJack(QWidget* parent = nullptr);
    private:
        HandView* dealer;
        HandView* player;
    public:
        void loadSettings(void);
        void closeEvent(QCloseEvent* event);
        void deal(void);
        void actionEvent(QAction* act);
    };

#endif  /* BLACK_JACK_H */
