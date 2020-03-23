// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Crew.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#include "Crew.hpp"

// constructor
Crew::Crew()
{
    //
}


// set member present
void Crew::setPresent(bool value)
{
    
    present = value;
    
}


// return value of present
bool Crew::isPresent( void )
{
    
    return present;
    
}
