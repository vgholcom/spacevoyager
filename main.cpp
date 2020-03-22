// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// main.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#include <iostream>

#include "SpaceVoyage.hpp"

int main() {
    
    // variable to keep playing
    int continuePlaying = 1;

    // initialize game with difficulty = medium
    SpaceVoyage spacevoyage(2);
    
    // while user wants to continue playing
    while ( continuePlaying == 1 )
    {
        // start game
        spacevoyage.startGame();
        
        // ask user to play again and get response
        std::cout << "Would you like to play again? 1 to play again, 0 to stop." << std::endl;
        std::cin >> continuePlaying;
    }
    
    // program is over
    std::cout << "Thanks for playing!" << std::endl;
    
}
