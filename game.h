#pragma once
#include "player.h"

class game {
protected:
    char map[3][3];
    bool playing = true;
    bool order;
    player player1;
    player player2;

    //function to draw the board
    void draw();

    //function to check if there is a winning row
    bool winner();

    //function to check if all map is filled
    bool finished();

    //clears the map
    void clearMap();
public:

    //constructor function
    game();

    //function to play the game
    void play();
};

