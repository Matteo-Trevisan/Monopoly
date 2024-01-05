
#ifndef OSTREAMFORK_H
#define OSTREAMFORK_H

#include <iostream>
#include <fstream>
#include <string>

class OstreamFork {
public:
	std::ostream *os1;
	std::ostream *os2;

	explicit OstreamFork(std::ostream *os_one = nullptr, std::ostream *os_two = nullptr);
private:

};

// For manipulators: endl, flush
OstreamFork &operator<<(OstreamFork &osf, std::ostream &(*f)(std::ostream &));

#include "Game_manager/OstreamFork.hpp"


#endif //OSTREAMFORK_H
