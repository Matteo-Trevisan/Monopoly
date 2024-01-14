//
//	AUTORE: Elia Tolfo
//

#include "Player/Bank.h"
#include <string>

// costruttore della classe Banck
Bank::Bank(int initialBalance, const std::string &name)
	: Player(initialBalance, name) {

}

// distruttore della classe Bank impostato di default
Bank::~Bank() = default;
