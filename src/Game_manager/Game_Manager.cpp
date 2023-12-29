
#include "Game_manager/Game_Manager.h"
#include <algorithm>
#include "unistd.h"

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

void Game_Manager::setup() {

	std::cout << RED << std::setw(25) << "MONOPOLY" << RESET << std::endl << draw_simple_line(40)
	<< std::endl << BLUE <<  "Sorteggi per ordnie turni: " << RESET << std::endl;

	for (auto& p : players) {
		p->roll_dices(rand_dice, gen);
		std::cout << "Giocatore " + p->get_name() + " ha tirato i dadi ottenendo un valore di " << p->get_dice_roll() << std::endl;
		// sleep(1);	//TODO remove comments
	}

	std::sort(players.begin(), players.end(), greaterRoll);

	std::cout << std::endl;

	for (int i = 0; i < players.size(); ++i) {

		int j = i + 1;
		int equal_rolls = 0;
		while (j < players.size() && players.at(i)->get_dice_roll() == players.at(j)->get_dice_roll()) {
			std::cout << "Giocatore " + players.at(i)->get_name() + " ha ottenuto lo stesso valore di Giocatore " << players.at(j)->get_name() << std::endl;
			++equal_rolls;
			++j;
		}

		if (equal_rolls == 0) {
			continue;
		}

		for (j = i; j <= i + equal_rolls; ++j) {
			players.at(j)->roll_dices(rand_dice, gen);
			std::cout << "Giocatore " + players.at(j)->get_name() + " ha ritirato i dadi ottenendo un valore di " << players.at(j)->get_dice_roll() << std::endl;
			// sleep(1); TODO remove comments
		}

		std::sort(players.begin(), players.end(), greaterRoll);
		std::cout << std::endl;

		--i;
	}

	std::cout << BLUE << "Ordine finale:" << RESET << std::endl;
	for (auto& p : players) {
		std::cout << "Giocatore " + p->get_name() << " ";
	}
	std::cout << std::endl << draw_simple_line(40) << std::endl;
}

const Gameboard& Game_Manager::get_gameboard() const {
	return gameboard;
}

void Game_Manager::run_game() {
	int i = -1;
	while(true) {
		//	Controllo fine partita
		int giocatori_in_gioco = 0;
		for (const auto & player : players) {
			if (player->isPlaying()) ++giocatori_in_gioco;
		}
		if (giocatori_in_gioco == 1) {
			return;
		}

		// selezionare prossimo gicatore
		++i;
		if (i >=4 ) i = 0;



		auto& current_player = *players.at(i);
		int dices = rand_dice(gen) + rand_dice(gen);
		std::cout << "Giocatore " + current_player.get_name() + " ha tirato i dadi ottenendo un valore di " << dices << std::endl;
		current_player.set_position((current_player.get_position() + dices) % 28);
		Space& final_space = *gameboard.get_space_at(current_player.get_position());
		std::cout << "Giocatore " + current_player.get_name() + " è arrivato alla casella " << final_space.get_name() << std::endl;

		if (final_space.get_owner() == nullptr) {	// TODO così non va bene: anche le caselle angolari restituiscono nullptr
			bool offer = current_player.offer("Giocatore " + current_player.get_name() + ", vuoi acquistare la proprietà " + final_space.get_name() + "?");
			if (offer) {
				current_player.pay(final_space.get_terrain_sale_price());
				final_space.set_owner(&current_player);
				//current_player.add_property();	TODO revove comments after implementing the function
			}
		} else {
			current_player.pay(*final_space.get_owner(), final_space.get_overnight_stay_price());
		}

		std::cout << gameboard << std::endl;

		//sleep(1);

	}
}

std::string draw_simple_line(int length) {
	return std::string(length, '-');
}

bool greaterRoll(const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
	return a->get_dice_roll() > b->get_dice_roll();
}

