//
//	AUTORE: Matteo Trevisan
//

#include "Game_Manager.h"
#include <vector>
#include <random>
#include <algorithm>
#include <unordered_set>
#include "Player/Human_Player.h"
#include "Player/Computer_Player.h"
#include "Player/Bank.h"
#include "Gameboard/Gameboard.h"
#include "OstreamFork.h"
#include "unistd.h"		// For sleep function
#include "Player/Bank.h"

Game_Manager::Game_Manager(Player_Type p, Config config, const std::string& filename) : gen(rd()) {

	// Crea il primo player del tipo richiesto (Computer o Human)
	players.reserve(4);
	if (p) {
		players.emplace_back(new Human_Player(config.initial_balance, "1"));
	} else {
		players.emplace_back(new Computer_Player(config.initial_balance, "1", config.computer_accept_percentage));
	}

	// Crea gli altri 3 giocatori computer
	for (int i = 0; i < 3; ++i) {
		players.emplace_back(new Computer_Player(config.initial_balance, std::to_string(i+2), config.computer_accept_percentage));
	}

	// Inizializza le altre variabili membro
	bank = Bank(config.initial_balance * 20, "Banca");
	gameboard = Gameboard(config, &players, &bank);
	rand_dice = std::uniform_int_distribution<>(1, 6);
	log_file = std::ofstream( filename) ;
	osf = OstreamFork( &log_file , &std::cout ) ;
	max_turn = config.max_turn;
}

// Funzione iniziale per tirare i dadi e decidere l'ordine dei giocatori
void Game_Manager::setup() {

	std::cout << RED << std::setw(30) << "MONOPOLY" << RESET << std::endl << print_simple_line()
	<< std::endl << BLUE;
	osf <<  "Sorteggi per ordine turni: ";
	std::cout << RESET;
	osf << std::endl;

	// Fa tirare i dadi a ogni giocatore
	for (auto& p : players) {
		p->roll_dices(rand_dice, gen);
		osf << "Giocatore " + p->get_name() + " ha tirato i dadi ottenendo un valore di " << p->get_dice_roll() << std::endl;
		sleep(1);
	}

	// Ordina il vector di giocatori in base al tiro di dadi
	std::sort(players.begin(), players.end(), greaterRoll);

	std::cout << std::endl;

	// Ciclo per controllare che i valori dei tiri siano tutti diversi
    while(!are_all_dice_unique()) {

        for (int i = 0; i < players.size(); ++i) {

            int j = i + 1;
            int equal_rolls = 0;
            while (j < players.size() && players.at(i)->get_dice_roll() == players.at(j)->get_dice_roll()) {
                osf << "Giocatore " + players.at(i)->get_name() + " ha ottenuto lo stesso valore di Giocatore "
                    << players.at(j)->get_name() << std::endl;
                ++equal_rolls;
                ++j;
            }

            if (equal_rolls == 0) {
                continue;
            }

            for (j = i; j <= i + equal_rolls; ++j) {
                players.at(j)->roll_dices(rand_dice, gen);
                osf << "Giocatore " + players.at(j)->get_name() + " ha ritirato i dadi ottenendo un valore di "
                    << players.at(j)->get_dice_roll() << std::endl;
                sleep(1);
            }

            std::sort(players.begin(), players.end(), greaterRoll);
            std::cout << std::endl;

			break;
        }
    }

	std::cout << BLUE << "Ordine finale:" << RESET << std::endl;
	for (auto& p : players) {
		std::cout << "Giocatore " + p->get_name() << "  ";
	}
	osf << std::endl << print_simple_line() << std::endl;
}


