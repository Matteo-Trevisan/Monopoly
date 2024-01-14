//
//	AUTORE: Matteo Trevisan
//

#ifndef OSTREAMFORK_HPP
#define OSTREAMFORK_HPP

// File .hpp in quanto ci sono delle funzioni che utilizzano template

// Overloading operator<< per gestione di dati: int, long, string, ...
template <class Data>
OstreamFork &operator<<(OstreamFork &osf, Data d) {
	(*osf.os1) << d;
	(*osf.os2) << d;
	return osf;
}

// Overloading operator<< per gestione di funzioni: setw() , ...
template <class Data>
OstreamFork &operator<<(OstreamFork &osf, std::ostream &(*f)(std::ostream &, Data)) {
	(*osf.os1) << f;
	(*osf.os2) << f;
	return osf;
}

#endif //OSTREAMFORK_HPP