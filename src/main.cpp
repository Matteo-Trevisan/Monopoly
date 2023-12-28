
#include <iostream>
#include "Game_manager/Game_Manager.h"
#include "Config.h"

int main(int argc, char* argv[]) {

	Config config = {{2,3,4,5,6, 'E'},
					 {3,3,4,5,6, 'S'},
					 {5,6,7,8,9, 'L'},
					 50};
//	Game_Manager gm(Player_Type::Computer, config);
//	gm.start();

	Gameboard b(config);

	for (int i = 0; i < 28; ++i) {
		std::cout << b.space_deck.at(i).get() -> get_type_char() << ", ";
	}
}