// Funzione pubblica principale per far partire l'esecuzione del gioco
void Game_Manager::run_game() {

	// Chiamata a setup per ordinare i giocatori
	setup();

	int player_index = -1;
	int turno = 1;
	while(true) {

		//	Controllo fine partita per numero turni (come da richiesta prof nel forum)
		if (turno == max_turn + 1) {

			// Stampa i vincitori
			print_balance_winning();

			// exit program
			return;
		}

		// controllo fine partita per numero giocatori
		int giocatori_in_gioco = 0;
		Player* potential_winner;
		for (const auto & player : players) {
			if (player->isPlaying()) {
				++giocatori_in_gioco;
				potential_winner = player.get();
			}
		}
		// Se è rimasto solo 1 giocatore in gioco
		if (giocatori_in_gioco == 1) {
			// Stampa i vincitori
			osf << "Giocatore " << potential_winner->get_name() << " ha vinto la partita" << std::endl;

			// exit program
			return;
		}

		// selezionare prossimo gicatore
		++player_index;
		if (player_index >= 4 ) player_index = 0;

		// Stampa il numero di turno al primo giocatore
		if (player_index == 0) {
			std::cout << std::endl << MAGENTA << print_simple_line() << std::endl << std::setw(30) << "Turno " << turno << std::endl <<  print_simple_line() << RESET << std::endl;
		}

		// Incrementa il numero di turno
		if (player_index == 3) {
			++turno;
		}

		// salva riferimento al giocatore attuale per comodità
		auto& current_player = *players.at(player_index);


		// delay di 1 secondo
		sleep(1);

		// Stampa linea divisoria + attuale giocatore
		std::cout << "\n" << print_simple_line(19) << " Giocatore " << current_player.get_name() << " " <<  print_simple_line(19) << std::endl;

		// Salta giocatore eliminato
		if (!current_player.isPlaying()) {
			std::cout << "GIOCATORE ELIMINATO" << std::endl;
			continue;
		}

		// Stampa info giocatore
		std::cout << "Saldo: " << current_player.get_balance() << " fiorini;   Posizione: " << gameboard.get_space_at(current_player.get_position())->get_name() << ";   Proprietà: " << current_player.get_properties() << std::endl << std::endl;

		// Offre al giocatore umano di stampare il tabellone
		if (current_player.print_offer()) {
			print_player_info();
		}

		// Salva la posizione iniziale del giocatore (per controllare se passa per il via)
		int prev_pos = current_player.get_position();

		// Tira i dadi
		current_player.roll_dices(rand_dice, gen);
		osf << "Giocatore " + current_player.get_name() + " ha tirato i dadi ottenendo un valore di " << current_player.get_dice_roll() << std::endl;

		// Sposta il giocatore
		current_player.set_position((current_player.get_position() + current_player.get_dice_roll()) % 28);

		// Ottiene una reference alla casella di arrivo del giocatore per comodità d'uso
		Space& arrival_space = *gameboard.get_space_at(current_player.get_position());

		// Stampa posizione di arrivo del giocatore
		osf << "Giocatore " + current_player.get_name() + " è arrivato alla casella " << arrival_space.get_name() << " ";
		if (arrival_space.get_owner() != nullptr && arrival_space.get_owner() != &bank) {
			std::cout << "di proprietà del Giocatore " << arrival_space.get_owner()->get_name();
		}
		osf << std::endl;

		//
		// Se il giocatore è passato dal via: ritira i soldi del passaggio
		//
		if (current_player.get_position() < prev_pos){
			int start_pass_money_amount = gameboard.get_space_at(0)->get_start_pass_money();
			current_player.increment_balance(start_pass_money_amount);
			osf << "Giocatore " << current_player.get_name() << " è passato dal via e ha ritirato " << start_pass_money_amount << " fiorini" << std::endl;
		}

		//
		// Se la casella non è di nessuno offre di comprarla
		//
		if (arrival_space.get_owner() == nullptr) {
			buy_space_manager(current_player, arrival_space);
			print_player_turn_end(current_player);
			continue;
		}

		//
		// Se la cella di arrivo è della banca (Angular_Space oppure Start_space)
		// non fare niente e continua
		//
		if (arrival_space.get_owner() == &bank) {
			print_player_turn_end(current_player);
			continue;
		}

		//
		// Se la cella di arrivo è del giocatore offre di fare upgrade della cella
		// se le condizioni sono favorevoli (cella upgradable e abbastanza soldi)
		//
		if (arrival_space.get_owner() == &current_player) {
			if (arrival_space.upgradable()) {
				upgrade_space_manager(current_player,arrival_space);
			}
			print_player_turn_end(current_player);
			continue;
		}

		//
		// Se la cella non è del giocatore allora paga il pernottamento
		//
		if (arrival_space.get_owner() != &current_player) {
			if (arrival_space.get_current_building() != Building::empty) {
				overnight_payment_manager(current_player, arrival_space);
			}
			print_player_turn_end(current_player);
			continue;
		}

	}
}

