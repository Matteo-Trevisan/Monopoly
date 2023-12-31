#include "Game_manager/Reprint.h"

void Reprint::openFile(const std::string &filename) {
    fileStream.open(filename, std::ios::app);
    if (!fileStream.is_open()) {
        std::cerr << "Impossibile aprire il file." << std::endl;
    }
}

void Reprint::closeFile() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

template<typename T>
Reprint &Reprint::operator<<(const T &data) {
    std::cout << data;
    if (fileStream.is_open()) {
        fileStream << data;
    }
    return *this;
}
