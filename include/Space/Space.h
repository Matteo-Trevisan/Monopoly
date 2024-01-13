
#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include <string>
#include "Player/Player.h"

enum Building {
	empty, house, hotel
};

class Space {
public:
	explicit Space(const std::string& name, Player* owner = nullptr);
	virtual ~Space();
	virtual int get_terrain_sale_price() const;
	virtual int get_house_sale_price() const;
	virtual int get_hotel_sale_price() const;
	virtual int get_house_overnight_stay_price() const;
	virtual int get_hotel_overnight_stay_price() const;
	virtual Building get_current_building() const;
	virtual std::string get_current_building_char() const;
	virtual std::string get_next_building_name() const;
	virtual int get_overnight_stay_price();
	virtual int get_next_upgrade_price();
	virtual bool upgradable();
	virtual void upgrade();
	virtual void reset();
	virtual char get_type_char() const;
	virtual int get_start_pass_money() const;
	Player* get_owner();
	void set_owner(Player* p);

	std::string get_name() const;
	void set_name(const std::string& value);

private:
	std::string name;
protected:
	Player* owner;
};

std::ostream &operator<<(std::ostream &os, const Space &d);


#endif //SPACE_H
