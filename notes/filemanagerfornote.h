#ifndef FILEMANAGERFORNOTE_H
#define FILEMANAGERFORNOTE_H
#include <QString>

class FileManagerForNote {
   public:
    FileManagerForNote();

    virtual QString ReadFile(const QString& folderPath,
                             const QString& fileName);
    virtual void SaveFile(const QString& folderPath, const QString& fileName,
                          const QString& newText);
    virtual void SaveTitle(const QString& folderPath, const QString& fileName,
                           QString nameOfTitle);
    virtual void SaveFileForToDoList(const QString& folderPath,
                                     const QString& fileName,
                                     const QStringList& lines);
    virtual QStringList ReadFileForToDoList(const QString& folderPath,
                                            const QString& fileName);
};

#endif	// FILEMANAGERFORNOTE_H
