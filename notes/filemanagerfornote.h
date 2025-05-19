#ifndef FILEMANAGERFORNOTE_H
#define FILEMANAGERFORNOTE_H
#include <QString>

class FileManagerForNote {
   public:
    FileManagerForNote();

    QString ReadFile(const QString& folderPath, const QString& fileName);
    void SaveFile(const QString& folderPath, const QString& fileName,
                  const QString& newText);
    QString NameForTitle(const QString& folderPath, const QString& fileName);
    void SaveTitle(const QString& folderPath, const QString& fileName,
                   QString nameOfTitle);
};

#endif	// FILEMANAGERFORNOTE_H
