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


void BlasterBolts::getInfo()
{
    std::cout << getSupplyName() << " ($" << std::setprecision(2) << getSupplyPrice() << ") - " << getSupplyDescription() << std::endl;
}


void BlasterBolts::printItemName()
{
    std::cout << getSupplyName() << "\t\t";
}

void BlasterBolts::purchaseIntro()
{
    std::cout << "How many " << getSupplyName() << " would you like to buy at $" << getSupplyPrice() <<"?" << std::endl;
}
