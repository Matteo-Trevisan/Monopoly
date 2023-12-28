
#include "Space/Normal_Space.h"

int Normal_Space::get_terrain_sale_price() const {
	return data.terrain_sale;
}

int Normal_Space::get_house_sale_price() const {
	return data.house_sale;
}

int Normal_Space::get_hotel_sale_price() const {
	return data.hotel_sale;
}

int Normal_Space::get_house_overnight_stay_price() const {
	return data.house_overnight_stay;
}

int Normal_Space::get_hotel_overnight_stay_price() const {
	return data.hotel_overnight_stay;
}

void Normal_Space::upgrade() {
	switch (building) {
		case empty:
			building = Building::house;
			break;
		case house:
			building = Building::hotel;
			break;
		case hotel:
			break;
	}
}

void Normal_Space::reset() {
	building = Building::empty;
	owner = nullptr;
}

int Normal_Space::get_overnight_stay_price() {
	switch (building) {
		case house:
			return get_house_overnight_stay_price();
		case hotel:
			return get_hotel_overnight_stay_price();
		default:
			return 0;
	}
}

int Normal_Space::get_next_upgrade_price() {
	if (owner != nullptr) {
		switch (building) {
			case empty:
				return get_house_sale_price();
			case house:
				return get_hotel_sale_price();
			case hotel:
				break;
		}
	}
	return 0;
}

bool Normal_Space::upgradable() {
	return owner != nullptr && building != Building::hotel;
}

char Normal_Space::get_type_char() const {
    return data.type;
}

std::string Normal_Space::get_current_building_char() const {
	switch (building) {
		case house:
			return "*";
		case hotel:
			return "^";
		default:
			return "";
	}
}

Player *Normal_Space::get_owner() {
	return owner;
}

void Normal_Space::set_owner(Player* p) {
	owner = p;
}
