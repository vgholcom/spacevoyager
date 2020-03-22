//
//  Doctor.hpp
//  SpaceVoyager
//
//  Created by Tori Tenney on 3/20/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef Doctor_hpp
#define Doctor_hpp

#include <stdio.h>
#include "Crew.hpp"

class Doctor : public Crew {
public:
    Doctor();
    virtual ~Doctor() = default; // virtual destructor
    
    virtual void getInfo() override; // print crew info
    virtual void chooseIntro() override;
    virtual void printCrewName() override;
    int getAdvantage();


private:
    std::string getCrewName() { return crewName; }
    std::string getCrewDescription() { return crewDescription; }
    
    std::string crewName{"Doctor"};
    std::string crewDescription{"Gives you a lower probability of getting sick. Requires less medicine to heal."};
    
    // advantage factor for having this crew member
    int advantage{2};
};
#endif /* Doctor_hpp */
