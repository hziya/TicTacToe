#include "player.h"

//function to take input for this player
void player::input() {
    std::cout << C << "'s turn \n" << "Enter the coordinates you want to place your charachter \nFirst enter the row [0, 1, 2] and then the column [0, 1, 2]: \n";
    std::cin >> x;
    while (x < 0 || x>2) {
        std::cout << "You entered a wrong number. Row should be one of the [0, 1, 2] \nEnter again:\n";
        std::cin >> x;
    }

    std::cin >> y;
    while (y < 0 || y>2) {
        std::cout << "You entered a wrong number. Column should be one of the [0, 1, 2] \nEnter again:\n";
        std::cin >> y;
    }
}
