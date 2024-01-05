
#ifndef ANGULAR_SPACE_H
#define ANGULAR_SPACE_H

#include "Space.h"
#include "iostream"

class Angular_Space : public Space {
public:
	explicit Angular_Space(Player* owner) : Angular_Space::Space(std::string(), owner) {};
	~Angular_Space() override;
	char get_type_char() const override;
};

#endif //ANGULAR_SPACE_H
