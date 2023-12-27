
#include "Gameboard/Gameboard.h"
#include <random>
#include <algorithm>


Gameboard::Gameboard(Config config) {
    std::vector<Normal_Space> space_deck;
    space_deck.reserve(24);
    for(int i = 0; i < 8; i++) {
        space_deck.emplace_back(config.Cheap_Space);
    }
    for(int i = 0; i < 10; i++) {
        space_deck.emplace_back(config.Standard_Space);
    }
    for(int i = 0; i < 6; i++) {
        space_deck.emplace_back(config.Luxury_Space);
    }
};