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

	std::unique_ptr<Space>& get_space_at(int i);

private:
	std::vector<std::unique_ptr<Space>> space_deck;

};

std::ostream &operator<<(std::ostream &os, Gameboard &g);
std::string get_space_info(std::unique_ptr<Space>& uptr);

#endif //GAMEBOARD_H
