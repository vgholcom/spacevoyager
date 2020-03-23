// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Supplies.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.


#include "Supplies.hpp"

// constructor
Supplies::Supplies()
{
    //
}


// set supply quantity
void Supplies::buySupply(int number)
{
    
    supplyQuantity = number;
    
}


// print quantity
void Supplies::printQuantity()
{
    
    std::cout << supplyQuantity << std::endl;
    
}


// change quantity
void Supplies::changeQuantity(double amount)
{
    
    supplyQuantity = supplyQuantity + amount;
    
}


// check quantity
double Supplies::checkQuantity( void )
{
    
    return supplyQuantity;
    
}


bool Supplies::checkIfSpaceship( void )
{
    return 0; 
}
