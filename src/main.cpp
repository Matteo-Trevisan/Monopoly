
#include <iostream>
#include "Game_manager/Game_Manager.h"
#include "Config.h"

#include <iomanip>

int main(int argc, char* argv[]) {

	Config config = {{2,3,4,5,6, 'E'},
					 {3,3,4,5,6, 'S'},
					 {5,6,7,8,9, 'L'},
					 50};
//	Game_Manager gm(Player_Type::Computer, config);
//	gm.start();

	Game_Manager gm(Player_Type::Computer ,config);
	std::cout << gm.get_gameboard() << std::endl;
//	for (int i = 0; i < 28; ++i) {
//		std::cout << b.get_space_at(i) -> get_type_char() << ", ";
//	}
}