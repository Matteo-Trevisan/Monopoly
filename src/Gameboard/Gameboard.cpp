
#include "Gameboard/Gameboard.h"
#include "Space/Normal_Space.h"
#include "Space/Start_Space.h"
#include <random>
#include <algorithm>


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
};