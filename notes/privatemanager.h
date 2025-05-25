#ifndef PRIVATEMANAGER_H
#define PRIVATEMANAGER_H
#include "manager.h"

class PrivateManager : Manager {
   public:
    PrivateManager();

   protected:
    void Initialization() override;
};

#endif	// PRIVATEMANAGER_H
