#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "Player/Player.h"
#include "Space/Space.h"
#include "Config.h"
#include "memory"

class Gameboard {
public:
    explicit Gameboard(Config config = Config());
    Space getPosition(Player p, int value);

	std::vector<std::unique_ptr<Space>> space_deck;
private:
};

#endif //GAMEBOARD_H
