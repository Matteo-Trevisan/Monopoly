
#include "Game_manager/Game_Manager.h"
#include <algorithm>
#include <random>

Game_Manager::Game_Manager(Player_Type p, Config config) {
	players.reserve(4);
	if (p) {
		players.emplace_back(new Human_Player(config.initial_balance, "1"));
	} else {
		players.emplace_back(new Computer_Player(config.initial_balance, "1"));
	}

	for (int i = 0; i < 3; ++i) {
		players.emplace_back(new Computer_Player(config.initial_balance, std::to_string(i+2)));
	}
	gameboard = Gameboard(config, &players);
}

void Game_Manager::start() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> rand_dice(1, 6);

	for (auto& p : players) {
		p->set_initial_dice_roll(rand_dice(gen) + rand_dice(gen));
	}

	std::sort(players.begin(), players.end(), compareByDiceRoll);
}

const Gameboard& Game_Manager::get_gameboard() const {
	return gameboard;
}

bool compareByDiceRoll(const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
	return a->get_initial_dice_roll() < b->get_initial_dice_roll();
}

