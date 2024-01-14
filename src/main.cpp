
#include "Game_manager/Game_Manager.h"
#include "Config.h"
#include <unordered_map>

std::string usage() {
	std::string ret;
	ret = "usage:\t ./Monopoly human "
		  "\n\t ./Monopoly computer";
	return ret;
}

int main(int argc, char* argv[]) {

	// Richiede un parametro passato
    if(argc != 2) {
		// Stampa indicazioni d'uso
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

	// Struct di configurazione
	Config config = {{90,60,60,40,135, 'E'},
					 {190,100,100,75,175, 'S'},
					 {340,150,150,100,250, 'L'},
					 1500, 100, 100, 25};

	std::unordered_map<std::string, int> statistic;

	// Save the original cout buffer
	std::streambuf* original_cout = std::cout.rdbuf();

	// Redirect cout to null (suppress output)
	std::ofstream nullStream("/dev/null");  // On Unix-like systems
	// std::ofstream nullStream("nul");      // On Windows

	// Redirect cout to nullStream
	std::cout.rdbuf(nullStream.rdbuf());


	for (int i = 0; i < 1000; ++i) {
		Game_Manager gm(pt, config, "log_file.txt");
		gm.setup();
		statistic[gm.run_game()]++;
	}

	// Restore the original cout buffer
	std::cout.rdbuf(original_cout);

	for (const auto& entry : statistic) {
		std::cout << "Valore: " << entry.first << ", Occorrenze: " << entry.second << std::endl;
	}


	return 0;
}