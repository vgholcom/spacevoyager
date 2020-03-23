// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Mechanic.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#ifndef Mechanic_hpp
#define Mechanic_hpp

#include <stdio.h>
#include "Crew.hpp"


// mechanic class, inheritance from crew class
class Mechanic : public Crew {
public:
    
    // constructor
    Mechanic();
    
    // virtual destructor
    virtual ~Mechanic() = default;
    
    // print crew info
    virtual void getInfo() override;
    
    // print choose member intro
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
    std::string crewName{"Mechanic"};
    
    // crew description
    std::string crewDescription{"Gives you a lower probability of breaking down. Requires less parts to fix the ship."};
    
    // advantage factor for having this crew member
    int advantage{2};
    
};

#endif /* Mechanic_hpp */
