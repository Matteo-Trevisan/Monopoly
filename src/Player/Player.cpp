
#include "Player/Player.h"

bool Player::isPlaying() const {
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

void Player::add_property(std::string space_name) {
	properties.push_back(space_name);
}

void Player::set_dice_roll(int value) {
	dice_roll = value;
}

int Player::get_dice_roll() const {
	return dice_roll;
}

int Player::get_position() const {
	return pos;
}

std::string Player::get_name() const {
	return name;
}

bool Player::offer(const std::string& offer, bool bypass_to_false) const {
	return bypass_to_false;
}

int Player::roll_dices(std::uniform_int_distribution<>& dices, std::mt19937& gen) {
	set_dice_roll(dices(gen) + dices(gen));
	return get_dice_roll();
}

void Player::bankrupt() {
	properties.clear();
	properties.emplace_back("Bancarotta");
	balance = -1;
	pos = -1;
}

int Player::get_balance() const {
	return balance;
}

std::string Player::get_properties() const {
	std::string ret;
	for (int i = 0; i < properties.size(); ++i) {
		ret += properties.at(i);
		if (i != properties.size() - 1) {
			ret += ", ";
		}
	}
	return ret;
}

bool Player::print_offer() const {
	return false;
}
