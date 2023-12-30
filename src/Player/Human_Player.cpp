
#include "Player/Human_Player.h"
#include <iostream>
#include <algorithm>

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

bool Human_Player::print_offer() {
	std::cout << "Digitare [S]  per visualizzare (show) il tabellone, \n[N] per continuare senza visualizzarlo: ";
	while (true) {
		std::string response;
		std::cin >> response;
		std::transform(response.begin(), response.end(),
					   response.begin(), ::toupper);
		if (response == "S" || response == "SHOW") {
			return true;
		} else if(response == "N") {
			return false;
		}
		std::cout << "Invalid response: ";
	}
}
