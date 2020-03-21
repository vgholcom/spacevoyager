//
//  Fuel.hpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef Fuel_hpp
#define Fuel_hpp

#include <stdio.h>
#include "Supplies.hpp"
#include <string> // C++ standard string class

class Fuel : public Supplies {
public:
    Fuel();
    virtual ~Fuel() = default; // virtual destructor
    
    virtual void getInfo() override; // print supply info
    virtual void printItemName() override;
    virtual void purchaseIntro() override;
    
    double getSupplyPrice() { return supplyPrice; }


private:
    
    std::string getSupplyName() { return supplyName; }
    std::string getSupplyDescription() { return supplyDescription; }
    
    
    std::string supplyName{"Fuel"};
    std::string supplyDescription{"Your spaceship requires fuel to operate."};
    double      supplyPrice{10.0};
};

#endif /* Fuel_hpp */
