//
//  Investor.cpp
//  SpaceVoyager
//
//  Created by Tori Tenney on 3/20/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#include "Investor.hpp"

// constructor
Investor::Investor()
{
    //
}


void Investor::getInfo()
{
    std::cout << getCrewName() << "\t\t" << getCrewDescription() << std::endl;
}


void Investor::chooseIntro()
{
    std::cout << "Would you like to bring the " << getCrewName() << " on your jouney?" << std::endl;
}


void Investor::printCrewName()
{
    std::cout << getCrewName() << " ";
}
