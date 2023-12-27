
#include <iostream>
#include "Gameboard/Gameboard.h"

int main(int argc, char* argv[]) {
    Config config = {{2,3,4,5,6, 'E'},
                     {3,3,4,5,6, 'S'},
                     {5,6,7,8,9, 'L'},
                     50};
    Gameboard g(config);

    /*
    for (Space s : g.space_deck) {
        std::cout << s << " ";
    }
     */
}