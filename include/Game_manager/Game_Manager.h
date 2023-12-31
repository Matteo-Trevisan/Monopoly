
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <vector>
#include <random>
#include "Player/Human_Player.h"
#include "Player/Computer_Player.h"
#include "Player/Bank.h"
#include "Gameboard/Gameboard.h"
#include "OstreamFork.h"


enum Player_Type {
	Computer, Human
};

class Game_Manager {
public:
	explicit Game_Manager(Player_Type p, Config config, const std::string& filename);
	void setup();
	void run_game();

	const Gameboard& get_gameboard() const;

private:
	OstreamFork osf;
	std::ofstream log_file;

	Player_Type fisrt_player_type;
	Gameboard gameboard;
	std::vector<std::unique_ptr<Player>> players;
	Bank bank;

	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<> rand_dice;

};

// comparison function object per riordinare i giocatori in base al valore del tiro dei dadi
bool greaterRoll(const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b);

std::string print_simple_line(int length = 51);
std::string player_vector_to_string(const std::vector<Player*>& vec);

#endif //GAME_MANAGER_H
