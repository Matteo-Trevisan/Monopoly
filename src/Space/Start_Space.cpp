
#include "Space/Start_Space.h"
#include "iostream"

int Start_Space::get_start_pass_money() const {
	return start_pass_money;
}

void Start_Space::set_start_pass_money(int startPassMoney) {
	start_pass_money = startPassMoney;
}
/*
std::ostream& Start_Space::operator<<(std::ostream &os) {
    return os << "P";
}
 */ TODO finire qui