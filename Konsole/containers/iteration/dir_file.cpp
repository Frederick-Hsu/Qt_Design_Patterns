#include "dir_file.h"
#include <QDir>
#include <QStringList>
#include <QString>
#include <QFileInfo>
#include <QTextStream>
#include <QDirIterator>

QTextStream qout(stdout);
QTextStream qin(stdin);
QTextStream qerr(stdout);

static void addMp3File(QString path)
{
    qout << path << endl;
}

static void usage()
{
    qout << "Usage : diriterator [path]" << endl;
    qout << "        prints out a list of mp3 files it can find below [path] or current directory." << endl;
}

void recursiveAccessDir(QDir dir, bool recursive, bool symlinks)
{
    dir.setSorting(QDir::Name);
    QDir::Filters filters = QDir::Files | QDir::NoDotAndDotDot;
    if (recursive)
    {
        filters |= QDir::Dirs;
    }
    if (not symlinks)
    {
        filters |= QDir::NoSymLinks;
    }

    QStringList strList = dir.entryList(filters, QDir::Name | QDir::DirsFirst);
    foreach (const QString& entry, strList)
    {
        QFileInfo finfo(dir, entry);
        if (finfo.isDir())
        {
            QDir subdir(finfo.absoluteFilePath());
            recursiveAccessDir(subdir);
        }
        else
        {
            if (finfo.completeSuffix() == "mp3")
            {
                addMp3File(finfo.absoluteFilePath());
            }
        }
    }
}

int iterativeAccessDir(QDir dir)
{
    if (!dir.exists())
    {
        qerr << dir.path() << " does not exist." << endl;
        usage();
        return (-1);
    }
    QDirIterator dirItor(dir.absolutePath(),
                         QStringList() << "*.mp3",
                         QDir::NoSymLinks | QDir::Files,
                         QDirIterator::Subdirectories);
    while (dirItor.hasNext())
    {
        addMp3File(dirItor.next());
    }
    return 0;
}
