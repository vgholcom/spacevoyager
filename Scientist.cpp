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
    std::cout << getCrewName() << " " << getCrewDescription() << std::endl;
}