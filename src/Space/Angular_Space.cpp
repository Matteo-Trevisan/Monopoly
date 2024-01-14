
#include "Space/Angular_Space.h"

//Distruttore di default
Angular_Space::~Angular_Space() = default;

//Restituisce il carattere che indica la tipologia di terreno
char Angular_Space::get_type_char() const {
	return Space::get_type_char();
}
