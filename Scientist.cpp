//
//  Scientist.cpp
//  SpaceVoyager
//
//  Created by Tori Tenney on 3/20/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#include "Scientist.hpp"

// constructor
Scientist::Scientist()
{
    //
}


void Scientist::getInfo()
{
    std::cout << getCrewName() << "\t\t" << getCrewDescription() << std::endl;
}


void Scientist::chooseIntro()
{
    std::cout << "Would you like to bring the " << getCrewName() << " on your jouney?" << std::endl;
}


void Scientist::printCrewName()
{
    std::cout << getCrewName() << " ";
}


int Scientist::getAdvantage()
{
    return advantage;
}
