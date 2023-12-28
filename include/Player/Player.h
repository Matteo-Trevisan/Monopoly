
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

class Player {
public:
	explicit Player(int initial_balance, bool human, std::string&& name) :
	balance(initial_balance), pos(0), human(human), name(name), dice_roll(0) {};
	bool isPlaying();
	bool has_enough_money(int value) const;
	bool pay(int value);
	bool pay(Player& receiver, int value);
	void set_position(int p);
	bool is_human() const;
	void add_property();
	void set_initial_dice_roll(int value);
	int get_initial_dice_roll() const;
	int get_position() const;
	std::string get_name() const;
	virtual bool offer(std::string offer) const;

private:
	int dice_roll;
	std::string name;
	int balance;
	int pos;
	std::vector<std::string> properties;
	bool human;
};

// comparison function object per riordinare i giocatori in base al valore del tiro dei dadi
bool compareByDiceRoll(const Player &a, const Player &b);


#endif //PLAYER_H
