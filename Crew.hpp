//
//  Crew.hpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef Crew_hpp
#define Crew_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

class Crew {
public:
    Crew();
    virtual ~Crew( void ) = default; // compiler generates virtual destructor
    virtual void getInfo( void ) = 0; // pure virtual
    virtual void chooseIntro( void ) = 0;
    virtual void printCrewName( void ) = 0;

    void setPresent( bool value );
    bool isPresent( void );
private:
    bool present;
};


#endif /* Supplies_hpp */
