
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <random>

class Player {
public:
	explicit Player(int initial_balance, const std::string& name) :
	balance(initial_balance), pos(0), name(name), dice_roll(0) {};
	bool isPlaying() const;
	bool has_enough_money(int value) const;
	bool pay(int value);
	bool pay(Player& receiver, int value);
	void set_position(int p);
	void add_property(std::string space_name);
	std::string get_properties() const;
	void set_dice_roll(int value);
	int get_dice_roll() const;
	int roll_dices(std::uniform_int_distribution<>& dices, std::mt19937& gen);
	int get_position() const;
	std::string get_name() const;
	void bankrupt();
	int get_balance() const;
	virtual bool offer(const std::string& offer) const;
	virtual bool print_offer();

private:
	int dice_roll;
	std::string name;
	int balance;
	int pos;
	std::vector<std::string> properties;
};

#endif //PLAYER_H
