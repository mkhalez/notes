#ifndef FILEMANAGERFORNOTE_H
#define FILEMANAGERFORNOTE_H
#include <QString>

class FileManagerForNote {
   public:
    FileManagerForNote();

    QString ReadFile(const QString& folderPath, const QString& fileName);
    void SaveFile(const QString& folderPath, const QString& fileName,
                  const QString& newText);
    void SaveTitle(const QString& folderPath, const QString& fileName,
                   QString nameOfTitle);
    void SaveFileForToDoList(const QString& folderPath, const QString& fileName,
                             const QStringList& lines);
    QStringList ReadFileForToDoList(const QString& folderPath,
                                    const QString& fileName);
};

#endif	// FILEMANAGERFORNOTE_H
