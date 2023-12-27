
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Position.h"

class Player {
public:
	explicit Player(int initial_balance) : balance(initial_balance), pos(Position{7,7}) {};
	bool isPlaying();
	bool has_enought_balance(int value);
	bool pay(int value);
	bool pay(Player& ricevente, int value);
	void set_position(Position&& p);

private:
	int balance;
	Position pos;
};


#endif //PLAYER_H
