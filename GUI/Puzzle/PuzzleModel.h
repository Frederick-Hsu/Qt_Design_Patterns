#ifndef PUZZLE_MODEL_H
#define PUZZLE_MODEL_H

    #include <QObject>
    #include <QList>

    class PuzzleModel : public QObject
    {
        Q_OBJECT
    public:
        PuzzleModel(QObject* parent = nullptr);
    private:
        QList<int> m_Positions;
        int m_Rows;
        int m_Cols;
    public:
        int value(int row, int col);
        bool slide(int tilenum);
        bool neighboring(int row, int col);
    private slots:
        void gridChanged();
    };


#endif  /* PUZZLE_MODEL_H */
