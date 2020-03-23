// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Spaceship.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#ifndef Spaceship_hpp
#define Spaceship_hpp

#include <stdio.h>
#include "Supplies.hpp"
#include <string>


// spaceship class, inheritance from supplies class
class Spaceship : public Supplies {
public:
    
    // constructor
    Spaceship( void );
    
    // virtual destructor
    virtual ~Spaceship( void ) = default;
    
    // print supply info
    virtual void getInfo( void ) override;

    // print item name
    virtual void printItemName( void ) override;
    
    // purchase intro
    virtual void purchaseIntro( void ) override;
    
    // print quantity
    virtual void printQuantity( void ) override;
    
    // get supply price
    virtual double getSupplyPrice( void ) override;

    // check if spaceship
    virtual bool checkIfSpaceship( void ) override;


private:
    
    // supply name
    std::string getSupplyName( void );
    
    // supply description
    std::string getSupplyDescription( void );
    
    // supply name
    std::string supplyName{"Spaceship"};
    
    // supply description
    std::string supplyDescription{"You'll need a spaceship for your journey. You get to choose how much you would like to spend. The cost is inversely proportional to the chance of breaking down."};
    
    // supply price
    double      supplyPrice{1.0};
};

#endif /* Spaceship_hpp */
