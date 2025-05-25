#ifndef FILEMANAGERFORREGISTRATION_H
#define FILEMANAGERFORREGISTRATION_H
#include <QString>

class FileManagerForRegistration {
   public:
    FileManagerForRegistration();

    void CreateFile(QString folder, QString name_of_file);
    int ReadFirstLine(QString folder_path, QString name_of_file);
    void WriteStation(QString folder, QString name_of_file,
                      QString password = "");
    QString ReadSecondLine(QString folder, QString name_of_file);
};

#endif	// FILEMANAGERFORREGISTRATION_H
