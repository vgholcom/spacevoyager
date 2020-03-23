// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Parts.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.


#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "Parts.hpp"

// constructor
Parts::Parts()
{
    //
}


// prints info
void Parts::getInfo()
{
    
    std::cout << getSupplyName() << " ($" << std::setprecision(2) << getSupplyPrice() << ") - " << getSupplyDescription() << std::endl;

}


// prints item name
void Parts::printItemName()
{
    
    std::cout << getSupplyName() << "\t\t\t\t";
    
}


// prints purchase intro
void Parts::purchaseIntro()
{
    
    std::cout << "How many " << getSupplyName() << " would you like to buy at $" << getSupplyPrice() <<"?" << std::endl;
    
}


// returns supply price
double Parts::getSupplyPrice()
{
    
    return supplyPrice;
    
}


// gets supply name
std::string Parts::getSupplyName()
{
    
    return supplyName;
    
}


// gets supply description
std::string Parts::getSupplyDescription()
{
    
    return supplyDescription;
    
}
