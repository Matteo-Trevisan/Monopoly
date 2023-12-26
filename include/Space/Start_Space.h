
#ifndef START_SPACE_H
#define START_SPACE_H

#include "Angular_Space.h"

class Start_Space : public Angular_Space{
public:
	Start_Space(int startPassMoney) : start_pass_money(startPassMoney){};
	int getStartPassMoney() const;
	void setStartPassMoney(int startPassMoney);
private:
	int start_pass_money;
public:
};


#endif //START_SPACE_H
