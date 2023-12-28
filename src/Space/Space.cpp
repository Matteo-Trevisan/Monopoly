
#include "Space/Space.h"

int Space::get_terrain_sale_price() const {
	return 0;
}

int Space::get_house_sale_price() const {
	return 0;
}

int Space::get_hotel_sale_price() const {
	return 0;
}

int Space::get_house_overnight_stay_price() const {
	return 0;
}

int Space::get_hotel_overnight_stay_price() const {
	return 0;
}

int Space::get_overnight_stay_price() {
	return 0;
}

int Space::get_next_upgrade_price() {
	return 0;
}

bool Space::upgradable() {
	return false;
}

void Space::upgrade() {

}

void Space::reset() {

}

char Space::get_type_char() const {
	return ' ';
}


std::ostream &operator<<(std::ostream &os, const Space &d) {
	return os << d.get_type_char();
}

