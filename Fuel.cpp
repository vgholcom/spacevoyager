// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Fuel.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.


#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "Fuel.hpp"

// constructor
Fuel::Fuel()
{
    //
}


// print supply info
void Fuel::getInfo()
{
    
    std::cout << getSupplyName() << " ($" << std::setprecision(2) << getSupplyPrice() << ") - " << getSupplyDescription() << std::endl;
    
}


// print item name
void Fuel::printItemName()
{
    
    std::cout << getSupplyName() << "\t\t\t\t";
    
}


// print purchase intro
void Fuel::purchaseIntro()
{
    
    std::cout << "How many " << getSupplyName() << " would you like to buy at $" << getSupplyPrice() <<"?" << std::endl;
    
}


// return supply price
double Fuel::getSupplyPrice()
{
    
    return supplyPrice;

}


// return supply name
std::string Fuel::getSupplyName()
{
    
    return supplyName;
    
}

// return supply description
std::string Fuel::getSupplyDescription()
{
    
    return supplyDescription;
    
}

