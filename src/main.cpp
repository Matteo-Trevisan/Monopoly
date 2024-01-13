
#include "Game_manager/Game_Manager.h"
#include "Config.h"

std::string usage() {
	std::string ret;
	ret = "usage:\t ./Monopoly human "
		  "\n\t ./Monopoly computer";
	return ret;
}

int main(int argc, char* argv[]) {

    if(argc != 2) {
		std::cout << usage() << std::endl;
        return 1;
    }

	// controlla il parametro passato da terminale
	Player_Type pt;
	std::string arg_player_type = argv[1];
	if (arg_player_type == "human") {
		pt = Player_Type::Human;
	} else if (arg_player_type == "computer") {
		pt = Player_Type::Computer;
	} else {
		std::cout << usage() << std::endl;
		return 1;
	}

	Config config = {{6,3,3,2,4, 'E'},
					 {10,5,5,4,8, 'S'},
					 {20,10,10,7,14, 'L'},
					 100, 20, 30};

	Game_Manager gm(pt, config, "log_file.txt");
	gm.setup();
	gm.run_game();

	return 0;
}