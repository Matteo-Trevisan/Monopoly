
#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include <string>

class Space {
public:
	virtual int get_terrain_sale_price() const;
	virtual int get_house_sale_price() const;
	virtual int get_hotel_sale_price() const;
	virtual int get_house_overnight_stay_price() const;
	virtual int get_hotel_overnight_stay_price() const;
	virtual std::string get_current_building_char() const;
	virtual int get_overnight_stay_price();
	virtual int get_next_upgrade_price();
	virtual bool upgradable();
	virtual void upgrade();
	virtual void reset();
	virtual char get_type_char() const;
};

std::ostream &operator<<(std::ostream &os, const Space &d);


#endif //SPACE_H
