
#include "Gameboard/Gameboard.h"
#include <random>
#include <algorithm>


Gameboard::Gameboard(Config config) {
    space_deck.reserve(24);
    for(int i = 0; i < 8; i++) {
        space_deck.push_back(Normal_Space(config.Cheap_Space));
    }
    for(int i = 0; i < 10; i++) {
        space_deck.push_back(Normal_Space(config.Standard_Space));
    }
    for(int i = 0; i < 6; i++) {
        space_deck.push_back(Normal_Space(config.Luxury_Space));
    }

    std::random_device rd{};
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(space_deck), std::end(space_deck),rng);

    space_deck.push_back(Start_Space(config.initial_balance));
    for (int i = 0; i < 3; ++i) {
        space_deck.push_back(Angular_Space());
    }
    iter_swap(space_deck.begin(), space_deck.begin() + 24);
    iter_swap(space_deck.begin() + 7, space_deck.begin() + 25);
    iter_swap(space_deck.begin() + 14, space_deck.begin() + 26);
    iter_swap(space_deck.begin() + 21, space_deck.begin() + 27);
};