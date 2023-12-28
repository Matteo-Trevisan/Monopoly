
#include "Gameboard/Gameboard.h"
#include "Space/Normal_Space.h"
#include "Space/Start_Space.h"
#include <random>
#include <algorithm>
#include <iomanip>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

Gameboard::Gameboard(Config config, std::vector<std::unique_ptr<Player>>* players) : players(players) {
    space_deck.reserve(24);
	space_deck.emplace_back(new Start_Space(config.initial_balance));
    for(int i = 0; i < 8; i++) {
        space_deck.emplace_back(new Normal_Space(config.Cheap_Space));
    }
    for(int i = 0; i < 10; i++) {
        space_deck.emplace_back(new Normal_Space(config.Standard_Space));
    }
    for(int i = 0; i < 6; i++) {
        space_deck.emplace_back(new Normal_Space(config.Luxury_Space));
    }

    std::random_device rd{};
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(space_deck) + 1, std::end(space_deck),rng);

    for (int i = 0; i < 3; ++i) {
        space_deck.emplace_back(new Angular_Space());
    }
    iter_swap(space_deck.begin() + 7, space_deck.begin() + 25);
    iter_swap(space_deck.begin() + 14, space_deck.begin() + 26);
    iter_swap(space_deck.begin() + 21, space_deck.begin() + 27);

	for (int i = 7; i >= 0; --i) {
		space_deck.at(i)->set_name("H" + std::to_string(8-i));
		space_deck.at(i+14)->set_name("A" + std::to_string(i+1));
	}
	for (int i = 0; i < 6; ++i) {
		space_deck.at(i+8)->set_name(std::string(1, char(71-i))+ "1");
		space_deck.at(i+22)->set_name(std::string(1, char(66+i))+ "8");
	}
}

const std::unique_ptr<Space>& Gameboard::get_space_at(int i) const {
	return space_deck.at(i);
}

std::unique_ptr<Space>& Gameboard::get_space_at(int i) {
	return space_deck.at(i);
}

std::vector<std::unique_ptr<Player>>* Gameboard::get_players() const {
	return players;
};

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


std::ostream &operator<<(std::ostream &os, const Gameboard &g) {
	std::string stampa;
	std::vector<int> player_pos;


	// LINEA
	os << GREEN << Print_Line() << std::endl;

	// LEGENDA ORIZZONTALE
	os << "|" << RED << std::setw(2) << " \u2665 " << std::setw(2) << GREEN << "|";
	for (int i = 0; i < 8; ++i) {
		os << std::setw(5) << char(65+i) << std::setw(5) << "|";
	}
	os << std::endl;

	// LINEA
	os << Print_Line() << std::endl << RESET;

	// PRIMA RIGA TABELLA
	os << GREEN << "|" << std::setw(2) << "1" << std::setw(2) << "|" << RESET;
	for (int i = 14; i < 22; ++i) {
		os << std::setw(5) << get_space_info(i, g) << std::setw(5) << "|";
	}
	os << std::endl << Print_Line(true, GREEN) << std::endl;

	// PARTE CENTRALE TABELLA
	int k = 22;
	for (int i = 0; i < 6; ++i) {
		os << GREEN << "|" << std::setw(2) << i+2 << std::setw(2) << "|" << RESET << std::setw(5) << get_space_info(k-9-i, g) << std::setw(5) << "|";
		os << std::setw(60);
		os << "|" << std::setw(5) << get_space_info(i+k, g) << std::setw(5) << "|";
		if (i < 5) {
			os << std::endl << Print_Line(false, GREEN) << std::endl;
		}
	}
	os << std::endl << Print_Line(true, GREEN) << std::endl;

	// RIGA FINALE TABELLA
	os << GREEN << "|" << std::setw(2) << "8" << std::setw(2) << "|" << RESET;
	for (int i = 7; i >= 0; --i) {
		os << std::setw(5) << get_space_info(i,g ) << std::setw(5) << "|";
	}
	os << std::endl << Print_Line(true, GREEN);
	return os << stampa;
}
