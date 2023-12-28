
#include "Game_manager/Game_Manager.h"
#include <algorithm>

Game_Manager::Game_Manager(Player_Type p, Config config) : gen(rd()){
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
	rand_dice = std::uniform_int_distribution<>(1, 6);
}

void Game_Manager::start() {
	for (auto& p : players) {
		p->set_initial_dice_roll(rand_dice(gen) + rand_dice(gen));
	}

	std::sort(players.begin(), players.end(), compareByDiceRoll);
}

const Gameboard& Game_Manager::get_gameboard() const {
	return gameboard;
}

void Game_Manager::run_game() {
	for (int i = 0; i < players.size() && players.at(i)->isPlaying(); ++i) {
		auto& pl = *players.at(i);
		int dices = rand_dice(gen) + rand_dice(gen);
		std::cout << "Giocatore " + pl.get_name() + " ha tirato i dadi ottenendo un valore di " << dices << std::endl;
		pl.set_position((pl.get_position() + dices) % 28);
		Space& final_space = *gameboard.get_space_at(pl.get_position());
		std::cout << "Giocatore " + pl.get_name() +" è arrivato alla casella " << final_space.get_name();

	}
}

bool compareByDiceRoll(const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
	return a->get_initial_dice_roll() < b->get_initial_dice_roll();
}

