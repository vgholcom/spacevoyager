//
//  BlasterBolts.hpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef BlasterBolts_hpp
#define BlasterBolts_hpp

#include <stdio.h>
#include "Supplies.hpp"
#include <string> // C++ standard string class

class BlasterBolts : public Supplies {
public:
    BlasterBolts();
    virtual ~BlasterBolts() = default; // virtual destructor
    
    virtual void getInfo() override; // print supply info
    virtual void printItemName() override;
    virtual void purchaseIntro() override;
    double getSupplyPrice() { return supplyPrice; }


private:
    
    std::string getSupplyName() { return supplyName; }
    std::string getSupplyDescription() { return supplyDescription; }
    
    std::string supplyName{"Blaster Bolts"};
    std::string supplyDescription{"Laser ammonition used for hunting space buffalo."};
    double      supplyPrice{5.0};
};

#endif /* BlasterBolts_hpp */
