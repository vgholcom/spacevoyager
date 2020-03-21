//
//  Parts.hpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef Parts_hpp
#define Parts_hpp

#include <stdio.h>
#include "Supplies.hpp"
#include <string> // C++ standard string class

class Parts : public Supplies {
public:
    Parts();
    virtual ~Parts() = default; // virtual destructor
    
    virtual void getInfo() override; // print supply info
    virtual void printItemName() override;
    virtual void purchaseIntro() override;

    double getSupplyPrice() { return supplyPrice; }

private:
    
    std::string getSupplyName() { return supplyName; }
    std::string getSupplyDescription() { return supplyDescription; }
    
    std::string supplyName{"Parts"};
    std::string supplyDescription{"Allow you to fix your spaceship if you break down."};
    double      supplyPrice{10.0};
};

#endif /* Parts_hpp */
