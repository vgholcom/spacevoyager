//
//  Medicine.hpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef Medicine_hpp
#define Medicine_hpp

#include <stdio.h>
#include "Supplies.hpp"
#include <string> // C++ standard string class

class Medicine : public Supplies {
public:
    Medicine();
    virtual ~Medicine() = default; // virtual destructor
    
    virtual void getInfo() override; // print supply info
    virtual void printItemName() override;
    virtual void purchaseIntro() override;

    double getSupplyPrice() { return supplyPrice; }

private:
    
    std::string getSupplyName() { return supplyName; }
    std::string getSupplyDescription() { return supplyDescription; }
    
    std::string supplyName{"Medicine"};
    std::string supplyDescription{"Heals you if you get sick."};
    double      supplyPrice{5.0};
};

#endif /* Medicine_hpp */
