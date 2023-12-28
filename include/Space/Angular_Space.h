
#ifndef ANGULAR_SPACE_H
#define ANGULAR_SPACE_H

#include "Space.h"
#include "iostream"

class Angular_Space : public Space {
public:
	Angular_Space() : Angular_Space::Space(std::string()) {};
	char get_type_char() const override;
};

#endif //ANGULAR_SPACE_H
