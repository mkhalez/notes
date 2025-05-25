#ifndef PRIVATEMANAGER_H
#define PRIVATEMANAGER_H
#include "manager.h"

class PrivateManager : Manager {
   public:
    PrivateManager();
    void SetKey(QString key);
    bool isOpenPrivate = false;

   private:
    QString key;

   protected:
    void Initialization() override;
};

#endif	// PRIVATEMANAGER_H
