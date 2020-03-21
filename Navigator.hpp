//
//  Navigator.hpp
//  SpaceVoyager
//
//  Created by Tori Tenney on 3/20/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef Navigator_hpp
#define Navigator_hpp

#include <stdio.h>
#include "Crew.hpp"

class Navigator : public Crew {
public:
    Navigator();
    virtual ~Navigator() = default; // virtual destructor
    
    virtual void getInfo() override; // print crew info
    virtual void chooseIntro() override;
    virtual void printCrewName() override;

private:
    std::string getCrewName() { return crewName; }
    std::string getCrewDescription() { return crewDescription; }
    
    std::string crewName{"Navigator"};
    std::string crewDescription{"Gives you a higher probability of traveling further."};
};

#endif /* Navigator_hpp */
