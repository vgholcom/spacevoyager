//
//  Mechanic.cpp
//  SpaceVoyager
//
//  Created by Tori Tenney on 3/20/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#include "Mechanic.hpp"

// constructor
Mechanic::Mechanic()
{
    //
}


void Mechanic::getInfo()
{
    std::cout << getCrewName() << " " << getCrewDescription() << std::endl;
}
