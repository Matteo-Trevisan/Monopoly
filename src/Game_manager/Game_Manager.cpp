
#include "Game_manager/Game_Manager.h"
#include <algorithm>
#include "unistd.h"		// For sleep function

Game_Manager::Game_Manager(Player_Type p, Config config) : fisrt_player_type(p), gen(rd()) {
	players.reserve(4);
	if (p) {
		players.emplace_back(new Human_Player(config.initial_balance, "1"));
	} else {
		players.emplace_back(new Computer_Player(config.initial_balance, "1"));
	}

	for (int i = 0; i < 3; ++i) {
		players.emplace_back(new Computer_Player(config.initial_balance, std::to_string(i+2)));
	}
	bank = Bank(config.initial_balance * 20, "Banca");
	gameboard = Gameboard(config, &players, &bank);
	rand_dice = std::uniform_int_distribution<>(1, 6);
}

void Game_Manager::setup() {


	std::cout << RED << std::setw(30) << "MONOPOLY" << RESET << std::endl << print_simple_line()
	<< std::endl << BLUE <<  "Sorteggi per ordine turni: " << RESET << std::endl;

	for (auto& p : players) {
		p->roll_dices(rand_dice, gen);
		std::cout << "Giocatore " + p->get_name() + " ha tirato i dadi ottenendo un valore di " << p->get_dice_roll() << std::endl;
		sleep(1);
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
			sleep(1);
		}

		std::sort(players.begin(), players.end(), greaterRoll);
		std::cout << std::endl;

		--i;
	}

	std::cout << BLUE << "Ordine finale:" << RESET << std::endl;
	for (auto& p : players) {
		std::cout << "Giocatore " + p->get_name() << " ";
	}
	std::cout << std::endl << print_simple_line() << std::endl;
}

const Gameboard& Game_Manager::get_gameboard() const {
	return gameboard;
}

