// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Supplies.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#ifndef Supplies_hpp
#define Supplies_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>


// supplies class
class Supplies {
public:
    
    // constructor
    Supplies();
    
    // compiler generates virtual destructor
    virtual ~Supplies( void ) = default;
    
    // pure virtual get info
    virtual void getInfo( void ) = 0;
    
    // pure virtual get supply price
    virtual double getSupplyPrice( void ) = 0;

    // pure virtual print item name
    virtual void printItemName( void ) = 0;
    
    // pure virtual purchase intro
    virtual void purchaseIntro( void ) = 0;

    // print quantity
    virtual void printQuantity( void );
    
    // check if spaceship
    virtual bool checkIfSpaceship( void );

    // set quantity
    void buySupply(double number);
    
    // check quantity
    double checkQuantity( void );
    
    // change quantity
    void changeQuantity(double amount);
    
private:

    // supply quantity
    double supplyQuantity{0};

};


#endif /* Supplies_hpp */
