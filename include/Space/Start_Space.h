
#ifndef START_SPACE_H
#define START_SPACE_H

#include "Angular_Space.h"

class Start_Space : public Angular_Space{
public:
	explicit Start_Space(int startPassMoney) : start_pass_money(startPassMoney){};
	int get_start_pass_money() const;
	void set_start_pass_money(int startPassMoney);
	char get_type_char() const;

private:
	int start_pass_money;

};



#endif //START_SPACE_H
