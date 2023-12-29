
#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "Player.h"

class Computer_Player : public Player{
public:
	explicit Computer_Player(int initial_balance, const std::string& name) :
			Computer_Player::Player(initial_balance, name){};
	bool offer(const std::string& offer, bool bypass_to_false) const override;

private:
};


#endif //COMPUTER_PLAYER_H
