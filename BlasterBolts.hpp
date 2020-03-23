// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// BlasterBolts.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.


#ifndef BlasterBolts_hpp
#define BlasterBolts_hpp

#include <stdio.h>
#include "Supplies.hpp"
#include <string> // C++ standard string class


// blasterbolts class, inheritance from supplies class
class BlasterBolts : public Supplies {
public:
    
    // constructor
    BlasterBolts();
    
    // virtual destructor
    virtual ~BlasterBolts() = default;
    
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
    std::string supplyName{"Blaster Bolts"};
    
    // supply description
    std::string supplyDescription{"Laser ammunition used for hunting space buffalo."};
    
    // supply price
    double      supplyPrice{5.0};
};

#endif /* BlasterBolts_hpp */
