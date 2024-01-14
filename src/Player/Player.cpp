//
//	AUTORE: Elia Tolfo
//

#include "Player/Player.h"
#include <vector>
#include <string>
#include <random>

// funzione che verifica se il giocatore è ancora in partita attraverso controllo balance
bool Player::isPlaying() const {
	return balance >= 0;
}

// funzione che verifica se il giocatore ha abbastanza soldi per poter fare un'azione
bool Player::has_enough_money(int value) const {
	return balance >= value;
}

// funzione che si occupa dei pagamenti non a favore di un altro giocatore
bool Player::pay(int value) {
    // controllo se balance del giocatore è sufficiente
	if (has_enough_money(value)) {
		balance -= value;
		return true;
	}
	return false;
}

// funzione che si occupa dei pagamenti a favore di un altro giocatore
bool Player::pay(Player &receiver, int value) {

    // controllo se balance del giocatore pagante è sufficiente
	if (has_enough_money(value)) {
		this->balance -= value;
		receiver.balance += value;
		return true;
	} else {    // in caso di balance giocatore pagante non sufficiente

        // giocatore ricevente ottiene i soldi che il giocatore pagante può pagare
        receiver.balance += this->balance;

        // set balance giocatore pagante negativo per eliminazion
		this -> balance = -1;
    }
	return false;
}

// funzione per spostare giocatore in una posizione
void Player::set_position(int p) {
	pos = p;
}

// funzione per aggiungere proprietà al giocatore
void Player::add_property(const std::string& space_name) {
	properties.push_back(space_name);
}

// attribuzione valore tiro dadi
void Player::set_dice_roll(int value) {
	dice_roll = value;
}

// ritorno valore tiro dadi
int Player::get_dice_roll() const {
	return dice_roll;
}

// ritorno posizione giocatore
int Player::get_position() const {
	return pos;
}

// ritorno nome giocatore
std::string Player::get_name() const {
	return name;
}

// funzione gestione richiesta risposta per un'offerta
int Player::offer(const std::string& offer) const {
	return false;
}

// funzione tiro dadi
int Player::roll_dices(std::uniform_int_distribution<>& dices, std::mt19937& gen) {
	set_dice_roll(dices(gen) + dices(gen));
	return get_dice_roll();
}

// funzione che elimina il giocatore dalla partita e libera le sue proprietà
void Player::bankrupt() {
	properties.clear();
	properties.emplace_back("Bancarotta");
	balance = -1;
	pos = -1;
}

// ritorno balance del giocatore
int Player::get_balance() const {
	return balance;
}

// ritorno proprietà del giocatore
std::string Player::get_properties() const {
	std::string ret;
	for (const auto & property : properties) {
		ret += property + ", ";
	}
	return ret;
}

// funzione stampa messaggio offerta
bool Player::print_offer() {
	return false;
}

// funzione incremento balance giocatore di value
void Player::increment_balance(int value) {
	balance += value;
}

// distruttore della classe Player impostato di default
Player::~Player() = default;
