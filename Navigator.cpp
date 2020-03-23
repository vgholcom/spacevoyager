// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Navigator.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#include "Navigator.hpp"


// constructor
Navigator::Navigator()
{
    //
}


// get info
void Navigator::getInfo()
{
    
    std::cout << getCrewName() << "\t\t" << getCrewDescription() << std::endl;
    
}


// choose crew
void Navigator::chooseIntro()
{
    
    std::cout << "Would you like to bring the " << getCrewName() << " on your jouney?" << std::endl;
    
}


// print crew name
void Navigator::printCrewName()
{
    
    std::cout << getCrewName() << " ";
    
}


// get crew advantage
double Navigator::getAdvantage()
{
    
    return advantage;
    
}


// get crew name
std::string Navigator::getCrewName()
{
    
    return crewName;
    
}


// get crew description
std::string Navigator::getCrewDescription()
{
    
    return crewDescription;
    
}
