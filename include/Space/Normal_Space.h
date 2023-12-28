
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
	explicit Normal_Space(Space_Data type) : Normal_Space::Space(std::string()), building(Building::empty), data(type), owner(nullptr) {};

	int get_terrain_sale_price() const override;
	int get_house_sale_price() const override;
	int get_hotel_sale_price() const override;
	int get_house_overnight_stay_price() const override;
	int get_hotel_overnight_stay_price() const override;
	int get_overnight_stay_price() override;
	int get_next_upgrade_price() override;
	std::string get_current_building_char() const override;
	bool upgradable() override;
	void upgrade() override;
	void reset() override;
    char get_type_char() const override;

private:
	Building building;
	Space_Data data;
	Player* owner;

};


#endif //NORMAL_SPACE_H
