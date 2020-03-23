// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Investor.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#include "Investor.hpp"

// constructor
Investor::Investor()
{
    //
}


// get info
void Investor::getInfo()
{
    
    std::cout << getCrewName() << "\t\t" << getCrewDescription() << std::endl;

}


// print choice intro
void Investor::chooseIntro()
{
    
    std::cout << "Would you like to bring the " << getCrewName() << " on your jouney?" << std::endl;

}


// print crew name
void Investor::printCrewName()
{
    
    std::cout << getCrewName() << " ";

}


// print crew name
std::string Investor::getCrewName()
{
    
    return crewName;
    
}


// print crew description
std::string Investor::getCrewDescription()
{
    
    return crewDescription;
    
}


// get advantage
int Investor::getAdvantage()
{
    
    return advantage;
    
}
