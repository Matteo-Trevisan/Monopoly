
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Position.h"

class Player {
public:
	explicit Player(int initial_balance, bool human) : balance(initial_balance), pos(Position{7,7}), human(human) {};
	bool isPlaying();
	bool has_enough_money(int value);
	bool pay(int value);
	bool pay(Player& receiver, int value);
	void set_position(Position&& p);
	bool is_human() const;
	void add_property();

private:
	int balance;
	Position pos;
	std::vector<Position> properties;
	bool human;
};


#endif //PLAYER_H
