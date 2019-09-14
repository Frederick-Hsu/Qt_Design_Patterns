#include "PuzzleWindow.h"
#include "PuzzleView.h"
#include "PuzzleModel.h"

PuzzleWindow::PuzzleWindow(QWidget* parent) : QMainWindow(parent)
{
#if 1
    PuzzleView* view = new PuzzleView(new PuzzleModel(parent));
    view->show();
#else
    PuzzleView view(new PuzzleModel(parent));
    view.show();
#endif
}
