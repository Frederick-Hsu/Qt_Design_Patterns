#include "UndoMainWnd.h"
#include "ui_UndoMainWnd.h"

#include <QImage>
#include <QFileDialog>
#include <QApplication>

UndoMainWnd::UndoMainWnd(QWidget* parent) : QMainWindow(parent),
                                            m_ImageDisplay(new QLabel(this)),
                                            m_Image(QImage()),
                                            ui(new Ui::UndoMainWnd)
{
    ui->setupUi(this);
    m_ImageDisplay->setMinimumSize(640, 480);
}

UndoMainWnd::~UndoMainWnd()
{
    delete ui;
}

void UndoMainWnd::displayImage(const QImage& img)
{
    m_ImageDisplay->setPixmap(QPixmap::fromImage(img));
}

void UndoMainWnd::on_actionOpen_triggered()
{
    m_Image.load(QFileDialog::getOpenFileName());
    displayImage(m_Image);
}

void UndoMainWnd::on_actionClose_triggered()
{
    m_ImageDisplay->clear();
    m_Image.allGray();
}

void UndoMainWnd::on_actionSave_triggered()
{
    on_saveButton_clicked();
}

void UndoMainWnd::on_actionQuit_triggered()
{
    on_quitButton_clicked();
}

void UndoMainWnd::on_actionHorizontal_Mirror_triggered()
{
    on_horizontalMirrorButton_clicked();
}

void UndoMainWnd::on_actionVertical_Mirror_triggered()
{
    on_verticalMirrorButton_clicked();
}

void UndoMainWnd::on_actionUndo_The_Last_Action_triggered()
{
    on_undoButton_clicked();
}

void UndoMainWnd::on_actionAdjust_Color_triggered()
{
    ui->redSpin->setFocus();
}

void UndoMainWnd::on_openButton_clicked()
{
    on_actionOpen_triggered();
}

void UndoMainWnd::on_saveButton_clicked()
{
    QString filename(QFileDialog::getSaveFileName());
    m_Image.save(filename);
}

void UndoMainWnd::on_quitButton_clicked()
{
    QApplication::quit();
}

void UndoMainWnd::on_undoButton_clicked()
{
    m_Stack.undo();
    displayImage(m_Image);
}

void UndoMainWnd::on_redoButton_clicked()
{
    m_Stack.redo();
    displayImage(m_Image);
}

void UndoMainWnd::on_verticalMirrorButton_clicked()
{

}
