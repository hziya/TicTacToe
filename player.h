#pragma once

#include <iostream>

class player {
public:
    //char of the player "O" or "X"
    char C;
    int x, y;
    int score = 0;

    //function to take input for this player
    void input();


};

