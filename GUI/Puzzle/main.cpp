#include <QApplication>
#include "PuzzleWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PuzzleWindow puzzle;
    puzzle.show();

    return a.exec();
}
