
#ifndef BANK_H
#define BANK_H

#include "Player.h"

class Bank : public Player{

public:
	Bank(int initialBalance, const std::string &name);
};


#endif //BANK_H
