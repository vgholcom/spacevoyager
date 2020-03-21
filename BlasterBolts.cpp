//
//  BlasterBolts.cpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "BlasterBolts.hpp"

// constructor
BlasterBolts::BlasterBolts()
{
    //
}


void BlasterBolts::getInfo()
{
    std::cout << getSupplyName() << " $" << std::setprecision(2) << getSupplyPrice() << " " << getSupplyDescription() << std::endl;
}


void BlasterBolts::printItemName()
{
    std::cout << getSupplyName() << "\t\t";
}

void BlasterBolts::purchaseIntro()
{
    std::cout << "How many " << getSupplyName() << " would you like to buy at $" << getSupplyPrice() <<"?" << std::endl;
}
