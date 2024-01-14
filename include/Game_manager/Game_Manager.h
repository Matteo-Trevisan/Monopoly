//
//	AUTORE: Matteo Trevisan
//

#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <vector>
#include <random>
#include "Player/Human_Player.h"
#include "Player/Computer_Player.h"
#include "Player/Bank.h"
#include "Gameboard/Gameboard.h"
#include "OstreamFork.h"

// Enum usato nel costruttore come parametro per identificare il tipo del primo giocatore
enum Player_Type {
	Computer, Human
};

class Game_Manager {
public:
	explicit Game_Manager(Player_Type p, Config config, const std::string& filename);
	void run_game();

private:
	OstreamFork osf;			// Oggetto per la gestione della scrittura su file
	std::ofstream log_file;		// Stram al file
	int max_turn;				// numero massimo di turni

	Gameboard gameboard;		// Oggetto Gameboard
	std::vector<std::unique_ptr<Player>> players;	// Vettore di players
	Bank bank;					// Banca

	std::random_device rd;		// Variabili per la gestione del random
	std::mt19937 gen;
	std::uniform_int_distribution<> rand_dice;

	void setup();
	void print_balance_winning();
	void print_player_info();
	void buy_space_manager(Player& current_player, Space& arrival_space);
	void upgrade_space_manager(Player& current_player, Space& arrival_space);
	void overnight_payment_manager(Player& current_player, Space& arrival_space);
	void print_player_turn_end(Player& current_player);
	bool are_all_dice_unique();
};

// comparison function object per riordinare i giocatori in base al valore del tiro dei dadi
bool greaterRoll(const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b);

std::string print_simple_line(int length = 51);
std::string player_vector_to_string(const std::vector<Player*>& vec);

#endif //GAME_MANAGER_H
