
#include <iostream>
#include "Game_manager/Game_Manager.h"
#include "Config.h"

int main(int argc, char* argv[]) {

	Config config = {{6,3,3,2,4, 'E'},
					 {10,5,5,4,8, 'S'},
					 {20,10,10,7,14, 'L'},
					 15, 20};

	Game_Manager gm(Player_Type::Computer ,config);
	gm.setup();
	gm.run_game();

}