// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// BlasterBolts.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "BlasterBolts.hpp"


// constructor
BlasterBolts::BlasterBolts()
{
    //
}


// print supply info to console
void BlasterBolts::getInfo()
{
    
    std::cout << getSupplyName() << " ($" << std::setprecision(2) << getSupplyPrice() << ") - " << getSupplyDescription() << std::endl;

}


// prints item name
void BlasterBolts::printItemName()
{

    std::cout << getSupplyName() << "\t\t";

}


// print intro to console
void BlasterBolts::purchaseIntro()
{

    std::cout << "How many " << getSupplyName() << " would you like to buy at $" << getSupplyPrice() <<"?" << std::endl;

}


// supply price
double BlasterBolts::getSupplyPrice()
{
    
    return supplyPrice;
    
}


// supply name
std::string BlasterBolts::getSupplyName()
{
    
    return supplyName;
    
}


// supply description
std::string BlasterBolts::getSupplyDescription()
{

    return supplyDescription;

}
