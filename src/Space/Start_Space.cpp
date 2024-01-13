
#include "Space/Start_Space.h"

Start_Space::~Start_Space() = default;

int Start_Space::get_start_pass_money() const {
	return start_pass_money;
}

char Start_Space::get_type_char() const {
	return 'P';
}
