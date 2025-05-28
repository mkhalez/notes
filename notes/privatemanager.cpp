#include "privatemanager.h"
#include <QDir>

PrivateManager::PrivateManager() : Manager(false) {
    Initialization();
}

void PrivateManager::SetKey(QString key) {
    this->key = key;
}

QString PrivateManager::encryptAES(const QString& plaintext) {
    // Конвертируем входные данные в бинарный формат
    QByteArray plainBytes = plaintext.toUtf8();
    QByteArray passBytes = key.toUtf8();

    // Генерация соли (8 случайных байт)
    QByteArray salt(8, 0);
    if (RAND_bytes((unsigned char*)salt.data(), salt.size()) <= 0) {
        qCritical() << "Salt generation error";
        return "";
    }

    // Генерация ключа и IV
    const EVP_CIPHER* cipher = EVP_aes_256_cbc();
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];

    if (EVP_BytesToKey(cipher, EVP_sha256(), (const unsigned char*)salt.data(),
                       (const unsigned char*)passBytes.data(), passBytes.size(),
                       10000, key, iv) <= 0) {
        qCritical() << "Key derivation failed";
        return "";
    }

    // Шифрование
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

    // Комбинируем соль + шифротекст
    QByteArray result = salt + ciphertext;

    // Конвертируем в Base64 строку
    return QString::fromLatin1(result.toBase64());
}

QString PrivateManager::decryptAES(const QString& ciphertext) {
    // Декодируем из Base64
    QByteArray encryptedData = QByteArray::fromBase64(ciphertext.toLatin1());
    if (encryptedData.size() <= 8) {
        qCritical() << "Invalid ciphertext";
        return "";
    }

    // Извлекаем соль и данные
    QByteArray salt = encryptedData.left(8);
    QByteArray data = encryptedData.mid(8);
    QByteArray passBytes = key.toUtf8();

    // Генерация ключа и IV
    const EVP_CIPHER* cipher = EVP_aes_256_cbc();
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];

    if (EVP_BytesToKey(cipher, EVP_sha256(), (const unsigned char*)salt.data(),
                       (const unsigned char*)passBytes.data(), passBytes.size(),
                       10000, key, iv) <= 0) {
        qCritical() << "Key derivation failed";
        return "";
    }

    // Дешифрование
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

    // Проверка успешности дешифрования
    if (final_result <= 0) {
        qCritical() << "Decryption failed. Wrong password?";
        return "";
    }

    // Конвертируем байты обратно в строку
    return QString::fromUtf8(plaintext);
}

void PrivateManager::Initialization() {
    QString folder_path = "data_of_user/private_data";

    QDir dir(folder_path);

    if (!dir.exists()) {
        dir.mkpath(".");
    }

    list_of_user_files = GetListOfFileByCreationTime(folder_path);
    if (list_of_user_files.isEmpty()) {
        number_of_item = 0;
    } else {
        QString last_name = list_of_user_files[list_of_user_files.length() - 1];
        last_name.chop(8);
        number_of_item = last_name.toInt();
    }
}

void PrivateManager::CreateFile(int number, int type, QString folder) {
    QDir dir("data_of_user/private_data");	// Всегда используем приватный путь

    QString filePath = dir.filePath(QString::number(number) + "data.txt");

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << QString::number(type);
        file.close();
    }
}
