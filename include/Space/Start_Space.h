//
//	AUTORE: Andrea Sacchetto
//

#ifndef START_SPACE_H
#define START_SPACE_H

#include "Angular_Space.h"
#include "Player/Player.h"
#include <string>

class Start_Space : public Angular_Space{
public:
	explicit Start_Space(int startPassMoney, Player *owner)
	: Angular_Space(owner), start_pass_money(startPassMoney) {};
	~Start_Space() override;
	int get_start_pass_money() const override;

	char get_type_char() const override;

private:
	int start_pass_money;

};

#endif //START_SPACE_H
