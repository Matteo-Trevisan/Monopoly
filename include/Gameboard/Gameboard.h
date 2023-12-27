#ifndef MONOPOLY_GAMEBOARD_H
#define MONOPOLY_GAMEBOARD_H

#include <vector>
#include "Player/Position.h"
#include "Player/Player.h"
#include "Space/Normal_Space.h"
#include "Space/Start_Space.h"
#include "Config.h"



class Gameboard {
public:
    explicit Gameboard(Config config);
    Space getPosition(Player p, int value);

    std::vector<Space> space_deck;  //TODO incapsulation
private:
};

#endif //MONOPOLY_GAMEBOARD_H
