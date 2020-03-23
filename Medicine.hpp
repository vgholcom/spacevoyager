// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Medicine.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.


#ifndef Medicine_hpp
#define Medicine_hpp

#include <stdio.h>
#include "Supplies.hpp"
#include <string>


// medicine class, inheritance from supplies class
class Medicine : public Supplies {
public:
    
    // constructor
    Medicine();
    
    // virtual destructor
    virtual ~Medicine() = default;
    
    // print supply info
    virtual void getInfo() override;
    
    // print item name
    virtual void printItemName() override;
    
    // print purchase into
    virtual void purchaseIntro() override;

    // supply price
    double getSupplyPrice() override;

private:
    
    // supply name
    std::string getSupplyName();
    
    // supply description
    std::string getSupplyDescription();
    
    // supply name
    std::string supplyName{"Medicine"};
    
    // supply description
    std::string supplyDescription{"Heals you if you get sick."};
    
    // supply price
    double      supplyPrice{5.0};
    
};

#endif /* Medicine_hpp */