void Game_Manager::print_balance_winning() {
	// cerca quale è il numero più alto di fiorini
	int max_balance = 0;
	for (const auto & player : players) {
		if (player->isPlaying()) {
			if(player->get_balance() > max_balance)
				max_balance = player->get_balance();
		}
	}

	// Seleziona i giocatori vincitori
	std::vector<Player*> winners;
	for (const auto & player : players) {
		if (player->isPlaying())
			if(player->get_balance() == max_balance) winners.push_back(player.get());
	}

	// Stampa i giocatori vincenti
	std::cout << "\n" << print_simple_line() << "\n";
	osf << std::endl << player_vector_to_string(winners);
	if(winners.size() == 1) {
		osf << " ha vinto la partita" << std::endl;
	} else {
		osf << " hanno vinto la partita" << std::endl;
	}
}

void Game_Manager::print_player_info() {
	// stampa tabellone
	std::cout << gameboard << std::endl << std::endl;

	// stampa lista proprietà per giocatore
	std::cout << "PROPRIETA'" << std::endl;
	for (const auto & p : players) {
		std::cout << "Giocatore " << p->get_name() << ": " << p->get_properties() << "\n";
	}

	// stampa lista fiorini per giocatore
	std::cout << std::endl << "SALDO" << std::endl;
	for (const auto & p : players) {
		std::cout << "Giocatore " << p->get_name() << ": " << p->get_balance() << " fiorini" << "\n";
	}

	// Implementazione di premere invio per continuare
	std::cout << "\nPremere INVIO per continuare...";
	std::cin.ignore();
	while (std::cin.get()!='\n');
	std::cout << std::endl;
}

void Game_Manager::buy_space_manager(Player& current_player, Space& arrival_space) {
	// Controllo che il giocatore abbia abbastanza soldi per comprare il terreno
	if(current_player.has_enough_money(arrival_space.get_terrain_sale_price())) {

		while (true) {

			// propone l'offerta
			// 0: rifiutata, 1: accettata, 2: visualizza tabellone
			int offer = current_player.offer(
					"Giocatore " + current_player.get_name() + ", vuoi acquistare la proprietà " +
					arrival_space.get_name() + " a " + std::to_string(arrival_space.get_terrain_sale_price()) +
					" fiorini?");

			if (offer == 0){	// offerta rifiutata
				std::cout << "Giocatore " << current_player.get_name() << " ha rifiutato l'offerta." << std::endl;
				break;
			} else if (offer == 1) {	// offerta accettata

				// paga il terreno
				current_player.pay(arrival_space.get_terrain_sale_price());

				// imposta il proprietario sulla casella
				arrival_space.set_owner(&current_player);

				// aggiunge la proprietà alla lista per comodità di stampa
				current_player.add_property(arrival_space.get_name());

				// stampa l'acquisto
				osf << "Giocatore " << current_player.get_name() << " ha acquistato il terreno " << arrival_space.get_name() << std::endl;
				break;
			} else if (offer == 2) {	// Visualizza tabellone
				print_player_info();
			}
		}
	} else {
		std::cout << "Giocatore " << current_player.get_name() << " non ha abbastanza fiorini per comprare il terreno." << std::endl;
	}
}

