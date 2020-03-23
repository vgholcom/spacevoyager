// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Mechanic.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#include "Mechanic.hpp"

// constructor
Mechanic::Mechanic()
{
    //
}


// get info
void Mechanic::getInfo()
{
    
    std::cout << getCrewName() << "\t\t" << getCrewDescription() << std::endl;

}


// choose member
void Mechanic::chooseIntro()
{
    
    std::cout << "Would you like to bring the " << getCrewName() << " on your jouney?" << std::endl;

}


// print crew
void Mechanic::printCrewName()
{
    
    std::cout << getCrewName() << " ";
    
}


// get advantage
int Mechanic::getAdvantage()
{
    
    return advantage;
    
}


// get crew name
std::string Mechanic::getCrewName()
{
    
    return crewName;
    
}


// get crew description
std::string Mechanic::getCrewDescription()
{
    
    return crewDescription;
    
}
