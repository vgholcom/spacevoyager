// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Fuel.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#ifndef Fuel_hpp
#define Fuel_hpp

#include <stdio.h>
#include "Supplies.hpp"
#include <string> // C++ standard string class


// fuel class, inheritance from supplies class
class Fuel : public Supplies {
public:
    
    // constructor
    Fuel();
    
    // virtual destructor
    virtual ~Fuel() = default;
    
    // print supply info
    virtual void getInfo() override;
    
    // print item name
    virtual void printItemName() override;
    
    // print purchase intro
    virtual void purchaseIntro() override;
    
    // get supply price
    double getSupplyPrice() override;


private:
    
    // get supply name
    std::string getSupplyName();
    
    // get supply description
    std::string getSupplyDescription();
    
    // supply name
    std::string supplyName{"Fuel"};
    
    // supply description
    std::string supplyDescription{"Your spaceship requires fuel to operate."};
    
    // supply price
    double      supplyPrice{10.0};

};

#endif /* Fuel_hpp */
