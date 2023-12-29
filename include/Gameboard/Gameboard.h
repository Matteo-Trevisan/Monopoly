#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <iomanip>
#include "Space/Space.h"
#include "Player/Bank.h"
#include "Config.h"
#include "memory"
#include "Colors.h"

class Gameboard {
public:
    explicit Gameboard(Config config = Config(), std::vector<std::unique_ptr<Player>>* players = nullptr, Bank* bank = nullptr);
	std::vector<std::unique_ptr<Player>>* get_players() const;
	const std::unique_ptr<Space>& get_space_at(int i) const;
	std::unique_ptr<Space>& get_space_at(int i);

private:
	std::vector<std::unique_ptr<Space>> space_deck;
	std::vector<std::unique_ptr<Player>>* players;
};

class Print_Line {
public:
	explicit Print_Line(bool mp = true, std::string col = std::string()) : middle_part(mp), color(col) {};
	bool middle_part;
	std::string color;
};

std::ostream &operator<<(std::ostream &os, const Gameboard &g);
std::ostream &operator<<(std::ostream &os, const Print_Line &obj);

std::string get_space_info(int i, const Gameboard &g);

#endif //GAMEBOARD_H
