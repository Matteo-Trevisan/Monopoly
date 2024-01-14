//
//	AUTORE: Elia Tolfo
//

#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "Player.h"
#include <vector>
#include <string>

class Computer_Player : public Player{
public:
	explicit Computer_Player(int initial_balance, const std::string& name) :
			Computer_Player::Player(initial_balance, name){};
	~Computer_Player() override;
	int offer(const std::string& offer) const override;

private:
};


#endif //COMPUTER_PLAYER_H
