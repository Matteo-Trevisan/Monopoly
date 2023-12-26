//
// Created by Matteo Trevisan on 26/12/23.
//

#ifndef NORMAL_SPACE_H
#define NORMAL_SPACE_H

#include "Space.h"
#include "Space_Data.h"

enum Building {
	empty, house, hotel
};

class Normal_Space : public Space{
public:
	Normal_Space(Space_Data type) : building(Building::empty), data(type) {};

	int get_terrain_sale_price();
	int get_house_sale_price();
	int get_hotel_sale_price();
	int get_house_overnight_stay_price();
	int get_hotel_overnight_stay_price();
	int get_overnight_stay_price();
	int get_next_upgrade_price();
	bool upgradable();
	void upgrade();
	void reset();

private:
	Building building;
	Space_Data data;
	//Player owner;		TODO When Player Created remove comment

};


#endif //NORMAL_SPACE_H
