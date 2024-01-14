//
//	AUTORE: Matteo Trevisan
//

#ifndef OSTREAMFORK_H
#define OSTREAMFORK_H

#include <iostream>
#include <fstream>
#include <string>

//	Classe per la gestione di stream doppio: std::cout e verso file
class OstreamFork {
public:
	std::ostream *os1;
	std::ostream *os2;

	explicit OstreamFork(std::ostream *os_one = nullptr, std::ostream *os_two = nullptr);
private:

};

// Overloading operator<< per gestione di manipolatori: endl, flush, ...
OstreamFork &operator<<(OstreamFork &osf, std::ostream &(*f)(std::ostream &));

#include "Game_manager/OstreamFork.hpp"


#endif //OSTREAMFORK_H
