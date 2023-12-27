//
// Created by Matteo Trevisan on 26/12/23.
//

#include "Player/Player.h"

bool Player::isPlaying() {
	return balance >= 0;
}


bool Player::has_enought_balance(int value) {
	return balance >= value;
}

bool Player::pay(int value) {
	if (has_enought_balance(value)) {
		balance -= value;
		return true;
	}
	return false;
}

bool Player::pay(Player &ricevente, int value) {
	if (has_enought_balance(value)) {
		this->balance -= value;
		ricevente.balance += value;
		return true;
	}
	return false;
}
