#include "crypto.h"
#include <QDebug>

Crypto::Crypto() {}

QString Crypto::GetKey() {
    return key;
}

void Crypto::SetKey(QString key) {
    this->key = key;
}

QString Crypto::encryptAES(const QString& plaintext) {
    if (plaintext.length() == 0)
        return "";
    QByteArray plainBytes = plaintext.toUtf8();
    QByteArray passBytes = key.toUtf8();

    QByteArray salt(8, 0);
    if (RAND_bytes((unsigned char*)salt.data(), salt.size()) <= 0) {
        qCritical() << "Salt generation error";
        return "";
    }

    const EVP_CIPHER* cipher = EVP_aes_256_cbc();
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];

    if (EVP_BytesToKey(cipher, EVP_sha256(), (const unsigned char*)salt.data(),
                       (const unsigned char*)passBytes.data(), passBytes.size(),
                       10000, key, iv) <= 0) {
        qCritical() << "Key derivation failed";
        return "";
    }

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, cipher, nullptr, key, iv);

    QByteArray ciphertext;
    int block_size = EVP_CIPHER_CTX_block_size(ctx);
    ciphertext.resize(plainBytes.size() + block_size);

    int len1 = 0, len2 = 0;
    EVP_EncryptUpdate(ctx, (unsigned char*)ciphertext.data(), &len1,
                      (const unsigned char*)plainBytes.data(),
                      plainBytes.size());
    EVP_EncryptFinal_ex(ctx, (unsigned char*)ciphertext.data() + len1, &len2);
    ciphertext.resize(len1 + len2);
    EVP_CIPHER_CTX_free(ctx);

    QByteArray result = salt + ciphertext;

    return QString::fromLatin1(result.toBase64());
}

QString Crypto::decryptAES(const QString& ciphertext) {
    if (ciphertext == "")
        return "";
    QByteArray encryptedData = QByteArray::fromBase64(ciphertext.toLatin1());
    if (encryptedData.size() <= 8) {
        qCritical() << "Invalid ciphertext";
        return "";
    }

    QByteArray salt = encryptedData.left(8);
    QByteArray data = encryptedData.mid(8);
    QByteArray passBytes = key.toUtf8();

    const EVP_CIPHER* cipher = EVP_aes_256_cbc();
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];

    if (EVP_BytesToKey(cipher, EVP_sha256(), (const unsigned char*)salt.data(),
                       (const unsigned char*)passBytes.data(), passBytes.size(),
                       10000, key, iv) <= 0) {
        qCritical() << "Key derivation failed";
        return "";
    }

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, cipher, nullptr, key, iv);

    QByteArray plaintext;
    int block_size = EVP_CIPHER_CTX_block_size(ctx);
    plaintext.resize(data.size() + block_size);

    int len1 = 0, len2 = 0;
    EVP_DecryptUpdate(ctx, (unsigned char*)plaintext.data(), &len1,
                      (const unsigned char*)data.data(), data.size());
    int final_result = EVP_DecryptFinal_ex(
        ctx, (unsigned char*)plaintext.data() + len1, &len2);
    plaintext.resize(len1 + len2);
    EVP_CIPHER_CTX_free(ctx);
    if (final_result <= 0) {
        qCritical() << "Decryption failed. Wrong password?";
        return "";
    }

    return QString::fromUtf8(plaintext);
}
