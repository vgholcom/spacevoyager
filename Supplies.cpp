//
//  Supplies.cpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#include "Supplies.hpp"

// constructor
Supplies::Supplies()
{
    //
}

void Supplies::buySupply(int number)
{
    supplyQuantity = number;
}


void Supplies::printQuantity()
{
    std::cout << supplyQuantity << std::endl;
}

void Supplies::changeQuantity(int amount)
{
    supplyQuantity = supplyQuantity + amount;
}

int Supplies::checkQuantity()
{
    return supplyQuantity;
}
