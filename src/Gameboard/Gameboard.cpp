//
//	AUTORE: Matteo Trevisan
//

#include "Gameboard/Gameboard.h"
#include <random>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include "Space/Normal_Space.h"
#include "Space/Start_Space.h"
#include "Space/Space.h"
#include "Player/Bank.h"
#include "Config.h"
#include "memory"
#include "Colors.h"

Gameboard::Gameboard(Config config, std::vector<std::unique_ptr<Player>>* players, Bank* bank) : players(players) {
	// Crea 24 spazi per le caselle
    space_deck.reserve(24);
	space_deck.emplace_back(new Start_Space(config.pass_start_space, bank));
    for(int i = 0; i < 8; i++) {
        space_deck.emplace_back(new Normal_Space(config.Cheap_Space));
    }
    for(int i = 0; i < 10; i++) {
        space_deck.emplace_back(new Normal_Space(config.Standard_Space));
    }
    for(int i = 0; i < 6; i++) {
        space_deck.emplace_back(new Normal_Space(config.Luxury_Space));
    }

	// Mescola le casella normali
    std::random_device rd{};
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(space_deck) + 1, std::end(space_deck),rng);

	// Inserimento delle 3 caselle angolari e posizionamento nel posto giusto tramite swap
    for (int i = 0; i < 3; ++i) {
        space_deck.emplace_back(new Angular_Space(bank));
    }
    iter_swap(space_deck.begin() + 7, space_deck.begin() + 25);
    iter_swap(space_deck.begin() + 14, space_deck.begin() + 26);
    iter_swap(space_deck.begin() + 21, space_deck.begin() + 27);

	// assegnazione dei nomi a ogni casella
	for (int i = 7; i >= 0; --i) {
		//Riga orizzontale bassa
		space_deck.at(i)->set_name("H" + std::to_string(8-i));
		// Riga orizzontale alta
		space_deck.at(i+14)->set_name("A" + std::to_string(i+1));
	}
	for (int i = 0; i < 6; ++i) {
		// Colonna verticale sinistra
		space_deck.at(i+8)->set_name(std::string(1, char(71-i))+ "1");
		// Colonna verticale destra
		space_deck.at(i+22)->set_name(std::string(1, char(66+i))+ "8");
	}
}

// Funzione per avere la caselle i-esima const
const std::unique_ptr<Space>& Gameboard::get_space_at(int i) const {
	return space_deck.at(i);
}

// Funzione per avere la caselle i-esima
std::unique_ptr<Space>& Gameboard::get_space_at(int i) {
	return space_deck.at(i);
}

// Ritorna puntatore al vettore di players const
std::vector<std::unique_ptr<Player>>* Gameboard::get_players() const {
	return players;
}

// Ritorna puntatore al vettore di players
std::vector<std::unique_ptr<Space>> &Gameboard::get_space_deck() {
	return space_deck;
}

// Ritorna una stringa da usare per stampare le caselle
// (la stringa contiene il carattere del tipo di building e un numero rappresentante il giocatore, se c'è)
std::string get_space_info(int i, const Gameboard &g) {
	std::string ret;
	const std::unique_ptr<Space>& uptr = g.get_space_at(i);
	ret += uptr -> get_type_char() + uptr -> get_current_building_char();
	if (g.get_players() != nullptr) {
		std::vector<std::unique_ptr<Player>>& players_vec = *g.get_players();
		for (const auto & j : players_vec) {
			if (j->get_position() == i) {
				ret += j->get_name();
			}
		}
	}
	return ret;
}

// Overloading operatore<< con Print_Line per stampare una linea
std::ostream &operator<<(std::ostream &os, const Print_Line &obj) {
	os << obj.color << "+" << std::string(3, '-') << "+";
	for (int i = 0; i < 8; ++i) {
		if (obj.middle_part || i == 0 || i == 7) {
			if (!obj.color.empty() && i == 0) {
				os << RESET << std::string(9, '-') << "+";
			} else {
				os << std::string(9, '-') << "+";
			}
		} else {
			if (i == 6) {
				os << " " << std::setw(9) << "+";
			} else {
				os << " " << std::setw(9) << " ";
			}
		}

	}
	return os;
}

// Overloading operatore<< con Gameboard per stampare la tabella
std::ostream &operator<<(std::ostream &os, const Gameboard &g) {
	std::string stampa;		// Stringa ritornata
	std::vector<int> player_pos;


	// LINEA
	os << GREEN << Print_Line() << std::endl;

	// LEGENDA ORIZZONTALE
	os << "|" << RED << std::setw(2) << " \u2665 " << std::setw(2) << GREEN << "|";
	for (int i = 0; i < 8; ++i) {
		os << std::setw(5) << i+1 << std::setw(5) << "|";
	}
	os << std::endl;

	// LINEA
	os << Print_Line() << std::endl << RESET;

	// PRIMA RIGA TABELLA
	os << GREEN << "|" << std::setw(2) << "A" << std::setw(2) << "|" << RESET;
	for (int i = 14; i < 22; ++i) {
		os << std::setw(5) << get_space_info(i, g) << std::setw(5) << "|";
	}
	os << std::endl << Print_Line(true, GREEN) << std::endl;

	// PARTE CENTRALE TABELLA
	int k = 22;
	for (int i = 0; i < 6; ++i) {
		os << GREEN << "|" << std::setw(2) << char(66+i) << std::setw(2) << "|" << RESET << std::setw(5) << get_space_info(k-9-i, g) << std::setw(5) << "|";
		os << std::setw(60);
		os << "|" << std::setw(5) << get_space_info(i+k, g) << std::setw(5) << "|";
		if (i < 5) {
			os << std::endl << Print_Line(false, GREEN) << std::endl;
		}
	}
	os << std::endl << Print_Line(true, GREEN) << std::endl;

	// RIGA FINALE TABELLA
	os << GREEN << "|" << std::setw(2) << "H" << std::setw(2) << "|" << RESET;
	for (int i = 7; i >= 0; --i) {
		os << std::setw(5) << get_space_info(i,g ) << std::setw(5) << "|";
	}
	os << std::endl << Print_Line(true, GREEN);
	return os << stampa;
}
