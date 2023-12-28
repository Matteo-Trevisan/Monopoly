
#include "Gameboard/Gameboard.h"
#include "Space/Normal_Space.h"
#include "Space/Start_Space.h"
#include <random>
#include <algorithm>
#include <stdexcept>


Gameboard::Gameboard(Config config) {
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

std::unique_ptr<Space>& Gameboard::get_space_at(int i) {
	return space_deck.at(i);
};

std::string get_space_info(std::unique_ptr<Space>& uptr) {
	return uptr -> get_type_char() + uptr -> get_current_building_char();
}


std::ostream &operator<<(std::ostream &os, Gameboard &g) {
	std::string stampa;
	for (int i = 14; i < 22; ++i) {
		std::unique_ptr<Space>& uptr = g.get_space_at(i);
		os << "|\t" << get_space_info(uptr) << "\t|\t";
	}
	os << std::endl;
	int t = 6;
	int k = 22;
	for (int i = 0; i < 6; ++i) {
		std::unique_ptr<Space>& uptr1 = g.get_space_at(k-9-i);
		os << "|\t" << get_space_info(uptr1) << "\t|\t";
		for (int s = 0; s < 18; ++s) {
			os << "\t";
		}
		std::unique_ptr<Space>& uptr2 = g.get_space_at(i+k);
		os << "|\t" << get_space_info(uptr2) << "\t|";
		if (i < 5) {
			os << std::endl;
		}
	}
	os << std::endl;
	for (int i = 7; i >= 0; --i) {
		std::unique_ptr<Space>& uptr = g.get_space_at(i);
		os << "|\t" << get_space_info(uptr) << "\t|\t";
	}
	return os << stampa;
}
