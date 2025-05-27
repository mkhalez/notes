#include "privatemanager.h"
#include <QDir>

PrivateManager::PrivateManager() : Manager(false) {
    Initialization();
}

void PrivateManager::SetKey(QString key) {
    this->key = key;
}

QString PrivateManager::Encrypt(QString text) {
    QString result;
    for (int i = 0; i < text.length(); ++i) {
        QChar ch = text.at(i);
        QChar keyCh = key.at(i % key.length());
        result.append(QChar(ch.unicode() ^ keyCh.unicode()));
    }
    return result;
}

QString PrivateManager::Decrypt(QString text) {
    return Encrypt(text);
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
