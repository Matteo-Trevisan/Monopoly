
#include "Player/Computer_Player.h"
#include <iostream>
#include <random>

bool Computer_Player::offer(const std::string& offer, bool bypass_to_false) const {
	if (bypass_to_false) {
		return false;
	}

	std::cout << offer << " [S/N]: ";

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> rand_choice(1, 100);

	if (rand_choice(gen) <= 25) {
		std::cout << "S" << std::endl;
		return true;
	} else {
		std::cout << "N" << std::endl;
		return false;
	}
}
