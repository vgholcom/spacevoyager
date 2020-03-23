// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Scientist.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#include "Scientist.hpp"

// constructor
Scientist::Scientist()
{
    //
}


// get info
void Scientist::getInfo()
{
    
    std::cout << getCrewName() << "\t\t" << getCrewDescription() << std::endl;

}


// choose crew
void Scientist::chooseIntro()
{
    
    std::cout << "Would you like to bring the " << getCrewName() << " on your jouney?" << std::endl;

}


// print crew
void Scientist::printCrewName()
{
    
    std::cout << getCrewName() << " ";

}


// get advantage
int Scientist::getAdvantage()
{
    
    return advantage;

}


// get crew name
std::string Scientist::getCrewName()
{
    
    return crewName;
    
}


// get crew description
std::string Scientist::getCrewDescription() { return crewDescription; }
