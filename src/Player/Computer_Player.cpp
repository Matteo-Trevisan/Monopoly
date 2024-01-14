//
//	AUTORE: Elia Tolfo
//

#include "Player/Computer_Player.h"
#include <iostream>
#include <random>

// funzione gestione richiesta risposta per un'offerta
int Computer_Player::offer(const std::string& offer) const {
	std::cout << offer << " [S/N]: ";

    // generatore di numeri casuali tra 1 e 100 inclusi
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> rand_choice(1, 100);

    // utilizzo del numero generato per l'attuazione dell'azione nel 25% dei casi
	if (rand_choice(gen) <= accept_percentage) {
		std::cout << "S" << std::endl;
		return true;
	} else {
		std::cout << "N" << std::endl;
		return false;
	}
}

// distruttore della classe Computer_Player impostato di default
Computer_Player::~Computer_Player() = default;
