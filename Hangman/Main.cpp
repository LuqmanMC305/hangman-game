#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main() {
    Hangman game;
    char guess;
    bool game_over = false;

    
    while (!game_over) {
        cout << "Enter a letter: ";
        cin >> guess;
        game_over = game.checkCondition(guess);
    }
    return 0;
}
