
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <vector>
#include "Player/Player.h"
#include "Gameboard/Gameboard.h"

enum Player_Type {
	Computer, Human
};

class Game_Manager {
public:
	explicit Game_Manager(Player_Type p, Config config);
	void start();
	const Gameboard& get_gameboard() const;

private:
	Gameboard gameboard;
	std::vector<Player> players;


};


#endif //GAME_MANAGER_H
