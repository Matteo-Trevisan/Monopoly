
#include "Player/Player.h"

bool Player::isPlaying() {
	return balance >= 0;
}


bool Player::has_enough_money(int value) const {
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

void Player::set_position(int p) {
	pos = p;
}

/*	TODO capire come implementare le prorpietà come coppie A1, B8
void Player::add_property() {
	properties.push_back(pos);
}
 */

void Player::set_initial_dice_roll(int value) {
	dice_roll = value;
}

int Player::get_initial_dice_roll() const {
	return dice_roll;
}

int Player::get_position() const {
	return pos;
}

std::string Player::get_name() const {
	return name;
}

bool Player::offer(const std::string& offer) const {
	return true;
}
