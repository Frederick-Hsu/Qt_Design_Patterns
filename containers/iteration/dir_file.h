#ifndef DIR_FILE_H
#define DIR_FILE_H

    class QDir;

    void recursiveAccessDir(QDir dir, bool recursive = true, bool symlinks = false);
    int iterativeAccessDir(QDir dir);

#endif  /* DIR_FILE_H */
