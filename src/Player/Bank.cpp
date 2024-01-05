
#include "Player/Bank.h"

Bank::Bank(int initialBalance, const std::string &name)
	: Player(initialBalance, name) {

}

Bank::~Bank() = default;
