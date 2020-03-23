// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Navigator.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#ifndef Navigator_hpp
#define Navigator_hpp

#include <stdio.h>
#include "Crew.hpp"


// navigator class, inheritance from crew class
class Navigator : public Crew {
public:
    
    // constructor
    Navigator();
    
    // virtual destructor
    virtual ~Navigator() = default;
    
    // print crew info
    virtual void getInfo() override;
    
    // choose crew member
    virtual void chooseIntro() override;
    
    // print name
    virtual void printCrewName() override;
    
    // get crew advantage
    double getAdvantage();

private:
    
    // get crew name
    std::string getCrewName();
    
    // get crew description
    std::string getCrewDescription();
    
    // crew name
    std::string crewName{"Navigator"};
    
    // crew description
    std::string crewDescription{"Gives you a higher probability of traveling further."};
    
    // advantage
    double advantage = 0.10;
};

#endif /* Navigator_hpp */
