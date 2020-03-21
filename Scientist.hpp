//
//  Scientist.hpp
//  SpaceVoyager
//
//  Created by Tori Tenney on 3/20/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef Scientist_hpp
#define Scientist_hpp

#include <stdio.h>
#include "Crew.hpp"

class Scientist : public Crew {
public:
    Scientist();
    virtual ~Scientist() = default; // virtual destructor
    virtual void getInfo() override; // print crew info
    virtual void chooseIntro() override;
    virtual void printCrewName() override;

private:
    std::string getCrewName() { return crewName; }
    std::string getCrewDescription() { return crewDescription; }
    
    std::string crewName{"Scientist"};
    std::string crewDescription{"Has a higher probability of mining when traveling through an ateroid belt."};
};
#endif /* Scientist_hpp */
