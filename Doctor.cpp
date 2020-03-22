//
//  Doctor.cpp
//  SpaceVoyager
//
//  Created by Tori Tenney on 3/20/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#include "Doctor.hpp"

// constructor
Doctor::Doctor()
{
    //
}


void Doctor::getInfo()
{
    std::cout << getCrewName() << "\t\t\t" << getCrewDescription() << std::endl;
}


void Doctor::chooseIntro()
{
    std::cout << "Would you like to bring the " << getCrewName() << " on your jouney?" << std::endl;
}


void Doctor::printCrewName()
{
    std::cout << getCrewName() << " ";
}


int Doctor::getAdvantage()
{
    return advantage;
}
