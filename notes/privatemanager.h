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
    bool isOpenPrivate = false;

   private:
    QString key;
    QString encryptAES(const QString& plaintext);
    QString decryptAES(const QString& ciphertext);


   protected:
    void Initialization() override;
    void CreateFile(int number, int type, QString folder) override;
};

#endif	// PRIVATEMANAGER_H
