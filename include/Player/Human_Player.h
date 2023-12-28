
#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"

class Human_Player : public Player{
public:
	explicit Human_Player(int initial_balance, const std::string& name) :
	Human_Player::Player(initial_balance, name){};
	bool offer(const std::string& offer) const override;

private:
};


#endif //HUMAN_PLAYER_H
