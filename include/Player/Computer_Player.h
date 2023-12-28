
#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "Player.h"

class Computer_Player : public Player{
public:
	bool offer(std::string offer) const override;

private:
};


#endif //COMPUTER_PLAYER_H
