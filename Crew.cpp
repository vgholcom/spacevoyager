//
//  Crew.cpp
//  SpaceVoyager
//
//  Created by Tori Tenney on 3/20/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#include "Crew.hpp"

// constructor
Crew::Crew()
{
    //
}

void Crew::setPresent(bool value)
{
    present = value;
}

bool Crew::isPresent( void )
{
    return present;
}
