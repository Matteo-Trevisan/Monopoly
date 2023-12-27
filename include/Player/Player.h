
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Space/Space.h"
#include "Position.h"

class Player {
public:
	bool isPlaying();
	bool pay(int value);
	bool pay(Player ricevente, int value);
	void clear();

private:
	int balance;
	std::vector<Space> properties;
	Position pos;
};


#endif //PLAYER_H
