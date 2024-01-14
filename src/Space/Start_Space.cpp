//
//	AUTORE: Andrea Sacchetto
//

#include "Space/Start_Space.h"

//Distruttore di default
Start_Space::~Start_Space() = default;

//Restituisce il valore che identifica l'ammontare di denaro da ricevere al passaggio del VIA
int Start_Space::get_start_pass_money() const {
	return start_pass_money;
}

//Restituisce il carattere che indica la tipologia di terreno
char Start_Space::get_type_char() const {
	return 'P';
}
