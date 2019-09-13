#ifndef PUZZLE_VIEW_H
#define PUZZLE_VIEW_H

    #include <QWidget>
    #include <QButtonGroup>

    class PuzzleModel;
    class QGridLayout;

    class PuzzleView : public QWidget
    {
        Q_OBJECT
    public:
        PuzzleView(PuzzleModel* model);
    private:
        PuzzleModel* m_Model;
        QGridLayout* m_Layout;
        QButtonGroup m_Buttons;
    public:
        void refresh();
        void tryToSlide(QAbstractButton* button);
    private slots:
        void shuffle();
    };


#endif  /* PUZZLE_VIEW_H */
