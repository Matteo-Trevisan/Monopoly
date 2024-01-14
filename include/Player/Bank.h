//
//	AUTORE: Elia Tolfo
//

#ifndef BANK_H
#define BANK_H

#include "Player.h"
#include <string>

class Bank : public Player{
public:
	explicit Bank(int initialBalance = 100000, const std::string &name = "Banca");
	~Bank() override;
};


#endif //BANK_H
