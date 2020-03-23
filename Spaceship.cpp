// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Spaceship.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.


#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "Spaceship.hpp"

// constructor
Spaceship::Spaceship()
{
    //
}


// get info
void Spaceship::getInfo()
{
    
    std::cout << getSupplyName() << " - " << getSupplyDescription() << std::endl;

}


// print item name
void Spaceship::printItemName()
{
    
    return;
    
}


// print quantity
void Spaceship::printQuantity()
{
    
    return;
    
}


// purchase intro
void Spaceship::purchaseIntro()
{
    
    std::cout << "How much would you like to spend on a " << getSupplyName() << "?" << std::endl;
    
}


// supply price
double Spaceship::getSupplyPrice()
{
    
    return supplyPrice;
    
}


// supply name
std::string Spaceship::getSupplyName()
{
    
    return supplyName;
    
}


// supply description
std::string Spaceship::getSupplyDescription()
{
    
    return supplyDescription;
    
}


bool Spaceship::checkIfSpaceship( void )
{
    return 1;
}
