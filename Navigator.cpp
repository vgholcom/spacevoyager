//
//  Navigator.cpp
//  SpaceVoyager
//
//  Created by Tori Tenney on 3/20/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#include "Navigator.hpp"


// constructor
Navigator::Navigator()
{
    //
}


void Navigator::getInfo()
{
    std::cout << getCrewName() << "\t\t" << getCrewDescription() << std::endl;
}



void Navigator::chooseIntro()
{
    std::cout << "Would you like to bring the " << getCrewName() << " on your jouney?" << std::endl;
}


void Navigator::printCrewName()
{
    std::cout << getCrewName() << " ";
}

double Navigator::getAdvantage()
{
    return advantage;
}
