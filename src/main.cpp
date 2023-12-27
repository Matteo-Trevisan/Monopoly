
#include <iostream>
#include "Game_manager/Game_Manager.h"

int main(int argc, char* argv[]) {
	Game_Manager gm(Player_Type::Computer, 200);
	gm.start();
}