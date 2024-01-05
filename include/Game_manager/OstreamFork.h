
#ifndef OSTREAMFORK_H
#define OSTREAMFORK_H

#include <iostream>
#include <fstream>
#include <string>

class OstreamFork {
public:
	std::ostream *os1;
	std::ostream *os2;

	explicit OstreamFork(std::ostream *os_one = nullptr, std::ostream *os_two = nullptr) : os1(os_one), os2(os_two) {
	};
private:

};

#include "Game_manager/OstreamFork.hpp"


#endif //OSTREAMFORK_H
