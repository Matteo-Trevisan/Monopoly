//
//	AUTORE: Matteo Trevisan
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <iomanip>
#include "Space/Space.h"
#include "Player/Bank.h"
#include "Config.h"
#include "memory"
#include "Colors.h"

// classe per la gestione del tabellone
class Gameboard {
public:
    explicit Gameboard(Config config = Config(), std::vector<std::unique_ptr<Player>>* players = nullptr, Bank* bank = nullptr);
	std::vector<std::unique_ptr<Player>>* get_players() const;
	const std::unique_ptr<Space>& get_space_at(int i) const;
	std::unique_ptr<Space>& get_space_at(int i);
	std::vector<std::unique_ptr<Space>>& get_space_deck();

private:
	std::vector<std::unique_ptr<Space>> space_deck;		// vector delle caselle
	std::vector<std::unique_ptr<Player>>* players;		// puntatore al vector dei giocatori per stampa posizione giocatori
};

// Classe per la gestione di stampa di linee della tabella
class Print_Line {
public:
	explicit Print_Line(bool mp = true, const std::string& col = std::string()) : middle_part(mp), color(col) {};
	bool middle_part;
	std::string color;
};

// Overloading operatore<< con Gameboard per stampare la tabella
std::ostream &operator<<(std::ostream &os, const Gameboard &g);

// Overloading operatore<< con Print_Line per stampare una linea
std::ostream &operator<<(std::ostream &os, const Print_Line &obj);

// Ritorna una stringa da usare per stampare le caselle
std::string get_space_info(int i, const Gameboard &g);

#endif //GAMEBOARD_H
