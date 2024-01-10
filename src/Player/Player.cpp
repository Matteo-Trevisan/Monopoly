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
	} else {
        receiver.balance += this->balance;
		this -> balance = -1;
    }
	return false;
}

void Player::set_position(int p) {
	pos = p;
}

void Player::add_property(const std::string& space_name) {
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

bool Player::offer(const std::string& offer) const {
	return false;
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
	for (const auto & property : properties) {
		ret += property + ", ";
	}
	return ret;
}

bool Player::print_offer() {
	return false;
}

Player::~Player() = default;
