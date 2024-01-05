#ifndef OSTREAMFORK_HPP
#define OSTREAMFORK_HPP

// For data: int, long , ...
template <class Data>
OstreamFork &operator<<(OstreamFork &osf, Data d) {
	(*osf.os1) << d;
	(*osf.os2) << d;
	return osf;
}

// For setw() , ...
template <class Data>
OstreamFork &operator<<(OstreamFork &osf, std::ostream &(*f)(std::ostream &, Data)) {
	(*osf.os1) << f;
	(*osf.os2) << f;
	return osf;
}

#endif //OSTREAMFORK_HPP