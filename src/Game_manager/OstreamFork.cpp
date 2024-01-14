//
//	AUTORE: Matteo Trevisan
//

#include "Game_manager/OstreamFork.h"
#include <iostream>

// Costruttore che accetta due puntatori agli ostram che verranno utilizzati
OstreamFork::OstreamFork(std::ostream *os_one, std::ostream *os_two) : os1(os_one), os2(os_two) {
}

// Per manipolatori: endl, flush
OstreamFork &operator<<(OstreamFork &osf, std::ostream &(*f)(std::ostream &)) {
	(*osf.os1) << f;
	(*osf.os2) << f;
	return osf;
}