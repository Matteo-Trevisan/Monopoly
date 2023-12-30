
#ifndef BANK_H
#define BANK_H

#include "Player.h"

class Bank : public Player{
public:
	explicit Bank(int initialBalance = 100000, const std::string &name = "Banca");

};


#endif //BANK_H
