
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <vector>
#include "Player/Human_Player.h"
#include "Player/Computer_Player.h"
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
	std::vector<std::unique_ptr<Player>> players;

};

// comparison function object per riordinare i giocatori in base al valore del tiro dei dadi
bool compareByDiceRoll(const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b);

#endif //GAME_MANAGER_H
