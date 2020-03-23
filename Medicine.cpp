// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Medicine.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "Medicine.hpp"

// constructor
Medicine::Medicine()
{
    //
}


// get info
void Medicine::getInfo()
{
    
    std::cout << getSupplyName() << " ($" << std::setprecision(2) << getSupplyPrice() << ") - " << getSupplyDescription() << std::endl;
    
}


// print item name
void Medicine::printItemName()
{
    
    std::cout << getSupplyName() << "\t\t\t";
    
}


// purchase info
void Medicine::purchaseIntro()
{
    
    std::cout << "How many " << getSupplyName() << " would you like to buy at $" << getSupplyPrice() <<"?" << std::endl;
    
}


// supply price
double Medicine::getSupplyPrice()
{
    
    return supplyPrice;
    
}


// supply name
std::string Medicine::getSupplyName()
{
    
    return supplyName;
    
}


// supply description
std::string Medicine::getSupplyDescription()
{
    
    return supplyDescription;
    
}
