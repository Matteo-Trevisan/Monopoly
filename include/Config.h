#ifndef CONFIG_H
#define CONFIG_H

#include "Space/Space_Data.h"

struct Config
{
    Space_Data Cheap_Space;
    Space_Data Standard_Space;
    Space_Data Luxury_Space;
    int initial_balance;
	int pass_start_space;
};

#endif //CONFIG_H
