// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Doctor.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#include "Doctor.hpp"

// constructor
Doctor::Doctor()
{
    //
}


// get info
void Doctor::getInfo()
{
    
    std::cout << getCrewName() << "\t\t\t" << getCrewDescription() << std::endl;

}


// choose member intro
void Doctor::chooseIntro()
{
    
    std::cout << "Would you like to bring the " << getCrewName() << " on your jouney?" << std::endl;

}


// print crew name
void Doctor::printCrewName()
{
    
    std::cout << getCrewName() << " ";

}


// get advantage
int Doctor::getAdvantage()
{
    return advantage;
}


// get crew name
std::string Doctor::getCrewName()
{
    
    return crewName;
    
}


// get crew description
std::string Doctor::getCrewDescription()
{
    
    return crewDescription;
    
}
