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
    std::cout << getCrewName() << " " << getCrewDescription() << std::endl;
}



void Navigator::chooseIntro()
{
    std::cout << "Would you like to bring the " << getSupplyName() << " on your jouney? 1 for yes, 0 for no." << std::endl;
}
