
#include "Gameboard/Gameboard.h"
#include "Space/Normal_Space.h"
#include "Space/Start_Space.h"
#include <random>
#include <algorithm>
#include <stdexcept>
#include <iomanip>


Gameboard::Gameboard(Config config, std::vector<Player>* players) : players(players) {
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
}

const std::unique_ptr<Space>& Gameboard::get_space_at(int i) const {
	return space_deck.at(i);
}

std::vector<Player>* Gameboard::get_players() const {
	return players;
};

std::string get_space_info(int i, const Gameboard &g) {
	std::string ret;
	const std::unique_ptr<Space>& uptr = g.get_space_at(i);
	ret += uptr -> get_type_char() + uptr -> get_current_building_char();
	if (g.get_players() != nullptr) {
		std::vector<Player>& players_vec = *g.get_players();
		for (int j = 0; j < players_vec.size(); ++j) {
			if (players_vec.at(j).get_position() == i) {
				ret += std::to_string(j+1);
			}
		}
	}
	return ret;
}


std::ostream &operator<<(std::ostream &os, const Gameboard &g) {
	std::string stampa;
	std::vector<int> player_pos;


	for (int i = 14; i < 22; ++i) {
		os << "|" << std::setw(5) << get_space_info(i, g) << std::setw(5) << "|";
	}
	os << std::endl;
	int t = 6;
	int k = 22;
	for (int i = 0; i < 6; ++i) {
		os << "|" << std::setw(5) << get_space_info(k-9-i, g) << std::setw(5) << "|";
		os << std::setw(67);
		os << "|" << std::setw(5) << get_space_info(i+k, g) << std::setw(5) << "|";
		if (i < 5) {
			os << std::endl;
		}
	}
	os << std::endl;
	for (int i = 7; i >= 0; --i) {
		os << "|" << std::setw(5) << get_space_info(i,g ) << std::setw(5) << "|";
	}
	return os << stampa;
}
