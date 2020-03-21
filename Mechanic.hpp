//
//  Mechanic.hpp
//  SpaceVoyager
//
//  Created by Tori Tenney on 3/20/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef Mechanic_hpp
#define Mechanic_hpp

#include <stdio.h>
#include "Crew.hpp"

class Mechanic : public Crew {
public:
    Mechanic();
    virtual ~Mechanic() = default; // virtual destructor
    
    virtual void getInfo() override; // print crew info
    virtual void chooseIntro() override;

private:
    std::string getCrewName() { return crewName; }
    std::string getCrewDescription() { return crewDescription; }
    
    std::string crewName{"Mechanic"};
    std::string crewDescription{"Gives you a lower probability of breaking down. Requires less parts to fix the ship."};
};

#endif /* Mechanic_hpp */
