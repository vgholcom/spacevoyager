//
//  Spaceship.hpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef Spaceship_hpp
#define Spaceship_hpp

#include <stdio.h>
#include "Supplies.hpp"
#include <string> // C++ standard string class

class Spaceship : public Supplies {
public:
    Spaceship();
    virtual ~Spaceship() = default; // virtual destructor
    
    virtual void getInfo() override; // print supply info

    virtual void printItemName() override;
    virtual void purchaseIntro() override;    
    virtual void printQuantity() override;
    
    virtual double getSupplyPrice() override { return supplyPrice; }


private:
    
    std::string getSupplyName() { return supplyName; }
    std::string getSupplyDescription() { return supplyDescription; }
    
    std::string supplyName{"Spaceship"};
    std::string supplyDescription{"You'll need a spaceship for your journey. You get to choose how much you would like to spend. The cost is inversely proportional to the chance of breaking down."};
    double      supplyPrice{1.0};
};

#endif /* Spaceship_hpp */