void Game_Manager::upgrade_space_manager(Player &current_player, Space &arrival_space) {
	// Controllo che il giocatore abbia abbastanza soldi per migliorare il terreno
	if (current_player.has_enough_money(arrival_space.get_next_upgrade_price())) {
		while (true) {
			// propone l'offerta
			// 0: rifiutata, 1: accettata, 2: visualizza tabellone
			int offer = current_player.offer("Vuoi migliorare la proprietà " + arrival_space.get_name() + ", costruendo una " + arrival_space.get_next_building_name() + ", al costo di " + std::to_string(arrival_space.get_next_upgrade_price()) + " fiorini?");

			if (offer == 1) {	// offerta accettata
				// Paga il miglioramento
				current_player.pay(arrival_space.get_next_upgrade_price());

				// Migliora la casella
				arrival_space.upgrade();

				// Stampa a terminale e sul file
				if (arrival_space.get_current_building() == Building::house) {
					osf << "Giocatore " << current_player.get_name() << " ha costruito una casa sul terreno " << arrival_space.get_name() << std::endl;
				} else if (arrival_space.get_current_building() == Building::hotel){
					osf << "Giocatore " << current_player.get_name() << " ha migliorato una casa in albergo sul terreno " << arrival_space.get_name() << std::endl;
				}
				break;
			} else if (offer == 0) {	// Offerta rifiutata
				std::cout << "Giocatore " << current_player.get_name() << " ha rifiutato l'offerta." << std::endl;
				break;
			} else if (offer == 2) {	// Visualizza tabellone
				print_player_info();
			}
		}
	} else {
		std::cout << "Giocatore " << current_player.get_name() << " non ha abbastanza fiorini per migliorare la casella." << std::endl;
	}
}

void Game_Manager::overnight_payment_manager(Player &current_player, Space &arrival_space) {
	//
	// Prova a pagare chiamando la funzione pay():
	// in caso positivo paga
	// altrimenti viene pagato tutto il capitale disponibile e dichiarata la bancarotta
	//
	if (current_player.pay(*arrival_space.get_owner(), arrival_space.get_overnight_stay_price())) {

		// Giocatore X paga Giocatore Y
		osf << "Giocatore " << current_player.get_name() << " ha pagato " << arrival_space.get_overnight_stay_price() << " fiorini a Giocatore "
			<< arrival_space.get_owner()->get_name() << " per pernottamento nella casella " << arrival_space.get_name() << std::endl;
	} else {

		// Bancarotta, Giocatore eliminato
		osf << "Giocatore " << current_player.get_name() << " è stato eliminato." << std::endl;
		current_player.bankrupt();

		// Reset delle celle del giocatore
		for (auto& s : gameboard.get_space_deck()) {
			if (s->get_owner() == &current_player) {
				s->reset();
			}
		}
	}
}

// Funzione per stampare la fine del turno del giocatore
void Game_Manager::print_player_turn_end(Player &current_player) {
	osf << "Giocatore " << current_player.get_name() <<" ha finito il turno" << std::endl;
}

// Funzione per stampare la lista di giocatori vincitori
std::string player_vector_to_string(const std::vector<Player*> &vec) {
	std::string ret;
    if (!vec.empty()) {
		for (int i = 0; i < vec.size(); ++i) {
			ret += "Giocatore " + vec.at(i)->get_name();
			if (vec.size() > 1 && i < vec.size() - 1) {
				ret += ", ";
			}
		}
    }
	return ret;
}


std::string print_simple_line(int length) {
	return std::string(length, '-');
}

// Funzione che verrà usata come predicato per confrontare i giocatori in base al lancio dei dadi
bool greaterRoll(const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
	return a->get_dice_roll() > b->get_dice_roll();
}

// FUnzione che controlla se tutti i lanci sono diversi per l'ordinamento
bool Game_Manager::are_all_dice_unique() {
    std::unordered_set<int> unique_dice_roll;

    for (auto& p : players) {
        // inserisce il valore nel set
        auto result = unique_dice_roll.insert(p->get_dice_roll());

        // verifica se l'inserimento è avvenuto con successo (il valore era unico)
        if (!result.second) {
            // Valore duplicato trovato
            return false;
        }
    }

    // tutti i valori dei tiri di dadi sono unici
    return true;
}



