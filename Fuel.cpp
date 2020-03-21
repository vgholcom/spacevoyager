//
//  Fuel.cpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "Fuel.hpp"

// constructor
Fuel::Fuel()
{
    //
}


void Fuel::getInfo()
{
    std::cout << getSupplyName() << " $" << std::setprecision(2) << getSupplyPrice() << " " << getSupplyDescription() << std::endl;
}


void Fuel::printItemName()
{
    std::cout << getSupplyName() << "\t\t\t\t";
}


void Fuel::purchaseIntro()
{
    std::cout << "How many " << getSupplyName() << " would you like to buy at $" << getSupplyPrice() <<"?" << std::endl;
}
