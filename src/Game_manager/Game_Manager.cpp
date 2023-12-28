
#include "Game_manager/Game_Manager.h"
#include <algorithm>
#include <random>

Game_Manager::Game_Manager(Player_Type p, Config config) {
	players.reserve(4);
	players.emplace_back(config.initial_balance, p, "Giocatore 1");
	for (int i = 0; i < 3; ++i) {
		players.emplace_back(config.initial_balance, 0, "Giocatore " + std::to_string(i));
	}
	gameboard = Gameboard(config, &players);
}

void Game_Manager::start() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> rand_dice(1, 6);

	for (Player p : players) {
		p.set_initial_dice_roll(rand_dice(gen) + rand_dice(gen));
	}

	std::sort(players.begin(), players.end(), compareByDiceRoll);
}

const Gameboard& Game_Manager::get_gameboard() const {
	return gameboard;
}

