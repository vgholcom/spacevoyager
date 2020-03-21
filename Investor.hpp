//
//  Investor.hpp
//  SpaceVoyager
//
//  Created by Tori Tenney on 3/20/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef Investor_hpp
#define Investor_hpp

#include <stdio.h>
#include "Crew.hpp"

class Investor : public Crew {
public:
    Investor();
    virtual ~Investor() = default; // virtual destructor
    virtual void getInfo() override; // print crew info
    virtual void chooseIntro() override;
    virtual void printCrewName() override;

    
private:
    std::string getCrewName() { return crewName; }
    std::string getCrewDescription() { return crewDescription; }
    
    std::string crewName{"Investor"};
    std::string crewDescription{"Your money is worth more when buying items at planets."};
};
#endif /* Investor_hpp */
