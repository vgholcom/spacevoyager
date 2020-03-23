// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Crew.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#ifndef Crew_hpp
#define Crew_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

// crew class
class Crew {
public:
    
    // constructor
    Crew();
    
    // compiler generates virtual destructor
    virtual ~Crew( void ) = default;
    
    // pure virtual get info
    virtual void getInfo( void ) = 0;
    
    // pure virtual choose intro
    virtual void chooseIntro( void ) = 0;
    
    // pure virtual print cname
    virtual void printCrewName( void ) = 0;
    
    // pure virtuaul get crew advantage
    //virtual int getAdvantage( void ) = 0;

    // set present value
    void setPresent( bool value );
    
    // return present value
    bool isPresent( void );
    
private:
    
    // member present
    bool present{0};
    
};


#endif /* Supplies_hpp */
