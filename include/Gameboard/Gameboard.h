#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "Player/Player.h"
#include "Space/Space.h"
#include "Config.h"
#include "memory"

class Gameboard {
public:
    explicit Gameboard(Config config = Config(), std::vector<std::unique_ptr<Player>>* players = nullptr);
	std::vector<std::unique_ptr<Player>>* get_players() const;
	const std::unique_ptr<Space>& get_space_at(int i) const;

private:
	std::vector<std::unique_ptr<Space>> space_deck;
	std::vector<std::unique_ptr<Player>>* players;
};

std::ostream &operator<<(std::ostream &os, const Gameboard &g);
std::string get_space_info(int i, const Gameboard &g);

#endif //GAMEBOARD_H
