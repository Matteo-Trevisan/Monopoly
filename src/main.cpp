
#include "Game_manager/Game_Manager.h"
#include "Config.h"

int main(int argc, char* argv[]) {

    if(argc != 2) {
        std::cout << R"(Use: "./Monopoly Human" or "./Monopoly Computer")";
        return 1;
    }

    std::string mode = argv[1];


	Config config = {{6,3,3,2,4, 'E'},
					 {10,5,5,4,8, 'S'},
					 {20,10,10,7,14, 'L'},
					 100, 20};

    if(mode == "Human") {
        Game_Manager gm(Player_Type::Human, config, "log_file.txt");
        gm.setup();
        gm.run_game();
    }
	if(mode == "Computer") {
        Game_Manager gm(Player_Type::Computer, config, "log_file.txt");
        gm.setup();
        gm.run_game();
    }



}