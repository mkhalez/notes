#ifndef CRYPTO_H
#define CRYPTO_H
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <QByteArray>
#include <QString>


class Crypto {
   public:
    Crypto();
    QString GetKey();
    void SetKey(QString key);

    QString encryptAES(const QString& plaintext);
    QString decryptAES(const QString& ciphertext);

   private:
    QString key = "";
};

#endif	// CRYPTO_H
