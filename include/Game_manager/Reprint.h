//
// Created by User on 31/12/2023.
//

#ifndef MONOPOLY_REPRINT_H
#define MONOPOLY_REPRINT_H

#include <iostream>
#include <fstream>
#include <string>

class Reprint {
public:
    std::ofstream fileStream;

    Reprint() = default;

	virtual ~Reprint();

	void openFile(const std::string& filename);

    void closeFile();

    template<typename T>
    Reprint& operator<<(const T& data);		// TODO Class Reprint not working
};

#endif //MONOPOLY_REPRINT_H
