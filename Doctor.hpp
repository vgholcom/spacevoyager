// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Doctor.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#ifndef Doctor_hpp
#define Doctor_hpp

#include <stdio.h>
#include "Crew.hpp"


// doctor class, inheritance from crew class
class Doctor : public Crew {
public:
    
    // constructor
    Doctor();
    
    // virtual destructor
    virtual ~Doctor() = default;
    
    // print crew info
    virtual void getInfo() override;
    
    // print chose member intro
    virtual void chooseIntro() override;
    
    // print crew name
    virtual void printCrewName() override;
    
    // get advantage
    int getAdvantage();


private:
    
    // get crew name
    std::string getCrewName();
    
    // get crew description
    std::string getCrewDescription();
    
    // crew name
    std::string crewName{"Doctor"};
    
    // crew description
    std::string crewDescription{"Gives you a lower probability of getting sick. Requires less medicine to heal."};
    
    // advantage factor for having this crew member
    int advantage{2};
    
};
#endif /* Doctor_hpp */
