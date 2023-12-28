//
// Created by Matteo Trevisan on 28/12/23.
//

#include "Player/Human_Player.h"
#include <iostream>

bool Human_Player::offer(const std::string& offer) const {
	std::cout << offer << " [S/N]: ";
	while (true) {
		std::string response;
		std::cin >> response;
		std::transform(response.begin(), response.end(),
					   response.begin(), ::toupper);
		if (response == "S") {
			return true;
		} else if (response == "N") {
			return false;
		}
		std::cout << "Invalid response [S/N]: ";
	}
}
