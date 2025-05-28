#ifndef PRIVATEMANAGER_H
#define PRIVATEMANAGER_H
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <QByteArray>
#include <QString>
#include "manager.h"

class PrivateManager : public Manager {
   public:
    PrivateManager();
    void SetKey(QString key);
    QString GetKy();
    bool isOpenPrivate = false;
    QString NameForTitle(const QString& folderPath,
                         const QString& fileName) override;

   private:
    QString key;
    QString encryptAES(const QString& plaintext);
    QString decryptAES(const QString& ciphertext);
    void CreateFile(int number, int type, QString folder) override;


   protected:
    void Initialization() override;
};

#endif	// PRIVATEMANAGER_H