void Game_Manager::run_game() {
	int player_index = -1;
	int turno = 1;
	while(true) {
		//	Controllo fine partita
		if (turno == 8 && fisrt_player_type == Player_Type::Computer) {
            int max_balance = 0;
            int winner_count = 0;
            for (const auto & player : players) {
                if (player->isPlaying()) {
                    if(player->get_balance() > max_balance)
                        max_balance = player->get_balance();
                }
            }
            for (const auto & player : players) {
                if (player->isPlaying())
                    if(player->get_balance() == max_balance) winner_count++;
            }

            if(winner_count > 1) {
                std::cout << "I vincitori sono ";
                print_player_vector(get_winner(max_balance));
            }
            else {
                std::cout << "Il vincitore è ";
                print_player_vector(get_winner(max_balance));
            }

			return;	// TODO da implemetare la vincita per numero di fiorini
		}
		int giocatori_in_gioco = 0;
		for (const auto & player : players) {
			if (player->isPlaying()) ++giocatori_in_gioco;
		}
		if (giocatori_in_gioco == 1) {
            for (const auto & player : players) {
                if (player->isPlaying())
                    std::cout << "Ha vinto Giocatore " << player->get_name();
            }
			return;		//TODO implemetare la vincita
		}

		// selezionare prossimo gicatore
		++player_index;
		if (player_index >= 4 ) player_index = 0;

		if (player_index == 0) {
			std::cout << std::endl << MAGENTA << print_simple_line() << std::endl << std::setw(30) << "Turno " << turno << std::endl <<  print_simple_line() << RESET << std::endl;
			++turno;
		}

		sleep(1);

		auto& current_player = *players.at(player_index);

		std::cout << "\n" << print_simple_line(19) << " Giocatore " << current_player.get_name() << " " <<  print_simple_line(19) << std::endl;
		std::cout << "Saldo: " << current_player.get_balance() << " fiorini;   Posizione: " << gameboard.get_space_at(current_player.get_position())->get_name() << ";   Proprietà: " << current_player.get_properties() << std::endl << std::endl;

		if (current_player.print_offer()) {
			// stampa tabellone
			std::cout << gameboard << std::endl << std::endl;

			// stampa lista proprietà per giocatore
			std::cout << "PROPRIETA'" << std::endl;
			for (const auto & p : players) {
				std::cout << "Giocatore " << p->get_name() << ": " << p->get_properties() << std::endl;
			}

			// stampa lista saldo per giocatore
			std::cout << std::endl << "SALDO" << std::endl;
			for (const auto & p : players) {
				std::cout << "Giocatore " << p->get_name() << ": " << p->get_balance() << " fiorini" << std::endl;
			}

			std::cout << "Press ENTER to continue...";
			std::cin.ignore();
			std::cin.get();
		}

		// Salva la posizione iniziale del giocatore (per controllare se passa per il via)
		int prev_pos = current_player.get_position();

		// Tira i dadi
		current_player.roll_dices(rand_dice, gen);
		std::cout << "Giocatore " + current_player.get_name() + " ha tirato i dadi ottenendo un valore di " << current_player.get_dice_roll() << std::endl;

		// Sposta il giocatore
		current_player.set_position((current_player.get_position() + current_player.get_dice_roll()) % 28);

		// Ottiene una reference alla casella di arrivo del giocatore + stampa posizione di arrivo
		Space& arrival_space = *gameboard.get_space_at(current_player.get_position());
		std::cout << "Giocatore " + current_player.get_name() + " è arrivato alla casella " << arrival_space.get_name() << " ";
		if (arrival_space.get_owner() != nullptr && arrival_space.get_owner() != &bank) {
			std::cout << "di proprietà del Giocatore" << arrival_space.get_owner()->get_name();
		}
		std::cout << std::endl;


		// Se il giocatore è passato dal via: ritira i soldi del passaggio
		if (current_player.get_position() < prev_pos){
			int start_pass_money_amount = gameboard.get_space_at(0)->get_start_pass_money();
			bank.pay(current_player, start_pass_money_amount);
			// TODO stampa che è passato dal via
			std::cout << "Giocatore " << current_player.get_name() << " è passato dal via e ha ritirato " << start_pass_money_amount << " fiorini" << std::endl;
		}

		// Se la casella non è di nessuno offre di comprarla
		if (arrival_space.get_owner() == nullptr) {		// TODO ti chiede se vuoi aquistarla anche se non hai abbastanza soldi: da cambiare
			if(arrival_space.get_terrain_sale_price() < current_player.get_balance()) {
                bool offer = current_player.offer(
                        "Giocatore " + current_player.get_name() + ", vuoi acquistare la proprietà " +
                        arrival_space.get_name() + " a " + std::to_string(arrival_space.get_terrain_sale_price()) +
                        " fiorini?");
                if (offer) {
                    current_player.pay(bank, arrival_space.get_terrain_sale_price());
                    arrival_space.set_owner(&current_player);
                    std::cout << "Acquistato proprietà" << std::endl; // TODO Stampare meglio
                    current_player.add_property(arrival_space.get_name());
                }
            }
			continue; // TODO questo continue va dentro o fuori dall'if subito sopra?
		}

		// Se la cella di arrivo è della banca (Angular_Space oppure Start_space)
		// non fare niente e continua
		if (arrival_space.get_owner() == &bank) {
			continue;
		}

		// Se la cella di arrivo è del giocatore offre di fare upgrade della cella
		// se le condizioni sono favorevoli (cella upgradable e abbastanza soldi)
		if (arrival_space.get_owner() == &current_player) {
			if (!arrival_space.upgradable()) {
				continue;
			}
			if (current_player.has_enough_money(arrival_space.get_next_upgrade_price())) {
				bool offer = current_player.offer("Vuoi migliorare la proprietà " + arrival_space.get_name() + ", costruendo una " + arrival_space.get_next_building_name() + ", al costo di " + std::to_string(arrival_space.get_next_upgrade_price()) + " fiorini?");
				if (offer) {
					current_player.pay(bank, arrival_space.get_terrain_sale_price());
					arrival_space.upgrade();
					std::cout << "Migliorato proprietà" << std::endl;
				} else {
					std::cout << "Rifiuta l'offerta" << std::endl;
					// TODO scrivere che rifiuta l'offerta
				}
			} else {
				std::cout << "Non ha abbastanza soldi" << std::endl;
				// TODO scrivere che non ha abbastanza soldi
				continue;
			}
		}

		// Se la cella non è del giocatore allora paga il pernottamento
		if (arrival_space.get_owner() != &current_player && !arrival_space.get_current_building_char().empty()) {
			if (current_player.pay(*arrival_space.get_owner(), arrival_space.get_overnight_stay_price())) {
				// TODO pagato
				std::cout << "Giocaotore " << current_player.get_name() << " paga Giocatore " << arrival_space.get_owner()->get_name() << " : " << arrival_space.get_overnight_stay_price() << " fiorini" << std::endl;
			} else {
				// TODO no abbastanza soldi => bancarotta
				std::cout << "Bancarotta: " << current_player.get_name() << std::endl;
				current_player.bankrupt();
				// Reset delle celle del giocatore
				for (auto& s : gameboard.get_space_deck()) {
					if (s->get_owner() == &current_player) {
						s->reset();
					}
				}
			}
		}

	}
}

std::vector<std::string> Game_Manager::get_winner(int value) {
    std::vector<std::string> winner;
    for (const auto & player : players) {
        if (player->isPlaying()) {
            if(player->get_balance() == value) {
                winner.push_back(player->get_name());
            }
        }
    }
    return winner;
}

template<typename T>
void Game_Manager::print_player_vector(const std::vector<T> &vec) {
    if (!vec.empty()) {
        auto iter = vec.begin();
        std::cout << "Giocatore " << *iter;
        ++iter;
        for (; iter != vec.end(); ++iter) {
            std::cout << ", " << *iter;
        }
    }
}


std::string print_simple_line(int length) {
	return std::string(length, '-');
}

bool greaterRoll(const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
	return a->get_dice_roll() > b->get_dice_roll();
}



