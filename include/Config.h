//
//	AUTORE: Elia Tolfo
//

#ifndef CONFIG_H
#define CONFIG_H

#include "Space/Space_Data.h"

// struct contenente i valori necessari al gioco
struct Config
{
    // struct per goni tipo di classe contenenti i prezzi delle varie azioni
    Space_Data Cheap_Space;
    Space_Data Standard_Space;
    Space_Data Luxury_Space;

    // valori base per il gioco
    int initial_balance;
	int pass_start_space;
	int max_turn;
	int cumputer_accept_percentage;
};

#endif //CONFIG_H
