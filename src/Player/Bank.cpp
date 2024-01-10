
#include "Player/Bank.h"
#include <string>

Bank::Bank(int initialBalance, const std::string &name)
	: Player(initialBalance, name) {

}

Bank::~Bank() = default;
