#ifndef PUZZLE_WINDOW_H
#define PUZZLE_WINDOW_H

    #include <QWidget>
    #include <QMainWindow>

    class PuzzleWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        PuzzleWindow(QWidget* parent = nullptr);
    };


#endif  /* PUZZLE_WINDOW_H */
