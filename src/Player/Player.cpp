//
// Created by Matteo Trevisan on 26/12/23.
//

#include "Player/Player.h"

bool Player::isPlaying() {
	return balance >= 0;
}


bool Player::has_enough_money(int value) {
	return balance >= value;
}

bool Player::pay(int value) {
	if (has_enough_money(value)) {
		balance -= value;
		return true;
	}
	return false;
}

bool Player::pay(Player &receiver, int value) {
	if (has_enough_money(value)) {
		this->balance -= value;
		receiver.balance += value;
		return true;
	}
	return false;
}

void Player::set_position(Position &&p) {
	pos = p;
}

bool Player::is_human() const {
	return human;
}
