#ifndef PRIVATEFILEMANAGERFORNOTE_H
#define PRIVATEFILEMANAGERFORNOTE_H
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <QByteArray>
#include <QString>
#include "crypto.h"
#include "filemanagerfornote.h"


class PrivateFileManagerForNote : public FileManagerForNote {
   public:
    PrivateFileManagerForNote(Crypto* crypto);
    QString ReadFile(const QString& folderPath,
                     const QString& fileName) override;
    void SaveFile(const QString& folderPath, const QString& fileName,
                  const QString& newText) override;
    void SaveTitle(const QString& folderPath, const QString& fileName,
                   QString nameOfTitle) override;
    void SaveFileForToDoList(const QString& folderPath, const QString& fileName,
                             const QStringList& lines) override;
    QStringList ReadFileForToDoList(const QString& folderPath,
                                    const QString& fileName) override;

    void SetKey(QString Key);


   private:
    Crypto* crypto;
};

#endif	// PRIVATEFILEMANAGERFORNOTE_H
