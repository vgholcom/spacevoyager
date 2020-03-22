//
//  Spaceship.cpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "Spaceship.hpp"

// constructor
Spaceship::Spaceship()
{
    //
}


void Spaceship::getInfo()
{
    std::cout << getSupplyName() << " - " << getSupplyDescription() << std::endl;
}

void Spaceship::printItemName()
{
    return;
}

void Spaceship::printQuantity()
{
    return;
}


void Spaceship::purchaseIntro()
{
    std::cout << "How much would you like to spend on a " << getSupplyName() << "?" << std::endl;
}
