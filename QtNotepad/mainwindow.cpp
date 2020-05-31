#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QSharedPointer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Untitled.txt --- Qt Notepad");
    QObject::connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFileSlot()));
    QObject::connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFileSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFileSlot()
{
    if (ui->mainTextEdit->document()->isModified())
    {
        qDebug() << "Current file is modified.";
    }
    else
    {
        qDebug() << "No change";
        ui->mainTextEdit->clear();
        this->setWindowTitle("Untitled.txt");

    }
}

void MainWindow::openFileSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open file", QDir::currentPath());
    // qDebug() << "Current file: " << fileName;
    if (fileName.isEmpty())
    {
        QMessageBox::information(this, "Error message", "Please select a text file.");
        return;
    }
#if 0
    QFile *file = new QFile(fileName);
    bool ok = file->open(QIODevice::ReadOnly);
    if (ok)
    {
        setWindowTitle(fileName);
        QTextStream in(file);
        ui->mainTextEdit->setText(in.readAll());
        file->close();
        delete file;
    }
    else
    {
        QMessageBox::information(this, "Error message", "File open failed: " + file->errorString());
        file->close();
        delete file;
    }
#else
    QSharedPointer<QFile> fileptr(new QFile(fileName));
    bool ok = fileptr->open(QIODevice::ReadOnly);
    if (ok)
    {
        this->setWindowTitle(fileName);
        QTextStream in(fileptr.get());
        ui->mainTextEdit->setText(in.readAll());
        fileptr->close();
    }
    else
    {
        QMessageBox::information(this, "Error message", "File open failed: " + fileptr->errorString());
        fileptr->close();
    }
#endif
}
