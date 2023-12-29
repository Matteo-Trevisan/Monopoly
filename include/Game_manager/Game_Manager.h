
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <vector>
#include <random>
#include "Player/Human_Player.h"
#include "Player/Computer_Player.h"
#include "Gameboard/Gameboard.h"

enum Player_Type {
	Computer, Human
};

class Game_Manager {
public:
	explicit Game_Manager(Player_Type p, Config config);
	void setup();
	void run_game();
	const Gameboard& get_gameboard() const;

private:
	Gameboard gameboard;
	std::vector<std::unique_ptr<Player>> players;
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<> rand_dice;
};

// comparison function object per riordinare i giocatori in base al valore del tiro dei dadi
bool greaterRoll(const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b);

std::string draw_simple_line(int length);

#endif //GAME_MANAGER_H
