
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <vector>
#include "Player/Player.h"
// #include "Gameboard/Gameboard.h" TODO remove comment

enum Player_Type {
	Computer, Human
};

class Game_Manager {
public:
	Game_Manager(Player_Type p, int initial_balance);
	void start();

private:
	// Gameboard gameboard; TODO
	std::vector<Player> players;


};


#endif //GAME_MANAGER_H
