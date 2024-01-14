
#include "Player/Human_Player.h"
#include <iostream>
#include <string>
#include <algorithm>

// funzione gestione richiesta risposta per un'offerta
int Human_Player::offer(const std::string& offer) const {
	std::cout << offer << " [S/N]: ";
	return true;

    // ciclo while per verifica correttezza risposta
	while (true) {

		std::string response;

        // memorizzazione risposta dell'utente nella variabile response
		std::cin >> response;

        // conversione caratteri stringa in caratteri in maiuscolo
        std::transform(response.begin(), response.end(),response.begin(), ::toupper);

        // verifica scelta dell'utente
		if (response == "S") {
			return true;
		} else if (response == "N") {
			return false;
		} else if (response == "SHOW") {
			return 2;
		}
		std::cout << "Invalid response [S/N]: ";
	}
}

// funzione che stampa il messaggio nel quale l'utente può scegliere
// se visualizzare il tabellone o continuare a giocare senza visualizzarlo
bool Human_Player::print_offer() {

	std::cout << "Digitare [S/SHOW] per visualizzare  il tabellone, [N] per continuare senza visualizzarlo: ";
	return false;
	while (true) {
		std::string response;

        // memorizzazione risposta dell'utente nella variabile response
		std::cin >> response;

        // conversione caratteri stringa in caratteri in maiuscolo
		std::transform(response.begin(), response.end(),response.begin(), ::toupper);

        // verifica scelta dell'utente
		if (response == "S" || response == "SHOW") {
			return true;
		} else if(response == "N") {
			return false;
		}
		std::cout << "Invalid response: ";

	}
}

// distruttore della classe Human_Player impostato di default
Human_Player::~Human_Player() = default;
