
#ifndef NORMAL_SPACE_H
#define NORMAL_SPACE_H

#include "Space.h"
#include "Space_Data.h"
#include "Player/Player.h"
#include "iostream"

enum Building {
	empty, house, hotel
};

class Normal_Space : public Space{
public:
	explicit Normal_Space(Space_Data type) : building(Building::empty), data(type), owner(nullptr) {};

	int get_terrain_sale_price() const;
	int get_house_sale_price() const;
	int get_hotel_sale_price() const;
	int get_house_overnight_stay_price() const;
	int get_hotel_overnight_stay_price() const;
	int get_overnight_stay_price();
	int get_next_upgrade_price();
	bool upgradable();
	void upgrade();
	void reset();
    char get_type_char() const;

private:
	Building building;
	Space_Data data;
	Player* owner;

};

std::ostream &operator<<(std::ostream &os, const Normal_Space &d);



#endif //NORMAL_SPACE_H
