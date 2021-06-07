#include "game.h"

//function to draw the board
void game::draw() {
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            std::cout << " " << map[j][i] << " ";
            if (i != 2) std::cout << "|";
        }
        std::cout << '\n';
        if (j != 2) std::cout << "---+---+---" << "\n";

    }
}

//function to check if there is a winning row
bool game::winner() {
    for (int i = 0; i < 3; i++) {
        //check rows
        if (map[i][0] == map[i][1] && map[i][1] == map[i][2] && map[i][0] != ' ') return true;
        //check columns
        if (map[0][i] == map[1][i] && map[1][i] == map[2][i] && map[0][i] != ' ') return true;
    }
    //check diagonals
    if (map[1][1] == map[2][2] && map[1][1] == map[0][0] && map[0][0] != ' ') return true;
    if (map[1][1] == map[0][2] && map[1][1] == map[2][0] && map[2][0] != ' ') return true;

    return false;
}

//function to check if all map is filled
bool game::finished() {
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            if (map[i][j] == ' ') return false;
        }
    }

    return true;

}

//clears the map
void game::clearMap() {
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            map[i][j] = ' ';
        }
    }

}

//constructor function
game::game() {
    clearMap();

    std::cout << "Who is going to start first, O or X?\n";

    char first;

    std::cin >> first;
    while (first != 'o' && first != 'x' && first != 'O' && first != 'X') {
        std::cout << "You should enter O or X\n";
        std::cin >> first;
    }
    player1.C = 'O';
    player2.C = 'X';

    (first == 'O' || first == 'o') ? order = true : order = false;
}

//function to play the game
void game::play() {
    char answer;
    draw();
    while (playing) {
        if (order) {
            player1.input();
            while (map[player1.x][player1.y] != ' ') {
                std::cout << "This space is already taken\n";
                player1.input();
            }
            map[player1.x][player1.y] = player1.C;
        }

        else {
            player2.input();
            while (map[player2.x][player2.y] != ' ') {
                std::cout << "This space is already taken\n";
                player2.input();
            }
            map[player2.x][player2.y] = player2.C;


        }

        draw();

        if (winner()) {
            if (order) {
                std::cout << player1.C << " is winner \n";
                player1.score++;
            }

            else {
                std::cout << player2.C << " is winner \n";
                player2.score++;
            }

            playing = false;
        }
        else if (finished()) {
            std::cout << "There is no winner \n";
            playing = false;
        }

        order = !order;

        if (!playing) {
            std::cout << "Your scores are:\n" << player1.C
                << ":" << player1.score << "\n" << player2.C << ":" << player2.score << "\n"
                << "If you want to play again write 'y' \n ";
            std::cin >> answer;
            if (answer == 'y') {
                playing = true;
                clearMap();
                draw();
            }

        }
    }

}