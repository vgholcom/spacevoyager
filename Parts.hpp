// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Parts.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.


#ifndef Parts_hpp
#define Parts_hpp

#include <stdio.h>
#include "Supplies.hpp"
#include <string>


// parts class, inheritance from supplies class
class Parts : public Supplies {
public:
    
    // constructor
    Parts();
    
    // virtual destructor
    virtual ~Parts() = default;
    
    // print supply info
    virtual void getInfo() override;
    
    // print item name
    virtual void printItemName() override;
    
    // print purchase intro
    virtual void purchaseIntro() override;

    // returns supply price
    double getSupplyPrice() override;

private:
    
    // supply name
    std::string getSupplyName();
    
    // supply description
    std::string getSupplyDescription();
    
    // supply name
    std::string supplyName{"Parts"};
    
    // supply description
    std::string supplyDescription{"Allow you to fix your spaceship if you break down."};
    
    // supply price
    double      supplyPrice{10.0};
};

#endif /* Parts_hpp */
