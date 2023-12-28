
#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"

class Human_Player : public Player{
public:
	bool offer(std::string offer) const override;

private:
};


#endif //HUMAN_PLAYER_H
